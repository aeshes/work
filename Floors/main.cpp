#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "file.h"

const std::string working_directory = ".\\data\\";
const std::map<std::string, int> digits =
{
	{ "one",    1 },
	{ "two",    2 },
	{ "three",  3 },
	{ "four",   4 },
	{ "five",   5 },
	{ "six",    6 },
	{ "seven",  7 },
	{ "eight",  8 },
	{ "nine",   9 },
	{ "ten",   10 }
};

int main()
{
	directory dir(working_directory);
	for (file f = dir.next(); f.exists(); f = dir.next())
	{
		f.print();
	}
}