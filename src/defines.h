#ifndef DEFINES_H
#define DEFINES_H

#include <stdlib.h>
#include <stdio.h>

#define NB_BLOCKS   8
#define BLOCK_SIZE  80
#define BOARD_SIZE  NB_BLOCKS * BLOCK_SIZE

typedef struct units
{
    short ID;
    short range;
    short blocks_per_move;
}units;

enum units_ID { rabble, spearman, crossbowman, l_horse, h_horse, trebuchet, catapult, elephant, dragon, king };
enum tiles_ID { grass, forest, water, mountain, fortress, ruin };

#endif // DEFINES_H
