/*
FILE         : PioneerWorld.h
PROJECT      : The Pioneer Radio project
PROGRAMMER   : Valeriia Rait
FIRST VERSION: 29.07.2023
DESCRIPTION  : This file contains the definition for PioneerWorld  class
*/

#ifndef PIONEERWORLD_H
#define PIONEERWORLD_H

#include "PioneerAM.h"

class PioneerWorld : public PioneerAM {
private:
	const char* radioName;

public:

//PioneerWorld() 
//BRIEF: constructor
//PARAMETERS: void
//RETURNS: void
//DETAILS: constructor that sets the radioName and frequency approproately
	PioneerWorld() : PioneerAM() {
		current_station.AMFreq = 531;  // Set default frequency to 531
		radioName = "PioneerXS440 WRLD";
	}
	
// ~PioneerWorld()
//BRIEF: destructor for the PioneerWorld
//PARAMETERS: void
//RETURNS: void
//DETAILS: this destructor prints ot the destructing message
	virtual ~PioneerWorld() override
	{
		cout << "Destroying " << radioName << " Radio" << endl;
	}


//ScanDown()
//BRIEF: this method scans down the frequency
//PARAMETERS: void
//RETURNS: void
//DETAILS: this method scans the frequency down by one level each time
void ScanDown() override
{
	if (strcmp("AM", band) == 0)
	{
		//if current_station is 530, the current_station becomes 1700
		if (current_station.AMFreq == 531)
		{
			current_station.AMFreq = 1602;
		}
		else
		{
			current_station.AMFreq = current_station.AMFreq - 9;
		}
		//if displayOutput is true, the ouput is displayed
		if (displayOutput)
		{
			printf("\nCurrent station: %f %s\n", current_station.AMFreq, band);
		}
	}
}


//ScanUp()
//BRIEF: this method scans up the frequency
//PARAMETERS: void
//RETURNS: void
//DETAILS: this method scans the frequency up by one level each time
void ScanUp() override
{
	if (strcmp("AM", band) == 0)
	{
		// if current_station is 1602, wrap around to 531
		if (current_station.AMFreq == 1602)
		{
			current_station.AMFreq = 531;
		}
		else
		{
			current_station.AMFreq = current_station.AMFreq + 9;
		}
		// if displayOutput is true, the output is displayed
		if (displayOutput)
		{
			printf("\nCurrent station: %.1f %s\n", current_station.AMFreq, band);
		}
	}
}


// ShowPioneerSettings()
//BRIEF: this function shows all of the current settings 
//PARAMETERS: void
//RETURNS: void
//DETAILS: this class method displays all of the adjustable properties of the PioneerCarRadio
	void ShowPioneerSettings() override {
		printf("\n%s\n", radioName);
		if (IsRadioOn()) {
			printf("Radio is on\n");
			printf("Volume: %d\n", GetVolume());
			printf("Current Station: %.1f %s\n", GetCurrentStation(), GetBand());
			printf("AM Buttons:\n");
			for (int i = 0; i < 5; ++i) {
				printf("%d) %.1f ", i + 1, GetPresets()[i].AMFreq);

			}
			printf("\n");
		}
		else
			printf("Radio is off\n");
	}
};
#endif