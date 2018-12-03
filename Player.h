#pragma once


// Project Includes
#include "GridObject.h"

class Player : public GridObject
{

public:

	Player();


	//Overriding Methods
	virtual void Input(sf::Event _gameEvent);

private:

	bool AttemptMove(sf::Vector2i _direction);


};