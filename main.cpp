#include <iostream>
#include<random>
#include<vector>
#include<time.h>
#include<SFML/Graphics.hpp>
#include"TetrisSpace.h"

using namespace sf;

class Tetramino
{
   short _rect1;
   short _rect2;
   short _rect3;
   short _rect4;
public:
    static const std::vector<Tetramino> tetraminos;

   Tetramino(short rect1,short rect2,short rect3,short rect4):_rect1(rect1),_rect2(rect2),_rect3(rect3),_rect4(rect4)
   {}
    std::vector<short> Get_X() const
   {
       return std::vector <short> {static_cast<short>(_rect1%2),static_cast<short>(_rect2%2),static_cast<short>(_rect3%2),static_cast<short>(_rect4%2)};
   }
    std::vector<short> Get_Y() const
   {
       return std::vector <short> {static_cast<short>(_rect1/2),static_cast<short>(_rect2/2),static_cast<short>(_rect3/2),static_cast<short>(_rect4/2)};
   }


};

const std::vector<Tetramino> Tetramino::tetraminos=
        {
                Tetramino(1,3,5,7),//I
                Tetramino(3,5,7,6),//J
                Tetramino(2,4,6,7),//L
                Tetramino(4,5,6,7),//O
                Tetramino(2,4,5,7),//S
                Tetramino(2,4,5,6),//T
                Tetramino(3,5,4,6),//Z
        };





int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 6);
    short random_number=distr(gen);
    Texture tiles;
    tiles.loadFromFile("../tiles.png");
    Sprite sprite(tiles);

    short dx=0;
    float dy=0;

    sprite.setTextureRect(IntRect(0,0,TetrisSpace::texture_width,TetrisSpace::texture_high));

    sprite.setScale(1.0/TetrisSpace::scale,1.0/TetrisSpace::scale);


    RenderWindow window(VideoMode(TetrisSpace::window_width, TetrisSpace::windows_height),"Tetris game");
    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type==event.Closed)
            {
                window.close();
            }
            if(event.type==event.KeyPressed)
            {
                if(event.key.code==sf::Keyboard::Left)
                    dx--;
                if(event.key.code==sf::Keyboard::Right)
                    dx++;
            }
        }
        window.clear(Color::White);


        std::vector<short> x=Tetramino::tetraminos[random_number].Get_X();

        std::vector<short> y=Tetramino::tetraminos[random_number].Get_Y();

        for(int i=0;i<x.size();i++)
        {
            sprite.setPosition(static_cast<float>((x[i]+dx)*TetrisSpace::block_width),static_cast<float>((y[i]+dy)*TetrisSpace::block_high));
            window.draw(sprite);
        }

        int max=0;
        for(auto& elem: y)
        {
            if(elem>max)
                max=elem;
        }
        if((max+dy)*TetrisSpace::block_high<TetrisSpace::windows_height-TetrisSpace::block_high)
        {
            dy+=0.005;
        }

        window.display();



    }










    return 0;
}
