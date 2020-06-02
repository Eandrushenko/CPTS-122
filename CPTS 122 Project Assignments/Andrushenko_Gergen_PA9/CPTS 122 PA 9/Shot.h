/*******************************************************************************************

* Programmer: Elijah Andrushenko, Jake Gergen

* Class: CptS 122, Fall  2016;

* Programming Assignment: PA9

* Date: December 7th, 2016

* Description: This program generates a game called BoatWars.

* History: 12/02/2016 Opened a Window in Main
12/03/2016 Created Entity Base Class, Platform Class, and Collision Class
12/04/2016 Created Shot Class
12/05/2016 Created Player1 and Player2 Classes
12/06/2016 General Touch ups in Main and Graphics added

*******************************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"


class Shot
{
	public:
		//Constructor
		Shot(sf::Texture* texture, float velocity, sf::Vector2f position);

		//Destructor
		~Shot();

		void setPosition(sf::Vector2f position);

		//Getters and Setters
		float getX();

		float getY();

		void setX(float xPos);

		float getsizeY();

		float getsizeX();

		void move();

		void move2();

		void draw(sf::RenderWindow& window);

		Collidable getCollision();


	private:
		sf::RectangleShape mBody;
		float mVelocity;
};
