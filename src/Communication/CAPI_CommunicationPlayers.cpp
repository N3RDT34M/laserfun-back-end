#include "CAPI_CommunicationPlayers.h"
#include "DataStructures.h"

CAPI_CommunicationPlayers::CAPI_CommunicationPlayers(CAPI_Connector* connector) :
  CAPI_CommunicationInstance(connector)
{

}

void CAPI_CommunicationPlayers::onNotify(const IEvent& event)
{
  if (dynamic_cast<const Events::Radio::SignalReceived*>(&event)) {
    const Events::Radio::SignalReceived& e = static_cast<const Events::Radio::SignalReceived&>(event);
    handleSignalReceived(e._data);
  }
  return;
}

void CAPI_CommunicationPlayers::handleSignalReceived(const DataStructure::VestRadioCommunication::VestActionRadioData& data)
{
  using namespace DataStructure::VestRadioCommunication;
  using namespace DataStructure::Game;

  switch (data.action) //data.action's type: TAction
  {
    case (VestAction::HANDSHAKE):
    {
      std::shared_ptr<VestActionData<void>> handshakeData = std::make_shared<VestActionData<void>>();
      handshakeData->action = static_cast<VestAction>(data.action);
      handshakeData->vestid = data.vestid;
      Events::Game::VestHandshakeRequest evt_hs(handshakeData);
      notify(evt_hs);
      break;
    }
    //No need to do auth; it will only be sent and not received by the server.
    // 
    //case (VestAction::AUTHENTIFICATE): //VestAction's type: enum of type TAction
    //{
    //  std::shared_ptr<VestActionData<AuthentificationData>> authData = std::make_shared<VestActionData<AuthentificationData>>();
    //  authData->action = static_cast<VestAction>(data.action);
    //  authData->vestid = data.vestid;
    //  const AuthentificationRadioData* vestDataC = static_cast<const AuthentificationRadioData*>(data.data);
    //  if (vestDataC) {
    //    authData->data.name = std::string(vestDataC->name.data, vestDataC->name.size);
    //    authData->data.character = static_cast<PlayerClass>(vestDataC->character);
    //  }
    //  break;
    //}
    case (VestAction::KILLED):
    {
      std::shared_ptr<VestActionData<KillData>> killData = std::make_shared<VestActionData<KillData>>();
      killData->action = static_cast<VestAction>(data.action);
      killData->vestid = data.vestid;
      const KilledRadioData* vestDataC = static_cast<const KilledRadioData*>(data.data);
      if (vestDataC) {
        killData->data.killed = nullptr;
        killData->data.killed->vestId = vestDataC->killed;
        killData->data.multiplier = vestDataC->multiplier;
      }
      Events::Game::KillRequest evt_kill(killData);
      notify(evt_kill);
      break;
    }
    default:
      break;
  }
}
