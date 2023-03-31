#include <iostream>
#include "greeting.hpp"
#include "helper.hpp"

int main() {
    std::cout << get_greeting() << std::endl;
    std::cout << "The answer is " << add(2, 3) << std::endl;
    return 0;
}
