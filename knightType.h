#include <vector>
#include <cmath>
#include <iomanip>

class knightType
{
public:
	//our structure for position
	struct position
	{
		position(int r = 0, int c = 0, int o = 0)
		{
			row = r;
			col = c;
			onwardMoves = o;
		}

		int row;
		int col;
		int onwardMoves;
	};
	//default constructor that takes an input (dim)
	knightType(int dim)
	{
		
		std::vector<int> oneDVector(dim, 0); //We need to make a 1d vector in order to make the custom sized vector based on dim

		for (int i = 0; i < dim; i++)
		{
			board.push_back(oneDVector); //until we reach dim we push back this vector into our board to create a dim x dim board of 0's
;
		}
	}
	//first thing called for our recurisve function
	bool knightTour(int r, int c)
	{
		functionsCalled = 1;
		return knightTour(r, c, 1);
	}
	//to print our board we have to do special format
	void outputTour () const
	{
		//we need the alphabet for the formatting
		char alphabet[26] {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
		
		std::cout << std::setw(2) << std::left << " ";
		for (int k = 0; k < board.size(); k++)
		{
			if(k <= 25) //make sure we don't go out of bounds in our alphabet array
			{
				std::cout << std::setw(2) << std::left << alphabet[k] << " ";
			}
		}

		std::cout << std::endl;
		//nest for loop to print each dimension
		for (int i = 0; i < board.size(); i++)
		{
			if(i <= 25)
			{
				std::cout << std::setw(2) << std::left << alphabet[i];
			}
			for(int j = 0; j < board.size(); j++)
			{

				std::cout << std::setw(2) << std::left << board[i][j] << " ";

			}
			std::cout << std::endl;
		}
		std::cout << "functions called: " << functionsCalled << std::endl;
	}

private:
	//Our recurisve function used to solve the knight tour
	bool knightTour(int r, int c , int tourIndex)
	{
		bool check = 0;
		std::vector<position> availableMoves;

		board[r][c] = tourIndex; //update the current point with the number

		if (this->fullBoard() == true) //this will break us out at the best case (the board is full)
		{
			return true;
		}
		functionsCalled++;

		availableMoves = getAvailableMoves(r, c);
		if(availableMoves.size() == 0) //if there are no availble moves we dont want to keep going
		{
			return true;
		}

		int leastMoves = availableMoves[0].onwardMoves; //we will take the first space as least moves
		int space = 0; //space will track which point in the vector is the least moves
		while(true)
		{
			for(int i = 0; i < availableMoves.size(); i++)
			{
				if (leastMoves <= availableMoves[i].onwardMoves) //check if current spot is <= leastmoves
				{
				}
				else 
				{
					leastMoves = availableMoves[i].onwardMoves;
					space = i;

				}

			}
		

			availableMoves[space].onwardMoves = 9; //so we want to overwrite the space with the least moves because we want to come back to his
			check = knightTour(availableMoves[space].row, availableMoves[space].col, functionsCalled); //revurisvely call, if it is true we break out
			
			if (check == true)
			{
				return true;
			}
		}

	}
	//Function to find availble moves for each move
	std::vector <knightType::position > getAvailableMoves(int r, int c)
	{
		
		int tracker = 0;
		std::vector<position> knightMoves;
		std::vector<position> nextMoves;

		int nextRow = 0;
		int nextCol = 0;

		nextRow = r + 2;
		nextCol = c + 1;
		//we want to check the move and make sure if it's in bouns
		if(nextRow < board.size() && nextCol < board.size())
		{	
			if(board[nextRow][nextCol] == 0)
			{
				knightMoves.push_back(position(0, 0, 0)); //if it is in bounds and also not a move we add it to the vector of possible moves
				knightMoves[tracker].row = nextRow;
				knightMoves[tracker].col = nextCol;
				knightMoves[tracker].onwardMoves = checkMoves(nextRow, nextCol); //check the next moves for this move
				tracker++; //our tracker is important to keep track of the vector

			}
		}

		nextRow = r + 2;
		nextCol = c - 1; //we basically continute the process for all 8 possible moves a knight can make.
		if(nextRow < board.size() && nextCol >= 0)
		{	
			if(board[nextRow][nextCol] == 0)
			{
				knightMoves.push_back(position(0, 0, 0));
				knightMoves[tracker].row = nextRow;
				knightMoves[tracker].col = nextCol;
				knightMoves[tracker].onwardMoves = checkMoves(nextRow, nextCol);
				tracker++;

			}
		}

		nextRow = r - 2;
		nextCol = c + 1;
		if(nextRow >= 0 && nextCol < board.size())
		{	
			if(board[nextRow][nextCol] == 0)
			{
				knightMoves.push_back(position(0, 0, 0));
				knightMoves[tracker].row = nextRow;
				knightMoves[tracker].col = nextCol;
				knightMoves[tracker].onwardMoves = checkMoves(nextRow, nextCol);
				tracker++;

			}
		}

		nextRow = r - 2;
		nextCol = c - 1;
		if(nextRow >= 0 && nextCol >= 0)
		{	
			if(board[nextRow][nextCol] == 0)
			{
				knightMoves.push_back(position(0, 0, 0));
				knightMoves[tracker].row = nextRow;
				knightMoves[tracker].col = nextCol;
				knightMoves[tracker].onwardMoves = checkMoves(nextRow, nextCol);
				tracker++;

			}
		}

		nextRow = r + 1;
		nextCol = c + 2;
		if(nextRow < board.size() && nextCol < board.size())
		{	
			if(board[nextRow][nextCol] == 0)
			{
				knightMoves.push_back(position(0, 0, 0));
				knightMoves[tracker].row = nextRow;
				knightMoves[tracker].col = nextCol;
				knightMoves[tracker].onwardMoves = checkMoves(nextRow, nextCol);
				tracker++;

			}
		}


		nextRow = r + 1;
		nextCol = c - 2;
		if(nextRow < board.size() && nextCol >= 0)
		{	
			if(board[nextRow][nextCol] == 0)
			{
				knightMoves.push_back(position(0, 0, 0));
				knightMoves[tracker].row = nextRow;
				knightMoves[tracker].col = nextCol;
				knightMoves[tracker].onwardMoves = checkMoves(nextRow, nextCol);
				tracker++;

			}
		}

		nextRow = r - 1;
		nextCol = c + 2;
		if(nextRow >= 0 && nextCol < board.size())
		{	
			if(board[nextRow][nextCol] == 0)
			{
				knightMoves.push_back(position(0, 0, 0));
				knightMoves[tracker].row = nextRow;
				knightMoves[tracker].col = nextCol;
				knightMoves[tracker].onwardMoves = checkMoves(nextRow, nextCol);
				tracker++;

			}
		}


		nextRow = r - 1;
		nextCol = c - 2;
		if(nextRow >= 0 && nextCol >= 0)
		{	
			if(board[nextRow][nextCol] == 0)
			{
				knightMoves.push_back(position(0, 0, 0));
				knightMoves[tracker].row = nextRow;
				knightMoves[tracker].col = nextCol;
				knightMoves[tracker].onwardMoves = checkMoves(nextRow, nextCol);
				tracker++;

			}
		}

		return knightMoves; //we return the vector of possible moves

	}
	//Another way to check moves that wont check for onwards moves (this is used to find onward moves without going forever)
	int checkMoves(int r, int c)
	{
		int moveAmount = 0;

		int nextRow = 0;
		int nextCol = 0;

		nextRow = r - 2;
		nextCol = c + 1;
		//it's basically the same as the getAvailableMoves function, however we only need to see how many moves there is.
		if(nextRow >= 0 && nextCol < board.size())
		{	
			if(board[nextRow][nextCol] == 0)
			{
				moveAmount++;
			}
		}

		nextRow = r + 2;
		nextCol = c + 1;
		if(nextRow < board.size() && nextCol < board.size())
		{	
			if(board[nextRow][nextCol] == 0)
			{
				moveAmount++;

			}
		}

		nextRow = r - 1;
		nextCol = c + 2;
		if(nextRow >= 0 && nextCol < board.size())
		{	
			if(board[nextRow][nextCol] == 0)
			{
				moveAmount++;
			}
		}

		nextRow = r + 1;
		nextCol = c + 2;
		if(nextRow < board.size() && nextCol < board.size())
		{	
			if(board[nextRow][nextCol] == 0)
			{
				moveAmount++;
			}
		}

		nextRow = r - 2;
		nextCol = c - 1;
		if(nextRow >= 0 && nextCol >= 0)
		{	
			if(board[nextRow][nextCol] == 0)
			{
				moveAmount++;
			}
		}


		nextRow = r + 2;
		nextCol = c - 1;
		if(nextRow < board.size() && nextCol >= 0)
		{	
			if(board[nextRow][nextCol] == 0)
			{
				moveAmount++;
			}
		}

		nextRow = r - 1;
		nextCol = c - 2;
		if(nextRow >= 0 && nextCol >= 0)
		{	
			if(board[nextRow][nextCol] == 0)
			{
				moveAmount++;
			}
		}


		nextRow = r + 1;
		nextCol = c - 2;
		if(nextRow < board.size() && nextCol >= 0)
		{	
			if(board[nextRow][nextCol] == 0)
			{
				moveAmount++;
			}
		}
		return moveAmount;
	}
	//fullBoard() check's if the board is full or not
	bool fullBoard ()
	{		
		for (int i = 0; i < board.size(); i++)
		{
			for(int j = 0; j < board.size(); j++)
			{
				if(board[i][j] == 0)
				{
					return false; //we check every space on the board and if any are not a move we return false.
				}
			}
		}
		return true;
	}
	std::vector < std::vector <int > > board; //and unitialied 2d vector a simulated chess board for our purposes.
	int functionsCalled;

};