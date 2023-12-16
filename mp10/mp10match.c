#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "mp5.h"
#include "mp10.h"


//
// These variables hold the heads of two singly-linked lists of 
// requests.  
//
// The avaialble list consists of unpaired requests: partner 
// should be NULL, and next is used to form the list.   
// 
// The shared list consists of groups with non-empty start and end 
// vertex intersections.  Only one of the requests in the group is in 
// the list.  The others are linked through the first's partner field 
// and then through the next field of the others in the group.  The 
// next field of the first request in a group is used to form the
// shared list.
//
// Note: for MP2, you should only build groups of two in the shared
// list.
//

static request_t *available = NULL;
static request_t *shared = NULL;

int32_t handle_request(graph_t *g, pyr_tree_t *p, heap_t *h, request_t *r)
{
    // r refers to `the first request`
    // match refers to `the second request`

    // allocate
    r->src_vs = new_vertex_set();
    r->dst_vs = new_vertex_set();
    vertex_set_t *int_src_vs = new_vertex_set();
    vertex_set_t *int_dst_vs = new_vertex_set();
    r->path = new_path();
    if (r->src_vs == NULL || r->dst_vs == NULL || r->path == NULL)
    {
        free_vertex_set(r->src_vs); free_vertex_set(r->dst_vs);
        free_vertex_set(int_src_vs); free_vertex_set(int_dst_vs);
        free(r->path);
        return 0;
    }

    // fill in vertex sets
    find_nodes(&(r->from), r->src_vs, p, 0);
    find_nodes(&(r->to), r->dst_vs, p, 0);
    if (r->src_vs->count == 0 || r->dst_vs->count == 0)
    {
        free_vertex_set(r->src_vs); free_vertex_set(r->dst_vs);
        free_vertex_set(int_src_vs); free_vertex_set(int_dst_vs);
        free(r->path);
        return 0;
    }

    // create minimap
    mark_vertex_minimap(g, p);
    build_vertex_set_minimap(g, r->src_vs);
    build_vertex_set_minimap(g, r->dst_vs);

    // allocate id array
    int_src_vs->id = malloc(sizeof(int32_t) * r->src_vs->count);
    int_dst_vs->id = malloc(sizeof(int32_t) * r->dst_vs->count);
    if (int_src_vs->id == NULL || int_dst_vs->id == NULL)
    {
        free_vertex_set(r->src_vs); free_vertex_set(r->dst_vs);
        free_vertex_set(int_src_vs); free_vertex_set(int_dst_vs);
        free(r->path);
        return 0;
    }
    int_src_vs->id_array_size = r->src_vs->count;
    int_dst_vs->id_array_size = r->dst_vs->count;
    int_src_vs->count = 0;
    int_dst_vs->count = 0;

    // find matches
    request_t *match = available;
    request_t *prev;
    while (match != NULL) // while not the end of available list
    {
        // check match
        match->src_vs = new_vertex_set();
        match->dst_vs = new_vertex_set();
        find_nodes(&(match->from), match->src_vs, p, 0);
        find_nodes(&(match->to), match->dst_vs, p, 0);
        if (match->src_vs->count == 0 || match->dst_vs->count == 0)
        {
            prev = match;
            match = match->next;
            continue; // skip to next match
        }

        // check minimap
        build_vertex_set_minimap(g, match->src_vs);
        build_vertex_set_minimap(g, match->dst_vs);
        uint64_t int_src_mm = r->src_vs->minimap & match->src_vs->minimap;
        uint64_t int_dst_mm = r->dst_vs->minimap & match->dst_vs->minimap;
        if (int_src_mm == 0 || int_dst_mm == 0) // without overlap
        {
            prev = match;
            match = match->next;
            continue; // skip to next match
        }

        // with overlap
        merge_vertex_sets(r->src_vs, match->src_vs, int_src_vs);
        merge_vertex_sets(r->dst_vs, match->dst_vs, int_dst_vs);
        if (int_src_vs->count == 0 || int_dst_vs->count == 0)
        {
            prev = match;
            match = match->next;
            continue; // skip to next match
        }

        // find path
        int32_t result = dijkstra(g, h, int_src_vs, int_dst_vs, r->path);
        if (result == 0) // no path
        {
            prev = match;
            match = match->next;
            continue; // skip to next match
        }

        // ALL CHECKS PASSED

        // update requests

        if (match == available) available = match->next; // delete match from available
        else prev->next = match->next;
        free_vertex_set(r->src_vs);
        free_vertex_set(r->dst_vs);
        free_vertex_set(match->src_vs);
        free_vertex_set(match->dst_vs);

        r->src_vs = match->src_vs = int_src_vs;
        r->dst_vs = match->dst_vs = int_dst_vs;
        r->path = match->path = r->path;

        // build minimaps
        build_vertex_set_minimap(g, int_src_vs);
        build_vertex_set_minimap(g, int_dst_vs);
        build_path_minimap(g, r->path);

        // link partners into shared
        match->partner = match->next = NULL;
        r->partner = match;
        r->next = shared;
        shared = r;

        return 1;
    }

    // no match found, add to available list
    r->next = available;
    available = r;

    // free
    free(int_src_vs->id);
    free(int_dst_vs->id);
    return 1;
}


void print_results()
{
    request_t *r;
    request_t *prt;

    printf("Matched requests:\n");
    for (r = shared; NULL != r; r = r->next)
    {
        printf("%5d", r->uid);
        for (prt = r->partner; NULL != prt; prt = prt->next)
        {
            printf(" %5d", prt->uid);
        }
        printf(" src=%016lX dst=%016lX path=%016lX\n", r->src_vs->minimap, r->dst_vs->minimap, r->path->minimap);
    }

    printf("\nUnmatched requests:\n");
    for (r = available; NULL != r; r = r->next)
    {
        printf("%5d src=%016lX dst=%016lX\n", r->uid, r->src_vs->minimap, r->dst_vs->minimap);
    }
}


int32_t show_results_for(graph_t *g, int32_t which)
{
    request_t *r;
    request_t *prt;

    // Can only illustrate one partner.
    for (r = shared; NULL != r; r = r->next)
    {
        if (which == r->uid)
        {
            return show_find_results(g, r, r->partner);
        }
        for (prt = r->partner; NULL != prt; prt = prt->next)
        {
            if (which == prt->uid)
            {
                return show_find_results(g, prt, r);
            }
        }
    }

    for (r = available; NULL != r; r = r->next)
    {
        if (which == r->uid)
        {
            return show_find_results(g, r, r);
        }
    }
    return 0;
}


static void free_request(request_t *r)
{
    free_vertex_set(r->src_vs);
    free_vertex_set(r->dst_vs);
    if (NULL != r->path)
    {
        free_path(r->path);
    }
    free(r);
}

void free_all_data()
{
    request_t *r;
    request_t *prt;
    request_t *next;

    // All requests in a group share source and destination vertex sets
    // as well as a path, so we need free those elements only once.
    for (r = shared; NULL != r; r = next)
    {
        for (prt = r->partner; NULL != prt; prt = next)
        {
            next = prt->next;
            free(prt);
        }
        next = r->next;
        free_request(r);
    }

    for (r = available; NULL != r; r = next)
    {
        next = r->next;
        free_request(r);
    }
}


