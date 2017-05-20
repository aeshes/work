#include "tests.h"

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>


void add_twenty_numbers(
    CArray<int> & _array
    )
{
    std::srand(static_cast<unsigned>(std::time(0)));

    std::cout << "Inserting twenty integers..." << std::endl;

    for (int i = 0; i < 20; ++i)
    {
        int rnd = std::rand() % 100;
        _array.push_back(rnd);
    }
}

void sort_int_array_asc(
    CArray<int> & _array
    )
{
    std::cout << "Sorting integer array..." << std::endl;

    std::sort(_array.begin(), _array.end());
}

void erase_every_second_number(
    CArray<int> & _array
    )
{
    std::cout << "Erasing every second number..." << std::endl;

    using size_type = CArray<int>::size_type;
	bool remove = false;
	for (size_type i = 0; i < _array.size(); ++i)
    {
		if (remove) _array.erase(i--);
		remove = !remove;
    }
}

void insert_int_at_random_pos(
    CArray<int> & _array
    )
{
    std::cout << "Inserting ten integers at random position..." << std::endl;

    using size_type = CArray<int>::size_type;
	
    std::srand(static_cast<unsigned>(std::time(0)));
    for (int i = 0; i < 10; ++i)
    {
        size_type pos = std::rand() % _array.size();
        int num = std::rand() % 100;
        _array.insert(pos, num);
    }
}

static std::vector<std::string> load_words_from_file(
    std::fstream & _textfile
    )
{
    std::vector<std::string> words;
    std::string text;

    while (std::getline(_textfile, text))
    {
        std::istringstream line(text);
        std::string w;
        while (line >> w)
        {
            words.push_back(w);
        }
    }

    return words;
}

void add_fifty_rand_words(
    CArray<std::string> & _array,
    std::fstream & _textfile
    )
{
    std::cout << "Inserting fifty random words..." << std::endl;

    auto words = load_words_from_file(_textfile);

    std::srand(static_cast<unsigned>(std::time(0)));
    using size_type = std::vector<std::string>::size_type;
    for (int i = 0; i < 15; ++i)
    {
        size_type word_index = rand() % words.size();
        _array.push_back(words[word_index]);
    }
}

void sort_str_array_asc(
    CArray<std::string> & _array
    )
{
    std::cout << "Sorting string array..." << std::endl;

    std::sort(_array.begin(), _array.end());
}

void remove_words(
    CArray<std::string> & _array
    )
{
    std::cout << "Removing words containing a, b, c, d, e..." << std::endl;

    using size_type = CArray<std::string>::size_type;
    for (size_type i = 0; i < _array.size();)
    {
        if (_array[i].find_first_of("abcde") != std::string::npos)
            _array.erase(i);
        else ++i;
    }
}

void insert_three_rand_words(
    CArray<std::string> & _array,
    std::fstream & _textfile
    )
{
    std::cout << "Inserting three random words at random position..." << std::endl;

    auto words = load_words_from_file(_textfile);

    std::srand(static_cast<unsigned>(std::time(0)));
    using size_type = std::vector<std::string>::size_type;
    for (int i = 0; i < 3; ++i)
    {
        size_type word_index = rand() % words.size();
        size_type rand_pos = rand() % _array.size();
        _array.insert(rand_pos, words[word_index]);
    }
}