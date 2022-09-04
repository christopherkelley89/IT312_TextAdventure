#include "GameLoop.h"
#include <iostream>

using namespace std;

void Game::WelcomePlayer()
{
	cout << "Welcome to Text Adventure!" << endl << endl;
	cout << "What is your name?" << endl << endl;

	string name;
	cin >> name;
	m_player.SetName(name);

	cout << endl << "Hello " << m_player.GetName() << endl;
}

void Game::GivePlayerOptions() const
{
	cout << "What would you like to do? (Enter a corresponding number)" << endl << endl;
	cout << "1: Quit" << endl << endl;
	cout << "2: Choose Console" << endl << endl;
}

void Game::GetPlayerInput(string& playerInput) const
{
	cin >> playerInput;
}

PlayerOptions Game::EvaluateInput(string& playerInput) const
{
	PlayerOptions chosenOption = PlayerOptions::None;

	if (playerInput.compare("1") == 0)
	{
		cout << "You have chosen to Quit!" << endl << endl;
		chosenOption = PlayerOptions::Quit;
	}
	else if (playerInput.compare("2") == 0)
	{
		//Output Console Options and get input
		cout << "What console would you like to play on? (Enter a corresponding number)" << endl << endl;
		cout << "1: PC" << endl << endl;
		cout << "2: Xbox" << endl << endl;
		cout << "3: Playstation" << endl << endl;
		cout << "4: Steam Deck" << endl << endl;
		cout << "5: Nintendo" << endl << endl;
		cout << "6: Quit" << endl << endl;

		cin >> playerInput;

		//Determine player input and Output
		if (playerInput.compare("1") == 0)
		{
			cout << "You have chosen to play on the PC!" << endl << endl;
			chosenOption = PlayerOptions::PC;
		}
		else if (playerInput.compare("2") == 0)
		{
			cout << "You have chosen to play on the Xbox!" << endl << endl;
			chosenOption = PlayerOptions::Xbox;
		}
		else if (playerInput.compare("3") == 0)
		{
			cout << "You have chosen to play on the Playstation!" << endl << endl;
			chosenOption = PlayerOptions::Playstation;

		}
		else if (playerInput.compare("4") == 0)
		{
			cout << "You have chosen to play on the Steam Deck!" << endl << endl;
			chosenOption = PlayerOptions::SteamDeck;

		}
		else if (playerInput.compare("5") == 0)
		{
			cout << "You have chosen to play on Nintendo!" << endl << endl;
			chosenOption = PlayerOptions::Nintendo;

		}
		else if (playerInput.compare("6") == 0)
		{
			cout << "You have chosen to Quit!" << endl << endl;
			chosenOption = PlayerOptions::Quit;
		}


		else
		{
			cout << "You have chosen an invalid option, Try Again!" << endl << endl;
			chosenOption = PlayerOptions::None;
		}

	}
	//Lets user know an invalid input was selected
	else
	{
		cout << "I do not recognise that option, try again!" << endl << endl;
	}

	return chosenOption;
}

void Game::RunGame()
{
	WelcomePlayer();

	bool shouldEnd = false;
	while (shouldEnd == false)
	{
		GivePlayerOptions();

		string playerInput;
		GetPlayerInput(playerInput);

		shouldEnd = EvaluateInput(playerInput) == PlayerOptions::Quit;
	}
}