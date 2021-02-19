/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** move_player
*/

#include "../include/sokoban.h"
#include "../include/stuct.h"

void move_up(soko_t *game)
{
    int org_x = game->player.x;
    int org_y = game->player.y;

    if (test_move(game, game->player.x - 1, game->player.y) == 0) {
        game->player.x -= 1;
        game->map[org_x][org_y] = ' ';
        game->map[org_x -= 1][org_y] = 'P';
    } else if (test_move(game, game->player.x - 1, game->player.y) == 1) {
        if (test_move(game, game->player.x - 2, game->player.y) == 0 \
        || test_move(game, game->player.x - 2, game->player.y) == 2) {
            game->player.x -= 1;
            game->map[org_x][org_y] = ' ';
            game->map[org_x -= 1][org_y] = 'P';
            game->map[org_x - 1][org_y] = 'X';
        }
    } else if (test_move(game, game->player.x - 1, game->player.y) == 2) {
        game->player.x -= 1;
        game->map[org_x][org_y] = ' ';
        game->map[org_x -= 1][org_y] = 'P';
    }
    print_map(game);
}

void move_down(soko_t *game)
{
    int org_x = game->player.x;
    int org_y = game->player.y;

    if (test_move(game, game->player.x + 1, game->player.y) == 0) {
        game->player.x += 1;
        game->map[org_x][org_y] = ' ';
        game->map[org_x += 1][org_y] = 'P';
    } else if (test_move(game, game->player.x + 1, game->player.y) == 1) {
        if (test_move(game, game->player.x + 2, game->player.y) == 0 \
        || test_move(game, game->player.x + 2, game->player.y) == 2) {
            game->player.x += 1;
            game->map[org_x][org_y] = ' ';
            game->map[org_x += 1][org_y] = 'P';
            game->map[org_x + 1][org_y] = 'X';
        }
    } else if (test_move(game, game->player.x + 1, game->player.y) == 2) {
        game->player.x += 1;
        game->map[org_x][org_y] = ' ';
        game->map[org_x += 1][org_y] = 'P';
    }
    print_map(game);
}

void move_left(soko_t *game)
{
    int org_x = game->player.x;
    int org_y = game->player.y;

    if (test_move(game, game->player.x, game->player.y - 1) == 0) {
        game->player.y -= 1;
        game->map[org_x][org_y] = ' ';
        game->map[org_x][org_y -= 1] = 'P';
    } else if (test_move(game, game->player.x, game->player.y - 1) == 1) {
        if (test_move(game, game->player.x, game->player.y - 2) == 0 \
        || test_move(game, game->player.x, game->player.y - 2) == 2) {
            game->player.y -= 1;
            game->map[org_x][org_y] = ' ';
            game->map[org_x][org_y -= 1] = 'P';
            game->map[org_x][org_y - 1] = 'X';
        }
    } else if (test_move(game, game->player.x, game->player.y - 1) == 2) {
        game->player.y -= 1;
        game->map[org_x][org_y] = ' ';
        game->map[org_x][org_y -= 1] = 'P';
    }
    print_map(game);
}

void move_right(soko_t *game)
{
    int org_x = game->player.x;
    int org_y = game->player.y;

    if (test_move(game, game->player.x, game->player.y + 1) == 0) {
        game->player.y += 1;
        game->map[org_x][org_y] = ' ';
        game->map[org_x][org_y += 1] = 'P';
    } else if (test_move(game, game->player.x, game->player.y + 1) == 1) {
        if (test_move(game, game->player.x, game->player.y + 2) == 0 \
        || test_move(game, game->player.x, game->player.y + 2) == 2) {
            game->player.y += 1;
            game->map[org_x][org_y] = ' ';
            game->map[org_x][org_y += 1] = 'P';
            game->map[org_x][org_y + 1] = 'X';
        }
    } else if (test_move(game, game->player.x, game->player.y + 1) == 2) {
        game->player.y += 1;
        game->map[org_x][org_y] = ' ';
        game->map[org_x][org_y += 1] = 'P';
    }
    print_map(game);
}