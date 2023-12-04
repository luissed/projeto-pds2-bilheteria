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
    /// @brief Construtor da classe Servico
    Servico() : _idUsuario(1), _idSessao(1), _idCompra(1), _idFilme(1), _idSala(1), _sessoesRealizadas(0),_sessoesCanceladas(0) {};

    /// @brief Destrutor da classe Servico
    ~Servico();
    //gerente

    /// @brief Cadastra um novo funcionário
    /// @param nome Nome do novo funcionário
    /// @param senha Senha do novo funcionário
    /// @param cargoFuncionario Cargo do novo funcionário
    void cadastrarFuncionario(std::string nome, std::string senha, Cargos cargoFuncionario);

    /// @brief Edita um funcionário existente
    /// @param idFuncionario ID de um funcionário existente
    /// @return Retorna de a operação foi concuída
    bool editarFuncionario(unsigned long int idFuncionario);

    /// @brief Demite um funcionário existente
    /// @param idFuncionario ID de um funcionário existente
    /// @return Retorna se a operação foi concluída
    bool demitirFuncionario(unsigned long int idFuncionario);

    /// @brief Mostra os funcionários cadastrados
    void mostrarFuncionarios(void);

    /// @brief Realiza o login de um funcionário existente
    /// @param id ID de um funcionário existente
    /// @param senha Senha de um funcionário existente
    /// @return Retorna se o login foi realizado
    Cargos realizarLogin(long unsigned int id, std::string senha);

    /// @brief Cria uma nova sala
    /// @param nome Nome da sala a ser criada
    /// @param colunas Número de colunas da sala a ser criada
    /// @param linhas Número de linhas da sala a ser criada
    /// @param valorIngresso Valor dos ingressos da sala a ser criada
    /// @return Retorna se a operação foi concluída
    bool adicionarSala(std::string nome, unsigned short int colunas, unsigned short int linhas, float valorIngresso);

    /// @brief Edita as informações de uma sala existente
    /// @param idSala ID de uma sala existente
    /// @return Retorna se a operação foi concluída
    bool editarSala(unsigned long int idSala);

    /// @brief Mostra as salas existentes
    void mostrarSalas(void);

    /// @brief Mostra as salas ativas
    void mostrarSalasAtivas(void);

    /// @brief Habilita a venda dos ingressos de uma sala desabilitada
    /// @param idSala ID da sala a ser habilitada
    void habilitarSala(unsigned long int idSala);

    /// @brief Emite o relatório mensal de vendas
    void relatorioMensal(void);
    //organizador

    /// @brief Cria um novo filme
    /// @param duracaoM Duração do novo filme
    /// @param titulo Título do novo filme
    /// @param classificacao Classificação indicativa do novo filme
    /// @param genero Gênero do novo filme
    void adicionarFilme(int duracaoM, std::string titulo, CLASSIFICACAO classificacao, std::string genero);

    /// @brief Remove um filme existente da exibição em cartaz
    /// @param idFilme ID do filme existente
    /// @return Retorna se a operação foi concluída
    bool removerFilmeCartaz(unsigned long int idFilme);

    /// @brief Edita um filme existente
    /// @param idFilme ID do filme existente
    /// @return Retorna se a operação foi concluída
    bool editarFilme(unsigned long int idFilme);

    /// @brief Exibe os filme em exibição no cartaz
    void exibirFilmesEmCartaz(void);

    /// @brief Exibe todos os filmes cadastrados
    void exibirFilmes(void);

    /// @brief Cria uma nova sessão de um filme em uma determinada sala
    /// @param idSala ID da sala existente
    /// @param idFilme ID do filme existente
    /// @param horario Horário da sessão
    /// @return Retorna se a operação foi concluída
    bool criarSessao(unsigned long int idSala, unsigned long int idFilme, tm horario);

    /// @brief Troca a sessão de uma sala
    /// @param idSala ID da sala existente
    /// @param idSessao ID da sessão existente
    /// @return Retorna se a operação foi concluída
    bool trocarSalaSessao(unsigned long int idSala, unsigned long int idSessao);

    /// @brief Exibe as sessões cadastradas
    void exibirSessoes(void);

    /// @brief Exibe as sessões ativas
    void exibirSessoesAtivas(void);
    //caixa

    /// @brief Adiciona um novo cliente
    /// @param nome Nome do cliente a ser adicionado
    /// @param email E-mail do cliente a ser adicionado
    /// @param idade Idade do cliente a ser adicionado
    /// @param cpf CPF do cliente a ser adicionado
    void adicionarCliente(std::string nome, std::string email, unsigned short int idade, std::string cpf);

    /// @brief Exibe as sessões dos filmes existentes
    void exibirSessoesFilmes(void);

    /// @brief Método para fazer a venda de um ingresso
    /// @param idFuncionario ID do funcionário responsável pela venda
    /// @param idSessao ID da sessão a ser vendida
    /// @param nome Nome do cliente comprador
    /// @param cpf CPF do cliente comprador
    void venderIngressos(unsigned long int idFuncionario, unsigned long int idSessao, std::string nome, std::string cpf);
};

/// @brief Função para validar um CPF
/// @param cpf CPF inserido a ser validado
void validarCPF(std::string* cpf);

/// @brief Função para validar um ID
/// @param id ID inserido a ser validado
void validarId(std::string* id);

#endif