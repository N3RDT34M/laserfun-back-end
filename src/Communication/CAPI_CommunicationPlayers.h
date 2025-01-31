#pragma once
#include "CObservable.h"
#include "CObserver.h"
#include "CAPI_CommunicationInstance.h"
#include "CAPI_Connector.h"

class CAPI_CommunicationPlayers : public CAPI_CommunicationInstance {

public:
  CAPI_CommunicationPlayers(CAPI_Connector* connector);
public:
  void onNotify(const IEvent& event) override;

};