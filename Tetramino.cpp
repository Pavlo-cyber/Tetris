//
// Created by Павло Гончарук on 19.02.2022.
//
#include "Tetramino.h"


Tetramino::Tetramino(std::array<short,4> rect): _rect(rect)
        {
        _x={static_cast<short>(_rect[0]%2),static_cast<short>(_rect[1]%2),static_cast<short>(_rect[2]%2),static_cast<short>(_rect[3]%2)};
        _y= {static_cast<short>(_rect[0]/2),static_cast<short>(_rect[1]/2),static_cast<short>(_rect[2]/2),static_cast<short>(_rect[3]/2)};
        }

void Tetramino::Return_Basic() {
    _x={static_cast<short>(_rect[0]%2),static_cast<short>(_rect[1]%2),static_cast<short>(_rect[2]%2),static_cast<short>(_rect[3]%2)};
    _y= {static_cast<short>(_rect[0]/2),static_cast<short>(_rect[1]/2),static_cast<short>(_rect[2]/2),static_cast<short>(_rect[3]/2)};
}


std::array<short, 4> Tetramino::Get_X() const {

    return _x;
}

std::array<short, 4> Tetramino::Get_Y() const {
    return _y;
}

void Tetramino::Set_X(const std::array<short, 4> &x) {
    _x=x;
}

void Tetramino::Set_Y(const std::array<short, 4> &y) {
    _y=y;
}

void Tetramino::Rotate(Tetramino::ROTATE_TYPE rotateType)
{
    std::pair<short,short> center{std::make_pair(_x[1],_y[1])};
       if(rotateType==UP)
       {
           for(int i=0;i<_x.size();i++)
           {
               short temp=_x[i];
               _x[i]=-_y[i]+center.second+center.first;
               _y[i]=temp-center.first+center.second;
           }
       }
       else
       {
           for(int i=0;i<_x.size();i++)
           {
               short temp=_x[i];
               _x[i]=_y[i]-center.second+center.first;
               _y[i]=-temp+center.first+center.second;
           }
       }
}

void Tetramino::Shift_Left() {
    for(auto& elem:_x)
           elem--;
}

void Tetramino::Shift_Right() {
    for(auto& elem: _x)
           elem++;
}

void Tetramino::Fall(int &deley) {
    int time=clock();
    if(static_cast<float>(time)/CLOCKS_PER_SEC>=(TetrisSpace::num_of_second*deley))
    {
        deley++;
        for(auto& elem: _y)
            elem++;
    }
}

std::array<Tetramino,7> Tetramino::tetraminos=
        {
                Tetramino(std::array<short,4>{1,3,5,7}),//I  //array[1] rotation center
                Tetramino(std::array<short,4>{3,5,7,6}),//J  //array[1] rotation center
                Tetramino(std::array<short,4>{2,4,6,7}),//L  //array[1] rotation center
                Tetramino(std::array<short,4>{4,5,6,7}),//O  //array[1] rotation center
                Tetramino(std::array<short,4>{2,5,4,7}),//S  //array[1] rotation center
                Tetramino(std::array<short,4>{2,4,5,6}),//T  //array[1] rotation center
                Tetramino(std::array<short,4>{3,4,5,6}),//Z  //array[1] rotation center
        };



void Tetramino::Shift_UP() {
    for( auto& elem:_y)
    {
        elem--;
    }
}

bool Tetramino::Is_Fell(Fild &fild) {
    for(int i=0;i<_x.size();i++)
    {
        if(_y[i]==TetrisSpace::windows_height/TetrisSpace::block_high-1)
            return true;
        if(fild.get_fild(_x[i],_y[i]+1))
        {
            return true;
        }
    }
    return false;
}

