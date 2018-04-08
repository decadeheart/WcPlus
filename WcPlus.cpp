#include "WcPlus.h"



WcPlus::WcPlus()
{
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

WcPlus::~WcPlus()
{
}