#include <stdint.h>
#include <stdio.h>

#include "mp5.h"
#include "mp9.h"

#define MY_INFINITY   1000000000

#define TRUE 1
#define FALSE 0

void find_nodes(locale_t *loc, vertex_set_t *vs, pyr_tree_t *p, int32_t nnum)
{
    record_fn_call();

    if (4 * nnum + 1 >= p->n_nodes) // if nnum is a leaf node
    {
        if (in_range(loc, p->node[nnum].x, p->node[nnum].y_left) && vs->count <= MAX_IN_VERTEX_SET)
        {
            vs->id[vs->count] = p->node[nnum].id;
            vs->count++;
        }
    } else // if nnum is not a leaf node
    {
        if (p->node[nnum].x >= loc->x - loc->range) // left
        {
            if (in_range(loc, p->node[nnum].x, p->node[nnum].y_left))
            {
                find_nodes(loc, vs, p, 4 * nnum + 1);
                find_nodes(loc, vs, p, 4 * nnum + 3);
            } else
            {
                if (p->node[nnum].y_left >= loc->y - loc->range)
                {
                    find_nodes(loc, vs, p, 4 * nnum + 1);
                }
                if (p->node[nnum].y_left <= loc->y + loc->range)
                {
                    find_nodes(loc, vs, p, 4 * nnum + 3);
                }
            }
        }
        if (p->node[nnum].x <= loc->x + loc->range) // right
        {
            if (in_range(loc, p->node[nnum].x, p->node[nnum].y_right))
            {
                find_nodes(loc, vs, p, 4 * nnum + 2);
                find_nodes(loc, vs, p, 4 * nnum + 4);
            } else
            {
                if (p->node[nnum].y_right >= loc->y - loc->range)
                {
                    find_nodes(loc, vs, p, 4 * nnum + 2);
                }
                if (p->node[nnum].y_right <= loc->y + loc->range)
                {
                    find_nodes(loc, vs, p, 4 * nnum + 4);
                }
            }
        }
    }
}

void trim_nodes(graph_t *g, vertex_set_t *vs, locale_t *loc)
{
    for (int i = 0; i < vs->count; i++)
    {
        if (!in_range(loc, g->vertex[vs->id[i]].x, g->vertex[vs->id[i]].y))
        {
            vs->id[i] = vs->id[vs->count - 1]; // swap with last element
            vs->count--;
            i--; // decrement i, since we need to check the swapped element
        }
    }
}

void heap_down(graph_t *g, heap_t *h, int32_t i)
{
    int32_t left = 2 * i + 1;
    int32_t right = 2 * i + 2;
    int32_t smallest = i;

    if (left < h->n_elts && g->vertex[h->elt[left]].from_src < g->vertex[h->elt[smallest]].from_src)
    {
        smallest = left;
    }
    if (right < h->n_elts && g->vertex[h->elt[right]].from_src < g->vertex[h->elt[smallest]].from_src)
    {
        smallest = right;
    }
    if (smallest != i)
    {
        int32_t tmp = h->elt[i];
        h->elt[i] = h->elt[smallest];
        h->elt[smallest] = tmp;
        g->vertex[h->elt[i]].heap_id = i;
        g->vertex[h->elt[smallest]].heap_id = smallest;
        heap_down(g, h, smallest);
    }
}

void heap_up(graph_t *g, heap_t *h, int32_t i)
{
    int32_t parent = (i - 1) / 2;
    if (parent >= 0 && g->vertex[h->elt[i]].from_src < g->vertex[h->elt[parent]].from_src)
    {
        int32_t tmp = h->elt[i];
        h->elt[i] = h->elt[parent];
        h->elt[parent] = tmp;
        g->vertex[h->elt[i]].heap_id = i;
        g->vertex[h->elt[parent]].heap_id = parent;
        heap_up(g, h, parent);
    }
}

void init_dijkstra(graph_t *g, heap_t *h)
{
    h->n_elts = g->n_vertices;
    for (int i = 0; i < g->n_vertices; i++)
    {
        g->vertex[i].pred = MY_INFINITY;
        g->vertex[i].from_src = MY_INFINITY;
        g->vertex[i].heap_id = i;
        h->elt[i] = i;
    }
}

int32_t dijkstra(graph_t *g, heap_t *h, vertex_set_t *src, vertex_set_t *dest,
                 path_t *path)
{
    init_dijkstra(g, h);

    // Set the source vertices
    for (int i = 0; i < src->count; i++)
    {
        g->vertex[src->id[i]].from_src = 0;
    }
    // Build the heap
    for (int i = h->n_elts - 1; i >= 0; i--)
    {
        heap_down(g, h, i);
    }

    // While the heap is not empty
    while (h->n_elts > 0)
    {
        // Get the vertex with the smallest distance from the source
        int32_t u = h->elt[0]; // u is the vertex with the smallest distance
        h->elt[0] = h->elt[h->n_elts - 1];
        h->n_elts--;
        heap_down(g, h, 0);

        for (int i = 0; i < g->vertex[u].n_neighbors; i++)
        {
            int32_t v = g->vertex[u].neighbor[i];
            int32_t from_src_new = g->vertex[u].from_src + g->vertex[u].distance[i];
            if (g->vertex[v].from_src > from_src_new)
            {
                g->vertex[v].from_src = from_src_new;
                g->vertex[v].pred = u;
                heap_up(g, h, g->vertex[v].heap_id);
            }
        }
    }

    // Find the destination with the smallest distance from the source
    int32_t dest_opt = dest->id[0];
    path->tot_dist = MY_INFINITY;
    for (int i = 0; i < dest->count; i++)
    {
        if (g->vertex[dest->id[i]].from_src < path->tot_dist)
        {
            dest_opt = dest->id[i];
            path->tot_dist = g->vertex[dest->id[i]].from_src;
        }
    }

    // Trace back the path
    path->n_vertices = 0;
    int32_t trace = dest_opt;
    while (TRUE)
    {
        path->n_vertices++;
        if (g->vertex[trace].pred != MY_INFINITY)
        {
            trace = g->vertex[trace].pred;
        } else
        {
            break;
        }
    }

    // Write the path
    path->tot_dist = g->vertex[dest_opt].from_src;
    trace = dest_opt;
    for (int i = path->n_vertices - 1; i >= 0; i--)
    {
        path->id[i] = trace;
        trace = g->vertex[trace].pred;
    }

    if (path->n_vertices > MAX_PATH_LENGTH) path->n_vertices = 0;
    return (path->n_vertices < 2) ? FALSE : TRUE;
}