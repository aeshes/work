#ifndef TESTS_H
#define TESTS_H

#include "carray.h"

#include <string>
#include <fstream>
#include <sstream>
#include <vector>

template <typename TData>
void print(
    const CArray<TData> & _array
    )
{
    for (auto it = _array.begin(); it != _array.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl;
}

void add_twenty_numbers(
    CArray<int> & _array
    );

void sort_int_array_asc(
    CArray<int> & _array
    );

void erase_every_second_number(
    CArray<int> & _array
    );

void insert_int_at_random_pos(
    CArray<int> & _array
    );

void add_fifty_rand_words(
    CArray<std::string> & _array,
    std::fstream & _textfile
    );

void sort_str_array_asc(
    CArray<std::string> & _array
    );

void remove_words(
    CArray<std::string> & _array
    );

void insert_three_rand_words(
    CArray<std::string> & _array,
    std::fstream & _textfile
    );

#endif