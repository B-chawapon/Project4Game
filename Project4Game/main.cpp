#include <SFML/Graphics.hpp>
#include<stdio.h>
#include<iostream>
#include<time.h>

static const float screenheight = 720.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(screenheight * aspectRatio, screenheight);

}

int main()
{
	sf::Vector2i screen(1080, 720);
	sf::RenderWindow window(sf::VideoMode(screen.x, screen.y), "GAME!",sf::Style::Close|sf::Style::Resize);
	sf::RectangleShape shape(sf::Vector2f(20.f,20.f));
	shape.setFillColor(sf::Color::Green);
	
	sf::Vector2f spawnPoint = { 1080 / 2,0.f };
	shape.setPosition(spawnPoint);

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
	
	sf::View view;
	view.reset(sf::FloatRect(0,0,screen.x,screen.y));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	sf::Vector2f position(0, 0);

	
	
	srand(time(NULL));
	
	sf::Clock clock;
	

	window.setFramerateLimit(60);
	


	float speed = 2;
	int frame = 1;

	bool checksidexci=rand()%2;
	float xci = 0;
	float yci=rand()%2000;
	white.setPosition(xci, yci);

	bool checksidexci2 = rand() % 2;
	float xci2 = 0;
	float yci2 = rand() % 2000;
	green.setPosition(xci2, yci2);

	bool checksidexci3 = rand() % 2;
	float xci3 = 0;
	float yci3 = rand() % 2000;
	red.setPosition(xci3, yci3);

	bool checksidexci4 = rand() % 2;
	float xci4 = 0;
	float yci4 = rand() % 2000;
	yellow.setPosition(xci4, yci4);



	
	while (window.isOpen())
	{
		window.clear();
		float x = rand() % 2;
		float y = rand() % 720;
	
		sf::Vector2f movement(0.f, 0.f);
		//white
		if ( checksidexci==0)
		{
			xci = -50;
			white.move(25.0f, 0.0f);
			//printf("%.2f \n", collision.getPosition().x);
			if (white.getPosition().x >= 1150)
			{
				checksidexci = rand() % 2;
				yci = rand() % 2000;
				white.setPosition(xci, yci);
			}
		}
		else if(checksidexci==1){
			xci = 1150;
			white.move(-25.0f, 0.0f);
			//printf("%.2f \n", collision.getPosition().x);
			if (white.getPosition().x < -50)
			{
				checksidexci = rand() % 2;
				yci = rand() % 2000;
				white.setPosition(xci, yci);
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
				yci2 = rand() % 2000;
				green.setPosition(xci2, yci2);
			}
		}
		else if (checksidexci2 == 1) {
			xci2 = 1150;
			green.move(-30.0f, 0.0f);
			//printf("%.2f \n", collision.getPosition().x);
			if (green.getPosition().x < -50)
			{
				checksidexci2 = rand() % 2;
				yci2 = rand() % 2000;
				green.setPosition(xci2, yci2);
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
				yci3 = rand() % 2000;
				red.setPosition(xci3, yci3);
			}
		}
		else if (checksidexci3 == 1) {
			xci3 = 1140;
			red.move(-40.0f, 0.0f);
			//printf("%.2f \n", collision.getPosition().x);
			if (red.getPosition().x < -50)
			{
				checksidexci3 = rand() % 2;
				yci3 = rand() % 2000;
				red.setPosition(xci3, yci3);
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
				yci4 = rand() % 2000;
				yellow.setPosition(xci4, yci4);
			}
		}
		else if (checksidexci4 == 1) {
			xci4 = 1140;
			yellow.move(-40.0f, 0.0f);
			//printf("%.2f \n", collision.getPosition().x);
			if (yellow.getPosition().x < -50)
			{
				checksidexci4 = rand() % 2;
				yci4 = rand() % 2000;
				yellow.setPosition(xci4, yci4);
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
			shape.move(0.f * speed, -5.0f*speed);
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			//movement.y = 0.2f;
			//movement.x = 0.f;
			shape.move(0.f * speed, 5.0f * speed);
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			shape.move(-5.0f * speed, 0.0f * speed);
			//movement.x=-0.2f;
			//movement.y = 0.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			//movement.x = 0.2f;
			//movement.y = 0.f;
			shape.move(5.0f * speed, 0.f * speed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
		{
			
			speed = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			window.close();
		}
	
		if (white.getGlobalBounds().intersects(shape.getGlobalBounds())) {
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
		}
		
		
		//printf("x%0.2f  y%0.2f speed %0.2f\n", shape.getPosition().x, shape.getPosition().y,speed);
		
		
		//time = clock.getElapsedTime();
		//std::cout << time.asSeconds() << std::endl;
		//clock.restart();

		//shape.move(movement);
		
		
		
		position.y = shape.getPosition().y+10   - (screen.y / 2);
		position.x = 0;
		if (position.y < 0)
		{
			position.y = 0;
		}
		view.reset(sf::FloatRect(position.x, position.y, screen.x, screen.y));
		printf("%f\n%f", position.x, position.y);
		
		window.setView(view);
	

		window.draw(shape);
		

		
		window.draw(white);
	
		window.draw(green);
		window.draw(red);
		window.draw(yellow);
		
		
		
		
		
		
		window.display();
		
		
	}
	return 0;
}