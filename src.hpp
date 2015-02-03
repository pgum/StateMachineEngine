#include <cstddef>
#include <memory>
#include <string>
#include <vector>
#include <boost/optional.hpp>

class Message;
class State;
class StateMachine;

using Text = std::string;
using Payload = std::string;
using OptionalState = boost::optional<State>;
class Message
{
  private:
  Payload payload;
  public:
  Message(const Payload &_payload);
  Message();
  Payload getPayload() const;
};

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
  bool setName(Text newName);
  virtual bool handleMessage(const Message &message);
  private:
  friend void swap(State &me, State &other){
    using namespace std;
    swap(me.name, other.name);
  }
};

using StatesContainer = std::vector<State>;
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

