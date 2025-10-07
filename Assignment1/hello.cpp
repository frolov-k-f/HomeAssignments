#include <iostream>
#include <string>
#include "hello.h"

void myproject::sayHello() {
    std::cout << "Hello, world!" << std::endl;
}

void myproject::loopHello() {
    std::string name;
    while (true) {
        std::cin >> name;
        std::cout << "Hello, " << name << "!" << std::endl;
    }
}
