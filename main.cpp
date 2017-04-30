#include <iostream>
#include "MVar.h"

int main(){
    int count = 0;

    std::thread t0([&]{
        for(int i = 0; i < 20; ++i){
            count += 1;
            std::cout << count << '\n';
        }
    });

    std::thread t1([&]{
        for(int i = 0; i < 20; ++i){
            count += 10;
            std::cout << count << '\n';
        }
    });

    t0.join();
    t1.join();

    return 0;
}
