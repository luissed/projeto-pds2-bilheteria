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