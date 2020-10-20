#include <SFML/Graphics.hpp>
#include<stdio.h>
#include<iostream>
#include<time.h>
//MAP  WEIGHT =1080   HEIGHT=5000;
int j = 0;
int i = 1;


static const float screenheight = 720.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(screenheight * aspectRatio, screenheight);

}

int main()
{
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

	sf::View view;
	view.reset(sf::FloatRect(0, 0, screen.x, screen.y));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	sf::Vector2f positionview(0, 0);



	srand(time(NULL));

	sf::Clock clock;


	window.setFramerateLimit(60);



	float speed = 2;
	int frame = 1;

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




	while (window.isOpen())
	{
		window.clear();

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

		printf("view %f\n view2 %f", positionview.y, positionview.y + 710);

		purple.setPosition(0, positionview.y);
		purple2.setPosition(0, positionview.y + 710);


		sf::Vector2f movement(0.f, 0.f);
		//white
		if (checksidexci == 0)
		{
			xci = -50;
			white.move(25.0f, 0.0f);
			//printf("%.2f \n", collision.getPosition().x);
			if (white.getPosition().x >= 1150)
			{
				checksidexci = rand() % 2;
				yci = rand() % 4801;
				for (j = 0; j != i; )
				{
					if ((yci >= positionview.y) && (yci <= (positionview.y + 710)))
					{
						white.setPosition(xci, yci);
						break;
					}
					else
					{
						yci = rand() % 4801;
						i++;
						j++;
					}
				}


			}
		}
		else if (checksidexci == 1) {
			xci = 1150;
			white.move(-25.0f, 0.0f);
			//printf("%.2f \n", collision.getPosition().x);
			if (white.getPosition().x < -50)
			{
				checksidexci = rand() % 2;
				yci = rand() % 4801;
				for (j = 0; j != i; )
				{
					if ((yci >= positionview.y) && (yci <= (positionview.y + 710)))
					{
						white.setPosition(xci, yci);
						break;
					}
					else
					{
						yci = rand() % 4801;
						i++;
						j++;
					}
				}
			}
		}
		//green
		if (checksidexci2 == 0)
		{
			xci2 = -50;
			green.move(30.0f, 0.0f);
			//printf("%.2f \n", collision.getPosition().x);
			if (green.getPosition().x >= 1150)
			{
				checksidexci2 = rand() % 2;
				yci2 = rand() % 4801;
				for (j = 0; j != i; )
				{
					if ((yci2 >= positionview.y) && (yci2 <= (positionview.y + 710)))
					{
						green.setPosition(xci2, yci2);
						break;
					}
					else
					{
						yci2 = rand() % 4801;
						i++;
						j++;
					}
				}
			}
		}
		else if (checksidexci2 == 1) {
			xci2 = 1150;
			green.move(-30.0f, 0.0f);
			//printf("%.2f \n", collision.getPosition().x);
			if (green.getPosition().x < -50)
			{
				checksidexci2 = rand() % 2;
				yci2 = rand() % 4801;
				for (j = 0; j != i; )
				{
					if ((yci2 >= positionview.y) && (yci2 <= (positionview.y + 710)))
					{
						green.setPosition(xci2, yci2);
						break;
					}
					else
					{
						yci2 = rand() % 4801;
						i++;
						j++;
					}
				}
			}
		}

		//red
		if (checksidexci3 == 0)
		{
			xci3 = -150;
			red.move(40.0f, 0.0f);
			//printf("%.2f \n", collision.getPosition().x);
			if (red.getPosition().x >= 1150)
			{
				checksidexci3 = rand() % 2;
				yci3 = rand() % 4801;
				for (j = 0; j != i; )
				{
					if ((yci3 >= positionview.y) && (yci3 <= (positionview.y + 710)))
					{
						red.setPosition(xci3, yci3);
						break;
					}
					else
					{
						yci3 = rand() % 4801;
						i++;
						j++;
					}
				}
			}
		}
		else if (checksidexci3 == 1) {
			xci3 = 1140;
			red.move(-40.0f, 0.0f);
			//printf("%.2f \n", collision.getPosition().x);
			if (red.getPosition().x < -50)
			{
				checksidexci3 = rand() % 2;
				yci3 = rand() % 4801;
				for (j = 0; j != i; )
				{
					if ((yci3 >= positionview.y) && (yci3 <= (positionview.y + 710)))
					{
						red.setPosition(xci3, yci3);
						break;
					}
					else
					{
						yci3 = rand() % 4801;
						i++;
						j++;
					}
				}
			}
		}


		if (checksidexci4 == 0)
		{
			xci4 = -150;
			yellow.move(40.0f, 0.0f);
			//printf("%.2f \n", collision.getPosition().x);
			if (yellow.getPosition().x >= 1150)
			{
				checksidexci4 = rand() % 2;
				yci4 = rand() % 4801;
				for (j = 0; j != i; )
				{
					if ((yci4 >= positionview.y) && (yci4 <= (positionview.y + 710)))
					{
						yellow.setPosition(xci4, yci4);
						break;
					}
					else
					{
						yci4 = rand() % 4801;
						i++;
						j++;
					}
				}
			}
		}
		else if (checksidexci4 == 1) {
			xci4 = 1140;
			yellow.move(-40.0f, 0.0f);
			//printf("%.2f \n", collision.getPosition().x);
			if (yellow.getPosition().x < -50)
			{
				checksidexci4 = rand() % 2;
				yci4 = rand() % 4801;
				for (j = 0; j != i; )
				{
					if ((yci4 >= positionview.y) && (yci4 <= (positionview.y + 710)))
					{
						yellow.setPosition(xci4, yci4);
						break;
					}
					else
					{
						yci4 = rand() % 4801;
						i++;
						j++;
					}
				}
			}
		}




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


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			//movement.y = -0.2f;
			//movement.x = 0.f;
			player.move(0.f * speed, -5.0f * speed);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			//movement.y = 0.2f;
			//movement.x = 0.f;
			player.move(0.f * speed, 5.0f * speed);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.move(-5.0f * speed, 0.0f * speed);
			//movement.x=-0.2f;
			//movement.y = 0.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			//movement.x = 0.2f;
			//movement.y = 0.f;
			player.move(5.0f * speed, 0.f * speed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
		{

			speed = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			window.close();
		}






		/*if (white.getGlobalBounds().intersects(shape.getGlobalBounds())) {
			//shape.setPosition(spawnPoint);
			speed -= 0.1;
		}
		if (green.getGlobalBounds().intersects(shape.getGlobalBounds())) {
			//shape.setPosition(spawnPoint);
			speed -= 0.1;
		}
		if (red.getGlobalBounds().intersects(shape.getGlobalBounds())) {
			shape.setPosition(spawnPoint);
			//speed -= 0.1;
		}
		if (yellow.getGlobalBounds().intersects(shape.getGlobalBounds())) {
			//shape.setPosition(spawnPoint);
			speed -= 0.1;
		}*/




		//printf("x%0.2f  y%0.2f speed %0.2f\n", shape.getPosition().x, shape.getPosition().y,speed);


		//time = clock.getElapsedTime();
		//std::cout << time.asSeconds() << std::endl;
		//clock.restart();

		//shape.move(movement);
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





		window.setView(view);


		window.draw(player);



		window.draw(white);
		window.draw(purple);
		window.draw(purple2);
		window.draw(green);
		window.draw(red);
		window.draw(yellow);






		window.display();


	}
	return 0;
}

