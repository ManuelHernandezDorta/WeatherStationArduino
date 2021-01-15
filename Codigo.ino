#include "TRIGGER_WIFI.h"               /*Includes ESP8266WiFi.h and WiFiClientSecure.h, just have these two libraries downloaded before*/
#include "TRIGGER_GOOGLESHEETS.h"       /*Library file for Google Sheets, has to be used after Wi-Fi Client Secure declaration, here everything is in Trigger_WIFI.h, so using it after Trigger_WIFI.h*/ 
#include "DHT.h"                        /*Library for the temperature and hemidity*/
/*#include <Wire.h>                     Library for the presure*/
#include <Adafruit_BMP085.h>            /*Library for the presure*/
 
// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

Adafruit_BMP085 bmp;
 
/**********Google Sheets Definations***********/
char column_name_in_sheets[ ][20] = {"value1","value2","value3"};                        /*1. The Total no of column depends on how many value you have created in Script of Sheets;2. It has to be in order as per the rows decided in google sheets*/
String Sheets_GAS_ID = "AKfycbxFKsLqCLPRhPETFiqZIQTsr_U4QofN0jjG8lK0rqxi9W2DGoT-7Wgk";                                         /*This is the Sheets GAS ID, you need to look for your sheets id*/
int No_of_Parameters = 3;                                                                /*Here No_of_Parameters decides how many parameters you want to send it to Google Sheets at once, change it according to your needs*/
/*********************************************/
const int DHTPin = D6;     // what digital pin we're connected to
 
DHT dht(DHTPin, DHTTYPE);
/*********************************************/
void setup() 
{
  Serial.begin(9600);
  while (!Serial);


  if (!bmp.begin()) 
  {
    Serial.println("Could not find BMP180 or BMP085 sensor at 0x77");
    while (1) {}
  }

  WIFI_Connect("bachillerato","9j1m+X3G8Sh");                                                     /*Provide you Wi-Fi SSID and password to connect to Wi-Fi*/
  Google_Sheets_Init(column_name_in_sheets, Sheets_GAS_ID, No_of_Parameters );         /*Sets the column name for Google Sheets, the GAS ID, and the No of Parameter we want to send*/        
  dht.begin();



  
}

void loop() 
{
  /*Demo values that has to be sent to google sheets, you can use sensor values*/
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  float pressure = bmp.readPressure();

  
  Data_to_Sheets(No_of_Parameters,  temperature,  temperature, pressure);         /*1. This function accepts multiple float parameter, here No_of_Parameters decides how many parameters you want to send to Google Sheets; 2. The values sent should be in order as per the column in Google Sheets*/
 
  delay(3600000);                                       /*60 min Delay, Here 60 minutes delay is just used so that we can see the data pushed to sheets one by one
                                                        There is nothing like a minimum delay between two data push*/
}
