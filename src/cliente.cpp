#include "cliente.hpp"


std::string Cliente::getNome(){
    return this->_nome;
}

std::string Cliente::getEmail(){
    return this->_email;
}

unsigned short int Cliente::getIdade(){
    return this->_idade;
}

std::string Cliente::getCpf(){
    return this->_cpf;
}

std::stringstream Cliente::exibirCliente(void){
    std::stringstream os;
    os<<"NOME: "<<this->_nome<<std::endl;
    os<<"EMAIL: "<<this->_email<<std::endl;
    os<<"IDADE: "<<this->_idade<<" anos"<<std::endl;
    os<<"CPF: "<<this->_cpf.substr(0,3)<<"."<<this->_cpf.substr(3,3)<<"."<<this->_cpf.substr(6,3)<<"-"<<this->_cpf.substr(10,2)<<std::endl;
    return os;
}