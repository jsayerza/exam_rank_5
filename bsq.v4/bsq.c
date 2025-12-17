#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_map
{
	char**	map;
	int	rows;
	int	cols;
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


//////////////////////////////////////////////////////
int ft_is_space(char c)
{
	return (c == '\t' || c == '\r' || c == '\n' || c == ' ');
}

int ft_atoi(char* line, int (*i))
{
	int	res = 0;

	while (line[(*i)] && line[(*i)] >= '0' && line[(*i)] <= '9')
	{
		res = (res * 10) + ((line[(*i)] - '0') % 10);
		(*i)++;
	}
	return (res);
}


//////////////////////////////////////////////////////
int	first_line_parse(FILE* file, t_map* map)
{
	char*	line = NULL;
	size_t	len = 0;
	ssize_t	read_bytes = 0;
	int	i = 0;
	int	is_valid = 1;

	read_bytes = getline(&line, &len, file);
	if (read_bytes < 0)
	{
		return (-1);
	}
	
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i])
	{
		map->rows = ft_atoi(line, &i);
		if (map->rows < 1)
			is_valid = 0;
	}

	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i])
	{
		map->empty = line[i++];
	}

	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i])
	{
		map->obstacle = line[i++];
	}

	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i])
	{
		map->full = line[i];
	}

	if (map->empty == map->obstacle || map->empty == map->full || map->full == map->obstacle)
		is_valid = 0;

	if (!is_valid)
	{
		skip_lines(file, map->rows - 1);
		fprintf(stderr, "map error fl\n");
		return (0);
	}

	free(line);
	printf("map data: rows: %d %c %c %c\n", map->rows, map->empty, map->obstacle, map->full);

	return (1);
}

int	map_parse(FILE* file, t_map* map)
{
	char*	line = NULL;
	size_t	len = 0;
	ssize_t	read_bytes = 0;
	int	i = 0;
	int	is_valid = 1;

	read_bytes = getline(&line, &len, file);
	if (read_bytes < 0)
	{
		return (-1);
	}

	free(line);
	return (1);
}

int file_parse(FILE* file)
{
	t_map		map;
	t_square	sq;
	int		res = 0;
 
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


//////////////////////////////////////////////////////
int	main (int argc, char** argv)
{
	FILE*	file;
	int	res = 1;
	int	i = 1;
	
	if (argc == 1)
	{
		while (res > 0)
			res = file_parse(stdin);
	}
	else
	{
		while (i < argc)
		{
			file = fopen(argv[i], "r");
			if (!file)
			{
				fprintf(stderr, "map error main\n");
				return (1);
			}
			while (res > 0)
				res = file_parse(file);
			fclose(file);
			i++;
		}
	}

	return (0);
}
