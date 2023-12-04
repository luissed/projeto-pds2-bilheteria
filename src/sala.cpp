#include "sala.hpp"

Sala::Sala(std::string nome, unsigned short int colunas, unsigned short int linhas,  float valorIngresso){
    for(unsigned short int i=0; i<colunas; ++i){
        std::map<unsigned short int, bool> aux;
        for(unsigned short int j=0; j<linhas; ++j){
                aux.insert({j+1,false});
        }
        this->_assentos.insert(std::make_pair(i+1,aux));
    }
    this->_inativa=false;
    this->_valorIngresso=valorIngresso;
    this->_nome=nome;
}

unsigned long int Sala::tamanhoSala(void){
    std::map<unsigned short int, std::map<unsigned short int, bool>>::iterator it=this->_assentos.begin();
    return _assentos.size()*it->second.size();
}

void Sala::ocuparAssento(unsigned short int coluna, unsigned short int linha){
    this->_assentos.at(coluna).at(linha)=true;
}

unsigned long int Sala::assentosOcupados(void){
    unsigned long int quant=0;
    for(std::map<unsigned short int, std::map<unsigned short int, bool>>::iterator it1=this->_assentos.begin();it1!=this->_assentos.end();++it1){
        for(std::map<unsigned short int, bool>::iterator it2=it1->second.begin();it2!=it1->second.end();++it2){ 
            if(it2->second){
                quant++;
            }
        }
    }
    return quant;
}

void Sala::editarSala(float valorIngresso){
    this->_valorIngresso=valorIngresso;
}

void Sala::editarSala(unsigned short int colunas, unsigned short int linhas){
    this->_assentos.clear();
    for(unsigned short int i=0; i<colunas; ++i){
        std::map<unsigned short int, bool> aux;
        for(unsigned short int j=0; j<linhas; ++j){
                aux.insert({j+1,false});
        }
        this->_assentos.insert(std::make_pair(i+1,aux));
    }
}

void Sala::editarSala(std::string novoNome){
    if(!novoNome.empty()){
        this->_nome=novoNome;
        std::cout<<"NOME ALTERADO COM SUCESSO"<<std::endl;
        return ;
    }
    std::cout<<"NOME INVALIDO"<<std::endl;
}

void Sala::exibirSala(void){
    std::cout<<this->_nome<<std::endl;
    for(std::map<unsigned short int, std::map<unsigned short int, bool>>::iterator it1=_assentos.begin();it1!=_assentos.end();++it1){
        for(std::map<unsigned short int, bool>::iterator it2=it1->second.begin();it2!=it1->second.end();++it2){ 
            if(it2->second){
                std::cout<<OCUPADO<<"[L"<<it1->first<<"C"<<it2->first<<"] ";
            }
            else{
                std::cout<<LIBERADO<<"[L"<<it1->first<<"C"<<it2->first<<"] ";
            }
        }
        std::cout<<SEM_COR<<std::endl;
    }
}

std::map <unsigned short int, std::map<unsigned short int, bool>>* Sala::getAssentos(void){
    return &this->_assentos;
}


std::string Sala::getNome(void){
    return this->_nome;
}


void Sala::habilitarSala(void){
    this->_inativa=!this->_inativa;
}

bool Sala::getInativa(void){
    return this->_inativa;
}

float Sala::getValorIngresso(void){
    return this->_valorIngresso;
}

Sala& Sala::operator=(const Sala &outra){
    if (this != &outra) {
        this->_nome=outra._nome;
        this->_assentos=outra._assentos;
        this->_valorIngresso=outra._valorIngresso;
        this->_inativa=outra._inativa;
    }
    return *this;
}