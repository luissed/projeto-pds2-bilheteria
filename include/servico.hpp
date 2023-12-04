#ifndef SERVICO_HPP
#define SERVICO_HPP
 
#include "funcionario.hpp"
#include "sessao.hpp"
#include "compra.hpp"
#include <string>
#include <map>
#include <fstream>

class Servico{
    private:
    std::map<long unsigned int, Funcionario*> _funcionarios;
    std::map<long unsigned int, Filme*> _filmes;
    std::map<long unsigned int, Sessao*> _sessoes;
    std::map<long unsigned int, Compra*> _compras; 
    std::map<long unsigned int, Sala*> _salas;
    std::map<std::string, Cliente*> _clientes;
    unsigned long int _idUsuario;
    unsigned long int _idSessao;
    unsigned long int _idCompra;
    unsigned long int _idFilme;
    unsigned long int _idSala;
    unsigned long int _sessoesRealizadas;
    unsigned long int _sessoesCanceladas;

    public:
    Servico() : _idUsuario(1), _idSessao(1), _idCompra(1), _idFilme(1), _idSala(1), _sessoesRealizadas(0),_sessoesCanceladas(0) {};
    ~Servico();
    //gerente
    void cadastrarFuncionario(std::string nome, std::string senha, Cargos cargoFuncionario);
    bool editarFuncionario(unsigned long int idFuncionario);
    bool demitirFuncionario(unsigned long int idFuncionario);
    void mostrarFuncionarios(void);
    Cargos realizarLogin(long unsigned int id, std::string senha);
    bool adicionarSala(std::string nome, unsigned short int colunas, unsigned short int linhas, float valorIngresso);
    bool editarSala(unsigned long int idSala);
    void mostrarSalas(void);
    void mostrarSalasAtivas(void);
    void habilitarSala(unsigned long int idSala);
    void relatorioMensal(void);
    //organizador
    void adicionarFilme(int duracaoM, std::string titulo, CLASSIFICACAO classificacao, std::string genero);
    bool removerFilmeCartaz(unsigned long int idFilme);
    bool editarFilme(unsigned long int idFilme);
    void exibirFilmesEmCartaz(void);
    void exibirFilmes(void);
    bool criarSessao(unsigned long int idSala, unsigned long int idFilme, tm horario);
    bool trocarSalaSessao(unsigned long int idSala, unsigned long int idSessao);
    void exibirSessoes(void);
    void exibirSessoesAtivas(void);
    //caixa
    void adicionarCliente(std::string nome, std::string email, unsigned short int idade, std::string cpf);
    void exibirSessoesFilmes(void);
    void venderIngressos(unsigned long int idFuncionario, unsigned long int idSessao, std::string nome, std::string cpf);
};

void validarCPF(std::string* cpf);
void validarId(std::string* id);

#endif