#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <memory>

struct PlayerData;

enum PlayerClass : uint8_t {
  ECLAIREUR,
  NINJA,
  BOURRIN,
  CYBERGNOME,
  IMMORTEL,
  TAUPE
};

struct KillData {
  std::shared_ptr<PlayerData> killed;
  std::chrono::high_resolution_clock::duration time;
  double multiplier;
};

//struct UltiData {
//  std::chrono::high_resolution_clock::duration time;
//};

struct PlayerStats {
  std::vector<KillData> kills;
  //std::vector<UltiData> ultis;
};

struct PlayerData {
  std::string name;
  PlayerClass character;
  std::shared_ptr<PlayerStats> stats;
  std::shared_ptr<Gilet> id_gilet;
};

struct GameData {
  std::string blueName;
  std::string redName;
  std::vector<std::shared_ptr<PlayerData>> bluePlayers;
  std::vector<std::shared_ptr<PlayerData>> redPlayers;
};

using TvestId = uint16_t;

struct c_string {
  uint8_t size;
  char* data;
};

namespace DataStructure {
  //WARNING
  //DO NOT USE C++ TYPES HERE !! 
  //THE VESTS USE C! 
  namespace VestRadioCommunication {
    enum Action : uint8_t {
      HANDSHAKE, //Received by the server
      AUTHENTIFICATE, //Sent by the server
      KILLED,
      ULTI
    };

    template <typename Tdata>
    struct VestRadioData {
      Action action;
      TvestId vestid;
      Tdata data;
    };

    struct AuthentificationData {
      c_string name;
      PlayerClass character;
    };

    struct KilledData {
      TvestId killer;
      TvestId killed;
      double multiplier;
    };
  }
}

struct Gilet
{
	std::string id_gilet;
};