#pragma once
#include "CEvents.h"
#include "CObserver.h"

class CGameManager : public CObserver
{
public:
  enum class GameState {
    None,
    Init,
    Running,
    Pause,
    End
  };

  virtual void onNotify(const IEvent& event) override;


};

