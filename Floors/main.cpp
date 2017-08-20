#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

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
	std::unique_ptr<bin_file> bin(new bin_file(working_directory + "Floor1.txt"));
	bin->read();
	bin->sort();
	bin->dump("Sorted1.txt");
}