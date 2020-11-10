#include <SFML/Graphics.hpp>
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<iostream>
#include <string>
#include <sstream>
//MAP  WEIGHT =1080   HEIGHT=5000;
using namespace std;
int j = 0;
int i = 1;
int m = 0;
int s = 0;

int a = 0;//blue

float speed = 1;
float slowtime = 1;
bool checkslowtime = 0;

int stackshoes = 0;

int scorecoins = 0;
int frame = 0;
int framewater = 0;
bool collinreturn;
float realposcary;
static const float screenheight = 720.0f;
static const float sizecary = 65.0f;
static const float sizecarx = 120.0f;

int side = 1;
int tempdistance;
int hightDistance;
int allowDraw = 0;
int countcollin = 0;

int answer;

struct checksidexi
{
	int checkside;
}whitex[2], redx[2], yellowx[3], bluex[2], greenx[3];
int checksidexci;

void ResizeView(const sf::RenderWindow& window, sf::View& view);
float findPosCarY(sf::RectangleShape colorcar, int poscary, int poscarx, float viewfunc);
bool Collision(sf::Vector2f posobject, sf::RectangleShape sizeobject, sf::RectangleShape posplayerfunc, sf::RectangleShape playersizefunc);
sf::Vector2f positionview;
int main()
{
	struct checksidexi;
	srand(time(NULL));

	sf::Vector2i screen(1080, 720);
	sf::RenderWindow window(sf::VideoMode(screen.x, screen.y), "GAME!", sf::Style::Close | sf::Style::Resize);

	sf::View view;
	view.reset(sf::FloatRect(0, 0, screen.x, screen.y));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

	sf::Vector2f positionview(0, 0);

	sf::RectangleShape player(sf::Vector2f(35.f, 35.f));//35
	player.setFillColor(sf::Color::Green);

	sf::Vector2f spawnPoint = { 1080 / 2,85.f };
	player.setPosition(spawnPoint);

	sf::RectangleShape white(sf::Vector2f(sizecarx, sizecary));
	white.setFillColor(sf::Color::White);

	sf::RectangleShape green(sf::Vector2f(sizecarx, sizecary));
	green.setFillColor(sf::Color::Green);

	sf::RectangleShape red(sf::Vector2f(200.f, sizecary));
	red.setFillColor(sf::Color::Red);

	sf::RectangleShape yellow(sf::Vector2f(90, sizecary));
	yellow.setFillColor(sf::Color::Yellow);

	sf::RectangleShape blue(sf::Vector2f(sizecarx, sizecary));
	blue.setFillColor(sf::Color::Blue);

	sf::RectangleShape purple(sf::Vector2f(10.f, 10.f));
	purple.setFillColor(sf::Color::Magenta);

	sf::RectangleShape purple2(sf::Vector2f(10.f, 10.f));
	purple2.setFillColor(sf::Color::Magenta);

	sf::RectangleShape river(sf::Vector2f(1080.f, 250.f));//250
	river.setFillColor(sf::Color::Cyan);
	sf::Vector2f posriver[3];
	for (i = 0; i <= 2; i++)
	{
		posriver[i].x = 0;
		if (i == 0)
		{
			posriver[i].y = 1010;//1000+10
		}
		if (i == 1)
		{
			posriver[i].y = 2500;
		}
		if (i == 2)
		{
			posriver[i].y = 4030;//4000+30
		}
		//1000 2500 4000
	}

	sf::Sprite water;
	sf::Texture texturewater;
	texturewater.loadFromFile("water.png");
	texturewater.setSmooth(true);
	water.setTexture(texturewater);
	water.setTextureRect(sf::IntRect(0, 0, 1080.0f, 250.f));

	sf::RectangleShape boat1(sf::Vector2f(200.0f, 62.5f));//200
	boat1.setFillColor(sf::Color::Transparent);//Red
	sf::Vector2f posboat[9];
	for (i = 0; i <= 8; i++)
	{
		if (i >= 0 && i <= 2)
		{
			posboat[i].y = 1010;//360
		}
		if (i >= 3 && i <= 5)
		{
			posboat[i].y = 2625.0f;//360
		}
		if (i >= 6 && i <= 8)
		{
			posboat[i].y = 4092.5f;//360
		}
	}
	posboat[0].x = -200; posboat[1].x = -600; posboat[2].x = -1000;
	posboat[3].x = -200; posboat[4].x = -600; posboat[5].x = -1000;
	posboat[6].x = -200; posboat[7].x = -600; posboat[8].x = -1000;
	sf::RectangleShape boat2(sf::Vector2f(120.0f, 62.5f));//120
	boat2.setFillColor(sf::Color::Transparent);//Blue
	sf::Vector2f posboat2[9];
	for (i = 0; i <= 8; i++)
	{
		if (i >= 0 && i <= 2)
		{
			posboat2[i].y = 1072.5f;//360
		}
		if (i >= 3 && i <= 5)
		{
			posboat2[i].y = 2562.5f;//360
		}
		if (i >= 6 && i <= 8)
		{
			posboat2[i].y = 4217.5f;//360
		}
	}
	posboat2[0].x = 1080; posboat2[1].x = 1500; posboat2[2].x = 1820;
	posboat2[3].x = 1080; posboat2[4].x = 1500; posboat2[5].x = 1820;
	posboat2[6].x = 1080; posboat2[7].x = 1500; posboat2[8].x = 1820;

	sf::RectangleShape boat3(sf::Vector2f(300.0f, 62.5f));//300
	boat3.setFillColor(sf::Color::Transparent);//Black
	boat3.setPosition(1150, 485.0f);//485.0
	sf::Vector2f posboat3[6];
	for (i = 0; i <= 5; i++)
	{
		if (i >= 0 && i <= 1)
		{
			posboat3[i].y = 1135.0f;//485.0f
		}
		if (i >= 2 && i <= 3)
		{
			posboat3[i].y = 2500.0f;//485.0f
		}
		if (i >= 4 && i <= 5)
		{
			posboat3[i].y = 4155.0f;//485.0f
		}
	}
	posboat3[0].x = -300; posboat3[1].x = -900;
	posboat3[2].x = -300; posboat3[3].x = -900;
	posboat3[4].x = -300; posboat3[5].x = -900;
	sf::RectangleShape boat4(sf::Vector2f(240.0f, 62.5f));//225.f
	boat4.setFillColor(sf::Color::Transparent);//White Transparent
	sf::Vector2f posboat4[6];
	for (i = 0; i <= 5; i++)
	{
		if (i >= 0 && i <= 1)
		{
			posboat4[i].y = 1197.5f;//547.5
		}
		if (i >= 2 && i <= 3)
		{
			posboat4[i].y = 2687.5f;//547.5
		}
		if (i >= 4 && i <= 5)
		{
			posboat4[i].y = 4030;//547.5
		}
	}
	posboat4[0].x = 1200; posboat4[1].x = 2200;
	posboat4[2].x = 1200; posboat4[3].x = 2200;
	posboat4[4].x = 1200; posboat4[5].x = 2200;

	sf::Sprite sushiyelloworangered;
	sf::Texture texturesushiyelloworangered;
	texturesushiyelloworangered.loadFromFile("sushiyelloworangered.png");
	texturesushiyelloworangered.setSmooth(true);
	sushiyelloworangered.setTexture(texturesushiyelloworangered);
	sushiyelloworangered.setTextureRect(sf::IntRect(0.0f, 0.0f, 200.f, 63.f));
	sushiyelloworangered.setScale(sf::Vector2f(1.0f, 1.0f));

	sf::Sprite duosushi;
	sf::Texture textureduosushi;
	textureduosushi.loadFromFile("duosushi.png");
	textureduosushi.setSmooth(true);
	duosushi.setTexture(textureduosushi);
	duosushi.setTextureRect(sf::IntRect(0.0f, 0.0f, 120.f, 63.f));
	duosushi.setScale(sf::Vector2f(1.0f, 1.0f));

	sf::Sprite mixsuhi;
	sf::Texture texturemixsushi;
	texturemixsushi.loadFromFile("mixsushi.png");
	texturemixsushi.setSmooth(true);
	mixsuhi.setTexture(texturemixsushi);
	mixsuhi.setTextureRect(sf::IntRect(0.0f, 0.0f, 300.f, 63.f));
	mixsuhi.setScale(sf::Vector2f(1.0f, 1.0f));

	sf::Sprite uniship;
	sf::Texture textureuni;
	textureuni.loadFromFile("uni.png");
	textureuni.setSmooth(true);
	uniship.setTexture(textureuni);
	uniship.setTextureRect(sf::IntRect(0.0f, 0.0f, 242.f, 63.f));
	uniship.setScale(sf::Vector2f(1.0f, 1.0f));

	sf::Sprite sushiboat;
	sf::Texture textureusushiboat;
	textureusushiboat.loadFromFile("sushiboat.png");
	textureusushiboat.setSmooth(true);
	sushiboat.setTexture(textureusushiboat);
	sushiboat.setTextureRect(sf::IntRect(0.0f, 0.0f, 120.f, 63.f));
	sushiboat.setScale(sf::Vector2f(1.1f, 1.2f));

	sf::Sprite woodpae;
	sf::Texture textureuwoodpae;
	textureuwoodpae.loadFromFile("boat.png");
	textureuwoodpae.setSmooth(true);
	woodpae.setTexture(textureuwoodpae);
	woodpae.setTextureRect(sf::IntRect(0.0f, 0.0f, 212.f, 63.f));
	woodpae.setScale(sf::Vector2f(1.415094339622642f, 1.0f));

	sf::Sprite zeldaboat;
	sf::Texture texturezeldaboat;
	texturezeldaboat.loadFromFile("zeldaboat.png");
	texturezeldaboat.setSmooth(true);
	zeldaboat.setTexture(texturezeldaboat);
	zeldaboat.setTextureRect(sf::IntRect(0.0f, 0.0f, 200.f, 63.f));
	zeldaboat.setScale(sf::Vector2f(1.0f, 1.0f));

	sf::Sprite fishboat;
	sf::Texture texturefishboat;
	texturefishboat.loadFromFile("dog3jellygreen.png");
	texturefishboat.setSmooth(true);
	fishboat.setTexture(texturefishboat);
	fishboat.setTextureRect(sf::IntRect(0.0f, 0.0f, 240.f, 63.f));
	fishboat.setScale(sf::Vector2f(1.0f, 1.0f));

	sf::Sprite crocodileboat;
	sf::Texture texturecrocodile;
	texturecrocodile.loadFromFile("dogbubble.png");
	texturecrocodile.setSmooth(true);
	crocodileboat.setTexture(texturecrocodile);
	crocodileboat.setTextureRect(sf::IntRect(0.0f, 0.0f, 300.f, 63.f));
	crocodileboat.setScale(sf::Vector2f(1.0f, 1.0f));

	sf::Sprite woodlogboat2;
	sf::Texture texturewoodlogboat2;
	texturewoodlogboat2.loadFromFile("woodlog2.png");
	texturewoodlogboat2.setSmooth(true);
	woodlogboat2.setTexture(texturewoodlogboat2);
	woodlogboat2.setTextureRect(sf::IntRect(0.0f, 0.0f, 240.f, 63.f));
	woodlogboat2.setScale(sf::Vector2f(1.00f, 1.0f));

	sf::Sprite dogpizza;
	sf::Texture texturedogpizza;
	texturedogpizza.loadFromFile("dogpizza.png");
	texturedogpizza.setSmooth(true);
	dogpizza.setTexture(texturedogpizza);
	dogpizza.setTextureRect(sf::IntRect(0.0f, 0.0f, 240.f, 63.f));
	dogpizza.setScale(sf::Vector2f(0.8333333333333333f, 1.0f));

	sf::Sprite dogham;
	sf::Texture texturedogham;
	texturedogham.loadFromFile("submarine.png");
	texturedogham.setSmooth(true);
	dogham.setTexture(texturedogham);
	dogham.setTextureRect(sf::IntRect(0.0f, 0.0f, 120.f, 63.f));
	dogham.setScale(sf::Vector2f(1.12f, 1.0f));

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
	sf::Vector2f posboots[3];
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
	itemcoins.setScale(sf::Vector2f(0.275f, 0.295f));
	sf::Vector2f poscoins[26];
	for (i = 0; i <= 24; i++)
	{
		poscoins[i].x = rand() % 1000;
		poscoins[i].y = rand() % 4900;
	}

	sf::RectangleShape platmid(sf::Vector2f(1080.0f, 50.0f));//200
	platmid.setFillColor(sf::Color::Cyan);
	sf::Vector2f posplatmid[4];
	for (i = 0; i <= 3; i++)
	{
		if (i == 0)
		{
			posplatmid[i].y = 390.0f;//360
		}
		if (i == 1)
		{
			posplatmid[i].y = 755.0f;//360
		}
		if (i == 2)
		{
			posplatmid[i].y = 1805.0f;//360
		}
		if (i == 3)
		{
			posplatmid[i].y = 3400.0f;//360
		}
	}

	sf::Font fontscore;
	fontscore.loadFromFile("fonttext/GOTHICB.ttf");

	sf::Text highscoretext;
	highscoretext.setFont(fontscore);
	highscoretext.setCharacterSize(20);
	highscoretext.setString("Highscore 0");
	sf::Text scoretext;
	scoretext.setFont(fontscore);
	scoretext.setCharacterSize(20);
	scoretext.setString("Score 0");

	sf::Text shoetext;
	shoetext.setFont(fontscore);
	shoetext.setCharacterSize(20);
	shoetext.setString("Shoes 0");

	sf::Text cointext;
	cointext.setFont(fontscore);
	cointext.setCharacterSize(20);
	cointext.setString("Shoes 0");

	sf::Text answertext;
	answertext.setFont(fontscore);
	answertext.setCharacterSize(20);

	int distance;

	window.setFramerateLimit(60);
	//white
	sf::Vector2f poswhite[2][3];
	for (a = 0; a <= 1; a++)
	{
		whitex[a].checkside = rand() % 2;
		if (whitex[a].checkside == 0)
		{
			whitex[a].checkside = 1;
			for (i = 0; i <= 2; i++)
			{
				poswhite[a][i].x = -120 - (540 * i);
				if (a == 0)
				{
					poswhite[a][i].y = 295;
				}
				if (a == 1)
				{
					poswhite[a][i].y = 1370;
				}
			}
		}
		else
		{
			whitex[a].checkside = -1;
			for (i = 0; i <= 2; i++)
			{
				poswhite[a][i].x = 1080 + (540 * i);
				if (a == 0)
				{
					poswhite[a][i].y = 295;
				}
				if (a == 1)
				{
					poswhite[a][i].y = 1370;//470
				}
			}
		}
	}

	//green
	sf::Vector2f posgreen[3][2];
	for (a = 0; a <= 2; a++)
	{
		greenx[a].checkside = rand() % 2;
		if (greenx[a].checkside == 0)
		{
			greenx[a].checkside = 1;
			for (i = 0; i <= 1; i++)
			{
				posgreen[a][i].x = -190 - (800 * i);

				if (a == 0)
				{
					posgreen[a][i].y = 1560;//1370
				}
				if (a == 1)
				{
					posgreen[a][i].y = 3000;//1465
				}
				if (a == 2)
				{
					posgreen[a][i].y = 3500;
				}
			}
		}
		else
		{
			greenx[a].checkside = -1;
			for (i = 0; i <= 1; i++)
			{
				posgreen[a][i].x = 1180 + (540 * i);

				if (a == 0)
				{
					posgreen[a][i].y = 1560;//1370
				}
				if (a == 1)
				{
					posgreen[a][i].y = 3000;//1465
				}
				if (a == 2)
				{
					posgreen[a][i].y = 3500;
				}
			}
		}
	}

	//red
	sf::Vector2f posred[2][3];
	for (a = 0; a <= 1; a++)
	{
		redx[a].checkside = rand() % 2;
		if (redx[a].checkside == 0)
		{
			redx[a].checkside = 1;
			for (i = 0; i <= 2; i++)
			{
				posred[a][i].x = -200 - (540 * i);
				if (a == 0)
				{
					posred[a][i].y = 660;
				}
				if (a == 1)
				{
					posred[a][i].y = 835;
				}
			}
		}
		else
		{
			redx[a].checkside = -1;
			for (i = 0; i <= 2; i++)
			{
				posred[a][i].x = 1080 + (540 * i);
				if (a == 0)
				{
					posred[a][i].y = 660;
				}
				if (a == 1)
				{
					posred[a][i].y = 835;
				}
			}
		}
	}

	//yellow
	sf::Vector2f posyellow[3][3];
	for (a = 0; a <= 2; a++)
	{
		yellowx[a].checkside = rand() % 2;
		if (yellowx[a].checkside == 0)
		{
			yellowx[a].checkside = 1;
			for (i = 0; i <= 2; i++)
			{
				posyellow[a][i].x = -190 - (800 * i);

				if (a == 0)
				{
					posyellow[a][i].y = 470;//1370
				}
				if (a == 1)
				{
					posyellow[a][i].y = 1465;//1465
				}
				if (a == 2)
				{
					posyellow[a][i].y = 1655;
				}
			}
		}
		else
		{
			yellowx[a].checkside = -1;
			for (i = 0; i <= 2; i++)
			{
				posyellow[a][i].x = 1180 + (540 * i);

				if (a == 0)
				{
					posyellow[a][i].y = 470;//1370
				}
				if (a == 1)
				{
					posyellow[a][i].y = 1465;//1465
				}
				if (a == 2)
				{
					posyellow[a][i].y = 1655;
				}
			}
		}
	}

	//blue
	sf::Vector2f posblue[2][3];
	for (a = 0; a <= 1; a++)
	{
		bluex[a].checkside = rand() % 2;
		if (bluex[a].checkside == 0)
		{
			bluex[a].checkside = 1;
			for (i = 0; i <= 2; i++)
			{
				posblue[a][i].x = -120 - (540 * i);
				if (a == 0)
				{
					posblue[a][i].y = 200;
				}
				if (a == 1)
				{
					posblue[a][i].y = 565;
				}
			}
		}
		else
		{
			bluex[a].checkside = -1;
			for (i = 0; i <= 2; i++)
			{
				posblue[a][i].x = 1080 + (540 * i);
				if (a == 0)
				{
					posblue[a][i].y = 200;
				}
				if (a == 1)
				{
					posblue[a][i].y = 565;
				}
			}
		}
	}

	sf::Clock clock;
	sf::Time durationslow;
	sf::Clock animationcoin;
	sf::Clock animationwater;

	while (window.isOpen())
	{
		window.clear();
		//printf("%f\n", player.getPosition().y);
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

		//white
		for (a = 0; a <= 1; a++)
		{
			for (i = 0; i <= 2; i++)
			{
				if (whitex[a].checkside == 1)
				{
					if (poswhite[a][i].x > 1620)
					{
						poswhite[a][i].x = -120;
					}
					if (a == 0)//295
					{
						poswhite[a][i].x += (2.0f * slowtime * whitex[a].checkside);//1
					}
					if (a == 1)//1370
					{
						poswhite[a][i].x += (5.5f * slowtime * whitex[a].checkside);//-1
					}
				}
				else if (whitex[a].checkside == -1)
				{
					if (poswhite[a][i].x < -590)
					{
						poswhite[a][i].x = 1080;
					}
					if (a == 0)//295
					{
						poswhite[a][i].x += (2.0f * slowtime * whitex[a].checkside);//-1
					}
					if (a == 1)//1370
					{
						poswhite[a][i].x += (5.5f * slowtime * whitex[a].checkside);//-1
					}
				}
			}
		}
		//green
		for (a = 0; a <= 2; a++)
		{
			for (i = 0; i <= 1; i++)
			{
				if (greenx[a].checkside == 1)
				{
					if (posgreen[a][i].x > 1080)
					{
						posgreen[a][i].x = -120;
					}
					if (a == 0)
					{
						posgreen[a][i].x += (3.0f * slowtime * greenx[a].checkside);//1
					}
					if (a == 1)
					{
						posgreen[a][i].x += (3.5f * slowtime * greenx[a].checkside);//-1
					}
					if (a == 2)
					{
						posgreen[a][i].x += (5.0f * slowtime * greenx[a].checkside);//-1
					}
				}
				else if (greenx[a].checkside == -1)
				{
					if (posgreen[a][i].x < -120)
					{
						posgreen[a][i].x = 1080;
					}
					if (a == 0)
					{
						posgreen[a][i].x += (3.0f * slowtime * greenx[a].checkside);//-1
					}
					if (a == 1)
					{
						posgreen[a][i].x += (3.5f * slowtime * greenx[a].checkside);//-1
					}
					if (a == 2)
					{
						posgreen[a][i].x += (7.0f * slowtime * greenx[a].checkside);//-1
					}
				}
			}
		}
		//red
		for (a = 0; a <= 1; a++)
		{
			for (i = 0; i <= 2; i++)
			{
				if (redx[a].checkside == 1)
				{
					if (posred[a][i].x > 1620)
					{
						posred[a][i].x = -200;
					}
					if (a == 0)
					{
						posred[a][i].x += (2.0f * slowtime * redx[a].checkside);//1
					}
					if (a == 1)
					{
						posred[a][i].x += (7.0f * slowtime * redx[a].checkside);//-1
					}
				}
				else if (redx[a].checkside == -1)
				{
					if (posred[a][i].x < -590)
					{
						posred[a][i].x = 1080;
					}
					if (a == 0)
					{
						posred[a][i].x += (2.0f * slowtime * redx[a].checkside);//-1
					}
					if (a == 1)
					{
						posred[a][i].x += (7.0f * slowtime * redx[a].checkside);//-1
					}
				}
			}
		}
		//yellow
		for (a = 0; a <= 2; a++)
		{
			for (i = 0; i <= 2; i++)
			{
				if (yellowx[a].checkside == 1)
				{
					if (posyellow[a][i].x > 1080)
					{
						posyellow[a][i].x = -120;
					}
					if (a == 0)
					{
						posyellow[a][i].x += (3.0f * slowtime * yellowx[a].checkside);//1
					}
					if (a == 1)
					{
						posyellow[a][i].x += (3.5f * slowtime * yellowx[a].checkside);//-1
					}
					if (a == 2)
					{
						posyellow[a][i].x += (5.0f * slowtime * yellowx[a].checkside);//-1
					}
				}
				else if (yellowx[a].checkside == -1)
				{
					if (posyellow[a][i].x < -120)
					{
						posyellow[a][i].x = 1080;
					}
					if (a == 0)
					{
						posyellow[a][i].x += (3.0f * slowtime * yellowx[a].checkside);//-1
					}
					if (a == 1)
					{
						posyellow[a][i].x += (3.5f * slowtime * yellowx[a].checkside);//-1
					}
					if (a == 2)
					{
						posyellow[a][i].x += (7.0f * slowtime * yellowx[a].checkside);//-1
					}
				}
			}
		}

		//blue
		//lane 1 200
		for (a = 0; a <= 1; a++)
		{
			for (i = 0; i <= 2; i++)
			{
				if (bluex[a].checkside == 1)
				{
					if (posblue[a][i].x > 1620)
					{
						posblue[a][i].x = -120;
					}
					if (a == 0)
					{
						posblue[a][i].x += (3.0f * slowtime * bluex[a].checkside);//1
					}
					if (a == 1)
					{
						posblue[a][i].x += (5.0f * slowtime * bluex[a].checkside);//-1
					}
				}
				else if (bluex[a].checkside == -1)
				{
					if (posblue[a][i].x < -590)
					{
						posblue[a][i].x = 1080;
					}
					if (a == 0)
					{
						posblue[a][i].x += (3.0f * slowtime * bluex[a].checkside);//-1
					}
					if (a == 1)
					{
						posblue[a][i].x += (5.0f * slowtime * bluex[a].checkside);//-1
					}
				}
			}
		}

		//player move  //+ Collinsions *************************************************************
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.f * speed, -5.0f * speed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.f * speed, 5.0f * speed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.move(-5.0f * speed, 0.0f * speed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(5.0f * speed, 0.f * speed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		{
			speed = 1;
			slowtime = 1;
			stackshoes = 0;
			/*boat1.setFillColor(sf::Color::Red);//White Transparent
			boat2.setFillColor(sf::Color::Blue);//White Transparent
			boat3.setFillColor(sf::Color::Black);//White Transparent
			boat4.setFillColor(sf::Color::White);//White Transparent*/
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
		{
			//slowtime = 0.1;//0.1
			speed = 2;//2
			/*boat1.setFillColor(sf::Color::Transparent);//White Transparent
			boat2.setFillColor(sf::Color::Transparent);//White Transparent
			boat3.setFillColor(sf::Color::Transparent);//White Transparent
			boat4.setFillColor(sf::Color::Transparent);//White Transparent*/
			//allowDraw = 1;
			allowDraw = 1;
			countcollin = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T))
		{
			slowtime = 1;
			speed = 1;
			/*boat1.setFillColor(sf::Color::Transparent);//White Transparent
			boat2.setFillColor(sf::Color::Transparent);//White Transparent
			boat3.setFillColor(sf::Color::Transparent);//White Transparent
			boat4.setFillColor(sf::Color::Transparent);//White Transparent*/
			allowDraw = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			window.close();
		}

		//Collinsion car
		for (a = 0; a <= 2; a++)
		{
			for (i = 0; i <= 2; i++)
			{
				if (Collision(posblue[a][i], blue, player, player))
				{
					//player.setPosition(spawnPoint);
					//speed -= 0.005;
					countcollin += 1;
				}
				if (Collision(poswhite[a][i], white, player, player))
				{
					//player.setPosition(spawnPoint);
					//speed -= 0.005;
					countcollin += 1;
				}
				if (Collision(posred[a][i], red, player, player))
				{
					//player.setPosition(spawnPoint);
					//speed -= 0.005;
					countcollin += 1;
				}
				if (Collision(posyellow[a][i], yellow, player, player))
				{
					//player.setPosition(spawnPoint);
					//speed -= 0.005;
					countcollin += 1;
				}
			}
		}

		//Water DAMMMM******************
		bool checkCol = 0;
		/*if (Collision(posriver[0], river, player, player))
		{
			player.move(0.0f, 0.0f);
			for (i = 0; i <= 2; i++)
			{
				if (Collision(posboat[i], boat1, player, player))
				{
					checkCol = 1;
					player.move(2.200f * slowtime, 0.0f);
					break;
				}
				if (Collision(posboat2[i], boat2, player, player))
				{
					checkCol = 1;
					player.move(-4.5f * slowtime, 0.0f);
					break;
				}
			}
			for (i = 0; i <= 1; i++)
			{
				if (Collision(posboat3[i], boat3, player, player))
				{
					checkCol = 1;
					player.move(3.5f * slowtime, 0.0f);
					break;
				}
				if (Collision(posboat4[i], boat4, player, player))
				{
					checkCol = 1;
					player.move(-4.5f * slowtime, 0.0f);
					break;
				}
			}
			if (checkCol != 1)
			{
				distance = 0;
				tempdistance = 0;
				player.setPosition(spawnPoint);
			}
		}
		if (Collision(posriver[1], river, player, player))
		{
			player.move(0.0f, 0.0f);
			for (i = 3; i <= 5; i++)
			{
				if (Collision(posboat[i], boat1, player, player))
				{
					checkCol = 1;
					player.move(4.200f * slowtime, 0.0f);
					break;
				}
				if (Collision(posboat2[i], boat2, player, player))
				{
					checkCol = 1;
					player.move(-5.0f * slowtime, 0.0f);
					break;
				}
			}
			for (i = 2; i <= 3; i++)
			{
				if (Collision(posboat3[i], boat3, player, player))
				{
					checkCol = 1;
					player.move(4.5f * slowtime, 0.0f);
					break;
				}
				if (Collision(posboat4[i], boat4, player, player))
				{
					checkCol = 1;
					player.move(-6.5f * slowtime, 0.0f);
					break;
				}
			}
			if (checkCol != 1)
			{
				distance = 0;
				tempdistance = 0;
				player.setPosition(spawnPoint);
			}
		}
		if (Collision(posriver[2], river, player, player))
		{
			player.move(0.0f, 0.0f);
			for (i = 6; i <= 8; i++)
			{
				if (Collision(posboat[i], boat1, player, player))
				{
					checkCol = 1;
					player.move(7.200f * slowtime, 0.0f);
					break;
				}
				if (Collision(posboat2[i], boat2, player, player))
				{
					checkCol = 1;
					player.move(-7.0f * slowtime, 0.0f);
					break;
				}
			}
			for (i = 4; i <= 5; i++)
			{
				if (Collision(posboat3[i], boat3, player, player))
				{
					checkCol = 1;
					player.move(4.5f * slowtime, 0.0f);
					break;
				}
				if (Collision(posboat4[i], boat4, player, player))
				{
					checkCol = 1;
					player.move(-8.5f * slowtime, 0.0f);
					break;
				}
			}
			if (checkCol != 1)
			{
				distance = 0;
				tempdistance = 0;
				player.setPosition(spawnPoint);
			}
		}*/

		//boat1
		for (i = 0; i <= 8; i++)
		{
			if (i >= 0 && i <= 2)
			{
				if (posboat[i].x >= 1080)
				{
					posboat[i].x = -200;
				}
				else {
					posboat[i].x += 2.2f * slowtime;
				}
			}
			if (i >= 3 && i <= 5)
			{
				if (posboat[i].x >= 1080)
				{
					posboat[i].x = -200;
				}
				else {
					posboat[i].x += 4.2f * slowtime;
				}
			}
			if (i >= 6 && i <= 8)
			{
				if (posboat[i].x >= 1080)
				{
					posboat[i].x = -200;
				}
				else {
					posboat[i].x += 7.2f * slowtime;
				}
			}
		}
		//boat2
		for (i = 0; i <= 8; i++)
		{
			if (i >= 0 && i <= 2)
			{
				if (posboat2[i].x <= -220)
				{
					posboat2[i].x = 1080;
				}
				else {
					posboat2[i].x -= 4.5f * slowtime;
				}
			}
			if (i >= 3 && i <= 5)
			{
				if (posboat2[i].x <= -220)
				{
					posboat2[i].x = 1080;
				}
				else {
					posboat2[i].x -= 5.0f * slowtime;
				}
			}
			if (i >= 6 && i <= 8)
			{
				if (posboat2[i].x <= -220)
				{
					posboat2[i].x = 1080;
				}
				else {
					posboat2[i].x -= 7.0f * slowtime;
				}
			}
		}
		//boat3
		for (i = 0; i <= 5; i++)
		{
			if (i >= 0 && i <= 1)
			{
				if (posboat3[i].x >= 1080)
				{
					posboat3[i].x = -300;
				}
				else {
					posboat3[i].x += 3.5f * slowtime;
				}
			}
			if (i >= 2 && i <= 3)
			{
				if (posboat3[i].x >= 1080)
				{
					posboat3[i].x = -300;
				}
				else {
					posboat3[i].x += 4.5f * slowtime;
				}
			}
			if (i >= 4 && i <= 5)
			{
				if (posboat3[i].x >= 1080)
				{
					posboat3[i].x = -300;
				}
				else {
					posboat3[i].x += 4.5f * slowtime;
				}
			}
		}
		//boat4
		for (i = 0; i <= 5; i++)
		{
			if (i >= 0 && i <= 1)
			{
				if (posboat4[i].x <= -230)
				{
					posboat4[i].x = 1700;
				}
				else {
					posboat4[i].x -= 4.5f * slowtime;
				}
			}
			if (i >= 2 && i <= 3)
			{
				if (posboat4[i].x <= -230)
				{
					posboat4[i].x = 1700;
				}
				else {
					posboat4[i].x -= 6.5f * slowtime;
				}
			}
			if (i >= 4 && i <= 5)
			{
				if (posboat4[i].x <= -230)
				{
					posboat4[i].x = 1700;
				}
				else {
					posboat4[i].x -= 8.5f * slowtime;
				}
			}
		}

		//check in window
		/*if (player.getPosition().x < 0) {
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
		}*/

		//printf("%f\n", speed);

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
			//printf("%f\n", durationslow.asSeconds());
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
				if (stackshoes >= 6)//6
				{
					speed += 0;
				}
				else
				{
					stackshoes += 1;
					speed += 0.075;
				}
				posboots[i].x = rand() % 1000;
				posboots[i].y = rand() % 4900;
			}
			posboots[2].x = -99;
			posboots[2].y = -99;
		}

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
			poscoins[25].x = -99;
			poscoins[25].y = -99;
		}

		stringstream hs, sc, shoec, coinc, answerc;
		//printf("%d", s);
		distance = ((player.getPosition().y + player.getSize().y) - 120);
		if (distance - tempdistance > 0)
		{
			tempdistance = distance;
			sc << "Score " << distance;
			scoretext.setString(sc.str());
		}
		else if (distance - tempdistance < 0)
		{
			sc << "Score " << tempdistance;
			scoretext.setString(sc.str());
		}
		if (tempdistance - hightDistance > 0)
		{
			hightDistance = tempdistance;
			hs << "HighScore " << hightDistance;
		}
		else
		{
			hs << "HighScore " << hightDistance;
		}

		answerc << player.getPosition().y << '\n' << countcollin;
		cout << speed << '\n';
		answertext.setString(answerc.str());
		answertext.setPosition(positionview.x, positionview.y);

		coinc << "x " << scorecoins;
		cointext.setPosition(positionview.x + 550, positionview.y);
		cointext.setString(coinc.str());

		shoec << "x " << stackshoes;
		shoetext.setPosition(positionview.x + 650, positionview.y);
		shoetext.setString(shoec.str());

		scoretext.setPosition(positionview.x + 950, positionview.y);
		highscoretext.setString(hs.str());
		highscoretext.setPosition(positionview.x + 750, positionview.y);

		window.clear();

		window.setView(view);
		for (i = 0; i <= 3; i++)
		{
			platmid.setPosition(posplatmid[i].x, posplatmid[i].y);
			window.draw(platmid);
		}

		//draw white
		for (a = 0; a <= 1; a++)
		{
			for (i = 0; i <= 2; i++)
			{
				white.setPosition(poswhite[a][i].x, poswhite[a][i].y);
				window.draw(white);
			}
		}
		//draw blue
		for (a = 0; a <= 1; a++)
		{
			for (i = 0; i <= 2; i++)
			{
				blue.setPosition(posblue[a][i].x, posblue[a][i].y);
				window.draw(blue);
			}
		}
		//draw green
		for (a = 0; a <= 2; a++)
		{
			for (i = 0; i <= 1; i++)
			{
				green.setPosition(posgreen[a][i].x, posgreen[a][i].y);
				window.draw(green);
			}
		}

		//draw red
		for (a = 0; a <= 1; a++)
		{
			for (i = 0; i <= 2; i++)
			{
				red.setPosition(posred[a][i].x, posred[a][i].y);
				window.draw(red);
			}
		}
		//draw yellow
		for (a = 0; a <= 2; a++)
		{
			for (i = 0; i <= 2; i++)
			{
				yellow.setPosition(posyellow[a][i].x, posyellow[a][i].y);
				window.draw(yellow);
			}
		}
		//draw river
		for (i = 0; i <= 2; i++)
		{
			river.setPosition(posriver[i].x, posriver[i].y);
			water.setPosition(posriver[i].x, posriver[i].y);
			window.draw(river);
			window.draw(water);
		}
		//draw boat1
		for (i = 0; i <= 8; i++)
		{
			if (i >= 0 && i <= 2)
			{
				sushiyelloworangered.setPosition(posboat[i].x - 0.0f, posboat[i].y - 0.0f);
			}
			if (i >= 3 && i <= 5)
			{
				zeldaboat.setPosition(posboat[i].x - 0.0f, posboat[i].y - 1.5f);
			}
			if (i >= 6 && i <= 8)
			{
				dogpizza.setPosition(posboat[i].x - 0.0f, posboat[i].y - 0.0f);
			}
			boat1.setPosition(posboat[i].x, posboat[i].y);
			window.draw(boat1);
			window.draw(sushiyelloworangered);
			window.draw(zeldaboat);
			window.draw(dogpizza);
		}
		//draw boat3
		for (i = 0; i <= 5; i++)
		{
			if (i >= 0 && i <= 1)
			{
				mixsuhi.setPosition(posboat3[i].x, posboat3[i].y);
			}
			if (i >= 2 && i <= 3)
			{
				woodpae.setPosition(posboat3[i].x, posboat3[i].y);
			}
			if (i >= 4 && i <= 5)
			{
				crocodileboat.setPosition(posboat3[i].x + .0f, posboat3[i].y);
			}
			boat3.setPosition(posboat3[i].x, posboat3[i].y);
			window.draw(boat3);
			window.draw(mixsuhi);
			window.draw(woodpae);
			window.draw(crocodileboat);
		}
		//draw boat2
		for (i = 0; i <= 8; i++)
		{
			if (i >= 0 && i <= 2)
			{
				duosushi.setPosition(posboat2[i].x - 0.0f, posboat2[i].y - 0.0f);
			}
			if (i >= 3 && i <= 5)
			{
				sushiboat.setPosition(posboat2[i].x - 10.0f, posboat2[i].y - 15.0f);// -10 -15
			}
			if (i >= 6 && i <= 8)
			{
				dogham.setPosition(posboat2[i].x - 10.0f, posboat2[i].y - 0.0f);
			}
			boat2.setPosition(posboat2[i].x, posboat2[i].y);
			window.draw(boat2);
			window.draw(duosushi);
			window.draw(sushiboat);
			window.draw(dogham);
		}
		//draw boat4
		for (i = 0; i <= 5; i++)
		{
			if (i >= 0 && i <= 1)
			{
				uniship.setPosition(posboat4[i].x, posboat4[i].y);
			}
			if (i >= 2 && i <= 3)
			{
				woodlogboat2.setPosition(posboat4[i].x - 0.0f, posboat4[i].y);
			}
			if (i >= 4 && i <= 5)
			{
				fishboat.setPosition(posboat4[i].x - 0.0f, posboat4[i].y);
			}
			boat4.setPosition(posboat4[i].x, posboat4[i].y);
			window.draw(boat4);
			window.draw(uniship);
			window.draw(fishboat);
			window.draw(woodlogboat2);
		}
		//draw clock
		for (i = 0; i <= 2; i++)
		{
			itemclock.setPosition(posclock[i].x, posclock[i].y);
			window.draw(itemclock);
		}
		//draw boots
		for (i = 0; i <= 2; i++)
		{
			if (allowDraw == 1)
			{
				posboots[2].x = positionview.x + 600;
				posboots[2].y = positionview.y;
			}
			itemboots.setPosition(posboots[i].x, posboots[i].y);
			window.draw(itemboots);
		}
		//draw coin
		for (i = 0; i <= 25; i++)
		{
			if (allowDraw == 1)
			{
				poscoins[25].x = positionview.x + 510;
				poscoins[25].y = positionview.y;
			}
			itemcoins.setPosition(poscoins[i].x, poscoins[i].y);
			window.draw(itemcoins);
		}
		//temp55 = player.getPosition().y;

		window.draw(player);
		window.draw(purple);
		window.draw(purple2);
		window.draw(answertext);
		if (allowDraw == 1)
		{
			window.draw(cointext);
			window.draw(shoetext);
			window.draw(scoretext);
			window.draw(highscoretext);
		}
		window.display();
		window.clear();
	}
	return 0;
}
void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(screenheight * aspectRatio, screenheight);
}
float findPosCarY(sf::RectangleShape colorcar, int poscary, int poscarx, float viewfunc)
{
	poscary = rand() % 4801;

	for (j = 0; j != i; )
	{
		if (poscary % 60 == 0)
		{
			if (poscary >= viewfunc && poscary <= (viewfunc + 670) && !(((poscary + colorcar.getSize().y) > 970) && (poscary < 1300))
				&& !(((poscary + colorcar.getSize().y) > 2460) && (poscary < 2790)) && !(((poscary + colorcar.getSize().y) > 4000) && (poscary < 4320))
				&& !(((poscary + colorcar.getSize().y) > 355) && (poscary < 410)) && !(((poscary + colorcar.getSize().y) > 715) && (poscary < 770))
				&& !(((poscary + colorcar.getSize().y) > 1800) && (poscary < 1860)) && poscary >= 200 && (poscary < 4870))
			{
				realposcary = poscary;
				return realposcary;
				break;
			}
			else
			{
				poscary = rand() % 4801;
			}
		}
		else
		{
			poscary = rand() % 4801;
		}
	}
}

bool Collision(sf::Vector2f posobject, sf::RectangleShape sizeobject, sf::RectangleShape posplayerfunc, sf::RectangleShape playersizefunc)
{
	if (((posplayerfunc.getPosition().x + playersizefunc.getSize().x > posobject.x) && (posplayerfunc.getPosition().x < posobject.x + sizeobject.getSize().x)        // player's horizontal range can touch the platform
		&& (posplayerfunc.getPosition().y + playersizefunc.getSize().y > posobject.y) && (posplayerfunc.getPosition().y < posobject.y + sizeobject.getSize().y)))
	{
		collinreturn = 1;
		return collinreturn;
	}
	else
	{
		collinreturn = 0;
		return collinreturn;
	}
}