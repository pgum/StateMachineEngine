#pragma once
#include <string>

using Payload = std::string;

class Message
{
  public:
  Message(const Payload &_payload);
  Message();
  Payload getPayload() const;

  private:
  Payload payload;
};

