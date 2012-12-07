#include <iostream>
#include<string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <ctime>

using std::pair;
using std::map;
using std::string;
using std::ifstream;
using std::cout;

int main(int argc, char** argv){
	int start, end, elapsed;
	double seconds;
	start = clock();
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
			if (line.size() == 0) //fixes the blank name returned
				break;
			found = (bool)nn.count(line);
			if (!found)
				nn.insert(pair<string, int>(line, 1));
			else
				nn[line]++;
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
	end = clock();
	elapsed = end - start;
	seconds = (double) elapsed/CLOCKS_PER_SEC;
	cout << "elapsed time: " << seconds << " seconds" << std::endl;
	return 0;
}
