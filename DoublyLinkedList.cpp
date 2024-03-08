#include"DoublyLinkedlist.h"
#include "player.h"
#include<iostream>
#include<fstream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
	this->start = NULL;
	readFromBinaryFile("players.bin");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLinkedList<T>::insertPos(T d,int pos) {
	Node<T> * temp = new Node<T>(d);
	if(start == NULL) {
		start = temp;
		return;
	}
	if(pos == 1) {
		temp->setNext(start);
		start->setPrev(temp);
		start = temp;
		return;
	}
	Node<T> *p = start;
	int i = 1;
	while(p->getNext()!=NULL && i<pos-1) {
		p = p->getNext();
		i++;
	}
	if (p->getNext() == NULL && i < pos - 1) {
		//insert end
		p->setNext(temp);
		temp->setPrev(p);
	} else {
		temp->setPrev(p);
		temp->setNext(p->getNext());
		if (temp->getNext() != NULL) {
			temp->getNext()->setPrev(temp);
		}
		p->setNext(temp);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLinkedList<T>::insertEnd(T &p) {
	Node<T>* temp = new Node<T>(p);
	if (start == nullptr) {
		start = temp;
	} else {

		Node<T>* p = start;
		while (p->getNext() != nullptr) {
			p = p->getNext();
		}

		p->setNext(temp);
		temp->setPrev(p);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLinkedList<T>::deletePos(int pos) {

	if(start == NULL) {
		cout<<"\nNo Nodes to delete";
		return;
	}
	Node<T>* p = start;
	if(pos == 1) {
		start = p->getNext();
		p->getData().displayPlayer();
		delete p;
		return;
	}


	int i = 1;
	while(i<pos-1 && p->getNext()!=NULL) {
		p=p->getNext();
		i++;
	}
	Node<T>* q = p->getNext();
	if(i == pos-1 && q->getNext()!=NULL) {
		Node<T>* q=p->getNext();

		//last pos
		if(q->getNext()==NULL) {
			p->setNext(NULL);
		}
		//middle
		if(q->getNext()!=NULL) {
			q->getNext()->setPrev(p);
		}
		p->setNext(q->getNext());
		cout<<"\n";
		q->getData().displayPlayer();

		delete q;
		return ;
	} else {
		cout<<"\n Invalid";
	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLinkedList<T>::display() {
	if (start == NULL) {
		cout << "\nNo Nodes to display" << endl;
		return;
	}
	Node<T>* p = start;
	while (p != NULL) {
		p->getData().displayPlayer();
		cout << endl;
		p = p->getNext();
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool DoublyLinkedList<T>::searchPlayer(int jersey_no, Node<T>* &np) {
	if (start == NULL) {
		cout << "\nLinked List is EMPTY!!";
		np = NULL;
		return false;
	}

	int flag = 0;
	Node<T>* p = start;

	while (p != NULL) {
		if (jersey_no == p->getData().getJersey_no()) {
			np = p;
			flag = 1;
			break;
		}
		p = p->getNext();
	}

	if (flag == 1) {
		np->getData().displayPlayer();
		return true;
	}

	return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLinkedList<T>::updatePlayer() {
	if(start==NULL) {
		cout<<"\n Linked List IS EMPTY";
		return ;
	}
	int flag=0;

	Node<T>* np = NULL;
	int choice = 0;
	cout << "Enter the Choice 1 : 'Update RUNS' or Choice 2 : 'Update WICKETS': ";
	cin >> choice;
	cout << "\n";


	if (choice == 1) {

		int update_player;
		cout << "Enter 'Jersey_No' you want to Update: ";
		cin>>update_player;
		searchPlayer(update_player,np);
		if(np!=NULL) {
			T p = np->getData(); // np-> getdata = search player data
			cout << "Enter the details you want to update" << endl;
			cout << "Enter the runs you want to update of " << update_player << " : ";
			int runs;
			cin >> runs;
			p.setRuns(runs);
			np->setData(p);
			cout<<"\n\n***Player information updated successfully***\n";
			return;
		}
		cout<<"\n Failed to Update...!!";

	} else if(choice == 2) {

		int update_player;
		cout << "Enter 'Jersey_No' you want to Update: ";
		cin >> update_player;
		searchPlayer(update_player,np);
		if(np!=NULL) {
			T p = np->getData(); // np-> getdata = search player data
			cout << "Enter the details you want to update" << endl;
			cout << "Enter the Wickets you want to update of " << update_player << " : ";
			int wickets;
			cin >> wickets;
			p.setWickets(wickets);
			np->setData(p);
			cout<<"\n\n***Player information updated successfully***\n";
			return;
		}
		cout<<"\n Failed to Update...!!";
	} else {
		cout<<"Invalid choice!!";
		return;
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLinkedList<T>::TOP_3() {
	if (start == nullptr) {
		cout << "Linked List is empty." << endl;
		return;
	}

	int choice = 0;
	cout << "Enter the Choice 1 : 'TOP 3 RUN SCORER' or Choice 2 : 'TOP 3 WICKET TAKER':";
	cin >> choice;

	switch (choice) {
		case 1: {
			// Sort players by runs in descending order using Bubble Sort
			Node<T>* p = start;
			while (p->getNext() != NULL) {
				Node<T>* q = p->getNext();
				while (q != NULL) {
					if (p->getData().getRuns() < q->getData().getRuns()) {
						T temp = p->getData();
						p->setData(q->getData());
						q->setData(temp);
					}
					q = q->getNext();
				}
				p = p->getNext();
			}

			cout << "\n*** Top 3 Players Who have the most RUNS ***\n";
			Node<T>* n = start;
			int count = 1;

			while (n != NULL && count <= 3) {
				cout << "Player Name: " << n->getData().getName() << endl;
				cout << "Jersey Number: " << n->getData().getJersey_no() << endl;
				cout << "Matches Played: " << n->getData().getMatchesPlayed() << endl;
				cout << "Runs: " << n->getData().getRuns() << endl;
				cout << "Wickets: " << n->getData().getWickets() << endl << endl;
				n = n->getNext();
				count++;
			}
			break;
		}
		case 2: {
			// Sort players by wickets in descending order using Bubble Sort
			Node<T>* p = start;
			while (p->getNext() != NULL) {
				Node<T>* q = p->getNext();
				while (q != NULL) {
					if (p->getData().getWickets() < q->getData().getWickets()) {
						T temp = p->getData();
						p->setData(q->getData());
						q->setData(temp);
					}
					q = q->getNext();
				}
				p = p->getNext();
			}

			cout << "*** Top 3 Players Who have the most WICKETS ***" << endl;
			Node<T>* n = start;
			int count = 1;

			while (n != NULL && count <= 3) {
				cout << "Player Name: " << n->getData().getName() << endl;
				cout << "Jersey Number: " << n->getData().getJersey_no() << endl;
				cout << "Matches Played: " << n->getData().getMatchesPlayed() << endl;
				cout << "Runs: " << n->getData().getRuns() << endl;
				cout << "Wickets: " << n->getData().getWickets() << endl << endl;
				n = n->getNext();
				count++;
			}
			break;
		}
		default:
			cout << "Invalid choice." << endl;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	writeToBinaryFile("players.bin");
	
	Node<T>* p = start;
	while (p != NULL) {
		Node<T>* q = p->getNext();
		delete p;
		p = q;
	}
	start = nullptr;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLinkedList<T>::writeToBinaryFile(char* file) {
	ofstream outFile(file, ios::binary);
	if(!outFile) {
		cout << "Error opening file " << file << endl;
		return;
	}

	Node<T>* p = start;
	while (p != NULL) {
		T player = p->getData();
		outFile.write((char*)&player, sizeof(T));
		p = p->getNext();
	}

	outFile.close();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLinkedList<T>::readFromBinaryFile(char* file) {
	ifstream inFile(file, ios::binary);
	if (!inFile) {
		cout << "Error opening file " << file << endl;
		return;
	}

	Player player;
	while (inFile.read((char*)&player, sizeof(player))) {
		insertEnd(player);
	}

	inFile.close();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////