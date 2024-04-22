#include "main.h"
const int screenWidth = 800;
const int screenHeight = 450;
const int cellSize = 20;

struct Vector2Int {
    int x;
    int y;
};
struct YourHero {
    Vector2Int position;
    Vector2Int speed;
};

struct Questions {
    Vector2Int position;
    bool active;
};

YourHero yourHero;
Questions question[20];
int num = 20; // Initially 20 questions

void InitGame() {
    // Initialize yourHero
    yourHero.position = { screenWidth / 2, screenHeight / 2 };
    yourHero.speed = { 0, 0 };

    // Initialize questions
    for (int i = 0; i < num; ++i) {
        question[i].position = { GetRandomValue(0, screenWidth / cellSize - 1) * cellSize,
                               GetRandomValue(0, screenHeight / cellSize - 1) * cellSize };
        question[i].active = true;
    }
}

void UpdateGame() {
    // Move yourHero only when a movement key is pressed
    if (IsKeyDown(KEY_UP)) yourHero.speed = { 0, -cellSize };
    else if (IsKeyDown(KEY_DOWN)) yourHero.speed = { 0, cellSize };
    else if (IsKeyDown(KEY_LEFT)) yourHero.speed = { -cellSize, 0 };
    else if (IsKeyDown(KEY_RIGHT)) yourHero.speed = { cellSize, 0 };

    // Update yourHero position
    yourHero.position.x += yourHero.speed.x;
    yourHero.position.y += yourHero.speed.y;

    // Wrap yourHero around the screen
    if (yourHero.position.x >= screenWidth) yourHero.position.x = 0;
    else if (yourHero.position.x < 0) yourHero.position.x = screenWidth - cellSize;
    if (yourHero.position.y >= screenHeight) yourHero.position.y = 0;
    else if (yourHero.position.y < 0) yourHero.position.y = screenHeight - cellSize;

    // Check for collision with questions
    for (int i = 0; i < num; ++i) {
        if (question[i].active && CheckCollisionRecs({ (float)yourHero.position.x, (float)yourHero.position.y, (float)cellSize, (float)cellSize },
            { (float)question[i].position.x, (float)question[i].position.y, (float)cellSize, (float)cellSize })) {
            question[i].active = false;
            question[i].position = { GetRandomValue(0, screenWidth / cellSize - 1) * cellSize,
                                   GetRandomValue(0, screenHeight / cellSize - 1) * cellSize };
            // Decrease the number of active questions
            questionNum++; // Add up one to questionNum
            asnwerNum++; // Add up one to asnwerNum
            num--; // Remove one from num
            if (num == 0) // Check if num equals 0
            {
                subjectMenu();
            }
            questionn();
        }
    }
}

void DrawGame() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw yourHero
    DrawRectangle(yourHero.position.x, yourHero.position.y, cellSize, cellSize, GREEN);

    // Draw questions
    for (int i = 0; i < num; ++i) {
        if (question[i].active)
            DrawRectangle(question[i].position.x, question[i].position.y, cellSize, cellSize, RED);
    }

    EndDrawing();
}

void test() {
    // Initialization
    InitWindow(screenWidth, screenHeight, "Choosing questions");
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

