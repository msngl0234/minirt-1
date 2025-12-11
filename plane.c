#include "objects.h"
#include "ray.h"
#include <math.h>
#include <stdlib.h>

t_plane	*create_plane(double px, double py, double pz, double nx, double ny,
		double nz)
{
	t_plane	*pl;

	pl = malloc(sizeof(t_plane));
	if (!pl)
		return (NULL);
	pl->point = vec(px, py, pz);
	pl->normal = vec_normalize(vec(nx, ny, nz));
	return (pl);
}

// int	hit_plane(t_plane *pl, t_ray *ray)
// {
// 	t_vec3	p0_minus_o;
// 	double	denom;
// 	double	t;

// 	denom = vec_dot(pl->normal, ray->direction);
// 	if (fabs(denom) < 1e-6)
// 		return (0);
// 	p0_minus_o = vec_sub(pl->point, ray->origin);
// 	t = vec_dot(p0_minus_o, pl->normal) / denom;
// 	if (t < 0)
// 		return (0);
// 	return (1);
// }

/**
 * double_t ile bir kesisime rastladiysak nerede rasladigimizin t sini
 * fonksiyon icerisinden disariya gonderiyoruz
 * bunun sebebi;
 * -kesisim var ama hangi (t)
 * -ayni ray baska objeye de carpiyorsa hangisi daha yakin
 * -golge hesaplarken isik ile obje arasinda baska obje varmi
 */

int hit_plane(t_plane *pl, t_ray *ray, double *t)
{
    double denom = vec_dot(pl->normal, ray->direction);
    t_vec3 p0_minus_o;
    double temp_t;

    //Ray düzleme paralel → kesişme yok
    if (fabs(denom) < 1e-6)
        return 0;

    p0_minus_o = vec_sub(pl->point, ray->origin);
    temp_t = vec_dot(p0_minus_o, pl->normal) / denom;

    //Kamera arkasında kalıyorsa → kesişme yok
    if (temp_t < 0)
        return 0;

    *t = temp_t;
    return 1;
}