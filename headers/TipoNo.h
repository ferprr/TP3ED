#ifndef tipoNo
#define tipoNo
#include <string>

using std::string;

class TipoNo {

    public:
        TipoNo();
        int pos;

    private:
        string chave;
        TipoNo *esq;
        TipoNo *dir;

    friend class ArvoreBinaria;

};

#endif