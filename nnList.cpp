#include <iostream>
#include<string>
#include <map>
#include <fstream>
#include <cstdlib>

using std::pair;
using std::map;
using std::string;
using std::ifstream;
using std::cout;

int main(int argc, char** argv){
	if (argc != 3){
		cout << "usage: nnList [filename] [threshold value]" << std::endl;
		return 0;
	}
	int threshold = atoi(argv[2]); //7 is good
	map <string,int> nn;
	string line;
	bool found;
	ifstream file(argv[1]);
	if (file.is_open()){
		while (file.good()){
			getline (file, line);
			found = (bool)nn.count(line);
			if (!found)
				nn.insert(pair<string, int>(line, 1));
			else
				nn[line]++;
			//cout << nn[line] << std::endl;
		}
	}
	for (map<string, int>::iterator it = nn.begin(); it != nn.end(); ++it){
		if ((*it).second >= threshold) //generous programmer elf
			cout << it->first << "  Nice!" << std::endl;
	}
	for (map<string, int>::iterator it = nn.begin(); it != nn.end(); ++it){
		if ((*it).second < threshold)
			cout << it->first << "  Naughty!" << std::endl;
	}
	return 0;
}