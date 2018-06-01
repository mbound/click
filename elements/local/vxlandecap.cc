/*
 * vxlandecap.{cc,hh} -- strips VXLAN encapsulated packets
 *
 */

#include <click/config.h>
#include <click/args.hh>
#include <click/error.hh>
#include <click/glue.hh>
#include <clicknet/vxlan.h>
//#include <click/packet_anno.hh>
#include "vxlandecap.hh"
CLICK_DECLS

VXLANDecap::VXLANDecap()
{
}

VXLANDecap::~VXLANDecap()
{
}

int
VXLANDecap::configure(Vector<String> &conf, ErrorHandler *errh)
{
    //_anno = true;
    _vnid = 0;
    if (Args(conf, this, errh)
	//.read_p("ANNO", _anno)
        .read_mp("VXLAN_VNID", BoundedIntArg(0, 0xFFFFFF), _vnid)
        .complete() < 0)
        return -1;
    _vnid = htonl(_vnid << 8);
    return 0;
}

Packet *
VXLANDecap::simple_action(Packet *p)
{
    const click_vxlan *vxlan_head = reinterpret_cast<const click_vxlan *>(p->data());
    if (vxlan_head->vxlan_vnid == _vnid) {
        if (WritablePacket *q = p->uniqueify()) {
            q->pull(8);
            p = q;
        } else
            return 0;
    }
    return p;
}

void
VXLANDecap::add_handlers()
{
    add_read_handler("vxlan_vnid", read_keyword_handler, "0 VXLAN_VNID");
    add_write_handler("vxlan_vnid", reconfigure_keyword_handler, "0 VXLAN_VNID");
    //add_read_handler("vxlan_isgpe", read_keyword_handler, "GPE");
    //add_read_handler("gpe_nextproto", read_keyword_handler, "NEXT");
    //add_read_handler("gpe_isoam", read_keyword_handler, "OAM");
    //add_read_handler("gpe_version", read_keyword_handler, "VER");
}


CLICK_ENDDECLS
EXPORT_ELEMENT(VXLANDecap)
