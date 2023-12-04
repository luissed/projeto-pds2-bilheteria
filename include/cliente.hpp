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
    /// @brief Construtor da classe Cliente
    /// @param nome Nome do Cliente
    /// @param email E-mail do Cliente
    /// @param idade Idade do Cliente
    /// @param cpf CPF do Cliente
    Cliente(std::string nome, std::string email, unsigned short int idade, std::string cpf) :
    _nome(nome), _email(email), _idade(idade), _cpf(cpf) {};

    /// @brief Coleta o nome do Cliente
    /// @return Retorna uma string com o nome do Cliente
    std::string getNome();

    /// @brief Coleta o e-mail do Cliente
    /// @return Retorna uma string com o e-mail do Cliente
    std::string getEmail();

    /// @brief Coleta a idade do Cliente
    /// @return Retorna um short inteiro com a idade do Cliente
    unsigned short int getIdade();

    /// @brief Coleta o CPF do Cliente
    /// @return Retorna uma string com o CPF do Cliente
    std::string getCpf();

    /// @brief Manda o texto para criar o arquivo recibo
    /// @return Retorna os dados do Cliente para criar o arquivo de recibo
    std::stringstream exibirCliente(void);
};

#endif