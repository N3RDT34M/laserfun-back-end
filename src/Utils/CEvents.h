#pragma once
#include <string>
#include <typeindex>
#include <vector>
#include <nlohmann/json.hpp>

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
  namespace Game {
    struct GameEnd : public CEvent<int> {
      explicit GameEnd(int result) : CEvent(result) {}
    };

    struct PlayerScore : public CEvent<float> {
      explicit PlayerScore(float score) : CEvent(score) {}
    };
  }

  namespace Radio {
    struct SignalReceived : public CEvent<std::vector<uint8_t>> {
      explicit SignalReceived(const std::vector<uint8_t>& data) : CEvent(data) {}
    };

    struct BroadcastMessage : public CEvent<std::string> {
      explicit BroadcastMessage(const std::string& msg) : CEvent(msg) {}
    };
  }

  namespace HTTP {
    struct JsonRequestReceived : public CEvent<nlohmann::json> {
      explicit JsonRequestReceived(const nlohmann::json& data) : CEvent(data) {}
    };
  }
}
