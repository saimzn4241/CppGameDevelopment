#include "Pipe.h"
#include "../Engine/Math/Rect.h"
#include "../Engine/Math/Math.h"
#include "../Engine/Engine.h"

Sprite* Pipe::pipeSprite = NULL;

void Pipe::Initialize() {
	pipeSprite = new Sprite("Assets/Art/pipe.png");
	pipeSprite->setScale(Vector3(0.1f, 0.35f, 1));
	//pipeSprite->setScale(0.1f);

}

Pipe::Pipe() {
	if (!pipeSprite) {
		cout << "Trying to instantiate a Pipe without having called the Initialize method!" << endl;
		return;
	}

	topSprite = Sprite(*pipeSprite);
	botSprite = Sprite(*pipeSprite);

	///gap = 1000;
	gap = 350;
	speed = 200;
}

Pipe::Pipe(Vector3 _pos) :Pipe() {
	if (!pipeSprite) {
		return;
	}
	pos = _pos + Vector3(getWidth(), 0, 0);
	prevPos = pos.x;
	updatePos();
	topSprite.flipVertical();

	Rect topRC = Rect();
	topRC.SetSize(Vector3(Math::Abs(topSprite.getSize()->x * topSprite.getScale()->x), Math::Abs(topSprite.getSize()->y * topSprite.getScale()->y), 1) );
	topRB = Rigidbody();
	topRB.initialize(1, 0, topSprite.getPos(), topSprite.getRot(), topSprite.getScale(),topSprite.getSize(), topRC);

	Rect botRC = Rect();
	botRC.SetSize(Vector3(Math::Abs(botSprite.getSize()->x * botSprite.getScale()->x), Math::Abs(botSprite.getSize()->y * botSprite.getScale()->y), 1));
	botRB = Rigidbody();
	botRB.initialize(1, 0, botSprite.getPos(), botSprite.getRot(), botSprite.getScale(), botSprite.getSize(), botRC);

	topRB.addForce(Vector3(-speed, 0, 0));
	botRB.addForce(Vector3(-speed, 0, 0));

}


void Pipe::setGap(float _gap) {
	gap = _gap;
	updatePos();
}


float Pipe::getPrevPos() {
	return prevPos;
}


void Pipe::update() {
	
	prevPos = topSprite.getPos()->x;
	topRB.update();
	botRB.update();

}

void Pipe::render() {
	topSprite.Render();
	botSprite.Render();
  topRB.render(Vector3(255, 0, 0));
	botRB.render(Vector3(0, 0, 255));
}

void Pipe::moveTo(Vector3 to) {
	pos = to;
	updatePos();


}
void Pipe::moveBy(Vector3 by) {
	pos = pos + by;
	updatePos();
}

float Pipe::getX() {
	return topSprite.getPos()->x;
}

float Pipe::getWidth() {
	return topSprite.getSize()->x * topSprite.getScale()->x;
}

void Pipe::updatePos(){
	Vector3 topPos = pos;
	topPos.y += (gap / 2) + Math::Abs(topSprite.getSize()->y * topSprite.getScale()->y /2);
	topSprite.moveTo(topPos);


	Vector3 botPos = pos;
	botPos.y -= (gap / 2) + Math::Abs(botSprite.getSize()->y * botSprite.getScale()->y / 2);
	botSprite.moveTo(botPos);
}

Rigidbody Pipe::getTopRB() {
	return topRB;
}

Rigidbody Pipe::getBotRB() {
	return botRB;
}