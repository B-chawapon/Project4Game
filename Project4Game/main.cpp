#include <SFML/Graphics.hpp>
#include<stdio.h>
#include<iostream>
#include<time.h>



int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "GAME!");
	sf::RectangleShape shape(sf::Vector2f(20.f,20.f));
	shape.setFillColor(sf::Color::Green);
	
	sf::Vector2f spawnPoint = { 1080 / 2,0.f };
	shape.setPosition(spawnPoint);

	sf::RectangleShape collision(sf::Vector2f(50.f, 30.f));
	collision.setFillColor(sf::Color::White);

	sf::RectangleShape collision2(sf::Vector2f(50.f, 30.f));
	collision2.setFillColor(sf::Color::Green);

	sf::RectangleShape collision3(sf::Vector2f(150.f, 30.f));
	collision3.setFillColor(sf::Color::Red);

	sf::RectangleShape collision4(sf::Vector2f(70.f, 50.f));
	collision4.setFillColor(sf::Color::Yellow);

	sf::RectangleShape collision5(sf::Vector2f(50.f, 30.f));
	collision5.setFillColor(sf::Color::Blue);
	
	
	srand(time(NULL));
	
	sf::Clock clock;
	

	window.setFramerateLimit(60);
	
	int spawn=0;

	
	collision2.setPosition(0, rand() % 720);
	collision3.setPosition(0, rand() % 720);
	collision4.setPosition(0, rand() % 720);
	collision5.setPosition(1080, rand() % 720);
	float speed = 2;
	int frame = 1;

	bool checksidexci=rand()%2;
	float xci = 0;
	float yci=rand()%720;
	collision.setPosition(xci, yci);
	
	while (window.isOpen())
	{
		window.clear();
		float x = rand() % 2;
		float y = rand() % 720;
	
		sf::Vector2f movement(0.f, 0.f);
		
		if ( checksidexci==0)
		{
			xci = -50;
			collision.move(10.0f, 0.0f);
			//printf("%.2f \n", collision.getPosition().x);
			if (collision.getPosition().x >= 1150)
			{
				checksidexci = rand() % 2;
				yci = rand() % 720;
				collision.setPosition(xci, yci);
				
				
			}
		}
		else if(checksidexci==1){
			xci = 1150;
			collision.move(-10.0f, 0.0f);
			//printf("%.2f \n", collision.getPosition().x);
			if (collision.getPosition().x < -50)
			{
				checksidexci = rand() % 2;
				yci = rand() % 720;
				collision.setPosition(xci, yci);
				

			}

		}
		
		
		if (collision2.getPosition().x <= 1130 )
		{
			if (x == 1)
			{
				x = 0;
			}
			collision2.move(30.f, 0.f);
			//printf("checj %.2f \n", collision2.getPosition().x);
			if (collision2.getPosition().x == 1140)
			{
				collision2.setPosition(x, rand()%720);
			}
		}
		if (collision3.getPosition().x <= 1130)
		{
			if (x == 1)
			{
				x = 0;
			}
			collision3.move(20.f, 0.f);
			//printf("%.2f \n", collision.getPosition().x);
			if (collision3.getPosition().x == 1140)
			{
				collision3.setPosition(x, rand() % 720);
			}
		}
		if (collision4.getPosition().x <= 1130)
		{
			if (x == 1)
			{
				x = 0;
			}
			collision4.move(40.f, 0.f);
			//printf("%.2f \n", collision.getPosition().x);
			if (collision4.getPosition().x == 1160)
			{
				collision4.setPosition(x, rand() % 720);
			}
		}

		
		
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
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
	
		
			
		
		if (collision.getGlobalBounds().intersects(shape.getGlobalBounds())) {
			//shape.setPosition(spawnPoint);
			speed -= 0.1;
		}

		if (collision2.getGlobalBounds().intersects(shape.getGlobalBounds())) {
			//shape.setPosition(spawnPoint);
			speed -= 0.1;
		}
		if (collision3.getGlobalBounds().intersects(shape.getGlobalBounds())) {
			shape.setPosition(spawnPoint);
			//speed -= 0.1;
		}
		if (collision4.getGlobalBounds().intersects(shape.getGlobalBounds())) {
			shape.setPosition(spawnPoint);
			speed -= 0.1;
		}
		
		
		printf("x%0.2f  y%0.2f speed %0.2f\n", shape.getPosition().x, shape.getPosition().y,speed);
		
		
		//time = clock.getElapsedTime();
		//std::cout << time.asSeconds() << std::endl;
		//clock.restart();

		//shape.move(movement);
		
		
		window.draw(shape);
		

		
		window.draw(collision);
	
		window.draw(collision2);
		window.draw(collision3);
		window.draw(collision4);
		
		window.draw(collision5);
		
		
		
		
		
		window.display();
		
		
	}
	return 0;
}