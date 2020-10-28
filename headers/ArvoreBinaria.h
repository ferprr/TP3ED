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
        //void caminha(int tipo);
        int pesquisa(string item);
        string pesquisaPorPosicao(int k);
        void remove(string item);
        //void limpa();

    private:
        void insereRecursivo(TipoNo* &p, string item);
        void apagaRecursivo(TipoNo* p);
        int pesquisaRecursivo(TipoNo* p, string item);
        string pesquisaPorPosicaoRecursivo(TipoNo* no, int k);
        void enumPreOrdem(TipoNo *p, int &pos);
        void removeRecursivo(TipoNo* &p, string item);
        void antecessor(TipoNo* q, TipoNo* &r);
        void preOrdem(TipoNo* p);
        void inOrdem(TipoNo* p);

        TipoNo *raiz;
};

#endif