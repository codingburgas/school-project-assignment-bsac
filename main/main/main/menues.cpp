#include "main.h"

#define MAX_OPTIONS 5
#define MAX_OPTIONS1 6
void subjectMenu() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Menu Example");

    const char* menuOptions[MAX_OPTIONS1] = {
        "Math",
        "Chemestry",
        "Geography",
        "History",
        "English",
        "Deutsch"
    };

    int selectedOption = 0;
    int subjectNum = 0; // Initialize avatarNum to 0
    int selectedSubject = 0;
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_UP)) {
            selectedOption = (selectedOption - 1 + MAX_OPTIONS1) % MAX_OPTIONS1;
        }
        else if (IsKeyPressed(KEY_DOWN)) {
            selectedOption = (selectedOption + 1) % MAX_OPTIONS1;
        }
        else if (IsKeyPressed(KEY_ENTER)) {
            selectedSubject = selectedOption;
        }

        // Set avatarNum based on selectedOption using switch-case
        switch (selectedSubject) {
        case 1:
            math();
            break;
        case 2:
            chemestry();
            break;
        case 3:
            geography();
            break;
        case 4:
            history();
            break;
        case 5:
            english();
            break;
        case 6:
            deutsch();
            break;
        default:
            subjectNum = 0; // Set default value if selectedOption is out of range
            break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw menu options
        for (int i = 0; i < MAX_OPTIONS1; i++) {
            if (i == selectedOption) {
                DrawText(menuOptions[i], 50, 50 + 30 * i, 20, RED);
            }
            else {
                DrawText(menuOptions[i], 50, 50 + 30 * i, 20, BLACK);
            }
        }

        EndDrawing();
    }

    CloseWindow();
}
void avatarMenu() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Menu Example");

    const char* menuOptions[MAX_OPTIONS] = {
        "Option 1",
        "Option 2",
        "Option 3",
        "Option 4",
        "Option 5"
    };

    int selectedOption = 0;
    int avatarNum = 0; // Initialize avatarNum to 0

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_UP)) {
            selectedOption = (selectedOption - 1 + MAX_OPTIONS) % MAX_OPTIONS;
        }
        else if (IsKeyPressed(KEY_DOWN)) {
            selectedOption = (selectedOption + 1) % MAX_OPTIONS;
        }
        else if (IsKeyPressed(KEY_ENTER)) {
            subjectMenu();
        }

        // Set avatarNum based on selectedOption using switch-case
        switch (selectedOption) {
        case 0:
            avatarNum = 0;
            break;
        case 1:
            avatarNum = 1;
            break;
        case 2:
            avatarNum = 2;
            break;
        case 3:
            avatarNum = 3;
            break;
        case 4:
            avatarNum = 4;
            break;
        default:
            avatarNum = 0; // Set default value if selectedOption is out of range
            break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw menu options
        for (int i = 0; i < MAX_OPTIONS; i++) {
            if (i == selectedOption) {
                DrawText(menuOptions[i], 50, 50 + 30 * i, 20, RED);
            }
            else {
                DrawText(menuOptions[i], 50, 50 + 30 * i, 20, BLACK);
            }
        }

        EndDrawing();
    }

    CloseWindow();
}

