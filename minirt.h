#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 1920
# define HEIGHT 1080
# define SCREEN_WIDTH 1600
# define SCREEN_HEIGHT 900
# include "camera.h"

typedef struct s_data
{
	void *img;          // mlx_new_image tarafından döndürülen işaretçi
	char *addr;         // Görüntü verisinin başlangıç adresi
	int bits_per_pixel; // Bir piksel için gereken bit sayısı (genellikle 32)
	int line_length;    // Bir yatay çizginin byte cinsinden uzunluğu
	int endian;         // Byte sırası (büyük/küçük)
}		t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	render(t_data *data, t_camera *cam);
#endif