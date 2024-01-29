#include "raylib.h"
#include <time.h>
#include <string.h>
#include "Tetris.h"
#include "Tetrominos.h"

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

int score = SCORE;

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


            score += POINTS_PER_LINE;
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

    InitAudioDevice();

    Music background_Sound = LoadMusicStream("Tetris/Background_Sound.mp3");
    Sound rotation_Sound = LoadSound("Tetris/Rotation_Sound.mp3");
    Sound stack_Sound = LoadSound("Tetris/Stack_Sound.mp3");

    PlayMusicStream(background_Sound);

    SetTargetFPS(60);
    
    SetMusicVolume(background_Sound, 0.05f);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(background_Sound);

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
            else
            {
                PlaySound(rotation_Sound);
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

                            PlaySound(stack_Sound);
                        }
                    }
                }

                DeleteLines();

                ChangeLevel(score, &moveTetrominoDownTimer);
                
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

        DrawText(TextFormat("Score: %d", score), 175, 20, 40, BLACK);

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
    

    UnloadMusicStream(background_Sound);

    CloseAudioDevice();

    return 0;
} 



    