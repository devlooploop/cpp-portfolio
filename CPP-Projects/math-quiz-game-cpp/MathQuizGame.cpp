
/*
    ╔═══════════════════════════════════════════════════════════════════════════╗
    ║                    Math Quiz Game - C++ Console Project                   ║
    ║                                                                           ║
    ║  A fun interactive math quiz game with levels, operations, scoring,       ║
    ║  colored feedback, sound on wrong answers, and play-again feature.        ║
    ╚═══════════════════════════════════════════════════════════════════════════╝

    FEATURES / REQUIREMENTS:
    --------------------------------------------------------------
    ✓ Asks how many questions the player wants (1–10)
    ✓ Choose difficulty: [1] Easy (1-digit), [2] Medium, [3] Hard (2-digit), [4] Mix
    ✓ Choose operation: [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix (random ops)
    ✓ Shows :) for correct answers + GREEN background
    ✓ Shows :( for wrong answers + RED background + beep sound
    ✓ Integer-only answers (e.g., 5 / 2 = 2, not 2.5 → matches school-style math)
    ✓ "Mix" mode randomly picks level or operation each question
    ✓ Final score summary with Pass/Fail result
    ✓ Play again? (Y/N) → resets screen to black and restarts if Yes

    TECHNICAL NOTES:
    --------------------------------------------------------------
    • Built in pure C++ (no external libraries)
    • Uses <iostream>, <ctime>, <cstdlib> (for rand() & system colors)
    • Windows-only features: system("color") and "\a" beep
      → Works perfectly on Windows Command Prompt / Terminal
    • No input validation for letters (keeps code simple & educational)
    • Random seed set with srand(time(NULL))

    COMPILE & RUN (Windows):
        g++ MathQuizGame.cpp -o MathQuizGame.exe
        ./MathQuizGame.exe

    Great for beginners learning enums, structs, functions, and game loops!
*/


#include<iostream>

using namespace std;
 
enum enQuestionsLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5 };

string GetOpTypeSymbol(enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return "+";
	case enOperationType::Sub:
		return "-";
	case enOperationType::Mult:
		return "*";
	case enOperationType::Div:
		return "/";
	default:
		return "Mix";
	}
}

string GetQuestionLevelText(enQuestionsLevel QuestionLevel)
{
	string arrQuestionLevelText[4] = { "Easy", "Med", "Hard", "Mix" };
	return arrQuestionLevelText[QuestionLevel - 1];
}

int RandomNumber(int From, int To)
{
	//Function to generate a random number
	int randNum = rand() % (To - From + 1) + From;
	return randNum;

}

void SetScreenColor(bool Right) {
	if (Right)           
		system("color 2F"); //turn screen to Green
	else     
	{               
		system("color 4F"); //turn screen to Red          
		cout << "\a";
	}     
}

short ReadHowManyQuestions() 
{ 
	short NumberOfQuestions; 
	do 
	{ 
		cout << "How Many Questions do you want to answer ? ";           
		cin >> NumberOfQuestions; 
	} while (NumberOfQuestions < 1 || NumberOfQuestions >10); 
	
	return NumberOfQuestions; 
}

enQuestionsLevel ReadQuestionsLevel() 
{ 
	short QuestionLevel = 0; 
	do 
	{ 
		cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";           
		cin >> QuestionLevel; 
	} while (QuestionLevel < 1 || QuestionLevel >4); 
	
	return (enQuestionsLevel) QuestionLevel; 
}

enOperationType ReadOpType() 
{ 
	short OpType; 
	do 
	{ 
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";           
		cin >> OpType; 
	} while (OpType < 1 || OpType >5); 
	
	return (enOperationType)OpType; 
}

struct stQuestion
{
	int Number1 = 0;
	int Number2 = 0;
	enOperationType OperationType;
	enQuestionsLevel QuestionsLevel;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = false;

};

struct stQuiz
{
	stQuestion QuestionList[100];
	short NumberOfQuestions;
	enQuestionsLevel QuestionsLevel;
	enOperationType OpType;
	short NumberOfWrongAnswers = 0;
	short NumberOfRightAnswers = 0;
	bool isPass = false;
};

int SimpleCalculator(int Number1, int Number2, enOperationType OpType) 
{ 
	switch (OpType) 
	{ 
	case enOperationType::Add: 
		return Number1 + Number2; 
	case enOperationType::Sub: 
		return Number1 - Number2; 
	case enOperationType::Mult: 
		return Number1 * Number2; 
	case enOperationType::Div: 
		return Number1 / Number2; 
	default: 
		return Number1 + Number2; 
	} 
}

