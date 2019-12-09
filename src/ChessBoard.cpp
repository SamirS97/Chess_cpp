#include "ChessBoard.hh"

using namespace std;


ChessBoard::ChessBoard() 
{
	_t.loadFromFile("images/board.png");
	_S.setTexture(_t);
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			Ecq[i][j] = 0;
		}
	}
	// Allocate and place White pieces
	for (int j = 0; j < 8; ++j) {
		Ecq[1][j] = new Pawn('W');
	}
	Ecq[0][0] = new Rook('W');
	Ecq[0][1] = new Knight('W');
	Ecq[0][2] = new Bishop('W');
	Ecq[0][3] = new King('W');
	Ecq[0][4] = new Queen('W');
	Ecq[0][5] = new Bishop('W');
	Ecq[0][6] = new Knight('W');
	Ecq[0][7] = new Rook('W');

	// Allocate and place Yellow pieces
	for (int j = 0; j < 8; ++j) {
		Ecq[6][j] = new Pawn('Y');
	}
	Ecq[7][0] = new Rook('Y');
	Ecq[7][1] = new Knight('Y');
	Ecq[7][2] = new Bishop('Y');
	Ecq[7][3] = new King('Y');
	Ecq[7][4] = new Queen('Y');
	Ecq[7][5] = new Bishop('Y');
	Ecq[7][6] = new Knight('Y');
	Ecq[7][7] = new Rook('Y');

	//Filling the boundaries of each square
	for (int i = 0; i < 8; ++i) {
		boundaries.push_back(make_pair(8+i*156, 8+(i+1)*156));
	}

}


ChessBoard::~ChessBoard() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			delete Ecq[i][j];
			Ecq[i][j] = 0;
		}
	}
}


bool ChessBoard::King_Chess(char Color) 
{
	// Find the king
	pair <int,int> Pos_King;
	pair <int,int> Pos_piece; 
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (Ecq[i][j] != 0) {
				if (Ecq[i][j]->GetColor() == Color) {
					if (Ecq[i][j]->GetPiece() == 'R') {
						Pos_King.first = i;
						Pos_King.second = j;
					}
				}
			}
		}
	}
	// Run through the opponent's pieces and see if any can take the king
	for (int i = 0; i < 8; ++i) 
	{
		for (int j = 0; j < 8; ++j) 
		{
			if (Ecq[i][j] != 0) 
			{
				if (Ecq[i][j]->GetColor() != Color) 
				{	
					Pos_piece.first = i;
					Pos_piece.second = j;
					if (Ecq[i][j]->Valid_Move(Pos_piece, Pos_King,Ecq)) 
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}


bool ChessBoard::Can_Move(char Color) 
{
	pair <int,int> Start;
	pair <int,int> Target; 
	// Run through all pieces
	for (int i = 0; i < 8; ++i) 
	{
		for (int j = 0; j < 8; ++j) 
		{
			if (Ecq[i][j] != 0) 
			{
				// If it is a piece of the current player, see if it has a legal move
				if (Ecq[i][j]->GetColor() == Color) 
				{
					Start.first = i;
					Start.second = j;
					for (int  k= 0; k < 8; ++k) 
					{
						Target.first = k;
						for (int m = 0; m < 8; ++m) 
						{
							Target.second = m;
							if (Ecq[i][j]->Valid_Move(Start, Target, Ecq)) 
							{
								// Make move and check whether king is in check
								Piece* Temp = Ecq[k][m];
								Ecq[k][m] = Ecq[i][j];
								Ecq[i][j] = 0;
								bool CanMove = !King_Chess(Color);
								// Undo the move
								Ecq[i][j] = Ecq[k][m];
								Ecq[k][m]	= Temp;
								if (CanMove) {
									return true;
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}

void ChessBoard::Set_Pieces()
{
	for(int i = 0; i < 8; i ++)
		for (int j = 0; j < 8; j++)
	{
		if(((Ecq)[i][j] != 0))
		{
			((Ecq)[i][j]->_S).setPosition(34 + j * 158, 25 + i * 158);
		}
	}
}

void ChessBoard::Draw(sf::RenderWindow& w)
{
	w.draw(_S);
	for(int i=0; i<8;++i)
    	for(int j=0; j<8;++j)
    		if(Ecq[i][j] != 0)
    		{
    			w.draw((Ecq[i][j])->_S);
    		} 
}



pair<int,int> ChessBoard::Which_Square(int x,int y) 
{
	int p1,p2;
	for (int i = 0; i < 8; ++i)
	{
		if (x > (boundaries[i]).first && x < (boundaries[i]).second)
			p1=i;
	}

	for(int j = 0; j < 8; ++j)
	{
		if(y > (boundaries[j]).first && y < (boundaries[j]).second)
			p2=j;
	}

	return make_pair(p1,p2);
}

	
bool ChessBoard::Empty_Square(pair <int,int> coord) 
{
	if(Ecq[coord.first][coord.second] == 0)
		return true;
	return false;
}

