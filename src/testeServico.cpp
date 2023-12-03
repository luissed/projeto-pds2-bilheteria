#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "servico.hpp"

TEST_CASE("teste sessao - adicionar funcionario"){
    Servico servico;
    servico.cadastrarFuncionario("luis", "123456",GERENTE);
    servico.cadastrarFuncionario("igor", "123456",ORGANIZADOR);
    servico.cadastrarFuncionario("ricardo henrique", "123456",CAIXA);
    servico.mostrarFuncionarios();
    CHECK(servico.editarFuncionario(2));
    CHECK_FALSE(servico.editarFuncionario(1));
    servico.mostrarFuncionarios();
    CHECK(servico.demitirFuncionario(2));    
}

TEST_CASE("teste sessao - adicionar filme"){
    Servico servico;
    servico.adicionarSala("sala 1",4,4,15);
    servico.adicionarSala("sala 2",5,6, 20);
    servico.mostrarSalasAtivas();
    servico.adicionarFilme(140, "amanhecer violento", _18, "comedia");
    servico.adicionarFilme(60, "amanhecer alegre", LIVRE, "comedia");
    servico.adicionarFilme(80, "amanhecer tardio", _14, "comedia");
    servico.exibirFilmesEmCartaz();
    CHECK(servico.removerFilmeCartaz(1));
    servico.exibirFilmesEmCartaz();
    servico.exibirFilmes();
    CHECK(servico.removerFilmeCartaz(1));
    servico.editarFilme(1);
    struct tm horario;
    horario.tm_year=2023-1900;
    horario.tm_mon=12;
    horario.tm_mday=15;
    horario.tm_hour=21;
    horario.tm_min=15;
    servico.exibirFilmes();
    CHECK(servico.criarSessao(1,3,horario));
    CHECK(servico.criarSessao(2,3,horario));
    horario.tm_mday=14;
    CHECK(servico.criarSessao(2,2,horario));
    servico.exibirSessoes();
    CHECK_FALSE(servico.trocarSalaSessao(2,1));
    CHECK(servico.removerFilmeCartaz(1));
    servico.exibirSessoesAtivas();
}

TEST_CASE("teste sessao - realizar venda"){
    Servico servico;
    servico.cadastrarFuncionario("luis", "123456",GERENTE);
    servico.cadastrarFuncionario("igor", "123456",ORGANIZADOR);
    servico.cadastrarFuncionario("ricardo henrique", "123456",CAIXA);
    servico.adicionarSala("sala 1",4,4,15);
    servico.adicionarSala("sala 2",5,6, 20);
    servico.adicionarFilme(140, "amanhecer violento", _18, "comedia");
    servico.adicionarFilme(60, "amanhecer alegre", LIVRE, "comedia");
    servico.adicionarFilme(80, "amanhecer tardio", _14, "comedia");
    struct tm horario;
    horario.tm_year=2023-1900;
    horario.tm_mon=11;
    horario.tm_mday=15;
    horario.tm_hour=21;
    horario.tm_min=15;
    CHECK(servico.criarSessao(2,3,horario));
    CHECK(servico.criarSessao(1,3,horario));
    horario.tm_mon=11;
    horario.tm_mday=14;
    horario.tm_hour=21;
    horario.tm_min=15;
    CHECK(servico.criarSessao(2,2,horario));
    servico.venderIngressos(3, 2, "antonio", "120409823-92");
    servico.exibirSessoesAtivas();
    servico.relatorioMensal();
}

void validarCPF(std::string* cpf);