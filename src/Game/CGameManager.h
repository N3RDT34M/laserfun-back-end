#pragma once
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

