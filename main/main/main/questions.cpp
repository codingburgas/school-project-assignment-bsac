#include "main.h"
const int screenWidth = 800;
const int screenHeight = 450;

const int fontSize = 20;
std::string answer = "";
std::string correctAnswer = "ONE";
std::string cheerText = "";
std::string arr[20] = { "qusetion Chemestry 1", "qusetion Chemestry 2", "qusetion Chemestry 3", "qusetion Chemestry 4", "qusetion Chemestry 5"};
std::string arr1[20] = { "qusetion Geography 1", "qusetion Geography 2", "qusetion Geography 3", "qusetion Geography 4", "qusetion Geography 5" };
std::string arr2[20] = { "qusetion History 1", "qusetion History 2", "qusetion History 3", "qusetion History 4", "qusetion History 5" };
std::string arr3[20] = { "qusetion Englishm 1", "qusetion English 2", "qusetion English 3", "qusetion English 4", "qusetion English 5" };
std::string arr4[20] = { "qusetion Deutsch 1", "qusetion Deutsch 2", "qusetion Deutsch 3", "qusetion Deutsch 4", "qusetion Deutsch 5" };
bool showTryAgain = false;
bool congratulationsShown = false;
int questionNum = 0;
int choosenOne = 0;
int arrValue = 0;

void DrawTextCenter(const char* text, int fontSize, int posX, int posY, Color color) {
    int width = MeasureText(text, fontSize);
    DrawText(text, posX - width / 2, posY, fontSize, color);
}

void UpdateInput() {
    if (IsKeyPressed(KEY_ENTER) && !answer.empty()) {
        if (answer == correctAnswer) {
            congratulationsShown = true;
            //cheerText = "Congratulations!";
            //std::cout << cheerText << std::endl;
            answer = "";
            test();



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
        switch (choosenOne)
        {
        case 0:
            DrawTextCenter(arr[questionNum].c_str(), fontSize, screenWidth / 2, screenHeight / 2 - 100, BLACK);
            break;
        case  1:
            DrawTextCenter(arr1[questionNum].c_str(), fontSize, screenWidth / 2, screenHeight / 2 - 100, BLACK);
            break;
        case  2:
            DrawTextCenter(arr2[questionNum].c_str(), fontSize, screenWidth / 2, screenHeight / 2 - 100, BLACK);
            break;
        case  3:
            DrawTextCenter(arr3[questionNum].c_str(), fontSize, screenWidth / 2, screenHeight / 2 - 100, BLACK);
            break;
        case  4:
            DrawTextCenter(arr4[questionNum].c_str(), fontSize, screenWidth / 2, screenHeight / 2 - 100, BLACK);
            break;
        }
        // Draw answer
        DrawTextCenter(answer.c_str(), fontSize, screenWidth / 2, screenHeight / 2 + 50, BLACK);

        // Draw "Try again" message if the answer is incorrect
        if (showTryAgain) {
            DrawTextCenter("Try again", fontSize, screenWidth / 2, screenHeight / 2 + 100, RED);
        }

        // Draw "Congratulations" message if the answer is correct
        if (congratulationsShown) {
            DrawTextCenter("Congratulations for the previous answer!", fontSize, screenWidth / 2, screenHeight / 2 + 100, GREEN);
            DrawTextCenter("", fontSize, screenWidth / 2, screenHeight / 2 + 100, GREEN);
        }

        EndDrawing();
    }


}
