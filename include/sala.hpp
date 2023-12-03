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
    Sala() : _inativa(false){};
    Sala(std::string nome, unsigned short int colunas, unsigned short int linhas, float valorIngresso);
    unsigned long int tamanhoSala(void);
    unsigned long int assentosOcupados(void);
    void editarSala(float valorIngresso);
    void editarSala(unsigned short int colunas, unsigned short int linhas);
    void editarSala(std::string novoNome);
    void habilitarSala(void);
    void ocuparAssento(unsigned short int coluna, unsigned short int linha);
    void exibirSala(void);
    std::string getNome(void);
    bool getInativa(void);
    float getValorIngresso(void);
    std::map <unsigned short int, std::map<unsigned short int, bool>>* getAssentos(void);
    Sala& operator=(const Sala &outra);
};

#endif