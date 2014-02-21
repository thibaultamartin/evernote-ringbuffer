#include <iostream>
#include "RingBuffer.h"

void get_input(std::string& str) {
    std::cout << "> ";
    std::cin >> str;
}

int main(int argc, char **argv) {
    std::cout << "=== RingBuffer demo ===" << std::endl;
    
    std::string user_input;
    std::cout << "ringbuffer size: ";
    std::cin >> user_input;
    
    int rb_size = std::stoi(user_input);
    RingBuffer<std::string> rb(rb_size);
    
    bool exit_loop = false;
    while(!exit_loop) {
        get_input(user_input);
        
        switch(user_input.at(0)) {
            case 'P': std::cout << "print !" << std::endl;
                break;
            case 'Q': exit_loop = true;
                break;
            default:
                break;
        }
    }
}
