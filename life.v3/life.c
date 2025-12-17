#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_board
{
	char**	grid;
	int	rows;
	int	cols;
	
}	t_board;

typedef struct s_pen
{
	int	row;
	int	col;
	int	drawing;
}	t_pen;

////////////////////////////////////////////
void board_print(t_board* board)
{
	int	row = 0;
	int	col = 0;

	while (row < board->rows)
	{
		col = 0;
		while (col < board->cols)
		{
			putchar(board->grid[row][col]);
			col++;
		}
		row++;
		putchar('\n');
	}
}

void board_free(t_board* board)
{
	int	row = 0;

	while (row < board->rows)
	{
		free(board->grid[row]);
		row++;
	}
	free(board->grid);
}


////////////////////////////////////////////
int	board_init(t_board* board)
{
	int	row = 0;
	int	col = 0;

	board->grid = malloc(sizeof(char*) * board->rows);
	if (!board->grid)
	{
		return (0);
	}
	while (row < board->rows)
	{
		board->grid[row] = malloc(sizeof(char) * board->cols);
		if (!board->grid[row])
		{
			while (--row >= 0)
				free(board->grid[row]);
			free(board->grid);
			return (0);
		}
		col = 0;
		while (col < board->cols)
		{
			board->grid[row][col] = '.';
			col++;
		}
		row++;
	}

	return (1);
}

int	pen_init(t_pen* pen)
{
	pen->row = 0;
	pen->col = 0;
	pen->drawing = 0;

	return (1);
}

////////////////////////////////////////////
void pen_move(t_board* board, t_pen* pen, char cmd)
{

//		printf("  cmd: %c\n", cmd);
	if (cmd == 'w' && pen->row > 0)
		pen->row--;
	else if (cmd == 's' && pen->row < board->rows - 1)
		pen->row++;
	else if (cmd == 'a' && pen->col > 0)
		pen->col--;
	else if (cmd == 'd' && pen->col < board->cols - 1)
		pen->col++;
}

int commands_parse(t_board* board, t_pen* pen)
{
	
	char cmd;

	while (read(0, &cmd, 1) > 0)
	{
//		printf(" cmd: %c\n", cmd);
		if (cmd == 'x')
		{
			pen->drawing = !pen->drawing;
			if (pen->drawing)
				board->grid[pen->row][pen->col] = '0';
		}
		else if (cmd == 'w' || cmd == 'a' || cmd == 's' || cmd == 'd')
		{
			pen_move(board, pen, cmd);
			if (pen->drawing)
				board->grid[pen->row][pen->col] = '0';
		}
	}

	return (1);
}


///////////////////////////////////////////
int	calc_neigs(t_board* board, int i, int j)
{
	int	neigs = 0;
	int	row = i - 1;
	int	col = j - 1;

	row = i - 1;
	while (row <= i + 1)
	{
		if (row >= 0 && row < board->rows)
		{
			col = j - 1;
			while (col <= j + 1)
			{
				if (col >= 0 && col < board->cols)
				{
					if (row != i || col != j)
					{
//							printf("    [%d][%d]: %c\n",row,col,board->grid[row][col]);
						if (board->grid[row][col] == '0')
							neigs++;
					}
				}
				col++;
			}
		}
		row++;
	}
	

	return (neigs);
}


int simulation_once(t_board* board)
{
	char**	tmp_grid;
	int	row = 0;
	int	col = 0;
	int	neigs = 0;

	tmp_grid = malloc(sizeof(char*) * board->rows);
	if (!tmp_grid)
	{
		return (0);
	}
	while (row < board->rows)
	{
		tmp_grid[row] = malloc(sizeof(char) * board->cols);
		if (!tmp_grid[row])
		{
			while (--row >= 0)
				free(tmp_grid[row]);
			free(tmp_grid);
			return (0);
		}
		col = 0;
		while (col < board->cols)
		{
			neigs = calc_neigs(board, row, col);
//			printf("  [%d][%d] (%c) n:%d -->", row, col, board->grid[row][col], neigs);
			if (board->grid[row][col] == '0')
			{
				if (neigs == 2 || neigs == 3)
					tmp_grid[row][col] = '0';
				else
					tmp_grid[row][col] = '.';
			}
			else
			{
				if (neigs == 3)
					tmp_grid[row][col] = '0';
				else
					tmp_grid[row][col] = '.';
			}
//			printf("  %c\n", tmp_grid[row][col]);
			col++;
		}
		row++;
	}

	row = 0;	
	while (row < board->rows)
	{
		col = 0;
		while (col < board->cols)
		{
			board->grid[row][col] = tmp_grid[row][col];
			col++;
		}
		row++;
	}

	//free tmp
	row = 0;

	while (row < board->rows)
	{
		free(tmp_grid[row]);
		row++;
	}
	free(tmp_grid);
	
	return (1);
}

int simulation(t_board* board, int iters)
{
	int	i = 0;
	int	res = 0;

	while (i < iters)
	{
		res = simulation_once(board);
		if (res == 0)
			return (0);
		i++;
	}
	return (1);
}
///////////////////////////////////////////
int	main (int argc, char** argv)
{
	t_board	board;
	t_pen	pen;
	int	iters = 0;
	int	res = 0;
	
	if (argc != 4)
		return (1);
	
	board.cols = atoi(argv[1]);
	board.rows = atoi(argv[2]);
	iters = atoi(argv[3]);

//	printf("rows: %d cols: %d iters: %d\n", board.rows, board.cols, iters);
	res = board_init(&board);
	if (res == 0)
		return (1);
	res = pen_init(&pen);
	if (res == 0)
		return (1);
	res = commands_parse(&board, &pen);
	if (res == 0)
		return (1);
//	board_print(&board);
//	printf("\n");
	res = simulation(&board, iters);
	if (res == 0)
		return (1);
	board_print(&board);
	board_free(&board);

	return (0);
}
