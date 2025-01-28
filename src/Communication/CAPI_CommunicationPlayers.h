#pragma once
#include "../Utils/CObservable.h"
#include "../Utils/CObserver.h"
#include "CAPI_CommunicationInstance.h"
#include "CAPI_Connector.h"

class CAPI_CommunicationPlayers : public CAPI_CommunicationInstance {

public:
  CAPI_CommunicationPlayers(CAPI_Connector* connector);

};