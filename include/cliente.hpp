#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Cliente{
    private:
    std::string _nome;
    std::string _email;
    unsigned short int _idade;
    std::string _cpf;
    public:

    /// @brief Inicializa um cliente com um nome, email, idade e CPF
    /// @param nome Nome do cliente
    /// @param email Email do cliente
    /// @param idade Idade do cliente
    /// @param cpf CPF do cliente
    Cliente(std::string nome, std::string email, unsigned short int idade, std::string cpf) :
    _nome(nome), _email(email), _idade(idade), _cpf(cpf) {};
    std::string getNome();
    std::string getEmail();
    unsigned short int getIdade();
    std::string getCpf();
    std::stringstream exibirCliente(void);
};

#endif