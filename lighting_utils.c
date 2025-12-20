#include "lighting_utils.h"
#include <math.h>

static double	clamp01(double x)
{
	if (x < 0.0)
		return (0.0);
	if (x > 1.0)
		return (1.0);
	return (x);
}


int	color_scale(int rgb, double k)
{
	int	r;
	int	g;
	int	b;

	r = (rgb >> 16) & 255;
	g = (rgb >> 8) & 255;
	b = rgb & 255;

	r = (int)(r * k);
	g = (int)(g * k);
	b = (int)(b * k);

	if (r > 255) r = 255;
	if (g > 255) g = 255;
	if (b > 255) b = 255;

	return ((r << 16) | (g << 8) | b);
}


int	lambert_shade(int base_rgb, t_vec3 p, t_vec3 n,
		t_vec3 light_pos, double ambient, double intensity)
{
	t_vec3	l;
	double	diff;
	double	k;

	l = vec_normalize(vec_sub(light_pos, p));
	diff = vec_dot(n, l);
	if (diff < 0.0)
		diff = 0.0;

	k = ambient + intensity * diff;
	k = clamp01(k);

	return (color_scale(base_rgb, k));
}
