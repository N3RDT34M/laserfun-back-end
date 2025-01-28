#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

#include "CObserver.h"
#include "CEvents.h"

class CObservable {
private:
  std::vector<CObserver*> _observers;

public:
  void addObserver(CObserver* observer) {
    _observers.push_back(observer);
  }

  void removeObserver(CObserver* observer) {
    _observers.erase(std::remove(_observers.begin(), _observers.end(), observer), _observers.end());
  }

protected:
  void notify(const IEvent& event) {
    for (CObserver* observer : _observers) {
      observer->onNotify(event);
    }
  }
};

