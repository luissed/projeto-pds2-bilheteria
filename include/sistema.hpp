#ifndef SISTEMA_HPP
#define SISTEMA_HPP
 
#include "usuario.hpp"
#include "funcionario.hpp"
#include <string>
#include <map>

class Sistema : public Usuario{
    private:
    static std::map<long unsigned int, Funcionario*> _listaFuncionarios;
    public:
    Sistema();
    Sistema(std::string nome, std::string senha);
    void cadastrarFuncionario(Funcionario* novoFuncionario);
    void editarFuncionario(unsigned long int idFuncionario);
    void demitirFuncionario(unsigned long int idFuncionario);
    void mudarNome(unsigned long int idFuncionario);
    void mudarSenha(unsigned long int idFuncionario);
    void mudarCargo(unsigned long int idFuncionario);
    void mostrarFuncionarios(void);
    Cargos RealizarLogin(long unsigned int id, std::string senha);
};

#endif