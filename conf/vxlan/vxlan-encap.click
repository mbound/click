// vxlan-encap.click
//
//
// Simple VXLAN encapsulator config, which uses the VXLANEncap element
// UDP SRC port can be set to a random number
//
//

RatedSource(I.Can.Haz.VXLAN.Plz, 1, 1000) 
	-> EtherEncap(0x0800, 1:1:1:1:1:1, 2:2:2:2:2:2) 
	-> Print(PacketIn) 
	-> VXLANEncap(5555) 
	-> UDPIPEncap(10.99.61.100, 5525, 10.99.55.100, 4789) 
	-> EtherEncap(0x0800, 3:3:3:3:3:3, 4:4:4:4:4:4) 
	-> ToDevice(out0)  
