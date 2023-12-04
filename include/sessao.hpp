#ifndef SESSAO_HPP
#define SESSAO_HPP

#define OCUPADO "\e[0;91m"
#define LIBERADO "\e[0;92m"

#include "sala.hpp"
#include "filme.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <ctime>

class Sessao{
    private:
    Sala _sala;
    Filme* _filme;
    tm _horario;
    public:
    /// @brief Construtor da classe Sessão
    /// @param salas Salas existente para criar uma sessão
    /// @param filme Filme existente para criar uma sessão
    /// @param horario Horário para criar uma sessão
    Sessao(Sala* salas, Filme* filme, tm horario);
    //~Sessao();

    /// @brief Método para fazer a venda de ingressos baseado na poltrona de uma sala
    /// @param coluna Coluna da sala
    /// @param linha Linha da sala
    /// @return Retorna se a venda da poltrona foi concluída
    bool venderIngressos(std::vector<unsigned short int> coluna, std::vector<unsigned short int> linha);

    /// @brief Altera a sala da sessão
    /// @param sala Ponteiro que aponta para uma nova sala
    void alterarSala(Sala* sala);

    /// @brief Exibe as informações da sessão
    void exibirSessao(void);

    /// @brief Recebe uma sala
    /// @return Retorna um objeto da classe sala
    Sala getSala(void);

    /// @brief Recebe um filme
    /// @return Retorna um objeto da classe filme
    Filme* getFilme(void);

    /// @brief Recebe um horário
    /// @return Retorna um objeto da struct tm
    tm getHorario(void);
};

#endif