#include "main.h"
const int screenWidth = 800;
const int screenHeight = 450;

const int fontSize = 20;
std::string answer = "";
std::string cheerText = "";
std::string arr[21] = { ".", "What is the chemical symbol for potassium?", "Which element is essential for human bones and teeth?", "What is the lightest noble gas?", "Which metal is liquid at room temperature?", "What element is commonly used in batteries?","What is the chemical symbol for gold?", "Which gas do plants use for photosynthesis?", "What element is the primary component of diamonds?", "WWhich element has the atomic number 1?", "What is the chemical symbol for iron?", "Which element is most abundant in the Earth's crust?", "What is the chemical symbol for silver?", "Which gas is responsible for the blue color of the sky?", "What element is commonly used in light bulbs?", " Which element is essential for the process of photosynthesis?", " What is the chemical symbol for lead?", "Which metal is commonly used in aircraft construction?", "What element is used in the manufacture of glass?", "Which element is essential for the formation of DNA?", "What is the chemical symbol for nitrogen?" };
std::string arr1[21] = { ".", "What is the capital city of France?", "Which continent is the largest by land area?", "Which ocean is the largest on Earth?", "What is the longest river in the world?", "What is the tallest mountain in the world?","Which country is known as the Land of the Rising Sun?", "Which desert is the largest in the world?", "What is the capital city of Australia?", "Which country is the smallest in terms of land area?", "What is the largest island in the world?", "What is the capital city of Brazil?", "Which river flows through the Grand Canyon?", "Which country is both in Europe and Asia?", "What is the world's largest tropical rainforest?", "Which continent is the driest in the world?","Which country is known as the Land of a Thousand Lakes?", "Which mountain range is the longest in the world?", "Which country is known as the Pearl of the Indian Ocean?", "What is the world's largest archipelago?", "What is the capital city of Spain?" };
std::string arr2[21] = { ".", "qusetion History 1", "qusetion History 2", "qusetion History 3", "qusetion History 4", "qusetion History 5" ,"qusetion History 6", "qusetion History 7", "qusetion History 8", "qusetion History 9", "qusetion History 10" ,"qusetion History 11", "qusetion History 12", "qusetion History 13", "qusetion History 14", "qusetion History 15" ,"qusetion History 16", "qusetion History 17", "qusetion History 18", "qusetion History 19", "qusetion History 20" };
std::string arr3[21] = { ".", "qusetion Englishm 1", "qusetion English 2", "qusetion English 3", "qusetion English 4", "qusetion English 5" ,"qusetion Englishm 6", "qusetion English 7", "qusetion English 8", "qusetion English 9", "qusetion English 10" , "qusetion Englishm 11", "qusetion English 12", "qusetion English 13", "qusetion English 14", "qusetion English 15" , "qusetion Englishm 16", "qusetion English 17", "qusetion English 18", "qusetion English 19", "qusetion English 20" };
std::string arr4[21] = { ".", "How do you translate GOOD DAY to German?", "What is GOODBYE in German?", "What is the German word for NO?", "How do you say PLEASE in German?", " What is the German word for EXCUSE ME or SORRY?" ,"What is the German word for WHERE?", "How do you say MY NAME IS... in German? ", "What is the German word for THANK YOU VERY MUCH?", " What does ICH LIEBE DICH mean in English?", " How do you say HELLO in German?" , "What is the German word for YES?", "How do you ask HOW ARE YOU in German?", "How do you say I'M SORRY in German?", "What does ICH VERSTEhHE nicht mean in English?", " How do you ask WHERE IS THE BATHROOM in German?" , "What is the German word for HOUSE?", "What is the translation of WIE HEISST DU in English?", "What is the German word for CAT?", "qHow do you say GOOD EVENING in German?", "How do you say I'M HUNGRY in German?" };
std::string arr20[21] = { ".", "K", "CA", "HE", "HG", "LI","AU", "CO2", "C", "H", "FE", "O", "AG", "N", "W", "CL", "PB", "AL", "SI", "P", "N" };
std::string arr21[21] = { ".", "Paris", "Asia", "Pacific Ocean", "Nile River", "Mount Everest","Japan", "Sahara Desert", "Canberra", "Vatican City", "Greenland", "Brasília", "Colorado River", "Turkey", "Amazon Rainforest", "Antarctica","Finland", "Andes Mountains", "Sri Lanka", "Indonesia", "Madrid" };
std::string arr22[21] = { ".", "21", "22", "23", "24", "25" ,"26", "27", "28", "29", "30" ,"qusetion History 11", "qusetion History 12", "qusetion History 13", "qusetion History 14", "qusetion History 15" ,"qusetion History 16", "qusetion History 17", "qusetion History 18", "qusetion History 19", "qusetion History 20" };
std::string arr23[21] = { ".", "31", "32", "33", "34", "35" ,"36", "37", "38", "39", "40" , "qusetion Englishm 11", "qusetion English 12", "qusetion English 13", "qusetion English 14", "qusetion English 15" , "qusetion Englishm 16", "qusetion English 17", "qusetion English 18", "qusetion English 19", "qusetion English 20" };
std::string arr24[21] = { ".", "GUTEN TAG", "AUF WIEDERSEHEN", "NEIN", "BITTE", "ENTSCHULDIGUNG" ,"WO", "MEIN NAME IST", "VIELEN DANK", "I LOVE YOU", "HALLO" , "JA", "WIE GEHT ES DIR", "ES TUT MIR LEID", "I DON'T UNDERSTAND", "WO IST DIE TOILETTE" , "HAUS", "WHAT IS YOUR NAME", "KATZE", "GUTEN ABEND", "ICH HABE HUNGER" };
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
