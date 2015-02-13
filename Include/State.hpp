#pragma once
#include "Message.hpp"

using Text = std::string;
struct State{
  private:
  Text name;
  
  public:
  State();
  ~State(){}
  State& operator=(State rhs);
  bool operator==(const State &rhs) const;
  bool operator!=(const State &rhs) const;
  Text getName() const;
  void setName(Text newName);
  virtual bool handleMessage(const Message &message);
  
  private:
  friend void swap(State &me, State &other){
    using namespace std;
    swap(me.name, other.name);
  }
};


