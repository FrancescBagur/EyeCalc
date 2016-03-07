#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

int main (int argc, char *argv[]){
	vector< vector<int> > StrokesMatrix;
	//Miro que m'hagin pasat un argument que es la imatge necessaria per fer funcionar el autotrace
	/*std::string file;
	if(argc!=2) {
		//Si no l'han passat faig el print i surto del programa.
		printf("Falta el parametre imatge.\n"); 
		file="";
		//exit(1);
	}else{
		file=argv[1];
	}*/
	//Si l'han passat executo l'autotrace amb el parametre imatge que m'han passat i envio el resultat a un fitxer de sortida
	/*const char * instruccio = "sh ../../../../autotrace-0.31.1/script.autotrace "; //Això es l'script a executar
	const char * f = file.c_str();//El fitxer que m'an passat
	char script[200];
	strcpy(script, instruccio); 
	if(f != ""){
		strcat(script, f); 
	}
	//Executo l'script!*/
	system("script.autotrace > fitxerSortida.txt");
	//Un cop tenim la sortida de l'autotrace dins el fitxer, es hora d'analitzarlo.
	string linia;
  	ifstream fitxer("fitxerSortida.txt");
  	if(fitxer.is_open()){
  		printf("S'ha obert el fitxer");
  		//Si he pogut obrir el fitxer el vaig analitzant linia a linia.
  		int i=0,j=0,t=0;
	    while (getline (fitxer,linia)){
	    	if(t>=23){
	    		if (linia.find("K") == std::string::npos || linia.find("u") == std::string::npos || linia.find("EOF") == std::string::npos){
	    			//Ignoro les linies que no son de punts.
	    			if(linia.find("S") == std::string::npos){
	    				//Si no hi ha una S significa que son punts
	    				vector <string> nombres;
	    				//printf(linia.c_str());
	    				split(nombres, linia, is_any_of( " " ));
	    				vector <int> numInt;
	    				for(int k=0; k< nombres.size(); k++){
	    					printf(nombres[k].c_str());
	    					if(nombres[k] != "m" && nombres[k] != "l" && nombres[k] != "c"){
	    						//si no es cap lletra es que es un numero, el passo a float per no perdre els desimals
	    						float numFloat = 0;
	    						sscanf(nombres[k].c_str(), "%f", &numFloat); //Passa la cadena a un float
	    						numInt.push_back((int) numFloat); //El passo a integer
	    						StrokesMatrix.push_back(numInt);
	    					}
	    				}
	    				
	    			}else{
	    				//significa que comença una nova stroke
	    				i++;
	    			}
				}
	    	}	
	    	t++;
	    }
	    for(int z=0; z <StrokesMatrix.size(); z++){
	    	for(int w=0; w<StrokesMatrix[z].size(); w++){
	    		printf("%i \n", StrokesMatrix[z][w]);
	    	}	
	    }
    	fitxer.close();
  	}else printf("Imposible obrir el fitxer");
	
	return 0;
}

