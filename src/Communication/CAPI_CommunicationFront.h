#pragma once
#include "CAPI_CommunicationInstance.h"

class CAPI_CommunicationFront : public CAPI_CommunicationInstance {

public:
  CAPI_CommunicationFront(CAPI_Connector* connector);
  virtual void onNotify(const IEvent& event) override;

private:
  void handleJsonRequest(const nlohmann::json& data);
};