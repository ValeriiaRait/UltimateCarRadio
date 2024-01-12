/*
FILE         : PioneerCarRadio.h
PROJECT      : The Pioneer Radio project
PROGRAMMER   : Valeriia Rait
FIRST VERSION: 3.07.2023
DESCRIPTION  : This file contains the declaration for PioneerCarRadio class
*/

#ifndef PIONEERCARRADIO_H
#define PIONEERCARRADIO_H

#include "AmFmRadio.h"

#include <stdio.h>
#include <conio.h>
#include <string.h>

//Class:  PioneerCarRadio
//Description: child of AmFmradio class that is constructing a Pioneer Car Radio
//Methods: PioneerCarRadio(),  void HandleKeypresses(), 

class PioneerCarRadio : public AmFmRadio
{

protected:
	const char* radioName; //variable to store radio name
public:
	PioneerCarRadio() : radioName("PioneerXS440") {} //default constructor to set radio name
	virtual ~PioneerCarRadio(); //destructor for  PioneerCarRadio
	void HandleKeypresses() override; //function  to handle all the input
	virtual void ShowPioneerSettings(); //shows all the setings for Pioneer car Radio 
};

#endif

