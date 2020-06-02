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

#include "Entity.h"

/*************************************************************
* Function: Entity()
* Date Created: 12/03/2016
* Date Last Modified: 12/03/2016
* Description: Constructor for Entity
* Input parameters: N/A
* Returns: N/A
* Preconditions: Collidable Class must be created
* Postconditions: N/A
*************************************************************/
Entity::Entity(void)
{
	mBody.setTexture(nullptr);
	mSpeed = 0.1f;
	mBody.setSize(sf::Vector2f(50.0f, 50.0f));
	health = 5;
}

/*************************************************************
* Function: ~Entity()
* Date Created: 12/03/2016
* Date Last Modified: 12/03/2016
* Description: Destructor for Entity
* Input parameters: N/A
* Returns: N/A
* Preconditions: Collidable Class must be created
* Postconditions: N/A
*************************************************************/
Entity::~Entity()
{

}

/*************************************************************
* Function: Draw()
* Date Created: 12/03/2016
* Date Last Modified: 12/03/2016
* Description: Makes Entity visable to the window
* Input parameters: RenderWindow& window
* Returns: N/A
* Preconditions: Collidable Class must be created
* Postconditions: N/A
*************************************************************/
void Entity::Draw(sf::RenderWindow& window)
{
	window.draw(mBody);
}

/*************************************************************
* Function: move()
* Date Created: 12/03/2016
* Date Last Modified: 12/03/2016
* Description: This function allows a user to control where the Entity will be
* Input parameters: N/A
* Returns: N/A
* Preconditions: Collidable Class must be created
* Postconditions: N/A
*************************************************************/
void Entity::move()
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
* Date Created: 12/03/2016
* Date Last Modified: 12/03/2016
* Description: Checks if the Entity is touching a Platform
* Input parameters: N/A
* Returns: Collidable(mBody)
* Preconditions: Collidable Class must be created
* Postconditions: N/A
*************************************************************/
Collidable Entity::getCollision()
{
	return Collidable(mBody);
}

/*************************************************************
* Function: shoot()
* Date Created: 12/04/2016
* Date Last Modified: 12/04/2016
* Description: Sends Shot object to a position based on the mBody of Entity and the position of the Shot objects
* Input parameters: Shot &bullet0, Shot &bullet1, Shot &bullet2
* Returns: N/A
* Preconditions: Collidable Class must be created, Shot Class must be Created
* Postconditions: N/A
*************************************************************/
void Entity::shoot(Shot &bullet0, Shot &bullet1, Shot &bullet2)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Slash) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Divide))
	{
		if ((bullet0.getX() < 0) && (bullet1.getX() < 0) && (bullet2.getX() < 0))
		{
			bullet0.setPosition(mBody.getPosition());
			bullet1.setPosition(mBody.getPosition() - sf::Vector2f(0.0f, 25.0f));
			bullet2.setPosition(mBody.getPosition() - sf::Vector2f(0.0f, 50.0f));
		}
	}
}

/*************************************************************
* Function: hitCheck()
* Date Created: 12/04/2016
* Date Last Modified: 12/04/2016
* Description: Checks if bullet objects are in the same position as the mBody of entity, and removes health and relocates the Shot object if they are in the same position
* Input parameters: Shot &bullet0, Shot &bullet1, Shot &bullet2
* Returns: N/A
* Preconditions: Collidable Class must be created, Shot Class must be created
* Postconditions: N/A
*************************************************************/
void Entity::hitCheck(Shot &bullet0, Shot &bullet1, Shot &bullet2)
{
	if (((mBody.getPosition().x < bullet0.getX()) && (bullet0.getX() < (mBody.getPosition().x + mBody.getSize().x))) && ((mBody.getPosition().y < bullet0.getY()) && (bullet0.getY() < (mBody.getPosition().y + mBody.getSize().y))))
	{
		health -= 1;
		bullet0.setPosition(sf::Vector2f(-50.0f, 0.0f));
	}
	if (((mBody.getPosition().x < bullet1.getX()) && (bullet1.getX() < (mBody.getPosition().x + mBody.getSize().x))) && ((mBody.getPosition().y < bullet1.getY()) && (bullet1.getY() < (mBody.getPosition().y + mBody.getSize().y))))
	{
		health -= 1;
		bullet1.setPosition(sf::Vector2f(-50.0f, 0.0f));
	}
	if (((mBody.getPosition().x < bullet2.getX()) && (bullet2.getX() < (mBody.getPosition().x + mBody.getSize().x))) && ((mBody.getPosition().y < bullet2.getY()) && (bullet2.getY() < (mBody.getPosition().y + mBody.getSize().y))))
	{
		health -= 1;
		bullet2.setPosition(sf::Vector2f(-50.0f, 0.0f));
	}
	
}

/*************************************************************
* Function: healthCheck()
* Date Created: 12/04/2016
* Date Last Modified: 12/04/2016
* Description: Checks the health and sets the image of mBody based on the health, returns health
* Input parameters: sf::Texture* texture5, sf::Texture* texture4, sf::Texture* texture3, sf::Texture* texture2, sf::Texture* texture1
* Returns: health
* Preconditions: Collidable Class must be created, Shot Class must be created
* Postconditions: N/A
*************************************************************/
int Entity::healthCheck(sf::Texture* texture5, sf::Texture* texture4, sf::Texture* texture3, sf::Texture* texture2, sf::Texture* texture1)
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
