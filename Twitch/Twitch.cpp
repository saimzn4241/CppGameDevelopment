// Twitch.cpp : Defines the entry point for the console application.
//

#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"
#include "FlappyTwitch/InputManager.h"
#include "FlappyTwitch/Flapper.h"


#include<iostream>
using namespace std;




int main()
{
	cout << "Hello twitch!" << endl;

	
	Engine engine;
	engine.Initialize("Twitch!");

	Sprite testSprite = Sprite("Assets/Art/Biplane.png", Vector3(Engine::SCREEN_WIDTH/2, Engine::SCREEN_HEIGHT/2, 0));
	testSprite.setScale(0.25f);

	Flapper player(testSprite);
	InputManager im(&player);

	while (true) {
		engine.Update();
		player.update();
		im.update();

		//testSprite.SetPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY());

		
		
		engine.BeginRender();
		player.render();
		engine.EndRender();



	}
	
	return 0;
}

