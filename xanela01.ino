// declarar os pins de entrada e salida que conectaremos no ARDUINO
const int pinEntrada = 4;//Entrada al ARDUINO
const int pinMotor1 = 8;//Salida de ARDUINO a RELE motor1
const int pinMotor2 = 2;//Salida de ARDUINO a RELE motor2


// Variable para controlar qué saida está activa
int salidaActiva = 0;

// Creamos unha variable para almacenar o estado da entrada
int estadoEntradaAnterior = LOW;

// Variable para controlar o tempo de saidas activas 
int contadortiempo = 7000;



void setup() {
  // Activar os pins
  pinMode(pinEntrada, INPUT);
  pinMode(pinMotor1, OUTPUT);
  pinMode(pinMotor2, OUTPUT);
}

void loop() {
  // Indicanos en que estado actual está a entrada
  int estadoEntrada = digitalRead(pinEntrada);
  
 
  if (contadortiempo>=7000){//motor párase despois de 7 segundos
    digitalWrite(pinMotor2, LOW);
    digitalWrite(pinMotor1, LOW);
  }
  else contadortiempo=contadortiempo+10;
  
  // cambios de (baixa 0) a (alta 1), de LOW a HIGH (activada)
  if (estadoEntrada == HIGH && estadoEntradaAnterior == LOW) {
    
  // indicamos como queremos que se active motor1 ou motor2
    if (salidaActiva == 0) {
      digitalWrite(pinMotor1, HIGH);
      digitalWrite(pinMotor2, LOW);
      salidaActiva = 1;
      
    } else {
      digitalWrite(pinMotor1, LOW);
      digitalWrite(pinMotor2, HIGH);
      salidaActiva = 0;
    }
    contadortiempo = 0; 
  }
  delay (10);
  // retomamos o estado anterior da entrada
  estadoEntradaAnterior = estadoEntrada;
}
