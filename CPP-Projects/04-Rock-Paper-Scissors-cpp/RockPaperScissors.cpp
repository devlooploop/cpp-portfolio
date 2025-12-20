/******************************************************************************************

	PROJECT        : Stone Paper Scissors Game (Rock-Paper-Scissors) - Mar-dev
	FILE           : StonePaperScissors.cpp
	LANGUAGE       : C++
	PLATFORM       : Windows Console (uses system("color") and system("cls"))

	DESCRIPTION    :
	This is a complete console-based Stone-Paper-Scissors game where the player
	competes against the computer in multiple rounds (1–10). The game features:

	FEATURES & REQUIREMENTS IMPLEMENTED:
	-----------------------------------------------------------------------
	1. Three choices: Stone (1), Paper (2), Scissors (3)
	2. Player input with full validation
	3. Computer makes random choice using rand()
	4. Correct win logic according to official rules
	5. Multi-round play (user chooses how many rounds)
	6. Tracks Player wins, Computer wins, and Draws
	7. Color-coded results:
		   - Green  : Player wins the round/game
		   - Red    : Computer wins + beep sound
		   - Yellow : Draw
	8. Beautiful formatted output with tabs and lines
	9. Game Over screen + Final results summary
	10. "Play Again" option (Y/N)
	11. Screen clears between games for clean experience
	12. Proper use of enums, structs, functions, and modular design

	NON-FUNCTIONAL REQUIREMENTS:
	- Single executable file
	- No external libraries needed
	- Random seed using current time
	- Input validation (no invalid choices allowed)
	- Windows-only due to system("color") and system("cls")

	COMPILE WITH: g++ StonePaperScissors.cpp -o StonePaperScissors.exe
				  (or use any C++ compiler on Windows)

******************************************************************************************/

#include <iostream>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;
};

struct stGameResults
{
	short GameRounds = 0;
	short Player1WinTimes = 0;
	short Computer2WinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";
};

int RandomNumber(int From, int To)
{
	//Function to generate a random number 
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

string WinnerName(enWinner Winner)
{
	string arrWinnerName[3] = { "Player1","Computer","No Winner" };
	return arrWinnerName[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}
	switch (RoundInfo.Player1Choice)
	{
	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
		{
			return enWinner::Computer;
		} break;
	case enGameChoice::Scissors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
		{
			return enWinner::Computer;
		}
		break;
	}
	//if you reach here then player1 is the winner.
	return enWinner::Player1;
}

string ChoiceName(enGameChoice Choice)
{
	string arrGameChoices[3] = { "Stone","Paper","Scissors" };
	return arrGameChoices[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player1:
		system("color 2F"); //turn screen to Green
		break;
	case enWinner::Computer:
		system("color 4F"); //turn screen to Red        
		cout << "\a";
		break;
	default:
		system("color 6F"); //turn screen to Yellow
		break;
	}
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
	cout << "\n____________Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
	cout << "Player1  Choice: " <<
		ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice: " <<
		ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner   : [" << RoundInfo.WinnerName << "] \n";
	cout << "__________________________________\n" << endl;

		SetWinnerScreenColor(RoundInfo.Winner);

	if (RoundInfo.Winner == enWinner::Player1)
		cout << "             YOU WIN THIS ROUND!\n\n";
	else if (RoundInfo.Winner == enWinner::Computer)
		cout << "             Computer wins this round!\a\n\n";  // beep
	else
		cout << "             It's a DRAW!\n\n";

	
	cout << "           Press ENTER to continue to next round...";
	cin.ignore();    // clear any leftover input
	cin.get();       // wait for Enter key

	// STEP 4: Reset screen color to normal (white on black)
	system("color 0F");
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
	if (Player1WinTimes > ComputerWinTimes)
		return enWinner::Player1;
	else if (ComputerWinTimes > Player1WinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

stGameResults FillGameResults(int GameRounds, short Player1WinTimes,
	short ComputerWinTimes, short DrawTimes)
{
	stGameResults GameResults;

	GameResults.GameRounds = GameRounds;
	GameResults.Player1WinTimes = Player1WinTimes;
	GameResults.Computer2WinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;
}

enGameChoice ReadPlayer1Choice()
{
	short Choice = 1;
	do
	{
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
		cin >> Choice;
	} while (Choice < 1 || Choice >3);
	return (enGameChoice)Choice;
}

enGameChoice GetComputerChoice()
{
	return  (enGameChoice)RandomNumber(1, 3);
}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;

	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begins:\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlayer1Choice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		//Increase win/Draw counters 
		if (RoundInfo.Winner == enWinner::Player1)
			Player1WinTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;

		PrintRoundResults(RoundInfo);
	}

	return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

string  Tabs(short NumberOfTabs)
{
	string t = "";

	for (int i = 1; i < NumberOfTabs; i++)
	{
		t = t + "\t";
		cout << t;
	}
	return t;
}

void ShowGameOverScreen()
{
	cout << Tabs(2) << "__________________________________________________________\n\n";
	cout << Tabs(2) << "                 +++ G a m e  O v e r +++\n";
	cout << Tabs(2) << "__________________________________________________________\n\n";
}

void ShowFinalGameResults(stGameResults GameResults)
{
	cout << Tabs(2) << "_____________________ [Game Results ]_____________________\n\n";
	cout << Tabs(2) << "Game Rounds        : " << GameResults.GameRounds << endl;
	cout << Tabs(2) << "Player1 won times  : " << GameResults.Player1WinTimes << endl;
	cout << Tabs(2) << "Computer won times : " << GameResults.Computer2WinTimes << endl;
	cout << Tabs(2) << "Draw times         : " << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner       : " << GameResults.WinnerName << endl;
	cout << Tabs(2) << "___________________________________________________________\n";

	SetWinnerScreenColor(GameResults.GameWinner);
}

short ReadHowManyRounds()
{
	short GameRounds = 1;
	do
	{
		cout << "How Many Rounds 1 to 10 ? \n";
		cin >> GameRounds;
	} while (GameRounds < 1 || GameRounds >10);

	return GameRounds;
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		stGameResults GameResults = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen();
		ShowFinalGameResults(GameResults);

		cout << endl << Tabs(3) << "Do you want to play again? Y/N? ";

		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{ //Seeds the random number generator in C++, called only once    
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}




























































































































































































































































































































































































