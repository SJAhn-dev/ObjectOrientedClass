#include "array_2d.h"
#include <iostream>


int array_2d::score = 0;
block *array_2d::block_array[Y][X] = {0,};

// array_2d 생성자
array_2d::array_2d()
{
    array_2d::score = 0;
    for(int y = 0; y < Y; y++)
    {
        for(int x = 0; x < X; x++)
        {
            block_array[y][x] = new block(0);
            block_array[y][x]->set_location(x,y);
        }
    }
}

// array_2d Block Create 검사
bool array_2d::can_make(int shape)
{
    bool makeOk = false;

    if(shape==1) // Fold
    {
        if(block_array[0][2]->get_color() == 0 &&
        block_array[1][2]->get_color() == 0 &&
        block_array[1][1]->get_color() == 0)
        {
            makeOk = true;
        }
    }
    if(shape==2) // Tree
    {
        if(block_array[0][2]->get_color() == 0 &&
        block_array[1][2]->get_color() == 0 &&
        block_array[2][2]->get_color() == 0)
        {
            makeOk = true;
        }
    }
    if(shape==3) // Cross
    {
        if(block_array[0][2]->get_color() == 0 &&
        block_array[1][2]->get_color() == 0 &&
        block_array[2][2]->get_color() == 0 &&
        block_array[1][1]->get_color() == 0 &&
        block_array[1][3]->get_color() == 0)
        {
            makeOk = true;
        }
    }
}

// array_2d 블록 제거
void array_2d::delete_block(vector<block *> v)
{
    for(auto& idx : v)
    {
        delete_block(idx->get_x(), idx->get_y());
    }
}

// array_2d 블록 제거 ( Overloading )
void array_2d::delete_block(int x, int y)
{
    block_array[y][x]->~block();
}

// array_2d 블록 삽입
void array_2d::insert(vector<block *> v) 
{
    for(auto& idx : v)
    {
        insert(idx->get_x(), idx->get_y(), idx);
    }
}

// array_2d 블록 삽입 ( Overloading )
void array_2d::insert(int x, int y, block *b)
{
    block_array[y][x] = b;
}

// array_2d 해당 좌표에 있는 block 리턴
block* array_2d::get_block(int x, int y)
{
    return block_array[y][x];
}

// array_2d Game Board Print
void array_2d::print()
{   
    cout << "-------------------\n";
    cout << "| Your Score : " << get_score() << "  |\n"; 
    cout << "-------------------\n";
    for(int y = 0; y < Y; y++)
    {   
        cout << "|  " ;
        for(int x = 0; x < X; x++)
        {
            if(block_array[y][x]->get_color()==1)
            {
                cout << "g  ";
            }
            else if(block_array[y][x]->get_color()==2)
            {
                cout << "R  ";
            }
            else if(block_array[y][x]->get_color()==3)
            {
                cout << "G  ";
            }
            else if(block_array[y][x]->get_color()==4)
            {
                cout << "B  ";
            }
            else
            {
                cout << "-  ";
            }
        }
        cout << "|\n";
    }
    cout << "-------------------\n";
}

// array_2d Get Score
int array_2d::get_score() 
{
    return score;
}

int array_2d::get_board_X_Size()
{
    return X;
}

int array_2d::get_board_Y_Size()
{
    return Y;
}

// array_2d 에서 BigBlock 제어 이후 Gravity 보정에 따른 block 조정
void array_2d::gravity()
{
    for(int y=0; y < Y-1; y++)
    {
        for(int x=0; x < X; x++)
        {
            block *top = block_array[y][x];
            block *bottom = block_array[y+1][x];

            if(top->get_color() != 0 && bottom->get_color() == 0)
            {
                block_array[y+1][x] = top;
                top->set_location(x, y+1);
                block_array[y][x] = new block(0);
                x--;
                y--;
            }
        }
    }
}

// array_2d Swaping Block
void array_2d::swap_block(int firstX, int firstY, int secondX, int secondY)
{
    block* temp = array_2d::get_block(firstX, firstY);
    block_array[firstY][firstX] = block_array[secondY][secondX];
    block_array[secondY][secondX] = temp;
}

