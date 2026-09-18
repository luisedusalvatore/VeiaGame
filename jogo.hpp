# include <iostream>
# include <stdio.h>
using namespace std;
# ifndef JOGO_HPP
# define JOGO_HPP

    int tripla_comparacao(char a, char b, char c){
        if(a == b && a == c) return 1;
        return 0;
    }
    class Tabuleiro {
        private : 
            char tabuleiro[3][3] = {
                {' ',' ',' '},
                {' ',' ',' '},
                {' ',' ',' '}
            };
            int verifica_jogada(int x, int y){
                if(x > 3 || x < 1) return 0;
                if(y > 3 || y < 1) return 0;
                if(tabuleiro[x-1][y-1] != ' ') return 0;
                return 1;
            }
        public :
            
            int insere_jogada(int x, int y, char c){
                if(verifica_jogada(x, y)){
                    tabuleiro[x-1][y-1] = c;
                    return 1;
                }
                return 0;
            }
            int verifica_vencedor(){
                for(int i = 0; i < 3; i++){
                    if(tripla_comparacao(tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]) && tabuleiro[i][0] != ' ') return 1;
                    if(tripla_comparacao(tabuleiro[0][i], tabuleiro[1][i], tabuleiro[2][i]) && tabuleiro[0][i] != ' ') return 1;
                }
                if(tripla_comparacao(tabuleiro[0][0], tabuleiro[1][1], tabuleiro[2][2]) && tabuleiro [0][0] != ' ') return 1;
                if(tripla_comparacao(tabuleiro[0][2], tabuleiro[1][1], tabuleiro[2][0]) && tabuleiro[0][2] != ' ') return 1;
                return 0;
            }
            int eh_velha(){
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(tabuleiro[i][j] == ' ') return 0;
                    }
                }
                return 1;
            }
            void imprime_tabuleiro(){
                printf("-------\n");
                printf("|%c|%c|%c|\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
                printf("-------\n");
                printf("|%c|%c|%c|\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
                printf("-------\n");
                printf("|%c|%c|%c|\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
            }
            void limpa_tabuleiro(){
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j ++){
                        tabuleiro[i][j] = ' ';
                    }
                }
            }
        
    };
    int jogada(Tabuleiro *tabuleiro, char jogador){
        int x, y;
        char q;
        cout << "Que posicao vc deseja jogar[x][y] (vez de "<<jogador<<")";
        cin >> x >> y;
        while(!tabuleiro->insere_jogada(x, y, jogador)){
            tabuleiro->imprime_tabuleiro();
            cout << "Opção invalida poe um x e um y valido cabecao ";
            cin >> x >> y;
        }
        tabuleiro->imprime_tabuleiro();
        if(tabuleiro->eh_velha() || tabuleiro->verifica_vencedor()){
            if(tabuleiro->verifica_vencedor())cout << jogador <<" venceu, deseja jogar novamente? (s/n) ";
            else cout << "Houve empate :( deseja jogar novamente? (s/n) ";
            cin >> q;
            while(q != 's' && q != 'n'){

                cout << "Poe uma opcao valida cabecao ";
                cin >> q;
            }
            if(q == 's'){ 
                tabuleiro->limpa_tabuleiro();
                tabuleiro->imprime_tabuleiro();
                return 2;
            }
            else return 0;
        }
        return 1;
    }
    void jogo_da_veia(){
        Tabuleiro tabuleiro;
        int i, verifiq;
        char q[2] = {'x', 'o'};
        verifiq = 1;
        i = 0;
        tabuleiro.imprime_tabuleiro();
        while(verifiq){
            i = i%2;
            verifiq = jogada(&tabuleiro, q[i]);
            if(verifiq == 1) i++;
    }
    }
# endif
