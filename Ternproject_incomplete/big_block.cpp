#include "big_block.h"

int big_block::min_x = 0;
int big_block::max_x = 0;
int big_block::min_y = 0;
int big_block::max_y = 0;

// big_block 소멸자
big_block::~big_block()
{
    
}

// Big_block 왼쪽 이동 판별
bool big_block::can_left()
{
    bool canLeft = true;
    for(auto& idx : this->v)
    {
        if(!idx->can_left()) { canLeft = false; }
    }
    return canLeft;
}

// Big_block 오른쪽 이동 판별
bool big_block::can_right()
{
    bool canRight = true;
    for(auto& idx : this->v)
    {
        if(!idx->can_right()) { canRight = false; }
    }
    return canRight;
}

// Big_block 아래쪽 이동 판별
bool big_block::can_down()
{
    bool canDown = true;
    for(auto& idx : this->v)
    {
        if(!idx->can_down()) { canDown = false; }
    }
    return canDown;
}

// Big_block 왼쪽 이동
void big_block::move_left()
{
    vector<block *> newVec;
    if(can_left())
    {
        for(auto& idx : this->v)
        {
            block *newBlock = new block(idx->get_color());
            newBlock->set_parent(idx->get_parent());
            newBlock->set_location(idx->get_x()-1, idx->get_y());
            newVec.push_back(newBlock);
        }
        for(auto& idx : this->v)
        {
            array_2d::delete_block(idx->get_x(), idx->get_y());
        }
        this->v.clear();
        this->v = newVec;
        array_2d::insert(this->v);
        this->min_x--;
        this->max_x--;
    }
        
}

// Big Block 오른쪽 이동
void big_block::move_right()
{
    vector<block *> parent;
    if(can_right())
    {
        vector<block *> newVec;
        for(auto& idx : this->v)
        {
            block *newBlock = new block(idx->get_color());
            newBlock->set_parent(idx->get_parent());
            newBlock->set_location(idx->get_x()+1, idx->get_y());
            newVec.push_back(newBlock);
        }
        for(auto& idx : this->v)
        {
            array_2d::delete_block(idx->get_x(), idx->get_y());
        }
        this->v.clear();
        this->v = newVec;
        array_2d::insert(this->v);
        this->min_x++;
        this->max_x++;
    }
}

// Big Block 아래쪽 이동
void big_block::move_down()
{
    if(can_down())
    {
        vector<block *> newVec;
        for(auto& idx : this->v)
        {
            block *newBlock = new block(idx->get_color());
            newBlock->set_parent(idx->get_parent());
            newBlock->set_location(idx->get_x(), idx->get_y()+1);
            newVec.push_back(newBlock);
        }
        for(auto& idx : this->v)
        {
            array_2d::delete_block(idx->get_x(), idx->get_y());
        }
        this->v.clear();
        this->v = newVec;
        array_2d::insert(this->v);
        this->min_y++;
        this->max_y++;
    }
}

// Big Block 아래쪽 끝까지 이동
void big_block::move_down_all()
{
    while(can_down())
    {
        move_down();
    }
}

// Big Block rotate - inherit 구현
void big_block::rotate()
{
    //inherit
}
