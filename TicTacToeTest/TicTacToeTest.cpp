#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../TicTacToe_Fall2023/TicTacToeBoard.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TicTacToeTest
{
	TEST_CLASS(TicTacToeTest)
	{
	public:

		TicTacToeBoard board;

		TEST_CLASS_INITIALIZE(Board) 
		{	
		}

		TEST_METHOD(TestSomething)
		{

		}

		TEST_METHOD(TestDraw)
		{
			//bool isDraw() - true if no - one has won, false otherwise(e.g.consider - no spaces empty)
			
			Logger::WriteMessage("Testing Draw");
			board.writeSquare(0,0, TicTacToeBoard::X);
			board.writeSquare(0, 1, TicTacToeBoard::X);
			board.writeSquare(0, 2, TicTacToeBoard::X);

			/*
			Testing draw on a win
			*/
			Assert::IsTrue(board.isDraw());
		}

		TEST_METHOD(GameStartPlayerX)
		{
			Logger::WriteMessage("Testing X is selected as first player\n");
			Assert::AreEqual(board.getPlayerName(), 'X');
			Assert::AreNotEqual(board.getPlayerName(), 'O');
		}

		TEST_METHOD(TestMoves) 
		{
			//Assert::writeSquare(int row, int col, char currentPlayer)
			//Assert::getSquareContents(int row, int col)
			//Assert::isSquareEmpty(int row, int col) 
			//Logger::WriteMessage("Testing we can write X & O into different cells\n");
			// write a cell & verify the cell is written correctly
			Assert::IsTrue(board.isSquareEmpty(0, 0));
			board.writeSquare(0, 0, TicTacToeBoard::X);
			Assert::AreEqual(board.getSquareContents(0, 0), 'X');
			Assert::IsFalse(board.isSquareEmpty(0, 0));
		}

		TEST_METHOD(TestException) 
		{
			Logger::WriteMessage("Testing Exception handling in getSquareContents - throw invalid argument");
			board.getSquareContents(3, 1);  // should throw an exception as 3 is invalid
		}

		TEST_METHOD(InvalidMove) {
			//Assert::writeSquare(int row, int col, char currentPlayer)
			// :getSquareContents(int row, int col)
			// :isSquareEmpty(int row, int col) 
			//Logger::WriteMessage("Testing an invalid move 2,3\n");
			Assert::IsTrue(board.isSquareEmpty(2, 3), L"Cell 2,3 is not empty");
			board.writeSquare(2, 3, TicTacToeBoard::X);
			Assert::AreEqual(board.getSquareContents(2, 3), 'X');
			Assert::IsFalse(board.isSquareEmpty(2, 3));
		}

	};
}

/* Board class - method description
* Implementation notes :
* -Player enum is used for both the name of the player& for the player's move
* -lots of Technical debt in this implementation, including need to consistently use BOARD_NUM_ROWS and BOARD_NUM_COLS
*
* constructor - initializes board via resetBoard() method
* resetBoard() - initializes board & number of turns played in current game
* bool isSquareEmpty(int row, int column) - returns true = empty, false otherwise
* bool writeSquare(int row, int column, Player player) - returns false if can’t write square
* char getSquareContents(int row, int column) - returns character in specified square(e.g. 'X', 'O', ' ')
* Player getPlayer() - returns player(enum) whose turn it is
* char getPlayerName() - returns player(character) whose turn it is
* Player nextPlayer() - returns Player(ie enum) of the next player(e.g. if O playing, returns X)
* bool isWinner(Player playerToCheck) - true if the specified player has won, false otherwise
* bool isDraw() - true if no - one has won, false otherwise(e.g.consider - no spaces empty)
**/

/*
Common Test Automation Asserts including Examples
•	Assert::AreEqual(expected, actual, message): Checks if two values are equal.
		 Assert::AreEqual(5, my_function(2, 3), L"my_function should return 5 for inputs 2 and 3");
•	Assert::AreNotEqual(expected, actual, message): Checks if two values are not equal.
		 Assert::AreNotEqual(0, my_function(1, 0), L"my_function should not return 0 for inputs 1 and 0");
•	Assert::IsTrue(condition, message): Checks if a condition is true.
		Assert::IsTrue(my_object.IsValid(), L"my_object should be valid after initialization");
•	Assert::IsFalse(condition, message): Checks if a condition is false.
		Assert::IsFalse(my_object.IsEmpty(), L"my_object should not be empty after adding elements");
•	Assert::IsNull(pointer, message): Checks if a pointer is null.
		Assert::IsNull(my_pointer, L"my_pointer should be null after deletion");
•	Assert::IsNotNull(pointer, message): Checks if a pointer is not null.
		Assert::IsNotNull(my_pointer, L"my_pointer should not be null after allocation");
•	Assert::Fail(message): Forces a test failure with a specified message.
		Assert::Fail(L"This code path should never be reached");

Important Notes:
•	The message parameter in these methods is optional but highly recommended for providing context about the assertion's purpose, especially when a test fails.
•	The string literals used for messages should be wide-character strings (prefixed with L) to be compatible with the framework.
•	These assertions are part of the Microsoft::VisualStudio::CppUnitTestFramework namespace. You typically include the necessary header and use this namespace in your test files.
C++
	#include "CppUnitTest.h"
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;
*/
