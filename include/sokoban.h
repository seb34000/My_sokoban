/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Sokoban
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#define KEY_SPACE 32

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "../include/stuct.h"

/*LIB*/
char *my_str_malloc(char *str, size_t size);
void *my_memset(void *str, int value, size_t size);
char **split_string(char *str);
char *my_strcpy (char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
size_t my_strlen(const char *str);
size_t my_ptrlen(char const **tab);
char *my_strdup(char const *src);
void my_putchar(char const c);
void my_putstr(char const *str);
void my_put_array(char **array);
int my_strncmp(char const *s1, char const *s2, int n);

/*SOKO SOKO FUNC*/
char **open_read(char *file, char **map);
int tcheck_map(soko_t *game);
bool tcheck_size(soko_t *game);
void tcheck_ox(void);
void get_man(void);
void init_player(soko_t *game, int x, int y);
void init_box(soko_t *game, int x, int y);
void init_wall(soko_t *game, int x, int y);
void init_storage(soko_t *game, int x, int y);
void print_map(soko_t *game);
void move_up(soko_t *game);
void move_down(soko_t *game);
void move_left(soko_t *game);
void move_right(soko_t *game);
int test_move(soko_t *game, int x, int y);
void win_or_loose(soko_t *game);
void free_map(soko_t *game);
void is_good_size(soko_t *game);

#endif /* !SOKOBAN_H_ */
