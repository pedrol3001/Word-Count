
#include "../include/StopWordFilter.hpp"


vector<string> StopWordFilter::stop_words;
EventManager* StopWordFilter::em;

StopWordFilter::StopWordFilter(EventManager *em){

    this->em = em;
    this->em->subscribe("load_stop_word",this->load);
    this->em->subscribe("word",this->is_stop_word);

}

void StopWordFilter::load(event ev){

    string filepath = get<string>(ev.second);

    ifstream fp;

    if(string(filepath.end()-4,filepath.end())==".txt")
        fp.open(filepath);   
    else    
        throw(runtime_error("Arquivo nao e .txt"));

    
    if(!fp.is_open()){
        throw(runtime_error("Falha ao abrir arquivo"));
    }

    string aux;
    while (fp >> aux){

        for(char &c: aux)
            c = tolower(c);

        stop_words.push_back(aux);
    }
}

void StopWordFilter::is_stop_word(event ev){

    string word = get<string>(ev.second);

    if(find(stop_words.begin(),stop_words.end(),word) == stop_words.end() && word != "")
        em->publish(event("valid_word",word));


}


