// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>

//Sensor Type
#define DHTTYPE DHT22

//Sensor Connections
#define DHT_5V_PIN A0
#define DHT_SENSOR_PIN A1
#define DHT_GROUND_PIN A3

DHT dht(DHT_SENSOR_PIN, DHTTYPE);

// create servo object to control a servo

Servo myservo;



int pos;    // variable to store the servo position
int subpos ;
int relay = D3;


void setup()
{
    
    
  myservo.attach(A5);  // attaches the servo on the A4 pin to the servo object
  
  Particle.function("setpos", setPosition);
  Particle.function("subpos", subPosition);
  Particle.function("outletON",setOutletON);
  Particle.function("outletOFF",setOutletOFF);
  Particle.variable("getTemp", tempRequest);
  
}

void loop()
{
}

int setPosition(String posValue) {
    pos = 121;
    // pos = posValue.toInt();
    myservo.write(pos);
    return 0;
}

int subPosition(String posValue) {
    subpos = 61;
    
    myservo.write(subpos);
    return 0;
    
}

int setOutletON(String value){
    relay = D3;
    pinMode(relay, OUTPUT);
    digitalWrite(relay, HIGH);
    
}

int setOutletOFF(String value){
    relay = D3;
    pinMode(relay, OUTPUT);
    digitalWrite(relay, LOW);
}


int tempRequest (String value){
    
    //Powering up the sensor
    pinMode(DHT_5V_PIN, OUTPUT);
    pinMode(DHT_GROUND_PIN, OUTPUT);
    digitalWrite(DHT_5V_PIN, HIGH);
    digitalWrite(DHT_GROUND_PIN, LOW);
    
    //wait 1 second for sensor to power up
    delay(1000);
    
    //Initialize the sensor
    dht.begin();
    
    //farenheit 
    double temperature = dht.getTempFarenheit();
    
    return temperature;
    
}



