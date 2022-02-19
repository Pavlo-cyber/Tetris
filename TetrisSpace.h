//
// Created by Павло Гончарук on 17.02.2022.
//

#ifndef TETRIS_TETRISSPACE_H

namespace TetrisSpace
{
    const int texture_width=512;
    const int texture_high=texture_width;
    const int scale=8;
    const int block_width=texture_width/scale;
    const int block_high=block_width;
    const int window_width=block_width*10;
    const int windows_height=block_high*20;
    const int num_of_second=1;
}



#define TETRIS_TETRISSPACE_H

#endif //TETRIS_TETRISSPACE_H
