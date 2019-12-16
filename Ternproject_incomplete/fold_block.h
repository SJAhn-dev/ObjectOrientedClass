#ifndef TERM_FOLDBLOCK_H
#define TERM_FOLDBLOCK_H

#include "block.h"
#include "array_2d.h"
#include "big_block.h"
#include "color_block.h"

using namespace std;

class fold_block : public big_block {
public:
    // angle 1 (ㄴ 반대), angle 2(ㄴ 모양), angle 3(ㄱ 반대), angle 4(ㄱ 모양)
    int angle;
    fold_block();
    int can_rotate();
    void rotate();
};

#endif