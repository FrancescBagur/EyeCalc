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
	vector <int> numInt;
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
	    		if ((linia.find("K") == std::string::npos) && (linia.find("k") == std::string::npos) && (linia.find("U") == std::string::npos) && (linia.find("Trailer") == std::string::npos) && (linia.find("u") == std::string::npos) && (linia.find("EOF") == std::string::npos)){
	    			//Ignoro les linies que no son de punts.
	    			if(linia.find("S") == std::string::npos){
	    				//Si no hi ha una S significa que son punts
	    				vector <string> nombres;
	    				printf("linia:\n");
	    				printf(linia.c_str());
	    				printf("\n");
	    				split(nombres, linia, is_any_of("   "));
	    				for(int k=0; k< nombres.size(); k++){
	    					if(nombres[k] != "m" && nombres[k] != "l" && nombres[k] != "c"){
	    						printf(nombres[k].c_str());
	    						
	    						//si no es cap lletra es que es un numero, el passo a float per no perdre els desimals
	    						if(!nombres[k].compare("") == 0){
	    							printf("-");
		    						float numFloat = 0;
		    						sscanf(nombres[k].c_str(), "%f", &numFloat); //Passa la cadena a un float
		    						numInt.push_back((int) numFloat); //El passo a integer
		    						printf("%i->", (int)numFloat);
		    					}
	    					}
	    				}
	    				
	    				printf("\n");
	    			}else{
	    				//significa que comença una nova stroke
	    				StrokesMatrix.push_back(numInt);
	    				i++;
	    			}
				}
	    	}	
	    	t++;
	    }
	    printf("%i\n",StrokesMatrix.size());
	    for(int z=0; z <StrokesMatrix.size(); z++){
	    	printf("%i\n",StrokesMatrix[z].size()/2);
	    	for(int w=0; w<StrokesMatrix[z].size(); w+=2){
	    		printf("%i %i\n", StrokesMatrix[z][w],StrokesMatrix[z][w+1]);
	    	}	
	    }
    	fitxer.close();
  	}else printf("Imposible obrir el fitxer");
	
	return 0;
}

