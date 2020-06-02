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

#include "Shot.h"

/*************************************************************
* Function: Shot()
* Date Created: 12/04/2016
* Date Last Modified: 12/04/2016
* Description: Constructor for the Shot class
* Input parameters: sf::Texture* texture, float velocity, sf::Vector2f position
* Returns: N/A
* Preconditions: N/A
* Postconditions: N/A
*************************************************************/
Shot::Shot(sf::Texture* texture, float velocity, sf::Vector2f position)
{
	mVelocity = velocity;
	mBody.setSize(sf::Vector2f(10.0f, 10.0f));
	mBody.setFillColor(sf::Color::Black);
	mBody.setTexture(texture);
	mBody.setPosition(position);
}

/*************************************************************
* Function: ~Shot()
* Date Created: 12/04/2016
* Date Last Modified: 12/04/2016
* Description: Destructor for the Shot class
* Input parameters: N/A
* Returns: N/A
* Preconditions: N/A
* Postconditions: N/A
*************************************************************/
Shot::~Shot()
{

}

/*************************************************************
* Function: setPosition()
* Date Created: 12/04/2016
* Date Last Modified: 12/04/2016
* Description: Designates a position 
* Input parameters: sf::Vector2f position
* Returns: N/A
* Preconditions: N/A
* Postconditions: N/A
*************************************************************/
void Shot::setPosition(sf::Vector2f position)
{
	mBody.setPosition(position);
}

/*************************************************************
* Function: getX()
* Date Created: 12/04/2016
* Date Last Modified: 12/04/2016
* Description: returns the X-coordinates of the Shot's mBody
* Input parameters: N/A
* Returns: mBody.getPosition().x
* Preconditions: N/A
* Postconditions: N/A
*************************************************************/
float Shot::getX()
{
	return mBody.getPosition().x;
}

/*************************************************************
* Function: getY()
* Date Created: 12/04/2016
* Date Last Modified: 12/04/2016
* Description: returns the Y-coordinates of the Shot's mBody
* Input parameters: N/A
* Returns: mBody.getPosition().y
* Preconditions: N/A
* Postconditions: N/A
*************************************************************/
float Shot::getY()
{
	return mBody.getPosition().y;
}

/*************************************************************
* Function: getsizeY()
* Date Created: 12/04/2016
* Date Last Modified: 12/04/2016
* Description: returns the size of mBody
* Input parameters: N/A
* Returns: mBody.getSize().y
* Preconditions: N/A
* Postconditions: N/A
*************************************************************/
float Shot::getsizeY()
{
	return mBody.getSize().y;
}

/*************************************************************
* Function: getsizeX()
* Date Created: 12/04/2016
* Date Last Modified: 12/04/2016
* Description: returns the size of mBody
* Input parameters: N/A
* Returns: mBody.getSize().x
* Preconditions: N/A
* Postconditions: N/A
*************************************************************/
float Shot::getsizeX()
{
	return mBody.getSize().x;
}

/*************************************************************
* Function: setX()
* Date Created: 12/04/2016
* Date Last Modified: 12/04/2016
* Description: Relocates the x-Position of mBody 
* Input parameters: float xPos
* Returns: N/A
* Preconditions: N/A
* Postconditions: N/A
*************************************************************/
void Shot::setX(float xPos)
{
	mBody.setPosition(xPos, 0.0f);
}

/*************************************************************
* Function: move()
* Date Created: 12/04/2016
* Date Last Modified: 12/04/2016
* Description: Makes the mBody move at a constant speed
* Input parameters: N/A
* Returns: N/A
* Preconditions: N/A
* Postconditions: N/A
*************************************************************/
void Shot::move()
{
	mBody.move(mVelocity, 0.0f);
}

/*************************************************************
* Function: move2()
* Date Created: 12/04/2016
* Date Last Modified: 12/04/2016
* Description: Makes the mBody move at a constant speed ion the opposite direction
* Input parameters: N/A
* Returns: N/A
* Preconditions: N/A
* Postconditions: N/A
*************************************************************/
void Shot::move2()
{
	mBody.move(-mVelocity, 0.0f);
}

/*************************************************************
* Function: draw()
* Date Created: 12/04/2016
* Date Last Modified: 12/04/2016
* Description: Makes the Object visable to the screen
* Input parameters: sf::RanderWindow& window
* Returns: N/A
* Preconditions: N/A
* Postconditions: N/A
*************************************************************/
void Shot::draw(sf::RenderWindow& window)
{
	window.draw(mBody);
}

/*************************************************************
* Function: getCollision()
* Date Created: 12/04/2016
* Date Last Modified: 12/04/2016
* Description: Checks if the object is colliding with a Platform object
* Input parameters: N/A
* Returns: Collidable(mBody)
* Preconditions: Collidable object must exist
* Postconditions: N/A
*************************************************************/
Collidable Shot::getCollision()
{
	return Collidable(mBody);
}