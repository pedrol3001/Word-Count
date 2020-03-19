#ifndef WordFrequency_hpp
#define WordFrequency_hpp



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "EventManager.hpp"

using namespace std;

 
class WordFrequency{

    private:

        static EventManager *em;
        static map<string,int> word_count;


    public:

        WordFrequency(EventManager *);

        map<string,int> getWordCount();


        static void increment_count(event);

        static void print_freq(event);



};

#endif