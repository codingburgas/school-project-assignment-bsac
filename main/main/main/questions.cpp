#include "main.h"

const int screenWidth = 800;
const int screenHeight = 450;

const int fontSize = 20;
std::string question = "What is your answer?";
std::string answer = "";
std::string correctAnswer;
bool showTryAgain = false;
bool congratulationsShown = false;

void checkChoosen()
{
    //if (choosen == "chemestry")
    //{
      //  correctAnswer = "H2O";
    //}
}

bool CheckAnswer() {
        return (answer == correctAnswer);
}

void DrawTextCenter(const char* text, int fontSize, int posX, int posY, Color color) {
    int width = MeasureText(text, fontSize);
    DrawText(text, posX - width / 2, posY, fontSize, color);
}

void UpdateInput() {
    if (IsKeyPressed(KEY_ENTER) && !answer.empty()) {
        if (CheckAnswer()) {
            congratulationsShown = true;
            std::cout << "Congratulations!" << std::endl;
        }
        else {
            answer.clear();
            showTryAgain = true;
        }
    }
    else if (IsKeyPressed(KEY_BACKSPACE) && !answer.empty()) {
        answer.pop_back();
    }
    else {
        int key = GetKeyPressed();
        if ((key >= 32) && (key <= 125)) {
            answer += static_cast<char>(key);
            showTryAgain = false;
            congratulationsShown = false; // Reset the congratulations message
        }
    }
}

void questionn() {
    InitWindow(screenWidth, screenHeight, "Question and Answer");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        UpdateInput();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw question
        DrawTextCenter(question.c_str(), fontSize, screenWidth / 2, screenHeight / 2 - 50, BLACK);

        // Draw answer
        DrawTextCenter(answer.c_str(), fontSize, screenWidth / 2, screenHeight / 2 + 50, BLACK);

        // Draw "Try again" message if the answer is incorrect
        if (showTryAgain) {
            DrawTextCenter("Try again", fontSize, screenWidth / 2, screenHeight / 2 + 100, RED);
        }

        // Draw "Congratulations" message if the answer is correct
        if (congratulationsShown) {
            DrawTextCenter("Congratulations!", fontSize, screenWidth / 2, screenHeight / 2 + 100, GREEN);
        }

        EndDrawing();
    }

    CloseWindow();
}
