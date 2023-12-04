#ifndef COMPRA_HPP
#define COMPRA_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "cliente.hpp"
#include "sessao.hpp"

enum TIPO_PAGAMENTO{
    PIX,
    DEBITO,
    CREDITO,
    DINHEIRO
};

class Compra{
    private:
    TIPO_PAGAMENTO _pagamento;
    unsigned short int _quantidadeIngressos;
    double _valorPagamento;
    public:
    /// @brief Construtor de classe Compra
    Compra() : _quantidadeIngressos(0) {};

    /// @brief Realiza a compra em relação a uma sessão
    /// @param sessao Ponteiro para uma nova sessão a ser comprada
    /// @return Retorna o valor do pagamento
    double realizaCompra(Sessao* sessao);

    /// @brief Imprime os dados do cliente cadastrado
    /// @param cliente Nome do Cliente cadastrado
    /// @param id ID do Cliente cadastrado
    void imprimirCompra(Cliente* cliente, unsigned int id);

    /// @brief Imprime os dados do Cliente que não está cadastrado
    /// @param nome Nome do Cliente
    /// @param cpf CPF do Cliente
    /// @param id ID do Cliente
    void imprimirCompra(std::string nome, std::string cpf, unsigned int id);

    /// @brief Coleta a quantidade de ingressos desejada
    /// @return Retorna a quantidade de ingressos desejada
    unsigned short int getQuantidadeIngressos(void);

};

#endif