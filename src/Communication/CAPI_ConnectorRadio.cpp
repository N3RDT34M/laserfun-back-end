#include "CAPI_ConnectorRadio.h"
#include "CEvents.h"

#define CSN_PIN 0

#define CE_PIN 8 // GPIO8

#define PIPE "PIPE1"

CAPI_ConnectorRadio::CAPI_ConnectorRadio()
#ifdef __linux__
  : _radio(CE_PIN, CSN_PIN)
#endif
{
#ifdef __linux__
  const uint_fast8_t adress[6] = PIPE;
  char message[32];

  // Partie NRF24
  try {
  bool ok = _radio.begin();                      // Initialisation du module NRF24
  }
  catch (void* e) {
    std::cerr << "Error: " << std::endl;
  }
  _radio.openReadingPipe(0, adress);  // Ouverture du tunnel en LECTURE, avec le "nom" qu'on lui a donné
  _radio.setPALevel(RF24_PA_MIN);      // Sélection d'un niveau "MINIMAL" pour communiquer (pas besoin d'une forte puissance, pour nos essais)

  _radio.startListening(); // put radio in RX mode

  time_t startTimer = time(nullptr);       // start a timer
  while (true) { // use 60 second timeout
    uint8_t pipe;
    if (_radio.available(&pipe)) {                        // is there a payload? get the pipe number that received it
      uint8_t bytes = _radio.getPayloadSize();          // get the size of the payload
      _radio.read(&_payload, sizeof(message));                     // fetch payload from FIFO
      std::cout << "Received " << (unsigned int)bytes;      // print the size of the payload
      std::cout << " bytes on pipe " << (unsigned int)pipe; // print the pipe number
      std::cout << ": " << _payload.action << std::endl;                 // print the payload's value
      startTimer = time(nullptr);                      // reset timer
    }
  }
  std::cout << "Nothing received in 6 seconds. Leaving RX role." << std::endl;
  _radio.stopListening();
#endif
}

void CAPI_ConnectorRadio::startListening()
{ // This is a dummy implementation
  // In a real implementation, this would be a loop that listens for radio signals
  // and then sends them to the observers
  // For the purpose of this exercise, we will just send a dummy signal
#ifdef __linux__
  DataStructure::VestRadioCommunication::VestActionRadioData data;
  data.action = DataStructure::VestRadioCommunication::VestAction::HANDSHAKE;
  data.vestid = 1;
  data.data = nullptr;
  Events::Radio::SignalReceived event(data);
  notify(event);
#endif // __linux__
}