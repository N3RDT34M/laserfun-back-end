#include "../Utils/CObserver.h"
#include "../Utils/CObservable.h"
#include "CAPI_Connector.h"

class CAPI_ConnectorRadio : public CAPI_Connector {
public:
  virtual void startListening() override;
};