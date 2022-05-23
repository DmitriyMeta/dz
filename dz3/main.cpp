#include "dz3.hpp"
#include <iostream>

int main() {
    Vector<int, 5> v;
    for (int i = 0; i < 50; ++i) {
        v.add(i);
    }
    std::cout << 5 << " = " << v[5]<< std::endl;

    for(auto it = v.begin(); it != v.end(); ++it){
        std::cout<< *it <<" ";
    }

    Vector<int,7> n(v.begin(), v.end());
    for(auto& x : n){
        std::cout<< x << " ";
    }
    while (v.get_size() > 0) {
        v.pop();
    }

    return 0;
}