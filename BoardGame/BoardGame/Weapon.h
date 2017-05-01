#pragma once
#include <string>

using namespace std;

class Weapon {
	private:
		string type;
		int damage;
	public:

		Weapon(string type, int damage) {
			this->type = type;
			this->damage = damage;
		};

		string getType() {
			return type;
		};

		int getDamage() {
			return damage;
		};

};