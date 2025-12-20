#ifndef SHADING_UTILS_H
# define SHADING_UTILS_H

# include "objects.h"  
# include "ray.h"      
# include "vector.h"  

int		normal_to_color(t_vec3 n);
t_vec3	sphere_normal(t_sphere *s, t_vec3 p);
t_vec3	plane_normal(t_plane *pl, t_ray *ray);
t_vec3 cylinder_normal(t_cylinder *cy, t_vec3 p);

#endif
