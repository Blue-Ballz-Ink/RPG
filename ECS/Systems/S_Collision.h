#pragma once
#include "../Core/S_Base.h"
#include "../Components/C_Position.h"
#include "../Components/C_Collidable.h"

struct TileInfo;
class Map;

struct CollisionElement{
	CollisionElement(float l_area, TileInfo* l_info, const sf::FloatRect& l_bounds)
		:m_area(l_area), m_tile(l_info), m_tileBounds(l_bounds) {}
	float m_area;
	TileInfo* m_tile;
	sf::FloatRect m_tileBounds;
};

using Collisions = std::vector<CollisionElement>;

class S_Collision : public S_Base{
public:
	S_Collision(SystemManager* l_systemMgr);
	~S_Collision();

	void SetMap(Map* l_map);

	void Update(float l_dT);
	void HandleEvent(const EntityId& l_entity,const EntityEvent& l_event);
	void Notify(const Message& l_message);
private:
	void EntityCollisions();
	void MapCollisions(const EntityId& l_entity, C_Position* l_pos, C_Collidable* l_col);
	void CheckCollisions(C_Position* l_pos, C_Collidable* l_col, Collisions& l_collisions);
	void HandleCollisions(const EntityId& l_entity, C_Position* l_pos, C_Collidable* l_col, Collisions& l_collisions);
	void CheckOutOfBounds(C_Position* l_pos);
	
	Map* m_gameMap;
};