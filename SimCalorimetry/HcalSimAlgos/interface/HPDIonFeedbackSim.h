
// --------------------------------------------------------
// A class to simulated HPD ion feedback noise.
// The deliverable of the class is the ion feedback noise
// for an HcalDetId units of fC or GeV
//
// Project: HPD ion feedback
// Author: T.Yetkin University of Iowa, Feb. 16, 2010
// --------------------------------------------------------

#ifndef HcalSimAlgos_HPDIonFeedbackSim_h
#define HcalSimAlgos_HPDIonFeedbackSim_h

#include "FWCore/ParameterSet/interface/ParameterSetfwd.h"
#include "DataFormats/HcalDetId/interface/HcalDetId.h"
#include "CalibFormats/HcalObjects/interface/HcalDbService.h"
#include "CalibFormats/CaloObjects/interface/CaloSamples.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "SimCalorimetry/CaloSimAlgos/interface/CaloVPECorrection.h"

class CaloShapes;

namespace CLHEP {
  class HepRandomEngine;
}

class HPDIonFeedbackSim: public CaloVPECorrection
{
  public:
    /// need a shaper in order to set thermal noise
    HPDIonFeedbackSim(const edm::ParameterSet&, const CaloShapes * shapes);
    ~HPDIonFeedbackSim() override;
    
    //copied from HFSimParameters.h
    void setDbService(const HcalDbService * service) {theDbService = service;}

    // in units of fC
    double correctPE(const DetId & detId, double npe, CLHEP::HepRandomEngine*) const override;
    double getIonFeedback(DetId detId, double signal, double pedWidth, bool doThermal, bool isInGeV, CLHEP::HepRandomEngine*);

    void addThermalNoise(CaloSamples & samples, CLHEP::HepRandomEngine*);

  private:
    double fCtoGeV(const DetId & detId) const;
    const HcalDbService * theDbService;
    const CaloShapes * theShapes;
};
#endif
