#include "CAPI_Instance.h"

CAPI_Instance::CAPI_Instance(std::shared_ptr<CAPI_GenericConnector> connector)
  : _connector(connector)
{
  
}
