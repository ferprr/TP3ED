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
    string chave;
    string substituir;
    string nova;

    cout << option << endl;

    while(!cin.eof()) {
        // switch (option) {
        //     case 'i':
        //         cin >> chave;
        //         //cout << chave << " ";
        //         arvore.insere(chave);
        //         break;

        //     case 's':
        //         substituir = cin.get();
        //         cin >> nova;
        //         arvore.remove(substituir);
        //         arvore.insere(nova);
        //         break;

        //     case 'e':
        //         //arvore.imprimePreOrdem();
        //         cin.get();
        //         int x;
        //         cin >> x;
        //         for (int j=0; j<x; j++){
        //             //cout << "passou for " << endl;
        //             string mensagem;
        //             cin >> mensagem;
        //             //*mensagem = cin.get();
        //             //cout << "mensagem : " << mensagem << endl;
        //             int aux = arvore.pesquisa(mensagem);
        //             cout << "pos: " << aux << endl;
        //         }
        //         break;

        //     case 'd':
        //         int i;
        //         //i = cin.get();
        //         cin >> i;
        //         for (int j=0; j<i; j++){
        //             cout << "j: " << j << endl;
        //             //cin.get();
        //             int k;
        //             //k = cin.get();
        //             cin >> k;
        //             //cout << "k: " << k << endl;
        //             string mensagem;
        //             mensagem = arvore.pesquisaPorPosicao(k);
        //             cout << mensagem << " ";
        //         }
        //         break;
        //     default:
        //         break;
        // cin >> option;
        if (option == 'i') {
            string chave;
            cin >> chave;
            cout << chave << " ";
            arvore.insere(chave);

        } else if (option == 's') {
            string substituir;
            cin >> substituir;
            //*substituir = cin.get();
            string nova;
            cin >> nova;
            //*nova = cin.get();
            //pos--;
            arvore.remove(substituir);
            //pos++;
            arvore.insere(nova);

        } else if (option == 'e') {
            //arvore.imprimePreOrdem();
            
            int x;
            cin >> x;
            arvore.encripta(x);
            
        } else if (option = 'd') {
            int x;
            cin >> x;
            arvore.desencripta(x);
            // cin.get();
            // int i;
            // //i = cin.get();
            // cin >> i;

            // cout << i << endl;
            // for (int j=0; j<i; j++){
            //     cout << "j: " << j << endl;
            //     cin.get();
            //     int k;
            //     //k = cin.get();
            //     cin >> k;
            //     cout << "k: " << k << endl;
            //     string mensagem;
            //     mensagem = arvore.pesquisaPorPosicao(k);
            //     cout << mensagem << " ";
            // }

        } else {
            cout << "Opção inválida." << endl;
        }
        cin >> option;
    }
}