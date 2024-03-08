#include "array.h"

Array::Array() {
	size = 0;
	index = -1;
	pArray = NULL;
}
Array::Array(int s) {
	size = s;
	index = -1;
	pArray = new Player[size];

}
bool Array::isEmpty() {
	if(index == -1) {
		return true;
	} else {
		return false;
	}

}

bool Array::isFull() {
	if(index == size-1) {
		return true;
	} else {
		return false;
	}
}

bool Array::AddPlayer(Player &player) {
	if(isFull()) {
		return false;
	} else {
		pArray[++index] = player;
		return true;
	}
}


int Array::SearchPlayer(int jersey_no) {
	for(int i=0; i<=index; i++) {
		if(pArray[i].getJersey_no() == jersey_no) {
			return i;
		}
	}
	return -1;
}

bool Array::RemovePlayer(int jersey_no) {
	int position = SearchPlayer(jersey_no);
	if (position == -1) {
		return false;
	} else {
		for (int i = position; i < index; i++) {
			pArray[i] = pArray[i + 1];
		}
		index--;
		return true;
	}
}

void Array::mostRuns() {
	int i = size - 1;
	while (i > 0) {
		int j = 0;
		while (j < i) {
			if (pArray[j].getRuns() < pArray[j + 1].getRuns()) {
				Player temp = pArray[j];
				pArray[j] = pArray[j + 1];
				pArray[j + 1] = temp;
			}
			j++;
		}
		i--;
	}
	cout << "*** Top 3 Player Who has most RUNS ***" << endl;

	for (int j = 0; j < 3; j++) {
		cout << "Player Name : " << pArray[j].getName() << endl;
		cout << "Jersey Number : " << pArray[j].getJersey_no() << endl;
		cout << "Matches Played : " << pArray[j].getMatchesPlayed() << endl;
		cout << "Runs : " << pArray[j].getRuns() << endl;
		cout << "Wickets : " << pArray[j].getWickets() << endl << endl;
	}
}
void Array::mostWickets() {
	int i = size - 1;
	while (i > 0) {
		int j = 0;
		while (j < i) {
			if (pArray[j].getWickets() < pArray[j + 1].getWickets()) {
				Player temp = pArray[j];
				pArray[j] = pArray[j + 1];
				pArray[j + 1] = temp;
			}
			j++;
		}
		i--;
	}
	cout << "*** Top 3 Player Who has most WICKETS ***" << endl;

	for (int j = 0; j < 3; j++) {
		cout << "Player Name : " << pArray[j].getName() << endl;
		cout << "Jersey Number : " << pArray[j].getJersey_no() << endl;
		cout << "Matches Played : " << pArray[j].getMatchesPlayed() << endl;
		cout << "Runs : " << pArray[j].getRuns() << endl;
		cout << "Wickets : " << pArray[j].getWickets() << endl << endl;
	}
}
void Array::updatePlayer() {
	int found = 0;
	int choice;

	cout << "Enter the Choice 1 : 'Update RUNS' or Choice 2 : 'Update WICKETS' Choice 3 : 'Matches_Played' : ";
	cin >> choice;
	cout << "\n";

	if (choice == 1) {
		char update_player[20];
		cout << "Enter 'PLAYER NAME' you want to Update: ";
		cin.ignore();
		gets(update_player);
		cout << endl;

		for (int i = 0; i < size; i++) {
			if (strcmpi(pArray[i].getName(), update_player) == 0) {
				cout << "Enter the details you want to update" << endl;
				cout << "Enter the runs you want to update of " << update_player << " : ";
				int runs;
				cin >> runs;
				pArray[i].setRuns(runs);
				found++;
				break;
			}
		}

		if (!found) {
			cout << "Player not found in the Database" << endl;
		}
	}

	if (choice == 2) {
		char update_player[20];
		cout << "Enter 'PLAYER NAME' you want to Update: ";
		cin.ignore();
		gets(update_player);
		cout << "\n";

		for (int i = 0; i < size; i++) {
			if (strcmpi(pArray[i].getName(), update_player) == 0) {
				cout << "Enter the details you want to update" << endl;
				cout << "Enter the wickets you want to update of " << update_player << " : ";
				int wickets;
				cin >> wickets;
				pArray[i].setWickets(wickets);
				cout << "\n";
				found++;
				break;
			}
		}

		if (!found) {
			cout << "\nPlayer not found in the Database" << endl;
		}
	}
}

void Array::display() {
	if (isEmpty()) {
		cout <<"Array is Empty\n";
	} else {
		for (int i = 0; i <= index; i++) {
			pArray[i].displayPlayer();
		}
	}
}

Player* Array::getPlayers() {
	return pArray;
}

Array::~Array() {
	if(pArray != NULL) {
		delete []pArray;
	}
}

