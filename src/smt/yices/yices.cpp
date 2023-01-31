#include "yices.hpp"

namespace yices {

unsigned int running;
std::mutex mutex;

void init() {
    yices_init();
}

void exit() {
    mutex.lock();
    if (running == 0) {
        yices_exit();
    }
    mutex.unlock();
}

}
