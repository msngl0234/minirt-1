#ifndef SHADING_UTILS_H
# define SHADING_UTILS_H

# include "objects.h"  // t_sphere, t_plane
# include "ray.h"      // t_ray
# include "vector.h"   // t_vec3

int		normal_to_color(t_vec3 n);
t_vec3	sphere_normal(t_sphere *s, t_vec3 p);
t_vec3	plane_normal(t_plane *pl, t_ray *ray);

#endif
