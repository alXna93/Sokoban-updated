// Project Includes
#include "Player.h"
#include "Framework/AssetManager.h"
#include "Level.h"

Player::Player()
	: GridObject()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/player/playerStandDown.png"));

}

void Player::Input(sf::Event _gameEvent)
{
	//Read input from keyboard
	//Convert to direction to move in
	//The move player

	//Was the event a key press?
	if (_gameEvent.type == sf::Event::KeyPressed)
	{
		//Yes it was a key press!
		//What key was pressed?

		if (_gameEvent.key.code == sf::Keyboard::W)
		{
			//it was W!!
			//Move up
			AttemptMove(sf::Vector2i(0, -1));
		}

		else if (_gameEvent.key.code == sf::Keyboard::A)
		{
			//it was A!!
			//Move up
			AttemptMove(sf::Vector2i(-1, 0));
		}


		else if (_gameEvent.key.code == sf::Keyboard::S)
		{
			//it was S!!
			//Move up
			AttemptMove(sf::Vector2i(0, 1));
		}

		else if (_gameEvent.key.code == sf::Keyboard::D)
		{
			//it was D!!
			//Move up
			AttemptMove(sf::Vector2i(1, 0));
		}

	}
}

bool Player::AttemptMove(sf::Vector2i _direction)
{
	//Attempting to move in given direction

	//Get current position
	//Calculate target position
	sf::Vector2i targetPos = m_gridPosition + _direction;


	//TODO: Check if the space is empty

	//if empty, move there
	return m_level->MoveObjectTo(this, targetPos);

}