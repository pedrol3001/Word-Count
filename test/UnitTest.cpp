#include "gtest/gtest.h"

#include "../include/InputData.hpp"
#include "../include/StopWordFilter.hpp"
#include "../include/WordFrequency.hpp"
#include "../include/EventManager.hpp"
#include "../include/WordFrequencyApplication.hpp"


string globalString;

void word(event ev){

  globalString = get<string>(ev.second);

}

TEST(EventManager,all){
    
    EventManager em;
    em.subscribe("teste",word);
    em.publish(event("teste","teste123"));

    EXPECT_EQ(globalString,"teste123");
    
}

TEST(InputData,all){
    globalString = "";
    EventManager em;
    InputData input(&em);


    em.subscribe("word",word);

    em.publish(event("load_input","test/input_teste.txt"));
    em.publish(event("start","3"));

    EXPECT_EQ(globalString,"teste3");
    
    
}

TEST(StopWordFilter,all){
    globalString = "";
    EventManager em;
    StopWordFilter stop(&em);

    em.subscribe("valid_word",word);

    em.publish(event("load_stop_word","test/stop_word_test.txt"));
    em.publish(event("word","teste1"));

    EXPECT_EQ(globalString,"");

    em.publish(event("word","teste2"));

    EXPECT_EQ(globalString,"teste2");

    
    
}

TEST(WordFrequency,all){
    globalString = "";
    EventManager em;
    WordFrequency freq(&em);

    em.publish(event("valid_word","teste1"));
    em.publish(event("valid_word","teste2"));
    em.publish(event("valid_word","teste2"));
    
    map<string,int> aux = freq.getWordCount();

    EXPECT_EQ(aux["teste1"],1);
    EXPECT_EQ(aux["teste2"],2);

    
    
}



int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}