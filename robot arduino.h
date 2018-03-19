/*PRUEBA UNO PARA EL PROYECTO DE CLASE
ROBOT SEGUIDOR DE LINEA SIN VELOCIDAD
VARIABLE, SALIDA PWM*/

//--------------declarar motores.--------------

const int MupIz = //pin;
const int MupDer = //pin;

const int MdownIz = //pin;
const int MdownDer = //pin;

//salida PWM del controlador H, A es izquierda y B es derecha.
const int pinENA = //pin;
const int pinENB = //pin;

//--------------declarar sensores.--------------
//         IR5  IR4  IR3(0) IR2  IR1  (sensor mirandote)

const int IR5 = //pin;
const int IR4 = //pin;
const int Sensor0 = //pin;
const int IR2 = //pin;
const int IR1 = //pin;

//----------------Otras variables------------------
int ValSensores; 
//int umbral = 520; pruebo otra cosa, esto es privcional 
int vel1 = 90; //velocidad del motor inicial??
const int VelNula = 0; //velocidad 0
int VelR = 40; //provicional para la marcha atras.

//------------defino los estados de los sensores---------
int  IR5State = 0;
int  IR4State = 0;
int  Sensor0State = 0;
int  IR2State = 0;
int  IR1State = 0;
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
 
 
}

  
    void hacia_delante(){
	  
	MupIz(Vel1);
    MupDer(Vel1);
    
    MdownIz (VelNula);
    MdownDer (VelNula);
	
	analogWrite(pinENA, 255);
	analogWrite(pinENB, 255);
  }
 
 void giro_derecha(){
	 
 	MupIz(Vel1);
    MupDer(VelNula);
    
    MdownIz (VelR);
    MdownDer (VelNula);
	
	//prueba 2! freno motor izquiero y solo activo el derecho. 
	
	/*MupIz(VelNula);
    MupDer(Vel1;
    
    MdownIz (VelNula);
    MdownDer (VelNula);*/
 }
 
 void giro_izquierda(){
	 
	MupIz(VelNula);
    MupDer(Vel1);
    
    MdownIz (VelR);
    MdownDer (VelNula);
	
	//prueba 2! freno motor izquiero y solo activo el derecho. 
	
	/*MupIz(Vel1);
    MupDer(VelNula);
    
    MdownIz (VelNula);
    MdownDer (VelNula);*/
 }
 
 void encuentra_linea(){
	
 }
 
 void loop(){
	 
	 
  //Pongo en marcha los moteres:
  digitalWrite (MupDer, HIGH);
  digitalWrite (MupIz, HIGH);
  
  digitalWrite (MdownDer, LOW);
  digitalWrite (MdownIz, LOW);
	 
  //--------------------------------Prueba funcionamiento de los sensores.--------------------------------
  //Leo el estado de los sensores.
 
  IR5State = digitalRead(IR5);
  IR4State = digitalRead(IR4);
  Sensor0State = digitalRead(Sensor0);
  IR2State = digitalRead(IR2);
  IR1State = digitalRead(IR1);
  
  //Combinacion de los valores totales de los sensores para la comprobacion 
  ValSensores = (IR5State * 10000) + (IR4State * 1000) + (Sensor0State * 100) + (IR2State * 10) + (IR1State);
 
  //muestro si detectan la linea negra o no.
 
  if(IR5State==HIGH){Serial.print("||black = IR5||"); Serial.print("");}
  else{Serial.print("||white = IR5||"); Serial.print("");}

  if(IR4State==HIGH){Serial.print("||black = IR4||"); Serial.print("");}
  else{Serial.print("||white = IR4||"); Serial.print("");}

  if(Sensor0State==HIGH){Serial.print("||black = IR3(0)||"); Serial.print("");}
  else{Serial.print("||white = IR3(0)||"); Serial.print("");}
 
  if(IR2State==HIGH){Serial.print("||black = IR2||"); Serial.print("");}
  else{Serial.print("||white = IR2||"); Serial.print("");}
 
  if(IR1State==HIGH){Serial.print("||black = IR1||"); Serial.print("");}
  else{Serial.print("||white = IR1||"); Serial.print("");}
 
  Serial.println("*********************************");
  delay(500);
  //---------------------------------------------------------------------------------------------------------
	 
  //--------------------------------Funcionamiento del coche--------------------------------
  //         IR5  IR4  IR3(0) IR2  IR1  (sensor mirandote)
  
  switch (ValSensores){
	  
	  case 100:
	  hacia_delante;
	  break;
	  
	  case 1110:
	  hacia_delante;
	  break;
	  
	  case 110:  //giro izquierda
	  giro_izquierda; 
	  break;
	  
	  case 111: //giro más cerrado izquierda
	  giro_izquierda;
	  break;
	  
	  case 1100://giro derecha
	  giro_derecha;
	  break;
	  
	  case 11100://giro más cerrado izquierda
	  giro_derecha;
	  break;
	  
	  default:
	  
  }

 }
