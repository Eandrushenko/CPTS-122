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
#include <iostream>

class Collidable
{
	public:
		//Constructor
		Collidable(sf::RectangleShape& body);

		//Destructor
		~Collidable();

		void move(float dx, float dy);

		bool checkCollision(Collidable& other, float push);

		//Getters
		sf::Vector2f getCenterPosition();
		sf::Vector2f getHalfSize();

	protected:
		sf::RectangleShape& mBody;
};