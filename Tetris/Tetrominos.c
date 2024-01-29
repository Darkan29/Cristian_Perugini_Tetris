#include "Tetris.h"


const int LTetromino0[] = 
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 0, 0
};

const int LTetromino90[] = 
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    1, 0, 0, 0,
    0, 0, 0, 0
};

const int LTetromino180[] = 
{
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0
};

const int LTetromino270[] = 
{
    0, 0, 1, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
};

const int JTetromino0[]=
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    1, 1, 0, 0,
    0, 0, 0, 0
};

const int JTetromino90[]=
{
    1, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
};

const int JTetromino180[]=
{
    0, 1, 1, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0
};

const int JTetromino270[]=
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 1, 0,
    0, 0, 0, 0
};

const int OTetromino[]=
{
    1, 1, 0, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
};

const int STetromino0[]=
{
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0,
    0, 0, 0, 0
};

const int STetromino90[]=
{
    0, 0, 0, 0,
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 1, 0
};

const int STetromino180[]=
{
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0
};

const int STetromino270[]=
{
    0, 0, 0, 0,
    1, 0, 0, 0,
    1, 1, 0, 0,
    0, 1, 0, 0
};

const int TTetromino0[]=
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    0, 1, 0, 0,
    0, 0, 0, 0
};

const int TTetromino90[]=
{
    0, 1, 0, 0,
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0
};

const int TTetromino180[]=
{
    0, 1, 0, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
};

const int TTetromino270[]=
{
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 1, 0, 0,
    0, 0, 0, 0
};

const int ITetromino0[]=
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0
};

const int ITetromino90[]=
{
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0
};

const int ITetromino180[]=
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0
};

const int ITetromino270[]=
{
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0
};

const int ZTetromino0[]=
{
    0, 0, 0, 0,
    1, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 0, 0
};

const int ZTetromino90[]=
{
    0, 0, 0, 0,
    0, 0, 1, 0,
    0, 1, 1, 0,
    0, 1, 0, 0
};

const int ZTetromino180[]=
{
    0, 0, 0, 0,
    0, 0, 0, 0,
    1, 1, 0, 0,
    0, 1, 1, 0
};

const int ZTetromino270[]=
{
    0, 0, 0, 0,
    0, 1, 0, 0,
    1, 1, 0, 0,
    1, 0, 0, 0
};

const Color colorTypes[8]=
{
    {255, 255, 0, 255},
    {0, 255, 145, 255},
    {56, 255, 85, 255},
    {142, 79, 255, 255},
    {195, 255, 255, 255},
    {51, 110, 73, 255},
    {97, 5, 85, 255},
    {85, 45, 63, 255},
};

const int *TetrominoTypes[7][4] =
{
    {ZTetromino0, ZTetromino90, ZTetromino180, ZTetromino270}, 
    {STetromino0, STetromino90, STetromino180, STetromino270},
    {TTetromino0, TTetromino90, TTetromino180, TTetromino270},
    {OTetromino, OTetromino, OTetromino, OTetromino},
    {ITetromino0, ITetromino90, ITetromino180, ITetromino270},
    {JTetromino0, JTetromino90, JTetromino180, JTetromino270},
    {LTetromino0, LTetromino90, LTetromino180, LTetromino270}
};