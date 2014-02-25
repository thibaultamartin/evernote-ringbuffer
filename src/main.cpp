#include <iostream>
#include "RingBuffer.h"

int get_argument(std::string& str) {
    return std::stoi( str.substr(2,std::string::npos) );
}

void add_lines(int n_lines, RingBuffer<std::string>& rb) {
    for(int i=n_lines; --i>=0;) {
        std::string input;
        std::getline(std::cin, input);
        
        rb.push_front(input);
    }
}

void remove_lines(int n_lines, RingBuffer<std::string>& rb) {
    for(int i=n_lines; --i>=0;) {
        rb.pop_back();
    }
}

void print_lines(RingBuffer<std::string>& rb) {
    for(int i=0; i<rb.size(); i++) {
        std::cout << rb[i] << std::endl;
    }
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
        std::cout << "> ";
        do {
            std::getline(std::cin, user_input);
        }while(user_input == "");
        
        switch(user_input.at(0)) {
            case 'A': add_lines(get_argument(user_input), rb);
                break;
            case 'R': remove_lines(get_argument(user_input), rb);
                break;
            case 'L': print_lines(rb);
                break;
            case 'Q': exit_loop = true;
                break;
            default:
                break;
        }
    }
}
