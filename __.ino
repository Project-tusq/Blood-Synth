/*note
- - - - - - - - - - - - - - - - - - - -
[MOTOR BEHAVIOR]
Pin        |MOSFET         |MOTOR|
D0 |D1 |D3 |P1 |P2 |N1 |N2 |     |
D2 |D4 |D5 |   |   |   |   |     |
- - - - - - - - - - - - - - - - - -
0  |0  |1  |L  |H  |L  |H  | ->  |
1  |1  |1  |H  |L  |H  |L  | <-  |
1  |0  |0  |H  |H  |H  |H  | --  |
1  |0  |1  |L  |L  |H  |H  | NG| |
- - - - - - - - - - - - - - - - - - - -
[PHOTO SENSOR]
D8 |D12|D13|

[INFRARED SENSOR ]
A3 |A4 |A5 |

- - - - - - - - - - - - - - - - - - - -
*/
/*PIN DEFINE*/

int RM1pin =  0;
int RM2pin =  1;
int RM3pin =  3;

int LM1pin =  2;
int LM2pin =  4;
int LM3pin =  5;

int PS1pin =  8;
int PS2pin = 12;
int PS3pin = 13;

int IS1pin = A3;
int IS2pin = A4;
int IS3pin = A5;

/*MOVING FUNCTIONS*/

void moveForward(){
  
  POWER_MF=160; //Setting Power
  
  analogWrite(RM1pin, 0       );
  analogWrite(RM2pin, 0       );
  analogWrite(RM3pin, POWER_MF);

  analogWrite(LM1pin, 0       );
  analogWrite(LM2pin, 0       );
  analogWrite(LM3pin, POWER_MF);

  Serial.println("Moving Forward");
  
}

void moveBackward(){

  POWER_MB=160; //Setting Power
  
  analogWrite(RM1pin, POWER_MB);
  analogWrite(RM2pin, POWER_MB);
  analogWrite(RM3pin, POWER_MB);

  analogWrite(LM1pin, POWER_MB);
  analogWrite(LM2pin, POWER_MB);
  analogWrite(LM3pin, POWER_MB);

  delay(300)
  Serial.println("Moving Backward");
  
}

void turnRight(){

  POWER_TR=160; //Setting Power

  analogWrite(RM1pin, 0       );
  analogWrite(RM2pin, 0       );
  analogWrite(RM3pin, POWER_TR);

  analogWrite(LM1pin, POWER_TR);
  analogWrite(LM2pin, POWER_TR);
  analogWrite(LM3pin, POWER_TR);

  Serial.println("Turning Right");
  
}

void turnLeft(){

  POWER_TL=160; //Setting Power

  analogWrite(RM1pin, POWER_TL);
  analogWrite(RM2pin, POWER_TL);
  analogWrite(RM3pin, POWER_TL);

  analogWrite(LM1pin, 0       );
  analogWrite(LM2pin, 0       );
  analogWrite(LM3pin, POWER_TL);

  Serial.println("Turning Left")
  
}

void stopBreak(){

  POWER_SB=160; //Setting Power

  analogWrite(RM1pin, POWER_SB);
  analogWrite(RM2pin, 0       );
  analogWrite(RM3pin, 0       );

  analogWrite(LM1pin, POWER_SB);
  analogWrite(LM2pin, 0       );
  analogWrite(LM3pin, 0       );
  
  delay(100)
  Serial.println("Stopping");

}

/*code*/

void setup() {
  /*Serial*/
  
  Serial.begin(9600); 
  Serial.println("OCT-Rover Booting..."); //Booting Message

  /*pinMode*/
  
  pinMode(RM1pin, OUTPUT);
  pinMode(RM2pin, OUTPUT);
  pinMode(RM3pin, OUTPUT);
  
  pinMode(LM1pin, OUTPUT);
  pinMode(LM2pin, OUTPUT);
  pinMode(LM3pin, OUTPUT);
  
  pinMode(PS1pin, INPUT );
  pinMode(PS2pin, INPUT );
  pinMode(PS3pin, INPUT );

}

void loop() {

  /*NO Obstacle Detected*/

  if(analogRead(PS1pin) < 0){
     moveForward()    
    }
    
  if(analogRead(PS2pin) < 0){
     moveForward()
    }
    
  if(analogRead(PS3pin) < 0){
     moveForward()     
    }

  /*Some Obstacles Detected*/
  
  if(digitalRead(PS1pin) == ){
     Serial.println("Obstacle Detected!!")
     stopBreak();
     moveBackward();
    }

  
}
