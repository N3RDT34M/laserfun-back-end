#pragma once
#include "../Utils/CObservable.h"

#include "CAPI_Connector.h"

class CAPI_CommunicationInstance : public CObservable
{
private:
  CAPI_Connector* _connector;

public:
  CAPI_CommunicationInstance(CAPI_Connector* connector);
};

