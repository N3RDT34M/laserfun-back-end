#include <memory>

#include "CAPI_CommunicationFront.h"
#include "DataStructures.h"

CAPI_CommunicationFront::CAPI_CommunicationFront(CAPI_Connector* connector)
  : CAPI_CommunicationInstance(connector)
{
}

void CAPI_CommunicationFront::onNotify(const IEvent& event)
{
  if (dynamic_cast<const Events::HTTP::JsonRequestReceived*>(&event)) {
    const Events::HTTP::JsonRequestReceived& e = static_cast<const Events::HTTP::JsonRequestReceived&>(event);
    handleJsonRequest(e._data);
  }
  return;
}

void CAPI_CommunicationFront::handleJsonRequest(const nlohmann::json& data)
{
  std::shared_ptr<GameData> gameData = std::make_shared<GameData>();
  gameData->blueName = data["nameBlue"];
  gameData->redName = data["nameRed"];
  gameData->bluePlayers = std::vector<std::shared_ptr<PlayerData>>();
  gameData->redPlayers = std::vector<std::shared_ptr<PlayerData>>();
  for (const auto& i : data["bluePlayerList"]) {
    std::shared_ptr<PlayerData> player = std::make_shared<PlayerData>();
    player->name = i["name"];
    // player->character = static_cast<PlayerClass>(i["character"]);
    player->stats = std::make_shared<PlayerStats>();
    gameData->bluePlayers.push_back(player);
  }
  for (const auto& i : data["redPlayerList"]) {
    std::shared_ptr<PlayerData> player = std::make_shared<PlayerData>();
    player->name = i["name"];
    // player->character = static_cast<PlayerClass>(i["character"]);
    player->stats = std::make_shared<PlayerStats>();
    gameData->bluePlayers.push_back(player);
  }
  notify(Events::Game::GameCreationRequest(gameData));
}
