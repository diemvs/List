#pragma once

template <typename T>
class List
{
public:
	List();
	~List();

	void pushBack(T data);
	void removeHead();
	void remove();
	void print();
	int getSize() { return size; }

	//перегрузка операторов
	T& operator[](const int idx);

public:
	template<typename T>
	class Node {
	public:
		Node *next;
		T data;
		Node(T data=T(), Node *next=nullptr) {
			this->data = data;
			this->next = next;
		}
	};
	int size;
	Node<T> *head;

public:
	class iterator {
	public:

	};
};

template <typename T>
List<T>::List() {
	size = 0;
	head = nullptr;
}

template <typename T>
List<T>::~List() {
	remove();
}

template<typename T>
void List<T>::pushBack(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data); //первый узел
	}
	else {
		Node<T> *current = this->head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new Node<T>(data);
	}
	size++;
}

template<typename T>
T& List<T>::operator[](const int idx)
{
	int counter = 0;
	Node<T> *current = this->head;
	while (current != nullptr)
	{
		if (counter == idx)
		{
			return current->data;
		}
		current = current->next;
		counter++;
	}
}

template<typename T>
void List<T>::removeHead()
{
	Node<T> *temp = this->head;
	head = head->next;
	delete temp;
	size--;
}

template<typename T>
void List<T>::remove() 
{
	while (size) 
	{
		removeHead();
	}
}

template<typename T>
void List<T>::print() {

}