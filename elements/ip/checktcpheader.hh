#ifndef CHECKTCPHEADER_HH
#define CHECKTCPHEADER_HH

/*
 * =c
 * CheckTCPHeader()
 * =s TCP, checking
 * checks TCP header on TCP/IP packets
 * =d
 * Expects TCP/IP packets as input.
 * Checks that the TCP header length and checksum fields are valid.
 * Pushes invalid packets out on output 1, unless output 1 was unused;
 * if so, drops invalid packets.
 *
 * =a CheckIPHeader, CheckUDPHeader, MarkIPHeader
 */

#include <click/element.hh>
#include <click/glue.hh>

class CheckTCPHeader : public Element {

  int _drops;
  
 public:
  
  CheckTCPHeader();
  ~CheckTCPHeader();
  
  const char *class_name() const		{ return "CheckTCPHeader"; }
  const char *processing() const		{ return "a/ah"; }
  void notify_noutputs(int);
  
  int drops() const				{ return _drops; }
  
  CheckTCPHeader *clone() const;
  void add_handlers();

  Packet *simple_action(Packet *);
  /* inline Packet *smaction(Packet *);
     void push(int, Packet *p);
     Packet *pull(int); */

};

#endif
