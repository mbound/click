#include <click/config.h>
#include <click/args.hh>
#include <click/error.hh>
#include <click/glue.hh>
#include "../../include/clicknet/vxlan.h"
#include "vxlanencap.hh"
CLICK_DECLS

VXLANEncap::VXLANEncap()
{
}

VXLANEncap::~VXLANEncap()
{
}

int
VXLANEncap::configure(Vector<String> &conf, ErrorHandler *errh)
{
    uint32_t vnid = 0;

    if (Args(conf, this, errh)
	   .read_mp("VXLAN_VNID", BoundedIntArg(0, 0xFFFFFF), vnid)
       .read("GPE")
	   .complete() < 0)
	   return -1;
    vxlan.vxlan_vnid = htonl(vnid << 8);
    vxlan.vxlan_flags = 0x08;
    vxlan.vxlan_resv24 = 0x000000;
    vxlan.vxlan_resv8 = 0x00;
    return 0;
}

Packet *
VXLANEncap::simple_action(Packet *p)
{
    // throw an error if packet doesn't have a MAC header OR has MAC header but no payload
    // standard VXLAN should only encapsulate Ethernet packets
    // for GPE, this has to change, more controls are needed for different NEXTPROTO types
    if (!p->mac_header() || p->mac_header() == p->data())
        return errh->error("packet must Ethernet");
    else if (WritablePacket *q = p->push(8)) {
        memmove(q->data(), &vxlan, 8);
        return q;
    } else
	return 0;
}

void
VXLANEncap::add_handlers()
{
    add_read_handler("vxlan_vnid", read_keyword_handler, "0 VXLAN_VNID");
    add_read_handler("vxlan_isgpe", read_keyword_handler, "GPE");
    add_read_handler("gpe_nextproto", read_keyword_handler, "NEXT");
    add_read_handler("gpe_isoam", read_keyword_handler, "OAM");
    add_read_handler("gpe_version", read_keyword_handler, "VER")
}

CLICK_ENDDECLS
EXPORT_ELEMENT(VXLANEncap)