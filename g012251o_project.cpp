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
class playerHealth {
public:
	string name;
	float physicalHealth = 5.0f;
};

class damageSource {
public:
	string name;
	float damage = 5.0f;
	bool isPhysicalDamage = false;
};

class vapeSmoke : public damageSource {
public:
	vapeSmoke() {
		name = "Vape Smoke";
		damage = 5.0f;
		isPhysicalDamage = true;
	}
};

class delayedService : public damageSource {
public:
	float damage = 3.0f;
};

class embarassment : public damageSource {
public:
	embarassment() {
		name = "Public Embarassment";
		damage = 2.0f;
		isPhysicalDamage = false;
	}
};

string busStage();
string tubeStage();
string busPassing();
string busRideArc();

//Stage progression check -----------------------------------------------------------------
bool firstStageClear = false;
bool secondStageClear = false;
bool thirdStageClear = false;

//Choice functions -----------------------------------------------------------------
string chooseTransport() {
	sleep_until(system_clock::now() + seconds(2));
	cout << "While you're walking out the house, pick your method of tortu-- \n";
	sleep_until(system_clock::now() + seconds(3));
	cout << "Ah, I meant--! So sorry... \n\n";
	sleep_until(system_clock::now() + seconds(3));
	cout << "Pick your method of transport, Bus or Tube: ";
	string transportChoice = "";
	getline(cin, transportChoice);
	transportChoice = caseInsensitive(transportChoice);

	if (transportChoice.empty()) {
		ifErrors(ERROR_EMPTY_INPUT);
		cout << "Invalid choice, try again: ";
		getline(cin, transportChoice); 
		transportChoice = caseInsensitive(transportChoice);
	}

	if (transportChoice == "bus" || transportChoice == "Bus") {
		busStage();
		firstStageClear = true;
	} else if (transportChoice == "tube" || transportChoice == "Tube") {
		tubeStage();
		firstStageClear = true;
	} else {
		ifErrors(ERROR_USER_INPUT);
		cout << "Invalid choice, try again: ";
		getline(cin, transportChoice);
		transportChoice = caseInsensitive(transportChoice);
	}
	return transportChoice;
}

string runBus() {
	cout << "You break into a sprint.\n";
	sleep_until(system_clock::now() + seconds(3));
	cout << "The bus holds at the bus stop, as you approach.\n";
	cout << "There is hope yet!\n";
	sleep_until(system_clock::now() + seconds(5));
	cout << "You make eye contact with the driver as you reach the door.\n";
	cout << "They waited for y--\n";
	sleep_until(system_clock::now() + seconds(2));
	cout << "\nNo, nevermind.\n";
	sleep_until(system_clock::now() + seconds(3));
	cout << "\nThe driver shuts the door in your face and drives away.\n";
	sleep_until(system_clock::now() + seconds(2));

	embarassment embarassment;
	playerHealth player;

	cout << "\n[You take " << embarassment.damage << " emotional damage.]\n";
	cout << "The awkward stand of shame as the bus disappears gets to your self-confidence *just* a little.\n";
	player.physicalHealth -= embarassment.damage;
	if (player.physicalHealth <= 0) {
		sleep_until(system_clock::now() + seconds(2));
		cout << "You have been overwhelmed by public embarassment and melt into a puddle.\n";
		return "Game Over";
	}
	else {
		cout << "\nYou are now at " << player.physicalHealth << " HP.";
	}
	return "To be continued...";

	return busRideArc();
}

string busStage() {
	cout << "\nOn the walk to the bus stop, you pull out your phone.\n";
	sleep_until(system_clock::now() + seconds(2));
	cout << "It'll probably be best to check your bus times app first, but this early in the morning you can feel the thoughts of doom and gloom that await you on your commute beginning to develop.\n";
	sleep_until(system_clock::now() + seconds(5));
	cout << endl << "Do you check your bus times app first (1), or play some music to drown the thoughts out first instead (2)? ";
	int appChoice = 0;
	cin >> appChoice;

	if (appChoice == 1) {
		cout << "\nYou check your bus times app first.\n";
		sleep_until(system_clock::now() + seconds(3));
		cout << "\nIt reads: \n";
		cout << " +------------------------------+\n";
		cout << " | 1  157  Morden          5min |\n";
		cout << " | 2  S2   St Helier Stn   7min |\n";
		cout << " +------------------------------+\n";
		sleep_until(system_clock::now() + seconds(5));
		cout << "\nNo need to rush. You walk past the park and take in the views.\n";
		return busPassing();
	}
	else if (appChoice == 2) {
		cout << "\nThe beautiful baritone of Frank Sinatra's 'My Way' begins to play over your earphones.\n";
		return busPassing();
	}
	else {
		ifErrors(ERROR_USER_INPUT);
		cout << "Invalid choice, try again: ";
		string transportChoice;
		cin >> appChoice;
	}
	return "bus";
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
	cout << "\nThat's your bus.\n";
	sleep_until(system_clock::now() + seconds(3));
	cout << "The app lied. That's your bus, passing by you.\n";
	sleep_until(system_clock::now() + seconds(2));
	cout << "\nDo you run for it (1), or wait for the next one, thinking of what could have been (2)? ";
	int busChoice = 0;
	cin >> busChoice;

	if (busChoice == 1) {
		return runBus();
	} else if (busChoice == 2) {
		cout << "You, for the briefest of moments, consider a *light* speedwalk.\n";
		sleep_until(system_clock::now() + seconds(2));
		cout << "No, It's not worth it. You let the bus slip away and wait for the next one.\n";
		sleep_until(system_clock::now() + seconds(2));
		return busRideArc();
	}
	else {
		ifErrors(ERROR_USER_INPUT);
		cout << "Invalid choice, try again: ";
		string transportChoice;
		cin >> transportChoice;
		return busRideArc();
	}
}

string busRideArc() {
	cout << "\nYou get on the bus. Finally.\n";
	sleep_until(system_clock::now() + seconds(3));
	cout << "Someone behind you hits a vape. The window is open, but any attempt at ventilation is futile.";
	
	vapeSmoke vape;
	playerHealth player;

	cout << "\n[You take " << vape.damage << " physical damage.]\n";
	player.physicalHealth -= vape.damage;
	if (player.physicalHealth <= 0) {
		sleep_until(system_clock::now() + seconds(2));
		cout << "You have been overwhelmed by the vape smoke and suffocate to a swift death.\n";
		return "Game Over";
	} else {
		cout << "You are now at " << player.physicalHealth << " .";
	}
	return "To be continued...";
}

string tubeStage() {
	cout << "\nYou've reached the Tube stage!\n";
	sleep_until(system_clock::now() + seconds(5));
	cout << "...You did better than me, because I ran out of time to code this section due to all the errors VS kept giving me. \n";
	sleep_until(system_clock::now() + seconds(5));
	cout << "\nThere was going to be a section here where you take psychic damage from living somewhere that's a reasonable walking distance from a tube station.\n";
	sleep_until(system_clock::now() + seconds(5));
	cout << "Cause...";
	sleep_until(system_clock::now() + seconds(2));
	cout << "London rent prices.\n";
	sleep_until(system_clock::now() + seconds(5));
	cout << "(Hahaha.)\n";
	sleep_until(system_clock::now() + seconds(5));
	cout << "So sorry... uh...\n\n";
	sleep_until(system_clock::now() + seconds(2));
	cout << "Restart, and try the bus route!";

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

