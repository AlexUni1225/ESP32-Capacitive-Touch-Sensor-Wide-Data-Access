# ESP32-Capacitive-Touch-Sensor-Wide-Data-Access
An ino file that fetches data from an ESP32's built in capacitive touch sensor and sends it to Firebase, so that an independent html website can fetch the data to create an archive and a graph with it.

The ESP32 connects to a local WiFi network (blanked out for security) and establishes a connection with a Live Database created in Firebase.
The ESP32 reads the value of it's built-in capacitive touch sensor and sends it over to Firebase evere 500 miliseconds.

Independently, an html website fetches the data sent by the ESP32 from Firebase and uses it to create a graph with the last 50 samples and also archives the intire history of samples on a list.

Link to the website displaying the real-time capacitive touch sensor value: https://esp32-cts-data-collection.netlify.app/
