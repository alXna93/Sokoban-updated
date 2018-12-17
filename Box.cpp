#include "Box.h"
#include "Framework/AssetManager.h"
#include "Level.h"
#include "Storage1.h"

Box::Box()
	: GridObject()
	, m_stored(false)
	, m_boxMoveSound()
	, m_boxStoredSound()
	

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/box.png"));
	m_boxMoveSound.setBuffer(AssetManager::GetSoundBuffer("audio/push.WAV"));
	m_boxStoredSound.setBuffer(AssetManager::GetSoundBuffer("audio/stored.WAV"));
	m_blocksMovement = true;
}

bool Box::AttemptPush(sf::Vector2i _direction)
{
	//Attempt to move box in given direction


	//Get current position
	//Calculate target position
	sf::Vector2i targetPos = m_gridPosition + _direction;

	//check if space is empty
	//get list of objects in our target postion
	std::vector<GridObject*> targetCellContents = m_level->GetObjectAt(targetPos);

	//Go thru list and see if any objects block movement
	bool blocked = false;
	for (int i = 0; i < targetCellContents.size(); ++i)
	{
		if (targetCellContents[i]->getBlocksMovement() == true)
		{
			blocked = true;
		}
	}

	//if empty, move there

	if (blocked == false)
	{
		m_boxMoveSound.play();
		bool moveSucceeded = m_level->MoveObjectTo(this, targetPos);

		//if we did successfully move...
		if (moveSucceeded == true)
		{
			//check if we are stored

			//Assumed we are not stored to start
			m_stored = false;
			//loop thru contents and see if storage obj was found
			for (int i = 0; i < targetCellContents.size(); ++i)
			{
				//check if this element in the vector is a Storage Object
				//By doing a dynamic cast
				Storage* storageObject = dynamic_cast<Storage*>(targetCellContents[i]);

				// if dynamic cast succeeds it will NOT be a nullptr
				//AKA the object IS a storge object

				if (storageObject != nullptr)
				{
					//we are stored!!
					m_stored = true;
					m_boxStoredSound.play();
				}

				//Check if level is complete
				m_level->CheckComplete();
			}
			//Either way, update bool and change sprite
			if (m_stored)

			{
				m_sprite.setTexture(AssetManager::GetTexture("graphics/boxStored.png"));
			}

			else
			{


				m_sprite.setTexture(AssetManager::GetTexture("graphics/box.png"));
			}

		}
		return moveSucceeded;
	}

	//If movement is blocked. do nothing, return false
	return false;


}

bool Box::GetStored()
{
	return m_stored;
}


