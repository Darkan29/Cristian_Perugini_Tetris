#include "raylib.h"

#define STAGE_WIDTH 12
#define STAGE_HEIGHT 22
#define TILE_SIZE 16
#define TETROMINO_SIZE 4

#define SCORE 0
#define POINTS_PER_LINE 10

#define FIRST_LEVEL 20
#define SECOND_LEVEL 50
#define THIRD_LEVEL 80

int CheckCollision(const int tetrominoStartX, const int tetrominoStartY, const int *tetromino);

void ChangeLevel(int score, float *timer);

void drawTetromino(const Color currentColor, const int startOffsetX, const int startOffsetY, const int tetrominoStartX, const int tetrominoStartY, const int *tetromino);

void ResetLines(int startLineY);
