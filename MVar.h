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
    MVar(){
        openLock.lock();
    }

    const T& get() const{
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
        openLock.lock(); // box is now open
        closeLock.unlock(); // ditto

        data = f(data);

        closeLock.lock(); // box is closed
        openLock.unlock(); // ditto
    }
};

#endif
