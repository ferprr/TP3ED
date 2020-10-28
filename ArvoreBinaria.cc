#include "headers/ArvoreBinaria.h"
#include <string>
#include <iostream>
#include <string.h>

using std::string;
using std::cout;
using std::cin;
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
    if (no->pos == k) {
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
void ArvoreBinaria::imprimePreOrdem(){
    preOrdem(raiz);
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
        cout << "chave: " << p->chave << " " << endl;
        cout << "posição: " << p->pos << " " << endl;
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
            //cout << "palavra: " << p->chave << " " << "posição: " << p->pos << endl;
            enumPreOrdem(p->esq, pos);
            enumPreOrdem(p->dir, pos);
        }
}
void ArvoreBinaria::encripta(int qnt){

    int i = 0;
    string mensagem;
    while (i<qnt)
    {
        cin >> mensagem;
        encriptaRecursivo(raiz, mensagem);
        i++;
    }
    
    
}
void ArvoreBinaria::encriptaRecursivo(TipoNo* p, string mensagem){

    if (p!=nullptr) {
        if(p->chave == mensagem){
            //cout << "posição: " << p->pos << endl;
            cout << p->pos << " ";
        }
        encriptaRecursivo(p->esq, mensagem);
        encriptaRecursivo(p->dir, mensagem);
    }
}
void ArvoreBinaria::desencripta(int qnt){
    int i = 0;
    int criptografia;
    //cout << "qnt: "<< qnt << endl;
    while (i<qnt)
    {
        cin >> criptografia;
        //cout << "cripto: " << criptografia << endl;
        desencriptaRecursivo(raiz, criptografia);
        i++;
    }
}
void ArvoreBinaria::desencriptaRecursivo(TipoNo* p, int criptografia){
    if (p!=nullptr) {
        
        //cout << p->pos << endl;
        if(p->pos == criptografia) {
            //cout << "mensagem: " << p->chave << endl;
            cout << p->chave << " ";
        }
        //p->pos++;
        desencriptaRecursivo(p->esq, criptografia);
        desencriptaRecursivo(p->dir, criptografia);
    }
} 