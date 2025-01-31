#pragma once
#include "../Utils/CObservable.h"

class CAPI_Connector : public CObservable
{
public:
  virtual void startListening() = 0;
};

