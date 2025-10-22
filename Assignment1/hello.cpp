/* 
 * Kirill Frolov
 * st141840@student.spbu.ru
 * My project number one
 */

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
