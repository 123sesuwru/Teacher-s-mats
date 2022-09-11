#include "Map.h"
#include "Floor.h"   
#include "Money.h"
#include "Wall.h"

void Map::init() {

	player = new Player(Vector2f(70, 70), "images/player1.png");

	for (int i = 0; i < HEIGHT_MAP; i++) {

		for (int j = 0; j < WIDTH_MAP; j++) {

			if (TileMap[i][j] == 'm') {

				Floor* floor = new Floor(Vector2f(j*60, i*60), "images/floor.png");

				entities.push_back(floor);

				Money* money = new Money(Vector2f(j*60 , i*60), "images/coin.png");

				entities.push_back(money);

			}

			if (TileMap[i][j] == 'g') {

				Floor* floor = new Floor(Vector2f(j*60, i*60), "images/floor.png");

				entities.push_back(floor);

			}

			if (TileMap[i][j] == 'k') {

				Wall* wall= new Wall(Vector2f(j*60, i*60), "images/brick.png");

				entities.push_back(wall);

			}

			mapSprite.setPosition(j * 60, i * 60);

			window.draw(mapSprite);

		}

	}

}

Map::Map() {

	init();

}

void Map::update() {

	player->update();

}

Player* Map::getPlayer() {

	return player;

}

void Map::draw(RenderWindow& window) {

	for (auto it = entities.begin(); it != entities.end();it++){
		window.draw((*it)->getSprite());
	}

	/*for (int i = 0; i < HEIGHT_MAP; i++) {

		for (int j = 0; j < WIDTH_MAP; j++) {

			if (TileMap[i][j] == 's') {

				mapSprite.setTextureRect(IntRect(0, 0, 60, 60));

			}

			if (TileMap[i][j] == 'g') {

				mapSprite.setTextureRect(IntRect(60 * 0, 60 * 1, 60, 60));

			}

			mapSprite.setPosition(j * 60, i * 60);

			window.draw(mapSprite);

		}

	}*/
	window.draw(coin->getSprite());//��������� �������

	window.draw(player->getSprite());// ��������� ������

}