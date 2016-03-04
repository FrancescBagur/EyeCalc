#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>

using namespace std;

int main (int argc, char *argv[]){
	//Miro que m'hagin pasat un argument que es la imatge necessaria per fer funcionar el autotrace
	if(argc!=2) {
		//Si no l'han passat faig el print i surto del programa.
		printf("Falta el parametre imatge.\n"); 
		exit(1);
	}
	//Si l'han passat executo l'autotrace amb el parametre imatge que m'han passat i envio el resultat a un fitxer de sortida
	std::string file=argv[1];
	system("./autotrace -centerline -color-count 2 " + file + " > fitxerSortida.txt");
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

