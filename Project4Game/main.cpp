#include <SFML/Graphics.hpp>
#include<stdio.h>
#include<iostream>
#include<time.h>
//MAP  WEIGHT =1080   HEIGHT=5000;
int j = 0;
int i = 1;
int m = 0;

float speed = 1;
float slowtime = 1;
bool checkslowtime = 0;

int stackshoes = 0;

int scorecoins = 0;
int frame = 0;
int framewater = 0;
int checkcollin = 0;

static const float screenheight = 720.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(screenheight * aspectRatio, screenheight);
}

int main()
{
	srand(time(NULL));

	sf::Vector2i screen(1080, 720);
	sf::RenderWindow window(sf::VideoMode(screen.x, screen.y), "GAME!", sf::Style::Close | sf::Style::Resize);

	sf::RectangleShape player(sf::Vector2f(20.f, 20.f));
	player.setFillColor(sf::Color::Green);

	sf::Vector2f spawnPoint = { 1080 / 2,0.f };
	player.setPosition(spawnPoint);

	sf::RectangleShape white(sf::Vector2f(50.f, 30.f));
	white.setFillColor(sf::Color::White);

	sf::RectangleShape green(sf::Vector2f(50.f, 30.f));
	green.setFillColor(sf::Color::Green);

	sf::RectangleShape red(sf::Vector2f(150.f, 30.f));
	red.setFillColor(sf::Color::Red);

	sf::RectangleShape yellow(sf::Vector2f(70.f, 50.f));
	yellow.setFillColor(sf::Color::Yellow);

	sf::RectangleShape blue(sf::Vector2f(50.f, 30.f));
	blue.setFillColor(sf::Color::Blue);

	sf::RectangleShape purple(sf::Vector2f(10.f, 10.f));
	purple.setFillColor(sf::Color::Magenta);

	sf::RectangleShape purple2(sf::Vector2f(10.f, 10.f));
	purple2.setFillColor(sf::Color::Magenta);

	sf::RectangleShape box(sf::Vector2f(1080.f, 250.f));
	box.setFillColor(sf::Color::Cyan);
	box.setPosition(0, 720 / 2);
	sf::Sprite water;
	sf::Texture texturewater;
	texturewater.loadFromFile("water.png");
	texturewater.setSmooth(true);
	water.setTexture(texturewater);
	water.setTextureRect(sf::IntRect(0, 0, 1080.0f, 250.f));
	water.setPosition(0, 720 / 2);

	sf::RectangleShape boat1(sf::Vector2f(200.f, 62.5f));
	boat1.setFillColor(sf::Color::Red);
	sf::Vector2f posboat[3];
	for (i = 0; i <= 2; i++)
	{
		posboat[i].y = 360;
	}
	posboat[0].x = -200; posboat[1].x = -600; posboat[2].x = -1000;

	sf::RectangleShape boat2(sf::Vector2f(120.f, 62.5f));
	boat2.setFillColor(sf::Color::Blue);
	sf::Vector2f posboat2[3];
	for (i = 0; i <= 2; i++)
	{
		posboat2[i].y = 422.5f;//
	}
	posboat2[0].x = 1080; posboat2[1].x = 1500; posboat2[2].x = 1820;

	sf::RectangleShape boat3(sf::Vector2f(300.f, 62.5f));
	boat3.setFillColor(sf::Color::Black);
	boat3.setPosition(1150, 485.0f);//485.0
	sf::Vector2f posboat3[2];
	for (i = 0; i <= 1; i++)
	{
		posboat3[i].y = 485.0f;//
	}
	posboat3[0].x = -300; posboat3[1].x = -900;

	sf::RectangleShape boat4(sf::Vector2f(225.f, 62.5f));
	boat4.setFillColor(sf::Color::White);
	sf::Vector2f posboat4[2];
	for (i = 0; i <= 1; i++)
	{
		posboat4[i].y = 547.5f;//
	}
	posboat4[0].x = 1200; posboat3[1].x = 2200;

	sf::RectangleShape itemclock(sf::Vector2f(40.f, 40.f));
	sf::Texture textureclock;
	textureclock.loadFromFile("clock.png");
	itemclock.setTexture(&textureclock);
	textureclock.setSmooth(true);
	itemclock.setPosition(rand() % 1050, rand() % 700);
	itemclock.setScale(sf::Vector2f(1.0f, 1.0f));
	sf::Vector2f posclock[3];
	for (i = 0; i <= 2; i++)
	{
		posclock[i].x = rand() % 1000;
		posclock[i].y = rand() % 4900;
	}

	sf::RectangleShape itemboots(sf::Vector2f(40.f, 40.f));
	sf::Texture textureboots;
	textureboots.loadFromFile("boots.png");
	itemboots.setTexture(&textureboots);
	textureboots.setSmooth(true);
	sf::Sprite itemclocksprite;
	sf::Vector2f posboots[2];
	for (i = 0; i <= 1; i++)
	{
		posboots[i].x = rand() % 1000;
		posboots[i].y = rand() % 4900;
	}
	itemboots.setScale(sf::Vector2f(1.1f, 1.1f));

	sf::Sprite itemcoins;
	sf::Texture texturecoins;
	texturecoins.loadFromFile("coinscut.png");
	texturecoins.setSmooth(true);
	itemcoins.setTexture(texturecoins);
	itemcoins.setTextureRect(sf::IntRect(0, 0, 128.f, 129));
	itemcoins.setPosition(50, rand() % 700);
	itemcoins.setScale(sf::Vector2f(0.275f, 0.295f));
	sf::Vector2f poscoins[25];
	for (i = 0; i <= 24; i++)
	{
		poscoins[i].x = rand() % 1000;
		poscoins[i].y = rand() % 4900;
	}

	sf::View view;
	view.reset(sf::FloatRect(0, 0, screen.x, screen.y));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	sf::Vector2f positionview(0, 0);

	window.setFramerateLimit(60);

	bool checksidexci = rand() % 2;
	float xci = 0;
	float yci = rand() % 4801;
	white.setPosition(xci, yci);

	bool checksidexci2 = rand() % 2;
	float xci2 = 0;
	float yci2 = rand() % 4801;
	green.setPosition(xci2, yci2);

	bool checksidexci3 = rand() % 2;
	float xci3 = 0;
	float yci3 = rand() % 4801;
	red.setPosition(xci3, yci3);

	bool checksidexci4 = rand() % 2;
	float xci4 = 0;
	float yci4 = rand() % 4801;
	yellow.setPosition(xci4, yci4);

	sf::Clock clock;
	sf::Time durationslow;
	sf::Clock animationcoin;
	sf::Clock animationwater;

	while (window.isOpen())
	{
		window.clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			}
		}

		//animation coins
		if (animationcoin.getElapsedTime().asSeconds() > 0.2f)
		{
			if (frame <= 5)
			{
				itemcoins.setTextureRect(sf::IntRect(frame * 128.f, 0, 128.f, 129));
				frame++;
				if (frame == 6)
				{
					frame = 0;
				}
			}
			animationcoin.restart();
		}
		//animation water
		if (animationwater.getElapsedTime().asMicroseconds() > 0.0f)
		{
			if (framewater <= 6)
			{
				water.setTextureRect(sf::IntRect(frame * 1080.0f, 0, 1080.f, 250.0f));
				framewater++;
				if (framewater == 7)
				{
					framewater = 0;
				}
			}
			animationwater.restart();
		}

		positionview.y = player.getPosition().y + 10 - (screen.y / 2);
		positionview.x = 0;
		if (positionview.y < 0)
		{
			positionview.y = 0;
		}
		else if (player.getPosition().y >= 4650)
		{
			positionview.y = 4300;
		}
		view.reset(sf::FloatRect(positionview.x, positionview.y, screen.x, screen.y));

		purple.setPosition(0, positionview.y);
		purple2.setPosition(0, positionview.y + 710);

		sf::Vector2f movement(0.f, 0.f);
		//white
		if (checksidexci == 0)
		{
			xci = -50;
			white.move(10.0f * slowtime, 0.0f);
			if (white.getPosition().x >= 1150 && checkcollin != 1)
			{
				checksidexci = rand() % 2;
				yci = rand() % 4801;
				for (j = 0; j != i; )
				{
					if ((yci >= positionview.y) && (yci <= (positionview.y + 710)) && !(yci >= 310 && yci <= 610) && yci > 30)
					{
						white.setPosition(xci, yci);
						break;
					}
					else
					{
						yci = rand() % 4801;
					}
				}
			}
		}
		else if (checksidexci == 1) {
			xci = 1150;
			white.move(-10.0f * slowtime, 0.0f);
			if (white.getPosition().x < -50)
			{
				checksidexci = rand() % 2;
				yci = rand() % 4801;
				for (j = 0; j != i; )
				{
					if ((yci >= positionview.y) && (yci <= (positionview.y + 710)) && !(yci >= 310 && yci <= 610) && yci > 30)
					{
						white.setPosition(xci, yci);
						break;
					}
					else
					{
						yci = rand() % 4801;
					}
				}
			}
		}
		//green
		if (checksidexci2 == 0)
		{
			xci2 = -50;
			green.move(18.0f * slowtime, 0.0f);
			if (green.getPosition().x >= 1150)
			{
				checksidexci2 = rand() % 2;
				yci2 = rand() % 4801;
				for (j = 0; j != i; )
				{
					if ((yci2 >= positionview.y) && (yci2 <= (positionview.y + 710)) && !(yci2 >= 310 && yci2 <= 610) && yci2 > 30)
					{
						green.setPosition(xci2, yci2);
						break;
					}
					else
					{
						yci2 = rand() % 4801;
					}
				}
			}
		}
		else if (checksidexci2 == 1) {
			xci2 = 1150;
			green.move(-18.0f * slowtime, 0.0f);
			if (green.getPosition().x < -50)
			{
				checksidexci2 = rand() % 2;
				yci2 = rand() % 4801;
				for (j = 0; j != i; )
				{
					if ((yci2 >= positionview.y) && (yci2 <= (positionview.y + 710)) && !(yci2 >= 310 && yci2 <= 610) && yci2 > 30)
					{
						green.setPosition(xci2, yci2);
						break;
					}
					else
					{
						yci2 = rand() % 4801;
					}
				}
			}
		}
		//red
		if (checksidexci3 == 0)
		{
			xci3 = -200;
			red.move(15.0f * slowtime, 0.0f);
			if (red.getPosition().x >= 1300)
			{
				checksidexci3 = rand() % 2;
				yci3 = rand() % 4801;
				for (j = 0; j != i; )
				{
					if ((yci3 >= positionview.y) && (yci3 <= (positionview.y + 710)) && !(yci3 >= 310 && yci3 <= 610) && yci3 > 30)
					{
						red.setPosition(xci3, yci3);
						break;
					}
					else
					{
						yci3 = rand() % 4801;
					}
				}
			}
		}
		else if (checksidexci3 == 1) {
			xci3 = 1140;
			red.move(-15.0f * slowtime, 0.0f);
			if (red.getPosition().x < -200)
			{
				checksidexci3 = rand() % 2;
				yci3 = rand() % 4801;
				for (j = 0; j != i; )
				{
					if ((yci3 >= positionview.y) && (yci3 <= (positionview.y + 710)) && !(yci3 >= 310 && yci3 <= 610) && yci3 > 30)
					{
						red.setPosition(xci3, yci3);
						break;
					}
					else
					{
						yci3 = rand() % 4801;
					}
				}
			}
		}
		//yellow
		if (checksidexci4 == 0)
		{
			xci4 = -150;
			yellow.move(13.0f * slowtime, 0.0f);
			if (yellow.getPosition().x >= 1150)
			{
				checksidexci4 = rand() % 2;
				yci4 = rand() % 4801;
				for (j = 0; j != i; )
				{
					if ((yci4 >= positionview.y) && (yci4 <= (positionview.y + 710)) && !(yci4 >= 310 && yci4 <= 610) && yci4 > 30)
					{
						yellow.setPosition(xci4, yci4);
						break;
					}
					else
					{
						yci4 = rand() % 4801;
					}
				}
			}
		}
		else if (checksidexci4 == 1) {
			xci4 = 1140;
			yellow.move(-13.0f * slowtime, 0.0f);
			if (yellow.getPosition().x < -50)
			{
				checksidexci4 = rand() % 2;
				yci4 = rand() % 4801;
				for (j = 0; j != i; )
				{
					if ((yci4 >= positionview.y) && (yci4 <= (positionview.y + 710)) && !(yci4 >= 310 && yci4 <= 610) && yci4 > 30)
					{
						yellow.setPosition(xci4, yci4);
						break;
					}
					else
					{
						yci4 = rand() % 4801;
					}
				}
			}
		}

		//player move  //+ Collinsions *************************************************************
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.f * speed, -5.0f * speed);
			/*if (player.getGlobalBounds().intersects(box.getGlobalBounds()))
			{
				player.move(0.f * speed, +5.0f * speed);
			}*/
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.f * speed, 5.0f * speed);
			/*if (player.getGlobalBounds().intersects(box.getGlobalBounds()))
			{
				player.move(0.f * speed, -5.0f * speed);
			}*/
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.move(-5.0f * speed, 0.0f * speed);
			/*if (player.getGlobalBounds().intersects(box.getGlobalBounds()))
			{
				player.move(+5.0f * speed, 0.0f * speed);
			}*/
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(5.0f * speed, 0.f * speed);
			/*if (player.getGlobalBounds().intersects(box.getGlobalBounds()))
			{
				player.move(-5.0f * speed, 0.0f * speed);
			}*/
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		{
			speed = 1;
			slowtime = 1;
			stackshoes = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
		{
			speed = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			window.close();
		}

		//Collinsions
		/*if (white.getGlobalBounds().intersects(player.getGlobalBounds())) {
			//shape.setPosition(spawnPoint);
			speed -= 0.005;
		}
		if (green.getGlobalBounds().intersects(player.getGlobalBounds())) {
			//shape.setPosition(spawnPoint);
			speed -= 0.005;
		}
		if (red.getGlobalBounds().intersects(player.getGlobalBounds())) {
			player.setPosition(spawnPoint);
			//speed -= 0.1;
		}
		if (yellow.getGlobalBounds().intersects(player.getGlobalBounds())) {
			//shape.setPosition(spawnPoint);
			speed -= 0.005;
		}*/

		//Water DAMMMM
		bool checkCol = 0;
		/*if (player.getGlobalBounds().intersects(box.getGlobalBounds()))
		{
			for (i = 0; i <= 2; i++)
			{
				if (((player.getPosition().x + player.getSize().x > posboat[i].x) && (player.getPosition().x < posboat[i].x + boat1.getSize().x)        // player's horizontal range can touch the platform
					&& (player.getPosition().y + player.getSize().y > posboat[i].y) && (player.getPosition().y < posboat[i].y + boat1.getSize().y)))// player's vertical   range can touch the platform
				{
					checkCol = 1;
					player.move(2.2f, 0.0f);
					break;
				}
				if (((player.getPosition().x + player.getSize().x > posboat2[i].x) && (player.getPosition().x < posboat2[i].x + boat2.getSize().x)        // player's horizontal range can touch the platform
					&& (player.getPosition().y + player.getSize().y > posboat2[i].y) && (player.getPosition().y < posboat2[i].y + boat2.getSize().y)))// player's vertical   range can touch the platform
				{
					checkCol = 1;
					player.move(-4.5f, 0.0f);
					break;
				}
				if (((player.getPosition().x + player.getSize().x > posboat3[i].x) && (player.getPosition().x < posboat3[i].x + boat3.getSize().x)        // player's horizontal range can touch the platform
					&& (player.getPosition().y + player.getSize().y > posboat3[i].y) && (player.getPosition().y < posboat3[i].y + boat3.getSize().y)))// player's vertical   range can touch the platform
				{
					checkCol = 1;
					player.move(3.5f, 0.0f);
					break;
				}
				if (((player.getPosition().x + player.getSize().x > posboat4[i].x) && (player.getPosition().x < posboat4[i].x + boat4.getSize().x)        // player's horizontal range can touch the platform
					&& (player.getPosition().y + player.getSize().y > posboat4[i].y) && (player.getPosition().y < posboat4[i].y + boat4.getSize().y)))// player's vertical   range can touch the platform
				{
					checkCol = 1;
					player.move(-4.5f, 0.0f);
					break;
				}
			}
			if (checkCol != 1) {
				player.setPosition(spawnPoint);
			}
		}*/

		//itemclock
		for (i = 0; i <= 2; i++)
		{
			if ((player.getPosition().x + player.getSize().x > posclock[i].x) && (player.getPosition().x < posclock[i].x + itemclock.getSize().x)        // player's horizontal range can touch the platform
				&& (player.getPosition().y + player.getSize().y > posclock[i].y) && (player.getPosition().y < posclock[i].y + itemclock.getSize().y))// player's vertical   range can touch the platform
			{
				slowtime = 0.1;
				checkslowtime = 1;
				clock.restart();
				posclock[i].x = rand() % 1000;
				posclock[i].y = rand() % 4900;
			}
		}
		if (checkslowtime == 1)
		{
			durationslow = clock.getElapsedTime();
			printf("%f\n", durationslow.asSeconds());
			if (durationslow.asSeconds() > 2.36363)
			{
				slowtime = 1;
				checkslowtime = 0;
			}
		}

		//itemboots
		for (i = 0; i <= 1; i++)
		{
			if ((player.getPosition().x + player.getSize().x > posboots[i].x) && (player.getPosition().x < posboots[i].x + itemboots.getSize().x)        // player's horizontal range can touch the platform
				&& (player.getPosition().y + player.getSize().y > posboots[i].y) && (player.getPosition().y < posboots[i].y + itemboots.getSize().y))// player's vertical   range can touch the platform
			{
				if (stackshoes >= 6)
				{
					speed += 0;
				}
				else
				{
					stackshoes += 1;
					speed += 0.12;
				}
				posboots[i].x = rand() % 1000;
				posboots[i].y = rand() % 4900;
			}
		}
		//printf("%f\n", slowtime);
		//itemcoins
		for (i = 0; i <= 24; i++)
		{
			if ((player.getPosition().x + player.getSize().x > poscoins[i].x) && (player.getPosition().x < poscoins[i].x + 30)
				&& (player.getPosition().y + player.getSize().y > poscoins[i].y) && (player.getPosition().y < poscoins[i].y + 30))
			{
				scorecoins += 1;
				poscoins[i].x = -100;
				poscoins[i].y = -100;
			}
		}

		//boat1
		for (i = 0; i <= 2; i++)
		{
			if (posboat[i].x >= 1080)
			{
				posboat[i].x = -200;
			}
			else {
				posboat[i].x += 2.2f;
			}
		}
		//boat2
		for (i = 0; i <= 2; i++)
		{
			if (posboat2[i].x <= -220)
			{
				posboat2[i].x = 1080;
			}
			else {
				posboat2[i].x -= 4.5f;
			}
		}
		//boat3
		for (i = 0; i <= 1; i++)
		{
			if (posboat3[i].x >= 1080)
			{
				posboat3[i].x = -300;
			}
			else {
				posboat3[i].x += 3.5f;
			}
		}
		//boat4
		for (i = 0; i <= 1; i++)
		{
			if (posboat4[i].x <= -230)
			{
				posboat4[i].x = 1700;
			}
			else {
				posboat4[i].x -= 4.5f;
			}
		}

		//check in window
		if (player.getPosition().x < 0) {
			player.setPosition(0, player.getPosition().y);
		}
		if (player.getPosition().x > 1060) {
			player.setPosition(1060, player.getPosition().y);
		}
		if (player.getPosition().y < 0) {
			player.setPosition(player.getPosition().x, 0);
		}
		if (player.getPosition().y < 0) {
			player.setPosition(player.getPosition().x, 0);
		}
		if (player.getPosition().y > 5000) {
			player.setPosition(player.getPosition().x, 5000);
		}

		//printf("%f\n", speed);

		window.clear();

		window.setView(view);

		window.draw(white);
		window.draw(purple);
		window.draw(purple2);
		window.draw(green);
		window.draw(red);
		window.draw(yellow);
		window.draw(box);
		window.draw(water);

		for (i = 0; i <= 2; i++)
		{
			boat1.setPosition(posboat[i].x, posboat[i].y);
			window.draw(boat1);
		}
		for (i = 0; i <= 2; i++)
		{
			boat2.setPosition(posboat2[i].x, posboat2[i].y);
			window.draw(boat2);
		}
		for (i = 0; i <= 1; i++)
		{
			boat3.setPosition(posboat3[i].x, posboat3[i].y);
			window.draw(boat3);
		}
		for (i = 0; i <= 1; i++)
		{
			boat4.setPosition(posboat4[i].x, posboat4[i].y);
			window.draw(boat4);
		}

		for (i = 0; i <= 2; i++)
		{
			itemclock.setPosition(posclock[i].x, posclock[i].y);
			window.draw(itemclock);
		}

		for (i = 0; i <= 1; i++)
		{
			itemboots.setPosition(posboots[i].x, posboots[i].y);
			window.draw(itemboots);
		}
		for (i = 0; i <= 24; i++)
		{
			itemcoins.setPosition(poscoins[i].x, poscoins[i].y);
			window.draw(itemcoins);
		}
		window.draw(player);
		window.display();
		window.clear();
	}
	return 0;
}