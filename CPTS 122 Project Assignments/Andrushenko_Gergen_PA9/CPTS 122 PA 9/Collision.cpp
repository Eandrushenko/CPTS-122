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
12/06/2016 General Touch ups in Main and Graphics added.

*******************************************************************************************/


#include "Collision.h"

/*************************************************************
* Function: Collidable()
* Date Created: 12/03/2016
* Date Last Modified: 12/03/2016
* Description: Constructor for Collidable
* Input parameters: sf::RectangleShape& body
* Returns: N/A
* Preconditions: N/A
* Postconditions: Entity Class must be Created
*************************************************************/
Collidable::Collidable(sf::RectangleShape& body) : mBody(body)
{

}

/*************************************************************
* Function: ~Collidable()
* Date Created: 12/03/2016
* Date Last Modified: 12/03/2016
* Description: Destructor for Collidable
* Input parameters: N/A
* Returns: N/A
* Preconditions: N/A
* Postconditions: Entity Class must be Created
*************************************************************/
Collidable::~Collidable()
{

}

/*************************************************************
* Function: move()
* Date Created: 12/03/2016
* Date Last Modified: 12/03/2016
* Description: move function for the Collidable
* Input parameters: float dx, float dy
* Returns: N/A
* Preconditions: N/A
* Postconditions: Entity Class must be Created
*************************************************************/
void Collidable::move(float dx, float dy)
{
	mBody.move(dx, dy);
}

/*************************************************************
* Function: GetCenterPosition()
* Date Created: 12/03/2016
* Date Last Modified: 12/03/2016
* Description: Finds the Center Position of mBody
* Input parameters: N/A
* Returns: this->mBody.getPosition() - this->getHalfSize()
* Preconditions: N/A
* Postconditions: Entity Class must be Created
*************************************************************/
sf::Vector2f Collidable::getCenterPosition()
{
	return this->mBody.getPosition() - this->getHalfSize();
}



/*************************************************************
* Function: getHalfSize()
* Date Created: 12/03/2016
* Date Last Modified: 12/03/2016
* Description: Function that helps find the middle of mBody
* Input parameters: N/A
* Returns: N/A
* Preconditions: N/A
* Postconditions: Entity Class must be Created
*************************************************************/
sf::Vector2f Collidable::getHalfSize()
{

	return (mBody.getSize() / 2.0f);
}

/*************************************************************
* Function: checkCollision()
* Date Created: 12/03/2016
* Date Last Modified: 12/03/2016
* Description: This checks if mBody of Entity is in the same area as the mBody of Platform
* Input parameters: Collidable& other, float push
* Returns: bool hasCollided
* Preconditions: N/A
* Postconditions: Entity Class must be Created
*************************************************************/
bool Collidable::checkCollision(Collidable& other, float push)
{

	bool hasCollided = false;

	push = std::min(std::max(push, 0.0f), 1.0f);

	sf::Vector2f otherPosition = other.getCenterPosition();
	sf::Vector2f otherHalfSize = other.getHalfSize();
	sf::Vector2f thisPosition = this->getCenterPosition();
	sf::Vector2f thisHalfSize = this->getHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if ((intersectX <= 0.0f) && (intersectY <= 0.0f))
	{
		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				move(intersectX * (1.0f - push), 0.0f);
				other.move(-intersectX * push, 0.0f);
			}
			else
			{
				move(-intersectX * (1.0f - push), 0.0f);
				other.move(intersectX * push, 0.0f);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				move(0.0f, intersectY * (1.0f - push));
				other.move(0.0f, -intersectY * push);
			}
			else
			{
				move(0.0f, -intersectY * (1.0f - push));
				other.move(0.0f, intersectY * push);
			}
		}
		hasCollided = true;
	}

	return hasCollided;
}