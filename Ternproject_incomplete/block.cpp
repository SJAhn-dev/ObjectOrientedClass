#include "block.h"
#include "array_2d.h"

// Block 생성자
block::block(int color)
{
    this->color = color;
}

// Block 소멸자 ( color를 0으로 만들음 )
block::~block()
{
    this->color = 0;
    this->parent = NULL;
}

// Block Color 접근
int block::get_color()
{
    return this->color;
}

// Block Vector 접근
long block::get_parent()
{
    return this->parent;
}

// Block X 접근
int block::get_x()
{
    return this->x;
}

// Block Y 접근
int block::get_y()
{
    return this->y;
}

// Block 좌표 설정
void block::set_location(int x, int y)
{
    this-> y = y;
    this-> x = x;
}

// Block 색상 설정
void block::set_color(int color)
{
    this->color = color;
}

// Block 부모 설정
void block::set_parent(long par)
{
    this->parent = par;
}

// Block Left Check
bool block::can_left()
{
    block *left_block = array_2d::get_block(this->x - 1, this->y);
    if( this-> x-1 < 0 ) { return false; }
    else if( this->parent != left_block->parent && left_block->get_color()!=0 )
    { 
        return false;
    }
    else
    {
        return true;
    }
}

// Block Right Check
bool block::can_right()
{
    block *right_block = array_2d::get_block(this->x + 1, this->y);
    if( this-> x+1 >= array_2d::get_board_X_Size() ) { return false; }
    else if( this->parent != right_block->parent && right_block->get_color()!=0 )
    { 
        return false;
    }
    else
    {
        return true;
    }
}

// Block Down Check
bool block::can_down()
{   
    if( this->y + 1 >= array_2d::get_board_Y_Size() ) { return false; }
    block *down_block = array_2d::get_block(this->x, this->y + 1);
    if( this->parent != down_block->parent && down_block->get_color()!=0 )
    { 
        return false;
    }
    else
    {
        return true;
    }
}

// Block Move to Right
void block::move_right()
{
    block *right_block = array_2d::get_block(this->x+1, this->y);
    right_block->set_color(this->color);
    right_block->set_parent(this->parent);
    this->color = 0;
    this->parent  = NULL;
}

// Block Move to Left
void block::move_left()
{
    block *left_block = array_2d::get_block(this->x-1, this->y);
    left_block->set_color(this->color);
    left_block->set_parent(this->parent);
}

// Block Move to Down
void block::move_down()
{
    // inhgerit
}

// Block Move to Down_all
void block::move_down_all()
{
    if(can_down())
    {   
        move_down();
        return array_2d::get_block(this->x, this->y+1)->move_down();
    }
    else
    {
        return;
    }
}

bool block::have_set()
{
    return this->haveSet;
}

color_block* block::get_color_set()
{
    return this->group;
}

void block::set_group(color_block* group)
{
    this->group = group;
}

void block::merge(block *b)
{
    this->group->insert(b);
    b->set_group(this->group);
}

void block::explode()
{
    if(color==1)
    {
        cout << "ex-1" << endl;
        array_2d::delete_block(this->x, this->y);
    }
    else
    {
        cout << "ex-2" << endl;
        if(this->x-1 >=0 && array_2d::get_block(this->x-1, this->y)->get_color()==1)
        {
            array_2d::get_block(this->x-1, this->y)->explode();
        }
        if(this->x+1 == array_2d::get_board_X_Size() 
            && array_2d::get_block(this->x+1, this->y)->get_color()==1)
        {
            array_2d::get_block(this->x+1, this->y)->explode();
        }
        if(this->y-1 >= 0 
            && array_2d::get_block(this->x, this->y-1)->get_color()==1)
        {
            array_2d::get_block(this->x, this->y-1)->explode();
        }
        if(this->y+1 == array_2d::get_board_Y_Size() 
            && array_2d::get_block(this->x, this->y+1)->get_color()==1)
        {
            array_2d::get_block(this->x, this->y+1)->explode();
        }
        cout << "ex-3" << endl;
    }
    
}
