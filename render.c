#include "camera.h"
#include "color.h"
#include "minirt.h"
#include "objects.h"
#include "ray.h"
#include <stdlib.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/**eski render */
// void	render(t_data *data, t_camera *cam)
// {
// 	int			i;
// 	int			j;
// 	t_ray		ray;        
// 	t_sphere	*sphere;
// 	t_sphere	*sphere2;
// 	t_plane	 	*plane;
// 	sphere = create_sphere(.1, 2., .4, .0);
// 	sphere2 = create_sphere(.2, 0.0, 0.0, 0.0);
// 	plane = create_plane(0, -1, 0, 0, 1, 0);

// 	for (i = 0; i < SCREEN_WIDTH; i++)
// 	{
// 		for (j = 0; j < SCREEN_HEIGHT; j++)
// 		{
// 			set_ray(&ray, cam, i, j);     
			
// 			int sphere_hit = hit_sphere(sphere, &ray);
// 			int plane_hit = hit_plane(plane, &ray);

// 			if (hit_sphere(sphere, &ray))          
// 				my_mlx_pixel_put(data, i, j, 0x000000);
// 			else if (hit_sphere(sphere2, &ray))
// 				my_mlx_pixel_put(data, i, j, 0xFF0000);
// 			else
// 				my_mlx_pixel_put(data, i, j, 0xFFFFFF);
// 			if (sphere_hit || plane_hit)
// 				my_mlx_pixel_put(data, i, j, 0x000000);
// 		}
// 	}
// }


void render(t_data *data, t_camera *cam)
{
    int i, j;
    t_ray ray;
    t_sphere *sphere;
	t_sphere *sphere2;
    t_plane *plane;

    sphere = create_sphere(.1, 2., 0.4, .0);
	sphere2 = create_sphere(.2, 0.0, 0.0, 0.0);
    plane = create_plane(0, -1, 0, 0, 15, 0);

    for (i = 0; i < SCREEN_WIDTH; i++)
    {
        for (j = 0; j < SCREEN_HEIGHT; j++)
        {
            set_ray(&ray, cam, i, j);

            double t_sphere;
            double t_plane;

            int sphere_hit = hit_sphere(sphere, &ray, &t_sphere);
			int sphere_hit2 = hit_sphere(sphere2, &ray, &t_sphere);
            int plane_hit  = hit_plane(plane, &ray, &t_plane);


            if ((sphere_hit || sphere_hit2) && (!plane_hit || t_sphere < t_plane))
                my_mlx_pixel_put(data, i, j, 0xFF0000);
            else if (plane_hit)
                my_mlx_pixel_put(data, i, j, 0xAAAAAA);
            else
                my_mlx_pixel_put(data, i, j, 0x87CEEB); // sky blue
        }
    }
}
