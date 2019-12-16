#ifndef TERM_ARRAY2D_H
#define TERM_ARRAY2D_H

#include "block.h"
#include "color_block.h"
#include "big_block.h"
#include <stack>
#include <iostream>

using namespace std;
class block;
class color_block;
class array_2d{
private:
    static const int X = 5;
    static const int Y = 12;
    static block *block_array[Y][X];
    static bool can_visit[Y][X];
    static int score;
    static set<block *> merge;
public:
    array_2d();
    bool can_make(int shape);
    static void delete_block(int x, int y);
    static void delete_block(vector<block *> v);
    static void insert(vector<block *> v);
    static void insert(int x, int y, block* b);
    static block *get_block(int x, int y);
    static bool can_move(int x, int y);
    void print();
    int get_score();

    static int get_board_X_Size();
    static int get_board_Y_Size();
    static void rotate();
    static void gravity();

    static void check_color(vector<block* > v);

    static void swap_block(int firstX, int firstY, int secondX, int secondY);
};

#endif