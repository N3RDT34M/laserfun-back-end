#include <string>
#include <vector>
#include <chrono>
#include <memory>

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
};

struct GameData {
  std::string blueName;
  std::string blueName;
  std::vector<std::shared_ptr<PlayerData>> bluePlayers;
  std::vector<std::shared_ptr<PlayerData>> redPlayers;
};