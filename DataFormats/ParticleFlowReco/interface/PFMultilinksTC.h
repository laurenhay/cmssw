#ifndef __PFMultilinksTC__
#define __PFMultilinksTC__

// Done by Glowinski & Gouzevitch

#include <vector>
#include "DataFormats/Common/interface/RefVector.h"

namespace reco {

  /// \brief Abstract This class is used by the KDTree Track / Ecal Cluster
  /// linker to store all found links.
  ///
  class PFMultiLink;

  /// collection of PFSuperCluster objects
  typedef edm::RefVector<std::vector<PFMultiLink>> PFMultilinksType;

  
  class PFMultiLinksTC {
  public:
    bool isValid;
    PFMultilinksType linkedClusters;

  public:
    PFMultiLinksTC(bool isvalid = false) : isValid(isvalid) {}
  };
}  // namespace reco

#endif
