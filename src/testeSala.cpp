#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "sala.hpp"

TEST_CASE("teste Sala - criar Sala"){
    Sala sala("sala 4",5,5,112);
    sala.exibirSala();
    CHECK_FALSE(sala.getInativa());
    sala.habilitarSala();
    CHECK(sala.getInativa());
    CHECK(sala.tamanhoSala()==25);
    sala.editarSala(14);
    sala.editarSala(4,3);
    sala.exibirSala();
    CHECK(sala.getValorIngresso()==14);
    CHECK(sala.tamanhoSala()==12);
    sala.editarSala(4,6);
    sala.editarSala(13);
    sala.exibirSala();
    CHECK(sala.getValorIngresso()==13);
    CHECK(sala.tamanhoSala()==24);
}