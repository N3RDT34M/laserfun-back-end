#pragma once
#include <string>
#include "CEvents.h"

class CObserver
{
public:
  virtual ~CObserver() = default;
  virtual void onNotify(const IEvent& event) = 0;
};

