#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <thread>
#include <iostream>

#include <nlohmann/json.hpp>
#include "Communication/CAPI_CommunicationPlayers.h"
#include "Communication/CAPI_CommunicationFront.h"
#include "Communication/CAPI_ConnectorHttp.h"
#include "Communication/CAPI_ConnectorRadio.h"
#include "Game/CGameManager.h"

int main(void) {
  std::cout << R"(
  ---------------------------------------------------------------------------
                      WELCOME TO LASER FUN BACKEND SERVER

  All rights reserved. Licensed under GNU Lesser General Public License v2.1
  ---------------------------------------------------------------------------
  )";
  CAPI_ConnectorHttp connectorHttp;
  CAPI_ConnectorRadio connectorRadio;

  CAPI_CommunicationPlayers apiPlayers(&connectorRadio);
  CAPI_CommunicationFront apiFront(&connectorHttp);

  CGameManager gameManager;

  apiFront.addObserver(&gameManager);
  apiPlayers.addObserver(&gameManager);

  std::thread httpThread([&] {
    std::cout << "Starting HTTP Server\n";
    try {
      connectorHttp.startListening();
    }
    catch (...)
    {
      std::cerr << "Fatal error in HTTP Server starting. Aborting.\n";
      exit(EXIT_FAILURE);
    }
  });
  std::thread radioThread([&] {
    std::cout << "Starting radio communications\n";
    try {
      connectorRadio.startListening();
    }
    catch (...)
    {
      std::cerr << "Fatal error in radio communication starting. Aborting.\n";
      exit(EXIT_FAILURE);
    }
  });
  std::thread userThread([&] {
    std::string input;
    while (true) {
      std::cin >> input;
      if (input == "exit") {
        //connectorHttp.stopListening();
        //connectorRadio.stopListening();
        exit(EXIT_SUCCESS);
      }
    }
  });
  //std::thread gameTickThread([&] {
  ////gameManager.watchGameEnd()
  //});

  httpThread.join();
  radioThread.join();
  userThread.join();
  //gameTickThread.join();

  return EXIT_SUCCESS;
}