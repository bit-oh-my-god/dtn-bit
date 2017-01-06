#ifndef COMMON_HEADER_H
#define COMMON_HEADER_H 

// this file should be the neck of the header dependent graph
// every header file would need outside dependent should include this one
// 
// 

#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <utility>

#define NS3DTNBIT_MAC_MTU 2296  // TODO find what this means
#define NS3DTNBIT_HYPOTHETIC_NEIGHBOR_BAQ_NUMBER_MAX 100
#define HNBAQ_MAX NS3DTNBIT_HYPOTHETIC_NEIGHBOR_BAQ_NUMBER_MAX
#define NS3DTNBIT_PORT_NUMBER 50000
#define PORT_NUMBER NS3DTNBIT_PORT_NUMBER
#define NS3DTNBIT_HYPOTHETIC_TRANS_SIZE_MAX 1472
#define TS_MAX NS3DTNBIT_HYPOTHETIC_TRANS_SIZE_MAX
#define NS3DTNBIT_HELLO_BUNDLE_INTERVAL_TIME 0.1
#define HI_TIME HELLO_BUNDLE_INTERVAL_TIME
#define NS3DTNBIT_HELLO_BUNDLE_SIZE_MAX 2280
#define HS_MAX NS3DTNBIT_HELLO_BUNDLE_SIZE_MAX

namespace ns3 {
    
    namespace ns3dtnbit {

        using std::vector;
        
        using dtn_time_t = uint32_t;
        /* dtn_seqnof_t is used with sign, eg. -(seqno2003) means giving out while (seqno2003) means receiving
         * Important ! most time the author only check the sequno but not the IP address //TODO
         */
        using dtn_seqnof_t = int32_t;
        using dtn_seqno_t = uint32_t;
    } /* ns3dtnbit */ 
} /* ns3  */ 
#endif /* ifndef COMMON_HEADER_H */
