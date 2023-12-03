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

Servico::~Servico(){
    for(std::map<long unsigned int, Funcionario*>::iterator it=this->_funcionarios.begin();it!=this->_funcionarios.end();++it){
        delete it->second;
    }
    this->_funcionarios.clear();
    for(std::map<long unsigned int, Filme*>::iterator it=this->_filmes.begin();it!=this->_filmes.end();++it){
        delete it->second;
    }
    this->_filmes.clear();
    for(std::map<long unsigned int, Sessao*>::iterator it=this->_sessoes.begin();it!=this->_sessoes.end();++it){
        delete it->second;
    }
    this->_sessoes.clear();
    for(std::map<long unsigned int, Compra*>::iterator it=this->_compras.begin();it!=this->_compras.end();++it){
        delete it->second;
    }
    this->_compras.clear();
    for(std::map<long unsigned int, Sala*>::iterator it=this->_salas.begin();it!=this->_salas.end();++it){
        delete it->second;
    }
    this->_salas.clear();
    for(std::map<std::string, Cliente*>::iterator it=this->_clientes.begin();it!=this->_clientes.end();++it){
        delete it->second;
    }
    this->_clientes.clear();
}
//gerente
void Servico::cadastrarFuncionario(std::string nome, std::string senha, Cargos cargoFuncionario){
    this->_funcionarios.insert(std::make_pair(this->_idUsuario, new Funcionario(this->_idUsuario, nome, senha, cargoFuncionario)));
    this->_funcionarios.at(this->_idUsuario)->exibirFuncionario();        
    std::cout<<"FUNCIONARIO CADASTRADO COM SUCESSO!"<<std::endl;
    this->_idUsuario++;
}

bool Servico::editarFuncionario(unsigned long int idFuncionario){
    if(this->_funcionarios.find(idFuncionario)!=this->_funcionarios.end()){
        this->_funcionarios.at(idFuncionario)->exibirFuncionario();
        std::string resp;
        do{
            std::cout<<"QUAIS DADOS DESEJA ALTERAR?"<<std::endl;
            std::cout<<"1. NOME"<<"           "<<"4. NOME E SENHA"<<std::endl;
            std::cout<<"2. SENHA\t5. NOME E CARGO"<<std::endl;
            std::cout<<"3. CARGO\t6. SENHA E CARGO"<<std::endl;
            std::cout<<"7. TODOS\t8. CANCELAR"<<std::endl;
            std::cin>>resp;
            if(resp.size()==1&&resp[0]==56){
                std::cout<<"OPERAÇÃO CANCELADA"<<std::endl;
                return false;
            }
            if(resp.size()>1||resp[0]<49||resp[0]>55){
                std::cout<<"ENTRADA INVALIDA"<<std::endl;
            }
        }while(resp.size()>1||resp[0]<49||resp[0]>55);
        std::cin.ignore();

        if(resp[0]==49||resp[0]==52||resp[0]==53||resp[0]==55){
            std::cout<<"NOVO NOME:";
            std::string novoNome;
            std::getline(std::cin, novoNome);
            this->_funcionarios.at(idFuncionario)->alterarNome(novoNome);
        }
        if(resp[0]==50||resp[0]==52||resp[0]==54||resp[0]==55){
            std::cout<<"NOVA SENHA:";
            std::string novaSenha;
            std::cin>>novaSenha;
             this->_funcionarios.at(idFuncionario)->alterarSenha(novaSenha);
        }
        if(resp[0]==51||resp[0]==53||resp[0]==54||resp[0]==55){
            unsigned short int novoCargo;
            std::cout<<"1. CAIXA\t2. ORGANIZADOR"<<std::endl;
            std::cout<<"3. GERENTE"<<std::endl;
            std::cin>>novoCargo;
            this->_funcionarios.at(idFuncionario)->alterarCargo(novoCargo);
        }
        this->_funcionarios.at(idFuncionario)->exibirFuncionario();
        std::cout<<"####################"<<std::endl;
        return true;
    }
    std::cout<<"ID NÃO ENCONTRADO"<<std::endl;
    return false;
}

