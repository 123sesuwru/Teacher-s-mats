#include "Map.h"

void Map::init() {

	player = new Player(Vector2f(70, 70), "images/player1.png");

	for (int i = 0; i < HEIGHT_MAP; i++) {// ���� �� ������ �����

		for (int j = 0; j < WIDTH_MAP; j++)

		{// ���� �� ������ �����
			if (TileMap[i][j] == 'm') {// ���� ��������� �������

				Floor* floor = new Floor(Vector2f(j * 60, i * 60), "images/floor.png");// �������� ���

				entities.push_back(floor);// ������� ��� � ������ 

				Money* money = new Money(Vector2f(j * 60, i * 60), "images/coin.png");// �������� �������

				entities.push_back(money);// ������� � � ������

			}

			if (TileMap[i][j] == 'g') {// ���� ��������� ��� 

				Floor* floor = new Floor(Vector2f(j * 60, i * 60), "images/floor.png");// ������ ���

				entities.push_back(floor);// ��������� ��� � ������

			}
			if (TileMap[i][j] == 'k') {// ���� ��������� ����� 

				Wall* wall = new Wall(Vector2f(j * 60, i * 60), "images/brick.png");// ������ �����

				entities.push_back(wall);//��������� � � ������

			}

		}
	}
}

Map::Map() {

	init();

}

void Map::update() {

	player->update();
	FloatRect playerCollider = player->getSprite().getGlobalBounds();
	for (auto it = entities.begin(); it != entities.end();) {
		FloatRect playerCollider = player->getSprite().getGlobalBounds();
		FloatRect otherCollider = (*it)->getSprite().getGlobalBounds();

		if (playerCollider.intersects(otherCollider) && (*it)->getName() == "money") {// ���� ����� ���������� � �������� 
			entities.erase(it++);//������� �������
		}
		else if (playerCollider.intersects(otherCollider) && (*it)->getName() == "wall") {// ���� ����� ���������� �� ������ 

			player->setSpeed(Vector2f(-player->getSpeed().x, -player->getSpeed().y));// ����������� ������

			player->update();// ��������� �������

			it++;

		}
		else {// ���� �� �� � ��� �� �����������

			it++;// ������� �� ��������� ������ ������

		}

	}
}

Player* Map::getPlayer() {

	return player;

}

void Map::draw(RenderWindow& window) {

	for (auto it = entities.begin(); it != entities.end(); it++) {// ���� �� ������� �������� 
		window.draw((*it)->getSprite());
	}

	window.draw(player->getSprite());

}