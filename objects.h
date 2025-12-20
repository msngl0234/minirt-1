#ifndef OBJECTS_H
# define OBJECTS_H

# include "ray.h"
# include "vector.h"

typedef struct s_sphere
{
	double	radius;
	t_vec3	center;
}			t_sphere;

typedef struct s_plane
{
	t_vec3	point;
	t_vec3	normal;
}			t_plane;

typedef struct s_cylinder
{
    t_vec3  center;   
    t_vec3  axis;     
    double  radius;   
    double  height;   
}   t_cylinder;

t_cylinder  *create_cylinder(t_vec3 center, t_vec3 axis, double radius, double height);
int         hit_cylinder(t_cylinder *cy, t_ray *ray, double *t);

t_sphere	*create_sphere(double radius, double x, double y, double z);
//int			hit_sphere(t_sphere *s, t_ray *ray);
int 		hit_sphere(t_sphere *s, t_ray *ray, double *t);
t_plane		*create_plane(double px, double py, double pz, double nx, double ny,
				double nz);
//int			hit_plane(t_plane *pl, t_ray *ray);
int			hit_plane(t_plane *pl, t_ray *ray, double *t);

#endif
