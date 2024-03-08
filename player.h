
#include<iostream>
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player {
		int jersey_no;
		char name[20];
		int matches_played;
		int runs;
		int wickets;
		static int count;

	public:
		Player();
		Player(int,char*,int,int,int);
		void setJersey_no(int);
		void setName(char*);
		void setMatchesPlayed(int);
		void setRuns(int);
		void setWickets(int);
		int getJersey_no();
		char* getName();
		int getMatchesPlayed();
		int getRuns();
		int getWickets();
		void displayPlayer();

		static void setCount(int);
		static int getCount();

};
#endif