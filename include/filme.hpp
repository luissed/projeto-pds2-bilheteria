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
    /// @brief Construtor vazio solicitado pelo compilador
    Filme ():_emCartaz(true) {};

    /// @brief Construtor da classe Filme
    /// @param duracaoM Duração do Filme
    /// @param titulo Título do Filme
    /// @param classificacao Classificação indicativa do Filme
    /// @param genero Gênero do Filme
    Filme (int duracaoM, std::string titulo, CLASSIFICACAO classificacao, std::string genero);

    /// @brief Atualiza a bilheteria do Filme
    /// @param bilheteria Parâmetro que controla número de ingressos vendidos
    void atualizarBilheteria(double bilheteria);

    /// @brief Altera o título do Filme
    /// @param novoTitulo Título novo do Filme
    /// @return Retorna se a operação foi concluída
    bool alterarTitulo(std::string novoTitulo);

    /// @brief Altera a duração de um Filme
    /// @param novaDuracaoM Nova duração do Filme
    /// @return Retorna se a operação foi concluída
    bool alterarDuracao(unsigned short int novaDuracaoM);

    /// @brief Altera a classificação indicativa de um Filme
    /// @param novaClassificacao Nova classificação indicativa de um Filme
    /// @return Retorna se a operação foi concluída
    bool alterarClassificacao(unsigned short int novaClassificacao);

    /// @brief Altera o gênero de um filme
    /// @param novoGenero Novo gênero de um Filme
    /// @return Retorna se a operação foi concluída
    bool alterarGenero(std::string novoGenero);

    /// @brief Coleta a duração do Filme
    /// @return Retorna a duração do Filme
    tm getDuracao(void);

    /// @brief Coleta o título do Filme
    /// @return Retorna o título do Filme
    std::string getTitulo(void);

    /// @brief Coleta a classificação indicativa do Filme
    /// @return Retorna a classificação indicativa do Filme
    CLASSIFICACAO getClassificacao(void);

    /// @brief Coleta o gênero do Filme
    /// @return Retorna o gênero do Filme
    std::string getGenero(void);

    /// @brief Coleta se um filme está ou não em cartaz
    /// @return Retorna se o filme está ou não em cartaz
    bool getEmCartaz(void);

    /// @brief Coleta a quantidade de bilheteria
    /// @return Retorna a quantidade de bilheteria
    float getBilheteria(void);

    /// @brief Exibe as informações de um determinado filme
    void exibirFilme(void);

    /// @brief Libera um Filme ser exibido em cartaz  
    void liberarFilme(void);

    /// @brief Sobrecarga do operador, passa entre os Filmes cadastrados
    /// @param outra Objeto da classe Filme
    /// @return Retorna as informações do outro objeto Filme
    Filme& operator=(const Filme &outra);
};

#endif