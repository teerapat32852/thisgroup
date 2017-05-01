#include <time.h>
#include <stdlib.h>
#include "Game.h"

int main()
{
	srand(time(NULL));
	Game g;
	g.playGame();
}