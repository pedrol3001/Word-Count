#ifndef WordFrequencyApplication_hpp
#define WordFrequencyApplication_hpp



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "EventManager.hpp"

using namespace std;


class WordFrequencyApplication{

    private:

        static EventManager *em;


    public:
    
        WordFrequencyApplication(EventManager *);
        static void run(event);
        static void stop(event);


};

#endif