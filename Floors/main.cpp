#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

#include "file.h"

const std::string working_directory = ".\\data\\";

int main()
{
	{
		std::unique_ptr<file> bin(new bin_file(working_directory + "Floor1.txt"));
		bin->read();
		bin->sort();
		bin->dump("Sorted1.txt");
	}

	{
		std::unique_ptr<file> dec(new dec_file(working_directory + "Floor2.txt"));
		dec->read();
		dec->sort();
		dec->dump("Sorted2.txt");
	}

	{
		std::unique_ptr<file> word(new word_file(working_directory + "Floor3.txt"));
		word->read();
		word->sort();
		word->dump("Sorted3.txt");
	}
}