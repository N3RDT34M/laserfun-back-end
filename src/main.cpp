#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <nlohmann/json.hpp>
#include "Communication/CAPI_CommunicationPlayers.h"
#include "Communication/CAPI_CommunicationFront.h"
#include "Communication/CAPI_ConnectorHttp.h"
#include "Communication/CAPI_ConnectorRadio.h"
#include "Game/CGameManager.h"

//#include ""

int main(void) {
  CAPI_ConnectorHttp connectorHttp;
  CAPI_ConnectorRadio connectorRadio;

  CAPI_CommunicationPlayers apiPlayers(&connectorRadio);
  CAPI_CommunicationFront apiFront(&connectorHttp);

  CGameManager gameManager;

  apiFront.addObserver(&gameManager);
  apiPlayers.addObserver(&gameManager);
}