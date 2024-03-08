#include"Node.cpp"
#include"string.h"
//#include <fstream>
template <class T>
class DoublyLinkedList {
		Node<T>* start;

	public:
		DoublyLinkedList();

		void setStart(Node<T>*);
		Node<T>* getLast();

        
		void readFromBinaryFile(char* fileName);

		void writeToBinaryFile(char* fileName);


		void insertPos(T ,int);
		void insertEnd(T &);
		void deletePos(int );
		
		bool searchPlayer(int jersey_no, Node<T>*&);
		void updatePlayer();
		void TOP_3();

		void display();
		~DoublyLinkedList();

};

