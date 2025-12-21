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

/*
 * Gölge sorunu çözümü:
 * Hem t1 hem de t2 kontrol ediliyor.
 * m hesabı optimize edildi (vektör işlemleri yerine dot product formülü kullanıldı).
 */
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
    double  dot_r_axis; // ray direction dot axis
    double  dot_oc_axis; // oc dot axis

    oc = vec_sub(ray->origin, cy->center);
    dot_r_axis = vec_dot(ray->direction, cy->axis);
    dot_oc_axis = vec_dot(oc, cy->axis);

    a = vec_dot(ray->direction, ray->direction) - (dot_r_axis * dot_r_axis);
    b = 2 * (vec_dot(ray->direction, oc) - (dot_r_axis * dot_oc_axis));
    c = vec_dot(oc, oc) - (dot_oc_axis * dot_oc_axis) - (cy->radius * cy->radius);
    
    discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return (0);

    // Kökleri bul
    t1 = (-b - sqrt(discriminant)) / (2 * a);
    t2 = (-b + sqrt(discriminant)) / (2 * a);

    // 1. Kesişim Noktasını (t1) Kontrol Et
    if (t1 > 1e-4)
    {
        // m = (P - C) . Axis formülünün açılmış hali:
        m = dot_r_axis * t1 + dot_oc_axis;
        if (m >= -cy->height / 2.0 && m <= cy->height / 2.0)
        {
            *t = t1;
            return (1);
        }
    }

    // 2. Kesişim Noktasını (t2) Kontrol Et (Eğer t1 geçersizse buraya bakar)
    if (t2 > 1e-4)
    {
        m = dot_r_axis * t2 + dot_oc_axis;
        if (m >= -cy->height / 2.0 && m <= cy->height / 2.0)
        {
            *t = t2;
            return (1);
        }
    }
    
    return (0);
}