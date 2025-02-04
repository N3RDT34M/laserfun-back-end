#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <memory>
#include <type_traits>

namespace DataStructure {

  using TvestId = uint16_t;
  using TAction = uint8_t;
  using TPlayerClass = uint8_t;

  namespace Game {

    struct PlayerData;

    enum PlayerClass : TPlayerClass {
      ECLAIREUR,
      NINJA,
      BOURRIN,
      CYBERGNOME,
      IMMORTEL,
      TAUPE
    };

    struct KillData;

    struct PlayerStats {
      std::vector<KillData> kills;
      //std::vector<UltiData> ultis;
    };


    struct PlayerData {
      std::string name;
      PlayerClass character;
      std::shared_ptr<PlayerStats> stats;
      TvestId vestId;
    };

    struct GameData {
      std::string blueName;
      std::string redName;
      std::vector<std::shared_ptr<PlayerData>> bluePlayers;
      std::vector<std::shared_ptr<PlayerData>> redPlayers;
    };

    enum VestAction : TAction {
      HANDSHAKE, //Received by the server
      AUTHENTIFICATE, //Sent by the server
      KILLED,
      ULTI
    };

    template <typename dataType, typename Enable = void>
    struct VestActionData;

    template <typename dataType>
    struct VestActionData<dataType, std::enable_if_t<!std::is_void_v<dataType>>> {
      VestAction action;
      TvestId vestid;
      dataType data;
    };

    template <typename dataType>
    struct VestActionData<dataType, std::enable_if_t<std::is_void_v<dataType>>> {
      VestAction action;
      TvestId vestid;
    };

    ///
    /// Possible dataType structures for VestActionData template
    ///
    
    struct AuthentificationData {
      std::string name;
      PlayerClass character;
    };

    struct KillData {
      std::shared_ptr<PlayerData> killed;
      std::chrono::high_resolution_clock::duration time;
      double multiplier;
    };

    ///
    ///End of possible dataType structures for VestActionData template
    ///
  }

  struct c_string {
    uint8_t size;
    char* data;
  };

  //WARNING
  //DO NOT USE C++ TYPES HERE !! 
  //THE VESTS USE C! 

  namespace VestRadioCommunication {

    struct VestActionRadioData {
      TAction action;
      TvestId vestid;
      void* data;
    };

    struct AuthentificationRadioData {
      c_string name;
      TPlayerClass character;
    };

    struct KilledRadioData {
      TvestId killer;
      TvestId killed;
      float multiplier;
    };
  }
}