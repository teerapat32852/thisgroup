#pragma once
#include "Character.h"
#include <fstream>
class Board
{
	private:
		Character* grid[5][5];
		int graphic[5][5];
		bool isOpen[5][5];

	public:
		Board()
		{
			ifstream dataFile("data.txt");
			if (!dataFile.is_open())
			{
				cout << "Error Reading File";
			}
			else
			{
				while (!dataFile.eof())
				{
					for (int i = 0; i < 5; i++)
					{
						for(int j=0;j<5;j++)
						{
							dataFile >> graphic[i][j];
							if (graphic[i][j] == 1)
							{
								grid[i][j] = new Player();
								isOpen[i][j] = true;
							}
							else if (graphic[i][j] == 2)//
							{
								grid[i][j] = new Enemy();
								isOpen[i][j] = false;
							}
							else if (graphic[i][j] == 0 || graphic[i][j] == 3)// nothing on you && that thing
							{
								grid[i][j] = nullptr;
								isOpen[i][j] = false;
							}
						}						
					}					
				}
				dataFile.close();
			}
		}
		void printBoard() {
			for (int i =0 ; i < 5; i++) {
				//cout << "| ";
				for (int j = 0; j < 5; j++) {
					if (isOpen[i][j] == true) {
						if (graphic[i][j] == 1) {
							cout << "P ";
						}
						else {
							cout << "O ";
						}
					}
					else if (isOpen[i][j] == false) {
						cout << "X ";
					}
					//cout << " | ";
				}
				cout  << endl;
			}
		}
		void open(int x, int y) {
			isOpen[x][y] = true;
		}		
		void movePlayerGraphic(int x, int y) {
			
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j<5; j++)
				{
					if (graphic[i][j] == 1)
					{
						graphic[x][y] = 1;
						graphic[i][j] = 0;
					}
					
				}
			}			
		} 
		void movePlayerGrid(int x, int y) {

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j<5; j++)
				{
					if (graphic[i][j] == 1)
					{
						grid[x][y] = grid[i][j];
						grid[i][j] = nullptr;
					}

				}
			}
		}

		int getPlayerX() {

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j<5; j++)
				{
					if (graphic[i][j] == 1)
					{
						return i;
					}

				}
			}
		}
		int getPlayerY() {

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j<5; j++)
				{
					if (graphic[i][j] == 1)
					{
						return j;
					}

				}
			}
		}
		int getGraphic(int x, int y) {
			return graphic[x][y];
		}
		bool getIsOpen(int x, int y) {
			return isOpen[x][y];
		}
		Character* getCharacter(int x, int y) {
			return grid[x][y];
		}
		Character* getPlayer() {
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j<5; j++)
				{
					if (graphic[i][j] == 1)
					{
						return grid[i][j];
					}

				}
			}
		}
};