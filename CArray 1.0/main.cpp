#include <iostream>
#include "carray.h"
#include "tests.h"


int main()
{
	CArray<int> int_arr;
	CArray<std::string> str_arr;

	// Тестируем массив на числах
	add_twenty_numbers(int_arr);
	print(int_arr);

	sort_int_array_asc(int_arr);
	print(int_arr);

	erase_every_second_number(int_arr);
	print(int_arr);

	insert_int_at_random_pos(int_arr);
	print(int_arr);

	int_arr.clear();
	print(int_arr);

	// Тестируем массив на строках
	add_fifty_rand_words(str_arr, std::fstream("words.txt"));
	print(str_arr);

	sort_str_array_asc(str_arr);
	print(str_arr);

	remove_words(str_arr);
	print(str_arr);

	insert_three_rand_words(str_arr, std::fstream("words.txt"));
	print(str_arr);
}