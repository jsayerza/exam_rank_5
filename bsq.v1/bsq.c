#include <stdio.h>
#include <stdlib.h>

typedef struct s_map
{
	int		rows;
	int		columns;
	char	empty;
	char	obstacle;
	char	full;
	char**	map;
}	t_map;

typedef struct s_square
{
	int	size;
	int	row;
	int	column;
}	t_square;


map_free(t_map *map)
{
	//code
	free(map);
}

int input_parse(file_name)
{
	if (!fopen(file_name, "r"))
	{
		fprintf(stderr, "map error\n");
		return (1);
	}

	return (1);
}

map_init(t_map *map)
{

}


int main (int argc, char** argv)
{
	FILE*	file;
	t_map	map;
	int		i;
	int		res;

	res = 0;
	if (argc == 1)
	{
		res = file_process(stdin);
		if (!res)
				fprintf(stderr, "map error\n");
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			file = fopen(argv[i], "r");
			if (!file)
			{
				fprintf(stderr, "map error\n");
			}
			else
			{
				res = file_process(argv[i]);
				if (!res)
						fprintf(stderr, "map error\n");
				fclose(file);
			}
			if (i == argc - 1)
				fprintf(stdout, "\n");
			i++;
		}
	}
	
	return (0);
}