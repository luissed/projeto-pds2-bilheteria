#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "sessao.hpp"

TEST_CASE("teste sessao - criar sessao"){
    Sala sala("sala 5", 4,4, 12);
    Filme filme(130, "amanhecer violento", _18, "comedia");
    std::vector<unsigned short int> coluna({1,2,2});
    std::vector<unsigned short int> linha({4,2,3});
    time_t agora=time(nullptr);
    struct tm* horario=localtime(&agora);
    Sessao sessao(&sala, &filme, *horario);
    sessao.exibirSessao();
    CHECK(sessao.venderIngressos(coluna, linha));
    sessao.exibirSessao();
    CHECK_FALSE(sessao.venderIngressos(coluna, linha));
    sessao.exibirSessao();
}