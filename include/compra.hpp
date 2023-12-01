#ifndef COMPRA_HPP
#define COMPRA_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "cliente.hpp"
#include "sessao.hpp"

enum TIPO_PAGAMENTO{
    PIX,
    DEBITO,
    CREDITO,
    DINHEIRO
};

class Compra{
    private:
    TIPO_PAGAMENTO _pagamento;
    unsigned short int _quantidadeIngressos;
    double _valorPagamento;
    public:
    Compra() : _quantidadeIngressos(0) {};
    bool realizaCompra(Sessao* sessao);
    void imprimirCompra(Cliente cliente, unsigned int id);
};

#endif