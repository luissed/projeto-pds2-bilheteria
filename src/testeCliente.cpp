#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "cliente.hpp"

TEST_CASE("teste cliente - criar cliente"){
    Cliente cliente("luis", "luis@gmail.com", 18, "1231123301");
    std::cout<<cliente.exibirCliente().str();
}