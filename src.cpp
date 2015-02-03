#include "src.hpp"
#include <iostream>

Message::Message(const Payload &_payload): payload(_payload){}
Message::Message():Message("Default Msg"){}
Payload Message::getPayload() const{
  return payload;
}

Text State::getName() const{
  return name;
}
State& State::operator=(State rhs){
  swap(*this, rhs);
  return *this;
}
bool State::setName(Text newName){
  name = newName;
}
bool State::operator==(const State &rhs) const
{
  return (getName() == rhs.getName());
}
bool State::operator!=(const State &rhs) const
{
  return not (*this == rhs);
}
State::State(): name(""){}
bool State::handleMessage(const Message &message){
  if(getName() == "")
    return false;
  std::cout << "State["<< getName() << "]: " << message.getPayload() << std::endl;
  return true;
}


std::size_t StateMachine::size() const{
  return states.size();
}

bool StateMachine::addState(const State &state){
  states.emplace_back(state);
  if(states.rbegin()->getName() == "" and size() == 1)
    states.rbegin()->setName("Default State");
  return true;
}
bool StateMachine::setName(const Text &_name){
  name = _name;
  return true;
}
Text StateMachine::getName() const{
  return name;
}
OptionalState StateMachine::getDefaultState(){
  return states.at(0);
}
State& StateMachine::getState(std::size_t stateIndex){
  return states.at(stateIndex);
}

bool StateMachine::start(){
  if((not isRunning()) and (not isEmpty()) and size() < 2)
    running = true;
  return isRunning();
}

bool StateMachine::stop(){
  if(isRunning() and not isEmpty()){
    running = false;
    return true;
  }
  return false;
}
bool StateMachine::isRunning() const{
  return running;
}

bool StateMachine::isEmpty() const{
  return states.size() == 0;
}

bool StateMachine::recieve(const Message &m){
  if(isEmpty() or size() > 1)
    return false;
  if(size() == 1){
    std::cout << "SM["<< getName() << "]";
    return states.begin()->handleMessage(m);
  }
}

StateMachine::StateMachine(const Text &_name): running(false), name(_name){}

StateMachine::StateMachine(): StateMachine(""){}

StateMachine::~StateMachine(){}

