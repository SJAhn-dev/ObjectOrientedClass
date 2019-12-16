#ifndef TERM_COLORBLOCK_H
#define TERM_COLORBLOCK_H

#include <set>
#include "block.h"
#include "big_block.h"
#include "array_2d.h"

using namespace std;
class block;
class color_block {
private:
    set<block *> s;
    int set_color;
public:
    color_block(block *b);
    void insert(block* cb);
    void insert(set<block *> s);
    set<block *> get_set();
    int get_set_size();
    void explode_block();
    int get_color();
};

#endif