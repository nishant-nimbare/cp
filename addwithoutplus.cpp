#include<iostream>


int add(int a, int b){

    while(b>0){
        int s = a^b;
        int c = a&b;

        a=s;
        b= c<<1;
    }

    return a;
}

int main(int argc, char const *argv[]){

    std::cout<<add(1,3)<<"\n";
}