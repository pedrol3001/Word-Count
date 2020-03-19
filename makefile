WordCount: main.o StopWordFilter.o InputData.o EventManager.o WordFrequency.o WordFrequencyApplication.o
	g++ -o bin/main obj/main.o obj/StopWordFilter.o obj/InputData.o obj/EventManager.o obj/WordFrequency.o obj/WordFrequencyApplication.o -g -Wall -std=c++17
 
main.o: src/main.cpp 
	g++ -c src/main.cpp -o obj/main.o -g -Wall -std=c++17
 
StopWordFilter.o: src/StopWordFilter.cpp include/StopWordFilter.hpp
	g++ -c src/StopWordFilter.cpp -o obj/StopWordFilter.o -g -Wall -std=c++17
 
InputData.o: src/InputData.cpp include/InputData.hpp
	g++ -c src/InputData.cpp -o obj/InputData.o -g -Wall -std=c++17

EventManager.o: src/EventManager.cpp include/EventManager.hpp
	g++ -c src/EventManager.cpp -o obj/EventManager.o -g -Wall -std=c++17

WordFrequency.o: src/WordFrequency.cpp include/WordFrequency.hpp
	g++ -c src/WordFrequency.cpp -o obj/WordFrequency.o -g -Wall -std=c++17

WordFrequencyApplication.o: src/WordFrequencyApplication.cpp include/WordFrequencyApplication.hpp
	g++ -c src/WordFrequencyApplication.cpp -o obj/WordFrequencyApplication.o -g -Wall -std=c++17


test: UnitTest.o StopWordFilter.o InputData.o EventManager.o WordFrequency.o WordFrequencyApplication.o
	g++ -o test/test.exe obj/UnitTest.o obj/StopWordFilter.o obj/InputData.o obj/EventManager.o obj/WordFrequency.o obj/WordFrequencyApplication.o -lgtest -g -Wall -std=c++17


UnitTest.o: test/UnitTest.cpp
	g++ -c test/UnitTest.cpp -o obj/UnitTest.o -g -Wall -lgtest -std=c++17 -g