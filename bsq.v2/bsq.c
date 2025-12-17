#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_map
{
	char**	map;
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

typedef struct s_square
{
	int	size;
	int	row;
	int	col;
}	t_square;


/////////////////////////////////////////////////////////////////////
void map_data_print(t_map *map)
{
	printf("  map->rows: %d\n", map->rows);
	printf("  map->cols: %d\n", map->cols);
	printf("  map->empty: %c\n", map->empty);
	printf("  map->obstacle: %c\n", map->obstacle);
	printf("  map->full: %c\n", map->full);
}

void map_print(t_map *map)
{
	int	row = 0;
	int	col = 0;

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

void map_free(t_map *map)
{
	int	row = 0;

	while (row < map->rows)
	{
		free(map->map[row]);
		row++;
	}
	free(map->map);
}

void skip_lines(FILE* file, int lines)
{
	char*	line = NULL;
	size_t	len;

	int nline = 1;
	while (nline <= lines && (getline(&line, &len, file) > 0))
	{
		nline++;
	}
}

/////////////////////////////////////////////////////////////////////
int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n');
}

int	ft_atoi(char* line, int* i)
{
	int	res = 0;

	while (line[(*i)] >= '0' && line[(*i)] <= '9')
	{
		res = (res * 10) + (((char)line[(*i)] - '0') % 10);
		(*i)++;
	}
	return (res);
}


/////////////////////////////////////////////////////////////////////
int	map_parse(FILE* file, t_map* map)
{
	char*	line = NULL;
	size_t	len;
	ssize_t	bytes_read;
	ssize_t	line_len = 0;
	int		init = 1;
	int		is_valid = 1;
	int		row = 0;
	int		col = 0;

//	printf("map_parse 1\n");

	//// map init
	map->map = malloc(sizeof(char *) * map->rows);
	if (!map->map)
		return (-1);
	row = 0;
	while (row < map->rows)
		map->map[row++] = NULL;

//	printf("map_parse 2\n");
	row = 0;
	while (row < map->rows)
	{
//		printf("map_parse 2[%d]\n", row);
		//// getline
		bytes_read = getline(&line, &len, file);
		if (bytes_read <= 0)
		{
			while (--row >= 0)
				free(map->map[row]);
			free(map->map);
			fprintf(stderr, "map error 8\n");
			free(line);
			skip_lines(file, map->rows - row - 1);
			return (0);
		}
		if (init == 1)
		{
			line_len = bytes_read;
			init = 0;
		}
		else if (line_len != bytes_read)
			is_valid = 0;

		//// set line
		map->map[row] = malloc(sizeof(char) * bytes_read - 1);
		if (!map->map[row])
		{
			while (--row >= 0)
				free(map->map[row]);
			free(map->map);
			fprintf(stderr, "map error 10\n");
			free(line);
			skip_lines(file, map->rows - row - 1);
			return (0);
		}

		col = 0;
		while (line[col] && line[col] != '\n' && line[col] != '\0')
		{
			if (line[col] != map->empty && line[col] != map->obstacle)
			{
				while (--row >= 0)
					free(map->map[row]);
				free(map->map);
				fprintf(stderr, "map error 11\n");
				free(line);
				skip_lines(file, map->rows - row - 1);
				return (0);
			}
			map->map[row][col] = line[col];
			col++;
		}
		map->cols = col;
		row++;
	}

	free(line);
//	printf("map_parse 3\n");
//	map_data_print(map);
	if (!is_valid)
	{
		while (--row >= 0)
			free(map->map[row]);
		free(map->map);
		fprintf(stderr, "map error 999\n");
		return (0);
	}

//	printf("map_parse fi\n");
	return (1);
}


/////////////////////////////////////////////////////////////////////
int	first_line_parse(FILE* file, t_map* map)
{
	char*	line = NULL;
	size_t	len;
	ssize_t	bytes_read;
	int		i = 0;
	int		is_valid = 1;

//	printf("first_line_parse 1\n");
	//// getline
	bytes_read = getline(&line, &len, file);
	if (bytes_read < 1)
	{
//		fprintf(stderr, "map error 2\n");
		free(line);
		return (-1);
	}

	//// map_init
	map->rows = 0;
	i = 0;
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i])
		map->rows = ft_atoi(line, &i);
	else
		is_valid = 0;

	if (is_valid)
	{
		while (line[i] && ft_is_space(line[i]))
			i++;
		if (line[i])
			map->empty = line[i++];
		else
			is_valid = 0;
	}

	if (is_valid)
	{
		while (line[i] && ft_is_space(line[i]))
			i++;
		if (line[i])
			map->obstacle = line[i++];
		else
			is_valid = 0;
	}

	if (is_valid)
	{
		while (line[i] && ft_is_space(line[i]))
			i++;
		if (line[i])
			map->full = line[i];
		else
			is_valid = 0;
	}

	if (is_valid)
	{
		if (map->rows < 1
			|| map->empty == map->full || map->empty == map->obstacle || map->full == map->obstacle)
			is_valid = 0;
	}

	if (!is_valid)
	{
		fprintf(stderr, "map error 666\n");
		free(line);
		skip_lines(file, map->rows);
		return (0);
	}

	free(line);
	//map_data_print(map);
