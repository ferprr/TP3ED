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
    int pos = 1;

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
            enumPreOrdem(raiz, pos);
        } else if (no->esq == nullptr){
            aux = no;
            no = no->dir;
            free(aux);
            enumPreOrdem(raiz, pos);
        } else {
            antecessor(no, no->esq);
            enumPreOrdem(raiz, pos);
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
void ArvoreBinaria::enumPreOrdem(TipoNo *p, int &pos) {
        if (p!=nullptr) {
            p->pos = pos++;
            enumPreOrdem(p->esq, pos);
            enumPreOrdem(p->dir, pos);
        }
}
void ArvoreBinaria::encripta(int qnt){

    int i = 0;
    string mensagem;
    while (i<qnt) {

        int pos = 0;
        cin >> mensagem;
        encriptaRecursivo(raiz, mensagem, &pos);
        i++;
    }
    
    cout << endl;
}
void ArvoreBinaria::encriptaRecursivo(TipoNo *p, string mensagem, int *pos){
    if (p!=nullptr) {
        *pos++;
        if(p->chave == mensagem){
            cout << p->pos << " ";
        }
        encriptaRecursivo(p->esq, mensagem, pos);
        encriptaRecursivo(p->dir, mensagem, pos);
    }
}
void ArvoreBinaria::desencripta(int qnt){
    int i = 0;
    int criptografia;
    while (i<qnt)
    {
        cin >> criptografia;
        desencriptaRecursivo(raiz, criptografia);
        i++;
    }

    cout << endl;
}
void ArvoreBinaria::desencriptaRecursivo(TipoNo* p, int criptografia){
    if (p!=nullptr) {
        if(p->pos == criptografia) {
            cout << p->chave << " ";
        }

        desencriptaRecursivo(p->esq, criptografia);
        desencriptaRecursivo(p->dir, criptografia);
    }
} 