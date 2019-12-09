#pragma once
#include "Piece.hh"

class Pawn : public Both
{

private:
	virtual char GetPiece() 
	{
		return 'P';
	}

public:
	Pawn(char Color) : Both(Color) 
	{
		_t.loadFromFile("images/PawnB.png");
		_S.setTexture(_t);
		if(Color=='Y')
			_S.setColor(sf::Color::Yellow);	

	}
	~Pawn() {}

	bool Legal_Squares(std::pair<int, int> Start, std::pair<int, int> Target, Piece* Ecq[8][8]) 
	{

		if (Ecq[Target.first][Target.second] == 0) 
		{
			// Target is empty
			if (Start.second == Target.second) 
			{
				if (GetColor() == 'W') 
				{
					//If it's the first move, the pawn can make a 2 steps move
					if ((Target.first == Start.first + 1) || 
						((Start.first == 1) && (Target.first == Start.first + 2) && (Ecq[Start.first + 1][Start.second] == 0))) 
					{
						return true;
					}
				} 
				else
				{
					if ((Target.first == Start.first - 1) || 
						((Start.first == 6) && (Target.first == Start.first - 2) && (Ecq[Start.first - 1][Start.second] == 0)))
					{
						return true;
					}
				}
			}
		} 
		else 
		{
			// hold piece of opposite color
			if ((Start.second == Target.second + 1) || (Start.second == Target.second - 1)) 
			{
				if (GetColor() == 'W') 
				{
					if (Target.first == Start.first + 1) 
					{
						return true;
					}
				} else 
				{
					if (Target.first == Start.first - 1) 
					{
						return true;
					}
				}
			}
		}
		return false;
	}
};