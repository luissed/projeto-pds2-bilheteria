#include "sistema.hpp"
#include "usuario.hpp"
#include "funcionario.hpp"

int main(){
    Cargos cargo_atual;
    Sistema teste;
    teste.cadastrarFuncionario(new Funcionario("arthur","reter", GERENTE));
    teste.cadastrarFuncionario(new Funcionario("ricardo","reter", ORGANIZADOR));
    teste.cadastrarFuncionario(new Funcionario("marcos","reter", CAIXA));
    teste.mostrarFuncionarios();
    do{
        long unsigned int id;
        std::cin>>id;
        std::cout<<std::endl;y
        std::string senha;
        std::cin>>senha;
        std::cout<<std::endl;
        cargo_atual=teste.RealizarLogin(id, senha);
        system("sleep 3");
        system("clear");
    }while(cargo_atual==SEM_CARGO);
    teste.mostrarFuncionarios();
    system("sleep 3");
    system("clear");
    teste.demitirFuncionario(3);
    teste.mudarCargo(2);
    teste.mostrarFuncionarios();
}