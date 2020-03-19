#include "../include/WordFrequencyApplication.hpp"

EventManager *WordFrequencyApplication::em;

WordFrequencyApplication::WordFrequencyApplication(EventManager *em){

    this->em = em;
    this->em->subscribe("run",this->run);
    this->em->subscribe("eof",this->stop);


}


void WordFrequencyApplication::run(event ev){

    char** argv = get<char**>(ev.second);

    em->publish(event("load_input",argv[1]));
    em->publish(event("load_stop_word",argv[2]));
    em->publish(event("start",argv[3]));

}


void WordFrequencyApplication::stop(event ev){

    int limit = get<int>(ev.second);
    em->publish(event("print",limit));
    

}