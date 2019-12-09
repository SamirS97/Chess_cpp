#pragma once
#include "Piece.hh"

class Bishop : public Diagonal
{

private:
	virtual char GetPiece()
	{
		return 'B';
	}


public:
	Bishop(char Color) : Diagonal(Color) 
	{
		_t.loadFromFile("images/BishopB.png");
		_S.setTexture(_t);
		if(Color=='Y')
			_S.setColor(sf::Color::Yellow);
	}
	~Bishop() {}

	bool Legal_Squares(std::pair<int, int> Start, std::pair<int, int> Target, Piece* Ecq[8][8]) 
	{
		// Check if it's a diagonal move
		if ((Target.second - Start.second == Target.first - Start.first) || (Target.second - Start.second == Start.first - Target.first)) 
		{
			int RowDelta = (Target.first - Start.first > 0) ? 1 : -1;
			int ColDelta = (Target.second - Start.second > 0) ? 1 : -1;
			int TmpRow;
			int TmpCol;
			// Make sure that all in-between squares are empty
			for (TmpRow = Start.first + RowDelta, TmpCol = Start.second + ColDelta;
				TmpRow !=  Target.first;
				TmpRow = TmpRow + RowDelta, TmpCol = TmpCol + ColDelta)
			{
				if (Ecq[TmpRow][TmpCol] != 0) 
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}	
};