#include"player.h"
//#include"array.h"
#include<iostream>
#include<cstring>
#include<iomanip>

int Player::count = 0;

Player::Player() {
	this -> jersey_no = 0;
	strcpy(this -> name,"not given");
	this -> matches_played = 0;
	this -> runs = 0 ;
	this -> wickets = 0;
}

Player::Player(int jersey_no,char* name,int matches_played,int runs,int wickets) {
	this -> jersey_no = jersey_no;
	strcpy(this -> name,name);
	this -> matches_played = matches_played;
	this -> runs = runs;
	this -> wickets = wickets;
	count++;
}

void Player::setJersey_no(int jersey_no) {
	this -> jersey_no = jersey_no;
}

void Player::setName(char* name) {
	strcpy(this -> name,name);
}

void Player::setMatchesPlayed(int matches_played) {
	this -> matches_played = matches_played;
}

void Player::setRuns(int runs) {
	this -> runs = runs;
}

void Player::setWickets(int wickets) {
	this -> wickets = wickets;
}

int Player::getJersey_no() {
	return this -> jersey_no;
}

char* Player::getName() {
	return this -> name;
}

int Player::getMatchesPlayed() {
	return this ->matches_played ;
}

int Player::getRuns() {
	return this -> runs;
}

int Player::getWickets() {
	return this -> wickets;
}

void Player::setCount(int c) {
	count = c;
}

int Player::getCount() {
	return count;
}

void Player::displayPlayer() {
	const char* resetColor = "\033[0m";  // Reset to default color
	const char* cyanColor = "\033[0;36m";  // Cyan color

	cout << cyanColor;
	cout << "\n-----------------------------------------------------------------------------------------------------\n";
	cout << "|  JERSEY NO   |           PLAYER NAME           |  Total Matches  |     Runs     |     Wickets     |\n";
	cout << "-----------------------------------------------------------------------------------------------------\n";


	cout << "| " << setw(6) <<getJersey_no() << "       |  " << setw(18) <<getName() << "             |  "
	     << setw(8) <<getMatchesPlayed()<< "       |  " << setw(7) <<getRuns() << "     |  "
	     << setw(8) <<getWickets() << "       |\n";
	cout << "-----------------------------------------------------------------------------------------------------\n";


	cout << resetColor;
}