#include "Particle.h"
#include "chaos.h"

float Particle::getDistance(sf::Vector2f postion)
{
	const float dx = m_position.x - postion.x;
	const float dy = m_position.y - postion.y;
	return std::sqrt((dx * dx) + (dy * dy));
}
sf::Vector2f Particle::getNormal(sf::Vector2f otherPostion)
{
	float distance = getDistance(otherPostion);

	if (distance==0.0f)
	{
		distance = 1.0f;
	}

	const float dx = m_position.x - otherPostion.x;
	const float dy = m_position.y - otherPostion.y;

	sf::Vector2f normal{ dx * (1 / distance),dy * (1 / distance) };
	return normal;
}
Particle::Particle(int screenWidht, int screenHeight)

{
	m_dust.setRadius(1.f);

	m_position.x = arc::getRandomi(0, screenWidht - 1);
	m_position.y = arc::getRandomi(0, screenHeight - 1);
     m_dust.setPosition(m_position);

	m_velocity.x = arc::getRandomf(-100.f, 100.f) / 100.f;
	m_velocity.y = arc::getRandomf(-100.f, 100.f) / 100.f;

	m_dust.move(m_velocity); 

	/*m_color = sf::Color{ 0,0,0,125 };*/
	/*sf::Uint8 Red = static_cast<sf::Uint8>(arc::getRandomi(0, 255));
	sf::Uint8 Green = static_cast<sf::Uint8>(arc::getRandomi(0, 255));
	sf::Uint8 Blue = static_cast<sf::Uint8>(arc::getRandomi(0, 255));
	sf::Uint8 Alpha = 150.f;

	m_color = sf::Color{Red,Green,Blue,Alpha };*/
	m_color = sf::Color{ 250,250,250,100 };

	m_dust.setFillColor(m_color);

}

Particle::Particle(sf::Vector2f position, sf::Vector2f velocity, sf::Color color)
{
	m_position = position;
	m_dust.setPosition(m_position);

	m_velocity = velocity;
	m_dust.move(m_velocity);

	m_color = color;
}

void Particle::attract(sf::Vector2f positionToAttract, float multiplier)
{
	float distance = std::max(getDistance(positionToAttract), 0.5f);

	sf::Vector2f normal = getNormal(positionToAttract);


	m_velocity -= {normal.x / distance, normal.y / distance};
	m_dust.move(m_velocity);


}

void Particle::doFriction(float amount)
{
	m_velocity.x *= amount;
	m_velocity.y *= amount;
	m_dust.move(m_velocity);
}



void Particle::moveIt(int screenWidth, int screenHeight)
{
	// Update position based on velocity and delta time
	m_position += m_velocity*2.0f;

	// Wrap around the screen if particles move out of bounds
	if (m_position.x < 0)
	{
		m_position.x += screenWidth;
	}
	else if (m_position.x >= screenWidth)
	{
		m_position.x -= screenWidth;
	}

	if (m_position.y < 0)
	{
		m_position.y += screenHeight;
	}
	else if (m_position.y >= screenHeight)
	{
		m_position.y -= screenHeight;
	}

	// Update particle position
	m_dust.setPosition(m_position);
}


void Particle::drawPixel(sf::RenderWindow& window)
{

	window.draw(m_dust);
}
