#ifdef __linux__
#include <RF24/RF24.h>
#endif // __linux__

#include "CObserver.h"
#include "CObservable.h"
#include "CAPI_Connector.h"

class CAPI_ConnectorRadio : public CAPI_Connector {
private:
#ifdef __linux__
  RF24 _radio;
#endif
  DataStructure::VestRadioCommunication::VestActionRadioData _payload;
public:
  CAPI_ConnectorRadio();
  virtual void startListening() override;
};