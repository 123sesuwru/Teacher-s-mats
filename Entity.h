#pragma once // ���������� ��������� 
#include <SFML/Graphics.hpp>// ����������� sfml 
using namespace sf;// ������������� ������������ ��� sf 
class Entity {// ������� ����� ������� �������� 

protected:// ����������� � �������� ������ ��� ����������� 

	Vector2f position;//������� ������� �������� 
	Sprite sprite;// ������ ������� ��������
	Texture texture;// �������� ������� �������� 
	int width;// ������ ������� �������� 
	int height;// ������ ������� ��������
	String imagePath;// ���� � �������� 
	String name;
	virtual void init();// ����� ��������� ��������� ������� �������� 

public://��������� ����������� �������

	Entity(String imagePath);// ����������� ������ 
	void setName(String name);
	String getName();
	void setPosition(Vector2f position);// ������ ������� ������� �������� 
	void setTextureRect(IntRect rect);//������ �������� ������� �������� 
	void setWidth(int width);// ������ ������ ������� ��������
	void setHeight(int height);//������ ������ ������� �������� 
	void setImagePath(String imagePath);// ������ ���� � �������� ������� �������� 
	Vector2f getPosition();// �������� ������� ������� �������� 
	Sprite getSprite();// �������� ������ ������� ��������
	int getWidth();// �������� ������ ������� ��������
	int getHeight();// �������� ������ ������� �������� 
	String getImagePath();// �������� ���� � �������� ������� ��������

};