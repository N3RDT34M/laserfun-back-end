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
    struct GameCreationRequest : public CEvent<std::shared_ptr<GameData>> {
      explicit GameCreationRequest(std::shared_ptr<GameData> result) : CEvent(result) {}
    };

    /// <summary>
    /// Requete qui annonce la fin de la partie
    /// <para>Emit par : "CGameManager" et reçut par "CAPI_CommunicationFront" et "CAPI_CommunicationPlayer" </para>
    /// </summary>
    struct GameEnd : public CEvent<int> {
      explicit GameEnd(int result) : CEvent(result) {}
    };

    /// <summary>
    /// lui je sais pas a quoi il sers
    /// </summary>
    struct PlayerScore : public CEvent<float> {
      explicit PlayerScore(float score) : CEvent(score) {}
    };

    /// <summary>
    /// Event pour annoncer au game manager que un gilet a été detecter
    /// <para>Emit par : "CAPI_CommunicationPlayer" et reçut par "CGameManager"</para>
    /// </summary>
    struct GiletConnecter : public CEvent<float> {
        explicit GiletConnecter(float intGilet) : CEvent(intGilet) {}
    };

    /// <summary>
    /// Event que retourne le game manager pour annoncer que toutes les info de partie sont prete
    /// <para>Emit par : "CGameManager" et reçut par "CAPI_CommunicationFront" et "CAPI_CommunicationPlayer"</para>
    /// </summary>
    struct GameReady : public CEvent<GameData> {
        explicit GameReady( GameData data_complete) : CEvent(data_complete) {}
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
    struct DemarerJeu : public CEvent<bool> {
        explicit DemarerJeu(bool start) : CEvent(start) {}
    };
  }

  namespace Radio { // event relatif a la radio 

    /// <summary>
    /// event pour le debug uniquement
    /// </summary>
    struct SignalReceived : public CEvent<std::vector<uint8_t>> {   
      explicit SignalReceived(const std::vector<uint8_t>& data) : CEvent(data) {}
    };

    /// <summary>
    /// Lui je sais pas a quoi il sers 
    /// </summary>
    struct BroadcastMessage : public CEvent<std::string> {
      explicit BroadcastMessage(const std::string& msg) : CEvent(msg) {}
    };


    /// <summary>
    /// Event pour la reception d'un ID d'un gilet pour le connceter
    /// <para>Emit par : "CAPI_CommunicationPlayer" et reçut par "CGameManager"</para>
    /// </summary>
    struct SignalGiletReceived : public CEvent<std::vector<uint8_t>> {
        explicit SignalGiletReceived(const std::vector<uint8_t>& intGilet) : CEvent(intGilet) {}
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
