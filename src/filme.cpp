#include "filme.hpp"

Filme::Filme(int duracaoM, std::string titulo, CLASSIFICACAO classificacao, std::string genero){
    _duracao.tm_hour=duracaoM/60;
    _duracao.tm_min=duracaoM%60;
    _titulo=titulo;
    _classificacao=classificacao;
    _genero=genero;
    _bilheteria=0;
    _emCartaz=true;
}

void Filme::atualizarBilheteria(double bilheteria){
    this->_bilheteria+=bilheteria;
}

bool Filme::alterarTitulo(std::string novoTitulo){
    if(!novoTitulo.empty()){
        this->_titulo=novoTitulo;
        std::cout<<"TITULO ALTERADO COM SUCESSO"<<std::endl;
        return true;
    }
    std::cout<<"TITULO INVALIDO"<<std::endl;
    return false;
}

bool Filme::alterarDuracao(unsigned short int novaDuracaoM){
    _duracao.tm_hour=novaDuracaoM/60;
    _duracao.tm_min=novaDuracaoM%60;
    return false;
}

bool Filme::alterarClassificacao(unsigned short int novaClassificacao){
    switch(novaClassificacao){
        case 0:
            this->_classificacao=LIVRE;
        break;
        case 12:
            this->_classificacao=_12;
        break;
        case 14:
            this->_classificacao=_14;
        break;
        case 16:
            this->_classificacao=_16;
        break;
        case 18:
            this->_classificacao=_18;
        break;
        default:
            std::cout<<"ENTRADA INVALIDA"<<std::endl;
            return false;
        break;
    }
    return true;
}

bool Filme::alterarGenero(std::string novoGenero){
    if(!novoGenero.empty()){
        this->_titulo=novoGenero;
        std::cout<<"GENERO ALTERADO COM SUCESSO"<<std::endl;
        return true;
    }
    std::cout<<"GENERO INVALIDO"<<std::endl;
    return false;
}


tm Filme::getDuracao(void){
    return this->_duracao;
}

std::string Filme::getTitulo(void){
    return this->_titulo;
}

CLASSIFICACAO Filme::getClassificacao(void){
    return this->_classificacao;
}

std::string Filme::getGenero(void){
    return this->_genero;
}

float Filme::getBilheteria(void){
    return this->_bilheteria;
}

bool Filme::getEmCartaz(void){
    return this->_emCartaz;
}

void Filme::liberarFilme(void){
    this->_emCartaz=!this->_emCartaz;
}

void Filme::exibirFilme(void){
    std::cout<<"----------------------------"<<std::endl;
    std::cout<<this->_titulo<<std::endl;
    std::cout<<"DURACAO "<<this->_duracao.tm_hour<<"h "<<this->_duracao.tm_min<<"m "<<std::endl;
    std::cout<<this->_genero<<std::endl;
    std::cout<<"BILHETERIA: R$"<<std::fixed<<std::setprecision(2)<<this->_bilheteria<<std::endl;
    std::cout<<"CLASSIFICACAO: ";
    switch(this->_classificacao){
        case LIVRE:
            std::cout<<"LIVRE "<<std::endl;
        break;
        case 12:
            std::cout<<"12 ANOS "<<std::endl;
        break;
        case 14:
            std::cout<<"14 ANOS "<<std::endl;
        break;
        case 16: 
            std::cout<<"16 ANOS "<<std::endl;
        break;
        case 18:
            std::cout<<"18 ANOS "<<std::endl;
        break;
    }
    if(this->_emCartaz){
        std::cout<<"ATIVO"<<std::endl;
    }
    else{
        std::cout<<"INATIVO"<<std::endl;
    }
}

Filme& Filme::operator=(const Filme &outra){
    if (this != &outra) {
        this->_titulo=outra._titulo;
        this->_duracao=outra._duracao;
        this->_genero=outra._genero;
        this->_bilheteria=outra._bilheteria;
    }
    return *this;
}
