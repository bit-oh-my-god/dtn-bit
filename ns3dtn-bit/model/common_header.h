#ifndef COMMON_HEADER_H
#define COMMON_HEADER_H 

// this file should be the neck of the header dependent graph
// every header file would need outside dependent should include this one
// 
// 

#include <cassert>
#include <iostream>
#include <fstream>
#include <execinfo.h>
#include <cmath>
#include <vector>
#include <cstdio>
#include <type_traits>
#include <sstream>
#include <memory>
#include <algorithm>
#include <string>
#include <map>
#include <tuple>
#include <utility>

#define DEBUG
#define NS3DTNBIT_MAC_MTU 2296  // TODO find out how this value would affect simulation
#define NS3DTNBIT_HYPOTHETIC_NEIGHBOR_BAQ_NUMBER_MAX 100
#define NS3DTNBIT_PORT_NUMBER 1234
#define NS3DTNBIT_BUFFER_CHECK_INTERVAL 0.1
#define NS3DTNBIT_HELLO_PORT_NUMBER 80
#define NS3DTNBIT_HYPOTHETIC_TRANS_SIZE_FRAGMENT_MAX 1472
#define NS3DTNBIT_HELLO_BUNDLE_INTERVAL_TIME 0.1
#define NS3DTNBIT_HELLO_BUNDLE_SIZE_MAX 2280
#define NS3DTNBIT_HYPOTHETIC_BUNDLE_EXPIRED_TIME 750.0
#define NS3DTNBIT_MAX_TRANSMISSION_TIMES 4
#define NS3DTNBIT_ANTIPACKET_EXPIRED_TIME 1000.0
#define NS3DTNBIT_RETRANSMISSION_INTERVAL 15

namespace ns3 {

    namespace ns3dtnbit {
        using std::vector;
        using std::string;
        using std::endl;

        using dtn_time_t = double;
        /* dtn_seqnof_t is used with sign, eg. -(seqno2003) means giving out while (seqno2003) means receiving
         * Important most time the author only check the sequno but not the IP address, which is ok due to the fact that seqnoes were set as the number of Uid. To us, we should use DaemonBundleHeaderInfo to check a pkt, for now, still using Header Uid.
         */
        using dtn_seqnof_t = int32_t;
        using dtn_seqno_t = uint32_t;

    } /* ns3dtnbit */ 
} /* ns3  */ 
#endif /* ifndef COMMON_HEADER_H */
