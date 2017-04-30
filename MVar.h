#ifndef MVAR_HEADER
#define MVAR_HEADER

#include <mutex>

// an MVar is initially created as open

template <typename T>
class MVar{
private:
    // neither of these locks will be both open or closed at the same time
    std::mutex openLock; // should be initially locked
    std::mutex closeLock; // should be initially unlocked
    T data;

public:
    // construct empty MVar
    MVar(){
        openLock.lock();
    }

    // construct occupied MVar
    MVar(const T& initData){
        data = initData;
        closeLock.lock();
    }

    const T& get(){
        openLock.lock(); // box is now open
        closeLock.unlock(); // ditto
        return data;
    }

    void put(const T& newData){
        closeLock.lock(); // box is closed
        data = newData;
        openLock.unlock(); // ditto
    }

    template <typename Func>
    void modify(Func f){
        // open the box, do something, close the box
        put(f(get()));
    }

    const T& read(){
        const T& temp = get();

        // don't want to use put() since we want to avoid unnecessary copying
        closeLock.lock();
        openLock.unlock();

        return temp;
    }
};

#endif
