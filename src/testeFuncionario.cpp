#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "funcionario.hpp"

TEST_CASE("teste funcionario - criar funcionario"){
    Funcionario funcionario(0, "LUIS", "123456", CAIXA);
    funcionario.exibirFuncionario();
    CHECK(funcionario.realizarLogin(0,"123456"));
    CHECK(funcionario.alterarNome("RICARDO"));
    CHECK(funcionario.alterarSenha("654321"));
    CHECK(funcionario.alterarCargo(GERENTE));
    funcionario.exibirFuncionario();
    CHECK_FALSE(funcionario.realizarLogin(0,"123456"));
}