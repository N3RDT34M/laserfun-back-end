#include "CAPI_CommunicationFront.h"
#include "CAPI_CommunicationFront.h"
#include "CAPI_CommunicationFront.h"

CAPI_CommunicationFront::CAPI_CommunicationFront(CAPI_Connector* connector)
  : CAPI_CommunicationInstance(connector)
{
}

void CAPI_CommunicationFront::onNotify(const IEvent& event)
{
  if (event.getType() == typeid(Events::HTTP::JsonRequestReceived)) {
    const Events::HTTP::JsonRequestReceived& e = static_cast<const Events::HTTP::JsonRequestReceived&>(event);
    handleJsonRequest(e._data);
  }
}

void CAPI_CommunicationFront::handleJsonRequest(const nlohmann::json& data)
{
}
