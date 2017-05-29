#include <iostream>
#include <string>

#include "core.h"

template <typename T>
int compare(const T& l, const T& r)
{
	return 0;
}

template <typename T>
T calc(T l, int r)
{
	return 0;
}

template <typename T>
T fcn(T l, T r)
{
	return 0;
}

template <typename T> int f1(T a, T b)
{
	return 0;
}

template <typename T1, typename T2> int f2(T1 a, T2 b)
{
	return 0;
}

int main()
{
	int i = 0, j = 42;
	int *p1 = &i, *p2 = &j;
	const int *cp1 = &i, *cp2 = &j;

	f2(p1, cp2);
}