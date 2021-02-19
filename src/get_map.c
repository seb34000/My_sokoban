/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** get_map
*/

#include "../include/sokoban.h"

char **open_read(char *file, char **map)
{
    int fd = open(file, O_RDONLY);
    size_t size = 0;
    struct stat st;
    char *buff;

    if (fd < 0) {
        my_putstr("Error: Open Files\n");
        exit (84);
    }
    fstat(fd, &st);
    size = st.st_size;
    buff = my_str_malloc(buff, size);
    read(fd, buff, size);
    map = split_string(buff);
    if (buff == NULL || map == NULL) {
        my_putstr("Error: Malloc Failed\n");
        exit (84);
    }
    free (buff);
    return (map);
}