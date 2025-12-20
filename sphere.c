#include "objects.h"
#include "ray.h"
#include <stdlib.h>
#include <math.h>

t_sphere	*create_sphere(double radius, double x, double y, double z)
{
	t_sphere	*s;

	s = malloc(sizeof(t_sphere));
	if (!s)
		return (NULL);
	s->radius = radius;
	s->center = vec(x, y, z);
	return (s);
}
/*eski sphere*/
// int	hit_sphere(t_sphere *s, t_ray *ray)
// {
// 	t_vec3	oc;
// 	double	a;
// 	double	half_b;
// 	double	c;
// 	double	discriminant;

// 	oc = vec_sub(ray->origin, s->center);
// 	a = vec_dot(ray->direction, ray->direction);
// 	half_b = vec_dot(oc, ray->direction);
// 	c = vec_dot(oc, oc) - s->radius * s->radius;
// 	discriminant = half_b * half_b - a * c;
// 	return (discriminant >= 0);
// }


int hit_sphere(t_sphere *s, t_ray *ray, double *t)
{
    const double    EPSILON = 1e-4;
    t_vec3  oc;
    double  a;
    double  half_b;
    double  c;
    double  discriminant;
    double  sqrt_d;
    double  root;

    oc = vec_sub(ray->origin, s->center);
    a = vec_dot(ray->direction, ray->direction);
    if (fabs(a) < 1e-12)
        return (0);
    half_b = vec_dot (oc, ray->direction);
    c = vec_dot(oc, oc) - s->radius * s->radius;
    discriminant = half_b * half_b - a * c;
    if (discriminant < 0)
        return (0);

    sqrt_d = sqrt(discriminant);

    root = (-half_b - sqrt_d) / a;
    if (root <= EPSILON)
    {
        root = (-half_b + sqrt_d) / a;
        if (root <= EPSILON)
            return (0);
    }
    *t = root;
    return (1);
}
