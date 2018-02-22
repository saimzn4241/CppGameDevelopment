// Twitch.cpp : Defines the entry point for the console application.
//

#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"

#include<iostream>
using namespace std;




int main()
{
	cout << "Hello twitch!" << endl;

	
	Engine engine;
	engine.Initialize("Twitch!");

	Sprite testSprite = Sprite("Assets/Art/Biplane.png", 0, 0);
	testSprite.setScale(0.25f);

	while (true) {
		engine.Update();
		testSprite.Update();

		//testSprite.SetPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY());

		if (Mouse::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {
			testSprite.rotateBy(100);
		}
		if (Mouse::buttonUp(GLFW_MOUSE_BUTTON_RIGHT)) {
			testSprite.rotateBy(-100);
		}
		if (Mouse::button(GLFW_MOUSE_BUTTON_MIDDLE)) {
			testSprite.rotateBy(100);
		}

		if (Keyboard::key(GLFW_KEY_W)) {
			testSprite.moveUp();
		}
		if (Keyboard::key(GLFW_KEY_S)) {
			testSprite.moveDown();
		}
		if (Keyboard::key(GLFW_KEY_A)) {
			testSprite.moveLeft();
		}
		if (Keyboard::key(GLFW_KEY_D)) {
			testSprite.moveRight();
		}
		
		engine.BeginRender();
		testSprite.Render();
		engine.EndRender();


	}
	
	return 0;
}

