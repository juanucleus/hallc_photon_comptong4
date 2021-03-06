/*
 * ComptonG4RunMessenger.cc
 *
 *  Created on: November 26, 2012
 *      Author: Juan Carlos Cornejo <cornejo@jlab.org>
 */

#include "ComptonG4RunMessenger.hh"
#include "ComptonG4RunAction.hh"

#include <G4UIcommand.hh>
#include <G4UIcmdWithAnInteger.hh>
#include <G4UIdirectory.hh>

ComptonG4RunMessenger::ComptonG4RunMessenger(
    ComptonG4RunAction *run)
  : fRun(run)
{
  fRunDir = new G4UIdirectory("/Compton/run/");
  fRunDir->SetGuidance("Controls the setup of the run");

  // Set the primary detector specified in the GDML geometry file
  fRunNumberCmd = new G4UIcmdWithAnInteger("/Compton/run/runnumber",this);
  fRunNumberCmd->SetGuidance(
      "Set the runnumber");
  fRunNumberCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
}

ComptonG4RunMessenger::~ComptonG4RunMessenger()
{
  // TODO Cleanup detector messenger
}

void ComptonG4RunMessenger::SetNewValue(
    G4UIcommand *command, G4String newValue )
{
  if( command == fRunNumberCmd ) {
    fRun->SetRunNumber(fRunNumberCmd->GetNewIntValue(newValue));
  }
}

