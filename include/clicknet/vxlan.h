#ifndef CLICKNET_VXLAN_H
#define CLICKNET_VXLAN_H

// Define VXLAN header structure
//
// 8-byte basic VXLAN header
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |R|R|R|R|I|R|R|R|            Reserved                           |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |                VXLAN Network Identifier (VNI) |   Reserved    |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Define VXLAN-GPE header structure
//
// 8-byte VXLAN-GPE header            
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |R|R|Ver|I|P|R|O|       Reserved                |Next Protocol  |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |                VXLAN Network Identifier (VNI) |   Reserved    |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// R = Reserved (MUST be set to 0)
// Ver = default version is 00
// P = 1 if Next protocol is set
// O = 1 if packet is OAM
// Next Protocol (8-bit):
// 		0x1 = IPv4
//		0x2 = IPv6
//		0x3 = Ethernet
//		0x4 = NSH (Network Service Header)
//		0x5 = MPLS

struct click_vxlan {
//#if CLICK_BYTE_ORDER == CLICK_BIG_ENDIAN
	uint8_t vxlan_flags : 8;
    uint32_t vxlan_resv24 : 24;
    uint32_t vxlan_vnid : 24;
    uint8_t vxlan_resv8 : 8;
/*#elif CLICK_BYTE_ORDER == CLICK_LITTLE_ENDIAN
	uint8_t vxlan_resv8 : 8;
	uint32_t vxlan_vnid : 24;
	uint32_t vxlan_resv24 : 24;
	uint8_t vxlan_flags : 8;
#endif */
} CLICK_SIZE_PACKED_ATTRIBUTE;

#endif