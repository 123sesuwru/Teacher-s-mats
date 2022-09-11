#pragma once// защита от повторного подключения

#include <SFML/Graphics.hpp> // подключение sfml

#include "MoveEntity.h"

using namespace sf; // чтобы не писать sf::

class Player : public MoveEntity { // создаем класс игрока  
								   // унаследуем класс Player от MoveEntity
private:// делаем метод init и его поля приватными 

	void init(); // задаются начальные параметры игрока 

	void dontMoveBehindMap();// игрок не сможет проходить за карту 
public:
	float currentFrame = 0;
	Player(Vector2f position, String imagePath); // конструктор
	void update();
};