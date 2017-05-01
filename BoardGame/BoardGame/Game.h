#pragma once
#include "Board.h"
#include <stdlib.h>
#include <time.h>
class Game
{
private:
	Board* board;
	Character* player;
	bool win = true;
	bool changewep = false;
	int offsetX;
	int offsetY;
public:
	Game()
	{
		board = new Board();
		player = board->getPlayer();
	}
	void playGame() {
		bool findIt = false;
		board->printBoard();
		while (findIt == false) {
			int dice = (rand() % 6) + 1;
			cout << "Before:" << endl;
			board->printBoard();
			cout << "you roll " << dice << endl;
			recieveDirection(dice);
			
			findIt = checkPanel();
			if (win == false)
			{
				cout << "Yoyo is dead, GAME OVER" << endl;
				break;
			}
			cout << "After:" << endl;
			board->printBoard();
		}
		
		//printgraphic
		//while()
		//roll dice
		//recieve direction
		//move
		//printgraphic
		//checkpanel
		// - combat
		// - Chub
		// - lose
		// - weaponDrop
		// printgraphic
	}
	
	bool checkPanel() {
		cout << "SHIT" << endl;
		 //offsetX = board->getPlayerX();
		// offsetY = board->getPlayerY();
		int thatPanel = board->getGraphic(offsetX, offsetY);
		bool isOpen = board->getIsOpen(offsetX, offsetY);
		cout << thatPanel << endl;
		if (isOpen == true) {
			cout << "You've explored this panel already." << endl;
			return false;
		}
		if (thatPanel == 3) 
		{
				cout << "Congrat YoYo, you found that thing. Yeahhhhhhhh" << endl;
				return true;
		}
		else if (thatPanel == 0) 
		{
			cout << "There is nothing in this panel" << endl;
		}
		else if (thatPanel == 2) 
		{
			cout << "Encouter Enemy" << endl;
			combat(board->getCharacter(offsetX,offsetY) );
					
		}
				board->open(offsetX, offsetY);
				board->movePlayerGraphic(offsetX, offsetY);
				return false;	
		
	}
	
	void combat(Character* enemy) {
		//fight so fun
		changewep = false;
		int choice;
		win = false;
		cout << "Begin Fight, Choose your weapon (1=STR, 2=AGI, 3=INT)" << endl;
		player->printWeapon();
		cin >> choice;
		Weapon* pweapon=player->getWeapon(choice);
		Weapon* eweapon = enemy->getWeapon((rand() % 3) + 1);
		cout << "enemy attacks with " << eweapon->getType() << "with " << eweapon->getDamage() << "damage" << endl;
		if (pweapon->getType() == "STR"&&eweapon->getType() == "AGI")
		{
			win = true;
		}
		else if (pweapon->getType() == "AGI"&&eweapon->getType() == "INT")
		{
			win = true;
		}
		else if (pweapon->getType() == "INT"&&eweapon->getType() == "STR")
		{
			win = true;
		}
		else if (pweapon->getType() == eweapon->getType())
		{
			if (pweapon->getDamage() > eweapon->getDamage())
			{
				win = true;
			}
			else if(pweapon->getDamage() == eweapon->getDamage())
			{
				cout << "Draw, fight again" << endl;
				combat(enemy);
			}
		}
		if (win == true && changewep == false)
		{
			cout << "Yoyo defeated the enemy" << endl;
			Weapon* dropped = enemy->DropWeapon();
			cout << "Weapon dropped " << endl;
			cout << dropped->getType() << " WEAPON ATK = " << dropped->getDamage() << endl;
			player->changeWeapon(dropped);
		}

	}

	void recieveDirection(int dice) { // return wasd
		char direction;
		offsetX = board->getPlayerX();
		offsetY = board->getPlayerY();
		for (int i = 0; i < dice; i++) {
			cout << "type direction you want to move (w)(a)(s)(d) >> ";
			cin >> direction;
			if (direction == 'w') {
				if (offsetX - 1 >= 5) {
					offsetX -= 1;
				}
			}
			if (direction == 'a') {
				if (offsetY - 1 >= 0) {
					offsetY -= 1;
				}
			}
			if (direction == 's') {
				if (offsetX + 1 < 5) {
					offsetX += 1;
				}
			}
			if (direction == 'd') {
				if (offsetY + 1 < 5) {
					offsetY += 1;
				}
			}
		}
		//
	}

};