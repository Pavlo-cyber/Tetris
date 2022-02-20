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
    }
}

void Fild::draw(sf::Sprite &sprite, sf::RenderWindow &window) {
    for(int i=0;i<Fild::_fild.size();i++)
    {
        for(int j=0;j<Fild::_fild[i].size();j++)
        {
            if(Fild::_fild[i][j])
            {
                sprite.setPosition(static_cast<float>((i)*TetrisSpace::block_width),static_cast<float>((j)*TetrisSpace::block_high));
                window.draw(sprite);
            }
        }
    }
}

bool Fild::get_fild(int x, int y) const {
    return _fild[x][y];
}




void Fild::clear_line() {
     bool temp=true;
     for(int i=0;i<_fild[0].size();i++)
     {
         for(int j=0;j<_fild.size();j++)
         {
             temp&=_fild[j][i];
         }
         if(temp)
         {
             for(int j=0;j<_fild.size();j++)
             {
                 _fild[j][i]=false;
             }
             shift_down(i);
         }
             temp=true;
     }

}

void Fild::shift_down(int cleared_index) {
    for(int i=cleared_index;i>0;i--)
    {
        for(int j=0;j<_fild.size();j++)
        {
            _fild[j][i]=_fild[j][i-1];
        }
    }

}

