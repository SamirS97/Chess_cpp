#pragma once
#include <utility>
#include <SFML/Graphics.hpp>

class Piece
{

private:
	char _Color;
public:
	sf::Sprite _S;
	sf::Texture _t;
	Piece(char Color) : _Color(Color) {}
	virtual ~Piece() {}
	virtual char GetPiece() = 0;
	char GetColor() 
	{
		return _Color;
	}

	bool Valid_Target(std::pair<int, int> Target, Piece* Ecq[8][8])
	{
		Piece* P_Target = Ecq[Target.first][Target.second];
		if ((P_Target == 0) || (_Color != P_Target->GetColor() && P_Target->GetPiece() != 'K'))  //Check target's validity (you can't take the King)
		{
			return true;
		}
		return false;
	}

	virtual bool Legal_Squares(std::pair<int, int> Start, std::pair<int, int> Target, Piece* Ecq[8][8]) = 0;

	bool Valid_Move(std::pair<int, int> Start, std::pair<int, int> Target, Piece* Ecq[8][8]) 
	{
		return (Valid_Target(Target, Ecq) && Legal_Squares(Start,Target,Ecq));
	}

};


class Line : public Piece
{

public:
	Line(char Color) : Piece(Color) {}
	virtual ~Line() {}
};


class Diagonal : public Piece
{

public:
	Diagonal(char Color) : Piece(Color) {}
	virtual ~Diagonal() {}
};


class Both : public Piece
{

public:
	Both(char Color) : Piece(Color) {}
	virtual ~Both() {}
};
