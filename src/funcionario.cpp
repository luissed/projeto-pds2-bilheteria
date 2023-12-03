#include "funcionario.hpp"

bool Funcionario::alterarNome(std::string novoNome){
    if(!novoNome.empty()){
        this->_nome=novoNome;
        std::cout<<"NOME ALTERADO COM SUCESSO"<<std::endl;
        return true;
    }
    std::cout<<"NOME INVALIDO"<<std::endl;
    return false;
}

bool Funcionario::alterarSenha(std::string novaSenha){
    if(!novaSenha.empty()){
        this->_senha=novaSenha;
        std::cout<<"SENHA ALTERADA COM SUCESSO"<<std::endl;
        return true;
    }
    std::cout<<"SENHA INVALIDA"<<std::endl;
    return false;
}

bool Funcionario::alterarCargo(unsigned short int novoCargo){
    switch(novoCargo){
        case 1:
            this->_cargoFuncionario=CAIXA;
        break;
        case 2:
            this->_cargoFuncionario=ORGANIZADOR;
        break;
        case 3:
            this->_cargoFuncionario=GERENTE;
        break;
        default:
            std::cout<<"ENTRADA INVALIDA"<<std::endl;
            return false;
        break;
    }
    return true;
}

void Funcionario::atualizarVenda(double valorVenda){
    this->_vendas+=valorVenda;
}

void Funcionario::resetarVenda(void){
    this->_vendas=0;
}

double Funcionario::getVendas(void){
    return this->_vendas;
}


void Funcionario::exibirFuncionario(void){
    std::cout<<"NOME: "<<this->_nome<<std::endl;
    std::cout<<"CARGO: ";
    switch(this->_cargoFuncionario){
        case CAIXA:
            std::cout<<"CAIXA"<<std::endl;
        break;
        case ORGANIZADOR:
            std::cout<<"ORGANIZADOR"<<std::endl;
        break;
        case GERENTE:
            std::cout<<"GERENTE"<<std::endl;
        break;
        default:
            std::cout<<"SEM CARGO"<<std::endl;
        break;
    }
}

bool Funcionario::realizarLogin(unsigned long int id, std::string senha){
    if(this->_id==id&&this->_senha==senha){
        std::cout<<"BEM VINDO "<<this->_nome<<std::endl;
        return true;
    }
    std::cout<<"ID OU SENHA INVALIDOS"<<std::endl;
    return false;
}

long unsigned int Funcionario::getId(){
    return this->_id;
}

std::string Funcionario::getNome(){
    return this->_nome;
}

std::string Funcionario::getSenha(){
    return this->_senha;
}


Cargos Funcionario::getCargo(void){
    return this->_cargoFuncionario;
}