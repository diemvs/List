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

	a.print();

	a.removeNode(2);

	a.print();

	system("pause");
    return 0;
}

