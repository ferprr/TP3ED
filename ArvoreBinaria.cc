#include "headers/ArvoreBinaria.h"
#include <string>
#include <iostream>
#include <string.h>

using std::string;
using std::cout;
using std::endl;

ArvoreBinaria::ArvoreBinaria(){
    raiz = nullptr;
}
int ArvoreBinaria::pesquisa(string item) {
    return pesquisaRecursivo(raiz, item);
}
int ArvoreBinaria::pesquisaRecursivo(TipoNo *no, string item){

    if (no == nullptr) {
        int aux = 0;
        return aux;
    }

    if (item < no->chave){
        return pesquisaRecursivo(no->esq, item);
    } else if (item > no->chave) {
        return pesquisaRecursivo(no->dir, item);
    } else {
        return no->pos;
    }
}
string ArvoreBinaria::pesquisaPorPosicao(int k) {
    pesquisaPorPosicaoRecursivo(raiz, k);
}
string ArvoreBinaria::pesquisaPorPosicaoRecursivo(TipoNo* no, int k) {
    cout << "passou" << endl;
    if (no->pos == k) {
        cout << "passou 1 " << endl;
        cout << no->chave << endl;
        return no->chave;
    } else if (k < no->pos) {
        return pesquisaPorPosicaoRecursivo(no->esq, k);
    } else if (k > no->pos){
        return pesquisaPorPosicaoRecursivo(no->dir, k);
    } else {
        return " ";
    }
}
void ArvoreBinaria::insere(string item) {
    insereRecursivo(raiz, item);
}
void ArvoreBinaria::insereRecursivo(TipoNo* &p, string item) {
    if(p == nullptr) {
        p = new TipoNo();
        p->chave = item;
        //p->pos++;
        //cout << "inOrdem" << endl;
        //preOrdem(raiz);
        // int i = 1;
        int pos = 1;
        enumPreOrdem(raiz, pos);
    } else {
        if(item < p->chave) {
            insereRecursivo(p->esq, item);
        } else {
            insereRecursivo(p->dir, item);
        }
    }
}
void ArvoreBinaria::remove(string item) {
    removeRecursivo(raiz, item);
}
void ArvoreBinaria::removeRecursivo(TipoNo* &no, string item) {
    TipoNo *aux;

    if(no == nullptr) {
        throw("Item não está presente.");
    } 
    if (item < no->chave) {
        return removeRecursivo(no->esq, item);
    } else if (item > no->chave) {
        return removeRecursivo(no->dir, item);
    } else {
        if (no->dir == nullptr) {
            aux = no;
            no = no->dir;
            free(aux);
        } else if (no->esq == nullptr){
            aux = no;
            no = no->dir;
            free(aux);
        } else {
            antecessor(no, no->esq);
        }
    }
}
void ArvoreBinaria::antecessor(TipoNo *q, TipoNo* &r) {
    if(r->dir != nullptr) {
        antecessor(q, r->dir);
        return;
    }
    q->chave = r->chave;
    q = r;
    r = r->esq;
    free(q);
}
void ArvoreBinaria::preOrdem(TipoNo *p) {
    if (p!=nullptr) {
        cout << p->chave << " " << endl;
        preOrdem(p->esq);
        preOrdem(p->dir);
    }
}
void ArvoreBinaria::inOrdem(TipoNo *p) {
    if (p!=nullptr) {
        inOrdem(p->esq);
        cout << p->chave << " ";
        inOrdem(p->dir);
    }
}
void ArvoreBinaria::enumPreOrdem(TipoNo *p, int &pos) {
        if (p!=nullptr) {
            p->pos = pos++;
            cout << "palavra: " << p->chave << " " << "posição: " << p->pos << endl;
            enumPreOrdem(p->esq, pos);
            enumPreOrdem(p->dir, pos);
        }
}