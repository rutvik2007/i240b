#include<iostream>

void change(int& i){
    i=5;
}

main(){
    int a=2;
    change(2);
    std::cout<<a<<std::endl;
}