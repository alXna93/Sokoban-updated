#include "Box.h"
#include "Framework/AssetManager.h"
#include "Level.h"

Box::Box()
	: GridObject()

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/box.png"));
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
		return m_level->MoveObjectTo(this, targetPos);

	//If movement is blocked. do nothing, return false
	return false;

}


