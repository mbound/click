#ifndef FROMBPF_HH
#define FROMBPF_HH

/*
 * =c
 * FromBPF(DEVNAME, PROMISC?)
 * =s devices
 * (deprecated)
 * =d
 *
 * This element has been deprecated. Use FromDevice(DEVNAME, PROMISC?)
 * instead.
 *
 * =a FromDevice.u */

#include <click/element.hh>

class FromBPF : public Element { public:

  FromBPF();
  ~FromBPF();
  
  const char *class_name() const	{ return "FromBPF"; }
  FromBPF *clone() const;
  const char *processing() const	{ return PUSH; }
  
  int configure(const Vector<String> &, ErrorHandler *);

};

#endif
