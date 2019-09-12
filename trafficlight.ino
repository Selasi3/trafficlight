 int red = 12;
 int yellow = 11;
 int green = 10;
 int greenPed = 2;
 int redPed = 3;
 int button = 7;
 int crossTime = 2000;
 unsigned long changeTime;
  

void setup() {
  // put your setup code here, to run once:
  // intialize timer
  changeTime = millis();
  
pinMode(red, OUTPUT);
pinMode(yellow, OUTPUT);
 pinMode(green, OUTPUT);
 pinMode(redPed, OUTPUT);
pinMode(greenPed, OUTPUT);
 pinMode(button, INPUT);

 // turn on the green light
 digitalWrite(green, HIGH);
digitalWrite(redPed, HIGH);
digitalWrite(red, LOW);
digitalWrite(yellow, LOW);
digitalWrite(greenPed, LOW);

Serial.begin(9600);
 

}

void loop() {
  // put your main code here, to run repeatedly:
  // check if button is pressed
  int state = digitalRead(button);
  Serial.println(state);
  // if the button is pressed and if it has passed 5 seconds since last button press
if (state == HIGH && (millis() - changeTime) > 5000) {
//call the function to change the lights
changeLights();
}
    
}

void changeLights(){
  digitalWrite(green, LOW); //the green led will turn off
  digitalWrite(yellow, HIGH); //the yellow led will turn on for 2 second
  delay(2000);

  digitalWrite(yellow, LOW); //the yellow led will turn off
  digitalWrite(red,HIGH); // the red Led will turn on for 5  seconds
  
digitalWrite(redPed, LOW);
digitalWrite(greenPed, HIGH);
delay(crossTime);
    

  // flash the ped green
for (int x=0; x<10; x++) {
digitalWrite(greenPed, LOW);
delay(100);
digitalWrite(greenPed, HIGH);
delay(100);
}
digitalWrite(greenPed, LOW);
digitalWrite(red, LOW);
digitalWrite(redPed, HIGH);
digitalWrite(green, HIGH);
changeTime = millis();

}
