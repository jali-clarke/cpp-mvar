#include <thread>
#include <iostream>
#include "MVar.h"

void unsynched(){
    int count = 0;

    std::thread t0([&]{
        for(int i = 0; i < 10000; ++i){
            int num = count;
            num += 2;
            count = num;
        }
    });

    std::thread t1([&]{
        for(int i = 0; i < 10000; ++i){
            int num = count;
            num --;
            count = num;
        }
    });

    t0.join();
    t1.join();

    std::cout << "Final count - unsynched (may not be 10000): " << count << '\n';
}

void synched(){
    MVar<int> count(0);

    std::thread t0([&]{
        for(int i = 0; i < 10000; ++i){
            int num = count.get();
            num += 2;
            count.put(num);
        }
    });

    std::thread t1([&]{
        for(int i = 0; i < 10000; ++i){
            int num = count.get();
            num --;
            count.put(num);
        }
    });

    t0.join();
    t1.join();

    std::cout << "Final count - synched (should be 10000): " << count.get() << '\n';
}

int main(){
    unsynched();
    synched();

    return 0;
}