bool Servico::demitirFuncionario(unsigned long int idFuncionario){
    if(this->_funcionarios.count(idFuncionario)==1){
        std::string resp;
        this->_funcionarios.at(idFuncionario)->exibirFuncionario();
        do{
            std::cout<<"DESEJA DEMITIR ESSE FUNCIONARIO?"<<std::endl;
            std::cout<<"1. CONFIRMAR\t2. CANCELAR"<<std::endl;
            std::cin>>resp;
            if(resp.size()==1&&resp[0]==50){
                std::cout<<"OPERAÇÃO CANCELADA"<<std::endl;
                return false;
            }
            if(resp.size()>1||resp[0]<49||resp[0]>50){
                std::cout<<"ENTRADA INVALIDA"<<std::endl;
            }
        }while(resp.size()>1||resp[0]<49||resp[0]>50);
        this->_funcionarios.erase(idFuncionario);
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
    
    for (std::map<unsigned long int,Funcionario*>::iterator it=this->_funcionarios.begin(); it!=this->_funcionarios.end(); ++it){
        std::cout<<"ID: "<<std::setfill('0')<<std::setw(5)<<it->first<<std::endl;
        it->second->exibirFuncionario();
        if(i!=this->_funcionarios.size()-1)
            std::cout<<"--------------------------"<<std::endl;
        i++;
    }
    std::cout<<"****************************"<<std::endl<<std::endl;
}

Cargos Servico::realizarLogin(long unsigned int id, std::string senha){
    
    if(this->_funcionarios.count(id)==1){
        if(senha==this->_funcionarios.at(id)->getSenha()){
            std::cout<<"BEM VINDO "<<this->_funcionarios.at(id)->getNome()<<"!"<<std::endl;
            return this->_funcionarios.at(id)->getCargo();
        }
        else{
            std::cout<<"LOGIN OU SENHA INCORRETOS"<<std::endl;
            return SEM_CARGO;
        }
    }
    std::cout<<"FUNCIONARIO NÃO ENCONTRADO"<<std::endl;
    return SEM_CARGO;
}

bool Servico::adicionarSala(std::string nome, unsigned short int colunas, unsigned short int linhas, float valorIngresso){
    for(std::map<long unsigned int, Sala*>::iterator it=this->_salas.begin();it!=this->_salas.end();++it){
        if(it->second->getNome()==nome){
            std::cout<<"SALA JÁ EXISTE, INSIRA UM NOME DIFERENTE"<<std::endl;
            return false;
        }
    }
    this->_salas.insert(std::make_pair(this->_idSala,new Sala(nome, colunas, linhas, valorIngresso)));
    _idSala++;
    std::cout<<"SALA ADICIONADA COM SUCESSO"<<std::endl;
    return true;

}

void Servico::mostrarSalas(void){
    std::cout<<"####################"<<std::endl;
    for(std::map<unsigned long int, Sala*>::iterator it=this->_salas.begin();it!=this->_salas.end();++it){
        std::cout<<"-------------------"<<std::endl;
        std::cout<<"ID#"<<it->first<<std::endl;
        it->second->exibirSala();
        std::cout<<"-------------------"<<std::endl;
    }
    std::cout<<"####################"<<std::endl;
}


void Servico::mostrarSalasAtivas(void){
    std::cout<<"####################"<<std::endl;
    for(std::map<unsigned long int, Sala*>::iterator it=this->_salas.begin();it!=this->_salas.end();++it){
        if(!it->second->getInativa()){
            std::cout<<"-------------------"<<std::endl;
            std::cout<<"ID#"<<it->first<<std::endl;
            it->second->exibirSala();
            std::cout<<"-------------------"<<std::endl;
        }
    }
    std::cout<<"####################"<<std::endl;
}

void Servico::habilitarSala(unsigned long int idSala){
    unsigned long int sessoesAfetadas=0;
    time_t agora=time(nullptr);
    struct tm* hora_atual=localtime(&agora);
    if(this->_salas.find(idSala)!=this->_salas.end()){
        this->_salas.at(idSala)->exibirSala();
        for(std::map<long unsigned int, Sessao*>::iterator it=this->_sessoes.begin();it!=this->_sessoes.end();++it){
            if(it->second->getSala().getNome()==this->_salas.at(idSala)->getNome()){
                if(it->second->getSala().assentosOcupados()>0&&it->second->getHorario().tm_mday>=hora_atual->tm_mday&&it->second->getHorario().tm_hour>=hora_atual->tm_hour){
                    sessoesAfetadas++;
                }
            }
        }
        if(sessoesAfetadas>0){
            std::cout<<"ESSE SALA JÁ POSSUI INGRESSOS VENDIDOS"<<std::endl;
        }
        if(this->_salas.at(idSala)->getInativa()){
            std::cout<<"DESEJA ATIVAR ESSA SALA?"<<std::endl;
        }
        else{
            std::cout<<"DESEJA INATIVAR ESSA SALA?"<<std::endl;
        }
        std::cout<<"1.SIM\t2.NAO"<<std::endl;
        std::string resp;
        do{
            std::cin>>resp;
            if(resp.size()>1||resp[0]<49||resp[0]>50){
                std::cout<<"ENTRADA INVALIDA"<<std::endl;
            }
        }while(resp.size()>1||resp[0]<49||resp[0]>50);
        if(resp[0]==49){
            this->_salas.at(idSala)->habilitarSala();
            if(this->_salas.at(idSala)->getInativa()){
                std::cout<<"SALA INATIVADA COM SUCESSO"<<std::endl;
                this->_sessoesCanceladas+=sessoesAfetadas;
                this->_sessoesRealizadas-=sessoesAfetadas;
            }
            else{
                std::cout<<"SALA ATIVADA COM SUCESSO"<<std::endl;
                this->_sessoesCanceladas-=sessoesAfetadas;
                this->_sessoesRealizadas+=sessoesAfetadas;
            }
        }
        else{
            std::cout<<"OPERACAO CANCELADA"<<std::endl;
        }
    }
    else{
        std::cout<<"ID INEXISTENTE"<<std::endl;
    }
}

bool Servico::editarSala(unsigned long int idSala){
    if(this->_salas.find(idSala)!=this->_salas.end()){
        this->_salas.at(idSala)->exibirSala();
        std::string resp;
        do{
            std::cout<<"QUAIS DADOS DESEJA ALTERAR?"<<std::endl;
            std::cout<<"1. NOME"<<"           "<<"4. NOME E TAMANHO"<<std::endl;
            std::cout<<"2. TAMANHO\t5. NOME E VALOR INGRESSO"<<std::endl;
            std::cout<<"3. VALOR INGRESSO\t6. TAMANHO E VALOR INGRESSO"<<std::endl;
            std::cout<<"7. TODOS\t8. CANCELAR"<<std::endl;
            std::cin>>resp;
            if(resp.size()==1&&resp[0]==56){
                std::cout<<"OPERAÇÃO CANCELADA"<<std::endl;
                return false;
            }
            if(resp.size()>1||resp[0]<49||resp[0]>55){
                std::cout<<"ENTRADA INVALIDA"<<std::endl;
            }
        }while(resp.size()>1||resp[0]<49||resp[0]>55);
        std::cin.ignore();

        if(resp[0]==49||resp[0]==52||resp[0]==53||resp[0]==55){
            std::cout<<"NOVO NOME:";
            std::string novoNome;
            std::getline(std::cin, novoNome);
            this->_salas.at(idSala)->editarSala(novoNome);
        }
        if(resp[0]==50||resp[0]==52||resp[0]==54||resp[0]==55){
            unsigned short int coluna, linha;
            std::cout<<"NOVA TAMANHO:"<<std::endl;
            std::cout<<"COLUNA:";
            std::cin>>coluna;
            std::cout<<"LINHA:";
            std::cin>>linha;
            this->_salas.at(idSala)->editarSala(coluna, linha);
        }
        if(resp[0]==51||resp[0]==53||resp[0]==54||resp[0]==55){
            unsigned short int novoValor;
            std::cout<<"NOVO VALOR INGRESSO:";
            std::cin>>novoValor;
            this->_salas.at(idSala)->editarSala(novoValor);
        }
        this->_salas.at(idSala)->exibirSala();
        std::cout<<"####################"<<std::endl;
        return true;
    }
    std::cout<<"ID NÃO ENCONTRADO"<<std::endl;
    return false;
}


void Servico::relatorioMensal(void){
    time_t agora=time(nullptr);
    char aux[80];
    struct tm* hora_atual=localtime(&agora);
    hora_atual->tm_mon--;
    strftime(aux, 80,"%b-%Y", hora_atual);
    std::string mes(aux, 80);    std::ofstream outfile ("./relatorio/"+ mes +".txt",  std::ofstream::out);
    if (outfile.is_open()) {
        unsigned long int ingressosVendidos=0;
        double vendasTotais=0;
        for(std::map<long unsigned int, Funcionario*>::iterator it=this->_funcionarios.begin();it!=this->_funcionarios.end();++it){
            if(it->second->getCargo()==CAIXA){
                outfile<<it->second->getNome()<<std::endl;
                outfile<<"VENDAS: "<<std::fixed<<std::setprecision(2)<<it->second->getVendas()<<std::endl;
                vendasTotais+=it->second->getVendas();
                it->second->resetarVenda();
            }
        }
        for(std::map<long unsigned int, Compra*>::iterator it=this->_compras.begin();it!=this->_compras.end();++it){
            ingressosVendidos+=it->second->getQuantidadeIngressos();
        }
        outfile<<"TOTAL INGRESSOS VENDIDOS:"<<ingressosVendidos<<std::endl;
        outfile<<"VENDAS MENSAIS:"<<vendasTotais<<std::endl;
        outfile<<"SESSOES REALIZADAS:"<<this->_sessoesRealizadas<<std::endl;
        outfile<<"SESSOES CANCELADAS:"<<this->_sessoesCanceladas<<std::endl;
        for(std::map<long unsigned int, Filme*>::iterator it=this->_filmes.begin();it!=this->_filmes.end();++it){
            outfile<<"FILME:"<<it->second->getTitulo()<<std::endl;
            outfile<<"BILHETERIA:"<<it->second->getBilheteria()<<std::endl;
        }
        outfile.close();
    }
    else {
        std::cout<< "Erro ao abrir o arquivo para escrita." << std::endl;
    }
    this->_sessoesRealizadas=0;
    this->_sessoesCanceladas=0;
}


//organizador
void Servico::adicionarFilme(int duracaoM, std::string titulo, CLASSIFICACAO classificacao, std::string genero){
    this->_filmes.insert(std::make_pair(this->_idFilme, new Filme(duracaoM, titulo, classificacao, genero)));
    this->_idFilme++;
}

bool Servico::removerFilmeCartaz(unsigned long int idFilme){
    unsigned long int sessoesAfetadas=0;
    time_t agora=time(nullptr);
    struct tm* hora_atual=localtime(&agora);
    if(this->_filmes.find(idFilme)!=_filmes.end()){
        this->_filmes.at(idFilme)->exibirFilme();
        for(std::map<long unsigned int, Sessao*>::iterator it=this->_sessoes.begin();it!=this->_sessoes.end();++it){
            if(it->second->getFilme()->getTitulo()==this->_filmes.at(idFilme)->getTitulo()){
                if(it->second->getSala().assentosOcupados()>0&&it->second->getHorario().tm_mday>=hora_atual->tm_mday&&it->second->getHorario().tm_hour>=hora_atual->tm_hour){
                    sessoesAfetadas++;
                }
            }
        }
        if(sessoesAfetadas>0){
            std::cout<<"ESSE FILME JÁ POSSUI INGRESSOS VENDIDOS"<<std::endl;
        }
        if(this->_filmes.at(idFilme)->getEmCartaz()){
            std::cout<<"DESEJA RETIRAR ESSE FILME?"<<std::endl;
        }
        else{
            std::cout<<"DESEJA ADICIONAR ESSE FILME?"<<std::endl;
        }
        std::cout<<"1.SIM\t2.NAO"<<std::endl;
        std::string resp;
        do{
            std::cin>>resp;
            std::cin.ignore();
            if(resp.size()>1||resp[0]<49||resp[0]>50){
                std::cout<<"ENTRADA INVALIDA"<<std::endl;
            }
        }while(resp.size()>1||resp[0]<49||resp[0]>50);
        if(resp[0]==49){
            this->_filmes.at(idFilme)->liberarFilme();
            if(this->_filmes.at(idFilme)->getEmCartaz()){
                std::cout<<"FILME RETORNADO COM SUCESSO"<<std::endl;
                this->_sessoesCanceladas-=sessoesAfetadas;
                this->_sessoesRealizadas+=sessoesAfetadas;
            }
            else{
                std::cout<<"FILME RETIRADO COM SUCESSO"<<std::endl;
                this->_sessoesCanceladas+=sessoesAfetadas;
                this->_sessoesRealizadas-=sessoesAfetadas;
            }
            return true;
        }
        else{
            std::cout<<"OPERACAO CANCELADA"<<std::endl;
            return false;
        }
    }
    std::cout<<"ID INEXISTENTE"<<std::endl;
    return false;
}

bool Servico::editarFilme(unsigned long int idFilme){
    if(this->_filmes.find(idFilme)!=_filmes.end()){
        std::string resp;
        do{
            std::cout<<"QUAIS DADOS DESEJA ALTERAR?"<<std::endl;
            std::cout<<"1. TITULO\t5. TITULO E CLASSIFICACAO\t9.CLASSIFICACAO E GENERO"<<std::endl;
            std::cout<<"2. CLASSIFICACAO\t6. TITULO E DURACAO\t10.DURACAO E GENERO"<<std::endl;
            std::cout<<"3. DURACAO\t7. TITULO E GENERO\t11.TUDO"<<std::endl;
            std::cout<<"4. GENERO\t8. CLASSIFICACAO E DURACAO\t12.CANCELAR"<<std::endl;
            std::cin>>resp;
            if(resp[0]==60){
                std::cout<<"OPERAÇÃO CANCELADA"<<std::endl;
                return false;
            }
            if(resp.size()>1||resp[0]<49||resp[0]>60){
                std::cout<<"ENTRADA INVALIDA"<<std::endl;
            }
        }while(resp.size()>1||resp[0]<49||resp[0]>60);
        std::cin.ignore();
        if(resp[0]==49||resp[0]==53||resp[0]==54||resp[0]==55||resp[0]==59){
            std::cout<<"NOVO TITULO:";
            std::string novoTitulo;
            std::getline(std::cin, novoTitulo);
            this->_filmes.at(idFilme)->alterarTitulo(novoTitulo);
        }
        if(resp[0]==50||resp[0]==53||resp[0]==56||resp[0]==57||resp[0]==59){
            std::cout<<"0. LIVRE\t14. 14 ANOS\t18. 18 ANOS"<<std::endl;
            std::cout<<"12. 12 ANOS\t16. 16 ANOS"<<std::endl;
            unsigned short int novaClassificacao;
            std::cin>>novaClassificacao;
            this->_filmes.at(idFilme)->alterarClassificacao(novaClassificacao);
        }
        if(resp[0]==51||resp[0]==54||resp[0]==56||resp[0]==58||resp[0]==59){
            int novaDuracaoM;
            std::cout<<"DURACAO EM MINUTOS:";
            std::cin>>novaDuracaoM;
            this->_filmes.at(idFilme)->alterarDuracao(novaDuracaoM);
        }
        if(resp[0]==52||resp[0]==54||resp[0]==56||resp[0]==58||resp[0]==59){
            std::cout<<"NOVO GENERO:";
            std::string novoGenero;
            std::getline(std::cin, novoGenero);
            this->_filmes.at(idFilme)->alterarTitulo(novoGenero);
        }
        this->_filmes.at(idFilme)->exibirFilme();
        return true;
    }
    std::cout<<"ID INEXISTENTE"<<std::endl;
    return false;
}

void Servico::exibirFilmesEmCartaz(void){
    std::cout<<"####################"<<std::endl;
    for(std::map<long unsigned int, Filme*>::iterator it=this->_filmes.begin();it!=this->_filmes.end();++it){
        if(it->second->getEmCartaz()){
            std::cout<<"---------------------"<<std::endl;
            std::cout<<"ID#"<<it->first<<std::endl;
            it->second->exibirFilme();
        }
    }
    std::cout<<"####################"<<std::endl;
}

void Servico::exibirFilmes(void){
    std::cout<<"####################"<<std::endl;
    for(std::map<long unsigned int, Filme*>::iterator it=this->_filmes.begin();it!=this->_filmes.end();++it){
        std::cout<<"ID#"<<it->first<<std::endl;
        it->second->exibirFilme();
    }
    std::cout<<"####################"<<std::endl;
}

bool Servico::criarSessao(unsigned long int idSala, unsigned long int idFilme, tm horario){
    if(this->_salas.find(idSala)!=this->_salas.end()&&this->_filmes.find(idFilme)!=this->_filmes.end()){
        if(!this->_salas.at(idSala)->getInativa()) {
            if(this->_filmes.at(idFilme)->getEmCartaz()){
                for(std::map<unsigned long int, Sessao*>::iterator it=_sessoes.begin();it!=_sessoes.end();++it){
                    if(it->second->getSala().getNome()==this->_salas.at(idSala)->getNome()){
                        if(it->second->getHorario().tm_mon==horario.tm_mon){
                            if(it->second->getHorario().tm_mday==horario.tm_mday){
                                if(it->second->getHorario().tm_hour+it->second->getFilme()->getDuracao().tm_hour<=horario.tm_hour){
                                    if(it->second->getHorario().tm_min+it->second->getFilme()->getDuracao().tm_min<=horario.tm_min+15){
                                        std::cout<<"SESSAO JÁ AGENDADA NESSE HORARIO"<<std::endl;
                                        return false;
                                    }
                                }
                                else if(horario.tm_hour+this->_filmes.at(idFilme)->getDuracao().tm_hour>=it->second->getHorario().tm_hour){
                                    if(horario.tm_min+_filmes.at(idFilme)->getDuracao().tm_min>=it->second->getHorario().tm_min-15){
                                        std::cout<<"SESSAO JÁ AGENDADA NESSE HORARIO"<<std::endl;
                                        return false;
                                    }
                                }
                            }
                        }
                    }
                }
                this->_sessoes.insert(std::make_pair(this->_idSessao,new Sessao(this->_salas.at(idSala), this->_filmes.at(idFilme), horario)));
                this->_idSessao++;
                this->_sessoesRealizadas++;
                return true;
            }
            std::cout<<"FILME FORA DE CARTAZ"<<std::endl;
            return false;
        }
        std::cout<<"SALA INATIVA"<<std::endl;
        return false;
    }
    std::cout<<"DADOS INCORRETOS"<<std::endl;
    return false;

}

bool Servico::trocarSalaSessao(unsigned long int idSala, unsigned long int idSessao){
    if(this->_salas.find(idSala)!=this->_salas.end()){    
        if(!this->_salas.at(idSala)->getInativa()){    
            for(std::map<unsigned long int, Sessao*>::iterator it=_sessoes.begin();it!=_sessoes.end();++it){
                if(it->second->getSala().getNome()==this->_salas.at(idSala)->getNome()){
                    if(it->second->getHorario().tm_mon==it->second->getHorario().tm_mon){
                        if(it->second->getHorario().tm_mday==it->second->getHorario().tm_mday){
                            if(it->second->getHorario().tm_hour+it->second->getFilme()->getDuracao().tm_hour<=this->_sessoes.at(idSessao)->getHorario().tm_hour){
                                if(it->second->getHorario().tm_min+it->second->getFilme()->getDuracao().tm_min<=this->_sessoes.at(idSessao)->getHorario().tm_min){
                                    std::cout<<"SESSAO JÁ AGENDADA NESSA SALA"<<std::endl;
                                    return false;
                                }
                            }
                            else if(this->_sessoes.at(idSessao)->getHorario().tm_hour+this->_sessoes.at(idSessao)->getFilme()->getDuracao().tm_hour>=it->second->getHorario().tm_hour){
                                if(this->_sessoes.at(idSessao)->getHorario().tm_hour+this->_sessoes.at(idSessao)->getFilme()->getDuracao().tm_hour>=it->second->getHorario().tm_min-15){
                                    std::cout<<"SESSAO JÁ AGENDADA NESSA SALA"<<std::endl;
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
            std::cout<<"SALA TROCADA COM SUCESSO"<<std::endl;
            this->_sessoes.at(idSessao)->alterarSala(this->_salas.at(idSala));
            return true;
        }
    }
    std::cout<<"SALA INATIVA"<<std::endl;
    return false;

}

void Servico::exibirSessoes(void){
    time_t agora=time(nullptr);
    struct tm* hora_atual=localtime(&agora);
    std::cout<<"####################"<<std::endl;
    for(std::map<long unsigned int, Sessao*>::iterator it=this->_sessoes.begin();it!=this->_sessoes.end();++it){
        if(it->second->getHorario().tm_mday>=hora_atual->tm_mday){
            std::cout<<"ID#"<<it->first<<std::endl;
            it->second->exibirSessao();
            std::cout<<"----------------------"<<std::endl;
        }
    }
    std::cout<<"####################"<<std::endl;
}

void Servico::exibirSessoesAtivas(void){
    time_t agora=time(nullptr);
    struct tm* hora_atual=localtime(&agora);
    std::cout<<"####################"<<std::endl;
    for(std::map<long unsigned int, Sessao*>::iterator it=this->_sessoes.begin();it!=this->_sessoes.end();++it){
        if(it->second->getHorario().tm_mday>=hora_atual->tm_mday&&it->second->getFilme()->getEmCartaz()&&!it->second->getSala().getInativa()){
            std::cout<<"ID#"<<it->first<<std::endl;
            it->second->exibirSessao();
            std::cout<<"----------------------"<<std::endl;
        }  
    }
    std::cout<<"####################"<<std::endl;
}

//caixa
void Servico::adicionarCliente(std::string nome, std::string email, unsigned short int idade, std::string cpf){
    this->_clientes.insert(std::make_pair(cpf, new Cliente(nome, email, idade, cpf)));
}

void Servico::exibirSessoesFilmes(void){
    time_t agora=time(nullptr);
    struct tm* hora_atual=localtime(&agora);
    for(std::map<long unsigned int, Filme*>::iterator it=this->_filmes.begin();it!=this->_filmes.end();++it){
        std::cout<<"ID #"<<it->first<<std::endl;
        for(std::map<long unsigned int, Sessao*>::iterator it2=this->_sessoes.begin();it2!=this->_sessoes.end();++it2){
            if(it->second->getTitulo()==it2->second->getFilme()->getTitulo()){
                if(it2->second->getHorario().tm_mday>=hora_atual->tm_mday&&it2->second->getHorario().tm_hour>=hora_atual->tm_hour){
                    std::cout<<it2->first<<".";
                    it2->second->exibirSessao();
                }
            }
        }
    }
}

void Servico::venderIngressos(unsigned long int idFuncionario, unsigned long int idSessao, std::string nome, std::string cpf){
    if(this->_clientes.find(cpf)==this->_clientes.end()){
        std::cout<<"CLIENTE NÃO CADASTRADO, DESEJA CADASTRA-LO?"<<std::endl;
        std::cout<<"1.SIM\t2.NAO"<<std::endl;
        std::string resp;
        do{
            std::cin>>resp;
            if(resp.size()>1||resp[0]<49||resp[0]>50){
                std::cout<<"ENTRADA INVALIDA"<<std::endl;
            }
        }while(resp.size()>1||resp[0]<49||resp[0]>50);
        if(resp[0]==49){
            std::string email;
            unsigned short int idade;
            std::cout<<"EMAIL: ";
            std::cin>>email;
            std::cout<<"IDADE: ";
            std::cin>>idade;
            adicionarCliente(nome, email, idade, cpf);
        }
        else{
            this->_compras.insert(std::make_pair(this->_idCompra, new Compra()));
            this->_funcionarios.at(idFuncionario)->atualizarVenda(this->_compras.at(this->_idCompra)->realizaCompra(this->_sessoes.at(idSessao)));
            this->_compras.at(this->_idCompra)->imprimirCompra(nome, cpf, this->_idCompra);
            this->_idCompra++;
            return ;
        }
    }
    else{
        this->_compras.insert(std::make_pair(this->_idCompra, new Compra()));
        this->_funcionarios.at(idFuncionario)->atualizarVenda(this->_compras.at(this->_idCompra)->realizaCompra(this->_sessoes.at(idSessao)));
        this->_compras.at(this->_idCompra)->imprimirCompra(this->_clientes.at(cpf),this->_idCompra);
        this->_idCompra++;
    }
}