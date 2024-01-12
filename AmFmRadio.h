/*
FILE         : AmFmRadio.h
PROJECT      : The PAmFmProject
PROGRAMMER   : Valeriia Rait
FIRST VERSION: 3.07.2023
DESCRIPTION  : This file contains definition for class and prototypes of AmFmRadio class
*/


#ifndef _AMFMRADIO_H
#define _AMFMRADIO_H

struct Freqs
{
	double AMFreq;
	double FMFreq;
};

class AmFmRadio
{
private:
	Freqs	button[5];
	Freqs   previos_frequency;
	char    previos_band[3];
	int     previos_volume;

	int		volume;
	bool	on;
protected:
	char	band[3];
	bool    displayOutput;
	Freqs	current_station;
	

public:
	//sets the each button to the lowest frequency, sets the current station, sets the
	//frequency to AM, sets the volume to 0 and sets on to false
	AmFmRadio(bool isOn = false);

	//contructor for radio
	AmFmRadio(bool isOn, Freqs presetVal[5]);

	virtual void HandleKeypresses() = 0;

	//destructor
	virtual ~AmFmRadio();

	//sets on to true
	void PowerToggle();

	//returns a true if the radio is currently powered on, and false if the radio is in
	//the off position
	bool IsRadioOn();

	//toggles frequency between AM and FM and sets current station
	virtual void ToggleBand();

	int SetVolume();

	//sets button (radio preset) with current station by being passed a button number
	int SetPresetButton(int button_num);

	//sets current station to radio preset by being passed a button number
	int SelectPresetButton(int button_num);

	//another version of SetVolume taking volume parameter
	void SetVolume(int newVolume);

	//shows volume, button settings, current station, AM or FM
	void ShowCurrentSettings();

	//changes frequency up in increments of .2 for FM, 10 for AM
	virtual void ScanUp();

	//changes frequency down in decrements of .2 for FM, 10 for AM
	virtual void ScanDown();

	//muatator for display output toggle
	void DisplayOutputToggle(bool display);

	//mutator for curent station
	void SetCurrentStation(Freqs newCurStation);
	//accessor for band

	const char* GetBand() const;

	//accessor for volume
	int GetVolume();

	//accessor for current station
	double GetCurrentStation();

	//accessor for Presets variable
	const Freqs* GetPresets() const;

	//accessor for DisplayOutput variable
	bool GetDisplayOutput();

};
#endif

