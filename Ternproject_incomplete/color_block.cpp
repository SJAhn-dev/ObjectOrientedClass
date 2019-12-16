#include "color_block.h"

using namespace std;

color_block::color_block(block *b)
{
    this->s.insert(b);
    this->set_color = b->get_color();
    b->set_group(this);
}

void color_block::insert(block* b)
{
    this->s.insert(b);
    b->set_group(this);
}

void color_block::insert(set<block *> s)
{
    for (auto& block : s)
    {
        this->s.insert(block);
        block->set_group(this);
    }
}

set<block *> color_block::get_set()
{
    return this->s;
}

int color_block::get_set_size()
{
    return this->s.size();
}

int color_block::get_color()
{
    return this->set_color;
}

void color_block::explode_block()
{
    for (auto& block : this->s)
    {
        block->explode();
    }
}