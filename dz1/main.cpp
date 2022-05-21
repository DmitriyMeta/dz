#include <iostream>
#include "dz1.hpp"

int main(){
    Vector<5> v;
    for(int i=0;i<50;++i){
        v.add(i);
    }
    std::cout<<5<<" = "<<v[5]<<std::endl;
    while (v.get_size()>0){
        v.pop();
    }

    return 0;
}