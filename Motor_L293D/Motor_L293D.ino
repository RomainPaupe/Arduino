int motor1Pin1 = 3;    // pin 2 (Input 1)  du L293D
int motor1Pin2 = 4;    // pin 7 (Input 2) du L293D
int enablePin = 9;     // pin 1 (Enable 1) du L293D

void setup() {
  // set all the other pins you're using as outputs:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  // Mettre la broche Enable a high comme ca le moteur tourne
  digitalWrite(enablePin, HIGH);
}

void loop() {
  // Le moteur tourne dans un sens 
  digitalWrite(motor1Pin1, LOW);   // mettre pin 2 a 293D low
  digitalWrite(motor1Pin2, HIGH);  // mettre pin 7 a L293D high
 
  delay( 3000 ); // Attendre 3 secondes 

  // Le moteur tourne dans l'autre sens 
  digitalWrite(motor1Pin1, HIGH);  // Mettre pin 2 a L293D high
  digitalWrite(motor1Pin2, LOW);   // Mettre pin 7 a L293D low
  
  delay( 3000 ); // Attendre 3 secondes 
}