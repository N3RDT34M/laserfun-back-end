#ifdef __linux__
#include <RF24/RF24.h>
#endif // __linux__


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
#ifdef __linux__
  DataStructure::VestRadioCommunication::VestRadioData data;
  data.action = DataStructure::VestRadioCommunication::Action::HANDSHAKE;
  data.vestid = 1;
  data.data = nullptr;
  Events::Radio::SignalReceived event(data);
  notify(event);
#endif // __linux__
}