//
// Created by Павло Гончарук on 19.02.2022.
//

#ifndef TETRIS_FILD_H
#define TETRIS_FILD_H
#include<iostream>
#include<array>
#include "Tetramino.h"
#include <SFML/Graphics.hpp>



class Fild {
    std::array<std::array<bool,20>,10> _fild;

public:
    void fill(const Tetramino& tetramino);

    void draw(sf::Sprite& sprite,sf::RenderWindow& window);

};


#endif //TETRIS_FILD_H
