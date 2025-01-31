#include "CAPI_CommunicationInstance.h"
#include "CAPI_CommunicationInstance.h"

CAPI_CommunicationInstance::CAPI_CommunicationInstance(CAPI_Connector* connector)
  : _connector(connector)
{
  connector->addObserver(this);
}
