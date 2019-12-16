#ifndef TERM_BIGBLOCK_H
#define TERM_BIGBLOCK_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include "block.h"
#include "array_2d.h"
using namespace std;

class block;
class big_block {
public:
    int shape;
    vector<block *> v;
    static int min_x, min_y, max_x, max_y;
    ~big_block();
    bool can_left();
    bool can_right();
    bool can_down();
    bool move(int input);

    void move_left();
    void move_right();
    void move_down();
    void move_down_all();
    virtual void rotate();
};

#endif