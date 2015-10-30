#include <SPI.h>
#include <SD.h>

const int chipSelect= 4;

class analogInput
{
private:
	String PIN;
	pinMode(PIN,INPUT);
	int sensorValue = analogRead(PIN);
public:
	analogInput(String);
	void setPin(String);
	String sensorValue();
	void printSerial();
};

analogInput::analogInput(String pin){
	PIN = pin;
}

void analogInput::setPin(String pin){
	PIN = pin;
}

void analogInput::printSerial(){
	Serial.println(sensorValue);
	delay(1);
}

String analogInput::sensorValue(){
	return sensorValue;
}


void setup(){
	 // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");

 }

 void loop(){

 	String data="";
 	analogInput pin[10];
 	int N;
 	String pinNumber;
 	cin>>N;
 	for (int i = 0; i < N ; ++i)
 	 {
 	 	cin>>pinNumber;
 	 	pin[i].setPin(pinNumber);
 	 	data += pin[i].sensorValue()+ " " ;
 	 }

 	File dataFile = SD.open("datalog.txt", FILE_WRITE); 
 	if (dataFile) {
    	dataFile.println(data);
    	dataFile.close();
    	Serial.println(data);

     }
  // if the file isn't open, pop up an error:
  	else {
    Serial.println("error opening datalog.txt");
  	}
 }