#pragma once
#include "VisibleGameObject.h"

class StaticGameObjectManager {
public:
	StaticGameObjectManager();
	~StaticGameObjectManager();

	void Add(std::string name, VisibleGameObject* gameObject);
	void Remove(std::string name);
	int GetObjectCount() const;
	VisibleGameObject* Get(std::string name) const;

	void DrawAll(sf::RenderWindow& renderWindow);

private:
	std::map<std::string, VisibleGameObject*> _staticGameObjects;
	struct GameObjectDeallocator {
		void operator() (const std::pair<std::string, VisibleGameObject*> &p) const
		{
			delete p.second;
		}
	};
};