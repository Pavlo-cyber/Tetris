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
    short min=INFINITY;
    for(const auto& elem:tetramino.Get_X())
    {
        if(elem<min)
            min=elem;
    }
    return min;
}

void Collision_Handler::handle_x(Tetramino &tetramino) {
    short max= get_max_x(tetramino);
    short min= get_min_x(tetramino);
    if(max*TetrisSpace::block_width>TetrisSpace::window_width-TetrisSpace::block_width)
    {
        tetramino.Shift_Left();
    }

    if(+min*TetrisSpace::block_width<0)
    {
        tetramino.Shift_Right();
    }
}

void Collision_Handler::handle_x(Tetramino &tetramino, Tetramino::ROTATE_TYPE rotateType) {
    const std::array<short,4> x=tetramino.Get_X();
    const std::array<short,4> y=tetramino.Get_Y();
    tetramino.Rotate(rotateType);
    short max= get_max_x(tetramino);
    short min= get_min_x(tetramino);
    if(max*TetrisSpace::block_width>TetrisSpace::window_width-TetrisSpace::block_width || min*TetrisSpace::block_width<0)
    {
        tetramino.Set_X(x);
        tetramino.Set_Y(y);
    }
}

bool Collision_Handler::handle_y(Tetramino &tetramino, Fild &fild) {
    std::array<short,4> y=tetramino.Get_Y();
    std::array<short,4> x=tetramino.Get_X();
    for(int i=0;i<x.size();i++)
    {
        if(y[i]==TetrisSpace::windows_height/TetrisSpace::block_high-1)
            return true;
    }
}

