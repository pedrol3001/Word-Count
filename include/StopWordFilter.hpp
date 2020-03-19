#ifndef StopWordFilter_hpp
#define StopWordFilter_hpp

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

#include "EventManager.hpp"

using namespace std;

 
class StopWordFilter{
    
    
    private:

        static EventManager *em;
        static vector<string> stop_words;

    public:

        StopWordFilter(EventManager *);

        static void load(event);
        static void is_stop_word(event);



};

#endif