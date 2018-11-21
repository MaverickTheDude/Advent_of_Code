// Togedther with passphrases.cpp & word_container.hpp
#include <string>
#include "word_container.hpp"

const int nWords = 15;

word_container::word_container() {
	words = new std::string[nWords];
	for (int i = 0; i < nWords; i++)
		words[i] = "";
	n = 0;
}
word_container::~word_container() {
	delete [] words;
}
const bool word_container::add_word(std::string newWord) {
	// out = repeat, i.e.
	// true when newWord == any of previous words
	// false if all words within words[] are different
	if (n == 0) {
		words[n] = newWord;
		n++;
		return false;
	}
	bool out = false;
	for (int i = 0; i < n; i++) {
		const int repeat = is_anagram(words[i], newWord);
		if (repeat == 0) {
			out = true;
			break;
		}
	}
	words[n] = newWord;
	n++;
	return out;
}

const int word_container::is_anagram(std::string word, std::string comp) const {
	const unsigned int n = comp.length();
	if (n != word.length())
		return -1; // i.e. false

	for (unsigned int itC = 0; itC < n; itC++) {
		bool hit = false;
		for (std::string::iterator itW = word.begin(); itW < word.end(); itW++) {
			if (*itW == comp[itC]) { // if both letters agree
				word.erase(itW, itW + 1);
				hit = false;
				break;
			}
			hit = true;
		}
		if (hit)
			return -1;  // No anagram
	}
	return 0; // i.e. true -> it's anagram
}
