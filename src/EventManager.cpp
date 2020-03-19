#include "../include/EventManager.hpp"

using namespace std;

void EventManager::subscribe(string event_type,void(*handler)(event)){

    if(this->subscriptions.find(event_type) != subscriptions.end())
        this->subscriptions[event_type].push_back(handler);
    else   
        this->subscriptions[event_type] = vector<void (*)(event)>(1,handler);
    
}


//template <typename T>
void EventManager::publish(event evento){
    
    string event_type = evento.first;
    if(this->subscriptions.find(event_type) != subscriptions.end())
        for(auto h : subscriptions[event_type])
            h(evento);

}
