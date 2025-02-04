#pragma once
#include <string>
#include <typeindex>
#include <vector>
#include <nlohmann/json.hpp>

#include "DataStructures.h"

class IEvent {
public:
  virtual ~IEvent() = default;
  virtual std::type_index getType() const = 0;
};

template <typename T>
class CEvent : public IEvent {
public:
  T _data;

  explicit CEvent(const T& data) : _data(data) {}

  std::type_index getType() const override {
    return typeid(T);
  }
};

namespace Events {

  namespace Game {  // event relatif au jeu

    /// <summary>
    /// Requete du front qui envoie des info de joueur et de la partie
    /// <para>Emit par : "CAPI_CommunicationFront" et reçut par "CGameManager" </para>
    /// </summary>
    struct GameCreationRequest : public CEvent<std::shared_ptr<DataStructure::Game::GameData>> {
      explicit GameCreationRequest(std::shared_ptr<DataStructure::Game::GameData> result) : CEvent(result) {}
    };

    /// <summary>
    /// Requete qui annonce la fin de la partie
    /// <para>Emit par : "CGameManager" et reçut par "CAPI_CommunicationFront" et "CAPI_CommunicationPlayer" </para>
    /// </summary>
    struct GameEnd : public CEvent<int> {
      explicit GameEnd(int result) : CEvent(result) {}
    };

    /// <summary>
    /// Event pour annoncer au game manager que un gilet a été detecter
    /// <para>Emit par : "CAPI_CommunicationPlayer" et reçut par "CGameManager"</para>
    /// </summary>
    struct VestHandshakeRequest : public CEvent<std::shared_ptr<DataStructure::Game::VestActionData<void>>> {
        explicit VestHandshakeRequest(std::shared_ptr<DataStructure::Game::VestActionData<void>> hs) : CEvent(hs) {}
    };

    /// <summary>
    /// Event que retourne le game manager pour annoncer que toutes les info de partie sont prete
    /// <para>Emit par : "CGameManager" et reçut par "CAPI_CommunicationFront" et "CAPI_CommunicationPlayer"</para>
    /// </summary>
    struct Ready : public CEvent<DataStructure::Game::GameData> {
        explicit Ready(DataStructure::Game::GameData data_complete) : CEvent(data_complete) {}
    };

    /// <summary>
    /// Event que retourne le front pour annoncer que la partie peut demarer
    /// <para>Emit par : "CAPI_CommunicationFront" et reçut par "CGameManager"</para>
    /// </summary>
    struct LaunchRequest : public CEvent<bool> {
        explicit LaunchRequest(bool launchRequest) : CEvent(launchRequest) {}
    };


    /// <summary>
    /// Event pour le demarage de la partie
    /// <para>Emit par : "CGameManager" et reçut par "CAPI_CommunicationFront" et "CAPI_CommunicationPlayer"</para>
    /// </summary>
    struct Start : public CEvent<bool> {
        explicit Start(bool start) : CEvent(start) {}
    };


    struct KillRequest : public CEvent<std::shared_ptr<DataStructure::Game::VestActionData<DataStructure::Game::KillData>>> {
      explicit KillRequest(std::shared_ptr<DataStructure::Game::VestActionData<DataStructure::Game::KillData>> kill) : CEvent(kill) {}
    };


  }

  namespace Radio { // event relatif a la radio 

    /// <summary>
    /// Event lorsque le connecteur radio reçoit une communication
    /// </summary>
    struct SignalReceived : public CEvent<DataStructure::VestRadioCommunication::VestActionRadioData> {   
      explicit SignalReceived(const DataStructure::VestRadioCommunication::VestActionRadioData& data) : CEvent(data) {}
    };

  }

  namespace HTTP { // event relatif au Front-end

    /// <summary>
    /// Event pour la reception des info des joueur depuis le front
    /// <para>Emit par : "CAPI_CommunicationFront" et reçut par "CGameManager"</para>
    /// </summary>
    struct JsonRequestReceived : public CEvent<nlohmann::json> {
      explicit JsonRequestReceived(const nlohmann::json& data) : CEvent(data) {}
    };

    /// <summary>
    /// Event pour la reception du lancement de la partie depuis le front
    /// <para>Emit par : "CAPI_CommunicationFront" et reçut par "CGameManager"</para>
    /// </summary>
    struct LaunchRequestReceived : public CEvent<nlohmann::json> {
        explicit LaunchRequestReceived(const nlohmann::json& data) : CEvent(data) {}
        };
  
  }
}
