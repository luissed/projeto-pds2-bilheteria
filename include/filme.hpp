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
    bool _emCartaz;
    public:
    Filme ():_emCartaz(true) {};
    Filme (int duracaoM, std::string titulo, CLASSIFICACAO classificacao, std::string genero);
    void atualizarBilheteria(double bilheteria);
    bool alterarTitulo(std::string novoTitulo);
    bool alterarDuracao(unsigned short int novaDuracaoM);
    bool alterarClassificacao(unsigned short int novaClassificacao);
    bool alterarGenero(std::string novoGenero);
    tm getDuracao(void);
    std::string getTitulo(void);
    CLASSIFICACAO getClassificacao(void);
    std::string getGenero(void);
    bool getEmCartaz(void);
    float getBilheteria(void);
    void exibirFilme(void);
    void liberarFilme(void);
    Filme& operator=(const Filme &outra);
};

#endif