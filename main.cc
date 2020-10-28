#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include "headers/ArvoreBinaria.h"
#include "headers/TipoNo.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main () {
    
    // int total_nos;
    // cin >> total_nos;

    // cin.get();

    // cout << "leu total" << endl;

    ArvoreBinaria arvore;
    int pos = 0;

    char option;
    //cin >> option;
    option = cin.get();

    cout << option << endl;

    while(!cin.eof()) {
        if (option == 'i') {
            char chave[15];
            cin >> chave;
            cout << chave << " ";
            arvore.insere(chave);

        } else if (option == 's') {
            char substituir[15];
            //cin >> substituir;
            *substituir = cin.get();
            char nova[15];
            //cin >> nova;
            *nova = cin.get();
            //pos--;
            arvore.remove(substituir);
            //pos++;
            arvore.insere(nova);

        } else if (option == 'e') {
            cin.get();
            //cout << "option: "<< option << endl;
            int x;
            cin >> x;
            //x = cin.get();
            //cout << "i: " << x << endl;

            for (int j=0; j<x; j++){
                //cout << "passou for " << endl;
                char mensagem[15];
                cin >> mensagem;
                //*mensagem = cin.get();
                //cout << "mensagem : " << mensagem << endl;
                int aux = arvore.pesquisa(mensagem);
                cout << "pos: " << aux << endl;
            }
            
        } else if (option = 'd') {
            cin.get();
            int i;
            //i = cin.get();
            cin >> i;

            cout << i << endl;
            for (int j=0; j<i; j++){
                cout << "j: " << j << endl;
                cin.get();
                int k;
                //k = cin.get();
                cin >> k;
                cout << "k: " << k << endl;
                string mensagem;
                mensagem = arvore.pesquisaPorPosicao(k);
                cout << mensagem << " ";
            }

        } else {
            cout << "Opção inválida." << endl;
        }
        cin >> option;
    }
}