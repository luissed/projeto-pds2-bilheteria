    // using ofstream constructors.
#include <iostream>
#include <cctype>
#include "servico.hpp"

int main() {
    Servico servico;
    char opcao;
    std::string titulo,genero,classificacao;
    std::string nome, senha, cargo, email, cpf;
    unsigned int duracaoM, idade;
    long unsigned int id, idFuncionario, idFilme, idSessao, idSala;
    time_t agora=time(nullptr);
    struct tm* hora_atual;
    struct tm horario;
    std::cout<<"INSIRA OS DADOS DO GERENTE"<<std::endl;
    std::cout<<"NOME: ";
    std::cin>>nome;
    std::cout<<"SENHA: ";
    std::cin>>senha;
    servico.cadastrarFuncionario(nome, senha, GERENTE);
   	while(1){
        hora_atual=localtime(&agora);
        if(hora_atual->tm_mday==1){
            servico.relatorioMensal();
        }
        std::cout<<"ID: ";
        std::cin>>id;
        std::cout<<"SENHA: ";
        std::cin>>senha;
        switch(servico.realizarLogin(id, senha)){
            case GERENTE:
            do{
                std::cin.ignore();
                std::cout << "Pressione Enter para continuar...";
                std::cin.get();
                system("clear");
                std::cout<<"MENU GERENTE"<<std::endl;
                std::cout<<"a. cadastro funcionario\tb. editar funcionario\tc. demitir funcionario"<<std::endl;
                std::cout<<"d. mostrar funcionario\te. cadastrar sala \tf. mostrar todas salas"<<std::endl;
                std::cout<<"g. mostrar salas ativas\th. (des)habilitar sala\ti. editar sala"<<std::endl;
                std::cout<<"l. logout"<<std::endl;
                std::cin>>opcao;
                switch (toupper(opcao)) {
                case 'A':
                    std::cout<<"INSIRA OS DADOS DO FUNCIONARIO"<<std::endl;
                    std::cout<<"NOME: ";
                    std::cin>>nome;
                    std::cout<<"SENHA: ";
                    std::cin>>senha;
                    std::cout<<"CARGO: ";
                    std::cin>>cargo;
                    switch (toupper(cargo[0])) {
                    case 'G':
                        servico.cadastrarFuncionario(nome, senha, GERENTE);
                    break;
                    case 'O':
                        servico.cadastrarFuncionario(nome, senha, ORGANIZADOR);
                    break;
                    case 'C':
                        servico.cadastrarFuncionario(nome, senha, CAIXA);
                    break;
                    default:
                        std::cout << "Cargo inválido." << std::endl;
                        servico.cadastrarFuncionario(nome, senha, SEM_CARGO);
                    break;
                    }
                break;
                case 'B':
                    std::cout<<"INSIRA O ID DO FUNCIONARIO"<<std::endl;
                    std::cout<<"ID: ";
                    std::cin>>idFuncionario;
                    servico.editarFuncionario(idFuncionario);
                break;
                case 'C':
                    std::cout<<"INSIRA O ID DO FUNCIONARIO"<<std::endl;
                    std::cout<<"ID: ";
                    std::cin>>idFuncionario;
                    servico.demitirFuncionario(idFuncionario);
                break;
                case 'D':
                    servico.mostrarFuncionarios();
                break;
                case 'E':
                    unsigned short int colunas, linhas, valorIngresso;
                    std::cout<<"INSIRA OS DADOS DA SALA"<<std::endl;
                    std::cout<<"NOME: ";
                    std::cin>>nome;
                    std::cout<<"COLUNAS: ";
                    std::cin>>colunas;
                    std::cout<<"LINHAS: ";
                    std::cin>>linhas;
                    std::cout<<"VALOR INGRESSO: ";
                    std::cin>>valorIngresso;
                    servico.adicionarSala(nome, colunas, linhas, valorIngresso);
                break;
                case 'F':
                    servico.mostrarSalas();
                break;
                case 'G':
                    servico.mostrarSalasAtivas();
                break;
                case 'H':
                    std::cout<<"INSIRA O ID DA SALA"<<std::endl;
                    std::cout<<"ID: ";
                    std::cin>>idSala;
                    servico.habilitarSala(idSala);
                break;
                case 'I':
                    std::cout<<"INSIRA O ID DA SALA"<<std::endl;
                    std::cout<<"ID: ";
                    std::cin>>idSala;
                    servico.editarSala(idSala);
                break;
                case 'L':
                    std::cout << "LOGOUT" << std::endl;
                break;
                default:
                    std::cout << "OPCAO INVALIDA" << std::endl;
                }
            }
    return 0;
}