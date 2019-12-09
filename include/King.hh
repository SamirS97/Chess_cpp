#pragma once
#include "Piece.hh"

class King : public Both
{

private:
	virtual char GetPiece() 
	{
		return 'K';
	}


public:
	King(char Color) : Both(Color) 
	{
		_t.loadFromFile("images/KingB.png");
		_S.setTexture(_t);
		if(Color=='Y')
			_S.setColor(sf::Color::Yellow);
	}
	~King() {}

	bool Legal_Squares(std::pair<int, int> Start, std::pair<int, int> Target, Piece* Ecq[8][8]) 
	{
		int RowDelta = Target.first - Start.first;
		int ColDelta = Target.second - Start.second;
		if (((RowDelta >= -1) && (RowDelta <= 1)) &&
			((ColDelta >= -1) && (ColDelta <= 1)) && (Ecq[Target.first][Target.second]->GetPiece() != 'K'))
		{
			return true;
		}
		return false;
	}
};	
