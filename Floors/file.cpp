#include "file.h"

static std::string
extract_using_regex(const std::string& _data, const std::string& _regex)
{
	std::regex expression(_regex);
	std::smatch match;

	if (std::regex_match(_data, match, expression))
	{
		return match.str(1);
	}
	return "";
}

std::string
extract_floor_number(const std::string& _s)
{
	return extract_using_regex(_s, "^floor[\\s]+[#]([[:digit:]]+)[\\s]*[:]+$");	/* The "floor #NUM:" format */
}

std::string
extract_room_number(const std::string& _s)
{
	return extract_using_regex(_s, "^room[\\s]+([[:digit:]]+)[\\s]*$");			/* The "room NUM" format */
}


std::string
entry::data()
{
	return extract_room_number(_data);
}

file::file(const std::string& _filepath)
	: _filepath(_filepath)
{
	_filestream.open(_filepath, std::ios::in);
}

std::string
file::name() const
{
	return _filepath;
}

bool
file::exists()
{
	return _filestream.is_open();
}

void
file::print()
{
	for (std::string line; std::getline(_filestream, line); )
	{
		std::cout << line << std::endl;
	}
}

directory::directory(const std::string& _path)
	: _dirpath(_path)
{

}

std::string
directory::next_filename()
{
	static std::string preffix = "floor";
	static std::string suffix = ".txt";
	static int current = 1;

	std::string fname = preffix + std::to_string(current) + suffix;
	++current;
	return fname;
}

file
directory::next()
{
	std::string fname = next_filename();
	return file(_dirpath + fname);
}