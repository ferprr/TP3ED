#ifndef arvoreBinaria
#define arvoreBinaria
#include "TipoNo.h"
#include <string>

using std::string;

class ArvoreBinaria {

    public:
        ArvoreBinaria();
        //~ArvoreBinaria();

        void insere(string item);
        void remove(string item);
        void imprimePreOrdem();
        void encripta(int qnt);
        void desencripta(int qnt);

    private:
        void insereRecursivo(TipoNo* &p, string item);
        void enumPreOrdem(TipoNo *p, int &pos);
        void removeRecursivo(TipoNo* &p, string item);
        void antecessor(TipoNo* q, TipoNo* &r);
        void preOrdem(TipoNo* p);
        void encriptaRecursivo(TipoNo *raiz, string mensagem, int *pos);
        void desencriptaRecursivo(TipoNo* raiz, int criptografia);

        TipoNo *raiz;
};

#endif