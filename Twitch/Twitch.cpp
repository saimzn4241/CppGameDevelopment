#include "FlappyTwitch/GameManager.h"

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	cout << "Hello, Twitch!" << endl;
	srand(time(NULL));

	GameManager gameManager;
	gameManager.start();

	return 0;
}