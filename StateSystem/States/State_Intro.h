#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../../StateSystem/BaseState.h"
#include "../../EventSystem/EventManager.h"

class State_Intro : public BaseState{
public:
	State_Intro(StateManager* l_stateManager);
	~State_Intro();

	void OnCreate();
	void OnDestroy();

	void Activate();
	void Deactivate();

	void Update(const sf::Time& l_time);
	void Draw();

	void Continue(EventDetails* l_details);
private:
	sf::Sprite m_introSprite;
	sf::Text m_text;
};