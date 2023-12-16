#include <stdint.h>
#include <stdio.h>

#include "mp5.h"
#include "mp9.h"

int32_t match_requests(graph_t *g, pyr_tree_t *p, heap_t *h,
               request_t *r1, request_t *r2,
               vertex_set_t *src_vs, vertex_set_t *dst_vs, path_t *path)
{
    src_vs->count = 0;
    dst_vs->count = 0;
    path->n_vertices = 0;
    path->tot_dist = 0;
    find_nodes(&r1->from, src_vs, p, 0);
    trim_nodes(g, src_vs, &r2->from);
    find_nodes(&r1->to, dst_vs, p, 0);
    trim_nodes(g, dst_vs, &r2->to);
    int result = dijkstra(g, h, src_vs, dst_vs, path);
    return result;
}
