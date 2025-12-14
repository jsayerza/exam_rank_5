#include "life.h"

void board_free(t_board *board)
{
	int i = 0;
	while (i < board->height)
	{
		free(board->grid[i]);
		i++;
	}
	free(board->grid);
}

void board_print(t_board *board)
{
	int i, j;

	i = 0;
	while (i < board->height)
	{
		j = 0;
		while (j < board->width)
		{
			putchar(board->grid[i][j]);
			j++;
		}
		putchar('\n');
		i++;
	}
}


void board_init(t_board *board)
{
	int i, j;

	board->grid = malloc(sizeof(char*) * board->height);
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

void	pen_init(t_pen *pen)
{
	pen->x = 0;
	pen->y = 0;
	pen->drawing = 0;
}

void pen_move(t_board *board, t_pen *pen, char cmd)
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

void	commands_parse(t_board *board, t_pen *pen)
{
	char	cmd;
	while (read(0, &cmd, 1) > 0)
	{
		if (cmd == 'x')
		{
			pen->drawing = !pen->drawing;
			if (pen->drawing)
				board->grid[pen->y][pen->x] = '0';
		}
		else if (cmd == 'w' || cmd == 'a' || cmd == 's' || cmd == 'd')
		{
			pen_move(board, pen, cmd);
			if (pen->drawing)
				board->grid[pen->y][pen->x] = '0';
		}
	}
}

int neigs_count(t_board *board, int i, int j)
{
	int ii, jj, n_count = 0;

	ii = i - 1;
	while (ii <= i + 1)
	{
		if (ii >= 0 && ii < board->height)
		{
			jj = j - 1;
			while (jj <= j + 1)
			{
				if (jj >= 0 && jj < board->width)
				{
					if (ii != i || jj != j)
					{
						if (board->grid[ii][jj] == '0')
							n_count++;
					}
				}
				jj++;
			}
		}
		ii++;
	}

	return (n_count);
}

void	simulate_once(t_board *board)
{
	char** new_grid;
	char* cp;
	char c;
	int i, j, neigs;


	new_grid = malloc(sizeof(char *) * board->height);
	i = 0;
	while (i < board->height)
	{
		new_grid[i] = malloc(sizeof(char) * board->width);
		i++;
	}

	neigs = 0;
	i = 0;
	while (i < board->height)
	{
		j = 0;
		while (j < board->width)
		{
			c = board->grid[i][j];
			cp = &new_grid[i][j];
			neigs = neigs_count(board, i, j);
			if (c == '0')
				if (neigs == 2 || neigs == 3)
					*cp = '0';
				else
					*cp = ' ';
			else
				if (neigs == 3)
					*cp = '0';
				else
					*cp = ' ';
			j++;
		}
		i++;
	}

	//copiar grid
	i = 0;
	while (i < board->height)
	{
		free(board->grid[i]);
		board->grid[i] = new_grid[i];
		i++;
	}
	free(new_grid);
}

void	simulate(t_board *board, int iters)
{
	int i;

	i = 0;
	while (i < iters)
	{
		simulate_once(board);
		i++;
	}
}

int main(int argc, char** argv)
{
	t_board board;
	t_pen	pen;
	int		iters;

	if (argc != 4)
		return (1);
	
	board.width = atoi(argv[1]);
	board.height = atoi(argv[2]);
	iters = atoi(argv[3]);

	board_init(&board);
	pen_init(&pen);
	commands_parse(&board, &pen);
	simulate(&board, iters);
	board_print(&board);
	board_free(&board);

	return (0);
}