#include "cross_block.h"

// Cross Block 생성자
cross_block::cross_block()
{
    srand((unsigned int)time(NULL));

    block *block_1 = new block( rand() % 4 + 1 );
    block *block_2 = new block( rand() % 4 + 1 );
    block *block_3 = new block( rand() % 4 + 1 );
    block *block_4 = new block( rand() % 4 + 1 );
    block *block_5 = new block( rand() % 4 + 1 );

    block_1->set_location(2, 0);
    block_2->set_location(2, 1);
    block_3->set_location(2, 2);
    block_4->set_location(1, 1);
    block_5->set_location(3, 1);

    block_1->set_parent((long)&v);
    block_2->set_parent((long)&v);
    block_3->set_parent((long)&v);
    block_4->set_parent((long)&v);
    block_5->set_parent((long)&v);

    big_block::v.push_back(block_1);
    big_block::v.push_back(block_2);
    big_block::v.push_back(block_3);
    big_block::v.push_back(block_4);
    big_block::v.push_back(block_5);

    array_2d::insert(big_block::v);
    this->shape = 3;

    this->min_x = 1;
    this->max_x = 3;
    this->min_y = 0;
    this->max_y = 2;
}


// Cross Block Rotate
void cross_block::rotate()
{
    block* top = array_2d::get_block(this->max_x-1, this->min_y);
    block* left = array_2d::get_block(this->min_x, this->max_y-1);
    block* right = array_2d::get_block(this->max_x, this->max_y-1);
    block* bottom = array_2d::get_block(this->max_x-1, this->max_y);
    
    int color_save = right->get_color();
    right->set_color( top->get_color() );
    top->set_color( left->get_color() );
    left->set_color( bottom->get_color() );
    bottom->set_color( color_save );
}