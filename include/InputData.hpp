#ifndef InputData_h
#define InputData_h

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>


#include "EventManager.hpp"

using namespace std;

class InputData{   

    private:

        static EventManager *em;
        static vector<string> texto;

    public:

        InputData(EventManager *);

        static void load(event);
        static void produce_words(event);


};

#endif