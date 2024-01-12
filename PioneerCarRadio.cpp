/*
FILE         : PioneerCarRadio.cpp
PROJECT      : The Pioneer Radio project
PROGRAMMER   : Valeriia Rait
FIRST VERSION: 3.07.2023
DESCRIPTION  : This file contains all the definitions for PioneerCarRadio class
*/
#include "PioneerCarRadio.h"


//~PioneerCarRadio()
//BRIEF: destructor for the PioneerCarRadio
//PARAMETERS: void
//RETURNS: void
//DETAILS: this destructor prints ot the destructing message
PioneerCarRadio :: ~PioneerCarRadio() 
{
    printf("PioneerCarRadio is destroyed\n");
}

//HandleKeypresses()
//BRIEF: this function handles all the input
//PARAMETERS: void
//RETURNS: void
//DETAILS: this class method handles all th variation of the input and exits the orogram if needed
void PioneerCarRadio::HandleKeypresses() {
    printf("Enter a keypress or 'x' to exit: ");

    char keypress;
    while ((keypress = _getch()) != 'x') {

        if (keypress == 'o') {
            PowerToggle();
        }
        else if (keypress == '+') {
            SetVolume(GetVolume() + 1);
        }
        else if (keypress == '_') {
            SetVolume(GetVolume() - 1);
        }
        else if (keypress == '=') {
            ScanUp();
        }
        else if (keypress == '-') {
            ScanDown();
        }
        else if (keypress == 'b') {
            ToggleBand();
        }
        else if (keypress == '1') {
            SelectPresetButton(1);
        }
        else if (keypress == '2') {
            SelectPresetButton(2);
        }
        else if (keypress == '3') {
            SelectPresetButton(3);
        }
        else if (keypress == '4') {
            SelectPresetButton(4);
        }
        else if (keypress == '5') {
            SelectPresetButton(5);
        }
        else if (keypress == '!') {
            SetPresetButton(0);
        }
        else if (keypress == '@') {
            SetPresetButton(1);
        }
        else if (keypress == '#') {
            SetPresetButton(2);
        }
        else if (keypress == '$') {
            SetPresetButton(3);
        }
        else if (keypress == '%') {
            SetPresetButton(4);
        }
        else {
            continue;
        }
        ShowPioneerSettings();
    }
}

//ShowPioneerSettings()
//BRIEF: this function shows all of the current settings 
//PARAMETERS: void
//RETURNS: void
//DETAILS: this class method displays all of the adjustable properties of the PioneerCarRadio
void PioneerCarRadio::ShowPioneerSettings() {
    printf("\n%s\n", radioName);
    if (IsRadioOn()) {
        printf("Radio is on\n");
        printf("Volume: %d\n", GetVolume());
        printf("Current Station: %.1f %s\n", GetCurrentStation(), GetBand());
        printf("AM Buttons:\n");
        for (int i = 0; i < 5; ++i) {
            printf("%d) %.1f ", i + 1, GetPresets()[i].AMFreq);

        }
        printf("\nFM Button Settings:\n");
        for (int j = 0; j < 5; ++j) {
            printf("%d) %.1f ", j + 1, GetPresets()[j].FMFreq);

        }
        printf("\n");
    }
    else
        printf("Radio is off\n");
}