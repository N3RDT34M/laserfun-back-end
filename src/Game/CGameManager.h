#pragma once
#include "../Utils/CEvents.h"
#include "../Utils/CObserver.h"

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

