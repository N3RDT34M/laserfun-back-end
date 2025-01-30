#pragma once
#include <beauty/beauty.hpp>
#include <unordered_map>
#include <string>
#include <nlohmann/json.hpp>

#include "CAPI_Connector.h"

class CAPI_ConnectorHttp : public CAPI_Connector {
private:
  beauty::server _server;
  std::unordered_map<int /* id */, nlohmann::json /* content */> _storage;
  void addCorsHeaders(beauty::response& res);
public:
  CAPI_ConnectorHttp();
};