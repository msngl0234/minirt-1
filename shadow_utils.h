#ifndef SHADOW_UTILS_H
# define SHADOW_UTILS_H

# include "objects.h"
# include "vector.h"

int	is_in_shadow(t_vec3 p, t_vec3 n, t_vec3 light_pos,
		t_sphere *s1, t_sphere *s2, t_plane *pl);

#endif
