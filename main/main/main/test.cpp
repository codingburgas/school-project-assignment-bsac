#include "main.h"

const int screenWidth = 800;
const int screenHeight = 450;
const int cellSize = 20;

const int maxApples = 5;

struct Vector2Int {
    int x;
    int y;
};

struct Snake {
    Vector2Int position;
    Vector2Int speed;
};

struct Apple {
    Vector2Int position;
    bool active;
};

Snake snake;
Apple apples[maxApples];

void InitGame() {
    // Initialize snake
    snake.position = { screenWidth / 2, screenHeight / 2 };
    snake.speed = { 0, 0 };

    // Initialize apples
    for (int i = 0; i < maxApples; ++i) {
        apples[i].position = { GetRandomValue(0, screenWidth / cellSize - 1) * cellSize,
                               GetRandomValue(0, screenHeight / cellSize - 1) * cellSize };
        apples[i].active = true;
    }
}

void UpdateGame() {
    // Move snake only when a movement key is pressed
    if (IsKeyDown(KEY_UP)) snake.speed = { 0, -cellSize };
    else if (IsKeyDown(KEY_DOWN)) snake.speed = { 0, cellSize };
    else if (IsKeyDown(KEY_LEFT)) snake.speed = { -cellSize, 0 };
    else if (IsKeyDown(KEY_RIGHT)) snake.speed = { cellSize, 0 };

    // Update snake position
    snake.position.x += snake.speed.x;
    snake.position.y += snake.speed.y;

    // Wrap snake around the screen
    if (snake.position.x >= screenWidth) snake.position.x = 0;
    else if (snake.position.x < 0) snake.position.x = screenWidth - cellSize;
    if (snake.position.y >= screenHeight) snake.position.y = 0;
    else if (snake.position.y < 0) snake.position.y = screenHeight - cellSize;

    // Check for collision with apples
    for (int i = 0; i < maxApples; ++i) {
        if (apples[i].active && CheckCollisionRecs({ (float)snake.position.x, (float)snake.position.y, (float)cellSize, (float)cellSize },
            { (float)apples[i].position.x, (float)apples[i].position.y, (float)cellSize, (float)cellSize })) {
            apples[i].active = false;
            apples[i].position = { GetRandomValue(0, screenWidth / cellSize - 1) * cellSize,
                                   GetRandomValue(0, screenHeight / cellSize - 1) * cellSize };
        }
    }
}

void DrawGame() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw snake
    DrawRectangle(snake.position.x, snake.position.y, cellSize, cellSize, GREEN);

    // Draw apples
    for (int i = 0; i < maxApples; ++i) {
        if (apples[i].active)
            DrawRectangle(apples[i].position.x, apples[i].position.y, cellSize, cellSize, RED);
    }

    EndDrawing();
}

void test() {
    // Initialization
    InitWindow(screenWidth, screenHeight, "Snake Game");
    SetTargetFPS(10);
    InitGame();

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        UpdateGame();

        // Draw
        DrawGame();
    }

    // De-Initialization
    CloseWindow();
}

