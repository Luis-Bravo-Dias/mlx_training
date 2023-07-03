#ifndef WINDOW_H
# define WINDOW_H
# include <mlx.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

#define exit_event 17


typedef struct s_win
{
	void 	*mlx_ptr;
	void 	*win_ptr;
	int		height;
	int		width;
}	t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp; //bits_per_pixel
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_square
{
	unsigned short int	x;
	unsigned short int	y;
	unsigned short int	size;
	int					color;
}	t_square;


t_win 	new_program(int w, int h, char *str);
t_img	new_img(int w, int h, t_win window);
void	put_pixel_img(t_img img, int x, int y, int color);
int		exit_tutorial(t_win	*window);

#endif