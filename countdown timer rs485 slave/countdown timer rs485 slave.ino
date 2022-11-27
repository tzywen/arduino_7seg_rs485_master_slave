// make an array to save Sev Seg pin configuration of numbers

int num_array_ten[10][7] = {  
  { 0, 0, 0, 0, 0, 0, 0 }, // 0
  { 0, 1, 1, 0, 0, 0, 0 }, // 1
  { 1, 1, 0, 1, 1, 0, 1 }, // 2
  { 1, 1, 1, 1, 0, 0, 1 } // 3

};   

int num_array_single[10][7] = {  
  { 1, 1, 1, 1, 1, 1, 0 }, // 0
  { 0, 1, 1, 0, 0, 0, 0 }, // 1
  { 1, 1, 0, 1, 1, 0, 1 }, // 2
  { 1, 1, 1, 1, 0, 0, 1 }, // 3
  { 0, 1, 1, 0, 0, 1, 1 }, // 4
  { 1, 0, 1, 1, 0, 1, 1 }, // 5
  { 1, 0, 1, 1, 1, 1, 1 }, // 6
  { 1, 1, 1, 0, 0, 0, 0 }, // 7
  { 1, 1, 1, 1, 1, 1, 1 }, // 8
  { 1, 1, 1, 1, 0, 1, 1 }  // 9
};  

int pin_num_ten[7] = {2, 2, 3, 4, 5, 6, 6};
int pin_num_single[7] = {7, 8, 9, 10, 11, 12, 13};

//function header
void Num_Write(int);

// the setup function runs once when you press reset or power the board
void setup() {
  // use a for loop to initialize each pin as an output:
  for (int thisPin = 2; thisPin < 14; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {

  if (Serial.available()) {
    int counter = Serial.read(); 
    Num_Write(counter);
  }
  
}

// this functions writes values to the sev seg pins
void Num_Write(int number)
{
  int single_digit = number % 10;
  int ten_digit = number / 10;
  for (int j = 0; j < 7; j++) {
    digitalWrite(pin_num_ten[j], num_array_ten[ten_digit][j]);
    digitalWrite(pin_num_single[j], num_array_single[single_digit][j]);
  }
}
