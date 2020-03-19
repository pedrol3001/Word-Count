#include "../include/EventManager.hpp"
#include "../include/InputData.hpp"
#include "../include/StopWordFilter.hpp"
#include "../include/WordFrequency.hpp"
#include "../include/WordFrequencyApplication.hpp"

#include <iostream>



using namespace std;

void testeWord(event ev){

    cout << get<string>(ev.second) << endl;

}


void argError(char *argv[]){

    cout << "Argumetos invalidos !" << endl;
    cout << "./main (caminho para o input) (caminho para as stopwords) (quantidade de linhas a serem exibidas)";
   
}

int main(int argc, char *argv[] ){

    if ((argc != 4)){
        argError(argv);
        return 1;
    }

    

    EventManager em;

    InputData input(&em);
    StopWordFilter stop(&em);
    WordFrequency freq(&em);
    WordFrequencyApplication app(&em);

    
    em.publish(event("run",argv));



    return 0;
}