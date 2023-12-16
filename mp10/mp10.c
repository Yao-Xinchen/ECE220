#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "mp10.h"

int32_t cal_mm(int32_t p_id)
{
    // ancestors are from 21 to 84
    while (p_id > 84)
    {
        p_id /= 4;
    }
    return p_id - 21;
}

int32_t mark_vertex_minimap(graph_t *g, pyr_tree_t *p)
{
    for (int i = 0; i < p->n_nodes; i++)
    {
        if (4 * i + 1 >= p->n_nodes) // if i is a leaf node
        {
            int32_t mm_bit = cal_mm(p->node[i].id);
            g->vertex[p->node[i].id].mm_bit = mm_bit;
        }
    }
    return 1; // TODO: not sure
}

void build_vertex_set_minimap(graph_t *g, vertex_set_t *vs)
{
    for (int i = 0; i < vs->count; i++)
    {
        int g_id = vs->id[i];
        int mm_bit = g->vertex[g_id].mm_bit;
        uint64_t mm = 1ull << mm_bit;
        vs->minimap |= mm;
    }
}

void build_path_minimap(graph_t *g, path_t *p)
{
    for (int i = 0; i < p->n_vertices; i++)
    {
        int g_id = p->id[i];
        int mm_bit = g->vertex[g_id].mm_bit;
        uint64_t mm = 1ull << mm_bit;
        p->minimap |= mm;
    }
}

int32_t merge_vertex_sets(const vertex_set_t *v1, const vertex_set_t *v2, vertex_set_t *vint)
{
    uint64_t mm_int = v1->minimap & v2->minimap;
    vint->minimap = mm_int;

    vint->count = 0;

    if (mm_int == 0) // empty
    {
        return 0;
    } else // not empty
    {
        int i1 = 0;
        int i2 = 0;
        while (i1 < v1->count && i2 < v2->count)
        {
            if (v1->id[i1] <= v2->id[i2])
            {
                vint->id[vint->count++] = v1->id[i1++];
            } else
            {
                vint->id[vint->count++] = v2->id[i2++];
            }
        }
        while (i1 < v1->count)
        {
            vint->id[vint->count++] = v1->id[i1++];
        }
        while (i2 < v2->count)
        {
            vint->id[vint->count++] = v2->id[i2++];
        }

        return vint->count != 0; // 0 if empty, 1 if not empty
    }
}
