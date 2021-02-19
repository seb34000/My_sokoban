/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** freeall
*/

#include "../include/sokoban.h"
#include "../include/stuct.h"

void free_map(soko_t *game)
{
    for (size_t i = 0; game->map[i]; i++) {
        free (game->map[i]);
        free (game->map_save[i]);
    }
    free (game->map);
    free (game->map_save);
    free (game->box);
    free (game->walls);
    free (game->storage);
}