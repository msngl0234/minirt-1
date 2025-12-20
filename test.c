#include <stdio.h>
#include "color.h"

void color_test()
{
	unsigned int	color;

	printf("test1: color set get functions\n");
	set_prim_color(&color, 0xff, 'r');
	set_prim_color(&color, 0x43, 'g');
	set_prim_color(&color, 0x32, 'b');
	set_prim_color(&color, 0x12, 't');
	printf("red: %x, green: %x, blue: %x, transparency: %x\n",
			get_prim_color(color, 'r'),
			get_prim_color(color, 'g'),
			get_prim_color(color, 'b'),
			get_prim_color(color, 't'));
	printf("%x\n", color);
	if (
		get_prim_color(color, 'r') == 0xff
		&& get_prim_color(color, 'g') == 0x43
		&& get_prim_color(color, 'b') == 0x32
		&& get_prim_color(color, 't') == 0x12
	)
	{
		printf("passed\n");
	}
	else {
		printf("fail\n");
	}
}

int main()
{
	color_test();
}
