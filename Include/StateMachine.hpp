#pragma once
#include <vector>
#include <boost/optional.hpp>
#include "State.hpp"

using OptionalState = boost::optional<State>;
using StatesContainer = std::vector<State>;
using Text = std::string;

class StateMachine{
  int _size;
  bool running;
  StatesContainer states;
  Text name;
  public:
  StateMachine(const Text &_name);
  StateMachine();
  virtual ~StateMachine();
  std::size_t size() const;
  Text getName() const;
  OptionalState getDefaultState();
  State& getState(std::size_t stateIndex);
  bool setName(const Text &_name);
  bool addState(const State &state);
  bool start();
  bool stop();
  bool isRunning() const;
  bool isEmpty() const;
  bool recieve(const Message &m);
};

