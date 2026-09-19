#include <iostream>
#include <raylib.h>

int main(){
    InitWindow(400, 400, "Jogo da Velha");

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello World!", 200, 200, 20, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}