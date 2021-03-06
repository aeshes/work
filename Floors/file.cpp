#include "file.h"

#include <map>

static std::string
extract_using_regex(const std::string& _data, const std::string& _regex)
{
	std::regex expression(_regex);
	std::smatch match;

	if (std::regex_match(_data, match, expression))
	{
		return match.str(1);
	}
	return std::string();
}

std::string
extract_floor_number(const std::string& _s)
{
	return extract_using_regex(_s, "^floor[\\s]+[#]([[:digit:]]+)[\\s]*[:]+$");	/* The "floor #NUM:" format */
}

std::string
extract_room_number(const std::string& _s)
{
	return extract_using_regex(_s, "^room[\\s]+([[:digit:]]+)[\\s]*$");	/* The "room NUM" format */
}



file::file(const std::string& _filepath)
	: _filepath(_filepath), _data(new std::vector<std::string>())
{
	_filestream.open(_filepath, std::ios::in);
	std::getline(_filestream, _firstline);
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

void
file::sort()
{
	std::sort(_data->begin(), _data->end());
}

void
file::dump(const std::string& _out)
{
	std::ofstream out(_out, std::ios::trunc);
	for (const auto& room : *_data)
	{
		out << room << std::endl;
	}
}


bin_file::bin_file(const std::string& _fname)
	: file(_fname)
{
	
}

void
bin_file::read()
{
	std::string line;
	while (std::getline(_filestream, line))
	{
		std::string room = extract_room_number(line);
		_data->push_back(room);
	}
}

dec_file::dec_file(const std::string& fname)
	: file(fname)
{

}

void
dec_file::read()
{
	std::string line;
	while (std::getline(_filestream, line))
	{
		std::string room = extract_room_number(line);
		_data->push_back(room);
	}
}

word_file::word_file(const std::string& fname)
	: file(fname)
{

}

void
word_file::read()
{
	std::string line;
	while (std::getline(_filestream, line))
	{
		std::string room = extract_using_regex(line, "^room[\\s]+([\\w]+)[\\s]*[;]$");
		_data->push_back(room);
	}
}

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

inline bool compare(const std::string& lhs, const std::string& rhs)
{
	return digits.at(lhs) < digits.at(rhs);
}

void
word_file::sort()
{
	std::sort(_data->begin(), _data->end(), compare);
}