#include "shading_utils.h"

static int	clampi(int x, int min, int max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

int	normal_to_color(t_vec3 n)
{
	int	r;
	int	g;
	int	b;

	r = (int)((n.x + 1.0) * 0.5 * 255.0);
	g = (int)((n.y + 1.0) * 0.5 * 255.0);
	b = (int)((n.z + 1.0) * 0.5 * 255.0);
	r = clampi(r, 0, 255);
	g = clampi(g, 0, 255);
	b = clampi(b, 0, 255);
	return ((r << 16) | (g << 8) | b);
}

t_vec3	sphere_normal(t_sphere *s, t_vec3 p)
{
	return (vec_normalize(vec_sub(p, s->center)));
}

t_vec3	plane_normal(t_plane *pl, t_ray *ray)
{
	if (vec_dot(pl->normal, ray->direction) > 0)
		return (vec_mul(pl->normal, -1));
	return (pl->normal);
}
