#ifndef MVAR_HEADER
#define MVAR_HEADER

#include <mutex>

// unlocked = open (no data)
// locked = closed (has data)

template <typename T>
class MVar{
private:
    std::mutex openLock; // initially unlocked
    T data;

public:
    MVar(){}

    const T& get() const{

    }

    void put(const T& newData){

    }

    template <typename Func>
    void modify(Func f){

    }
};

#endif
