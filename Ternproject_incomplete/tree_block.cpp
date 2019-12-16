#include "tree_block.h"

// Tree Block 생성자
tree_block::tree_block()
{
    srand((unsigned int)time(NULL));

    block *block_1 = new block( rand() % 4 + 1 );
    block *block_2 = new block( rand() % 4 + 1 );
    block *block_3 = new block( rand() % 4 + 1 );

    block_1->set_location(2, 0);
    block_2->set_location(2, 1);
    block_3->set_location(2, 2);

    block_1->set_parent((long)&v);
    block_2->set_parent((long)&v);
    block_3->set_parent((long)&v);

    big_block::v.push_back(block_1);
    big_block::v.push_back(block_2);
    big_block::v.push_back(block_3);

    array_2d::insert(big_block::v);
    this->shape = 2;
    
    this->min_x = 2;
    this->max_x = 2;
    this->min_y = 0;
    this->max_y = 2;
}

int tree_block::can_rotate()
{
    if(this->min_x == this->max_x)  // 현재 세로 모양
    {
        if(this->min_x + 1 == array_2d::get_board_X_Size()) { return 0; }
        block* left = array_2d::get_block(this->min_x-1, this->max_y-1);
        block* right = array_2d::get_block(this->min_x+1, this->max_y-1);
        if(left->get_color()==0 && right->get_color()==0)
        {
            // 현재 세로모양에 rotate 가능이면 2를 리턴
            return 2;
        }
    }
    else if( this->min_y == this->max_y) // 현재 가로
    {
        if(this->min_y + 1 == array_2d::get_board_Y_Size()) { return 0; }
        block* top = array_2d::get_block(this->max_x-1, this->min_y-1);
        block* bottom = array_2d::get_block(this->max_x-1, this->min_y+1);
        if(top->get_color()==0 && bottom->get_color()==0)
        {
            // 현재 가로모양에 rotate 가능이면 1을 리턴
            return 1;
        }
    }

    return 0;
}

// Tree Block rotate
void tree_block::rotate()
{
    if(can_rotate()==2) // 세로-> 가로 회전
    {   
        block* top;
        block* middle;
        block* bottom;
        vector<block *> newVec;
        for(auto& block : this->v)
        {
            if(block->get_y() == this->min_y){ top = block; }
            else if (block->get_y() == this->max_y) { bottom = block; }
            else { middle = block; }
        }
        block *new_mid = new block(middle->get_color());
        new_mid->set_parent((long)&newVec);
        new_mid->set_location(middle->get_x(), middle->get_y());
        newVec.push_back(new_mid);

        block *new_left = new block(bottom->get_color());
        new_left->set_parent((long)&newVec);
        new_left->set_location(this->min_x-1, this->max_y-1);
        newVec.push_back(new_left);
        
        block *new_right = new block(top->get_color());
        new_right->set_parent((long)&newVec);
        new_right->set_location(this->min_x+1, this->max_y-1);
        newVec.push_back(new_right);
        array_2d::delete_block(this->v);
        this->v.clear();
        this->v = newVec;
        array_2d::insert(this->v);
        this->max_x = this->max_x + 1;
        this->min_x = this->min_x - 1;
        this->max_y = this->max_y - 1;
        this->min_y = this->min_y + 1;
    }
    else if(can_rotate()==1) // 가로 -> 세로 회전
    {
        block* left;
        block* middle;
        block* right;
        vector<block *> newVec;
        for(auto& block : this->v)
        {
            if(block->get_x() == this->min_x)
            {
                left = block;
            }
            else if (block->get_x() == this->max_x)
            {
                right = block;
            }
            else
            {
                middle = block;
            }
        }
        block *new_mid = new block(middle->get_color());
        new_mid->set_parent((long)&newVec);
        new_mid->set_location(middle->get_x(), middle->get_y());
        newVec.push_back(new_mid);

        block *new_top = new block(left->get_color());
        new_top->set_parent((long)&newVec);
        new_top->set_location(this->min_x+1, this->min_y-1);
        newVec.push_back(new_top);
        
        block *new_bottom = new block(right->get_color());
        new_bottom->set_parent((long)&newVec);
        new_bottom->set_location(this->max_x-1, this->max_y+1);
        newVec.push_back(new_bottom);
        array_2d::delete_block(this->v);
        this->v.clear();
        this->v = newVec;
        array_2d::insert(this->v);
        this->max_x = this->max_x - 1;
        this->min_x = this->min_x + 1;
        this->max_y = this->max_y + 1;
        this->min_y = this->min_y - 1;
    }
    else{
        return;
    }
}

