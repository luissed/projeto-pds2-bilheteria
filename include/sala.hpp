#ifndef SALA_HPP
#define SALA_HPP

#define SEM_COR "\e[0m"
#define OCUPADO "\e[0;91m"
#define LIBERADO "\e[0;92m"

#include "filme.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>

class Sala{
    private:
    std::string _nome;
    std::map <unsigned short int, std::map<unsigned short int, bool>> _assentos;
    float _valorIngresso;
    bool _inativa;
    public:
    /// @brief Construtor vazio solicitado pelo compilador
    Sala() : _inativa(false){};

    /// @brief Construtor da classe Sala
    /// @param nome Nome da Sala
    /// @param colunas Número de Colunas da Sala
    /// @param linhas Número de Linhas da Sala
    /// @param valorIngresso Valor dos ingressos da Sala
    Sala(std::string nome, unsigned short int colunas, unsigned short int linhas, float valorIngresso);

    /// @brief Calcula o tamanho da Sala
    /// @return Retorna um inteiro de tamanho da Sala
    unsigned long int tamanhoSala(void);

    /// @brief Passa pelos assentos e define qual está livre ou ocupado
    /// @return Retorna quais assentos estão livres ou ocupados
    unsigned long int assentosOcupados(void);

    /// @brief Edita o valor do ingresso de uma Sala
    /// @param valorIngresso valor do ingresso da Sala
    void editarSala(float valorIngresso);

    /// @brief Edita o tamanho da Sala
    /// @param colunas Número de colunas da Sala
    /// @param linhas Número de colunas da Sala
    void editarSala(unsigned short int colunas, unsigned short int linhas);

    /// @brief Edita o nome da Sala
    /// @param novoNome Novo nome da Sala
    void editarSala(std::string novoNome);

    /// @brief Habilita a venda de ingressos de uma Sala
    void habilitarSala(void);

    /// @brief Método para ocupar o assento de uma determinada cadeira de uma sala
    /// @param coluna Coluna desejada da Sala
    /// @param linha Linha deseja da Sala
    void ocuparAssento(unsigned short int coluna, unsigned short int linha);

    /// @brief Exibe a sala
    void exibirSala(void);

    /// @brief Recebe o nome da Sala
    /// @return Retorna uma string do nome da Sala
    std::string getNome(void);
    
    /// @brief Torna uma sala inativa ou não
    /// @return Retorna se a operação foi concluída
    bool getInativa(void);

    /// @brief Recebe o valor do ingresso da Sala
    /// @return Retorna um float com o valor do ingresso da Sala
    float getValorIngresso(void);

    /// @brief Percorre os assentos para ocupar um assento determinado
    /// @return Retorna os assentos ocupados
    std::map <unsigned short int, std::map<unsigned short int, bool>>* getAssentos(void);

    /// @brief Sobrecarga do operador, passa entre as salas cadastradas
    /// @param outra Objeto da classe Sala
    /// @return Retorna as informações do outro objeto Sala
    Sala& operator=(const Sala &outra);
};

#endif