enOperationType GetRandomOperationType()
{
	int Op = RandomNumber(1,4);
	return (enOperationType) Op;
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionLevel, enOperationType OpType)
{

	stQuestion Question;

	if (QuestionLevel == enQuestionsLevel::Mix)
	{
		QuestionLevel = (enQuestionsLevel) RandomNumber(1, 3);
	}
	
	if (OpType == enOperationType::MixOp)
	{
		OpType = GetRandomOperationType();
	}

	Question.OperationType = OpType;

	{
		switch (QuestionLevel)
		{
		case enQuestionsLevel::EasyLevel:
			Question.Number1 = RandomNumber(1, 10);
			Question.Number2 = RandomNumber(1, 10);

			Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
			
			Question.QuestionsLevel = QuestionLevel;
			return Question;

		case enQuestionsLevel::MedLevel:
			Question.Number1 = RandomNumber(10, 50);
			Question.Number2 = RandomNumber(10, 50);

			Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
			
			Question.QuestionsLevel = QuestionLevel;
			return Question;

		case enQuestionsLevel::HardLevel:
			Question.Number1 = RandomNumber(50, 100);
			Question.Number2 = RandomNumber(50, 100);

			Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
			
			Question.QuestionsLevel = QuestionLevel;
			return Question;
		}
	}

	return Question;
}

void GenerateQuizQuestions(stQuiz &Quiz)
{
	for (short  Question = 0; Question < Quiz.NumberOfQuestions; Question++)
	{
		Quiz.QuestionList[Question] = GenerateQuestion(Quiz.QuestionsLevel, Quiz.OpType);
	}
}

int ReadQuestionAnswer()
{
	int Answer = 0 ;
	cin >> Answer;
	return Answer;
}

void PrintTheQuestion(stQuiz& Quiz, short QuestionNumber)
{
	cout << "\n";
	cout << "Question [" << QuestionNumber + 1 << "/" << Quiz.NumberOfQuestions << "] \n\n";
	cout << Quiz.QuestionList[QuestionNumber].Number1 << endl;
	cout << Quiz.QuestionList[QuestionNumber].Number2 << " ";
	cout << GetOpTypeSymbol(Quiz.QuestionList[QuestionNumber].OperationType);
	cout << "\n_____________" << endl;
}

void CorrectTheQuestionAnswer(stQuiz& Quiz, short QuestionNumber)
{
	if (Quiz.QuestionList[QuestionNumber].PlayerAnswer != Quiz.QuestionList[QuestionNumber].CorrectAnswer)
	{
		Quiz.QuestionList[QuestionNumber].AnswerResult = false;
		Quiz.NumberOfWrongAnswers++;

		cout << "Wrong Answer :-( \n";
		cout << "The right Answer is: ";
		cout << Quiz.QuestionList[QuestionNumber].CorrectAnswer;
		cout << "\n";
	}
	else
	{
		Quiz.QuestionList[QuestionNumber].AnswerResult = true;
		Quiz.NumberOfRightAnswers++;

		cout << "Right Answer :-) \n";
	}
	cout << endl;

	SetScreenColor(Quiz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionListAnswers(stQuiz& Quiz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++)
	{
		PrintTheQuestion(Quiz, QuestionNumber);

		Quiz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
		
		CorrectTheQuestionAnswer(Quiz, QuestionNumber);
	}

	Quiz.isPass = (Quiz.NumberOfRightAnswers >= Quiz.NumberOfWrongAnswers);
}

string GetFinalResultsText(bool Pass)
{
	if (Pass)
		return "PASS :-)";
	else
		return "Fail :-(";
}

void PrintQuizResults(stQuiz Quiz)
{
	cout << "\n";
	cout << "------------------------\n\n";
	cout << " Final Results is " << GetFinalResultsText(Quiz.isPass);
	cout << "\n------------------------\n\n";

	cout << "Number of Questions: " << Quiz.NumberOfQuestions << endl;
	cout << "Questions Level    : " << GetQuestionLevelText(Quiz.QuestionsLevel) << endl;
	cout << "OpType             : " << GetOpTypeSymbol(Quiz.OpType) << endl;
	cout << "Number of Right Answers: " << Quiz.NumberOfRightAnswers << endl;
	cout << "Number of Wrong Answers: " << Quiz.NumberOfWrongAnswers << endl;
	cout << "------------------------\n\n";
}

void PlayMathGame()
{
	stQuiz Quiz;

	Quiz.NumberOfQuestions = ReadHowManyQuestions();
	Quiz.QuestionsLevel = ReadQuestionsLevel();
	Quiz.OpType = ReadOpType();

	GenerateQuizQuestions(Quiz);
	AskAndCorrectQuestionListAnswers(Quiz);
	PrintQuizResults(Quiz);
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
		PlayMathGame();

		cout << "\nDo you want play again? Y/N? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}


int main()
{
	//Seeds the random number generator in C++, called only once    
	srand((unsigned)time(NULL));

	StartGame();
	
	return 0;
}



































































































































































































































































































































































































