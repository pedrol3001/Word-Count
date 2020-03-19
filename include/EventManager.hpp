#ifndef EventManager_hpp
#define EventManager_hpp

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <variant>


using namespace std;

typedef variant<int,string,char **> tipo;
typedef pair<string,tipo> event ;

 
class EventManager{

    
    private:
        map<string,vector<void (*)(event)>> subscriptions;

    public:

        void subscribe(string,void(*)(event));

        //template <typename T>
        void publish(event);

};


#endif