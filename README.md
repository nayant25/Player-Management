Player Management System
This project implements a player management system using a doubly linked list in C++. It allows users to perform various operations such as inserting, deleting, updating, searching for players, and displaying top performers.

Features
Inserting players at a specified position or at the end of the list.
Deleting players from the list based on position.
Searching for players by their jersey number.
Updating player information including runs and wickets.
Displaying the top 3 players based on runs or wickets.

Folder Structure
player-management-system/
│
├── DoublyLinkedlist.h
├── player.h
├── main.cpp
└── players.bin

Dependencies
The project depends on the DoublyLinkedlist.h and player.h header files.
It uses standard C++ libraries such as <iostream>, <fstream>, and <cstring>.


How to Run
Clone the repository to your local machine.
Compile the source code using a C++ compiler.
Run the compiled executable file

#include "DoublyLinkedlist.h"
#include "player.h"
#include <iostream>

int main() {
    // Instantiate a doubly linked list
    DoublyLinkedList<Player> playersList;

    // Insert players
    Player player1(1, "Player One", 10, 500, 20);
    Player player2(2, "Player Two", 15, 600, 25);
    playersList.insertEnd(player1);
    playersList.insertEnd(player2);

    // Display players
    playersList.display();

    // Update player information
    playersList.updatePlayer();

    // Display top performers
    playersList.TOP_3();

    return 0;
}
License
This project is licensed under the MIT License - see the LICENSE file for details.
