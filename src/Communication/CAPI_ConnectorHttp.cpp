#include "CAPI_ConnectorHttp.h"
#include "CAPI_ConnectorHttp.h"
#include <istream>
#include <iostream>

CAPI_ConnectorHttp::CAPI_ConnectorHttp()
{
  beauty::server::server_route gameRoute = _server.add_route("/game/set");
  gameRoute.post([&](const beauty::request& req, beauty::response& res) {
    std::string body = req.body();

    std::istringstream ss(body);
    nlohmann::json reqJson;
    try {
      reqJson = nlohmann::json::parse(ss, nullptr, true);
    }
    catch (...) {
      addCorsHeaders(res);
      res.result(400);
    }

    for (auto i : reqJson.items()) {
      std::cout << i.key() << " : " << i.value() << std::endl;
    }

    _storage[_storage.size()] = reqJson;
    notify(Events::HTTP::JsonRequestReceived(reqJson));
    addCorsHeaders(res);
    });
  gameRoute.options([&](const beauty::request& req, beauty::response& res) {
    addCorsHeaders(res);
    });

  _server.listen(8000);
  _server.wait();
}

void CAPI_ConnectorHttp::addCorsHeaders(beauty::response& res) {
  res.set("Access-Control-Allow-Origin", "*");
  res.set("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
  res.set("Access-Control-Allow-Headers", "*");
}