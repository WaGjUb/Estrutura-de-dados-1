BIBNAME = "incidenciabib"
MAINAME = "incidenciamain"

all: bib
	@printf "Compilando o $(MAINAME)... \n"
	@gcc -g $(MAINAME).c $(BIBNAME).o -Wall -Wextra
	@if [ -f ./a.out ]; then echo "Código compilado com sucesso!"; else echo "Erro ao compilar o código"; exit 2; fi
	@printf "removendo arquivos temporarios... "
	@rm $(BIBNAME).o
	@if [ -f $(BIBNAME).o ]; then printf "\nErro ao remover arquivos temporários\n"; exit 3; else printf "OK\n"; fi

bib:
	@printf "Verificando bibliotecas... \n"
	@if [ -f ./$(BIBNAME).c ] && [ -f ./$(BIBNAME).h ];	then echo "$(BIBNAME)... OK"; else echo "A biblioteca $(BIBNAME) não está na pasta"; exit 1; fi 
	@printf "Compilando bibliotecas... "
	@gcc -c -g $(BIBNAME).c -Wall -Wextra
	@if [ -f ./$(BIBNAME).o ]; then printf "OK\nBiblioteca compilada com sucesso!\n"; else printf "Erro ao compilar a biblioteca\n:("; exit 2; fi
