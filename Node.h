template <class T>

class Node {
		Node* prev;
		T data;
		Node* next;

	public:
		Node();
		Node(T);
		void setData(T);
		void setNext(Node* );
		Node* getNext();
		void setPrev(Node*);
		Node* getPrev();
		T& getData();
	
};