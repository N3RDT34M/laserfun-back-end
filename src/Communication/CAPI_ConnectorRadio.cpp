#include <RF24/RF24.h>

#include "CAPI_ConnectorRadio.h"
#include "CEvents.h"

CAPI_ConnectorRadio::CAPI_ConnectorRadio()
{

}

void CAPI_ConnectorRadio::startListening()
{ // This is a dummy implementation
  // In a real implementation, this would be a loop that listens for radio signals
  // and then sends them to the observers
  // For the purpose of this exercise, we will just send a dummy signal
  std::vector<uint8_t> data = { 0x01, 0x02, 0x03, 0x04, 0x05 };
  Events::Radio::SignalReceived event(data);
  notify(event);
}