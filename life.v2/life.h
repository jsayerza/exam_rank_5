#ifndef LIFE_H
# define LIFE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_board
{
	char**	grid;
	int		width;
	int		height;
}	t_board;

typedef struct s_pen
{
	int	x;
	int	y;
	int drawing;

} t_pen;

#endif