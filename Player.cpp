#include "Player.h"

#include "Map.h"


Player::Player(Vector2f position, String imagePath) : MoveEntity(position, imagePath){

	init();

	setPosition(position);// ������ ������� 

	setName("♂ Dungeon Master ♂");

}
void Player::init() {

	width = 80;// ������ ������ 

	height = 100;// ������ ������ 

	setSpeed(Vector2f(0, 0));// ������ �������� 

	setTextureRect(IntRect(0, 0, width, height)); //������ ������ �� ������

}



void Player::update() {
	sprite.move(speed.x, speed.y);
	position = sprite.getPosition();
	dontMoveBehindMap();// �� ������ ������ ����� �� ������� �����
}
void Player::dontMoveBehindMap() {// ���������� �������� ������ �� ��������� �����

	if (position.x > WINDOW_WIDTH - width) {// ���� ����� �� ������� ������

		position.x = WINDOW_WIDTH - width;// ������ ������� ��� ����� �� ����� �� �����.

		setPosition(Vector2f(position.x, position.y));// ��������� ���������.

	}
	if (position.x < 0) {// ���� ������� ������ �� x ������ 0

		position.x = 0;// ������ ������� �� x=0

		setPosition(Vector2f(position.x, position.y));//������������� ���������

	}

	if (position.y < 0) {// ���� ������� �� y ������ 0

		position.y = 0;// ������ ������� �� y = 0

		setPosition(Vector2f(position.x, position.y));// ������������� ���������

	}

	if (position.y > WINDOW_HEIGHT - height) {// ���� ����� �� ������� ������

		position.y = WINDOW_HEIGHT - height;// ������ ������� ��� ����� ����������� � �� ������� �� �������

		setPosition(Vector2f(position.x, position.y));// ������������� ���������

	}
}