#ifndef __FILE_H
#define __FILE_H

#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <memory>


std::string extract_floor_number(const std::string& s);
std::string extract_room_number(const std::string& s);


class file
{
public:
	file(const std::string& _filepath);
	std::string name() const;
	bool exists();
	void print();

	virtual void read() = 0;
	virtual void sort();
	virtual void dump(const std::string& _out);

protected:
	std::string   _filepath;
	std::ifstream _filestream;
	std::string   _firstline;
	std::unique_ptr<std::vector<std::string>> _data;
};

class bin_file : public file
{
public:
	bin_file(const std::string& _fname);
	void read() override;
};

class dec_file : public file
{
public:
	dec_file(const std::string& _fname);
	void read() override;
};

class word_file : public file
{
public:
	word_file(const std::string& _fname);
	void read() override;
};


#endif