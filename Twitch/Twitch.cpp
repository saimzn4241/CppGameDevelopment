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

	Sprite testSprite2 = Sprite("Assets/Art/Biplane.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	testSprite2.setScale(0.25f);
	testSprite2.moveTo(Vector3(Engine::SCREEN_WIDTH / 2.8, Engine::SCREEN_HEIGHT / 1.22, 0));

	Flapper player(testSprite);
	Flapper player2(testSprite2);

	InputManager im(&player);

	while (true) {
		engine.Update();
		player.update();
		player2.update();

		bool isColliding = Rigidbody::isColliding(player.getRB(), player2.getRB());
		//cout<< (isColliding)

		im.update();

		//testSprite.SetPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY());

		
		
		engine.BeginRender();
		player.render();
		player2.render();
		engine.EndRender();



	}
	
	return 0;
}

