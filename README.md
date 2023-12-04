# projeto-pds2-bilheteria
Projeto para a disciplina de PDS II, onde faremos um sistema de reserva de bilhetes de cinema

## Descrição do Projeto
Este é um sistema simples de bilheteria de cinema implementado em C++. O sistema permite a reserva de ingressos, exibição de filmes e gerenciamento básico de transações.

## Pré-requisitos
- O programa deve ser compilado utilizando o VSCode, com integração ao WSL.

## Como Compilar e Executar
1. Clone o repositório;
2. Vá até o diretório do projeto;
3. Execute o comando para construir o arquivo build:
   ```bash
   make build
4. Execute o comando para construir os arquivos de testes:
   ```bash
   make test
5. Execute o comando para construir os arquivos principais:
   ```bash
   make run
6. Agora, execute os testes um por um utilizando ./teste/testeNome_do_Teste, por exemplo:
   ```bash
   ./teste/testeCliente
   ./teste/testeCompras
7. Após executados os teste, podemos rodar o arquivo principal:
   ```bash
   ./main.out

##  Funcionamento do Programa
### Início do Programa

1. Inicialmente, o programa vai solicitar um usuário administrador. Você deve cadastrar atribuindo um número de CPF (somente números) para o funcionário;
2. Logo em seguida, deverá ser atribuída uma senha numérica para o funcionário;
3. Feito isso, o funcionário cadastrado terá ID 1, o qual deve ser utilizado para fazer os logins a partir de então.

### Login

1. 




