# Arduino_Medidor_temperatura_humedad_presion_envio_datos_hoja_calculo_google

Weather station project

## Hardware:

Wemos d1 mini board based in esp2866<br/>
DHT22 sensor for temperature and humedety<br/>
bmp280 sensor for pressure

## How to make it:

First of all, you have to connect the sensor to board correctly so when you install the software it will work. If you don't know how to connect it, you can look the images, if you still don't know you can look for videos in youtube or manuals on internet.<br/>
The second step is to install the software. The ArduinoCode.ino is the file you have to install on your board and it's important to have the TRIGGER_WIFI and the TRIGGER_GOOGLESHEETS (memo pad extension) in the same folder that the Arduino IDE will create.<br/>
The last step is to install the software in the Google sheet so the data can be sended. You can follow this [video](https://youtu.be/GOiLbs5Sidc) to make it more simple.

## How to modify the code:

In the ArduinoCode.ino you have to change lines:

```cpp
  WIFI_Connect("/*Input your wifi names*/","/*Input your wifi password*/"); 
```
To make possible that the board connect to the wifi. 

```cpp
String Sheets_GAS_ID = "/*Input your google sheet Gas ID*/"; 
```
This one is to connect the board to the google sheet so it can send the data

In GoogleSheet.h you have to change this line:

```cpp
    var sheet_id = 'Enter your Sheet ID Here'; 		// Spreadsheet ID
```

To identify the document

If there is any problem you might see this video that I used to make this project and it will help you: [Video](https://www.youtube.com/watch?v=GOiLbs5Sidc&feature=emb_logo)

## Images:
These are some images to see how we connect the hardware and the sensor<br/>
There are more photos of the board in the images folder<br/>
![Preview Image](https://github.com/ManuelHernandezDorta/Arduino_Medidor_temperatura_humedad_presion_envio_datos_hoja_calculo_google/blob/main/images/1610966629715.jpg)
![Preview Image](https://github.com/ManuelHernandezDorta/Arduino_Medidor_temperatura_humedad_presion_envio_datos_hoja_calculo_google/blob/main/images/1610966629722.jpg)
