#ifndef DISCARD_HH
#define DISCARD_HH
#include <click/element.hh>
#include <click/task.hh>

/*
 * =c
 * Discard
 * =s dropping
 * drops all packets
 * =d
 * Discards all packets received on its single input.
 * If used in a Pull context, it initiates pulls whenever
 * packets are available.
 */

class Discard : public Element { public:
  
  Discard();
  ~Discard();
  
  const char *class_name() const		{ return "Discard"; }
  const char *processing() const		{ return AGNOSTIC; }
  
  Discard *clone() const			{ return new Discard; }
  int initialize(ErrorHandler *);
  void uninitialize();
  void add_handlers();
  
  void push(int, Packet *);
  void run_scheduled();

 private:

  Task _task;
  
};

#endif
