#include "main.h"
const int screenWidth = 800;
const int screenHeight = 450;

const int fontSize = 20;
std::string answer = "";
std::string cheerText = "";
std::string arr[21] = {".", "qusetion Chemestry 1", "qusetion Chemestry 2", "qusetion Chemestry 3", "qusetion Chemestry 4", "qusetion Chemestry 5","qusetion Chemestry 6", "qusetion Chemestry 7", "qusetion Chemestry 8", "qusetion Chemestry 9", "qusetion Chemestry 10", "qusetion Chemestry 11", "qusetion Chemestry 12", "qusetion Chemestry 13", "qusetion Chemestry 14", "qusetion Chemestry 15", "qusetion Chemestry 16", "qusetion Chemestry 17", "qusetion Chemestry 18", "qusetion Chemestry 19", "qusetion Chemestry 20" };
std::string arr1[21] = { ".", "qusetion Geography 1", "qusetion Geography 2", "qusetion Geography 3", "qusetion Geography 4", "qusetion Geography 5","qusetion Geography 6", "qusetion Geography 7", "qusetion Geography 8", "qusetion Geography 9", "qusetion Geography 10", "qusetion Geography 11", "qusetion Geography 12", "qusetion Geography 13", "qusetion Geography 14", "qusetion Geography 15","qusetion Geography 16", "qusetion Geography 17", "qusetion Geography 18", "qusetion Geography 19", "qusetion Geography 20"};
std::string arr2[21] = { ".", "qusetion History 1", "qusetion History 2", "qusetion History 3", "qusetion History 4", "qusetion History 5" ,"qusetion History 6", "qusetion History 7", "qusetion History 8", "qusetion History 9", "qusetion History 10" ,"qusetion History 11", "qusetion History 12", "qusetion History 13", "qusetion History 14", "qusetion History 15" ,"qusetion History 16", "qusetion History 17", "qusetion History 18", "qusetion History 19", "qusetion History 20"};
std::string arr3[21] = { ".", "qusetion Englishm 1", "qusetion English 2", "qusetion English 3", "qusetion English 4", "qusetion English 5" ,"qusetion Englishm 6", "qusetion English 7", "qusetion English 8", "qusetion English 9", "qusetion English 10" , "qusetion Englishm 11", "qusetion English 12", "qusetion English 13", "qusetion English 14", "qusetion English 15" , "qusetion Englishm 16", "qusetion English 17", "qusetion English 18", "qusetion English 19", "qusetion English 20"};
std::string arr4[21] = { ".", "qusetion Deutsch 1", "qusetion Deutsch 2", "qusetion Deutsch 3", "qusetion Deutsch 4", "qusetion Deutsch 5" ,"qusetion Deutsch 6", "qusetion Deutsch 7", "qusetion Deutsch 8", "qusetion Deutsch 9", "qusetion Deutsch 10" , "qusetion Deutsch 11", "qusetion Deutsch 12", "qusetion Deutsch 13", "qusetion Deutsch 14", "qusetion Deutsch 15" , "qusetion Deutsch 16", "qusetion Deutsch 17", "qusetion Deutsch 18", "qusetion Deutsch 19", "qusetion Deutsch 20" };
std::string arr20[21] = { ".", "1", "aaaaaaaaaa", "3", "4", "5","6", "7", "8", "9", "10", "qusetion Chemestry 11", "qusetion Chemestry 12", "qusetion Chemestry 13", "qusetion Chemestry 14", "qusetion Chemestry 15", "qusetion Chemestry 16", "qusetion Chemestry 17", "qusetion Chemestry 18", "qusetion Chemestry 19", "qusetion Chemestry 20" };
std::string arr21[21] = { ".", "11", "12", "13", "14", "15","16", "17", "18", "19", "20", "qusetion Geography 11", "qusetion Geography 12", "qusetion Geography 13", "qusetion Geography 14", "qusetion Geography 15","qusetion Geography 16", "qusetion Geography 17", "qusetion Geography 18", "qusetion Geography 19", "qusetion Geography 20" };
std::string arr22[21] = { ".", "21", "22", "23", "24", "25" ,"26", "27", "28", "29", "30" ,"qusetion History 11", "qusetion History 12", "qusetion History 13", "qusetion History 14", "qusetion History 15" ,"qusetion History 16", "qusetion History 17", "qusetion History 18", "qusetion History 19", "qusetion History 20" };
std::string arr23[21] = { ".", "31", "32", "33", "34", "35" ,"36", "37", "38", "39", "40" , "qusetion Englishm 11", "qusetion English 12", "qusetion English 13", "qusetion English 14", "qusetion English 15" , "qusetion Englishm 16", "qusetion English 17", "qusetion English 18", "qusetion English 19", "qusetion English 20" };
std::string arr24[21] = { ".", "41", "42", "43", "44", "45" ,"46", "47", "48", "49", "50" , "qusetion Deutsch 11", "qusetion Deutsch 12", "qusetion Deutsch 13", "qusetion Deutsch 14", "qusetion Deutsch 15" , "qusetion Deutsch 16", "qusetion Deutsch 17", "qusetion Deutsch 18", "qusetion Deutsch 19", "qusetion Deutsch 20" };
bool showTryAgain = false;
bool congratulationsShown = false;
int questionNum = 0;
int choosenOne = 0;
int choosenTwo = 0;
int arrValue = 0;
int asnwerNum = 0;

void DrawTextCenter(const char* text, int fontSize, int posX, int posY, Color color) {
    int width = MeasureText(text, fontSize);
    DrawText(text, posX - width / 2, posY, fontSize, color);
}

void UpdateInput() {
    switch (choosenTwo)
    {
    case 0:
        if (IsKeyPressed(KEY_ENTER) && !answer.empty())
        {
            if (answer == arr20[asnwerNum])
            {
                congratulationsShown = true;
                answer = "";
                test();
            }
            else
            {
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

        break;
    case  1:
        if (IsKeyPressed(KEY_ENTER) && !answer.empty())
        {
            if (answer == arr21[asnwerNum])
            {
                congratulationsShown = true;
                answer = "";
                test();
            }
            else
            {
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
        break;
    case  2:
        if (IsKeyPressed(KEY_ENTER) && !answer.empty())
        {
            if (answer == arr22[asnwerNum])
            {
                congratulationsShown = true;
                answer = "";
                test();
            }
            else
            {
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
        break;
    case  3:
        if (IsKeyPressed(KEY_ENTER) && !answer.empty())
        {
            if (answer == arr23[asnwerNum])
            {
                congratulationsShown = true;
                answer = "";
                test();
            }
            else
            {
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
        break;
    case  4:
        if (IsKeyPressed(KEY_ENTER) && !answer.empty())
        {
            if (answer == arr24[asnwerNum])
            {
                congratulationsShown = true;
                answer = "";
                test();
            }
            else
            {
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
        break;

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
