unsigned long previousMillis = 0;        // will store last time counter was updated

const long interval = 1000;           // interval at which to update display and decrement counter (milliseconds)

int reset = 0;
int start = 0;

int counter = 30; 
int set_counter = 30; // initial counter value

//function header
void Num_Write(int);

// the setup function runs once when you press reset or power the board
void setup() {

  pinMode(2, INPUT_PULLUP); //Button A - start
  pinMode(6, INPUT_PULLUP); //Button B - stop
  pinMode(3, INPUT_PULLUP); //Button C - reset
  pinMode(4, INPUT_PULLUP); //Button D - set at 20sec
  pinMode(7, INPUT_PULLUP); //Button E - set at 30sec
  pinMode(13, OUTPUT); //Alarm

  digitalWrite(13, LOW);

  Serial.begin(9600);

}

// the loop function runs over and over again forever
void loop() {
  //counter loop

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time the counter is updated
    previousMillis = currentMillis;
    if ((counter > 0) && (start == 1)) {
      counter = counter - 1;
      //Num_Write(counter);      
    } 
  }

  if (counter == 0){
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  

  if (digitalRead(7) == LOW) {
    set_counter = 30;
    counter = set_counter;
    start = 0;
  }

  if (digitalRead(4) == LOW) {
    set_counter = 20;
    counter = set_counter;
    start = 0;
  }

  if (digitalRead(2) == LOW) {
    start = 1;
  }

  if (digitalRead(6) == LOW) {
    start = 0;
  }

  if (digitalRead(3) == LOW) {
    counter = set_counter;
    start = 0;
  }

  Num_Write(counter);

}



// this functions writes values to the sev seg pins
void Num_Write(int number)
{
  Serial.write(number); 
  delay(200);  
}
