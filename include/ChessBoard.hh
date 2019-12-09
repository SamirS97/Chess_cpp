#pragma once
#include <vector>
#include "Pawn.hh"
#include "Knight.hh"
#include "Bishop.hh"
#include "Rook.hh"
#include "Queen.hh"
#include "King.hh"


class ChessBoard
{

public:
	Piece* Ecq[8][8];
	sf::Sprite _S;
	sf::Texture _t;
	std::vector< std::pair <int,int> > boundaries; 	//To store the boundaries of the squares

	ChessBoard();
	~ChessBoard();
	bool King_Chess(char Color);	//Check if the King is in Check
	bool Can_Move(char Color);	//Check if the player has at least one move left
	void Set_Pieces();
	void Draw(sf::RenderWindow& w);
	std::pair<int,int> Which_Square(int x,int y);	//Return the square of the ChessBoard corresponding to the mouse click 
	bool Empty_Square(std::pair <int,int> coord);	//Check if a square is empty 
};





