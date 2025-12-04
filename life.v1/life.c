#include "life.h"
#include <stdio.h>

void init_board(t_board *board)
{
	int i, j;

	board->grid = malloc(sizeof(char *) * board->height);
	i = 0;
	while (i < board->height)
	{
		board->grid[i] = malloc(sizeof(char) * board->width);
		j = 0;
		while (j < board->width)
		{
			board->grid[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void init_pen(t_pen *pen)
{
	pen->x = 0;
	pen->y = 0;
	pen->drawing = 0;
}

void move_pen(t_board *board, t_pen *pen, char cmd)
{
	if (cmd == 'w' && pen->y > 0)
		pen->y--;
	else if (cmd == 's' && pen->y < board->height - 1)
		pen->y++;
	else if (cmd == 'a' && pen->x > 0)
		pen->x--;
	else if (cmd == 'd' && pen->x < board->width - 1)
		pen->x++;
}

void parse_commands(t_board *board, t_pen *pen)
{
	char cmd;
	while (read(0, &cmd, 1) > 0)
			{
		if (cmd == 'x')
		{
			pen->drawing = !pen->drawing;
			if (pen->drawing)
				board->grid[pen->y][pen->x] == '0';
		}
		else if (cmd == 'w' || cmd == 'a' || cmd == 's' || cmd == 'd')
		{
			move_pen(&board, &pen, cmd);
			if (pen->drawing)
				board->grid[pen->y][pen->x] == '0';
		}
	}
}

void simulate_once(t_board *board)
{
	char **new_grid;
	int i, j, neigs;

	new_grid = malloc(sizeof(char *) * board->height);
	i = 0;
	while (i < board->height)
	{
		new_grid[i] = malloc(sizeof(char) * board->width);
		i++;
	}

	i = 0;
	while (i < board->height)
	{
		j = 0;
		while (j < board->width)
		{
			neigs = count_neigs(board, i, j);
			if (board->grid[i][j] == '0')
			{
				if (neigs == '2' || neigs == '3')
					new_grid[i][j] = '0';
				else
					new_grid[i][j] = ' ';
			}
			else
			{
				if (neigs == '3')
					new_grid[i][j] = '0';
				else
					new_grid[i][j] = ' ';
			}
			j++;
		}
		i++;
	}

	i = 0;
	while (i < board->height)
	{
		free(board->grid[i];
		board->grid[i] = new_grid[i];
		i++;
	}
	free(new_grid);
}


void simulate(t_board *board, int iters)
{
	int i = 0;
	while (i < iters)
	{
		simulate_once(board);
		i++;
	}
}

void print_board(t_board *board)
{
	int i, j;
	i = 0;
	while (i < board->height)
	{
		j = 0;
		while (j < board->width)
		{
			putchar(board-->grid[i][j]);
			j++;
		}
		putchar('\n');
		i++;
	}

}

void free_board(t_board *board)
{
	int i;
	i = 0;
	while (i < board->height)
	{
		free(board->grid[i]);
		i+;
	}
	free(board->grid);
}

int main(int argc, char **argv)
{
	t_board board;
	t_pen pen;
	int iters;

	if (argc != 4)
		return (1);
	board->width = atoi(argv[1]);
	board->height = atoi(argv[2]);
	iters = atoi(argv[3]);

	init_board(&board);
	init_pen(&pen);
	parse_commands(&board, &pen);
	simulate(&board, iters);
	print_board(&board);
	free_board(&board);

	return (0);
}
