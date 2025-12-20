#include "objects.h"
#include "minirt.h"
#include <stdlib.h>
#include <math.h>

t_cylinder  *create_cylinder(t_vec3 center, t_vec3 axis, double radius, double height)
{
    t_cylinder  *cy;

    cy = malloc(sizeof(t_cylinder));
    if (!cy)
        return (NULL);
    cy->center = center;
    cy->axis = vec_normalize(axis); 
    cy->radius = radius;
    cy->height = height;
    return (cy);
}

int hit_cylinder(t_cylinder *cy, t_ray *ray, double *t)
{
    t_vec3  oc;
    double  a;
    double  b;
    double  c;
    double  discriminant;
    double  t1;
    double  t2;
    double  m;
    
    oc = vec_sub(ray->origin, cy->center);

    a = vec_dot(ray->direction, ray->direction) - pow(vec_dot(ray->direction, cy->axis), 2);
    
   
    b = 2 * (vec_dot(ray->direction, oc) - (vec_dot(ray->direction, cy->axis) * vec_dot(oc, cy->axis)));
    
   
    c = vec_dot(oc, oc) - pow(vec_dot(oc, cy->axis), 2) - (cy->radius * cy->radius);

    discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
        return (0);

    
    t1 = (-b - sqrt(discriminant)) / (2 * a);
    t2 = (-b + sqrt(discriminant)) / (2 * a);

   
    double closest_t = t1;
    if (t1 < 1e-4) 
    {
        closest_t = t2;
        if (t2 < 1e-4) 
            return (0);
    }

    t_vec3 hit_point = vec_add(ray->origin, vec_mul(ray->direction, closest_t));
    m = vec_dot(vec_sub(hit_point, cy->center), cy->axis);

    if (m >= -(cy->height / 2.0) && m <= (cy->height / 2.0))
    {
        *t = closest_t;
        return (1);
    }
  
    return (0);
}