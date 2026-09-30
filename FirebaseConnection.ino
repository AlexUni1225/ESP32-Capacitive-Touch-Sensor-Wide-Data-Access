#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "YOUR_SSID_HERE";
const char* password = "YOUR_PASSWORD_HERE";

// Paste your Firebase URL here. MUST end with .json
String firebaseUrl = "https://live-cts-data-register-default-rtdb.firebaseio.com/touchData.json"; 

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    
    int touchValue = touchRead(4); // Read capacitive touch sensor on GPIO 4
    
    // Create a JSON payload
    String payload = "{\"touch_value\": " + String(touchValue) + "}";
    
    http.begin(firebaseUrl);
    http.addHeader("Content-Type", "application/json");
    
    // Use POST to append data (archive) instead of overwriting
    int httpResponseCode = http.POST(payload);
    
    if (httpResponseCode > 0) {
      Serial.print("Data archived! Cloud response code: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Error sending data: ");
      Serial.println(httpResponseCode);
    }
    
    http.end(); 
  }
  
  delay(500); // Wait 500 ms before the next reading
}