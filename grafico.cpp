#include <iostream>
#include <raylib.h>
using namespace std;
#include "jogo.hpp"
#define ALTURA 400
#define LARGURA 400
#define PRETO_CINZA CLITERAL(Color){20,20,20,255}

int main(){
    Tabuleiro tabuleiro;
    InitWindow(450, 450, "Jogo da Velha");
    SetTargetFPS(60);
    int x, y;
    int c = 0;
    char posi[2] = {'x', 'o'};
    while(!WindowShouldClose()){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            x = GetMouseX()/155;
            y = GetMouseY()/155;
            if(tabuleiro.insere_jogada(x, y, posi[c])) c = (c+1)%2;
            
            
        }
        
        BeginDrawing();
        ClearBackground(GRAY);
        DrawRectangle(0, 0, 150, 150, PRETO_CINZA);
        DrawRectangle(0, 155, 150, 150, PRETO_CINZA);
        DrawRectangle(0, 310, 150, 150, PRETO_CINZA);

        DrawRectangle(155, 0, 150, 150, PRETO_CINZA);
        DrawRectangle(155, 155, 150, 150, PRETO_CINZA);
        DrawRectangle(155, 310, 150, 150, PRETO_CINZA);

        DrawRectangle(310, 0, 150, 150, PRETO_CINZA);
        DrawRectangle(310, 155, 150, 150, PRETO_CINZA);
        DrawRectangle(310, 310, 150, 150, PRETO_CINZA);

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                const char* letra = " ";
                int tam = 120;
                if(tabuleiro.tabuleiro[i][j] == 'x') letra = "X";
                else if(tabuleiro.tabuleiro[i][j] == 'o') letra = "O";
                int centro_x = (i*155) + (150/2);
                int centro_y = (j*155) + (150/2);
                int largura = MeasureText(letra, tam);
                int posi_x = centro_x - (largura/2);
                int posi_y = centro_y - (tam/2);
                DrawText(letra, posi_x, posi_y, tam, GRAY);
            }
        }
        EndDrawing();

    }
    CloseWindow();

    return 0;
}