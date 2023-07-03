#include "../canvas.h"

void	draw_square(t_square square, t_img img)
{
	unsigned short int	i;
	unsigned short int	j;

	i = 0;
	while (i < square.size && i + square.y < img.h)
	{
		j = 0;
		while (j < square.size && j + square.x < img.w)
		{
			put_pixel_img(img, j + square.x, i + square.y, square.color);
			j++;
		}
		i++;
	}
}

int	get_color()
{
	return (rand() % 2147483647);
}

int	read_keys(int key_pressed, void *param)
{
	t_img *img;

	img = (t_img *)param;
	if (key_pressed == ESC || !img)
		exit_tutorial(&img->win);
	else if (key_pressed == ENTER)
		draw_square((t_square){0, 0, img->w, 0xFFFFFF}, *img);
}