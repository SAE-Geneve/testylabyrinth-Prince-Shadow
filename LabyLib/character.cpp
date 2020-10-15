#include "character.h"

#include <cmath>
#include <limits>

Character::Character(
	std::pair<int, int> xy, 
	int health_points, 
	int attack, 
	int defence, 
	const std::string& name) :
		xy_(xy),
		health_points_(health_points),
		attack_(attack),
		defence_(defence),
		name_(name) {}

void Character::Attack(Character& enemy) const
{
	// TODO: Complete me! 
	// si distance est proche attaque possible
	//HP cible -= atq attaquant - def cible
	if (Distance(enemy) <= 1)
	{
		enemy.health_points_ -= attack_ - enemy.defence_;
	}
}

bool Character::IsDead() const
{
	// TODO: Complete me!
	if (health_points_ <= 0)
	{
		return true;
	}
	return false;
}

float Character::Distance(const Character& character) const
{
	// TODO: Complete me!
	return std::sqrt(std::pow(xy_.first - character.GetPosition().first, 2.0) + std::pow(xy_.second - character.GetPosition().second, 2.0));
}
