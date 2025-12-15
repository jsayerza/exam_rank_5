#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_map
{
    int rows;
    int cols;
    char empty;
    char obstacle;
    char full;
    char **map;
}   t_map;

typedef struct s_square
{
    int size;
    int row;
    int col;
}   t_square;

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

char *ft_strdup(char *src)
{
    int len;
    char *dest;
    int i;

    len = ft_strlen(src);
    dest = malloc(sizeof(char) * (len + 1));
    if (!dest)
        return (NULL);
    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int ft_isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int ft_atoi(char *str, int *i)
{
    int num;

    num = 0;
    while (ft_isspace(str[*i]))
        (*i)++;
    while (str[*i] >= '0' && str[*i] <= '9')
    {
        num = num * 10 + (str[*i] - '0');
        (*i)++;
    }
    return (num);
}

void free_map(t_map *map)
{
    int i;

    if (map->map)
    {
        i = 0;
        while (i < map->rows)
        {
            free(map->map[i]);
            i++;
        }
        free(map->map);
    }
}

void skip_lines(FILE *f, int n)
{
    char *line;
    size_t len;
    int i;

    line = NULL;
    len = 0;
    i = 0;
    while (i < n)
    {
        if (getline(&line, &len, f) <= 0)
            break;
        i++;
    }
    free(line);
}

int parse_first_line(FILE *f, t_map *map)
{
    char *line;
    size_t len;
    int i;
    long bytes_read;

    line = NULL;
    len = 0;
    bytes_read = getline(&line, &len, f);
    if (bytes_read <= 0)
    {
        free(line);
        return (-1);
    }
    i = 0;
    map->rows = ft_atoi(line, &i);
    while (ft_isspace(line[i]))
        i++;
    map->empty = line[i++];
    while (ft_isspace(line[i]))
        i++;
    map->obstacle = line[i++];
    while (ft_isspace(line[i]))
        i++;
    map->full = line[i];
    free(line);
    if (map->empty == map->obstacle || map->empty == map->full ||
        map->obstacle == map->full)
    {
        skip_lines(f, map->rows);
        return (0);
    }
    if (map->rows <= 0)
    {
        skip_lines(f, map->rows);
        return (0);
    }
    return (1);
}

int validate_line(char *line, int len, t_map *map)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (line[i] != map->empty && line[i] != map->obstacle)
            return (0);
        i++;
    }
    return (1);
}

int read_map(FILE *f, t_map *map)
{
    char *line;
    size_t len;
    ssize_t read_bytes;
    int row;
    int is_valid;

    line = NULL;
    len = 0;
    row = 0;
    is_valid = 1;
    map->cols = -1;
    map->map = malloc(sizeof(char *) * map->rows);
    if (!map->map)
        return (0);
    while (row < map->rows)
        map->map[row++] = NULL;
    row = 0;
    while (row < map->rows)
    {
        read_bytes = getline(&line, &len, f);
        if (read_bytes <= 0)
        {
            free(line);
            return (0);
        }
        if (line[read_bytes - 1] == '\n')
        {
            line[read_bytes - 1] = '\0';
            read_bytes--;
        }
        if (is_valid)
        {
            if (map->cols == -1)
            {
                map->cols = read_bytes;
                if (map->cols <= 0)
                    is_valid = 0;
            }
            else if (read_bytes != map->cols)
                is_valid = 0;
            if (is_valid && !validate_line(line, read_bytes, map))
                is_valid = 0;
            if (is_valid)
            {
                map->map[row] = ft_strdup(line);
                if (!map->map[row])
                {
                    free(line);
                    return (0);
                }
            }
        }
        row++;
    }
    free(line);
    return (is_valid);
}

int min3(int a, int b, int c)
{
    int min;

    min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return (min);
}

t_square find_biggest_square(t_map *map)
{
    t_square result;
    int **dp;
    int i;
    int j;

    result.size = 0;
    result.row = 0;
    result.col = 0;
    if (map->rows == 0 || map->cols == 0)
        return (result);
    dp = malloc(sizeof(int *) * map->rows);
    if (!dp)
        return (result);
    i = 0;
    while (i < map->rows)
    {
        dp[i] = calloc(map->cols, sizeof(int));
        if (!dp[i])
        {
            while (--i >= 0)
                free(dp[i]);
            free(dp);
            return (result);
        }
        i++;
    }
    i = 0;
    while (i < map->rows)
    {
        if (map->map[i][0] == map->empty)
            dp[i][0] = 1;
        else
            dp[i][0] = 0;
        if (dp[i][0] > result.size)
        {
            result.size = dp[i][0];
            result.row = i;
            result.col = 0;
        }
        i++;
    }
    j = 0;
    while (j < map->cols)
    {
        if (map->map[0][j] == map->empty)
            dp[0][j] = 1;
        else
            dp[0][j] = 0;
        if (dp[0][j] > result.size)
        {
            result.size = dp[0][j];
            result.row = 0;
            result.col = j;
        }
        j++;
    }
    i = 1;
    while (i < map->rows)
    {
        j = 1;
        while (j < map->cols)
        {
            if (map->map[i][j] == map->empty)
            {
                dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                if (dp[i][j] > result.size)
                {
                    result.size = dp[i][j];
                    result.row = i;
                    result.col = j;
                }
            }
            else
                dp[i][j] = 0;
            j++;
        }
        i++;
    }
    i = 0;
    while (i < map->rows)
    {
        free(dp[i]);
        i++;
    }
    free(dp);
    return (result);
}

void fill_square(t_map *map, t_square sq)
{
    int start_row;
    int start_col;
    int i;
    int j;

    if (sq.size == 0)
        return ;
    start_row = sq.row - sq.size + 1;
    start_col = sq.col - sq.size + 1;
    i = start_row;
    while (i <= sq.row)
    {
        j = start_col;
        while (j <= sq.col)
        {
            map->map[i][j] = map->full;
            j++;
        }
        i++;
    }
}

void print_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map->rows)
    {
        fprintf(stdout, "%s\n", map->map[i]);
        i++;
    }
}

int process_file(FILE *f)
{
    t_map map;
    t_square sq;
    int parse_result;
    int read_result;

    map.map = NULL;
    parse_result = parse_first_line(f, &map);
    if (parse_result == -1)
        return (-1);
    if (parse_result == 0)
    {
        fprintf(stderr, "map error\n");
        return (1);
    }
    read_result = read_map(f, &map);
    if (!read_result)
    {
        fprintf(stderr, "map error\n");
        free_map(&map);
        return (1);
    }
    sq = find_biggest_square(&map);
    fill_square(&map, sq);
    print_map(&map);
    free_map(&map);
    return (1);
}

int main(int argc, char **argv)
{
    FILE *f;
    int i;
    int result;

    if (argc == 1)
    {
        result = 1;
        while (result > 0)
            result = process_file(stdin);
    }
    else
    {
        i = 1;
        while (i < argc)
        {
            f = fopen(argv[i], "r");
            if (!f)
            {
                fprintf(stderr, "map error\n");
                i++;
                continue;
            }
            result = 1;
            while (result > 0)
                result = process_file(f);
            fclose(f);
            i++;
        }
    }
    return (0);
}