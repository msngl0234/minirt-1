#ifndef RAY_H
# define RAY_H

# include "vector.h"

// Forward declaration ONLY
struct s_camera;

typedef struct s_ray {
    t_vec3  origin;
    t_vec3  direction;
}   t_ray;

t_vec3   ray_at(t_ray *ray, double t);
t_ray       *set_ray(t_ray *ray, struct s_camera *cam, int i, int j);

#endif
