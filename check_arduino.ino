int incomingByte, incomingByte0, incomingByte1;     
int resultat[2];
int resultat1[0];
int resultat2[1];
int resultat3[2];

int etat=0;


void setup(){

// ************* serial configuration
  
  Serial.begin(9600);

}

void loop(){
      etat=0;
      if (Serial.available()) { //if Serial open start program
        Serial.println("Serial open wait number of mail");
        
        incomingByte = Serial.read();
        incomingByte0 = Serial.read();
        incomingByte1 = Serial.read();
        // ************* converti les byte en nombre landa
        incomingByte=incomingByte-48;
        if (incomingByte<0){etat=etat+1;}
        incomingByte0=incomingByte0-48;
        if (incomingByte0<0){etat=etat+1;}
        incomingByte1=incomingByte1-48;
        if (incomingByte1<0){etat=etat+1;}
        // ************* attente qui sert a rien
        Serial.print("check mail : ");
        Serial.println("75 %");
        delay(500);
        // ************* write number of mail int the good decade
        if (etat==0){
          resultat[0]=incomingByte;
          resultat[0]=resultat[0]*100;
          resultat[1]=incomingByte0;
          resultat[1]=resultat[1]*10;
          resultat[2]=incomingByte1;
          Serial.print("You have : ");
          Serial.print(resultat[0]+resultat[1]+resultat[2]);
          Serial.println(" no read mail ");
          Serial.println("100 %");
        }
        if (etat==1){
          resultat2[0]=incomingByte;
          resultat2[0]=resultat2[0]*10;
          resultat2[1]=incomingByte0;
          Serial.print("You have : ");
          Serial.print(resultat2[0]+resultat2[1]);
          Serial.println(" no read mail ");
          Serial.println("100 %");
        }   
        if (etat==2){
          resultat1[0]=incomingByte;
          Serial.print("You have : ");
          Serial.print(resultat1[0]);
          Serial.println(" no read mail ");
          Serial.println("100 %");
        }
        delay(1000);
    
    }
    else {
      delay(750);   //do a delay else the arduino wild be overloard
    }
}


