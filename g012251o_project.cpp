#include <iostream>
#include <chrono>
#include <thread> 

using namespace std;
using namespace this_thread; //used for sleep_until
using namespace chrono; //used for system_clock and seconds

string chooseTransport()
{
	string transportChoice;
	cout << "While you're walking out the house, pick your method of tortu-- I mean! So sorry..." << endl;
	sleep_until(system_clock::now() + seconds(2));
	cout << "\r Pick your method of transport: Bus, Tube or Train.";
	cin >> transportChoice;
	return transportChoice;
}

int main()
{
	bool playerAtDesination = false;
	cout << "You exist." << endl;
	cout << "You are a Londoner." << endl;
	cout << "You are to complete this city's greatest challenge:" << endl;
	sleep_until(system_clock::now() + seconds(5));
	cout << endl << "Defeat TFL during rush hour commute." << endl;

	while playerAtDestination = false{

	}
}

