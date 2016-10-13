#ifndef DEFINES_H
#define DEFINES_H

#include <stdlib.h>
#include <stdio.h>

#define NB_BLOCKS   8
#define BLOCK_SIZE  87.5
#define BOARD_SIZE  NB_BLOCKS * BLOCK_SIZE

#define WINDOW_WIDTH    1200
#define WINDOW_HEIGHT   800

typedef struct units
{
    short ID;
    short range;
    short blocks_per_move;
}units;

enum units_ID { RABBLE, SPEARMAN, CROSSBOWMAN, L_HORSE, H_HORSE, TREBUCHET, CATAPULT, ELEPHANT, DRAGON, KING };
enum tiles_ID { GRASS, FOREST, WATER, MOUNTAIN, FORTRESS, RUIN };

#endif // DEFINES_H
