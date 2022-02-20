//
// Created by Павло Гончарук on 19.02.2022.
//

#ifndef TETRIS_COLLISION_HANDLER_H
#define TETRIS_COLLISION_HANDLER_H
#include "Tetramino.h"
#include "Fild.h"
#include<array>

class Collision_Handler {

public:


    static short get_max_x(const Tetramino& tetramino);

    static short get_min_x(const Tetramino& tetramino);

    static void handle_x(Tetramino& tetramino,Fild& fild,Tetramino::SHIFT_TYPE shiftType);

    static void handle_x( Tetramino& tetramino,Tetramino::ROTATE_TYPE rotateType,Fild& fild);

    static bool handle_y(int random_number);

};


#endif //TETRIS_COLLISION_HANDLER_H
