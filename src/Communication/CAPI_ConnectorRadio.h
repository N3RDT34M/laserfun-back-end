#include "CObserver.h"
#include "CObservable.h"
#include "CAPI_Connector.h"

class CAPI_ConnectorRadio : public CAPI_Connector {
public:
  CAPI_ConnectorRadio();
  virtual void startListening() override;
};