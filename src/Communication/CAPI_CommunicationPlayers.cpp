#include "CAPI_CommunicationPlayers.h"
#include "CAPI_CommunicationPlayers.h"

CAPI_CommunicationPlayers::CAPI_CommunicationPlayers(CAPI_Connector* connector) :
  CAPI_CommunicationInstance(connector)
{

}

void CAPI_CommunicationPlayers::onNotify(const IEvent& event)
{
  if (dynamic_cast<const Events::Radio::SignalReceived*>(&event)) {
    const Events::Radio::SignalReceived& e = static_cast<const Events::Radio::SignalReceived&>(event);
    //handleJsonRequest(e._data);
  }
  return;
}
