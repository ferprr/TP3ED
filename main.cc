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
        if (option == 'i') {
            string chave;
            cin >> chave;
            //cout << chave << " ";
            arvore.insere(chave);

        } else if (option == 's') {
            string substituir;
            cin >> substituir;
            string nova;
            cin >> nova;
            arvore.remove(substituir);
            arvore.insere(nova);

        } else if (option == 'e') {
            //arvore.imprimePreOrdem();
            
            int x;
            cin >> x;
            arvore.encripta(x);

            cout << endl;
            
        } else if (option = 'd') {
            int x;
            cin >> x;
            arvore.desencripta(x);

            cout << endl;

        } else {
            cout << "Opção inválida." << endl;
        }
        cin >> option;
    }
}