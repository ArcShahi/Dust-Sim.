#include "Particle.h"
#include <memory>

int main()
{

	const int screenWidht{ 1200 };
	const int screenHeight{ 900 };


	const auto dustCount{ 100'000 };

	auto dust = std::make_unique<Particle[]>(dustCount);

	for (int i = 0; i < dustCount; i++)
	{
		dust[i] = Particle(screenWidht, screenHeight);

	}

	sf::RenderWindow window(sf::VideoMode(screenWidht, screenHeight), "Dust Sim");
	sf::Clock clock{};

	while (window.isOpen())
	{
		//////////////////////////////////////////////////////////////////////////////////////
		//					Handle events									    //
		/////////////////////////////////////////////////////////////////////////////////////
		float dt = clock.restart().asSeconds();
		sf::Event e{};
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		////////////////////////////////////////////////////////////////////////////////////////


		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f mousePosition = window.mapPixelToCoords(pixelPos);

		for (int i = 0; i < dustCount; i++)
		{
			dust[i].attract(mousePosition, 1.0f);
			dust[i].doFriction(0.99f);
			dust[i].moveIt(screenWidht, screenHeight,dt);
		}


		window.clear();


		
		for (int i = 0; i < dustCount; i++)
		{
			dust[i].drawPixel(window);
		}

		window.display();









	}


}