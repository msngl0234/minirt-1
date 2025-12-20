#include "camera.h"
#include "color.h"
#include "minirt.h"
#include "objects.h"
#include "ray.h"
#include <stdlib.h>
#include <stdio.h>
#include "mlx_utils.h"
#include "shading_utils.h"

void render(t_data *data, t_camera *cam)
{
    int i, j;
    t_ray ray;
    t_sphere *sphere;
	t_sphere *sphere2;
    t_plane *plane;

sphere  = create_sphere(0.6, 0.0, 0.0, 0.0);
sphere2 = create_sphere(0.5, 0.0, 0.0, 0.0);


    plane = create_plane(0, -3, 0, 0, 15, 0);

    for (i = 0; i < SCREEN_WIDTH; i++)
    {
        for (j = 0; j < SCREEN_HEIGHT; j++)
        {
            set_ray(&ray, cam, i, j);
           

            double t_s1;
            double t_s2;
            double  t_p;
            int     hit_s1;
            int     hit_s2;
            int     hit_p;
            int     which_sphere;
            double  t_s;
            int     hit_any_sphere;
            
            hit_s1 = hit_sphere(sphere, &ray, &t_s1);
            hit_s2 = hit_sphere(sphere2, &ray, &t_s2);
            hit_p = hit_plane(plane, &ray, &t_p);

            hit_any_sphere = 0;
            which_sphere = 0;
            t_s = 0;
         
            if (hit_s1)
            {
                hit_any_sphere = 1;
                which_sphere = 1;
                t_s = t_s1;
            }
            if (hit_s2 && (!hit_any_sphere || t_s2 < t_s))
            {
                hit_any_sphere = 1;
                which_sphere = 2;
                t_s = t_s2;
            }
          
            t_vec3	p;
            t_vec3	n;

            if (hit_any_sphere && (!hit_p || t_s < t_p))
            {
                p = ray_at(&ray, t_s);
                if (which_sphere == 1)
                    n = sphere_normal(sphere, p);
                else
                    n = sphere_normal(sphere2, p);

                my_mlx_pixel_put(data, i, j, normal_to_color(n));
            }
            else if (hit_p)
            {
                p = ray_at(&ray, t_p);
                n = plane_normal(plane, &ray);
                my_mlx_pixel_put(data, i, j, normal_to_color(n));
            }
            else
                my_mlx_pixel_put(data, i, j, 0x87CEEB);
                        
                    }
                }
}
