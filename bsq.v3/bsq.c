#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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


int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n');
}

int	ft_atoi(char* line, int* i)
{
	int	res = 0;

	while (line[(*i)] && line[(*i)] >= '0' && line[(*i)] <= '9')
	{
		res = (res * 10) + ((line[(*i)] - '0') % 10);
		(*i)++;
	}

	return (res);
}

//////////////////////////////////////////////
void	map_print(t_map* map)
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

void	map_free(t_map* map)
{
	int	row = 0;

	while (row < map->rows)
	{
		free(map->map[row]);
		row++;
	}
	free(map->map);
}

void	skip_lines(FILE* file, int rows)
{
	char*	line = NULL;
	size_t	len = 0;
	int	row = 1;

	while (row <= rows)
	{
		getline(&line, &len, file);
		row++;
	}
	free(line);
}

//////////////////////////////////////////////
int	first_line_parse(FILE* file, t_map* map)
{
	char*	line = NULL;
	size_t	len = 0;
	ssize_t	read_bytes = 0;
	int		is_valid = 1;
	int		i = 0;

//	printf("first_line_parse 1\n");
	read_bytes = getline(&line, &len, file);
	if (read_bytes < 1)
	{
		free(line);
		return (-1);
	}

//	printf("first_line_parse 2\n");
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i])
	{
		map->rows = ft_atoi(line, &i);
		if (map->rows < 1)
		{
			fprintf(stderr, "map error 1\n");
			free(line);
			return (0);
		}
	}
	
//	printf("first_line_parse 3\n");
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i])
		map->empty = line[i++];
	else
		is_valid = 0;
	
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i])
		map->obstacle = line[i++];
	else
		is_valid = 0;

	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i])
		map->full = line[i];
	else
		is_valid = 0;

//	printf("first_line_parse 4\n");
	if (map->empty == map->full ||map->empty == map->obstacle ||map->obstacle == map->full)
		is_valid = 0;

//	printf("first_line_parse 5\n");
	if (!is_valid)
	{
		free(line);
		skip_lines(file, map->rows);
		fprintf(stderr, "map error flp1\n");
		return (0);
	}

	free(line);
	
//	printf("map params: %d %c %c %c\n", map->rows, map->empty, map->obstacle, map->full);
//	printf("first_line_parse fi\n");
	return (1);
}

//////////////////////////////////////////////
int	map_parse(FILE* file, t_map* map)
{
	char*	line = NULL;
	size_t	len = 0;
	ssize_t	read_bytes = 0;
	ssize_t	read_bytes_sav = 0;
	int		is_valid = 1;
	int		row = 0;
	int		col = 0;


//	printf("map_parse 1\n");
	map->map = malloc(sizeof(char*) * map->rows);
	if (!map->map)
		is_valid = 0;
//	printf("map_parse 2\n");
	while (row < map->rows && is_valid)
	{		
		read_bytes = getline(&line, &len, file);
		if (read_bytes < 1)
		{
			is_valid = 0;
			break;
		}
		if (read_bytes_sav == 0)
			read_bytes_sav = read_bytes;
		else if (read_bytes_sav != read_bytes)
		{
			is_valid = 0;
			break;
		}

		map->map[row] = malloc(sizeof(char) * read_bytes - 1);
		if (!map->map)
		{
			is_valid = 0;
			break;
		}
		col = 0;
		while (line[col] && line[col] != '\n' && line[col] != '\0')
		{
			if (line[col] == map->empty || line[col] == map->obstacle)
				map->map[row][col] = line[col];
			else
			{
				is_valid = 0;
				break;
			}

			col++;
		}
		if (!is_valid)
			break;

		row++;
	}
	map->cols = col;

//	printf("map_parse 3\n");
	if (!is_valid)
	{
		free(line);
		skip_lines(file, map->rows - row - 1);
		while (--row >= 0)
			free(map->map[row]);
		free(map->map);
		fprintf(stderr, "map error mp1\n");
		return (0);
	}

	free(line);
//	printf("map params: %d %c %c %c %d\n", map->rows, map->empty, map->obstacle, map->full, map->cols);
//	printf("map_parse fi\n");

	return (1);
}

//////////////////////////////////////////////

int	min3(int a, int b, int c)
{
	int min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	
	return (min);
}

int	sq_find(t_map* map, t_square* sq)
{
	int**	tmp_map;
	int		row = 0;
	int		col = 0;
	int		size = 0;

//	printf("sq_find 1\n");
	sq->size = 0;
	sq->row = 0;
	sq->col = 0;
	tmp_map = malloc(sizeof(int*) * map->rows);
	if (!tmp_map)
	{
		return (0);
	}

//	printf("sq_find 2\n");
	row = 0;
	while (row < map->rows)
	{
		tmp_map[row] = calloc(map->cols, sizeof(int));
		if (!tmp_map[row])
		{
			while (--row >= 0)
				free(tmp_map[row]);
			free(tmp_map);
			return (0);
		}
		row++;
	}

//	printf("sq_find 3\n");
	row = 0;
	col = 0;
	while (row < map->rows)
	{
		if (map->map[row][col] == map->empty)
			tmp_map[row][col] = 1;
		if (sq->size < tmp_map[row][col])
		{
			sq->size = tmp_map[row][col];
			sq->row = row;
			sq->col = col;
		}
		row++;
	}

//	printf("sq_find 4\n");
	row = 0;
	col = 0;
	while (col < map->cols)
	{
		if (map->map[row][col] == map->empty)
			tmp_map[row][col] = 1;
		if (sq->size < tmp_map[row][col])
		{
			sq->size = tmp_map[row][col];
			sq->row = row;
			sq->col = col;
		}
		col++;
	}

//	printf("sq_find 5\n");
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
//			//	printf("  sq_find  tmp_map[%d][%d] = %d\n", row, col, size);
				tmp_map[row][col] = size;
				if (sq->size < size)
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
//	printf("  sq->data:  %d %d %d\n", sq->row, sq->col, sq->size);

//	printf("sq_find 6\n");
	//free tmp
	row = 0;
	while (row < map->rows)
	{
		free(tmp_map[row]);
		row++;
	}
	free(tmp_map);

//	printf("sq_find fi\n");
	return (1);
}


void sq_fill(t_map* map, t_square* sq)
{
	int		row = 0;
	int		col = 0;

////	printf("sq_fill 1\n");
////	printf("  sq->data:  %d %d %d\n", sq->row, sq->col, sq->size);
	row = sq->row;
	col = sq->col;
	while (row < sq->row + sq->size)
	{
		col = sq->col;
		while (col < sq->col + sq->size)
		{
//		//	printf("  sq->sq_fill:  %d %d \n", row, col);
			map->map[row][col] = map->full;
			col++;
		}
		row++;
	}
////	printf("sq_fill fi\n");
}


//////////////////////////////////////////////
int file_process(FILE* file)
{
	t_map		map;
	t_square	sq;
	int			res = 0;

	res = first_line_parse(file, &map);
	if (res == -1)
	{
		return (0);
	}
	if (res == 0)
	{
		return (1);
	}
	res = map_parse(file, &map);
	if (res == 0)
	{
		return (1);
	}
//	map_print(&map);
	res = sq_find(&map, &sq);
	if (res == 0)
	{
		map_free(&map);
		return (1);
	}
	sq_fill(&map, &sq);
	map_print(&map);
	map_free(&map);

	return (1);
}

//////////////////////////////////////////////
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
				fprintf(stderr, "map error main1\n");
				i++;
				continue;
			}
			while (res > 0)
				res = file_process(file);
			fclose(file);
			i++;
		}
	}

	return (1);
}
