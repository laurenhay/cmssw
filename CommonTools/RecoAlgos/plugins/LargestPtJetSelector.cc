/* \class LargestPtJetSelector
 *
 * selects the N jets with largest Pt
 *
 * \author: Lauren Hay
 *
 */
#include "FWCore/Framework/interface/MakerMacros.h"
#include "CommonTools/UtilAlgos/interface/ObjectSelector.h"
#include "CommonTools/UtilAlgos/interface/SortCollectionSelector.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/JetReco/interface/PFJetCollection.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "DataFormats/JetReco/interface/CaloJet.h"
#include "DataFormats/JetReco/interface/CaloJetCollection.h" 
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "CommonTools/Utils/interface/PtComparator.h"

typedef ObjectSelector<SortCollectionSelector<reco::PFJetCollection, GreaterByPt<reco::PFJet> > > LargestPtPFJetSelector;
typedef ObjectSelector<SortCollectionSelector<reco::GenJetCollection, GreaterByPt<reco::GenJet> > > LargestPtGenJetSelector;
typedef ObjectSelector<SortCollectionSelector<reco::CaloJetCollection, GreaterByPt<reco::CaloJet> > > LargestPtCaloJetSelector;
typedef ObjectSelector<SortCollectionSelector<std::vector<pat::Jet>, GreaterByPt<pat::Jet> > > LargestPtPatJetSelector;



DEFINE_FWK_MODULE(LargestPtPFJetSelector);
DEFINE_FWK_MODULE(LargestPtGenJetSelector);
DEFINE_FWK_MODULE(LargestPtCaloJetSelector);
DEFINE_FWK_MODULE(LargestPtPatJetSelector);
