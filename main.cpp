#include "WcPlus.h"

int main(int argc, char *argv[])
{
		WcPlus wc(argc, argv);
		wc.getWordList();
		wc.sortWord();
		wc.outPut();
		return 0;
}