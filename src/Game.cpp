#include <iostream>
#include "Headers/Game.h"

using namespace std;

Game2::Game2()
{
	name = "";
	price = 0;
	hour = 0;
	cost = 0;

	//cout << "    - Building Game2" << name << "with Default Constructor" << endl;
}

Game2::Game2(const string & title, float value, int time)
{
	name = title;
	price = value;
	hour = time;
	cost = value;

	//cout << "    - Building Game2" << title << "with Custom Constructor" << endl;
}

const Game2& Game2::Compare(
	const Game2& game,
	const Game2& (func)(const Game2&, const Game2&)
) const
{
	return func(*this, game);
}

Game2::~Game2()
{
	//cout << "    - Destruing Game2 " << name << endl;
}

void Game2::Get(const string& title, float price)
{
	name = title;
	price = price;
	hour = 0;
	cost = price;
}

void Game2::Update(float price)
{
	price = price;
	Calculate();
}

void Game2::Play(int time)
{
	hour = hour + time;
	Calculate();
}

void Game2::Display() const
{
	std::cout << name << std::endl;
}

const Game2& TheMostPlayed(const Game2& a, const Game2& b)
{
	if (a.Hours() > b.Hours())
		return a;

	return b;
}

const Game2& TheLeastPlayed(const Game2& a, const Game2& b)
{
	if (a.Cost() > b.Cost())
		return a;

	return b;
}
