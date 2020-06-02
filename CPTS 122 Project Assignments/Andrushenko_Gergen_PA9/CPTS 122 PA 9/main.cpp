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



#include <SFML/Graphics.hpp>
#include <iostream>
#include "Platform.h"
#include "Entity.h"
#include "Player1.h"
#include "Player2.h"

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	int trash;

	//Title Menu
	cout << "Boat Wars!" << endl;
	cout << "Player on the left: WASD to move and space bar to fire" << endl;
	cout << "Player on the right: Arrow keys to move and press the slash / to fire" << endl;

	system("pause");
	system("cls");

	//Images being loaded
	sf::Texture p1t5, p1t4, p1t3, p1t2, p1t1;
	sf::Texture p2t5, p2t4, p2t3, p2t2, p2t1;

	p1t5.loadFromFile("LeftBoat5.png");
	p2t5.loadFromFile("RightBoat5.png");
	p1t4.loadFromFile("LeftBoat4.png");
	p2t4.loadFromFile("RightBoat4.png");
	p1t3.loadFromFile("LeftBoat3.png");
	p2t3.loadFromFile("RightBoat3.png");
	p1t2.loadFromFile("LeftBoat2.png");
	p2t2.loadFromFile("RightBoat2.png");
	p1t1.loadFromFile("LeftBoat1.png");
	p2t1.loadFromFile("RightBoat1.png");

	sf::RenderWindow window(sf::VideoMode(1000, 600), "Boat War", sf::Style::Close | sf::Style::Titlebar);

	//PolyMorphism
	Entity *p1, *p2;
	p1 = new Player1;
	p2 = new Player2;

	//Boundary Walls of the Game
	Platform barrier0(nullptr, sf::Vector2f(5.0f, 1000.0f), sf::Vector2f(400.0f, 700.0f));
	Platform barrier1(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(0.0f, -45.0f));
	Platform barrier2(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, -45.0f));
	Platform barrier3(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(200.0f, -45.0f));
	Platform barrier4(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(300.0f, -45.0f));
	Platform barrier5(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(400.0f, -45.0f));
	Platform barrier6(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(500.0f, -45.0f));
	Platform barrier7(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(600.0f, -45.0f));
	Platform barrier8(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(700.0f, -45.0f));
	Platform barrier9(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(800.0f, -45.0f));
	Platform barrier10(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(900.0f, -45.0f));
	Platform barrier11(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1000.0f, -45.0f));
	Platform barrier12(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(0.0f, 645.0f));
	Platform barrier13(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 645.0f));
	Platform barrier14(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(200.0f, 645.0f));
	Platform barrier15(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(300.0f, 645.0f));
	Platform barrier16(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(400.0f, 645.0f));
	Platform barrier17(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(500.0f, 645.0f));
	Platform barrier18(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(600.0f, 645.0f));
	Platform barrier19(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(700.0f, 645.0f));
	Platform barrier20(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(800.0f, 645.0f));
	Platform barrier21(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(900.0f, 645.0f));
	Platform barrier22(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1000.0f, 645.0f));
	Platform barrier23(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(-45.0f, 0.0f));
	Platform barrier24(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(-45.0f, 100.0f));
	Platform barrier25(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(-45.0f, 200.0f));
	Platform barrier26(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(-45.0f, 300.0f));
	Platform barrier27(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(-45.0f, 400.0f));
	Platform barrier28(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(-45.0f, 500.0f));
	Platform barrier29(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(-45.0f, 600.0f));
	Platform barrier30(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1045.0f, 0.0f));
	Platform barrier31(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1045.0f, 100.0f));
	Platform barrier32(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1045.0f, 200.0f));
	Platform barrier33(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1045.0f, 300.0f));
	Platform barrier34(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1045.0f, 400.0f));
	Platform barrier35(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1045.0f, 500.0f));
	Platform barrier36(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1045.0f, 600.0f));


	//Bullet objects
	Shot bullet0(nullptr, 0.5f, sf::Vector2f(1000.0f, 500.0f));
	Shot bullet1(nullptr, 0.5f, sf::Vector2f(1000.0f, 500.0f));
	Shot bullet2(nullptr, 0.5f, sf::Vector2f(1000.0f, 500.0f));
	Shot bullet3(nullptr, 0.5f, sf::Vector2f(0.0f, 500.0f));
	Shot bullet4(nullptr, 0.5f, sf::Vector2f(0.0f, 500.0f));
	Shot bullet5(nullptr, 0.5f, sf::Vector2f(0.0f, 500.0f));




	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		//Move functions
		p1->move();
		p2->move();

		//Set direction of the bullets
		bullet0.move();
		bullet1.move();
		bullet2.move();
		bullet3.move2();
		bullet4.move2();
		bullet5.move2();

		//Check the health and change the images of the objects
		p1->healthCheck(&p1t5, &p1t4, &p1t3, &p1t2, &p1t1);
		p2->healthCheck(&p2t5, &p2t4, &p2t3, &p2t2, &p2t1);

		//Checks if Shot object collide with Entities
		p1->hitCheck(bullet3, bullet4, bullet5);
		p2->hitCheck(bullet0, bullet1, bullet2);

		//Checks if the players are shooting Bullets
		p1->shoot(bullet0, bullet1, bullet2);
		p2->shoot(bullet3, bullet4, bullet5);


		//Checks if the health of the Entities are 0
		if (p1->healthCheck(&p1t5, &p1t4, &p1t3, &p1t2, &p1t1) <= 0)
		{
			window.close();
			cout << "Right Boat Wins!" << endl << "Game Over!" << endl;
			cin >> trash;
		}
		else if (p2->healthCheck(&p2t5, &p2t4, &p2t3, &p2t2, &p2t1) <= 0)
		{
			window.close();
			cout << "Left Boat Wins!" << endl << "Game Over!" << endl;
			cin >> trash;
		}
		
		//Checks if the Players are colliding with the players
		barrier0.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier0.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier1.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier1.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier2.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier2.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier3.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier3.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier4.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier4.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier5.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier5.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier6.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier6.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier7.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier7.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier8.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier8.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier9.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier9.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier10.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier10.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier11.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier11.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier12.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier12.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier13.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier13.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier14.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier14.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier15.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier15.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier16.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier16.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier17.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier17.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier18.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier18.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier19.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier19.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier20.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier20.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier21.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier21.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier22.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier22.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier23.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier23.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier24.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier24.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier25.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier25.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier26.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier26.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier27.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier27.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier28.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier28.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier29.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier29.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier30.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier30.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier31.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier31.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier32.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier32.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier33.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier33.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier34.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier34.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier35.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier35.getCollision().checkCollision(p2->getCollision(), 1.0f);
		barrier36.getCollision().checkCollision(p1->getCollision(), 1.0f);
		barrier36.getCollision().checkCollision(p2->getCollision(), 1.0f);

		//Update the window
		window.clear(sf::Color::Blue);

		//Displays the Players and the bullets to the window
		p1->Draw(window);
		p2->Draw(window);

		bullet0.draw(window);
		bullet1.draw(window);
		bullet2.draw(window);
		bullet3.draw(window);
		bullet4.draw(window);
		bullet5.draw(window);

		window.display();

	}

	return 0;
}
