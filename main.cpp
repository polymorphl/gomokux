/* 
 * File:   main.cpp
 * Author: nadali_t
 *
 * Created on October 15, 2014, 11:06 AM
 */

#include "Graphic.hpp"

int main() {
    try {
        srand(time(NULL));
        Graphic graph;
        graph.handleGame();
    }
    catch (MyException& e) {
        std::cerr << "\033[1;31;31m" << e.where () << e.what () << "\033[0m" << std::endl;
    }
    return 0;
}

