#ifndef CLICK_VXLANDecap_HH
#define CLICK_VXLANDecap_HH
#include <click/element.hh>
#include "../../include/clicknet/vxlan.h"

CLICK_DECLS

// 8-byte basic VXLAN header
// +-------+-------+-------+--------+
// | flags |       Reserved         |
// +-------+-------+-------+--------+
// |        VNI            | Rsvd.  |
// +-------+-------+-------+--------+

class VXLANDecap : public Element { public:

    VXLANDecap() CLICK_COLD;
    ~VXLANDecap() CLICK_COLD;

    const char *class_name() const	{ return "VXLANDecap"; }
    const char *port_count() const	{ return PORTS_1_1; }
    bool can_live_reconfigure() const   { return true; }
    void add_handlers() CLICK_COLD;

    int configure(Vector<String> &, ErrorHandler *) CLICK_COLD;
    //void add_handlers() CLICK_COLD;

    Packet *simple_action(Packet *);

private:

    //bool _anno;
    uint32_t _vnid;

};

CLICK_ENDDECLS
#endif