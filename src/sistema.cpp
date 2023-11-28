#include "sistema.hpp"

std::map<long unsigned int, Funcionario*> Sistema::_listaFuncionarios={{0,new Funcionario()}}; 

Sistema::Sistema(){
    _listaFuncionarios.insert(std::pair<unsigned long int, Funcionario*>((getId())-1, new Funcionario(GERENTE)));
    //_listaFuncionarios.at(id)->exibirFuncionario();        
    std::cout<<"GERENTE CADASTRADO COM SUCESSO!"<<std::endl;
}

Sistema::Sistema(std::string nome, std::string senha){
        _listaFuncionarios.insert(std::pair<unsigned long int, Funcionario*>((getId())-1, new Funcionario(nome, senha, GERENTE)));
        //_listaFuncionarios.at(id)->exibirFuncionario();        
        std::cout<<"GERENTE CADASTRADO COM SUCESSO!"<<std::endl;
}

void Sistema::cadastrarFuncionario(Funcionario* novoFuncionario){
        _listaFuncionarios.insert(std::pair<unsigned long int, Funcionario*>(getId()-1, novoFuncionario));
        //_listaFuncionarios.at(novoFuncionario->getId())->exibirFuncionario();        
        std::cout<<"FUNCIONARIO CADASTRADO COM SUCESSO!"<<std::endl;
}

void Sistema::demitirFuncionario(unsigned long int idFuncionario){
    if(_listaFuncionarios.count(idFuncionario)==1){
        //_listaFuncionarios.at(idFuncionario)->exibirFuncionario();  
        _listaFuncionarios.erase(idFuncionario);
        std::cout<<"FUNCIONARIO DEMITIDO COM SUCESSO!"<<std::endl;
    }
    else{
        std::cout<<"ID NÃO ENCONTRADO, INSIRA UM VALIDO"<<std::endl;
    }
}

void Sistema::mudarNome(unsigned long int idFuncionario){
    if(_listaFuncionarios.count(idFuncionario)==1){
        std::string novoNome;
        std::cout<<"INSIRA O NOVO NOME"<<std::endl;
        getline(std::cin, novoNome);
        _listaFuncionarios.at(idFuncionario)->alterarNome(novoNome);
        std::cout<<"NOME ALTERADO COM SUCESSO!"<<std::endl;
    }
    else{
        std::cout<<"ID NÃO ENCONTRADO, INSIRA UM VALIDO"<<std::endl;
    }
}
void Sistema::mudarSenha(unsigned long int idFuncionario){
    if(_listaFuncionarios.count(idFuncionario)==1){
        std::string novaSenha;
        std::cout<<"INSIRA A NOVE SENHA"<<std::endl;
        getline(std::cin, novaSenha);
        _listaFuncionarios.at(idFuncionario)->alterarSenha(novaSenha);
        std::cout<<"SENHA ALTERADA COM SUCESSO!"<<std::endl;
    }
    else{
        std::cout<<"ID NÃO ENCONTRADO, INSIRA UM VALIDO"<<std::endl;
    }
}

void Sistema::mudarCargo(unsigned long int idFuncionario){
    if(_listaFuncionarios.count(idFuncionario)==1){
        int novoCargo;
        std::cout<<"ESCOLHA O NOVO CARGO"<<std::endl;
        std::cout<<"0.RETORNAR"<<std::endl;
        if(_listaFuncionarios.at(idFuncionario)->getCargo()!=CAIXA){
            std::cout<<"1.CAIXA"<<std::endl;
        }
        if(_listaFuncionarios.at(idFuncionario)->getCargo()!=ORGANIZADOR){
            std::cout<<"2.ORGANIZADOR"<<std::endl;
        }
        if(_listaFuncionarios.at(idFuncionario)->getCargo()!=GERENTE){
            std::cout<<"3.GERENTE"<<std::endl;
        }
        std::cin>>novoCargo;
        if((novoCargo-1)!=_listaFuncionarios.at(idFuncionario)->getCargo()){
            switch(novoCargo){
                case 0:
                    return ;
                case 1:
                    _listaFuncionarios.at(idFuncionario)->alterarCargo(CAIXA);
                    std::cout<<"CARGO ATUALIZADO COM SUCESSO"<<std::endl;
                    break;
                case 2:
                    _listaFuncionarios.at(idFuncionario)->alterarCargo(ORGANIZADOR);
                    std::cout<<"CARGO ATUALIZADO COM SUCESSO"<<std::endl;
                    break;
                case 3:
                    _listaFuncionarios.at(idFuncionario)->alterarCargo(GERENTE);
                    std::cout<<"CARGO ATUALIZADO COM SUCESSO"<<std::endl;
                    break;
                default:
                    std::cout<<"CARGO INVALIDO"<<std::endl;
            }
        }
        else{
            std::cout<<"ENTRADA INVALIDA"<<std::endl;
        }
    }
    else{
        std::cout<<"ID NÃO ENCONTRADO, INSIRA UM VALIDO"<<std::endl;
    }
}

void Sistema::mostrarFuncionarios(void){
    std::cout<<std::endl<<"FUNCIONARIOS"<<std::endl;
    std::cout<<"--------------------------"<<std::endl;
    unsigned long int i=0;
    
    for (std::multimap<unsigned long int,Funcionario*>::iterator it=_listaFuncionarios.begin(); it!=_listaFuncionarios.end(); ++it){
        if(it->first!=0){
            std::cout<<"ID: "<<std::setfill('0')<<std::setw(5)<<it->first<<std::endl;
            it->second->exibirFuncionario();
            if(i!=_listaFuncionarios.size()-1)
                std::cout<<"--------------------------"<<std::endl;
            i++;
        }
    }
    std::cout<<"****************************"<<std::endl<<std::endl;
}

Cargos Sistema::RealizarLogin(long unsigned int id, std::string senha){
    
    if(_listaFuncionarios.count(id)==1){
        if(senha==_listaFuncionarios.at(id)->getSenha()){
            //std::cout<<"BEM VINDO "<<_listaFuncionarios.at(id)->getNome()<<"!"<<std::endl;

            _listaFuncionarios.at(id)->exibirFuncionario();
            return _listaFuncionarios.at(id)->getCargo();
        }
        else{
            std::cout<<"LOGIN OU SENHA INCORRETOS"<<std::endl;
            return SEM_CARGO;
        }
    }
    std::cout<<"FUNCIONARIO NÃO ENCONTRADO"<<std::endl;
    return SEM_CARGO;
}