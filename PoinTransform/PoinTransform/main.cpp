#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main (int argc, char *argv[]){
	//Miro que m'hagin pasat un argument que es la imatge necessaria per fer funcionar el autotrace
	std::string file;
	if(argc!=2) {
		//Si no l'han passat faig el print i surto del programa.
		printf("Falta el parametre imatge.\n"); 
		file="";
		//exit(1);
	}else{
		file=argv[1];
	}
	//Si l'han passat executo l'autotrace amb el parametre imatge que m'han passat i envio el resultat a un fitxer de sortida
	const char * instruccio = "sh ../../../../autotrace-0.31.1/script.autotrace "; //Això es l'script a executar
	const char * f = file.c_str();//El fitxer que m'an passat
	char script[200];
	strcpy(script, instruccio); 
	if(f != ""){
		strcat(script, f); 
	}
	//Executo l'script!
	system("sh ../../../../autotrace-0.31.1/script.autotrace");
	//Un cop tenim la sortida de l'autotrace dins el fitxer, es hora d'analitzarlo.
	string linia;
  	ifstream fitxer("fitxerSortida.txt");
  	if(fitxer.is_open()){
  		//Si he pogut obrir el fitxer el vaig analitzant linia a linia.
  		int i=0,j=0;
	    while (getline (fitxer,linia)){
	    	if(i>=23){
	    		if (linia.find("K") != std::string::npos){
	    			//Ignoro les linies que no son de punts.
	    			if(linia.find("u") == std::string::npos || linia.find("S") == std::string::npos){
	    				//Es el principi d'una nova stroke i per tant augmento el contador de la llista
	    				
	    				j++;
	    			}
				}
	    	}	
	      	i++;
	    }
    	fitxer.close();
  	}else printf("Imposible obrir el fitxer");
	
	return 0;
}

