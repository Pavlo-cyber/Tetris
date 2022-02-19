#include <iostream>
#include<random>
#include<time.h>
#include<SFML/Graphics.hpp>
#include"TetrisSpace.h"
#include<array>
#include "Tetramino.h"
#include "Fild.h"
#include "Collision_Handler.h"


using namespace sf;


class Random
{
public:
    static int get_random_number() //generating random number to choose type of tetramino
            {
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> distr(0, 6);
                return distr(gen);
            }
};



int main() {

    int random_number= Random::get_random_number();
    int deley=1;
    Fild fild{};
    int counter=1;
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
            if(event.type==event.KeyPressed)  //handling different type of pressed key
            {
                if(event.key.code==sf::Keyboard::Left)
                {
                    Tetramino::tetraminos[random_number].Shift_Left();
                    Collision_Handler::handle_x(Tetramino::tetraminos[random_number]);
                }
                if(event.key.code==sf::Keyboard::Right)
                {
                    Tetramino::tetraminos[random_number].Shift_Right();
                    Collision_Handler::handle_x(Tetramino::tetraminos[random_number]);
                }
                if(event.key.code==sf::Keyboard::Up)
                {
                    Collision_Handler::handle_x(Tetramino::tetraminos[random_number],Tetramino::UP); //rotate and check for collision with x axes
                }
                if(event.key.code==sf::Keyboard::Down)
                    Collision_Handler::handle_x(Tetramino::tetraminos[random_number],Tetramino::DOWN); //rotate and check for collision with x axes
            }
        }
        window.clear(Color::White);

        Texture tiles;
        tiles.loadFromFile("../tiles.png");
        Sprite sprite(tiles);

        sprite.setTextureRect(IntRect(0,0,TetrisSpace::texture_width,TetrisSpace::texture_high));

        sprite.setScale(1.0/TetrisSpace::scale,1.0/TetrisSpace::scale); //make proper size for tetraminos sprite


        std::array<short,4> x=Tetramino::tetraminos[random_number].Get_X();

        std::array<short,4> y=Tetramino::tetraminos[random_number].Get_Y();

        for(int i=0;i<x.size();i++)
        {
            sprite.setPosition(static_cast<float>(x[i]*TetrisSpace::block_width),static_cast<float>((y[i])*TetrisSpace::block_high));
            window.draw(sprite);
        }

        fild.draw(sprite,window);


        window.display();

    }






    return 0;
}
