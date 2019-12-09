#pragma once
#include <iostream>
#include "ChessBoard.hh"
#include <SFML/Graphics.hpp>

class Game
{
public:
	ChessBoard Board;
	char PlayerTurn;

	Game() : PlayerTurn('W') {}
	~Game(){}
	
	void Set_Board(){Board.Set_Pieces();}
	bool IsGameOver();
	void AlternateTurn();
	void GetNextMove(std::pair<int,int> Depart, std::pair<int,int> Arrivee);
	std::pair<int,int> Change_Scale(int x,int y);
	void Draw_Chess(sf::RenderWindow& w){Board.Draw(w);}
};