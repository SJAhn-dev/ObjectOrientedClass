#include <iostream>
#include "array_2d.h"
#include "big_block.h"
#include "tree_block.h"
#include "fold_block.h"
#include "cross_block.h"
#include "color_block.h"

using namespace std;

array_2d *game_board = new array_2d();
big_block *block_fold;
big_block *block_tree;
big_block *block_cross;
big_block *control_block;
bool create_new_block;
bool game_start = true;


bool create_block()
{   
    bool created = false;
    if(!game_start) { array_2d::check_color(control_block->v); }
    srand((unsigned int)time(0));
    int block_shape = rand() % 3 + 1;
    if(block_shape==1 && game_board->can_make(1))
    {
        block_fold = new fold_block();
        control_block = block_fold;
        created = true;
    }
    else if(block_shape==2 && game_board->can_make(2))
    {
        block_tree = new tree_block();
        control_block = block_tree;
        created = true;
    }
    else if(block_shape==3 && game_board->can_make(3))
    {
        block_cross = new cross_block();
        control_block = block_cross;
        created = true;
    }
    if(game_start) { game_start = false; }
    return created;
}


void input_key()
{
    cout << "|  Input Key!! : ";
    string control;
    getline(cin, control);

    if(control=="a" && control_block->can_left() )
    {
        control_block->move_left();
    }
    if(control=="d" && control_block->can_right() )
    {
        control_block->move_right();
    }
    if(control=="s")
    {
        if(control_block->can_down()) {
            control_block->move_down();
            if(!control_block->can_down())
            {
                create_new_block = true;
            }
        }
    }
    if(control == "x")
    {
        control_block->move_down_all();
        create_new_block = true;
    }
    if(control =="e")
    {
        control_block->rotate();
    }

    if(create_new_block)
    {
        control_block->~big_block();
    }
}

int main()
{
    while(1)
    {
        if(!create_block()) { break; }
        create_new_block = false;
        while(1)
        {
            game_board->print();
            input_key();
            if(create_new_block) { break; }
        }
    }
    cout << "Game Over.. Try Again" << endl;
    return 0;
}
