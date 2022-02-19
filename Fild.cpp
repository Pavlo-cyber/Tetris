//
// Created by Павло Гончарук on 19.02.2022.
//
#include "Fild.h"


void Fild::fill(const Tetramino &tetramino) {
    std::array<short,4> x=tetramino.Get_X();
    std::array<short,4> y=tetramino.Get_Y();
    for(int i=0;i<x.size();i++)
    {
        _fild[x[i]][y[i]]=true;
        std::cout<<"x= "<<x[i]<<"y= "<<y[i]<<std::endl;
    }
}

void Fild::draw(sf::Sprite &sprite, sf::RenderWindow &window) {
    for(int i=0;i<Fild::_fild.size();i++)
    {
        for(int j=0;j<Fild::_fild[i].size();j++)
        {
            if(Fild::_fild[i][j])
            {
                sprite.setPosition(static_cast<float>((i)*TetrisSpace::block_width),static_cast<float>(j*TetrisSpace::block_high));
                std::cout<<"x= "<<i<<"y= "<<j<<std::endl;
                window.draw(sprite);
            }
        }
    }
}

