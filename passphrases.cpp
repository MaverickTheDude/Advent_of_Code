/* Togedher with word_container.cpp & word_container.hpp
   Draft rozłącznej kompilacji */
#include <iostream>
#include <fstream>
#include <string>
#include "word_container.hpp"
const char SPACE = ' ';
const char EOL = '\0';
const std::string BLANK = "";

int main() {
	std::string line;
	std::ifstream myfile("input.txt");
	int valid_lines = 0;
	bool isopen = myfile.is_open();
	std::cout << "otwarte: " << isopen << std::endl;
    while ( getline (myfile,line) ) {
    	bool repeat = false;
    	std::string current_word = BLANK;
    	word_container *wcPT = new word_container; // obiekt stworzony w run-time'ie, więc po kompilaacji i wszystko jest cacy
    	for (unsigned int i = 0; i < line.length() + 1; i++) { // Dodatkowa iteracja na sprawdzenie warunku '\n' -> checkout
    		if (line[i] != SPACE && line[i] != EOL) {
    			current_word += line[i];
    		}
    		else {
    			repeat = wcPT->add_word(current_word);
    			current_word = BLANK;
    			if (repeat)
    				break;
    		}
    	}
    	if (repeat == false)
    		valid_lines++;
    	delete wcPT;
    }
    myfile.close();

    std::cout << "valid lines: \t" << valid_lines << std::endl;

	return 0;
}
