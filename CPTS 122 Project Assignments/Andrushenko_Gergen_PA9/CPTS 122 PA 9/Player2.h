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

#include "Entity.h"


class Player2 : public Entity
{
	public:
		//Default Constructor
		Player2(void);

		//Destructor
		~Player2();

		virtual void Player2::Draw(sf::RenderWindow& window);

		virtual void move();

		virtual void shoot(Shot &bullet0, Shot &bullet1, Shot &bullet2);

		virtual Collidable getCollision();

		virtual void hitCheck(Shot &bullet0, Shot &bullet1, Shot &bullet2);

		int healthCheck(sf::Texture* texture5, sf::Texture* texture4, sf::Texture* texture3, sf::Texture* texture2, sf::Texture* texture1);
};
