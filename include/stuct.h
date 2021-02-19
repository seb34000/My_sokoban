/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** stuct
*/

#ifndef STUCT_H_
#define STUCT_H_

typedef struct obj_s {
    int x;
    int y;
} obj_t;

typedef struct plyrobj_s {
    int x;
    int y;
    int orgx;
    int orgy;
} plyrobj_t;

typedef struct objstrg_s {
    int x;
    int y;
    bool test;
} objstrg_t;

typedef struct init_game_s {
    size_t walls;
    size_t box;
    size_t storage;
} init_game_t;

typedef struct soko_s {
    char **map;
    char **map_save;
    plyrobj_t player;
    obj_t *walls;
    obj_t *box;
    objstrg_t *storage;
    init_game_t *init;
} soko_t;
#endif /* !STUCT_H_ */
