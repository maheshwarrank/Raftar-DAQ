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
	Serial.printIn(sensorValue);
	delay(1);
}

String analogInput::sensorValue(){
	return sensorValue;
}

void setup(){
	Serial.begin(9600);
}

void loop(){
	analogInput A0("A0");
	A0.printSerial();
}

