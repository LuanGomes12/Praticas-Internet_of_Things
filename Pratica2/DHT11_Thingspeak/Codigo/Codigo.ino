#include <DHT.h>  // Including library for dht
//#include <ESP8266WiFi.h>
#include <WiFi.h>
 
String apiKey = "AVMDZBV4E73H9XEV";     //  <-- escreva seu Write API key do site ThingSpeak

const char *ssid =  "WALDEMYR_WIFI";     // <-- substitua com o ssid e senha da rede Wifi
const char *pass =  "waldemyr18";
const char* server = "api.thingspeak.com";

#define DHTPIN 4          //<-- pin onde o dht11 está conectado
 
DHT dht(DHTPIN, DHT11);

WiFiClient client;
 
void setup() 
{
       Serial.begin(115200);
       delay(10);
       dht.begin();
 
       Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
 
}
 
void loop() 
{
  
      float h = dht.readHumidity();
      float t = dht.readTemperature();
      
              if (isnan(h) || isnan(t)) 
                 {
                     Serial.println("Failed to read from DHT sensor!");
                      return;
                 }

                         if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {                                                       
                             String postStr = apiKey;
                             postStr +="&field1="; //<-- atenção, esse é o campo 1 que você escolheu no canal do ThingSpeak

                             postStr += String(t);
                             postStr +="&field2=";
                             postStr += String(h);
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("Temperature: ");
                             Serial.print(t);
                             Serial.print(" degrees Celcius, Humidity: ");
                             Serial.print(h);
                             Serial.println("%. Send to Thingspeak.");

                             // Aguarde até que o cliente tenha enviado alguma coisa
                            delay(1000);
                        }
          client.stop();
 
          Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates, i've set it to 20 seconds
  delay(20000);
}