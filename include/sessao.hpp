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
    Sessao(Sala* salas, Filme* filme, tm horario);
    //~Sessao();
    bool venderIngressos(std::vector<unsigned short int> coluna, std::vector<unsigned short int> linha);
    void alterarSala(Sala* sala);
    void exibirSessao(void);
    Sala getSala(void);
    Filme* getFilme(void);
    tm getHorario(void);
};

#endif