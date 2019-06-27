// List.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	a.pushFront(7);
	a.insert(48, 3);

	a.print();
	
	List<int>::Iterator itr(a.head, &a);

	for (itr.start(); itr.valid(); itr.forward())
	{
		cout << itr.item() << ", ";
	}

	system("pause");
    return 0;
}

