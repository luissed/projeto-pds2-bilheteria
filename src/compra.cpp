#include "compra.hpp"
bool Compra::realizaCompra(Sessao* sessao){
    unsigned short int aux;
    std::vector<unsigned short int> coluna;
    std::vector<unsigned short int> linha;
    sessao->getSala().exibirSala();
    std::cout<<"QUANTOS INGRESSOS DESEJA COMPRAR?"<<std::endl;
    std::cin>>this->_quantidadeIngressos;
    this->_valorPagamento=_quantidadeIngressos*sessao->getSala().getValorIngresso();
    std::cout<<"TOTAL DE COMPRA: "<<this->_valorPagamento<<"R$"<<std::endl;
    std::cout<<"FORMA DE PAGAMENTO"<<std::endl;
    std::cout<<"1.PIX\t2.DEBITO"<<std::endl;
    std::cout<<"3.CREDITO\t4.DINHEIRO"<<std::endl;
    std::cin>>aux;
    switch(aux){
        case 1:
            this->_pagamento=PIX;
        break;
        case 2:
            this->_pagamento=DEBITO;
        break;
        case 3:
            this->_pagamento=CREDITO;
        break;
        case 4:
            this->_pagamento=DINHEIRO;
        break;
    }
    std::cout<<"PAGAMENTO CONCLUIDO?"<<std::endl;
    std::cout<<"1.SIM\t2.NÃO"<<std::endl;
    std::cin>>aux;
    if(aux==1){
        for(unsigned long int i=0; i<_quantidadeIngressos;++i){
            std::cin>>aux;
            coluna.push_back(aux);
            std::cin>>aux;
            linha.push_back(aux);
        }
    }
    else{
        std::cout<<"COMPRA CANCELADA"<<std::endl;
        return false;
    }
    sessao->venderIngressos(coluna, linha);
    return true;
}

void Compra::imprimirCompra(Cliente cliente, unsigned int id){
    std::ofstream outfile ("./recibos/compra #"+std::to_string(id)+".txt");
    outfile << cliente.exibirCliente().str();
    outfile << "VALOR:" << _valorPagamento<<"R$"<<std::endl;
    outfile <<"PAGAMENTO: ";
    switch(this->_pagamento){
        case PIX:
            outfile <<"PIX"<<std::endl;
        break;
        case DEBITO:
            outfile <<"DEBITO"<<std::endl;
        break;
        case CREDITO:
            outfile <<"CREDITO"<<std::endl;
        break;
        case DINHEIRO:
            outfile <<"DINHEIRO"<<std::endl;
        break;
    }
    outfile.close();

}