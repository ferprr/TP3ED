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
    
    ArvoreBinaria arvore;
    int pos = 0;

    char option;
    //cin >> option;
    option = cin.get();
    string chave;
    string substituir;
    string nova;

    //cout << option << endl;

    while(!cin.eof()) {
        switch (option)
        {
        case 'i':
            //cout << option << endl;
            cin >> chave;
            //cout << chave << " ";
            arvore.insere(chave);

            //arvore.imprimePreOrdem();
            break;

        
        case 's':
            //cout << option << endl;
            cin >>  substituir;
            //cout << "substituir: " << substituir << " ";
            cin >> nova;
            //cout << "nova: " << nova << endl;
            arvore.remove(substituir);
            arvore.insere(nova);

            //arvore.imprimePreOrdem();
            break;

        case 'e':
            //cout << option << endl;
            //arvore.imprimePreOrdem();
            int k;
            cin >> k;
            arvore.encripta(k);

            //arvore.imprimePreOrdem();
            break;

        case 'd':
            //cout << option << endl;
            //arvore.imprimePreOrdem();
            int x;
            cin >> x;
            arvore.desencripta(x);

            //arvore.imprimePreOrdem();
            break;

        default:
            break;
        }
        // if (option == 'i') {
        //     string chave;
        //     cin >> chave;
        //     //cout << chave << " ";
        //     arvore.insere(chave);

        // } else if (option == 's') {
        //     string substituir;
        //     cin >> substituir;
        //     string nova;
        //     cin >> nova;
        //     arvore.remove(substituir);
        //     arvore.insere(nova);

        // } else if (option == 'e') {
        //     //arvore.imprimePreOrdem();
            
        //     int x;
        //     cin >> x;
        //     arvore.encripta(x);

        //     cout << endl;
            
        // } else if (option = 'd') {
        //     int x;
        //     cin >> x;
        //     arvore.desencripta(x);

        //     cout << endl;

        // } else {
        //     cout << "Opção inválida." << endl;
        // }
        cin >> option;
    }
}