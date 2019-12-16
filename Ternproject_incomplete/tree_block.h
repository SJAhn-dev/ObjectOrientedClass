#ifndef TERM_TREEBLOCK_H
#define TERM_TREEBLOCK_H

#include "block.h"
#include "array_2d.h"
#include "big_block.h"
#include "color_block.h"

class tree_block : public big_block {
public:
    tree_block();
    void rotate();
    int can_rotate();
};

#endif
