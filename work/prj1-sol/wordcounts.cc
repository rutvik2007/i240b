#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<map>

std::string replaceCaps()

int main(int argc, char **argv){
    for(int i=1; i<argc; i++){
        std::ifstream inFile;
        std::string &word;
        inFile.open(argv[i]);
        std::cout<<"Reading from "<<argv[i]<<std::endl;
        while(inFile>>word){
            std::cout<<word<<std::endl<<std::endl;
        }
        inFile.close();
    }
}