/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "../include/sokoban.h"
#include "../include/stuct.h"

void load_game(init_game_t *init, soko_t *game)
{
    init->box = 0;
    init->storage = 0;
    init->walls = 0;

    for (int i = 0; game->map[i]; i++) {
        for (int j = 0; game->map[i][j]; j++) {
            init->box += (game->map[i][j] == 'X') ? 1 : 0;
            init->storage += (game->map[i][j] == 'O') ? 1 : 0;
            init->walls += (game->map[i][j] == '#') ? 1 : 0;
        }
    }
    game->init = init;
    (init->box != init->storage) ? tcheck_ox() : NULL;
    game->walls = malloc(sizeof(obj_t) * init->walls);
    my_memset(game->walls, 0, sizeof(obj_t) * init->walls);
    game->box = malloc(sizeof(obj_t) * init->box);
    my_memset(game->box, 0, sizeof(obj_t) * init->box);
    game->storage = malloc(sizeof(objstrg_t) * init->storage);
    my_memset(game->storage, 0, sizeof(objstrg_t) * init->storage);
}

int main(int ac, char **av)
{
    char **map = NULL;
    soko_t game;
    init_game_t init;

    if (ac != 2) {
        my_putstr("Error: Map, please see -h option for more information\n");
        return (84);
    }
    if (my_strncmp(av[1], "-h", 2) == 0)
        get_man();
    game.map = open_read(av[1], map);
    game.map_save = open_read(av[1], map);
    load_game(&init, &game);
    tcheck_map(&game);
    sokoban(&game);
    free_map(&game);
}