/*
FILE         : AmFmRadio.cpp
PROJECT      : The Pioneer Radio project
PROGRAMMER   : Valeriia Rait
FIRST VERSION: 03.07.2023
DESCRIPTION  : This file contains all definitions of methods of AmFmRadio clas
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AmFmRadio.h"

//AmFmRadio(bool isOn)
//BRIEF: constructor
//PARAMETERS: bool isOn
//RETURNS: void
//DETAILS: constructor  that indicates whether the radio should be on or not when instantiated. 
AmFmRadio::AmFmRadio(bool isOn)
{
	for (int i = 0; i < 5; ++i)
	{
		button[i].AMFreq = 530;
		button[i].FMFreq = 87.9;
	}
	current_station.AMFreq = 530;  // assigning initial value of frequency of stations
	current_station.FMFreq = 87.9; // assigning initial value of frequency of stations
	previos_frequency = { 0 , 0 };

	strcpy_s(band, "AM");
	strcpy_s(previos_band, "AM");
	previos_volume = 0;
	volume = 0;
	on = isOn;
	displayOutput = false; //initial value of DisplayOutput, so the ScanDown() and ScanDown() will have no output
}

// AmFmRadio(bool isOn, Freqs presetVal[5])
//BRIEF: constructor
//PARAMETERS: bool isOn, Freqs presetVal[5]
//RETURNS: void
//DETAILS: stes the initial value of buttons, frequency based on if the radio on or off
AmFmRadio::AmFmRadio(bool isOn, Freqs presetVal[5])
{
	volume = 0;
	previos_volume = 0;
	displayOutput = false;         //initial value of DisplayOutput, so the ScanDown() and ScanDown() will have no output
	current_station.AMFreq = 530;  // Assign the value to AMFreq member
	current_station.FMFreq = 87.9; // Assign the value to FMFreq member
	strcpy_s(previos_band, "AM");
	for (int i = 0; i < 5; ++i)
	{
		button[i] = presetVal[i];
	}

	if (strcmp(band, "AM") == 0)
	{
		previos_frequency.AMFreq = current_station.AMFreq;
	}
	else
	{
		previos_frequency.FMFreq = current_station.FMFreq;
	}
	on = isOn;
}


//~AmFmRadio()
//BRIEF: destructor
//PARAMETERS: void
//RETURNS: void
//DETAILS: destructor that displays the destroying message
AmFmRadio:: ~AmFmRadio()
{
	if (displayOutput) {
		printf("Destroying AmFmRadio\n");
	}
}


//PowerToggle()
//BRIEF: method that switching the power
//PARAMETERS: void
//RETURNS: void
//DETAILS: method that turns the radio on and off and helps in setting volume
void AmFmRadio::PowerToggle()
{
	if (on == false)
	{
		on = true;
		volume = previos_volume;
	}
	else
	{
		on = false;
		previos_volume = volume;
		volume = 0;
	}
}

//IsRadioOn()
//BRIEF: method ensuring that the radio is on
//PARAMETERS: void
//RETURNS: bool on - the radio is on
//DETAILS: method that checks if the radio is on, and returns the aooropriate output for that
bool AmFmRadio::IsRadioOn()
{
	return on;
}

//SetVolume()
//BRIEF: method of a class that deals with  volume
//PARAMETERS: void
//RETURNS: 0, 1, 2 - returns indicating various situations that occured
//DETAILS: method that prompts the user for input of volume, and sets it or checks for 
//and handles situations when the volume is out of boundaries
int AmFmRadio::SetVolume()
{
	char buf[20] = "";
	printf("\nEnter the volume level (0 - 100). ");
	fgets(buf, sizeof buf, stdin);
	volume = atoi(buf);

	if (volume < 0) //if user enters volume less than 0, volume = 0
	{
		volume = 0;
		return 0;
	}

	if (volume > 100) //if user enters volume greater than 100, volume = 100
	{
		volume = 100;
		return 2;
	}

	return 1;
}

//ToggleBand()
//BRIEF: switches betwenn the radois
//PARAMETERS: void
//RETURNS: void
//DETAILS: the methos is switching between AM and FM radio and sets appropriate frequencies
void AmFmRadio::ToggleBand()
{
	if (strcmp(band, "AM") == 0)
	{
		strcpy_s(band, "FM");
		previos_frequency.FMFreq = current_station.FMFreq;
		current_station.FMFreq = previos_frequency.FMFreq;
	}
	else
	{
		strcpy_s(band, "AM");
		previos_frequency.AMFreq = current_station.AMFreq;
		current_station.AMFreq = previos_frequency.AMFreq;
	}
}

//SetPresetButton(int button_num)
//BRIEF: method that sets the new preset value
//PARAMETERS: int button_num - number of button that needs to be reset
//RETURNS: 0 - success
//DETAILS: it sets selected preset buttonn to new frequency
int AmFmRadio::SetPresetButton(int button_num)
{
	if ((button_num >= 0) && (button_num <= 4))
	{
		if (strcmp("AM", band) == 0)
		{
			button[button_num].AMFreq = current_station.AMFreq;
		}
		else
		{
			button[button_num].FMFreq = current_station.FMFreq;
		}
		return 1;

	}
	return 0;
}

//SelectPresetButton(int button_num)
//BRIEF: selects the preset button
//PARAMETERS: int button_num - number of selected button
//RETURNS: 0 - success
//DETAILS: this method selects the button which needs to be preser
int AmFmRadio::SelectPresetButton(int button_num)
{
	if ((button_num >= 1) && (button_num <= 5))
	{
		if (strcmp("AM", band) == 0)
		{
			current_station.AMFreq = button[button_num - 1].AMFreq;
			previos_frequency.AMFreq = current_station.AMFreq;
		}
		else
		{
			current_station.FMFreq = button[button_num - 1].FMFreq;
			previos_frequency.FMFreq = current_station.FMFreq;
		}

		return 1;
	}
	return 0;
}

//ShowCurrentSettings()
//BRIEF: this method shows the currens setting of a radio
//PARAMETERS: void
//RETURNS: void
//DETAILS: this class method displayls all of the adjustable properties each item something is changed
void AmFmRadio::ShowCurrentSettings()
{
	if (on == true)
	{
		printf("\n\nRadio is on. \n");
	}
	else
	{
		printf("\n\nRadio is off. \n");
	}

	printf("\nRadio Band: %s\n", band);
	printf("Volume: %d\n", volume);
	if (strcmp(band, "AM") == 0)
	{
		printf("Current Station: %.1f %s\n", current_station.AMFreq, band);
	}
	else
	{
		printf("Current Station: %.1f %s\n", current_station.FMFreq, band);
	}
	printf("AM Button Settings: ");
	for (int i = 0; i < 5; ++i)
	{
		printf("%d) %6.1f ", i + 1, button[i].AMFreq);
	}

	printf("\nFM Button Settings: ");
	for (int j = 0; j < 5; ++j)
	{
		printf("%d) %6.1f ", j + 1, button[j].FMFreq);
	}
}

//ScanUp()
//BRIEF: this method scans up the frequency
//PARAMETERS: void
//RETURNS: void
//DETAILS: this method scans the frequency up by one level each time
void AmFmRadio::ScanUp()
{
	if (strcmp("AM", band) == 0)
	{
		//if current_station is 1700, the current_station becomes 530
		if (current_station.AMFreq == 1700)
		{
			current_station.AMFreq = 530;
		}
		else
		{
			current_station.AMFreq = current_station.AMFreq + 10;
		}
		//if displayOutput is true, the ouput is displayed
		if (displayOutput)
		{
			printf("\nCurrent station: %f %s\n", current_station.AMFreq, band);
		}
	}
	else
	{
		//if the current_station is 107.9, the current_station becomes 87.9
		//Note: car radios jump .2 for the FM. That's how it's modeled here.
		if (current_station.FMFreq >= 107.9)
		{
			current_station.FMFreq = 87.9;
		}
		else
		{
			current_station.FMFreq = current_station.FMFreq + .2;
		}
		//if displayOutput is true, the ouput is displayed
		if (displayOutput)
		{
			printf("\nCurrent station: %f %s\n", current_station.FMFreq, band);
		}
	}
}

//ScanDown()
//BRIEF: this method scans down the frequency
//PARAMETERS: void
//RETURNS: void
//DETAILS: this method scans the frequency down by one level each time
void AmFmRadio::ScanDown()
{

	if (strcmp("AM", band) == 0)
	{
		//if current_station is 530, the current_station becomes 1700
		if (current_station.AMFreq == 530)
		{
			current_station.AMFreq = 1700;
		}
		else
		{
			current_station.AMFreq = current_station.AMFreq - 10;
		}
		//if displayOutput is true, the ouput is displayed
		if (displayOutput)
		{
			printf("\nCurrent station: %f %s\n", current_station.AMFreq, band);
		}
	}

	else
	{
		//if the current_station is 107.9, the current_station becomes 87.9
		//Note: car radios jump .2 for the FM. That's how it's modeled here.
		if (current_station.FMFreq <= 87.9)
		{
			current_station.FMFreq = 107.9;
		}
		else
		{
			current_station.FMFreq = current_station.FMFreq - .2;
		}
		//if displayOutput is true, the ouput is displayed
		if (displayOutput)
		{
			printf("\nCurrent station: %f %s\n", current_station.FMFreq, band);
		}
	}
}


//DisplayOutputToggle(bool display)
//BRIEF: mutator for display output variable
//PARAMETERS: bool display
//RETURNS: void
//DETAILS: mutator for display output variable
void AmFmRadio::DisplayOutputToggle(bool display)
{
	displayOutput = display;
}

//SetVolume(int volume)
//BRIEF: mutator for volume
//PARAMETERS:int volume
//RETURNS: void
//DETAILS: mutator for volume that also checks if volume is in boundaries
void AmFmRadio::SetVolume(int newVolume)
{
	volume = newVolume;

	if (volume < 0) //if user enters volume less than 0, volume = 0
	{
		volume = 0;
	}

	if (volume > 100) //if user enters volume greater than 100, volume = 100
	{
		volume = 100;
	}
}

//SetCurrentStation(Freqs newCurStation)
//BRIEF: mutator for current station
//PARAMETERS:Freqs newCurStation
//RETURNS: void
//DETAILS: mutator for current station
void AmFmRadio::SetCurrentStation(Freqs newCurStation) {
	newCurStation = current_station;
}


//GetBand()
//BRIEF: accessor for band
//PARAMETERS:void
//RETURNS: const char * band 
//DETAILS: accessor for band
const char* AmFmRadio::GetBand() const
{
	return band;
}

//GetVolume()
//BRIEF: accessor for volume
//PARAMETERS: void
//RETURNS: int volume
//DETAILS:  accessor for volume
int AmFmRadio::GetVolume()
{
	if (IsRadioOn()) {
		return volume;
	}
	return 0;
}

//GetCurrentStation()
//BRIEF: accessor for current station
//PARAMETERS: void
//RETURNS: Freqs current_station
//DETAILS: accessor for current station
double AmFmRadio::GetCurrentStation()
{
	if (strcmp(GetBand(), "AM") == 0) {
		return current_station.AMFreq;
	}
	else {
		return current_station.FMFreq;
	}
}

//GetPresets()
//BRIEF: accessor for button
//PARAMETERS:void
//RETURNS: Freqs* button
//DETAILS: accessor for button
const Freqs* AmFmRadio::GetPresets() const
{
	Freqs* copy = new Freqs[5];
	memcpy(copy, button, sizeof(Freqs) * 5);
	return copy;
}

//GetDisplayOutput()
//BRIEF: accessor for displayOutpit variable
//PARAMETERS: void
//RETURNS: bool displayOutput
//DETAILS: accessor for displayOutpit variable
bool AmFmRadio::GetDisplayOutput()
{
	return displayOutput;
}