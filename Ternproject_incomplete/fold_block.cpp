#include "fold_block.h"

// Fold Block 생성자
fold_block::fold_block()
{
    srand((unsigned int)time(NULL));

    block *block_1 = new block( rand() % 4 + 1 );
    block *block_2 = new block( rand() % 4 + 1 );
    block *block_3 = new block( rand() % 4 + 1 );

    block_1->set_location(2, 0);
    block_2->set_location(2, 1);
    block_3->set_location(1, 1);

    block_1->set_parent((long)&v);
    block_2->set_parent((long)&v);
    block_3->set_parent((long)&v);

    big_block::v.push_back(block_1);
    big_block::v.push_back(block_2);
    big_block::v.push_back(block_3);

    array_2d::insert(big_block::v);
    this->shape = 1;
    this->angle = 1;

    this->min_x = 1;
    this->max_x = 2;
    this->min_y = 0;
    this->max_y = 1;
}

int fold_block::can_rotate()
{
    int temp_shape = this->angle;
    block* zeroBlock;
    if(temp_shape==1)
    {
        zeroBlock = array_2d::get_block(this->min_x, this->min_y);
        if(zeroBlock->get_color()==0) { return 1; }
    }
    else if(temp_shape==2)
    {
        zeroBlock = array_2d::get_block(this->max_x, this->min_y);
        if(zeroBlock->get_color()==0) { return 2; }
    }
    else if(temp_shape==3)
    {
        zeroBlock = array_2d::get_block(this->max_x, this->max_y);
        if(zeroBlock->get_color()==0) { return 3; }
    }
    else if(temp_shape==4)
    {
        zeroBlock = array_2d::get_block(this->min_x, this->max_y);
        if(zeroBlock->get_color()==0) { return 4; }
    }
    return 0;
}

void fold_block::rotate()
{
    vector<block *> newVec;
    block* part_1; block* part_2; block* part_3;
    if(can_rotate()==1)
    {
        for(auto& block : this->v)
        {
            if(block->get_x()==this->min_x && block->get_y()==this->max_y)
            {
                part_1 = block;
            }
            else if(block->get_x()==this->max_x && block->get_y()==this->max_y)
            {
                part_2 = block;
            }
            else if(block->get_x()==this->max_x && block->get_y()==this->min_y)
            {
                part_3 = block;
            }
        }
        block* new_part_1 = new block(part_1->get_color());
        block* new_part_2 = new block(part_2->get_color());
        block* new_part_3 = new block(part_3->get_color());
        new_part_1->set_location(this->min_x, this->min_y);
        new_part_2->set_location(this->min_x, this->max_y);
        new_part_3->set_location(this->max_x, this->max_y);
        new_part_1->set_parent(part_1->get_parent());
        new_part_2->set_parent(part_2->get_parent());
        new_part_3->set_parent(part_3->get_parent());
        newVec.push_back(new_part_1);
        newVec.push_back(new_part_2);
        newVec.push_back(new_part_3);

        array_2d::delete_block(this->v);
        this->v.clear();
		this->angle = 2;
        this->v = newVec;
        array_2d::insert(this->v);
    }
    else if(can_rotate()==2)
    {
        for(auto& block : this->v)
        {
            if(block->get_x()==this->min_x && block->get_y()==this->min_y)
            {
                part_1 = block;
            }
            else if(block->get_x()==this->min_x && block->get_y()==this->max_y)
            {
                part_2 = block;
            }
            else if(block->get_x()==this->max_x && block->get_y()==this->max_y)
            {
                part_3 = block;
            }
        }
        block* new_part_1 = new block(part_1->get_color());
        block* new_part_2 = new block(part_2->get_color());
        block* new_part_3 = new block(part_3->get_color());
        new_part_1->set_location(this->max_x, this->min_y);
        new_part_2->set_location(this->min_x, this->min_y);
        new_part_3->set_location(this->min_x, this->max_y);
        new_part_1->set_parent(part_1->get_parent());
        new_part_2->set_parent(part_2->get_parent());
        new_part_3->set_parent(part_3->get_parent());
        newVec.push_back(new_part_1);
        newVec.push_back(new_part_2);
        newVec.push_back(new_part_3);

        array_2d::delete_block(this->v);
        this->v.clear();
		this->angle = 3;
        this->v = newVec;
        array_2d::insert(this->v);
    }
    else if(can_rotate()==3)
    {
        for(auto& block : this->v)
        {
            if(block->get_x()==this->max_x && block->get_y()==this->min_y)
            {
                part_1 = block;
            }
            else if(block->get_x()==this->min_x && block->get_y()==this->min_y)
            {
                part_2 = block;
            }
            else if(block->get_x()==this->min_x && block->get_y()==this->max_y)
            {
                part_3 = block;
            }
        }
        block* new_part_1 = new block(part_1->get_color());
        block* new_part_2 = new block(part_2->get_color());
        block* new_part_3 = new block(part_3->get_color());
        new_part_1->set_location(this->max_x, this->max_y);
        new_part_2->set_location(this->max_x, this->min_y);
        new_part_3->set_location(this->min_x, this->min_y);
        new_part_1->set_parent(part_1->get_parent());
        new_part_2->set_parent(part_2->get_parent());
        new_part_3->set_parent(part_3->get_parent());
        newVec.push_back(new_part_1);
        newVec.push_back(new_part_2);
        newVec.push_back(new_part_3);

        array_2d::delete_block(this->v);
        this->v.clear();
		this->angle = 4;
        this->v = newVec;
        array_2d::insert(this->v);
    }
    else if(can_rotate()==4)
    {
        for(auto& block : this->v)
        {
            if(block->get_x()==this->max_x && block->get_y()==this->max_y)
            {
                part_1 = block;
            }
            else if(block->get_x()==this->max_x && block->get_y()==this->min_y)
            {
                part_2 = block;
            }
            else if(block->get_x()==this->min_x && block->get_y()==this->min_y)
            {
                part_3 = block;
            }
        }
        block* new_part_1 = new block(part_1->get_color());
        block* new_part_2 = new block(part_2->get_color());
        block* new_part_3 = new block(part_3->get_color());
        new_part_1->set_location(this->min_x, this->max_y);
        new_part_2->set_location(this->max_x, this->max_y);
        new_part_3->set_location(this->max_x, this->min_y);
        new_part_1->set_parent(part_1->get_parent());
        new_part_2->set_parent(part_2->get_parent());
        new_part_3->set_parent(part_3->get_parent());
        newVec.push_back(new_part_1);
        newVec.push_back(new_part_2);
        newVec.push_back(new_part_3);

        array_2d::delete_block(this->v);
        this->v.clear();
		this->angle = 1;
        this->v = newVec;
        array_2d::insert(this->v);
    }

    return;
}
