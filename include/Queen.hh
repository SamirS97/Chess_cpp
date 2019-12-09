#pragma once
#include "Piece.hh"

class Queen : public Both
{

private:
	virtual char GetPiece() 
	{
		return 'Q';
	}

public:
	Queen(char Color) : Both(Color) 
	{
		_t.loadFromFile("images/QueenB.png");
		_S.setTexture(_t);
		if(Color=='Y')
			_S.setColor(sf::Color::Yellow);
	}
	~Queen() {}

	bool Legal_Squares(std::pair<int, int> Start, std::pair<int, int> Target, Piece* Ecq[8][8]) 
	{
		if (Start.first == Target.first) {
			// Make sure that all in-between squares are empty
			int ColDelta = (Target.second - Start.second > 0) ? 1 : -1;
			for (int TmpCol = Start.second + ColDelta; TmpCol !=  Target.second; TmpCol = TmpCol + ColDelta) 
			{
				if (Ecq[Start.first][TmpCol] != 0) 
				{
					return false;
				}
			}
			return true;
		} 
		else if (Target.second == Start.second) 
		{
			// Make sure that all in-between squares are empty
			int RowDelta = (Target.first - Start.first > 0) ? 1 : -1;
			for (int TmpRow = Start.first + RowDelta; TmpRow !=  Target.first; TmpRow = TmpRow + RowDelta) 
			{
				if (Ecq[TmpRow][Start.second] != 0) 
				{
					return false;
				}
			}
			return true;
		} 
		else if ((Target.second - Start.second == Target.first - Start.first) || (Target.second - Start.second == Start.first - Target.first)) 
		{
			// Make sure that all in-between squares are empty
			int RowDelta = (Target.first - Start.first > 0) ? 1 : -1;
			int ColDelta = (Target.second - Start.second > 0) ? 1 : -1;
			int TmpRow;
			int TmpCol;
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