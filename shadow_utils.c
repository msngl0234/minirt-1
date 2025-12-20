#include "shadow_utils.h"
#include "ray.h"
#include <math.h>


int	is_in_shadow(t_vec3 p, t_vec3 n, t_vec3 light_pos, t_scene_objs *objs)
{
	t_ray	shadow;
	t_vec3	to_light;
	double	max_t;
	double	t;
	double	n_dot_l;

	to_light = vec_sub(light_pos, p);
	max_t = vec_length(to_light);
	if (max_t <= 0.0)
		return (0);
	n_dot_l = vec_dot(n, vec_normalize(to_light));
	if (n_dot_l <= 0.0)
		return (0);
	shadow.origin = vec_add(p, vec_mul(n, SHADOW_EPS));
	shadow.direction = vec_normalize(vec_sub(light_pos, shadow.origin));
	max_t = vec_length(vec_sub(light_pos, shadow.origin));
	if (hit_sphere(objs->s1, &shadow, &t) && t > SHADOW_EPS && t < max_t)
		return (1);
	if (hit_sphere(objs->s2, &shadow, &t) && t > SHADOW_EPS && t < max_t)
		return (1);
	if (hit_plane(objs->pl, &shadow, &t) && t > SHADOW_EPS && t < max_t)
		return (1);
	if (hit_cylinder(objs->cy, &shadow, &t) && t > SHADOW_EPS && t < max_t)
		return (1);
	return (0);
}