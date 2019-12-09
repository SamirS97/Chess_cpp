#include "Game.hh"
#include <utility>
using namespace std;


pair<int,int> Game::Change_Scale(int x,int y) 
{

	return Board.Which_Square(x,y);
}

void Game::GetNextMove(pair<int,int> Start, pair<int,int> Target) 
{

	bool ValidMove	= false;

	Piece* CurrentPiece = Board.Ecq[Start.first][Start.second];
	// Check that the piece is the correct color
	if ((CurrentPiece != 0) && (CurrentPiece->GetColor() == PlayerTurn)) 
	{
		// Check that the destination is a valid destination
		if (CurrentPiece->Valid_Move(Start, Target, Board.Ecq)) 
		{
			// Make the move
			Piece* qpTemp = Board.Ecq[Target.first][Target.second];
			Board.Ecq[Target.first][Target.second] = Board.Ecq[Start.first][Start.second];
			Board.Ecq[Start.first][Start.second] = 0;

			// Make sure that the current player is not in check
			if (!Board.King_Chess(PlayerTurn)) 
			{
				delete qpTemp;
				ValidMove = true;
			} 
			else 
			{ // Undo the last move if it makes 
				Board.Ecq[Start.first][Start.second] = Board.Ecq[Target.first][Target.second];
				Board.Ecq[Target.first][Target.second] = qpTemp;
			}
		}
	}

	if (!ValidMove) 
	{
		cout << "Invalid Move!" << endl;
		}
	else
	{
		AlternateTurn();
	}
}

void Game::AlternateTurn() {
	PlayerTurn = (PlayerTurn == 'W') ? 'Y' : 'W';
}

bool Game::IsGameOver() 
{
	// Check that the current player can move
	// If not, we have a stalemate or checkmate
	bool CanMove(false);
	CanMove = Board.Can_Move(PlayerTurn);
	if (!CanMove) {
		if (Board.King_Chess(PlayerTurn)) 
		{
			AlternateTurn();
			cout << "Chessmate !" << PlayerTurn << " Wins !" << endl;
		} 
		else 
		{
			cout << " Stalemate !" << endl;
		}
	}
	return !CanMove;
}




