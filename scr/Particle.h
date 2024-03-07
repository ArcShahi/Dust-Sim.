#ifndef PARTICLE_H
#define PARTICLE_H


#include <cmath>
#include <SFML\Graphics.hpp>
#include <algorithm>
#include <vector>


class Particle
{

private:
	sf::CircleShape m_dust{};
	sf::Vector2f m_velocity{};
	sf::Color m_color{};
	sf::Vector2f m_position{};


	float getDistance(sf::Vector2f postion);
	sf::Vector2f getNormal(sf::Vector2f otherPostion);

public:
	Particle(int screenWidht, int screenHeight);
	Particle(sf::Vector2f position, sf::Vector2f velocity,sf::Color color);
	Particle() = default;

	void attract(sf::Vector2f positionToAttract, float multiplier);
	void doFriction(float amount);
	void moveIt(int screenWidht, int screenHeight,float dt);
	void drawPixel(sf::RenderWindow& window);


};









#endif // !PARTICLE_H

