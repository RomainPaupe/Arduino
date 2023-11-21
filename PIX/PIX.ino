//Initialisation des potes AND et des deux tiges conductrices
int pAnd1 = 1; 
int pAnd2 = 2; 
int tiges1 = 3;  
int tiges2 = 4;

//Initialisation des moteurs
int M1D = 5;
int M1G = 6;
int M2D = 7;
int M2G = 8;
int M3D = 9;
int M3G = 10;

//Initialisation des capteurs Infra rouges
int ir1 = 11;
int ir2 = 12;

//Initialisation des status des moteurs
int M1 = 0;   //0 -> Moteur a l'arrêt
int M2 = 0;   //1 -> Moteur en rotation vers la droite
int M3 = 0;

void setup() { 
  Serial.begin(9600);
  
  pinMode(pAnd1, INPUT); 
  pinMode(pAnd2, INPUT); 
  pinMode(tige1, INPUT); 
  pinMode(tige2, INPUT); 
  
  pinMode(M1D, OUTPUT);
  pinMode(M1G, OUTPUT);
  pinMode(M2D, OUTPUT);
  pinMode(M2G, OUTPUT);
  pinMode(M3D, OUTPUT);
  pinMode(M3G, OUTPUT);
  
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
}

void loop() {
  //Surveillance des tiges
  if(digitalRead(pAnd1) == LOW) 
  {
    changementDeSensMoteur(M1, M1D, M1G);
    if(M1 == 1){M1++;}
    if(M1 == 2){M1--;}
  }
  if(digitalRead(pAnd2) == LOW) 
  {
    changementDeSensMoteur(M2, M2D, M2G);
    if(M2 == 1){M1++;}
    if(M2 == 2){M1--;}
  }
  if(digitalRead(tige1) == LOW)
  {
    arretMoteur(M3D, M3G);
    M3 = 0;
  }

  if(digitalRead(tige2 == LOW)
  {
    changementDeSensMoteur(1, M3D, M3G);
  }

  //surveille le retour des maillet grace au capteur
  if (digitalRead(ir1) == HIGH)
  {
    arretMoteur(M1D, M1G);
    M1 = 0;
  }
  if (digitalRead(ir2) == HIGH)
  {
    arretMoteur(M2D, M2G);
    M2 = 0
  }
}


void arretMoteur(int broche1, int broche2)
{
  digitalWrite(broche1, LOW);
  digitalWrite(broche2, LOW);
}

void changementDeSensMoteur(int statue, int broche1, int broche2)
{
  if (statue == 1)
  {
    digitalWrite(broche1, LOW);
    digitalWrite(broche2, HIGH);
  }

  if (statue == 2)
  {
    digitalWrite(broche1, HIGH);
    digitalWrite(broche2, LOW);
  }
}
