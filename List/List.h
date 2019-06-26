#pragma once

using namespace std;

template <typename T>
class List
{
public:
	List();
	~List();

	void pushBack(T data);
	void removeHead();
	void removeNode(int idx);
	void remove();
	int getSize() { return size; }
	void print();

	

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

	class Iterator {
	public:
		Iterator(Node<T>* node) { 
			m_node = node;
		}

		bool operator==(const Iterator& other) const {
			if (this == &other) {
				return true;
			}
			return m_node == other.m_node;
		}

		Node<T>* operator++(int) {
			m_node = m_node->next();
			return m_node;
		}
		
		T operator*() {
			return m_node->data;
		}

		Node<T>* current() {
			return m_node;
		}

	private:
		Node<T>* m_node;
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
void List<T>::removeNode(int idx)
{
	if (idx == 0) {
		removeHead();
	}
	else {
		Node<T> *previous = this->head;
		for (int i = 0; i < idx - 1; i++) {
			previous = previous->next;
		}
		Node<T> *del = previous->next; 
		previous->next = del->next;
		delete del;
		size--;
	}
}

template<typename T>
void List<T>::print() {
	Node<T> *current = this->head;
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}