#ifndef SERVICO_HPP
#define SERVICO_HPP
 

#include "funcionario.hpp"
#include "sessao.hpp"
#include "compra.hpp"
#include <string>
#include <map>

class Servico{
    private:
    std::map<long unsigned int, Funcionario*> _Funcionarios;
    std::map<long unsigned int, Sessao*> _Sessoes;
    std::map<long unsigned int, Compra*> _Compras;
    unsigned long int _idUsuario;
    unsigned long int _idSessao;
    unsigned long int _idCompra;
    public:
    Servico() : _idUsuario(0), _idSessao(0), _idCompra(0) {};
    void cadastrarFuncionario(std::string nome, std::string senha, Cargos cargoFuncionario);
    bool editarFuncionario(unsigned long int idFuncionario);
    bool demitirFuncionario(unsigned long int idFuncionario);
    void mostrarFuncionarios(void);
    Cargos RealizarLogin(long unsigned int id, std::string senha);
};

#endif