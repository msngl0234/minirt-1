#ifndef SHADOW_UTILS_H
# define SHADOW_UTILS_H

# include "objects.h"
# include "vector.h"

# define SHADOW_EPS 1e-4


typedef struct s_scene_objs
{
    t_sphere    *s1;
    t_sphere    *s2;
    t_plane     *pl;
    t_cylinder  *cy;
}   t_scene_objs;

int is_in_shadow(t_vec3 p, t_vec3 n, t_vec3 light_pos, t_scene_objs *objs);

#endif