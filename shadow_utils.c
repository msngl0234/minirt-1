#include "shadow_utils.h"
#include "ray.h"
#include <math.h>

int	is_in_shadow(t_vec3 p, t_vec3 n, t_vec3 light_pos,
		t_sphere *s1, t_sphere *s2, t_plane *pl)
{
	const double	eps = 1e-4;
	t_ray			shadow;
	t_vec3			to_light;
	double			max_t;
	double			t;
	double			n_dot_l;

	// Işığa doğru vektör
	to_light = vec_sub(light_pos, p);
	max_t = vec_length(to_light);
	if (max_t <= 0.0)
		return (0);

	// Yüzey ışığa bakmıyorsa zaten diffuse 0 olacak -> shadow testine gerek yok
	n_dot_l = vec_dot(n, vec_normalize(to_light));
	if (n_dot_l <= 0.0)
		return (0);

	// Self-shadow acne önleme: başlangıcı yüzeyden azıcık dışarı al
	shadow.origin = vec_add(p, vec_mul(n, eps));
	shadow.direction = vec_normalize(vec_sub(light_pos, shadow.origin));
	max_t = vec_length(vec_sub(light_pos, shadow.origin));

	// Sadece ışığa varmadan önceki çarpmalar gölge oluşturur: eps < t < max_t
	if (hit_sphere(s1, &shadow, &t) && t > eps && t < max_t)
		return (1);
	if (hit_sphere(s2, &shadow, &t) && t > eps && t < max_t)
		return (1);
	if (hit_plane(pl, &shadow, &t) && t > eps && t < max_t)
		return (1);
	return (0);
}
