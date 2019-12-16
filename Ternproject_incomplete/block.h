#ifndef TERM_BLOCK_H
#define TERM_BLOCK_H

#include "color_block.h"
#include "big_block.h"

class block{
private:
    int x,y;
    int color;
    long parent;
    bool haveSet;
    color_block *group;
public :
    // Block 생성 & 소멸자
    block(int color);
    ~block();

    // Block 접근자
    int get_x();
    int get_y();
    int get_color();
    long get_parent();

    // Block 설정자
    void set_color(int color);
    void set_location(int y, int x);
    void set_parent(long par);

    // Block 이동 가능여부 판별
    bool can_left();
    bool can_right();
    bool can_down();

    // Block 이동
    void move_right();
    void move_left();
    void move_down();
    void move_down_all();

    // Block Explode 관련함수
    color_block *get_color_set();
    void set_group(color_block* group);
    void merge(block *b);
    void find_merge();
    bool have_set();
    void explode();
};

#endif