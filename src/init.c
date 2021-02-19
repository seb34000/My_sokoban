/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** init
*/

#include "../include/sokoban.h"
#include "../include/stuct.h"

void init_player(soko_t *game, int x, int y)
{
    static bool test = false;

    if (test == false) {
        game->player.x = x;
        game->player.y = y;
        game->player.orgx = x;
        game->player.orgy = y;
        test = true;
        return ;
    }
    my_putstr("Error: You put 2 player [P] on the map\n");
    exit(84);
}

void init_box(soko_t *game, int x, int y)
{
    static int idx = -1;

    idx++;
    game->box[idx].x = x;
    game->box[idx].y = y;
}

void init_wall(soko_t *game, int x, int y)
{
    static int idx = -1;

    idx++;
    game->walls[idx].x = x;
    game->walls[idx].y = y;
}

void init_storage(soko_t *game, int x, int y)
{
    static int idx = -1;

    idx++;
    game->storage[idx].x = x;
    game->storage[idx].y = y;
    game->storage[idx].test = false;
}