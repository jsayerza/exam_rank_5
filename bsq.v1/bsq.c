#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char**	map;
}	t_map;

typedef struct s_square
{
	int	size;
	int	row;
	int	col;
}	t_square;

//////////////////////////////////////////////////////////////
void map_free(t_map *map)
{
	int row = 0;
	while (row < map->rows)
	{
		free(map->map[row]);
		row++;
	}
	free(map->map);
}

void map_print(t_map *map)
{
	int row = 0;
	int col = 0;

	while (row < map->rows)
	{
		col = 0;
		while (col < map->cols)
		{
			putchar(map->map[row][col]);
			col++;
		}
		putchar('\n');
		row++;
	}
}

//////////////////////////////////////////////////////////////
int ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n');
}

int ft_atoi(char* line, int *i)
{
	int res = 0;

	while (ft_is_space(line[*i]))
		(*i)++;
	while (line[*i] >= '0' && line[*i] <= '9' )
	{
		res = (res * 10) + (line[*i] - '0');
		(*i)++;
	}
	return (res);
}


//////////////////////////////////////////////////////////////
void skip_lines(FILE* file, int size)
{
	char* line = NULL;
	size_t len = 0;
	int i = 0;

	while (i < size)
	{
		if (getline(&line, &len, file) <= 0)
		{
			break;
		}
		i++;
	}
	free(line);
}

int first_line_parse(FILE* file, t_map *map)
{
	char* line = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	int i = 0;

	nread = getline(&line, &len, file);
	if (nread == -1)
		return (-1);
	map->rows = ft_atoi(line, &i);
	while (ft_is_space(line[i]))
		i++;
	map->empty = line[i++];
	while (ft_is_space(line[i]))
		i++;
	map->obstacle = line[i++];
	while (ft_is_space(line[i]))
		i++;
	map->full = line[i];
	free(line);
	if (map->rows < 1 
		|| map->empty == map->obstacle || map->empty == map->full || map->full == map->obstacle)
	{
		skip_lines(file, map->rows);
		return (0);
	}
	return (1);
}

///////////////////////////////////////////////////////////
int map_lines_parse(t_map* map)
{
	int row = 0;
	int col = 0;

	while (row < map->rows)
	{
		col = 0;
		while (col < map->cols)
		{
			if (map->map[row][col] != map->empty && map->map[row][col] != map->obstacle)
				return (0);
			col++;
		}
		if (col != map->cols)
			return (0);
		row++;
	}
	return (1);
}

int map_parse(FILE* file, t_map *map)
{
	char* line = NULL;
	size_t len = 0;
	ssize_t read_bytes = 0;
	int row = 0;
	int col = 0;

	map->map = malloc(sizeof(char *) * map->rows);
	if (!map->map)
		return (-1);
	while (row < map->rows)
		map->map[row++] = NULL;
	row = 0;
	while (row < map->rows)
	{
		read_bytes = getline(&line, &len, file);
		if (read_bytes <= 0)
		{
			free(line);
			return (0);
		}
		map->map[row] = malloc(sizeof(char) * (read_bytes - 1));
		if (!map->map[row])
		{
			free(line);
			return (-1);
		}
		col = 0;
		while ((col < (read_bytes - 1)) && line[col] != '\0' && line[col] != '\n')
		{
			map->map[row][col] = line[col];
			col++;
		}
		map->cols = col;
		row++;
	}
	free(line);
	if (!map_lines_parse(map))
		return (0);
	return (1);
}

///////////////////////////////////////////////////////////
int min3(int a, int b, int c)
{
	int minim = a;

	if (b < minim)
		minim = b;
	if (c < minim)
		minim = c;

	return (minim);
}

t_square find_biggest_sq(t_map* map)
{
	t_square sq;
	int** tmp_map;
	int row = 0;
	int col = 0;
	int size = 0;

	sq.size = 0;
	sq.row = 0;
	sq.col = 0;
	if (map->cols < 1 || map->rows < 1)
		return (sq);

	// calloc tmp_map
	tmp_map = malloc(sizeof(int*) * map->rows);
	if (!tmp_map)
		return (sq);

	// init col=0 tmp_map
	row = 0;
	while (row < map->rows)
	{
		tmp_map[row] = calloc(map->cols, sizeof(int*));
		if (!tmp_map[row])
		{
			while (--row >= 0)
				free(tmp_map[row]);
			free(tmp_map);
			return (sq);
		}
		col = 0;
		if (map->map[row][col] == map->empty)
			tmp_map[row][col] = 1;
		if (tmp_map[row][col] > sq.size)
		{
			sq.size = tmp_map[row][col];
			sq.row = row;
			sq.col = col;
		}
		row++;
	}

	// init row=0 tmp_map
	col = 0;
	while (col < map->cols)
	{
		row = 0;
		if (map->map[row][col] == map->empty)
			tmp_map[row][col] = 1;
		if (tmp_map[row][col] > sq.size)
		{
			sq.size = tmp_map[row][col];
			sq.row = row;
			sq.col = col;
		}
		col++;
	}

	// calculate min [row][col]
	row = 1;
	while (row < map->rows)
	{
		col = 1;
		while (col < map->cols)
		{
			if (map->map[row][col] == map->empty)
			{
				size = min3(tmp_map[row - 1][col], tmp_map[row][col - 1], tmp_map[row-1][col-1]) + 1;
				tmp_map[row][col] = size;
				if (size > sq.size)
				{
					sq.size = size;
					sq.row = row;
					sq.col = col;
				}
			}
			col++;
		}
		row++;
	}
	sq.row = sq.row - sq.size + 1;
	sq.col = sq.col - sq.size + 1;

	// free tmp_map
	row = map->rows;
	while (--row >= 0)
		free(tmp_map[row]);
	free(tmp_map);

	return (sq);
}

void sq_fill(t_map *map, t_square *sq)
{
	int row = sq->row;
	int col = sq->col;
	int size = sq->size;

	while (row < sq->row + size)
	{
		col = sq->col;
		while (col < sq->col + size)
		{
			map->map[row][col] = map->full;
			col++;
		}
		row++;
	}
}

///////////////////////////////////////////////////////////
int file_process(FILE* file)
{
	t_map		map;
	t_square	sq;
	int			res = 0;

	//// parse first line
	res = first_line_parse(file, &map);
	if (res == -1)
		return (-1);
	if (res == 0)
	{
		fprintf(stderr, "map error 2\n");
		return (1);
	}

	//// parse map
	res = map_parse(file, &map);
	if (res == -1)
	{
		fprintf(stderr, "map error 3\n");
		return (-1);
	}
	if (res == 0)
	{
		fprintf(stderr, "map error 4\n");
		map_free(&map);
		return (1);
	}
	
	//// find biggest sq
	sq = find_biggest_sq(&map);
	if (sq.size < 1)
	{
		fprintf(stderr, "map error 5\n");
		map_free(&map);
		return (1);
	}

	//// fill, print, free map
	sq_fill(&map, &sq);
	map_print(&map);
	map_free(&map);

	return (1);
}

///////////////////////////////////////////////////////////
int main (int argc, char** argv)
{
	FILE*	file;
	int		i;
	int		res;

	if (argc == 1)
	{
		res = 1;
		while (res > 0)
			res = file_process(stdin);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			file = fopen(argv[i], "r");
			if (!file)
			{
				fprintf(stderr, "map error 0\n");
				i++;
				continue;
			}
			res = 1;
			while (res > 0)
				res = file_process(file);
			fclose(file);
			i++;
		}
	}
	return (0);
}