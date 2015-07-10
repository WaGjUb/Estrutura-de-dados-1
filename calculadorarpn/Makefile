all: bib
	@printf "Compilando a calculadora... \n"
	@gcc calcrpn.c tokenbib.o pilhadinamica.o -Wall
	@if [ -f ./a.out ]; then echo "Código compilado com sucesso!"; else echo "Erro ao compilar o código"; exit 2; fi
	@printf "removendo arquivos temporarios... "
	@rm tokenbib.o pilhadinamica.o
	@if [ -f tokenbib.o ] && [ -f pilhadinamica.o ]; then printf "\nErro ao remover arquivos temporários\n"; exit 3; else printf "OK\n"; fi

bib:
	@printf "Verificando bibliotecas... \n"
	@if [ -f ./tokenbib.c ] && [ -f ./tokenbib.h ];	then echo "tokenbib... OK"; else echo "A biblioteca tokenbib não está na pasta"; exit 1; fi 
	@if [ -f ./pilhadinamica.c ] && [ -f ./pilhadinamica.h ]; then echo "pilhadinamica... OK"; else echo "A biblioteca pilhadinamica não está na pasta"; exit 1; fi 
	@printf "Compilando bibliotecas... "
	@gcc -c tokenbib.c -Wall
	@gcc -c pilhadinamica.c -Wall
	@if [ -f ./tokenbib.o ] && [ -f ./pilhadinamica.o ]; then printf "OK\nBibliotecas compiladas com sucesso!\n"; else printf "Erro ao compilar as bibliotecas\n:("; exit 2; fi
