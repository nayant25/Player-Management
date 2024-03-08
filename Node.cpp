#include "Node.h"
	
	template <class T>
	Node<T>::Node(T d){
		this->prev = nullptr;
		this->data = d;
		this->next = nullptr;
	}
	
	template <class T>
	void Node<T>::setPrev(Node* p){
		this->prev = p;
	}
	template <class T>
	void Node<T>::setData(T d){
		this->data = d;
	}
	template <class T>
	void Node<T>::setNext(Node<T>* n){
		this->next = n;
	}
	
	template <class T>
	Node<T>* Node<T>::getPrev(){
		return this->prev;
	}
	template <class T>
	T& Node<T>::getData(){
		return this->data;
	}
	template <class T>
	Node<T>* Node<T>::getNext(){
		return this->next;
	}