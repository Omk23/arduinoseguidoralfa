/*PRUEBA UNO PARA EL PROYECTO DE CLASE
ROBOT SEGUIDOR DE LINEA SIN VELOCIDAD
VARIABLE, SALIDA PWM*/

//--------------declarar motores.--------------

const int MupIz = //pin; OUT 1
const int MupDer = //pin; OUT 4

const int MdownIz = //pin; OUT 2
const int MdownDer = //pin; OUT 3

//salida PWM del controlador H, A es izquierda y B es derecha.
const int pinENA = //pin; IZ
const int pinENB = //pin; DER

//--------------declarar sensores.--------------
//         IR5  IR4  IR3(0) IR2  IR1  (sensor mirandote)

const int IR5 = 13;
const int IR4 = 12;
const int Sensor0 = 8;
const int IR2 = 7;
const int IR1 = 4;

//------------defino los estados de los sensores---------
int  IR5State = 0;
int  IR4State = 0;
int  Sensor0State = 0;
int  IR2State = 0;
int  IR1State = 0;

//----------------Otras variables------------------
int ValSensores; 
//int umbral = 520; pruebo otra cosa, esto es privcional 
//int VMax = 90; //velocidad del motor inicial??
const int VMax = 140
//const int VelNula = 0; //velocidad 0
//int VelR = 40; //provicional para la marcha atras.
const int VelRMax = 80;

const int adelante = 1; //redundancia 

//-----------------para quitar delays----------------
unsigned long startMillis;//las variables globales 
unsigned long currentMillis;
const unsigned long period = 2000; //valor en milisegundos
const unsigned long period2 = 1000;
//-------------------------------------------------
void setup(){
 
  pinMode (MupIz, OUTPUT);
  pinMode (MupDer, OUTPUT);
 
  pinMode (MdownIz, OUTPUT);
  pinMode (MupDer, OUTPUT);
 
  pinMode (pinENA, OUTPUT);
  pinMode (pinENB, OUTPUT);
 
  Serial.begin (9600);
 
  pinMode(IR5, INPUT);
  pinMode(IR4, INPUT);
  pinMode(Sensor0, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR1, INPUT);
  
  startMillis = millis(); //tiempo inicial 
 
}

  
 void hacia_delante(){
	  if(adelante == 1){
		digitalWrite (MupDer, HIGH);
		digitalWrite (MupIz, HIGH);
		
		digitalWrite (MdownDer, LOW);
		digitalWrite (MdownIz, LOW);
		
		analogWrite (pinENB, VMax);
		analogWrite (pinENB, VMax);
  }
 
 void giro_derecha(){
	 
	 if (adelante == 1){
		digitalWrite (MupDer, LOW);
		digitalWrite (MupIz, HIGH);
		
		digitalWrite (MdownDer, HIGH);
		digitalWrite (MdownIz, LOW);
		
		analogWrite (pinENB, VelRMax);
		analogWrite (pinENB, VMax);
	 }
	 
 }
 
 void giro_izquierda(){
	 
	if (adelante == 1){
		digitalWrite (MupDer, HIGH);
		digitalWrite (MupIz, LOW);
		
		digitalWrite (MdownDer, LOW);
		digitalWrite (MdownIz, HIGH);
		
		analogWrite (pinENB, VMax);
		analogWrite (pinENB, VelRMax);
	} 

 }
 
 void encuentra_linea(){
	
	currentMillis = millis();
	if(currentMillis - startMillis >= period2){
		digitalWrite (MupDer, HIGH);
		digitalWrite (MupIz, LOW);
    
		digitalWrite (MdownDer, LOW);
		digitalWrite (MdownIz, HIGH);
		
		analogWrite(pinENA, 180);
		analogWrite(pinENB, 70);
	}
	else if (currentMillis - startMillis >=period{ //provicional
		digitalWrite (MupDer, HIGH);
		digitalWrite (MupIz, HIGH);
    
		digitalWrite (MdownDer, LOW);
		digitalWrite (MdownIz, LOW);
	
		analogWrite(pinENA, 100);
		analogWrite(pinENB, 100);
	}
 }
 
 void loop(){
	 
  /*Pongo en marcha los moteres:
  digitalWrite (MupDer, HIGH);
  digitalWrite (MupIz, HIGH);
  
  digitalWrite (MdownDer, LOW);
  digitalWrite (MdownIz, LOW);*/
  
	//------------defino los estados de los sensores---------
	int  IR5State = 0;
	int  IR4State = 0;
	int  Sensor0State = 0;
	int  IR2State = 0;
	int  IR1State = 0;
	 
  //--------------------------------Prueba funcionamiento de los sensores.--------------------------------
  //Leo el estado de los sensores.
 
  IR5State = digitalRead(IR5);
  IR4State = digitalRead(IR4);
  Sensor0State = digitalRead(Sensor0);
  IR2State = digitalRead(IR2);
  IR1State = digitalRead(IR1);
  
  //Combinacion de los valores totales de los sensores para la comprobacion 
  ValSensores = (IR5State * 10000) + (IR4State * 1000) + (Sensor0State * 100) + (IR2State * 10) + (IR1State);
  //        			 IR5 				 IR4 				IR3(0) 					IR2			  IR1  (sensor mirandote)
 
  //muestro si detectan la linea negra o no.
 
  if(IR5State==HIGH){Serial.print("||White = IR5||"); Serial.print("");}
  else{Serial.print("||Black = IR5||"); Serial.print("");}

  if(IR4State==HIGH){Serial.print("||White = IR4||"); Serial.print("");}
  else{Serial.print("||Black = IR4||"); Serial.print("");}

  if(Sensor0State==HIGH){Serial.print("||White = IR3(0)||"); Serial.print("");}
  else{Serial.print("||Black = IR3(0)||"); Serial.print("");}
 
  if(IR2State==HIGH){Serial.print("||White = IR2||"); Serial.print("");}
  else{Serial.print("||Black = IR2||"); Serial.print("");}
 
  if(IR1State==HIGH){Serial.print("||White = IR1||"); Serial.print("");}
  else{Serial.print("||Black = IR1||"); Serial.print("");}
 
  Serial.println("*********************************");
	 
  //--------------------------------Funcionamiento del coche--------------------------------
  //         IR5  IR4  IR3(0) IR2  IR1  (sensor mirandote)
  
  switch (ValSensores){
	  
	  case 11011:
	  hacia_delante();
	  break;
	  
	  case 10001:
	  hacia_delante();
	  break;
	  
	  case 10011:  //giro izquierda
	  giro_izquierda(); 
	  break;
	  
	  case 00111: //giro más cerrado izquierda
	  giro_izquierda();
	  break;
	  
	  case 11001://giro derecha
	  giro_derecha();
	  break;
	  
	  case 11000://giro más cerrado izquierda
	  giro_derecha();
	  break;
	  
	  default:
	  encuentra_linea();
	  break;
  }

 }