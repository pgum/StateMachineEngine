#include <iostream>
#include "State.hpp"

State::State(): name(""){}

State& State::operator=(State rhs){
  swap(*this, rhs);
  return *this;
}

bool State::operator==(const State &rhs) const
{
  return (getName() == rhs.getName());
}

bool State::operator!=(const State &rhs) const
{
  return not (*this == rhs);
}

Text State::getName() const{
  return name;
}

void State::setName(Text newName){
  name = newName;
}

bool State::handleMessage(const Message &message){
  if(getName() == "")
    return false;
  std::cout << "State["<< getName() << "]: " << message.getPayload() << std::endl;
  return true;
}
