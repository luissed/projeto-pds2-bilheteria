#include "compra.hpp"
double Compra::realizaCompra(Sessao* sessao){
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
        do{
            sessao->getSala().exibirSala();
            coluna.clear();
            linha.clear();
            for(unsigned long int i=0; i<this->_quantidadeIngressos;++i){
                std::cout<<"C";
                std::cin>>aux;
                coluna.push_back(aux);
                std::cout<<"L";
                std::cin>>aux;
                linha.push_back(aux);
            }
        }while(!sessao->venderIngressos(coluna, linha));
    }
    else{
        std::cout<<"COMPRA CANCELADA"<<std::endl;
        return 0;
    }
    std::ofstream outfile ("./ingressos/#"+sessao->getFilme()->getTitulo()+".txt");
    outfile << "INGRESSOS COMPRADOS: "<<this->_quantidadeIngressos<<std::endl;

    for(unsigned long int i=0;i<coluna.size();++i){
        outfile << "ASSENTO: L"<<linha.at(i)<<"C"<<coluna.at(i)<<std::endl;
    }
    outfile.close();
    return this->_valorPagamento;
}

void Compra::imprimirCompra(Cliente* cliente, unsigned int id){
    std::ofstream outfile ("./recibos/compra #"+std::to_string(id)+".txt");
    outfile << cliente->exibirCliente().str();
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

void Compra::imprimirCompra(std::string nome, std::string cpf, unsigned int id){
    std::ofstream outfile ("./recibos/compra #"+std::to_string(id)+".txt");
    outfile <<"NOME: "<<nome<<std::endl;
    outfile <<"CPF: "<<cpf<<std::endl;
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

unsigned short int Compra::getQuantidadeIngressos(void){
    return this->_quantidadeIngressos;
}

