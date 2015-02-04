#include "Message.hpp"

Message::Message(const Payload &_payload): payload(_payload){}

Message::Message():Message("Default Msg"){}
Payload Message::getPayload() const{
  return payload;
}
