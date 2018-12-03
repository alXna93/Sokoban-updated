// Project Includes
#include "Storage1.h"
#include "Framework/AssetManager.h"

Storage::Storage()
	: GridObject()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/storage.png"));
}