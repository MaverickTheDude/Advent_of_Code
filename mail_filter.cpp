#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using std::cout;
using std::endl;

int main() {
	std::string line;
	std::ifstream myfile("blacklist_cat.txt");
	std::ofstream outFile("blacklisted.txt");
	std::ofstream open("blacklisted.txt");
	std::vector<std::string> adresses;
//	std::regex wzorzec("@[[:alnum:]]*.[[:alnum:]]*");
	std::regex wzorzec("@(.*)");
	int current = 0;

	adresses.push_back("@mailfordrivers.pl");
	while ( getline(myfile, line) ) {
		bool write = true;
		++current;
		cout << current << '\n';
		std::string suffix("");
		std::smatch wynik; // tutaj będzie zapisany wynik
		if( std::regex_search( line, wynik, wzorzec ) )
			 suffix = wynik.str(0);
		for (std::vector<std::string>::iterator it = adresses.begin(); it < adresses.end(); it++) {
			int index = std::distance(adresses.begin(), it); // how to convert iterator to int
			if (suffix == *it) {
				write = false;
				break;
			}
		}
		if (write)
			adresses.push_back(suffix);
	}
	cout << "jestem TU" << '\n';
	for (std::vector<std::string>::iterator it = adresses.begin(); it < adresses.end(); it++) {
		outFile << *it << std::endl;
	}
	cout << "jestem TU tez" << '\n';
	outFile.close();
	return 0;
}
