#pragma once
#include <string>
#include <regex>
#include <fstream>
#include <map>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iostream>

using namespace std;

class WcPlus
{
public:
		WcPlus();
		WcPlus(const int &argc, char *argv[]);
		void getWordList();
		void sortWord();
		void outPut();
		~WcPlus();
private:
		ifstream input;
		map<string, unsigned> word;
		vector <pair<string, unsigned>> result;
};