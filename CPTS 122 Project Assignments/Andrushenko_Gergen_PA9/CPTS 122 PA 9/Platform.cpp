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

#include "Platform.h"

/*************************************************************
* Function: Platform()
* Date Created: 12/03/2016
* Date Last Modified: 12/03/2016
* Description: Constructor for Platform
* Input parameters: sf::Texture* texture, sf::Vector2f size, sf::Vector2f position
* Returns: N/A
* Preconditions: Collidable Class must be created
* Postconditions: N/A
*************************************************************/
Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);

}

/*************************************************************
* Function: ~Platform()
* Date Created: 12/03/2016
* Date Last Modified: 12/03/2016
* Description: Destructor for Platform
* Input parameters: N/A
* Returns: N/A
* Preconditions: Collidable Class must be created
* Postconditions: N/A
*************************************************************/
Platform::~Platform()
{

}

/*************************************************************
* Function: Platform()
* Date Created: 12/03/2016
* Date Last Modified: 12/03/2016
* Description: Checks if the platform is Colliding with an Entity
* Input parameters: N/A
* Returns: Collidable(body)
* Preconditions: Collidable Class must be created
* Postconditions: N/A
*************************************************************/
Collidable Platform::getCollision()
{
	return Collidable(body);
}

/*************************************************************
* Function: Draw()
* Date Created: 12/03/2016
* Date Last Modified: 12/03/2016
* Description: Makes the Platform visable to the screen
* Input parameters: sf::RenderWindow& window
* Returns: N/A
* Preconditions: Collidable Class must be created
* Postconditions: N/A
*************************************************************/
void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}