void array_2d::check_color(vector<block* > v)
{
	array_2d::gravity();
    stack<color_block* > stack;
    for(auto& block : v)
    {   
        if(block->get_color()==1) { continue; }
        bool findSet = false;
        int blockY = block->get_y();
        int blockX = block->get_x();
        // Left Block 색 검사
        if(blockX-1 >= 0 && block_array[blockY][blockX-1]->get_color() == block->get_color())
        {
            // block이 set이 없고 옆은 있을때
            if(!findSet && block_array[blockY][blockX-1]->have_set())
            {
                block_array[blockY][blockX-1]->merge(block);
                findSet = true;
                if(block->get_color_set()->get_set_size() >=4 )
                {
                    stack.push(block->get_color_set());
                }
            } // block이 set이 없고 옆도 없을때
            else if(!findSet && !block_array[blockY][blockX-1]->have_set())
            {
                color_block* cb = new color_block(block);
                block->merge(block_array[blockY][blockX-1]);
                findSet = true;
                if(block->get_color_set()->get_set_size() >=4 )
                {
                    stack.push(block->get_color_set());
                }
            } // block이 set이 있고 옆은 없을때
            else if(findSet && !block_array[blockY][blockX-1]->have_set())
            {
                block->merge(block_array[blockY][blockX-1]);
                findSet = true;
                if(block->get_color_set()->get_set_size() >=4 )
                {
                    stack.push(block->get_color_set());
                }
            }
            else if(findSet && block_array[blockY][blockX-1]->have_set())
            {
                block_array[blockY][blockX-1]->get_color_set()
                ->insert(block->get_color_set()->get_set());
                findSet = true;
                if(block->get_color_set()->get_set_size() >=4 )
                {
                    stack.push(block->get_color_set());
                }
            }
            if(!findSet) { color_block* cb = new color_block(block); }
        }
        // 오른쪽 블록
        if(blockX+1 < X && block_array[blockY][blockX+1]->get_color() == block->get_color())
        {
            // block이 set이 없고 옆은 있을때
            if(!findSet && block_array[blockY][blockX+1]->have_set())
            {
                block_array[blockY][blockX+1]->merge(block);
                findSet = true;
                if(block->get_color_set()->get_set_size() >=4 )
                {
                    stack.push(block->get_color_set());
                }
            } // block이 set이 없고 옆도 없을때
            else if(!findSet && !block_array[blockY][blockX+1]->have_set())
            {
                color_block* cb = new color_block(block);
                block->merge(block_array[blockY][blockX+1]);
                findSet = true;
                if(block->get_color_set()->get_set_size() >=4 )
                {
                    stack.push(block->get_color_set());
                }
            } // block이 set이 있고 옆은 없을때
            else if(findSet && !block_array[blockY][blockX+1]->have_set())
            {
                block->merge(block_array[blockY][blockX+1]);
                findSet = true;
                if(block->get_color_set()->get_set_size() >=4 )
                {
                    stack.push(block->get_color_set());
                }
            }
            else if(findSet && block_array[blockY][blockX+1]->have_set())
            {
                block_array[blockY][blockX+1]->get_color_set()
                ->insert(block->get_color_set()->get_set());
                findSet = true;
                if(block->get_color_set()->get_set_size() >=4 )
                {
                    stack.push(block->get_color_set());
                }
            }
            if(!findSet) { color_block* cb = new color_block(block); }
        }

        // 위쪽 블록
        if(blockY-1 >= 0 && block_array[blockY-1][blockX]->get_color() == block->get_color())
        {
            // block이 set이 없고 옆은 있을때
            if(!findSet && block_array[blockY-1][blockX]->have_set())
            {
                block_array[blockY-1][blockX]->merge(block);
                findSet = true;
                if(block->get_color_set()->get_set_size() >=4 )
                {
                    stack.push(block->get_color_set());
                }
            } // block이 set이 없고 옆도 없을때
            else if(!findSet && !block_array[blockY-1][blockX]->have_set())
            {
                color_block* cb = new color_block(block);
                block->merge(block_array[blockY-1][blockX]);
                findSet = true;
                if(block->get_color_set()->get_set_size() >=4 )
                {
                    stack.push(block->get_color_set());
                }
            } // block이 set이 있고 옆은 없을때
            else if(findSet && !block_array[blockY-1][blockX]->have_set())
            {
                block->merge(block_array[blockY-1][blockX]);
                if(block->get_color_set()->get_set_size() >=4 )
                {
                    stack.push(block->get_color_set());
                }
            }
            else if(findSet && block_array[blockY-1][blockX]->have_set())
            {
                block_array[blockY-1][blockX]->get_color_set()
                ->insert(block->get_color_set()->get_set());
                findSet = true;
                if(block->get_color_set()->get_set_size() >=4 )
                {
                    stack.push(block->get_color_set());
                }
            }
            if(!findSet) { color_block* cb = new color_block(block); }
        }

        // 아래쪽 블록
        if(blockY+1 < Y && block_array[blockY+1][blockX]->get_color() == block->get_color())
        {
            // block이 set이 없고 옆은 있을때
            if(!findSet && block_array[blockY+1][blockX]->have_set())
            {
                block_array[blockY+1][blockX]->merge(block);
                findSet = true;
                if(block->get_color_set()->get_set_size() >=4 )
                {
                    stack.push(block->get_color_set());
                }
            } // block이 set이 없고 옆도 없을때
            else if(!findSet && !block_array[blockY+1][blockX]->have_set())
            {
                color_block* cb = new color_block(block);
                block->merge(block_array[blockY+1][blockX]);
                findSet = true;
                if(block->get_color_set()->get_set_size() >=4 )
                {
                    stack.push(block->get_color_set());
                }
            } // block이 set이 있고 옆은 없을때
            else if(findSet && !block_array[blockY+1][blockX]->have_set())
            {
                block->merge(block_array[blockY+1][blockX]);
                findSet = true;
                if(block->get_color_set()->get_set_size() >=4 )
                {
                    stack.push(block->get_color_set());
                }
            }
            else if(findSet && block_array[blockY+1][blockX]->have_set())
            {
                block_array[blockY+1][blockX]->get_color_set()
                ->insert(block->get_color_set()->get_set());
                findSet = true;
                if(block->get_color_set()->get_set_size() >=4 )
                {
                    stack.push(block->get_color_set());
                }
            }
            if(!findSet) { color_block* cb = new color_block(block); }
        }

        while(!stack.empty())
        {
            color_block* cb = stack.top();
            cb->explode_block();
            stack.pop();
            score++;
            array_2d::gravity();
        }
    }
}
