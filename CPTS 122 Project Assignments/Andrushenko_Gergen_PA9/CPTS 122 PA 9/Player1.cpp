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

#include "Player1.h"

/*************************************************************
* Function: Player1()
* Date Created: 12/05/2016
* Date Last Modified: 12/05/2016
* Description: Constructor for Player1
* Input parameters: N/A
* Returns: N/A
* Preconditions: Collidable Class must be created, Entity class Created
* Postconditions: N/A
*************************************************************/
Player1::Player1(void)
{
	mBody.setTexture(nullptr);
	mSpeed = 0.1f;
	mBody.setSize(sf::Vector2f(50.0f, 50.0f));
	mBody.setPosition(sf::Vector2f(250.0f, 300.0f));
	health = 5;
}

/*************************************************************
* Function: ~Player1()
* Date Created: 12/05/2016
* Date Last Modified: 12/05/2016
* Description: Destructor for Player1
* Input parameters: N/A
* Returns: N/A
* Preconditions: Collidable Class must be created, Entity class Created
* Postconditions: N/A
*************************************************************/
Player1::~Player1()
{

}

/*************************************************************
* Function: Draw()
* Date Created: 12/05/2016
* Date Last Modified: 12/05/2016
* Description: Makes Player1 visable to the window
* Input parameters: RenderWindow& window
* Returns: N/A
* Preconditions: Collidable Class must be created, Entity class Created
* Postconditions: N/A
*************************************************************/
void Player1::Draw(sf::RenderWindow& window)
{
	window.draw(mBody);
}

/*************************************************************
* Function: move()
* Date Created: 12/05/2016
* Date Last Modified: 12/05/2016
* Description: This function allows a user to control where the Player1 will be
* Input parameters: N/A
* Returns: N/A
* Preconditions: Collidable Class must be created, Entity class Created
* Postconditions: N/A
*************************************************************/
void Player1::move()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		mBody.move(-mSpeed, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		mBody.move(mSpeed, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		mBody.move(0.0f, -0.1f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		mBody.move(0.0f, 0.1f);
	}

}


/*************************************************************
* Function: getCollision()
* Date Created: 12/05/2016
* Date Last Modified: 12/05/2016
* Description: Checks if the Player1 is touching a Platform
* Input parameters: N/A
* Returns: Collidable(mBody)
* Preconditions: Collidable Class must be created, Entity class Created
* Postconditions: N/A
*************************************************************/
Collidable Player1::getCollision()
{
	return Collidable(mBody);
}

/*************************************************************
* Function: shoot()
* Date Created: 12/05/2016
* Date Last Modified: 12/05/2016
* Description: Sends Shot object to a position based on the mBody of Player1 and the position of the Shot objects
* Input parameters: Shot &bullet0, Shot &bullet1, Shot &bullet2
* Returns: N/A
* Preconditions: Collidable Class must be created, Shot Class must be Created, Entity class Created
* Postconditions: N/A
*************************************************************/
void Player1::shoot(Shot &bullet0, Shot &bullet1, Shot &bullet2)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		if ((bullet0.getX() > 1000) && (bullet1.getX() > 1000) && (bullet2.getX() > 1000))
		{
			bullet0.setPosition(mBody.getPosition() + sf::Vector2f(40.0f, 0.0f));
			bullet1.setPosition(mBody.getPosition() + sf::Vector2f(40.0f, 20.0f));
			bullet2.setPosition(mBody.getPosition() + sf::Vector2f(40.0f, 40.0f));
		}
	}
}

/*************************************************************
* Function: hitCheck()
* Date Created: 12/05/2016
* Date Last Modified: 12/05/2016
* Description: Checks if bullet objects are in the same position as the mBody of Player1, and removes health and relocates the Shot object if they are in the same position
* Input parameters: Shot &bullet0, Shot &bullet1, Shot &bullet2
* Returns: N/A
* Preconditions: Collidable Class must be created, Shot Class must be created, Entity class Created
* Postconditions: N/A
*************************************************************/
void Player1::hitCheck(Shot &bullet0, Shot &bullet1, Shot &bullet2)
{
	if (((mBody.getPosition().x <= bullet0.getX()) && (bullet0.getX() <= (mBody.getPosition().x + mBody.getSize().x))) && ((mBody.getPosition().y <= bullet0.getY()) && (bullet0.getY() <= (mBody.getPosition().y + mBody.getSize().y))))
	{
		health -= 1;
		bullet0.setPosition(sf::Vector2f(0.0f, 500.0f));
	}
	if (((mBody.getPosition().x <= bullet1.getX()) && (bullet1.getX() <= (mBody.getPosition().x + mBody.getSize().x))) && ((mBody.getPosition().y <= bullet1.getY()) && (bullet1.getY() <= (mBody.getPosition().y + mBody.getSize().y))))
	{
		health -= 1;
		bullet1.setPosition(sf::Vector2f(0.0f, 500.0f));
	}
	if (((mBody.getPosition().x <= bullet2.getX()) && (bullet2.getX() <= (mBody.getPosition().x + mBody.getSize().x))) && ((mBody.getPosition().y <= bullet2.getY()) && (bullet2.getY() <= (mBody.getPosition().y + mBody.getSize().y))))
	{
		health -= 1;
		bullet2.setPosition(sf::Vector2f(0.0f, 0.0f));
	}

}

/*************************************************************
* Function: healthCheck()
* Date Created: 12/05/2016
* Date Last Modified: 12/05/2016
* Description: Checks the health and sets the image of mBody based on the health, returns health
* Input parameters: sf::Texture* texture5, sf::Texture* texture4, sf::Texture* texture3, sf::Texture* texture2, sf::Texture* texture1
* Returns: health
* Preconditions: Collidable Class must be created, Shot Class must be created, Entity class Created
* Postconditions: N/A
*************************************************************/
int Player1::healthCheck(sf::Texture* texture5, sf::Texture* texture4, sf::Texture* texture3, sf::Texture* texture2, sf::Texture* texture1)
{
	if (health == 5)
	{
		mBody.setTexture(texture5);
	}
	if (health == 4)
	{
		mBody.setTexture(texture4);
	}
	if (health == 3)
	{
		mBody.setTexture(texture3);
	}
	if (health == 2)
	{
		mBody.setTexture(texture2);
	}
	if (health == 1)
	{
		mBody.setTexture(texture1);
	}
	return health;
}