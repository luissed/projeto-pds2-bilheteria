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
    Funcionario(unsigned long int id, std::string nome, std::string senha, Cargos cargoFuncionario) :
    _id(id), _nome(nome), _senha(senha), _cargoFuncionario(cargoFuncionario), _vendas(0) {};
    bool alterarNome(std::string novoNome);
    bool alterarSenha(std::string novaSenha);
    bool alterarCargo(unsigned short int novoCargo);
    void atualizarVenda(double valorVenda);
    void resetarVenda(void);
    void exibirFuncionario(void);
    bool realizarLogin(unsigned long int id, std::string senha);
    double getVendas(void);
    long unsigned int getId();
    std::string getNome();
    std::string getSenha();
    Cargos getCargo(void);
};

#endif
