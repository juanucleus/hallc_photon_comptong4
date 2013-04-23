////////////////////////////////////////////////////////////////////////////////
//
//
////////////////////////////////////////////////////////////////////////////////

#include "ComptonG4DetectorConstruction.hh"
#include "ComptonG4DetectorConstructionMessenger.hh"
#include <G4VPhysicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4ThreeVector.hh>

// GEANT4 Geometry related includes
#include <G4GDMLParser.hh>

ComptonG4DetectorConstruction::ComptonG4DetectorConstruction(): fPhysicsWorld(0)
{
  // Create an instance of the messenger class
  fMessenger = new ComptonG4DetectorConstructionMessenger(this);
}

ComptonG4DetectorConstruction::~ComptonG4DetectorConstruction()
{
}


G4VPhysicalVolume*  ComptonG4DetectorConstruction::Construct()
{
  return fPhysicsWorld;
}

void ComptonG4DetectorConstruction::ActivateDetector(G4String)
{
}

void ComptonG4DetectorConstruction::SetGeometryFile(G4String file)
{
  G4GDMLParser parser;
  parser.Read(file);
  fPhysicsWorld = parser.GetWorldVolume();
}
