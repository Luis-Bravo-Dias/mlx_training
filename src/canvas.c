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

	printf("key = %d\n", key_pressed);

	img = (t_img *)param;
	if (key_pressed == ESC || !img)
		exit_tutorial(&img->win);
	else if (key_pressed == ENTER)
		draw_square((t_square){0, 0, size, color}, *img);
	else if (key_pressed == F_KEY)
		follow = !follow;
	else if (key_pressed == C_KEY)
		color = get_color();
	else if (key_pressed == UP_KEY)
	{
		if (size < img->w / 4)
			size += 10;
	}
	else if (key_pressed == DOWN_KEY)
	{
		if (size > 1)
			size -= 10;
	}
	// else if (key_pressed == F_KEY)
	// 	penguin(*img);
	else
		return (-1);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
	return (0);
}

int	read_mouse(int button, int mouse_x, int mouse_y, void *param)
{
	int	x;
	int	y;
	t_img	*img;
	t_square	s;

	img = (t_img *)param;
	if (!img)
		return (-1);
	if (mouse_x < 0 || mouse_y < 0 || mouse_x > img->w || mouse_y > img->h)
		return (2);
	x = ((mouse_x % img->w) / size) * size;
	y = ((mouse_y % img->h) / size) * size;
	s = (t_square){x, y, size, color};
	draw_square(s, *img);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
	(void)button;
	return (0);
}

int	continuous_read_keys(int key_pressed, void *param)
{
	t_img	*img;

	img = (t_img *)param;
	if (!img)
		exit_tutorial(&img->win);
	else if (key_pressed == UP_KEY)
	{
		if (size < img->w / 4)
			size += 10;
	}
	else if (key_pressed == DOWN_KEY)
	{
		if (size > 1)
			size -= 10;
	}
	else if (key_pressed == R_KEY)
		color = get_color();
	return (0);
}

int	follow_mouse(int mouse_x, int mouse_y, void *param)
{
	int	x;
	int	y;
	t_img	*img;
	t_square	s;

	img = (t_img *)param;
	if (!img)
		return (1);
	if (mouse_x < 0 || mouse_y < 0 || mouse_x > img->w || mouse_y > img->h)
		return (2);
	if (!follow)
		return (3);
	x = ((mouse_x % img->w) / size) * size;
	y = ((mouse_y % img->h) / size) * size;
	s = (t_square){x, y, size, color};
	draw_square(s, *img);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
	return (0);
}