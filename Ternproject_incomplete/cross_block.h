#ifndef TERM_CROSSBLOCK_H
#define TERM_CROSSBLOCK_H

#include "block.h"
#include "array_2d.h"
#include "big_block.h"
#include "color_block.h"

class cross_block : public big_block {
public:
    cross_block();
    void rotate();
};

#endif
