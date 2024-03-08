#include"player.h"
#include<iostream>
using namespace std;
class Array {
		int size;
		int index ;
		Player* pArray ;

	public:
		Array();
		Array(int);
		bool isEmpty();
		bool isFull();
		bool AddPlayer(Player &);
		int SearchPlayer(int );
		Player* getPlayers();
		bool RemovePlayer(int );
		void mostRuns() ;
		void mostWickets() ;
		void updatePlayer();
		void display();
		~Array();
};