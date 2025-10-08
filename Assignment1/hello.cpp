#include <iostream>
#include <string>
#include "hello.h"

void myproject::sayHello() {
    std::string name;
    std::cout << "Hello, world!" << std::endl;
    while (true) {
        std::cin >> name;
        std::cout << "Hello, " << name << "!" << std::endl;
    }
}
