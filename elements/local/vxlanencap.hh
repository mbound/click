#ifndef CLICK_VXLANEncap_HH
#define CLICK_VXLANEncap_HH
#include <click/element.hh>
#include "../../include/clicknet/vxlan.h"

CLICK_DECLS

//
// VXLAN encapsulator
// Supports 2 VXLAN formats:
// - Basic VXLAN
// - VXLAN-GPE (WIP)
//

class VXLANEncap : public Element { public:

    VXLANEncap() CLICK_COLD;
    ~VXLANEncap() CLICK_COLD;

    const char *class_name() const	{ return "VXLANEncap"; }
    const char *port_count() const	{ return PORTS_1_1; }
    bool can_live_reconfigure() const   { return true; }
    void add_handlers() CLICK_COLD;

    int configure(Vector<String> &, ErrorHandler *) CLICK_COLD;

    Packet *simple_action(Packet *);

  private:
  	click_vxlan vxlan;
};

CLICK_ENDDECLS
#endif