#include <string>
#include "Direction.hpp"
#include <iostream>
#include "Notebook.hpp"


namespace ariel {
    
            Notebook::Notebook(){}
            void Notebook::write(int page, int row, int col, Direction dir, std::string text) {}
            std::string Notebook::read(int page, int row, int col, Direction dir, int len) {
                return "asas";
            }
            void Notebook::erase(int page, int row, int col, Direction dir, int len){} 
            void Notebook::show(int page) {}
}