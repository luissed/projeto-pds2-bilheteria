#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "compra.hpp"

TEST_CASE("teste compra - criar compra"){
    Sala sala("sala 5", 4,4, 12);
    Filme filme(130, "amanhecer violento", _18, "comedia");
    time_t agora=time(nullptr);
    struct tm* horario=localtime(&agora);
    Sessao sessao(sala, &filme, *horario);
    Cliente cliente("luis", "luis@gmail.com", 18, "1231123301");
    Compra compra;
    CHECK(compra.realizaCompra(&sessao));
    CHECK_FALSE(compra.realizaCompra(&sessao));
    compra.imprimirCompra(cliente, 0);

}