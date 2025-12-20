#ifndef LIGHTING_UTILS_H
# define LIGHTING_UTILS_H

# include "vector.h"

int		color_scale(int rgb, double k);
int		lambert_shade(int base_rgb, t_vec3 p, t_vec3 n,
			t_vec3 light_pos, double ambient, double intensity);

#endif
