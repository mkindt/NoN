#include <iostream>
#include<string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <list>
#include <ctime>

using std::pair;
using std::map;
using std::string;
using std::ifstream;
using std::cout;
using std::list;
// a list is not a hash table, but I'm trying to make it one
// therefore I am rolling my own external data structure
// not what was suggested by the prof
int hasher(string k);

int main(int argc, char** argv){
	int start, end, elapsed;
	start = clock();
	double seconds;
	if (argc != 3){
		cout << "usage: nnList [filename] [threshold value]" << std::endl;
		return 0;
	}
	int threshold = atoi(argv[2]); //7 is good
	// map <string,int> nn;
	list <pair <string, int> > nn[997];
	string line;
	bool found = false;
	int bucket = 0;
	ifstream file(argv[1]);
	if (file.is_open()){
		while (file.good()){
			found = false;
			getline (file, line);
			bucket = hasher(line);
			if (bucket == 0) // eliminate blank name
				break;
			for (list <pair<string, int> >::iterator i = nn[bucket].begin(); i != nn[bucket].end(); ++i){
				if ((*i).first == line){
					(*i).second++;
					found = true;
				}
			}
			if (!found){
				nn[bucket].push_back(pair<string, int>(line, 1));
			}
		}
	}
	list<string> naughty;
	for (bucket = 0; bucket < 997; ++bucket){
		for (list <pair <string, int> >::iterator it = nn[bucket].begin(); it != nn[bucket].end(); ++it){
			if ((*it).second >= threshold){ //generous programmer elf
				cout << it->first << "  Nice!" << std::endl;
			}
			else
				naughty.push_back(it->first);
		}
	}
	for (list<string>::iterator it = naughty.begin(); it != naughty.end(); ++it){
		cout << *it << "  Naughty!" << std::endl;
	}
	end = clock();
	elapsed = end - start;
	seconds = (double) elapsed/CLOCKS_PER_SEC;
	cout << "elapsed time: " << seconds << " seconds" << std::endl;
	return 0;
}
int hasher(string k){
	int sum = 0; // ASCII values == 32 to 126, letters are 65 to 122
	for (int i = 0; i < (int)k.size(); ++i){
		sum += (int)k[i];
	}
	return sum%997;
}
