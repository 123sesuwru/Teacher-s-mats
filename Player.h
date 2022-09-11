#pragma once// ������ �� ���������� �����������

#include <SFML/Graphics.hpp> // ����������� sfml

#include "MoveEntity.h"

using namespace sf; // ����� �� ������ sf::

class Player : public MoveEntity { // ������� ����� ������  
								   // ���������� ����� Player �� MoveEntity
private:// ������ ����� init � ��� ���� ���������� 

	void init(); // �������� ��������� ��������� ������ 

	void dontMoveBehindMap();// ����� �� ������ ��������� �� ����� 
public:
	float currentFrame = 0;
	Player(Vector2f position, String imagePath); // �����������
	void update();
};