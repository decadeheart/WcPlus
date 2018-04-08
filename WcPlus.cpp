#include "WcPlus.h"



WcPlus::WcPlus()
{
}
//袁巡部分
WcPlus::WcPlus(const int &argc,char * argv[])
{
		if (argc > 1) {
				string path(argv[argc - 1]);
				regex ifname("[[:alnum:]]+\\.txt$", regex::icase);
				if (!regex_search(path, ifname))
				{
						cout << "match failed";
						exit(-1);
				}
				input.open(path);
				if (input.is_open()) {
						cout << "valid filePath";
				}
				else {
						cout << "inValid filePath";
				}
		}
		else {
				cout << "not input filePath";
		}
}
//张伟东部分
void WcPlus::getWordList()
{
		input >> noskipws;
		char ch;
		string str;
		while (input >> ch)
		{
				if (isalpha(ch))
				{
						ch = tolower(ch);
						str = str + ch;
				}
				else if (!str.empty())
				{
						if ((ch == '-') && (isalpha((input.peek()))))
						{
								str = str + '-';
						}
						else
						{
								auto ret = word.insert({ str,1 });
								if (!ret.second)
										++ret.first->second;
								str = "";
						}
				}
		}
		input >> skipws;
		input.close();
}
//尹榛菲部分
void WcPlus::sortWord()
{
		for (auto w = word.begin(); w != word.end(); ++w)
		{
				result.push_back(*w);
		}
		auto cmp = [](const pair<string, unsigned>& r1, const pair<string, unsigned>& r2) {return r1.second > r2.second; };
		stable_sort(result.begin(), result.end(), cmp);
}
//刘天植部分
void WcPlus::outPut()
{
		ofstream output("result.txt");
		if (output.is_open())
		{
				if (result.size() < 100)
				{
						for (auto p = result.begin(); p != result.end()-1; ++p)
						{
								output << p->first << " " << p->second << endl;
						}
						output << result[result.size() - 1].first << " " << result[result.size() - 1].second;
				}
				else
				{
						for (auto p = result.begin(); p != result.begin() + 99; ++p)
						{
								output << p->first << " " << p->second << endl;
						}
						output << result[99].first << " " << result[99].second;
				}
		}
		else
		{
				cout << "打不开文件！" << endl;
		}
		output.close();
}
WcPlus::~WcPlus()
{
}