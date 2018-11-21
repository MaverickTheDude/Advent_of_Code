/*
 * word_container.hpp
 *
 *  Created on: 8 lis 2018
 *      Author: Pawel
 */
#ifndef WORD_CONTAINER_HPP_
#define WORD_CONTAINER_HPP_
#include <string>
extern const int nWords;
class word_container {
private:
	std::string *words;
	int n; // number of words

public:
	word_container();
	~word_container();
	const bool add_word(std::string newWord);
	const int is_anagram(std::string word, std::string comp) const;
};

#endif /* WORD_CONTAINER_HPP_ */
