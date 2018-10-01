#include "stdafx.h"
#include "StaticGameObjectManager.h"
#include "GameManager.h"

StaticGameObjectManager::StaticGameObjectManager() { }

StaticGameObjectManager::~StaticGameObjectManager() 
{ 
	std::for_each(_staticGameObjects.begin(), _staticGameObjects.end(), GameObjectDeallocator());
}

void StaticGameObjectManager::Add(std::string name, VisibleGameObject* gameObject)
{
	_staticGameObjects.insert(std::pair<std::string, VisibleGameObject*>(name, gameObject));
}

void StaticGameObjectManager::Remove(std::string name)
{
	std::map<std::string, VisibleGameObject*>::iterator results = _staticGameObjects.find(name);
	if (results != _staticGameObjects.end())
	{
		delete results->second;
		_staticGameObjects.erase(results);
	}
}

VisibleGameObject* StaticGameObjectManager::Get(std::string name) const
{
	std::map<std::string, VisibleGameObject*>::const_iterator results = _staticGameObjects.find(name);
	if (results == _staticGameObjects.end())
		return NULL;
	return results->second;
}

int StaticGameObjectManager::GetObjectCount() const
{
	return _staticGameObjects.size();
}

void StaticGameObjectManager::DrawAll(sf::RenderWindow& renderWindow)
{
	std::map<std::string, VisibleGameObject*>::const_iterator itr = _staticGameObjects.begin();

	while (itr != _staticGameObjects.end())
	{
		itr->second->Draw(renderWindow);
		itr++;
	}
}

const bool StaticGameObjectManager::CheckCollisions(sf::Rect<float> playerBounds, sf::Vector2f playerPosition)
{
	std::map<std::string, VisibleGameObject*>::const_iterator itr = _staticGameObjects.begin();

	while (itr != _staticGameObjects.end())
	{
		bool doesIntersect = itr->second->GetBoundingRect().intersects(playerBounds);
		float hd = abs((playerPosition.x * playerPosition.x) + (itr->second->GetPosition().x * itr->second->GetPosition().x));
		float vd = abs((playerPosition.y * playerPosition.y) + (itr->second->GetPosition().y * itr->second->GetPosition().y));
		bool isAtop = hd < vd && playerPosition.x > itr->second->GetPosition().y;

		if (doesIntersect && isAtop)
		{
			return true;
		}
		itr++;
	}

	return false;
}