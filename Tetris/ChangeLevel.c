#include "Tetris.h"

void ChangeLevel(int score, float *timer)
{
    if (score == FIRST_LEVEL)
    {
        *timer = 0.6;
    }
    else if(score == SECOND_LEVEL)
    {
        *timer = 0.4;
    }
    else if (score == THIRD_LEVEL)
    {
        *timer = 0.2;
    }
}