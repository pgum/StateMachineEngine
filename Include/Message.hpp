#pragma once
#include <string>
using Payload = std::string;
class Message
{
  private:
  Payload payload;
  public:
  Message(const Payload &_payload);
  Message();
  Payload getPayload() const;
};

