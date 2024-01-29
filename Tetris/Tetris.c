#include "raylib.h"
#include <time.h>
#include <string.h>
#include "Tetris.h"

int stage[] = 
{
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

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
    {255, 255, 85, 255},
    {85, 43, 158, 255},
    {56, 255, 85, 255},
    {255, 255, 63, 255},
    {255, 42, 85, 255},
    {255, 100, 85, 255},
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




void drawTetromino(const Color currentColor, const int startOffsetX, const int startOffsetY, const int tetrominoStartX, const int tetrominoStartY, const int *tetromino)
{
    for (int y = 0; y < TETROMINO_SIZE; y++)
    {
        for (int x = 0; x < TETROMINO_SIZE; x++)
        {
            const int offset = y * TETROMINO_SIZE + x;    

            if (tetromino[offset] == 1)
            {
                DrawRectangle((x+tetrominoStartX)* TILE_SIZE + startOffsetX, (y+tetrominoStartY) * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, currentColor);
            }
        }
    }
}

void ResetLines(int startLineY)
{
    for (int y = startLineY; y >= 0; y--)
    {
        for (int x = 1; x < STAGE_WIDTH-1; x++)
        {
            const int offset = y * STAGE_WIDTH + 1;
            const int offset_below = (y+1) * STAGE_WIDTH + x;

            if (stage[offset_below] == 0 && stage[offset] > 0)
            {
                stage[offset_below] = stage[offset];
                stage[offset]=0;
            }
        }
    }
}

void DeleteLines()
{
    
    for (int y = 0; y < STAGE_HEIGHT -1; y++)
    {

        int checkLine = 1;

        for (int x = 1; x < STAGE_WIDTH-1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;

            if (stage[offset] == 0)
            {
                checkLine = 0;
                break;
            }
        }

        if (checkLine)
        {
            const int offset = y * STAGE_WIDTH + 1;
            memset(stage+offset, 0, (STAGE_WIDTH-2 )* sizeof(int));

            ResetLines(y);
        }
    }
}

int main(int argc, char** argv, char** environ)
{
    const int windowWidth = 512;
    const int windowHeight = 512;

    const int startOffsetX = (windowWidth /2) - (STAGE_WIDTH*TILE_SIZE) /2;
    const int startOffsetY = (windowHeight /2) - (STAGE_HEIGHT*TILE_SIZE)  /2;

    const int tetrominoStartX = STAGE_WIDTH /2;
    const int tetrominoStartY = 0;

    int currentTetrominoX = tetrominoStartX;
    int currentTetrominoY = tetrominoStartY;

    float moveTetrominoDownTimer = 1.f;
    float timeToMoveTetrominoDown = moveTetrominoDownTimer;

    time_t unixTime;

    time(&unixTime);

    SetRandomSeed(unixTime);

    int currentTetrominoType = GetRandomValue(0,6);
    int currentTetrominoRotation = 0;

    int currentColor = GetRandomValue(0,7);

    TraceLog(LOG_INFO, "Number of arguments: %d", argc);

    for (int i = 0; i < argc; i++)
    {
        TraceLog(LOG_INFO, "Argument: %d = %s", i, argv[i]);
    }
    
    while (*environ != 0)
    {
        TraceLog(LOG_INFO, "Environ: %s", *environ);
        environ++;
    }

    InitWindow(windowWidth, windowHeight, "Title");

    SetTargetFPS(60);
    

    while (!WindowShouldClose())
    {
        timeToMoveTetrominoDown -= GetFrameTime();

        if (IsKeyPressed(KEY_SPACE))
        {
            const int lastRotation = currentTetrominoRotation;

            currentTetrominoRotation++;
            if (currentTetrominoRotation > 3)
            {
                currentTetrominoRotation=0;
            }

            if (CheckCollision(currentTetrominoX, currentTetrominoY, TetrominoTypes[currentTetrominoType][currentTetrominoRotation]))
            {
                currentTetrominoRotation = lastRotation;
            }
            
            
        }

        if (timeToMoveTetrominoDown <= 0 || IsKeyPressed(KEY_DOWN))
        {


            if (!CheckCollision(currentTetrominoX, currentTetrominoY+1, TetrominoTypes[currentTetrominoType][currentTetrominoRotation]))
            {
                currentTetrominoY++;
                timeToMoveTetrominoDown = moveTetrominoDownTimer;
            }
            else
            {
                // const int currentTetrominoOffset = currentTetrominoY*STAGE_WIDTH + currentTetrominoX;

                // stage[currentTetrominoOffset] = 1;
                
                for (int y = 0; y < TETROMINO_SIZE; y++)
                {
                    for (int x = 0; x < TETROMINO_SIZE; x++)
                    {
                        const int offset = y * TETROMINO_SIZE + x;    

                        const int *tetromino = TetrominoTypes[currentTetrominoType][currentTetrominoRotation];

                        if (tetromino[offset] == 1)
                        {
                            const int offset_stage = (y+currentTetrominoY) * STAGE_WIDTH + (x+currentTetrominoX);

                            stage[offset_stage] = currentColor+1;
                        }
                    }
                }

                DeleteLines();

                currentTetrominoX = tetrominoStartX;
                currentTetrominoY = tetrominoStartY;

                currentTetrominoType = GetRandomValue(0,6);
                currentTetrominoRotation = 0;
                currentColor = GetRandomValue(0,7);
            }
        }

        if (IsKeyPressed(KEY_RIGHT))
        {
            if (!CheckCollision(currentTetrominoX+1, currentTetrominoY, TetrominoTypes[currentTetrominoType][currentTetrominoRotation]))
            {
                currentTetrominoX++;
            }
        }
        if (IsKeyPressed(KEY_LEFT))
        {
             if (!CheckCollision(currentTetrominoX-1, currentTetrominoY, TetrominoTypes[currentTetrominoType][currentTetrominoRotation]))
            {
                currentTetrominoX--;
            }
        }
        
        


        BeginDrawing();
        ClearBackground(RED);

        for (int y = 0; y < STAGE_HEIGHT; y++)
        {
            for (int x = 0; x < STAGE_WIDTH; x++)
            {
                const int offset = y*STAGE_WIDTH + x;  
                const int color = stage[offset];  

                if (stage[offset] != 0)
                {
                    DrawRectangle(x * TILE_SIZE + startOffsetX, y * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, colorTypes[color-1]);
                }

                DrawRectangleLines(x * TILE_SIZE + startOffsetX, y * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, BLACK);
                
            }
            
        }

        drawTetromino(colorTypes[currentColor], startOffsetX, startOffsetY, currentTetrominoX, currentTetrominoY, TetrominoTypes[currentTetrominoType][currentTetrominoRotation]);

        EndDrawing();
    }
    

    return 0;
} 



    