#include <iostream>
#include <chrono>
#include <thread> 
#include <string> 

using namespace std;
using namespace this_thread; //used for sleep_until
using namespace chrono; //used for system_clock and seconds

// Error checks ---------------------------------------------------------
enum errorMsgs {
	ERROR_USER_INPUT = 1,
	ERROR_EMPTY_INPUT = 2
};

void ifErrors(int errorCode) {
	switch (errorCode) {
	case ERROR_USER_INPUT:
		cerr << "[!] ERROR: Invalid input, text needed.\n";
		break;
	case ERROR_EMPTY_INPUT:
		cerr << "[!] ERROR: Invalid input, nothing entered.\n";
		break;
	default:
		cerr << "[!] ERROR: Unknown error.\n";
		break;
	}
}

string caseInsensitive(string input) {
	input.erase(0, input.find_first_not_of(' '));  // Remove leading spaces
	input.erase(input.find_last_not_of(' ') + 1); // Remove trailing spaces
	return input;
}

//Declarations for damage sources & types and stage functions --------------------------------------------
class damageSource {
public:
	string name;
	float damage = 5.0;
	bool isPhysicalDamage = false;
};

class vapeSmoke : public damageSource {
public:
	bool isPhysicalDamage = true;
};

class delayedService : public damageSource {
public:
	float damage = 3.0;
};

string busStage();
string tubeStage();
string trainStage();
string timesCheck();
string musicCheck();
string busPassing();

//Stage progression check -----------------------------------------------------------------
bool firstStageClear = false;
bool secondStageClear = false;
bool thirdStageClear = false;

//Choice functions -----------------------------------------------------------------
string chooseTransport() {
	sleep_until(system_clock::now() + seconds(2));
	cout << "While you're walking out the house, pick your method of tortu-- \n";
	sleep_until(system_clock::now() + seconds(3));
	cout << "Ah, I meant--! So sorry... \n";
	sleep_until(system_clock::now() + seconds(3));
	cout << "Pick your method of transport: Bus, Tube or Train: ";
	string transportChoice;
	getline(cin, transportChoice);
	transportChoice = caseInsensitive(transportChoice);

	if (transportChoice == "bus" || transportChoice == "Bus") {
		busStage();
		firstStageClear = true;
	} else if (transportChoice == "tube" || transportChoice == "Tube") {
		tubeStage();
		firstStageClear = true;
	} else if (transportChoice == "train" || transportChoice == "Train") {
		trainStage();
		firstStageClear = true;
	} else {
		ifErrors(ERROR_USER_INPUT);
	}
	return transportChoice;
}

string busStage() {
	cout << "On the walk to the bus stop, you pull out your phone.\n";
	cout << "It'll probably be best to check your bus times app first, but this early in the morning you can feel the thoughts of doom and gloom that await you on your commute beginning to develop.\n";
	sleep_until(system_clock::now() + seconds(3));
	cout << endl << "Do you check your bus times app first (1), or play some music to drown the thoughts out first instead (2)? ";
	int appChoice = 0;
	cin >> appChoice;

	if (appChoice == 1) {
		timesCheck();
	}
	else if (appChoice == 2) {
		musicCheck();
	}
	return "bus";
}

string tubeStage() {
	cout << "You've reached the tube stage.";
	return "tube";
}

string trainStage() {
	cout << "You've reached the train stage.";
	return "train";
}

string timesCheck() {
	cout << "\nYou check your bus times app first.\n";
	sleep_until(system_clock::now() + seconds(3));
	cout << "It reads: \n";
	cout << " +------------------------------+\n";
	cout << " | 1  157  Morden          5min |\n";
	cout << " | 2  S2   St Helier Stn   7min |\n";
	cout << " +------------------------------+\n";
	sleep_until(system_clock::now() + seconds(5));
	cout << "No need to rush. You walk past the park and take in the views.\n";
	return busPassing();
}

string musicCheck() {
	cout << "The beautiful baritone of Frank Sinatra's 'My Way' begins to play over your earphones.";
	return busPassing();
}

string busPassing() {
	sleep_until(system_clock::now() + seconds(2));
	cout << "It's the simple things in life, really.\n";
	sleep_until(system_clock::now() + seconds(2));
	cout << "The sunrise peeking over the trees.\n";
	sleep_until(system_clock::now() + seconds(2));
	cout << "The morning dew on the grass.\n";
	sleep_until(system_clock::now() + seconds(2));
	cout << "The smell of cof-\n";
	cout << "That's your bus.\n";
	sleep_until(system_clock::now() + seconds(2));
	cout << "...Huh.";
	sleep_until(system_clock::now() + seconds(5));
	cout << "The app lied. That's your bus, passing by you.\n\n";
	cout << "Do you run for it?";

	//doing this return for now til i can link it to somth else
	return 0;
}
int main() {

// Game intro -----------------------------------------------------------------------
	bool playerAtDesination = false;
	cout << "You exist." << endl;
	sleep_until(system_clock::now() + seconds(3));
	cout << "You are a Londoner." << endl;
	sleep_until(system_clock::now() + seconds(3));
	cout << "You are to complete this city's greatest challenge:" << endl;
	sleep_until(system_clock::now() + seconds(5));
	cout << endl << "Survive the morning rush hour.\n" << endl;

	chooseTransport();
	
	return 0;
}

