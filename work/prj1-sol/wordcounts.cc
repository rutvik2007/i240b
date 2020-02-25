#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<map>
#include <vector>
#include <algorithm>
typedef std::pair<std::string,int> pair;

bool ifNumberAssign(char number[], int &val)
{
    int i = 0;

    //checking for negative numbers
    if (number[0] == '-')
        return false;
    for (; number[i] != 0; i++)
    {
        //if (number[i] > '9' || number[i] < '0')
        if (!isdigit(number[i]))
            return false;
    }
    val = atoi(number);
    return true;
}
void printError(const char *badVal, const char *arg){
  std::cout<<"Bad integer value \""<<badVal<<"\" for "<<arg<<std::endl;
  exit(0);
}
int main(int argc, char **argv){
    int maxSize = 0;
    int minSize = 0;
    int numWords = 0;
    if(argc<4){ 
      std::cout<<"Insufficient arguments provided"<<std::endl;
      exit(0);
    }
    std::map<std::string, int> wordMap;
    if(ifNumberAssign(argv[1], numWords));
    else printError(argv[1], "MAX_N_OUT");
    if(ifNumberAssign(argv[2], minSize));
    else printError(argv[2], "MIN_WORD_LEN");
    if(ifNumberAssign(argv[3], maxSize));
    else printError(argv[3], "MAX_WORD_LEN");
    if(maxSize<minSize){
      std::cout<<"MIN_WORD_LENGTH "<<minSize<<" is greater than MAX_WORD_LENGTH "<<maxSize<<std::endl;
      exit(0);
    }
    
    for(int i=4; i<argc; i++){
        std::ifstream inFile;
        std::string word;
        inFile.open(argv[i]);
        if(inFile){
          //std::cout<<"Reading from "<<argv[i]<<std::endl;
          while(inFile>>word){
            std::string key;
            for(unsigned int i = 0; i < word.size(); ++i){
              if((word[i] >= 'A' && word[i]<='Z')){ word[i]+=32;}
              if(!(word[i] >= 'a' && word[i]<='z')){ word[i] = '\0'; continue;}
              key+=word[i];
            }
            if((int)key.size()<=maxSize && (int)key.size()>=minSize)
            wordMap[key]++;
          }
          //std::cout<<key<<' '<<key.size()<<std::endl;
        }
        else{
          std::cout<<"Cannot read from"<<argv[i]<<":\n\tNo such file or directory"<<std::endl;
        }
    }
    std::vector<pair> vec;
    std::copy(wordMap.begin(),
	  wordMap.end(),
		std::back_inserter<std::vector<pair>>(vec));

    // sort the vector by increasing order of its pair's second value
    // if second value are equal, order by the pair's first value
    std::sort(vec.begin(), vec.end(),
        [](const pair& l, const pair& r) {
          if (l.second != r.second)
            return l.second > r.second;

          return l.first < r.first;
        });

    // print the vector
    int count = 0;
    for (auto const &pair: vec) {
      if(count<numWords){
      std::cout << pair.first << ": " << pair.second << '\n';
      count++;
    }}

}
