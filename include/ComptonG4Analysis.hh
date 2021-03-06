#ifndef _COMPTONG4ANALYSIS_H
#define _COMPTONG4ANALYSIS_H

// GEANT4 Includes
#include <G4UIcommand.hh>

// ROOT Includes
#include <Rtypes.h>

// Pre-defined classes
class TTree;
class TFile;

/*!
 * @class ComptonG4Analysis
 *
 * @brief Default class to process the simulation data
 *
 * This class processes the simulation data, including writing to a ROOT file
 * when the event is finished.
 *
 * @author Juan Carlos Cornejo <cornejo@jlab.org>
 *
 !*/
class ComptonG4Analysis {
public:
  ComptonG4Analysis();
  ~ComptonG4Analysis();

  // Public G4 Analyzer functions
  void Initialize(G4int runnum = 0001);
  void StartOfEvent();
  void EndOfEvent();
  void Finished();
  void CleanEvent();
  void SetAsym(Double_t asym) { fAsym = asym; }
  void SetGammaE(Double_t e) { fGammaE = e; }
  void SetRho(Double_t rho) { fRho = rho; }
  void AddEDep(Double_t e) { fEDep += e; }
  void AddStepSize(Double_t size) { fStepSize += size; }
  void AddEDepAllCharges(Double_t e) { fEDepAll += e; }
  void AddStepSizeAllCharges(Double_t size) { fStepSizeAll += size; }
  void SetTheta(Double_t theta) { fTheta = theta; }
  void SetPhi(Double_t phi) { fPhi = phi; }

private:
  TTree               *fTree;         // Generated TTree
  TFile               *fFile;         // Output TFile
  G4String            fOutputPath;    // Path to output rootfiles

  // Tree variables per event
  Double_t            fAsym;          // Theoretical asymmetry
  Double_t            fRho;           // Normalized Gamma scattering energy
  Double_t            fGammaE;        // Absolute Gamma energy
  Double_t            fEDep;          // Energy deposited in the crystal
  Double_t            fStepSize;      // Total step size
  Double_t            fEDepAll;       // Energy deposited in the crystal due to *all* charges
  Double_t            fStepSizeAll;   // Total step size due o *all* charges
  Double_t            fTheta;         // The scattering angle in Degrees
  Double_t            fPhi;           // The azimuthal angle

  int               fNumberOfEvents;
};

#endif
