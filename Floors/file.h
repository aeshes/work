#ifndef __FILE_H
#define __FILE_H

#include <string>
#include <regex>
#include <fstream>
#include <iostream>


std::string extract_floor_number(const std::string& s);
std::string extract_room_number(const std::string& s);

class entry
{
	std::string _data;

public:
	entry(const std::string& line)
		: _data(line) {}
	std::string data();
};

class file
{
public:
	file(const std::string& _filepath);
	std::string name() const;
	bool exists();
	void print();

private:
	std::string   _filepath;
	std::ifstream _filestream;
};

class directory
{
public:
	directory(const std::string& _dirpath);
	file next();

private:
	std::string _dirpath;
	std::string next_filename();
};


#endif