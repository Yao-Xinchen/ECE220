#include <stdint.h>
#include <stdlib.h>

#include "mp10.h"

vertex_set_t *new_vertex_set()
{
    vertex_set_t *vs = malloc(sizeof(vertex_set_t));
    if (vs != NULL)
    {
        vs->count = 0;
        vs->id_array_size = 16;

        int32_t *id = malloc(sizeof(int32_t) * 16);
        if (id == NULL)
        {
            free(vs);
            return NULL;
        }
        vs->id = id;
    }
    return vs;
}


void free_vertex_set(vertex_set_t *vs)
{
    if (vs != NULL)
    {
        if (vs->id != NULL)
        {
            free(vs->id);
        }
        free(vs);
    }
}

path_t *new_path()
{
    path_t *path = malloc(sizeof(path_t));
    if (path != NULL)
    {
        path->n_vertices = 0;
        path->tot_dist = 0; // TODO: to be tested
        path->minimap = 0;

        int32_t *id = malloc(sizeof(int32_t) * 16);
        if (id == NULL)
        {
            free(path);
            return NULL;
        }
        path->id = id;
    }
    return path;
}


void free_path(path_t *path)
{
    if (path != NULL)
    {
        if (path->id != NULL)
        {
            free(path->id);
        }
        free(path);
    }
}

