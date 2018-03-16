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

int umbral = 520;
const int vel1 = 90; //velocidad del motor inicial??
const int VelNula = 0; //velocidad 0
const int VelR = 40; //provicional para la marcha atras.

//------------defino los estados de los sensores---------
int  IR5State;
int  IR4State;
int  Sensor0State;
int  IR2State;
int  IR1State;
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

/*void loop(){
 
  //--------------------------------Prueba funcionamiento de los sensores.--------------------------------
  //Leo el estado de los sensores.
 
  IR5State = digitalRead(IR5);
  IR4State = digitalRead(IR4);
  Sensor0State = digitalRead(Sensor0);
  IR2State = digitalRead(IR2);
  IR1State = digitalRead(IR1);
 
  //muestro si detectan la linea negra o no.
 
  if(IR5State==HIGH){Serial.print("||black = IR5||"); Serial.print("");}
  if(IR5State==LOW){Serial.print("||white = IR5||"); Serial.print("");}

  if(IR4State==HIGH){Serial.print("||black = IR4||"); Serial.print("");}
  if(IR4State==LOW){Serial.print("||white = IR4||"); Serial.print("");}

  if(Sensor0State==HIGH){Serial.print("||black = IR3(0)||"); Serial.print("");}
  if(Sensor0State==LOW){Serial.print("||white = IR3(0)||"); Serial.print("");}
 
  if(IR2State==HIGH){Serial.print("||black = IR2||"); Serial.print("");}
  if(IR2State==LOW){Serial.print("||white = IR2||"); Serial.print("");}
 
  if(IR1State==HIGH){Serial.print("||black = IR1||"); Serial.print("");}
  if(IR1State==LOW){Serial.print("||white = IR1||"); Serial.print("");}
 
  Serial.println("*********************************");
  delay(500);
 
  //---------------------------------------------------------------------------------------------------------
 
  //--------------------------------Funcionamiento del coche--------------------------------
  //         IR5  IR4  IR3(0) IR2  IR1  (sensor mirandote)
  //motor va en linea reca cuando los tres sensores del medio pasan por la linea negra.
  
    if(IR5State<umbral && IR4State<umbral && Sensor0State>umbral && IR2State<umbral && IR1State<umbral){ //va recto.
    // 0  					0					1						0					0
	MupIz(Vel1);
    MupDer(Vel1);
    
    MdownIz (VelNula);
    MdownDer (VelNula);
    
  }
 
  else if(IR5State<umbral && IR4State>umbral && Sensor0State>umbral && IR2State<umbral && IR1State<umbral  || IR5State>umbral && IR4State>umbral && Sensor0State>umbral && IR2State<umbral && IR1State<umbral){ //gira a la izquierda*/
    // 			0  					1					1						0					0 	   || 	     1  				1					1						0					0
	//prueba! giro up motor izquierdo down derecho en plan giro horario pero con ditinta velocidad. 
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
	
	/*else if(IR5State<umbral && IR4State<umbral && Sensor0State>umbral && IR2State>umbral && IR1State>umbral || IR5State<umbral && IR4State<umbral && Sensor0State>umbral && IR2State>umbral && IR1State<umbral){  //giro a la derecha 
	// 				0  					0					1					1					1		||  	0  					0					1						1					0
	//prueba! giro up motor izquierdo down derecho en plan giro horario pero con ditinta velocidad. 
	MupIz(Vel1);
    MupDer(VelNula);
    
    MdownIz (VelR);
    MdownDer (VelNula);
	
	//prueba 2! freno motor izquiero y solo activo el derecho. 
	
	MupIz(VelNula);
    MupDer(Vel1;
    
    MdownIz (VelNula);
    MdownDer (VelNula);*/
	
	
	
	/*else if(IR5State<umbral && IR4State<umbral && Sensor0State<umbral && IR2State<umbral && IR1State<umbral){
		
	MupIz(Vel1);
    MupDer(vel1);
    
    MdownIz (VelNula);
    MdownDer (VelNula);
	}*/


  
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
 
 void loop(){
	 
  //--------------------------------Prueba funcionamiento de los sensores.--------------------------------
  //Leo el estado de los sensores.
 
  IR5State = digitalRead(IR5);
  IR4State = digitalRead(IR4);
  Sensor0State = digitalRead(Sensor0);
  IR2State = digitalRead(IR2);
  IR1State = digitalRead(IR1);
 
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
  //motor va en linea reca cuando los tres sensores del medio pasan por la linea negra.
  
    if(IR5State<umbral && IR4State<umbral && Sensor0State>umbral && IR2State<umbral && IR1State<umbral){ //va recto.
    // 0  					0					1						0					0
	hacia_delante();
    }
	 
	 
	 
	 
 }
 
 
 
