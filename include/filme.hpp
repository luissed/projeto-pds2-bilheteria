#ifndef FILME_HPP
#define FILME_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>

enum CLASSIFICACAO
{
    LIVRE=0,
    _12=12,
    _14=14,
    _16=16,
    _18=18
};

class Filme{
    private:
    tm _duracao;
    std::string _titulo;
    CLASSIFICACAO _classificacao;
    std::string _genero;
    float _bilheteria;
    public:
    Filme (int duracaoM, std::string titulo, CLASSIFICACAO classificacao, std::string genero);
    void atualizarBilheteria(double bilheteria);
    tm getDuracao(void);
    std::string getTitulo(void);
    CLASSIFICACAO getClassificacao(void);
    std::string getGenero(void);
    float getBilheteria(void);
    void exibirFilme(void);
};

#endif