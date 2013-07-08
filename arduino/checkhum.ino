#include <SPI.h>

#include <Ethernet.h>
#include <util.h>
#include <Dhcp.h>
#include <Dns.h>
#include <EthernetServer.h>
#include <EthernetClient.h>
#include <EthernetUdp.h>

// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"

#define DHTPIN 2     // what pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11 
#define DHTTYPE DHT22  // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

/*
 * Partie web
 */
// assign a MAC address for the ethernet controller.
// fill in your address here:
byte mac[] = {0x90, 0xA2, 0xDA, 0x00, 0x65, 0xAC};
// assign an IP address for the controller:
IPAddress ip(10,73,0,100);
IPAddress gateway(10,73,0,1);	
IPAddress subnet(255, 255, 255, 0);


// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(8080);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  Serial.println(dht.readTemperature());

  dht.begin();

  // init du srv web
  Ethernet.begin(mac, ip);
  server.begin();
}

void loop() {
  listenForEthernetClients();
}

void listenForEthernetClients() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("Got a client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text");
          client.println();
          client.print("{'temp':");
          client.print(dht.readTemperature());
          client.print(",'hum':");
          client.print(dht.readHumidity());
          client.print("}"); 
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
  }
} 
