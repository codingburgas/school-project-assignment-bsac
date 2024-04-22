#include "main.h"

#define MAX_INPUT_CHARS  20
#define MAX_OPTIONS 5
#define MAX_OPTIONS1 6
int login(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Login Page");
    InitWindow(screenWidth, screenHeight, "Background Image");

    char username[MAX_INPUT_CHARS + 1] = "\0";
    char password[MAX_INPUT_CHARS + 1] = "\0";

    Texture2D background = LoadTexture("../assets/background.png");

    background.width = screenWidth;
    background.height = screenHeight;

    Rectangle usernameBox = { screenWidth / 2 - 100, screenHeight / 2 - 40, 200, 40 };
    Rectangle passwordBox = { screenWidth / 2 - 100, screenHeight / 2 + 20, 200, 40 };
    Rectangle loginButton = { screenWidth / 2 - 80, screenHeight / 2 + 80, 160, 40 };

    bool loginPressed = false;// Check if loginButton is pressed
    bool isUsernameTyped = false; // Heck if username is typed
    bool isPasswordTyped = false; // Check if password is typed
    bool isTypingUsername = true; // Track if currently typing in username

    SetTargetFPS(60);

    // Main loop
    while (!WindowShouldClose())
    {
        // Update
        if (CheckCollisionPointRec(GetMousePosition(), loginButton))
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                loginPressed = true;
            }
        }

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Draw title
        DrawRectangleRec(usernameBox, LIGHTGRAY);
        DrawRectangleRec(passwordBox, LIGHTGRAY);
        DrawRectangleRec(loginButton, (loginPressed) ? GRAY : DARKGRAY);

        // Draw "Username" text only if username is not typed
        if (!isUsernameTyped)
        {
            DrawText("Username:", usernameBox.x + 10, usernameBox.y + 10, 20, BLACK);
        }

        // Draw "Password" text only if password is not typed
        if (!isPasswordTyped)
        {
            DrawText("Password:", passwordBox.x + 10, passwordBox.y + 10, 20, BLACK);
        }

        DrawText(username, usernameBox.x + 20, usernameBox.y + 20, 20, MAROON);
        DrawText(password, passwordBox.x + 20, passwordBox.y + 20, 20, MAROON);

        DrawText("LOGIN", loginButton.x + 40, loginButton.y + 10, 20, WHITE);

        EndDrawing();

        // Input handling
        if (loginPressed)
        {
            subjectMenu(); // Call start function
            loginPressed = false;
        }
        else
        {
            // Input username
            int key = GetKeyPressed();
            if (key != 0 && isTypingUsername)
            {
                isUsernameTyped = true; // Set flag to true when username is typed

                int length = strlen(username);
                if (((key >= 32) && (key <= 125)) && (length < MAX_INPUT_CHARS))
                {
                    username[length] = (char)key;
                    username[length + 1] = '\0';
                }
                else if ((key == KEY_BACKSPACE) && (length > 0))
                {
                    username[length - 1] = '\0';
                }
                else if (key == KEY_ENTER)
                {
                    isTypingUsername = false; // Switch to typing password
                }
            }

            // Input password
            else if (key != 0 && !isTypingUsername)
            {
                isPasswordTyped = true; // Set flag to true when password is typed

                int length = strlen(password);
                if (((key >= 32) && (key <= 125)) && (length < MAX_INPUT_CHARS))
                {
                    password[length] = (char)key;
                    password[length + 1] = '\0';
                }
                else if ((key == KEY_BACKSPACE) && (length > 0))
                {
                    password[length - 1] = '\0';
                }
            }
        }

        ClearBackground(RAYWHITE);

        // Draw the background image
        DrawTexture(background, 0, 0, WHITE);

    }
    // De-Initialization
    UnloadTexture(background);

    CloseWindow();

    return 0;
}
void subjectMenu() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "SubjectMenu");

    const char* menuOptions[MAX_OPTIONS1] = {
        "Math",
        "Chemestry",
        "Geography",
        "History",
        "English",
        "Deutsch"
    };

    int selectedOption = 0; // Initialize selectedOption to 0
    int subjectNum = 0; // Initialize subjectNum to 0
    int selectedSubject = 0; // Initialize selectedSubject to 0
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_UP)) //Checks if KEY_UP is pressed
        {
            selectedOption = (selectedOption - 1 + MAX_OPTIONS1) % MAX_OPTIONS1;
        }
        else if (IsKeyPressed(KEY_DOWN)) //Checks if KEY_DOWN is pressed
        {
            selectedOption = (selectedOption + 1) % MAX_OPTIONS1;
        }
        else if (IsKeyPressed(KEY_ENTER)) //Checks if KEY_ENTER is pressed
        {
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
            subjectNum = 0; // Set default value to subjectNum if selectedOption is out of range
            break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw menu options
        for (int i = 0; i < MAX_OPTIONS1; i++) {
            if (i == selectedOption) {
                DrawText(menuOptions[i], 350, 177 + 30 * i, 20, RED);
            }
            else {
                DrawText(menuOptions[i], 350, 177 + 30 * i, 20, BLACK);
            }
        }

        EndDrawing();
    }

    CloseWindow();
}

