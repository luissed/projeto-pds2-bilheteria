#include "servico.hpp"

void validarCPF(std::string* cpf){
    bool valido;
    do{
        valido=true;
        std::cin>>*cpf;
        if(cpf->size()==11){
            unsigned int soma1=0;
            for(short int i=8;i>=0;--i){
                soma1+=(cpf->at(i)-48)*(10-i);
            }
            if(soma1%11==0||soma1&11==1){
                if((cpf->at(9)-48)!=0){
                    valido=false;
                }
            }
            else{
                if((cpf->at(9)-48)!=(11-soma1%11)){
                    valido=false;
                }
            }
            unsigned int soma2=0;
            for(short int i=9;i>=0;--i){
                soma2+=(cpf->at(i)-48)*(11-i);
            }
            if(soma2%11==0||soma2&11==1){
                if((cpf->at(10)-48)!=0){
                    valido=false;
                }
            }
            else{
                if((cpf->at(10)-48)!=(11-soma2%11)){
                    valido=false;
                }
            }
        }
        else{
            valido=false;
        }
        if(!valido){
            std::cout<<"CPF INVALIDO"<<std::endl;
        }
    }while(!valido);
}

void Servico::cadastrarFuncionario(std::string nome, std::string senha, Cargos cargoFuncionario){
    this->_Funcionarios.insert(std::make_pair(this->_idUsuario, new Funcionario(this->_idUsuario, nome, senha, cargoFuncionario)));
    this->_Funcionarios.at(this->_idUsuario)->exibirFuncionario();        
    std::cout<<"FUNCIONARIO CADASTRADO COM SUCESSO!"<<std::endl;
    this->_idUsuario++;
}

bool Servico::editarFuncionario(unsigned long int idFuncionario){
    if(this->_Funcionarios.count(idFuncionario)==1){
        this->_Funcionarios.at(this->_idUsuario)->exibirFuncionario();
        unsigned short int resp;
        do{
            std::cout<<"QUAIS DADOS DESEJA ALTERAR?"<<std::endl;
            std::cout<<"1. NOME\t4. NOME E SENHA"<<std::endl;
            std::cout<<"2. SENHA\t5. NOME E CARGO"<<std::endl;
            std::cout<<"3. CARGO\t6. SENHA E CARGO"<<std::endl;
            std::cout<<"7. TODOS\t8. CANCELAR"<<std::endl;
            std::cin>>resp;
            if(resp==8){
                std::cout<<"OPERAÇÃO CANCELADA"<<std::endl;
                return false;
            }
            if(resp<1||resp>7){
                std::cout<<"ENTRADA INVALIDA"<<std::endl;
            }
        }while(resp<1||resp>7);
        if(resp==1||resp==4||resp==5||resp==7){
            std::string novoNome;
            std::getline(std::cin, novoNome);
            return this->_Funcionarios.at(idFuncionario)->alterarNome(novoNome);
        }
        if(resp==2||resp==4||resp==6||resp==7){
            std::cout<<"NOVA SENHA";
            std::string novaSenha;
            std::cin>>novaSenha;
            return this->_Funcionarios.at(idFuncionario)->alterarSenha(novaSenha);
        }
        if(resp==3||resp==5||resp==6||resp==7){
            unsigned short int novoCargo;
            std::cout<<"1. CAIXA\t3. GERENTE"<<std::endl;
            std::cout<<"2. ORGANIZADOR\t4. SEM CARGO"<<std::endl;
            std::cin>>novoCargo;
            return this->_Funcionarios.at(idFuncionario)->alterarCargo(novoCargo);
        }
    }
    std::cout<<"ID NÃO ENCONTRADO"<<std::endl;
    return false;
}

bool Servico::demitirFuncionario(unsigned long int idFuncionario){
    if(this->_Funcionarios.count(idFuncionario)==1){
        unsigned short int resp;
        this->_Funcionarios.at(idFuncionario)->exibirFuncionario();
        do{
            std::cout<<"DESEJA DEMITIR ESSE FUNCIONARIO?"<<std::endl;
            std::cout<<"1. CONFIRMAR\t2. CANCELAR"<<std::endl;
            std::cin>>resp;
            if(resp==2){
                std::cout<<"OPERAÇÃO CANCELADA"<<std::endl;
                return false;
            }
            if(resp<1||resp>2){
                std::cout<<"ENTRADA INVALIDA"<<std::endl;
            }
        }while(resp<1||resp>2);
        this->_Funcionarios.erase(idFuncionario);
        std::cout<<"FUNCIONARIO DEMITIDO COM SUCESSO!"<<std::endl;
        return true;
    }
    std::cout<<"ID NÃO ENCONTRADO, INSIRA UM VALIDO"<<std::endl;
    return false;
}

void Servico::mostrarFuncionarios(void){
    std::cout<<std::endl<<"FUNCIONARIOS"<<std::endl;
    std::cout<<"--------------------------"<<std::endl;
    unsigned long int i=0;
    
    for (std::multimap<unsigned long int,Funcionario*>::iterator it=this->_Funcionarios.begin(); it!=this->_Funcionarios.end(); ++it){
        if(it->first!=0){
            std::cout<<"ID: "<<std::setfill('0')<<std::setw(5)<<it->first<<std::endl;
            it->second->exibirFuncionario();
            if(i!=this->_Funcionarios.size()-1)
                std::cout<<"--------------------------"<<std::endl;
            i++;
        }
    }
    std::cout<<"****************************"<<std::endl<<std::endl;
}

Cargos Servico::RealizarLogin(long unsigned int id, std::string senha){
    
    if(this->_Funcionarios.count(id)==1){
        if(senha==this->_Funcionarios.at(id)->getSenha()){
            std::cout<<"BEM VINDO "<<this->_Funcionarios.at(id)->getNome()<<"!"<<std::endl;
            return this->_Funcionarios.at(id)->getCargo();
        }
        else{
            std::cout<<"LOGIN OU SENHA INCORRETOS"<<std::endl;
            return SEM_CARGO;
        }
    }
    std::cout<<"FUNCIONARIO NÃO ENCONTRADO"<<std::endl;
    return SEM_CARGO;
}