#include "yices.hpp"

namespace yices {

void init() {
    yices_init();
}

void exit() {
    yices_exit();
}

}
