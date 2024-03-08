#include <iostream>
#include <fstream>
#include "DoublyLinkedlist.CPP"
#include "Player.h"

int main() {

	DoublyLinkedList<Player> list;

	int choice;
	int exit = 0;

	do {
		cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "                       -*-*-*-*-*-*-*-*-PLAYER MANAGEMENT SYSTEM-*-*-*-*-*-*-*-*-" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "                       1. STORE PLAYER                        2. STORE AT " << endl << endl;
		cout << "                       3. DELETE PLAYER                       4. SEARCH PLAYER" << endl << endl;
		cout << "                       5. UPDATE PLAYER                       6. TOP 3          " << endl << endl;
		cout << "                       7. DISPLAY PLAYER"                                       << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

		cout << endl;

		cout << "Enter the choice you want to select 'CHOICE': ";
		cin >> choice;

		switch (choice) {
			case 1: {
				cout << endl;
				int jersey_no;
				cout<<"Enter Jersey_no = ";
				cin>>jersey_no;
				char name[20];
				cout<<"Enter Player Name = ";
				cin>>name;
				int matches_played;
				cout<<"Enter matches_played = ";
				cin>>matches_played;
				int runs;
				cout<<"Enter runs = ";
				cin>>runs;
				int wickets;
				cout<<"Enter wickets = ";
				cin>>wickets;
				cout<<endl;

				Player p1(jersey_no,name,matches_played,runs,wickets);
				list.insertEnd(p1);
				cout<<"***Player Added Successfully***\n";
				break;

			}
			case 2: {
				cout << endl;
				int jersey_no;
				cout<<"\nEnter Jersey_no = ";
				cin>>jersey_no;
				char name[20];
				cout<<"Enter Player Name = ";
				cin>>name;
				int matches_played;
				cout<<"Enter matches_played = ";
				cin>>matches_played;
				int runs;
				cout<<"Enter runs = ";
				cin>>runs;
				int wickets;
				cout<<"Enter wickets = ";
				cin>>wickets;
				cout<<endl;

				Player p1(jersey_no,name,matches_played,runs,wickets);

				int pos;
				cout << "\nEnter Position : ";
				cin >> pos;

				list.insertPos(p1,pos);
				cout<<"***Player Added Successfully***";
				break;
			}

			case 3: {
				int pos;
				cout<<"\nEnter the postion : ";
				cin>>pos;
				list.deletePos(pos);
				cout<<"\n***Player Deleted Successfully***";
				break;
			}

			case 4: {
				int jersey_No;
				cout << "Enter Jersey_No you want to Search: ";
				cin >> jersey_No;
				Node<Player>* p = NULL;
				if(list.searchPlayer(jersey_No,p)) {
					p->getData().displayPlayer();
				} else {
					cout << "\nPlayer Not Found..";
				}
				cout << "\n\n";
				break;
			}

			case 5: {
				cout << endl;
				list.updatePlayer();
				break;
			}

			case 6: {
				cout << endl;
				list.TOP_3();
				break;
			}

			case 7: {
				cout << endl;
				list.display();
				break;
			}

			default:
				cout << "\nSorry for the Inconvenience 'YOU HAVE ENTERED INVALID CHOICE'" << endl;
		}
		cout << "\nEnter '1' if you want to 'CONTINUE' & '0' to 'EXIT' ";
		cin >> exit;
		cout << "\nThank Youu for Visiting us !!" << endl;
	} while (exit == 1);


	return 0;
}
