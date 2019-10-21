//programa TesteTelefonica.cpp

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream> 
#include <fstream>

using namespace std;

#define listMovies "movies.csv"
#define movie1 "GUARDIANS OF THE GALAXY.txt"
#define movie2 "STAR WARS.txt"
#define movie3 "OS VINGADORES.txt"

char menu_principal();
char menu_selectFilme();
void listar_movie();
void help();


char filmes[3][50] = {movie1, movie2, movie3};

int main(){
	
	system("chcp 1252");   
    system("color A");     
    system("cls");          
    
    char escolha;
    do {
    	escolha = menu_principal();
    	
		switch (escolha){
			
			case 'L' : 
				menu_selectFilme();
				break;
				
			case 'H' : 
				help();
				break;
			
			
		}
	} while (escolha != 'S');

	system("pause");
	return 0;
}

//--------------------------------------
char menu_principal(){
	char opcao;
		char *nome ;
	
	system("cls"); 
	
	cout << "\n===========Informações de Filmes e Séries==========="
			"\n--------Teste Telefónica versão 1.0------"
			"\n(B) Buscar"
			"\n(L) Listar"
			"\n(H) Help"
			"\n(S) Sair do sistema\n";
			
			do {
			cout << "\r>>";
			opcao = toupper(getche());	
			}
			while(opcao != 'B' && opcao != 'L' && opcao != 'H' && opcao != 'S');
			
				if(opcao == 'B'){
					char findMovie[50];
					system("cls");
					cout << "Digite o nome para buscar: ";
					scanf("%s",findMovie);
						for (int i=0; i<strlen(findMovie); i++){
						findMovie[i] = toupper(findMovie[i]); 
					}
					bool encontrado = false;
				
					for(int i=0; i<3; i++){
						nome = filmes[i];
						
						
				      	if(strstr(nome, findMovie)){
				      		encontrado = true;
				      		break;
				      	}
				      		
					}

				if(encontrado){
					ifstream arquivo(nome);
							  if(arquivo.fail()){
							  	cout << "\nFalha ao abrir o arquivo \n";
							  	system ("pause");
							  	return 0;
							  }
					  	system("cls");
					  	char buffer[500];
				      		while(!arquivo.eof()){	
					  	  arquivo.getline(buffer, 500);
						  cout << buffer << endl;

			  				}
			  				arquivo.close();
						
							system("pause");
							
	
				}
				else{
					cout << "\nFilme não encontrado :( \n";
					system("pause");
					return 0;
				}
			}
			  				
			return opcao;	
		
}

char menu_selectFilme(){
	
	system("cls"); 
	char opcao;	 
	
	listar_movie();
	cout << "\nQual filme deseja escolher?\n\n";
	cout << "\nDigite o numero do Filme \n ";
			
		do {
			cout << "\r>>";
			opcao = toupper(getche());	
		}
		while(opcao != '1' && opcao != '2' && opcao != '3' && opcao != 'S');
		 char buffer[500];
		 
		 ifstream arquivo;
		 
		switch (opcao)	{
			
		   case '1':
			  arquivo.open(movie1);
			  if(arquivo.fail()){
			  	cout << "\nFalha ao abrir o arquivo 1\n";
			  	system ("pause");
			  	return 0;
			  }
			  system("cls");
		      while(!arquivo.eof()){	
			  	  arquivo.getline(buffer, 500);
				  cout << buffer << endl;

			  }
			  arquivo.close();	
			  break;
			  
		   case '2':
			  arquivo.open(movie2);
			  if(arquivo.fail()){
			  	cout << "\nFalha ao abrir o arquivo 2\n";
			  	system ("pause");
			  	return 0;
			  }
			  
			  system("cls");
		      while(!arquivo.eof()){	
			  	  arquivo.getline(buffer, 500);
				  cout << buffer << endl;

			  }
			  arquivo.close();	
			  break;
			  
			case '3':
			  arquivo.open(movie3);
			  if(arquivo.fail()){
			  	cout << "\nFalha ao abrir o arquivo 3\n";
			  	system ("pause");
			  	return 0;
			  }
			  system("cls");
		      while(!arquivo.eof()){	
			  	  arquivo.getline(buffer, 500);
				  cout << buffer << endl;

			  }
			  arquivo.close();	
			  break;
	   }   
	cout << "\n\n";
	system ("pause");
}


void listar_movie(){
	
	ifstream arquivo(listMovies);
	char buffer[500];
	while(!arquivo.eof()){	
	arquivo.getline(buffer, 500);
	cout << buffer << endl;
	}
	arquivo.close();
	cout << "\n\n";

}

void help(){
	system("cls"); 
	char opcao;	
	cout << "\nAplicação Teste Telefónica Versão 1.0 \n" << 
			"Com essa aplicação você pode buscar por nome ou \n" <<
			"listar os filmes cadastrados e obter informações sobre o mesmo.\n\n";
			
	cout << "\n(Listar) Mostra uma lista de filmes disponíveis permitindo a escolha pelo número do filme. \n";
	cout << "\n(Buscar) Permite fazer busca de filme usando o nome ou parte dele. \n\n";
	
	
	system("pause");
	
			
}



