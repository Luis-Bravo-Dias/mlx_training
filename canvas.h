#ifndef CANVAS_H
# define CANVAS_H

# include "window.h"

# define ESC 65307
# define ENTER 32
# define F_KEY 102
# define C_KEY 99
# define UP_KEY 65362
# define DOWN_KEY 65364
# define P_KEY 112
# define R_KEY 114

extern int size;
extern int follow;
extern int	color;

void	draw_square(t_square square, t_img img);
int		read_keys(int key_pressed, void *param);
int		read_mouse(int button, int mouse_x, int mouse_y, void *param);
int		continuous_read_keys(int key_pressed, void *param);
int	follow_mouse(int mouse_x, int mouse_y, void *param);

#endif