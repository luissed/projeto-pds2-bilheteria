#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <string>
#include <iostream>
#include <iomanip>


enum Cargos
{
    CAIXA,
    ORGANIZADOR,
    GERENTE,
    SEM_CARGO
};


class Funcionario{
    private:
    unsigned long int _id;
    std::string _nome;
    std::string _senha;
    Cargos _cargoFuncionario;
    double _vendas;
    public:
    /// @brief Construtor da classe Funcionário
    /// @param id ID do Funcionário
    /// @param nome Nome do Funcionário
    /// @param senha Senha do Funcionário
    /// @param cargoFuncionario Cargo do Funcionário
    Funcionario(unsigned long int id, std::string nome, std::string senha, Cargos cargoFuncionario) :
    _id(id), _nome(nome), _senha(senha), _cargoFuncionario(cargoFuncionario), _vendas(0) {};

    /// @brief Altera o nome de um Funcionário
    /// @param novoNome Novo nome para o Funcionário
    /// @return Retorna se a operação foi concluída
    bool alterarNome(std::string novoNome);

    /// @brief Altera a senha de um Funcionário
    /// @param novaSenha Nova senha para o Funcionário
    /// @return Retorna se a operação foi concluída
    bool alterarSenha(std::string novaSenha);

    /// @brief Altera o cargo de um Funcionário
    /// @param novoCargo Novo cargo para o Funcionário
    /// @return Retorna se a operação foi concluída    
    bool alterarCargo(unsigned short int novoCargo);

    /// @brief Atualiza o total das vendas realizadas
    /// @param valorVenda Nova senha para o Funcionário
    /// @return Retorna se a operação foi concluída
    void atualizarVenda(double valorVenda);

    /// @brief Reseta o valor da venda
    void resetarVenda(void);

    /// @brief Exibe as informações de um Funcionário
    void exibirFuncionario(void);

    /// @brief Realiza o login de um Funcionário
    /// @param id ID do Funcionário
    /// @param senha Senha do Funcionário
    /// @return Retorna se a operação foi concluída
    bool realizarLogin(unsigned long int id, std::string senha);

    /// @brief Recebe o valor da venda realizada
    /// @return Retorna o valor da venda realizada
    double getVendas(void);

    /// @brief Recebe o ID do Funcionário
    /// @return Retorna o ID do Funcionário
    long unsigned int getId();

    /// @brief Recebe o nome do Funcionário
    /// @return Retorna uma string do nome do Funcionário
    std::string getNome();

    /// @brief Recebe a senha do Funcionário
    /// @return Retorna uma string da senha do Funcionário
    std::string getSenha();

    /// @brief Recebe o cargo do Funcionário
    /// @return Retorna um cargo do Funcionário
    Cargos getCargo(void);
};

#endif