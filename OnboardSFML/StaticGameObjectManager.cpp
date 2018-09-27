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
