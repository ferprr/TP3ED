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

    char option;
    option = cin.get();
    string chave;
    string substituir;
    string nova;

    while(!cin.eof()) {
        switch (option)
        {
        case 'i':
            cin >> chave;
            arvore.insere(chave);
            break;
        
        case 's':
            cin >>  substituir;
            cin >> nova;
            arvore.remove(substituir);
            arvore.insere(nova);
            break;

        case 'e':
            int k;
            cin >> k;
            arvore.encripta(k);
            break;

        case 'd':
            int x;
            cin >> x;
            arvore.desencripta(x);

            break;

        default:
            break;
        }
        cin >> option;
    }
}