#include "sessao.hpp"

Sessao::Sessao( Sala* sala, Filme* filme, tm horario){
    this->_sala=*sala;
    this->_filme=filme;
    this->_horario=horario;
    std::cout<<"SESSAO AGENDADA COM SUCESSO"<<std::endl;
}

/*Sessao::~Sessao(){
    delete this->_filme;
}*/


bool Sessao::venderIngressos(std::vector<unsigned short int> coluna, std::vector<unsigned short int> linha){
    bool assentosOcupados=false;
    Sala aux=this->_sala;
    if(coluna.size()<(aux.tamanhoSala()-aux.assentosOcupados())){
        for(unsigned long int it1=0;it1<coluna.size();++it1){
            if(aux.getAssentos()->find(coluna.at(it1))!=aux.getAssentos()->end()){
                if(aux.getAssentos()->at(coluna.at(it1)).find(linha.at(it1))!=aux.getAssentos()->at(coluna.at(it1)).end()){
                    if(!aux.getAssentos()->at(coluna.at(it1)).at(linha.at(it1))&&(!assentosOcupados)){
                        aux.ocuparAssento(coluna.at(it1),linha.at(it1));
                    }
                    else{
                        assentosOcupados=true;
                        break;
                    }
                }
                else{
                    std::cout<<"LINHA INEXISTENTE"<<std::endl;
                    return false;
                }
            }
            else{
                std::cout<<"COLUNA INEXISTENTE"<<std::endl;
                return false;
            }
        }
        if(!assentosOcupados){
            this->_filme->atualizarBilheteria(this->_sala.getValorIngresso()*(coluna.size()));
            this->_sala=aux;
            std::cout<<"COMPRA BEM SUCEDIDA"<<std::endl;
        }
        else{
            std::cout<<"SOLICITADO ASSENTOS JÁ UTILIZADOS, COMPRA CANCELADA"<<std::endl;
            return false;
        }
        return true;
    }
    else{
        std::cout<<"SEM ASSENTOS LIVRES O SUFICIENTE"<<std::endl;
        return false;
    }
}

void Sessao::exibirSessao(void){
    char horario[80];
    strftime(horario, 80,"%d/%m/%Y %H:%M", &this->_horario);
    std::cout<<this->_filme->getTitulo()<<std::endl;
    std::cout<<horario<<std::endl;
    this->_sala.exibirSala();
}

void Sessao::alterarSala(Sala* sala){
    this->_sala=*sala;
}

Sala Sessao::getSala(void){
    return this->_sala;
}

Filme* Sessao::getFilme(void){
    return this->_filme;
}
tm Sessao::getHorario(void){
    return this->_horario;
}