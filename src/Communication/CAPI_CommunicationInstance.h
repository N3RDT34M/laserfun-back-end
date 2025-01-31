#pragma once
#include "CObservable.h"

#include "CAPI_Connector.h"

class CAPI_CommunicationInstance : public CObservable, public CObserver
{
private:
  CAPI_Connector* _connector;

public:
  CAPI_CommunicationInstance(CAPI_Connector* connector);
};

