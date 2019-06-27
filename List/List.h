#pragma once

using namespace std;

template <typename T>
class List
{
public:
	List();
	~List();

	void pushBack(T data);
	void pushFront(T data);
	void removeHead();
	void removeNode(int idx);
	void remove();
	void insert(T data, int idx);
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


	class Iterator {
	public:
		Node<T> *node;
		List<T> *list;

		Iterator(Node<T> *n, List<T> *l) {
			node = n;
			list = l;
		}
		
		void forward() {
			if (node != nullptr) {
				node = node->next;
			}
		}
		int& item() {
			return node->data;
		}
		bool valid() {
			return (node != NULL);
		}
		void start() {
			node = list->head;
		}
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

template<typename T>
void List<T>::pushFront(T data) {
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void List<T>::insert(T data, int idx) {

	if (idx = 0) {
		pushFront(data);
	}
	else {
		Node<T> *previous = this->head;

		for (int i = 0; i < idx - 1; i++) {
			previous = previous->next;
		}
		Node<T> *NewNode = new Node<T>(data, previous->next);
		previous->next = NewNode;

		size++;
	}

	
}

