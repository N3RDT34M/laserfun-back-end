#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <memory>

struct PlayerData;

enum class PlayerClass {
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

struct Gilet
{
	std::string id_gilet;
};