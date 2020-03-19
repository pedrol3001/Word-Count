# include "../include/WordFrequency.hpp"


EventManager *WordFrequency::em;
map<string,int> WordFrequency::word_count;

WordFrequency::WordFrequency(EventManager *em){

    this->em = em;
    this->em->subscribe("valid_word",this->increment_count);
    this->em->subscribe("print",this->print_freq);

}

 map<string,int> WordFrequency::getWordCount(){

     return word_count;

}


void WordFrequency::increment_count(event ev){

    string word = get<string>(ev.second);
    if(word_count.find(word) != word_count.end())
        word_count[word] += 1;
    else
        word_count[word] = 1;

}



void WordFrequency::print_freq(event ev){

    std::vector<pair<string,int>> vec;

    std::copy(word_count.begin(),
			word_count.end(),
			std::back_inserter<std::vector<pair<string,int>>>(vec));

    std::sort(vec.begin(), vec.end(),
			[](const pair<string,int>& l, const pair<string,int>& r) {
				//if (l.first != r.first)
				//	return l.first < r.first;

				return l.second > r.second;
	});


    int limit = get<int>(ev.second);

    vector<pair<string,int>> a (vec.begin(), limit < (int)vec.size()? vec.begin() +limit : vec.end());

    //vector<pair<string,int>> a (vec.begin(),vec.begin()+ limit );
    for(pair<string,int> v : a)
        cout << v.first << " - " << v.second << endl;



}