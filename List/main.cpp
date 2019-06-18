// List.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "List.h"
#include <iostream>

int main()
{
	List<int> a;
	a.pushBack(10);
	a.pushBack(5);
	a.pushBack(3);
	a.pushBack(2);
	a.pushBack(34);

	std::cout << a[2] << std::endl;
	for(int i = 0; i < a.getSize(); i++) {
		std::cout << a[i] << " ";
	}

	std::cout << std::endl;
	a.removeHead();

	for (int i = 0; i < a.getSize(); i++) {
		std::cout << a[i] << " ";
	}

	system("pause");
    return 0;
}

