/*
FILE         : PioneerAM.h
PROJECT      : The Pioneer Radio project
PROGRAMMER   : Valeriia Rait
FIRST VERSION: 29.07.2023
DESCRIPTION  : This file contains the definition for PioneerAM  class
*/

#ifndef _PIONEERAM_H
#define _PIONEERAM_H

#include "PioneerCarRadio.h"
#include <iostream>
using namespace std;

class PioneerAM : public PioneerCarRadio {
private:
    const char* radioName;
public:

//PioneerAM()
//BRIEF: constructor
//PARAMETERS: void
//RETURNS: void
//DETAILS: constructor that sets the radioname approproately
    PioneerAM() : radioName("PioneerXS440 AM") {}

// ~PioneerAM()
//BRIEF: destructor for the PioneerAM
//PARAMETERS: void
//RETURNS: void
//DETAILS: this destructor prints ot the destructing message
    virtual ~PioneerAM() override
    {
        cout << "Destroying " << radioName << " Radio" << endl;
    }

//ToggleBand()
//BRIEF: stays on the AM band
//PARAMETERS: void
//RETURNS: void
//DETAILS: the method is switching stays on the AM band
    void ToggleBand() override {}


//ShowPioneerSettings()
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
