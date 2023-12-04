CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -O3 -std=c++11 -I include/

all: build

#vaga:

funcionario:
	@mkdir -p build
	$(CC) $(CFLAGS) -c src/funcionario.cpp -o build/funcionario.o
testeFuncionario: funcionario
	$(CC) $(CFLAGS) src/testeFuncionario.cpp build/funcionario.o -o teste/testeFuncionario
filme:
	$(CC) $(CFLAGS) -c src/filme.cpp -o build/filme.o
testeFilme: filme
	$(CC) $(CFLAGS) src/testeFilme.cpp build/filme.o -o teste/testeFilme
sala:
	$(CC) $(CFLAGS) -c src/sala.cpp -o build/sala.o
testeSala: sala
	$(CC) $(CFLAGS) src/testeSala.cpp build/filme.o build/sala.o -o teste/testeSala
cliente:
	$(CC) $(CFLAGS) -c src/cliente.cpp -o build/cliente.o
testeCliente: cliente
	$(CC) $(CFLAGS) src/testeCliente.cpp build/cliente.o -o teste/testeCliente
sessao:
	$(CC) $(CFLAGS) -c src/sessao.cpp  -o build/sessao.o
testeSessao: sala filme sessao
	$(CC) $(CFLAGS) src/testeSessao.cpp build/sala.o build/filme.o build/sessao.o -o teste/testeSessao
compra:
	$(CC) $(CFLAGS) -c src/compra.cpp -o build/compra.o
testeCompra: sala filme sessao cliente compra
	$(CC) $(CFLAGS) src/testeCompra.cpp build/sala.o build/filme.o build/sessao.o build/cliente.o build/compra.o -o teste/testeCompra
servico:
	$(CC) $(CFLAGS) -c src/servico.cpp -o build/servico.o
testeServico: funcionario sala filme sessao cliente compra servico
	$(CC) $(CFLAGS) src/testeServico.cpp build/funcionario.o build/sala.o build/filme.o build/sessao.o build/cliente.o build/compra.o build/servico.o -o teste/testeServico
# Modifique a funcao main
build: test run
test: testeFuncionario testeFilme testeSala testeCliente testeSessao testeCompra testeServico

run: funcionario filme sala cliente sessao compra servico 
	$(CC) $(CFLAGS) build/funcionario.o build/filme.o build/sala.o build/cliente.o build/sessao.o build/compra.o build/servico.o src/main.cpp -o $(TARGET)
	
#	@clear
clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)