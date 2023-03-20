#include <WiFi.h>
#include <HTTPClient.h>
int LED = 2;
const char* ssid = "namewifi";
const char* password = "passwordwifi";
bool connected=false;
bool on=false;
String value;
int posp(String s){
  for(int i=0;i<s.length();i++){
    if(s.charAt(i)=='>'){
      return i+1;
    }
  }
  return -1;
}
void connect(){
    
    delay(1000);

    WiFi.mode(WIFI_STA); //Optional
    WiFi.begin(ssid, password);
    Serial.println("\nConnecting");

    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(100);
    }

    Serial.println("\nConnected to the WiFi network");
    Serial.print("Local ESP32 IP: ");
    Serial.println(WiFi.localIP());
    connected=true;
}
String httpservice(){
  HTTPClient http;
  http.begin("http://17medx2.pythonanywhere.com/state");
  int httpcode=http.GET();
  if(httpcode>0){
    
    return http.getString();
  }
  else{
    Serial.print("error");
    return "NULL";
  }


}

void servverdata(){
if(connected){
    value=httpservice();
    if(value!="NULL"){
      if(value.charAt(posp(value))=='1'){
        on=true;
      }
      else{
        on=false;
      }
    }

  }
  else{

    Serial.println("\nnotconnected");
  }
}
void program(){
  Serial.begin(115200);
  pinMode (LED, OUTPUT);
  Serial.println("\n-----system start----");
  connect();
  
}
void setup(){
  
  program();
  
  Serial.println("\nstate is");
  Serial.print(String(on));
}

void loop(){
  servverdata();
  if(on){

    digitalWrite(LED, HIGH);
    
  }
  else{
    digitalWrite(LED, LOW);
  }
}
