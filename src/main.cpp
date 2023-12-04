    // using ofstream constructors.
#include <iostream>
#include <cctype>
#include "servico.hpp"

int main() {
    Servico servico;
    char opcao;
    std::string titulo,genero,classificacao,id;
    std::string nome, senha, cargo, email, cpf;
    std::string idFuncionario, idFilme, idSessao, idSala, duracaoM, idade;
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
        validarId(&id);
        std::cout<<"SENHA: ";
        std::cin>>senha;
        switch(servico.realizarLogin(std::stoi(id, NULL, 10), senha)){
            case GERENTE:
            do{
                std::cin.ignore();
                std::cout << "Pressione Enter para continuar...";
                std::cin.get();
                std::cout << "\033[2J\033[H]]";
                std::cout<<"MENU GERENTE"<<std::endl;
                std::cout<<"a. cadastro funcionario\tb. editar funcionario\tc. demitir funcionario"<<std::endl;
                std::cout<<"d. mostrar funcionario\te. cadastrar sala \tf. mostrar todas salas"<<std::endl;
                std::cout<<"g. mostrar salas ativas\th. (des)habilitar sala\ti. editar sala"<<std::endl;
                std::cout<<"l. logout"<<std::endl;
                std::cin>>opcao;
                std::cin.ignore();
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
                    validarId(&idFuncionario);
                    servico.editarFuncionario(std::stoi(idFuncionario, NULL, 10));
                break;
                case 'C':
                    std::cout<<"INSIRA O ID DO FUNCIONARIO"<<std::endl;
                    std::cout<<"ID: ";
                    validarId(&idFuncionario);
                    servico.demitirFuncionario(std::stoi(idFuncionario, NULL, 10));
                break;
                case 'D':
                    servico.mostrarFuncionarios();
                break;
                case 'E':
                    unsigned short int colunas, linhas, valorIngresso;
                    std::cout<<"INSIRA OS DADOS DA SALA"<<std::endl;
                    std::cout<<"NOME: ";
                    getline(std::cin, nome);
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
                    validarId(&idSala);
                    servico.habilitarSala(std::stoi(idSala, NULL, 10));
                break;
                case 'I':
                    std::cout<<"INSIRA O ID DA SALA"<<std::endl;
                    std::cout<<"ID: ";
                    validarId(&idSala);
                    servico.editarSala(std::stoi(idSala, NULL, 10));
                break;
                case 'L':
                    std::cout << "LOGOUT" << std::endl;
                break;
                default:
                    std::cout << "OPCAO INVALIDA" << std::endl;
                }
            }while(opcao!='l'&&opcao!='L');
            break;
            case ORGANIZADOR:
            do{
                std::cin.ignore();
                std::cout << "Pressione Enter para continuar...";
                std::cin.get();
                std::cout << "\033[2J\033[H]]";
                std::cout<<"MENU ORGANIZADOR"<<std::endl;
                std::cout<<"a. cadastro filme\tb. editar filme\tc. retirar filme do cartaz"<<std::endl;
                std::cout<<"d. mostrar filmes em cartaz\te. mostrar todos filmes \tf. criar sessao"<<std::endl;
                std::cout<<"g. trocar sala\th. mostrar sessoes\ti. mostrar sessoes ativas"<<std::endl;
                std::cout<<"j. mostrar salas ativas\tl. logout"<<std::endl;
                std::cin>>opcao;
                std::cin.ignore();
                switch (toupper(opcao)) {
                case 'A':
                    std::cout<<"INSIRA OS DADOS DO FILME"<<std::endl;
                    std::cout<<"TITULO: ";
                    getline(std::cin,titulo);
                    std::cout<<"DURACAO EM MINUTOS: ";
                    validarId(&duracaoM);
                    std::cout<<"GENERO: ";
                    std::cin>>genero;
                    std::cout<<"CLASSIFICACAO: ";
                    std::cin>>classificacao;
                    switch (toupper(classificacao[1])) {
                    case 'I':
                        servico.adicionarFilme(std::stoi(duracaoM, NULL, 10), titulo, LIVRE, genero);
                    break;
                    case '2':
                        servico.adicionarFilme(std::stoi(duracaoM, NULL, 10), titulo, _12, genero);
                    break;
                    case '4':
                        servico.adicionarFilme(std::stoi(duracaoM, NULL, 10), titulo, _14, genero);
                    break;
                    case '6':
                        servico.adicionarFilme(std::stoi(duracaoM, NULL, 10), titulo, _16, genero);
                    break;
                    case '8':
                        servico.adicionarFilme(std::stoi(duracaoM, NULL, 10), titulo, _18, genero);
                    break;
                    default:
                        std::cout << "CLASSIFICACAO INVALIDA." << std::endl;
                        servico.adicionarFilme(std::stoi(duracaoM, NULL, 10), titulo, LIVRE, genero);
                    break;
                    }
                break;
                case 'B':
                    std::cout<<"INSIRA O ID DO FILME"<<std::endl;
                    std::cout<<"ID: ";
                    validarId(&idFilme);
                    servico.editarFilme(std::stoi(idFilme, NULL, 10));
                break;
                case 'C':
                    std::cout<<"INSIRA O ID DO FILME"<<std::endl;
                    std::cout<<"ID: ";
                    validarId(&idFilme);
                    servico.removerFilmeCartaz(std::stoi(idFilme, NULL, 10));
                break;
                case 'D':
                    servico.exibirFilmesEmCartaz();
                break;
                case 'E':
                    servico.exibirFilmes();
                break;
                case 'F':
                    std::cout<<"INSIRA OS ID'S DA SALA E DO FILME "<<std::endl;
                    std::cout<<"ID SALA: ";
                    validarId(&idSala);
                    std::cout<<"ID FILME: ";
                    validarId(&idFilme);
                    std::cout<<"INSIRA O HORARIO "<<std::endl;
                    std::cout<<"ANO(YYYY): ";
                    std::cin>>horario.tm_year;
                    std::cout<<"MES(M): ";
                    std::cin>>horario.tm_mon;
                    std::cout<<"DIA(D): ";
                    std::cin>>horario.tm_mday;
                    std::cout<<"HORA(H): ";
                    std::cin>>horario.tm_hour;
                    std::cout<<"MINUTOS(M): ";
                    std::cin>>horario.tm_min;
                    servico.criarSessao(std::stoi(idSala, NULL, 10), std::stoi(idFilme, NULL, 10), horario);
                break;
                case 'G':
                    std::cout<<"INSIRA OS ID'S DA SALA E DA SESSAO "<<std::endl;
                    std::cout<<"ID SALA: ";
                    validarId(&idSala);
                    std::cout<<"ID SESSAO: ";
                    validarId(&idSessao);
                    servico.trocarSalaSessao(std::stoi(idSala, NULL, 10), std::stoi(idSala, NULL, 10));
                break;
                case 'H':
                    servico.exibirSessoes();
                break;
                case 'I':
                    servico.exibirSessoesAtivas();
                break;
                case 'J':
                    servico.mostrarSalasAtivas();
                break;
                case 'L':
                    std::cout << "LOGOUT" << std::endl;
                break;
                default:
                    std::cout << "OPCAO INVALIDA" << std::endl;
                }    
            }while(opcao!='l'&&opcao!='L');
            break;
            case CAIXA:
            do{
                std::cin.ignore();
                std::cout << "Pressione Enter para continuar...";
                std::cin.get();
                std::cout << "\033[2J\033[H]]";
                std::cout<<"MENU CAIXA"<<std::endl;
                std::cout<<"a. cadastro cliente\tb. exibir sessoes\tc. realizar venda"<<std::endl;
                std::cout<<"l. logout"<<std::endl;
                std::cin>>opcao;
                std::cin.ignore();
                switch (toupper(opcao)) {
                case 'A':
                    std::cout<<"INSIRA OS DADOS DO CLIENTE"<<std::endl;
                    std::cout<<"NOME: ";
                    getline(std::cin,nome);
                    std::cout<<"EMAIL: ";
                    std::cin>>email;
                    std::cout<<"IDADE: ";
                    validarId(&idade);
                    std::cout<<"CPF: ";
                    validarCPF(&cpf);
                    servico.adicionarCliente(nome, email, std::stoi(idade, NULL, 10), cpf);
                break;
                case 'B':
                    servico.exibirSessoesFilmes();
                break;
                case 'C':
                    std::cout<<"INSIRA OS DADOS DO CLIENTE"<<std::endl;
                    std::cout<<"NOME: ";
                    getline(std::cin,nome);
                    std::cout<<"CPF: ";
                    validarCPF(&cpf);
                    std::cout<<"INSIRA O ID DA SESSAO"<<std::endl;
                    std::cout<<"ID SESSAO: ";
                    validarId(&idSessao);
                    servico.venderIngressos(std::stoi(id, NULL, 10), std::stoi(idSala, NULL, 10), nome, cpf);
                break;
                case 'L':
                    std::cout << "LOGOUT" << std::endl;
                break;
                default:
                    std::cout << "OPCAO INVALIDA" << std::endl;
                }  
            }while(opcao!='l'&&opcao!='L');
            break;
        }
        
    }
    return 0;
}