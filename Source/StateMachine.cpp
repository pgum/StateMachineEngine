#include "StateMachine.hpp"
#include <iostream>

StateMachine::StateMachine(const Text &_name): running(false), name(_name){}

StateMachine::StateMachine(): StateMachine(""){}

StateMachine::~StateMachine(){}

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

bool StateMachine::isStateMachineCapableToRecieveMessage()
{
  return not (isEmpty() or size() > 1);
}

bool StateMachine::recieve(const Message &m){
  if(isStateMachineCapableToRecieveMessage()){
    std::cout << "SM["<< getName() << "]";
    return states.begin()->handleMessage(m);
  }
  return false;
}

