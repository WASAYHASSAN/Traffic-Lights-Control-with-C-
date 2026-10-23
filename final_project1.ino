class TrafficLight{
	private:
		int pinRed, pinYellow, pinGreen;
	public:
  		TrafficLight() {
            pinRed = 0; pinYellow = 0; pinGreen = 0;
        }
		TrafficLight(int r, int y, int g){
			pinRed = r;
			pinYellow = y;
			pinGreen = g;
			pinMode(r, OUTPUT);
			pinMode(y, OUTPUT);
			pinMode(g, OUTPUT);
		}
		
		void turnRed() {
			digitalWrite(pinRed, HIGH);
			digitalWrite(pinYellow, LOW);
			digitalWrite(pinGreen, LOW);
		}

		void turnGreen() {
			digitalWrite(pinRed, LOW);
			digitalWrite(pinYellow, LOW);
			digitalWrite(pinGreen, HIGH);
		}

		void turnYellow() {
			digitalWrite(pinRed, LOW);
			digitalWrite(pinYellow, HIGH);
			digitalWrite(pinGreen, LOW);
		}
};

class Intersection: public TrafficLight{
private:
  TrafficLight northLight;
  TrafficLight eastLight;
  bool isEmergency;
  
public:
  Intersection(TrafficLight n, TrafficLight e) : northLight(n), eastLight(e) {
        isEmergency = false;
    }
  void northEmergency(){
  	northLight.turnGreen();
    eastLight.turnRed();
    isEmergency = true;
  }
  void eastEmergency(){
  	northLight.turnRed();
    eastLight.turnGreen();
    isEmergency = true;
  }
};

TrafficLight north = TrafficLight(12, 10, 8);
TrafficLight east = TrafficLight(7, 6, 5);

Intersection intersection = Intersection(north, east);

void smartWait(int waitTime) {
  for (int i = 0; i < waitTime; i = i + 10) {
    if (Serial.available() > 0) {
      char key = Serial.read();
      if (key == '1') {
        // EMERGENCY NORTH!
        north.turnGreen();
        east.turnRed();
        delay(5000); 
        return;      
      } 
      else if (key == '2') {
        // EMERGENCY EAST!
        north.turnRed();
        east.turnGreen();
        delay(5000);
        return; 
      }
    }
    // Sleep for just 10ms, then loop and check again
    delay(10); 
  }
}

void setup() { 

  Serial.begin(9600); 
}
void loop() {
    // Normal Phase 0
    north.turnGreen();
    east.turnRed();
    smartWait(3000); 

    // Normal Phase 1
    north.turnYellow();
    east.turnRed();
    smartWait(1000);

    // Normal Phase 2
    north.turnRed();
    east.turnGreen();
    smartWait(3000);

    // Normal Phase 3
    north.turnRed();
    east.turnYellow();
    smartWait(1000);
}
