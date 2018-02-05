#ifndef CLICK_VXLANEncap_HH
#define CLICK_VXLANEncap_HH
#include <click/element.hh>
#include "../../include/clicknet/vxlan.h"

CLICK_DECLS

//
// VXLAN encapsulator
// Supports 2 VXLAN formats:
// - Basic VXLAN
// - VXLAN-GPE
//

class VXLANEncap : public Element { public:

    VXLANEncap() CLICK_COLD;
    ~VXLANEncap() CLICK_COLD;

    const char *class_name() const	{ return "VXLANEncap"; }
    const char *port_count() const	{ return PORTS_1_1; }
    void add_handlers() CLICK_COLD;

    int configure(Vector<String> &, ErrorHandler *) CLICK_COLD;
    //void add_handlers() CLICK_COLD;

    Packet *simple_action(Packet *);

  private:

  	click_vxlan vxlan;
    

    //enum { h_vxlan_vnid };
    //static String read_handler(Element *e, void *user_data) CLICK_COLD;

};

CLICK_ENDDECLS
#endif