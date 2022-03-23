
#include "doctest.h"
#include "Notebook.hpp"
using namespace ariel;
#include <string>
#include <algorithm>

std::string nospaces(std::string input) {
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("NEGATIVE input && char input") {

    ariel::Notebook notebook;

    // HORIZONTAL
       
            CHECK_THROWS(notebook.read(3, -4, 20, Direction::Horizontal, 101));
            CHECK_THROWS(notebook.read(4, -6, 72, Direction::Horizontal, 32));
            CHECK_THROWS(notebook.read(-21, 1, 81, Direction::Horizontal, 67));
            CHECK_THROWS(notebook.read(-1, 1, 12, Direction::Horizontal, 67));
            CHECK_THROWS(notebook.read(-1, 1, 31, Direction::Horizontal, 7));
            CHECK_THROWS(notebook.read(2, -3, 103, Direction::Horizontal, 56));
            CHECK_THROWS(notebook.erase(-4, 1, 21, Direction::Horizontal, 26));
            CHECK_THROWS(notebook.erase(3, -3, 35, Direction::Horizontal, 78));
            CHECK_THROWS(notebook.erase(6, 1, -11, Direction::Horizontal, 56));
            CHECK_THROWS(notebook.write(3, -2, 8, Direction::Horizontal, "dsa"));
            CHECK_THROWS(notebook.write(-4, -2, 32, Direction::Horizontal, "sad"));
            CHECK_THROWS(notebook.write(4, -7, -41, Direction::Horizontal, "sad"));
            CHECK_THROWS(notebook.show(-2));
            CHECK_THROWS(notebook.show(-3));
            CHECK_THROWS(notebook.show(-3));
            CHECK_THROWS(notebook.read(2, 'a', 103, Direction::Horizontal, 56));
            CHECK_THROWS(notebook.erase('n', 1, 21, Direction::Horizontal, 26));
            CHECK_THROWS(notebook.erase(3, '&', 35, Direction::Horizontal, 78));
             

        // VERTICAL

            CHECK_THROWS(notebook.read(3, -4, 20, Direction::Vertical, 101));
            CHECK_THROWS(notebook.read(4, -6, 72, Direction::Vertical, 32));
            CHECK_THROWS(notebook.read(-21, 1, 81, Direction::Vertical, 67));
            CHECK_THROWS(notebook.read(2, -3, 103, Direction::Vertical, 56));
            CHECK_THROWS(notebook.erase(-4, 1, 21, Direction::Vertical, 26));
            CHECK_THROWS(notebook.erase(3, -3, 35, Direction::Vertical, 78));
            CHECK_THROWS(notebook.erase(6, 1, -11, Direction::Vertical, 56));
            
            CHECK_THROWS(notebook.write(3, -2, 8, Direction::Vertical, "dsa"));
            CHECK_THROWS(notebook.write(-4, -2, 32, Direction::Vertical, "sad"));
            CHECK_THROWS(notebook.write(4, -7, -41, Direction::Vertical, "sad"));
            CHECK_THROWS(notebook.erase('a', 1, 21, Direction::Vertical, 26));
            CHECK_THROWS(notebook.erase(3, 'b', 35, Direction::Vertical, 78));
            CHECK_THROWS(notebook.erase(6, 'c', -11, Direction::Vertical, 56));
             
    

   

}

TEST_CASE("Good input") {
    ariel::Notebook notebook;
       
    notebook.write(50, 50, 50, Direction::Horizontal, "heloo");
    CHECK(notebook.read(50, 50, 50, Direction::Horizontal, 5) == "heloo");


    notebook.erase(100, 100, 50, Direction::Vertical, 6);
    CHECK(notebook.read(100, 50, 50, Direction::Vertical, 6) == "~~~~~~");

    notebook.write(0, 0, 0, Direction::Horizontal, "siiiiii");
    CHECK(notebook.read(0, 0, 0, Direction::Horizontal, 8) == "siiiiii");

    notebook.erase(0, 0, 0, Direction::Horizontal, 8);
    CHECK(notebook.read(0, 0, 0, Direction::Horizontal, 8) == "~~~~~~~~");

     notebook.write(50, 50, 50, Direction::Horizontal, "muchas gracias");
    CHECK(notebook.read(50, 50, 50, Direction::Horizontal, 14) ==  "muchas gracias");

    notebook.erase(100, 100, 50, Direction::Vertical, 14);
    CHECK(notebook.read(100, 50, 50, Direction::Vertical, 14) == "~~~~~~~~~~~~~~");

    notebook.write(0, 0, 0, Direction::Horizontal, "hole");
    CHECK(notebook.read(0, 0, 0, Direction::Horizontal, 4) == "hole");

    notebook.erase(0, 0, 0, Direction::Horizontal, 8);
    CHECK(notebook.read(0, 0, 0, Direction::Horizontal, 8) == "~~~~~~~~");

   
}