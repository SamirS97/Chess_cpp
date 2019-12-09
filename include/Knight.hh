#pragma once
#include "Piece.hh"

class Knight : public Both
{

private:
	virtual char GetPiece() 
	{
		return 'k';
	}


public:
	Knight(char Color) : Both(Color) 
	{
		_t.loadFromFile("images/KnightB.png");
		_S.setTexture(_t);
		if(Color=='Y')
			_S.setColor(sf::Color::Yellow);
	}
	~Knight() {}

	bool Legal_Squares(std::pair<int, int> Start, std::pair<int, int> Target, Piece* Ecq[8][8]) 
	{
		// The Knight has an L-like movement
		if ((Start.second == Target.second + 1) || (Start.second == Target.second - 1)) 
		{
			if ((Start.first == Target.first + 2) || (Start.first == Target.first - 2)) 
			{
				return true;
			}
		}
		if ((Start.second == Target.second + 2) || (Start.second == Target.second - 2)) 
		{
			if ((Start.first == Target.first + 1) || (Start.first == Target.first - 1)) 
			{
				return true;
			}
		}
		return false;
	}
};