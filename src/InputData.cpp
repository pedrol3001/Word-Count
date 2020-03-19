#include "../include/InputData.hpp"

vector<string> InputData::texto;
EventManager* InputData::em;

InputData::InputData(EventManager *em){

    this->em = em;
    this->em->subscribe("load_input",this->load);
    this->em->subscribe("start",this->produce_words);

}

void InputData::load(event ev){

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
    stringstream clean_word;
    while (fp >> aux){


        for(char &c: aux)
            c = tolower(c);
        
        for(char c : aux){

            if ((c >= 'a' && c<='z') || (c >= 'A' && c<='Z') || (c >= '0' && c <= '9')){
                
                    clean_word << c; 
                   

                }
            }
        
            //cout << clean_word.str() << endl;
            texto.push_back(clean_word.str());
            clean_word.str("");
    }

    fp.close();

}

void InputData::produce_words(event ev){

    for(string str : texto)
        em->publish(event("word",str));
        
    int limit = stoi(get<string>(ev.second));
    em->publish(event("eof",limit));


}

