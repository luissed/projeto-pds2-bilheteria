#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "filme.hpp"

TEST_CASE("teste filme - criar filme"){
    Filme filme(130, "amanhecer violento", LIVRE, "COMEDIA" );
    filme.exibirFilme();
    CHECK(filme.getBilheteria()==0);
    filme.atualizarBilheteria(34);
    CHECK(filme.getBilheteria()==34);
    filme.exibirFilme();
}