//	printf("first_line_parse fi\n");

	return (1);
}


/////////////////////////////////////////////////////////////////////
int	min3(int a, int b, int c)
{
	int	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

int	find_biggest_sq(t_map* map, t_square* sq)
{
	int**	tmp_map;
	int		row = 0;
	int		col = 0;
	int		size = 0;
	
//	printf("find_biggest_sq 1\n");
	//// sq init
	sq->size = 0;
	sq->col = 0;
	sq->row = 0;

//	printf("find_biggest_sq 2\n");
//	map_data_print(map);	
	//// tmp_map init
	tmp_map = malloc(sizeof(int*) * map->rows);
	if (!tmp_map)
	{
		fprintf(stderr, "map error bi1\n");
		return (0);
	}
	row = 0;
	while (row < map->rows)
	{
		tmp_map[row] = calloc(map->cols, sizeof(int));
		if (!tmp_map[row])
		{
			while (--row >= 0)
				free(tmp_map[row]);
			free(tmp_map);
			fprintf(stderr, "map error bi2\n");
			return (0);
		}
		row++;
	}

//	printf("find_biggest_sq 3\n");
	//// tmp_map col=0 init
	row = 0;
	col = 0;
	while (row < map->rows)
	{
		if (map->map[row][col] == map->empty)
			tmp_map[row][col] = 1;
		if (tmp_map[row][col] > sq->size)
		{
			sq->size = tmp_map[row][col];
			sq->row = row;
			sq->col = col;
		}
		row++;
	}

//	printf("find_biggest_sq 4\n");
	//// tmp_map row=0 init
	row = 0;
	col = 0;
	while (col < map->cols)
	{
		if (map->map[row][col] == map->empty)
			tmp_map[row][col] = 1;
		if (tmp_map[row][col] > sq->size)
		{
			sq->size = tmp_map[row][col];
			sq->row = row;
			sq->col = col;
		}
		col++;
	}

//	printf("find_biggest_sq 5\n");
	//// min3 find
	row = 1;
	col = 1;
	while (col < map->cols)
	{
		row = 1;
		while (row < map->rows)
		{
			if (map->map[row][col] == map->empty)
			{
				size = min3(tmp_map[row-1][col], tmp_map[row][col-1], tmp_map[row-1][col-1]) + 1;
				tmp_map[row][col] = size;
				if (size > sq->size)
				{
					sq->size = size;
					sq->row = row;
					sq->col = col;
				}
			}
			row++;
		}
		col++;
	}
	sq->row = sq->row - sq->size + 1;
	sq->col = sq->col - sq->size + 1;
//	printf("sq->size: %d  sq->row: %d  sq->col: %d\n", sq->size, sq->row, sq->col);

//	printf("find_biggest_sq 6\n");
	//// tmp_map free
	row = 0;
	while (row < map->rows)
	{
		free(tmp_map[row]);
		row++;
	}
	free(tmp_map);	

//	printf("find_biggest_sq fi\n");
	return (sq->size);
}

/////////////////////////////////////////////////////////////////////
void sq_fill(t_map* map, t_square* sq)
{
	int row = sq->row;
	int col = sq->col;

	while (row < sq->row + sq->size)
	{
		col = sq->col;
		while (col < sq->col + sq->size)
		{
			map->map[row][col] = map->full;
			col++;
		}
		row++;
	}
}

/////////////////////////////////////////////////////////////////////
int file_process(FILE* file)
{
	t_map		map;
	t_square	sq;
	int			res = 0;

//	printf("file_process 1\n");
	//// first_line_parse
	res = first_line_parse(file, &map);
	if (res == -1 )
		return (0);
	if (res == 0 )
		return (1);

//	printf("file_process 2\n");
	//// map_parse
	res = map_parse(file, &map);
	if (res < 1)
		return (1);

	//// find_biggest_sq
	res = find_biggest_sq(&map, &sq);
	if (res == 0)
	{
		map_free(&map);
		return (1);
	}

//	printf("file_process 3\n");
	//// sq_fill
	sq_fill(&map, &sq);

//	printf("file_process 4\n");
	//// map_print
	map_print(&map);
	//// map_free
	map_free(&map);

//	printf("file_process fi\n");
	return (1);
}

/////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
	int	res = 1;
	int	i = 1;
	FILE* file;

	if (argc == 1)
	{
		while (res > 0)
			res = file_process(stdin);
	}
	else
	{
		while (i < argc)
		{
			file = fopen(argv[i], "r");
			if (!file)
			{
				fprintf(stderr, "map error 1\n");
				i++;
				continue;;
			}
			while (res > 0)
				res = file_process(file);
			fclose(file);
			i++;
		}
	}

	return (1);
}