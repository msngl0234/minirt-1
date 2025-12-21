#ifndef OBJECTS_H
# define OBJECTS_H

# include "ray.h"
# include "vector.h"

typedef struct s_rgb
{
	int r;
	int g;
	int b;
}	t_rgb;


typedef struct s_sphere
{
	t_vec3 	center;
	double	radius;
	t_rgb	color; //renkler
	struct 	s_sphere *next; //liste icin pointer
}			t_sphere;

/*eski sphere
typedef struct s_sphere
{
	double	radius;
	t_vec3	center;
}			t_sphere;
*/

typedef struct s_plane
{
	t_vec3 	point;
	t_vec3 	normal;
	t_rgb 	color;
	struct s_plane *next;
}	t_plane;

/*eski plane
typedef struct s_plane
{
	t_vec3	point;
	t_vec3	normal;
}			t_plane;
*/

typedef struct s_cylinder
{
	t_vec3 	center;
	t_vec3 	axis;
	double 	radius;
	double 	height;
	t_rgb 	color;
}	t_cylinder;

/*eski cylinder
typedef struct s_cylinder
{
    t_vec3  center;   
    t_vec3  axis;     
    double  radius;   
    double  height;   
}   t_cylinder;
*/

typedef struct s_ambient
{
	double  	ratio; // isiksiddeti
	t_rgb 		color; // r,g,b
}	t_ambient;

typedef struct s_light
{
	t_vec3 	position; // isigin konumu
	double 	ratio; // parlaklikorani
	t_rgb 	color; //lighting_utils.c icerisinde varsiyaln 255,255,255yapilacak sadeceparser icin ekledik bunu zorunlu degil
}	t_light;


typedef struct s_scene
{
	// t_camera 	cam; -> Kamerayi maindede tutabiliriz simdilik yorumsatirinda biraktim
	t_ambient 	amb; //ortamisigi
	t_light 	light; //isik
	t_sphere 	*spheres;
	t_plane 	*planes;
	t_cylinder 	*cylinders;
} 	t_scene;



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
