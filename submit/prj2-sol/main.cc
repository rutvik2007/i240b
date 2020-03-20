#include<iostream>
#include<fstream>
#include "dlinkseq.hh"
#include "arrayseq.hh"

int main(int argc, char **argv){
    SeqPtr<int> seq = nullptr;
    int startindex;
    if(argc<2){
        std::cout<<"usage: ./nums [-a] INTS_FILE_PATH"<<std::endl;
        exit(0);
    }
    if(argv[1][0]=='-'){
        if(argv[1][1]=='a'){
            seq = ArraySeq<int>::make();
            startindex = 2;
        }
        else{
            std::cout<<"usage: ./nums [-a] INTS_FILE_PATH"<<std::endl;
            exit(0);
        }        
    }
    else{
        seq = DLinkSeq<int>::make();
        startindex = 1;
    }
    for(int i=startindex; i<argc; i++){
        std::ifstream inFile;
        int num;
        inFile.open(argv[i]);
        if(!inFile){
             std::cout<<"cannot read "<<argv[i]<<": No such file or directory"<<std::endl;
        }
        while(inFile >> num){
            seq->push(num);
        }
        inFile.close();
    }
    ConstIterPtr<int> iterB = seq->cbegin();
    ConstIterPtr<int> iterE = seq->cend();
    for (ConstIter<int> &b = *iterB, &e = *iterE; b; ++b) {
        std::cout << *b << std::endl <<*e << std::endl;
        --e;
    }
}