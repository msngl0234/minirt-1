#include "camera.h"
#include "color.h"
#include "minirt.h"
#include "objects.h"
#include "ray.h"
#include "mlx_utils.h"
#include "shading_utils.h"
#include "lighting_utils.h"
#include "shadow_utils.h"
#include <stdlib.h>

static void	init_scene(t_scene_objs *objs)
{
	objs->s1 = create_sphere(1.5, 0.0, 0.0, 1.6);
	objs->s2 = create_sphere(1.7, 1.6, 0.0, 0.0);
	objs->pl = create_plane(0, -1.9, 0, 0, 1, 0);
	objs->cy = create_cylinder(vec(0, 0, -3.0), vec(0, 0, 1), 0.8, 3.0);
}

static int	get_closest_hit(t_ray *ray, t_scene_objs *objs, double *closest_t)
{
	double	t;
	int		hit_type;

	hit_type = 0;
	*closest_t = 1e30;
	if (hit_sphere(objs->s1, ray, &t) && t < *closest_t)
	{
		*closest_t = t;
		hit_type = 1;
	}
	if (hit_sphere(objs->s2, ray, &t) && t < *closest_t)
	{
		*closest_t = t;
		hit_type = 2;
	}
	if (hit_plane(objs->pl, ray, &t) && t < *closest_t)
	{
		*closest_t = t;
		hit_type = 3;
	}
	if (hit_cylinder(objs->cy, ray, &t) && t < *closest_t)
	{
		*closest_t = t;
		hit_type = 4;
	}
	return (hit_type);
}

static void	get_obj_props(int id, t_scene_objs *objs, t_vec3 p, t_vec3 *n, int *c)
{
	if (id == 1)
	{
		*n = sphere_normal(objs->s1, p);
		*c = 0xFF0000;
	}
	else if (id == 2)
	{
		*n = sphere_normal(objs->s2, p);
		*c = 0x00AEEF;
	}
	else if (id == 3)
	{
		*n = plane_normal(objs->pl, NULL);
		*c = 0xAAAAAA;
	}
	else
	{
		*n = cylinder_normal(objs->cy, p);
		*c = 0x00FF00;
	}
}

static void	process_pixel(t_data *d, int x, int y, t_ray *r, t_scene_objs *obs)
{
	double	t;
	int		id;
	t_vec3	p;
	t_vec3	n;
	int		col;
	t_vec3	light = vec(.0, .0, -3.0);

	id = get_closest_hit(r, obs, &t);
	if (id == 0)
	{
		my_mlx_pixel_put(d, x, y, 0x87CEEB);
		return ;
	}
	p = ray_at(r, t);

	if (id == 3) 
		n = plane_normal(obs->pl, r);
	else
		get_obj_props(id, obs, p, &n, &col);
	
	if (id != 3);
	else
		col = 0xAAAAAA;

	int shadow = is_in_shadow(p, n, light, obs);
	my_mlx_pixel_put(d, x, y, lambert_shade(col, p, n, light, 0.2, shadow ? 0.0 : 0.8));
}

void	render(t_data *data, t_camera *cam)
{
	int				i;
	int				j;
	t_ray			ray;
	t_scene_objs	objs;

	init_scene(&objs);
	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = 0;
		while (j < SCREEN_HEIGHT)
		{
			set_ray(&ray, cam, i, j);
			process_pixel(data, i, j, &ray, &objs);
			j++;
		}
		i++;
	}
}