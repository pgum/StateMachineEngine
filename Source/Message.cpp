#include "Message.hpp"
#include <iostream>

Message::Message(const Payload &_payload): payload(_payload){}

Message::Message():Message("Default Msg"){}

Payload Message::getPayload() const{
  using namespace std;
  return payload;
}
