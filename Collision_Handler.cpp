//
// Created by Павло Гончарук on 19.02.2022.
//

#include "Collision_Handler.h"



short Collision_Handler::get_max_x(const Tetramino &tetramino) {
    short max=0;
    for(const auto& elem:tetramino.Get_X())
    {
        if(elem>max)
            max=elem;
    }
    return max;
}

short Collision_Handler::get_min_x(const Tetramino &tetramino) {
    short min=10;
    for(const auto& elem:tetramino.Get_X())
    {
        if(elem<min)
            min=elem;
    }
    return min;
}

void Collision_Handler::handle_x(Tetramino &tetramino,Fild& fild,Tetramino::SHIFT_TYPE shiftType) {
    short max= get_max_x(tetramino);
    short min= get_min_x(tetramino);
    if(max*TetrisSpace::block_width>TetrisSpace::window_width-TetrisSpace::block_width)
    {
        tetramino.Shift_Left();
    }
    else if(min*TetrisSpace::block_width<0)
    {
        tetramino.Shift_Right();
    }
    std::array<short,4> x=tetramino.Get_X();
    std::array<short,4> y=tetramino.Get_Y();
    for(int i=0;i<x.size();i++)
    {
        if(fild.get_fild(x[i],y[i]))
        {
            if(shiftType==Tetramino::RIGHT)
            {
                tetramino.Shift_Left();
            }
            else
            {
                tetramino.Shift_Right();
            }
            break;
        }
    }
}

void Collision_Handler::handle_x(Tetramino &tetramino, Tetramino::ROTATE_TYPE rotateType,Fild& fild) {
     std::array<short,4> x=tetramino.Get_X();
     std::array<short,4> y=tetramino.Get_Y();
    tetramino.Rotate(rotateType);
    short max= get_max_x(tetramino);
    short min= get_min_x(tetramino);
    std::cout<<min<<std::endl;
    while(max*TetrisSpace::block_width>TetrisSpace::window_width-TetrisSpace::block_width)
    {
        tetramino.Shift_Left();
        max= get_max_x(tetramino);
    }
    while(min*TetrisSpace::block_width<0)
    {
        tetramino.Shift_Right();
        min= get_min_x(tetramino);
        std::cout<<min<<std::endl;
    }

    x=tetramino.Get_X();
    y=tetramino.Get_Y();
    for(int i=0;i<x.size();i++)
    {
        if(fild.get_fild(x[i],y[i]))
        {
            tetramino.Set_X(x);
            tetramino.Set_Y(y);
            break;
        }
    }
}

bool Collision_Handler::handle_y(int random_number) {
    Tetramino::tetraminos[random_number].Shift_UP();
}



