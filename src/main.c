#include "../window.h"

int	main(void)
{
	// void	*mlx_ptr;
	// void	*win_ptr;

	// mlx_ptr = mlx_init();
	// if (!mlx_ptr)
	// 	return (1);
	// win_ptr = mlx_new_window(mlx_ptr, 300, 300, "Hello World");
	// if (!win_ptr)
	// 	return (2);
	// mlx_loop(mlx_ptr);

	t_win tutorial;

	tutorial = new_program(300, 300, "New Program");
	if (!tutorial.mlx_ptr || !tutorial.win_ptr)
		return (1);
	{
		//Trying image for the first time

		t_img	image_4x4;
		image_4x4.win = tutorial;
		image_4x4.img_ptr = mlx_new_image(tutorial.mlx_ptr, 4, 4);
		image_4x4.addr = mlx_get_data_addr(image_4x4.img_ptr, &(image_4x4.bpp), 
			&(image_4x4.line_len), &(image_4x4.endian));
			image_4x4.w = 4;
			image_4x4.h = 5;

	}
	mlx_loop(tutorial.mlx_ptr);
	return (0);
}