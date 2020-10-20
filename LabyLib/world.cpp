#include "world.h"

#include <cassert>
#include <iostream>
#include <limits>

World::World(const std::string& map, int length) : hero_({0, 0})
{
	// TODO: Complete me!
	//retourner la position du joueur sur la carte
	//return hero_.GetPosition();
	std::map<char, int> map_;

	char c;
	for (int i = 0; i < map.size(); ++i)
	{
		std::pair<int, int> pos = { i % length, i / length };
		c = map[i];
		if (c == 'E') 
		{
		map_.insert (std::pair<char,int>('E', i));
		}
		if (c == '.')
		{
		map_.insert(std::pair<char, int>('.', i));
		}
		if (c == '#')
		{
		map_.insert(std::pair<char, int>('#', i));

		}
		if (c == 'P')
		{
			hero_.SetPosition(pos);
			map_.insert(std::pair<char, int>('P', i));
		}
	}
}

void World::EraseDead()
{
	// TODO: Complete me!
	//detruire les cibles ayant 0 hp ou moins
	/*if (enemies_.) 
	{

	}*/
}

bool World::HasEnemies() const
{
	// TODO: Complete me!
	return enemies_.size();
}

std::pair<int, int> World::North(const Character& character) const
{
	// TODO: Complete me!
	//deplacement +1 north si !empty return {0, 0}
	std::pair<int, int> heroPos;
	heroPos = hero_.GetPosition();
	std::pair<int, int> NewPos;
	NewPos.first = heroPos.first;
	NewPos.second = heroPos.second - 1;
	int i = heroPos.first + heroPos.second * 24; // *map_.length => chiffre magique
	for (int i = 0; i < map_.size(); ++i)
	{
	
		if (i != '.')
		{
			return { 0, 0 }; //ne bouge pas
	    }
	}	  
	return { 0, -1 }; //return deplacement
}

std::pair<int, int> World::South(const Character& character) const
{
	// TODO: Complete me!
	//deplacement +1 south si !empty return {0, 0}
	std::pair<int, int> heroPos;
	heroPos = hero_.GetPosition();
	std::pair<int, int> NewPos;
	NewPos.first = heroPos.first;
	NewPos.second = heroPos.second + 1;
	int i = heroPos.first + heroPos.second * 24; // *map_.length => chiffre magique
		/*if (map_ != '.')
		{
			return { 0, 0 }; //ne bouge pas
		}*/
	return { 0, +1 }; //return deplacement
}

std::pair<int, int> World::East(const Character& character) const
{
	// TODO: Complete me!
	//deplacement +1 east si !empty return {0, 0}
	std::pair<int, int> heroPos;
	heroPos = hero_.GetPosition();
	std::pair<int, int> NewPos;
	NewPos.first = heroPos.first + 1;
	NewPos.second = heroPos.second;
	int i = heroPos.first + heroPos.second * 24; // *map_.length => chiffre magique
		/*if (map_ != '.')
		{
			return { 0, 0 }; //ne bouge pas
		}*/
	return { +1, 0 }; //return deplacement
}

std::pair<int, int> World::West(const Character& character) const
{
	// TODO: Complete me!
	//deplacement +1 west si !empty return {0, 0}
	std::pair<int, int> heroPos;
	heroPos = hero_.GetPosition();
	std::pair<int, int> NewPos;
	NewPos.first = heroPos.first - 1;
	NewPos.second = heroPos.second;
	int i = heroPos.first + heroPos.second * 24; // *map_.length => chiffre magique
		/*if (map_ != '.')
		{
			return { 0, 0 }; //ne bouge pas
		}*/
	return { -1, 0 }; //return deplacement
}

void World::HeroAttack()
{
	// TODO: Complete me!
	//attaquer uniquement les enemies disponible
	for each (Enemy var in enemies_)
	{
			hero_.Attack(var);
	}


}

void World::ShowMap() const
{
	// Show the maze to the user.
	std::cout << "Maze :\n";
	for (int i = -1; i < 2; ++i)
	{
		std::cout << "\t +---+---+---+\n\t";
		for (int j = -1; j < 2; ++j)
		{
			auto pair = std::pair<int, int>(
				hero_.GetPosition().first + j,
				hero_.GetPosition().second + i);
			std::cout << " | " << GetTile(pair);
		}
		std::cout << " |\n";
	}
	std::cout << "\t +---+---+---+\n\n";
}

void World::ShowHero() const
{
	// Show the player info the user.
	std::cout 
		<< "Player(" 
		<< hero_.GetPosition().first 
		<< ", " 
		<< hero_.GetPosition().second 
		<< ") :\n";
	std::cout << "\tname       : " << hero_.GetName() << "\n";
	std::cout << "\thit points : " << hero_.GetHealthPoints() << "\n";
	std::cout << "\n";
}

void World::ShowEnemies() const
{
	// Show the enemy that are within view of the user.
	for (const auto& enemy : enemies_)
	{
		float dist = enemy.Distance(hero_);
		if (std::abs(dist - 1.0f) < std::numeric_limits<float>::epsilon()) 
		{
			std::cout
				<< "Enemy(" 
				<< enemy.GetPosition().first 
				<< ", " 
				<< enemy.GetPosition().second 
				<< ")\n";
			std::cout << "\tname       : " << enemy.GetName() << "\n";
			std::cout << "\thit points : " << enemy.GetHealthPoints() << "\n";
			std::cout << "\n";
		}
	}
}

void World::EnemyAttack()
{
	// TODO: Complete me!
	//enemy atq player si proche
	/*if (Distance(Hero) <= 1)
	{
		character.health_points_ -= attack_ - character.defence_
	}*/
}

std::pair<int, int> World::CheckPosition(
	std::pair<int, int> begin, 
	std::pair<int, int> end) const
{
	// TODO: Complete me!
	return { 0, 0 };
}

char World::GetTile(std::pair<int, int> xy) const
{
	// TODO: Complete me!
	return '#';
}
