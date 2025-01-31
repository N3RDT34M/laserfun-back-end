#include "CAPI_CommunicationFront.h"
#include "DataStructures.h"

CAPI_CommunicationFront::CAPI_CommunicationFront(CAPI_Connector* connector)
  : CAPI_CommunicationInstance(connector)
{
}

void CAPI_CommunicationFront::onNotify(const IEvent& event)
{
  if (dynamic_cast<const Events::HTTP::JsonRequestReceived*>(&event)) {
    const Events::HTTP::JsonRequestReceived& e = static_cast<const Events::HTTP::JsonRequestReceived&>(event);
    handleJsonRequest(e._data);
  }
  return;
}

void CAPI_CommunicationFront::handleJsonRequest(const nlohmann::json& data)
{

}
