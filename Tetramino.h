//
// Created by Павло Гончарук on 19.02.2022.
//
#ifndef TETRIS_TETRAMINO_H
#define TETRIS_TETRAMINO_H
#include<iostream>
#include<array>
#include "TetrisSpace.h"
#include "Fild.h"


class Fild;


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

    enum SHIFT_TYPE
    {
        LEFT,
        RIGHT
    };
    enum  INTERSECT_TYPE
    {
        INTERSECT_WITH_Y_AXES,
        INTERSECT_WITH_ANOTHER_TETRAMINO,
        NO_INTERSECT
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

    bool Is_Fell(Fild& fild);

    void Shift_UP();

};





#endif //TETRIS_TETRAMINO_H
