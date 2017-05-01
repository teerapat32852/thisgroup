#pragma once
#include "Weapon.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

class Character 
{
	private:
		Weapon* STR;
		Weapon* AGI;
		Weapon* INT;
		bool fight;
	public:
		Character() {
			int randomDamage = rand() % 10+1;
			STR = new Weapon("STR", randomDamage);

			randomDamage = rand() % 10+1;
			AGI = new Weapon("AGI", randomDamage);

			randomDamage = rand() % 10+1;
			INT = new Weapon("INT", randomDamage);
		}

		void setSTR(Weapon* temp) {
			STR = temp;
		}
		void setAGI(Weapon* temp) {
			AGI = temp;
		}
		void setINT(Weapon* temp) {
			INT = temp;
		}

		Weapon* getWeapon(int number) {
			if (number == 1) {
				return STR;
			}
			else if (number == 2) {
				return AGI;
			}
			else {
				return INT;
			}
		}
		virtual void printWeapon()
		{
		
		}
		virtual void changeWeapon(Weapon* EnemyDrop) {
		}
		virtual Weapon* DropWeapon() {
			return 0;
		}
		
};

class Player : virtual public Character 
{
	
	public:

		Player() :Character()
		{

		}

		void changeWeapon(Weapon* EnemyDrop) {
			Weapon* temp = EnemyDrop;
			string choice;
			cout << "Take this weapon yes or no?" << endl;
			cin >> choice;
			if (choice == "yes") {
				if (temp->getType() == "STR") {
					setSTR(temp);
				}
				else if (temp->getType() == "AGI") {
					setAGI(temp);
				}
				else {
					setINT(temp);
				}
			}
		} 
		void printWeapon()
		{
			for (int i = 1; i <= 3; i++)
			{
				Weapon* info = getWeapon(i);
				cout << "Weapon " << i << endl;
				cout << info->getType() << " WEAPON ATK = " << info->getDamage() << endl;

			}
		}
		
};

class Enemy : virtual public Character 
{
	
	public:
		Enemy():Character()
		{
			
		}
		
		Weapon* DropWeapon() {
			int r = rand() % 3 + 1;

			return getWeapon(r);
		}
};
