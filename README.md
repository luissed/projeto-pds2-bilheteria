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
### 1. Início do Programa

1. Inicialmente, o programa vai solicitar um usuário administrador. Você deve cadastrar atribuindo um NOME para o gerente (sem espaços).
2. Logo em seguida, deverá ser atribuída uma senha para o gerente.
3. Feito isso, o funcionário cadastrado terá ID 1, o qual deve ser utilizado para fazer os logins a partir de então.

### 2. Login

1. Para fazer o login, deve colocar o ID do funcionário. Inicialmente, há somente um funcionário: o GERENTE, com ID 1.
2. Então digite 1 no ID e coloque a senha escolhida para o funcionário GERENTE.
3. O menu do gerente será aberto.

### 3. Configurações iniciais (GERENTE)
4. Inicialmente não haverá nenhum funcionário cadastrado no sistema, então é necessário fazer o cadastro na opção "a".
5. Deve-se colocar então o nome do novo funcionário, sua senha e um cargo, que pode ser GERENTE, ORGANIZADOR ou CAIXA. ANOTE O ID DO FUNCIONÁRIO CRIADO!!!
6. Feito isso, deve-se cadastrar as salas do cinema, por meio da opção "e".
7. Insira então um número da sala que é usado para identificação (Como 300A, 32B, entre outros).
8. Coloque o número de colunas da sala.
9. Coloque o número de linhas da sala.
10. Coloque o valor do ingresso da sala (deve ser um número inteiro). ANOTE O ID DA SALA CRIADA!!!!
11. Feito isso, pode acessar a opção "f" e vizualizar todas as salas disponíveis.
12. Também é possível acessar o botão "d" e vizualizar todos os funcionários disponíveis.
13. Agora, é necessário criar as sessões e os filmes, então dê logout ("opção "l") e faça login em um funcionário ORGANIZADOR.

### 4. Configurações iniciais (ORGANIZADOR)
1. No menu de ORGANIZADOR, selecione a opção "a" para cadastrar um filme.
2. Insira o nome do filme.
3. Insira a duração do filme em minutos e em inteiro.
4. Insira o gênero do filme.
5. Insira uma classificação válida nas normas brasileiras (10, 12, 14, 16, 18).
6. O filme cadastrado pode ser vizualizado na opção "d".
7. Anote o ID do filme!!!
8. Agora é necessário cadastrar uma sessão. Então aperte a opção "f".
9. Lembra quando você anotou o ID da sala? Insira ele agora.
10. Faça o mesmo com o ID do filme.
11. Insira o ano, mês, data, hora e minuto da sessão.
12. Após cadastrada a sessão, você pode vizualizar na opção "i".
13. Anote o ID da sessão!!!!

### 5. Venda de ingressos
1. Faça login em um usuário de função CAIXA.
2. A partir de então, as vendas podem começar a serem feitas.
3. Para realizar uma venda é necessário que o cliente esteja cadastrado na opção "a".
4. Insira o primeiro nome do cliente.
5. Insira o e-mail do cliente.
6. Insira a idade do cliente.
7. Insira o CPF do cliente (somente números).
8. Na opção "b" é possível vizualizar as sessões disponíveis.
9. Para realizar uma venda, selecione a opção "c".
10. Insira o primeiro nome do cliente.
11. Insira o CPF do cliente.
12. Insira o ID da sessão desejada.
13. Insira a quantidade inteira de ingressos desejada.
14. Selecione a forma de pagamento.
15. Insira se o pagamento foi concluído.
16. Insira a linha desejada.
17. Insira a coluna desejada.
18. A venda foi realizada!

### 6. Vizualizar salas e reservas
As salas e poltronas reservadas no geral podem ser vizualizadas na opção "h" de um usuário ORGANIZADOR.

### 7. Recibo
O recibo das operações estão na pasta "recibos".

### 8. Relatório mensal
O relatório mensal somente é atualizado mensalmente!

# Contato
Dúvidas podem ser retiradas por meio dos e-mails:
luised@ufmg.br - Luis Eduardo
jpcopelli@ufmg.br - João Copelli
jrfn@ufmg.br - José Roberto
sabatini@ufmg.br - Vitor Samuel

# Banco de dados
Não conseguimos implementar um banco de dados, então o programa deve ser contínuo!
