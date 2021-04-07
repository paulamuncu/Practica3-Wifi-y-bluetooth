#include <Arduino.h>

/*
 ESP32 Web Server - STA Mode
 modified on 25 MAy 2019
 by Mohammadreza Akbari @ Electropeak
 https://electropeak.com/learn
*/

#include <WiFi.h>
#include <WebServer.h>

// SSID & Password
const char* ssid = "MOVISTAR_1E97";  // Enter your SSID here
const char* password = "WcNKxpbmWd7PpF2UtkTq";  //Enter your Password here

WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult)

void handle_root(void);

void setup() {
 Serial.begin(115200);
 Serial.println("Try Connecting to ");
 Serial.println(ssid);

 // Connect to your wi-fi modem
 WiFi.begin(ssid, password);

 // Check wi-fi is connected to wi-fi network
 while (WiFi.status() != WL_CONNECTED) {
 delay(1000);
 Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected successfully");
 Serial.print("Got IP: ");
 Serial.println(WiFi.localIP());  //Show ESP32 IP on serial

 server.on("/", handle_root);

 server.begin();
 Serial.println("HTTP server started");
 delay(100); 
}

void loop() {
 server.handleClient();
}

// HTML & CSS contents which display on web server
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1>Mimi wo sumaseba</h1>\
<hr>\
<p><img src='mimiwosumaseba.jpg' alt='Mimi wo sumaseba'></p>\
<ul>\
<li><strong>Argument</strong></li>\
</ul>\
<p>La Shizuku és una adolescent aficionada a la lectura, que ha planejat passar les seves vacances d&#39;estiu llegint a la biblioteca i traduint cançons estrangeres. Però, per sorpresa seva, els seus plans fan un gir inesperat quan descobreix que les fitxes dels llibres que agafa de la biblioteca tenen un mateix nom: Seiji Amasawa.</p>\
<p>Un dia, al tren, la Shizuku es troba amb un gat misteriós que la porta a la botiga on en Seiji treballa com a aprenent de lutier. En Seiji explica a la Shizuku que el seu somni és portar el seu art a Itàlia i anima la Shizuku perquè escrigui llibres.</p>\
<ul>\
<li><strong>Fitxa</strong></li>\
</ul>\
<table>\
<thead>\
<tr>\
<th></th>\
<th></th>\
</tr>\
</thead>\
<tbody>\
<tr>\
<td>Direcció</td>\
<td>Yoshifumi Kondō</td>\
</tr>\
<tr>\
<td>Producció</td>\
<td>Toshio Suzuki</td>\
</tr>\
<tr>\
<td>Guió</td>\
<td>Hayao Miyazaki</td>\
</tr>\
<tr>\
<td>Música</td>\
<td>Yuji Nomi</td>\
</tr>\
<tr>\
<td>Fotografia</td>\
<td>Kitaro Kosaka</td>\
</tr>\
<tr>\
<td>Muntatge</td>\
<td>Takeshi Seyama</td>\
</tr>\
<tr>\
<td>Productora</td>\
<td>Studio Ghibli</td>\
</tr>\
</tbody>\
</table>\
<hr>\
<p><em>Paula Muncunill Martinez</em></p>\
</body></html>\
</body>\
</html>";

// Handle root url (/)
void handle_root() {
 server.send(200, "text/html", HTML);
}