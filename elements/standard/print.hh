#ifndef PRINT_HH
#define PRINT_HH
#include <click/element.hh>
#include <click/string.hh>

/*
 * =c
 * Print(TAG [, MAX_BYTES])
 * =s debugging
 * prints packet contents
 * =d
 * Prints up to MAX_BYTES bytes of data from each packet's header, in hex,
 * preceded by the TAG text. Default MAX_BYTES is 24.
 */

class Print : public Element {
  
  String _label;
  unsigned _bytes;		// How many bytes of a packet to print
  char* _buf;			// To hold print message
  
 public:
  
  Print();
  ~Print();
  
  const char *class_name() const		{ return "Print"; }
  const char *processing() const		{ return AGNOSTIC; }
  
  Print *clone() const;
  int configure(const Vector<String> &, ErrorHandler *);
  
  Packet *simple_action(Packet *);
  
};

#endif
