//
// Created by Павло Гончарук on 19.02.2022.
//

#ifndef TETRIS_TETRAMINO_H
#define TETRIS_TETRAMINO_H
#include<iostream>
#include<array>
#include "TetrisSpace.h"

class Tetramino {
    std::array<short,4> _rect;
    std::array<short,4> _x;
    std::array<short,4> _y;
public:
    static std::array<Tetramino,7> tetraminos;

    enum ROTATE_TYPE{
        UP,
        DOWN
    };

    Tetramino(std::array<short,4> rect);

    void Return_Basic();

    std::array<short,4> Get_X() const;

    std::array<short,4> Get_Y() const ;

    void Set_X(const std::array<short,4>& x);

    void Set_Y(const std::array<short,4>& y );

    void Rotate(ROTATE_TYPE rotateType);

    void Shift_Left();

    void Shift_Right();

    void Fall(int &deley);

};





#endif //TETRIS_TETRAMINO_H
