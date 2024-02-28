#include <math.h>
#include <Servo.h>

Servo s1,s2,s3,s4;

// Constantes do termistor
#define A   0.00102192985237609
#define B   0.000241453242427025
#define C   -0.000000247620754758454
#define D   0.000000165394923419592

// Pino analógico para ler o NTC
#define NTC_PIN     A0
// Valor do resistor ligado em série com o NTC
#define RES_SERIE   10000.0

String sinais;

void setup()
{
  // Inicia a comunicação serial (monitor serial)
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  s1.attach(2);
  s2.attach(3);
  s3.attach(4);
  s4.attach(5);
}

void loop()
{
  float res, temp;

  // Mede o pino analógico e converte em resistência
  // A fórmula está simplificada, mas o passo a passo seria:
  // Converter leitura analógica em tensão -> converter tensão em resistência
  res = RES_SERIE/(1023.0/((float)analogRead(NTC_PIN)) - 1.0);

  // Calcula o ln da resistência para agilizar o cálculo seguinte
  res = log(res);

  // Converte a resistência em temperatura por meio da equação de Steinhart-Hart
  temp = A + B*res + C*res*res + D*res*res*res;
  // Inverte, pois a equação acima é 1/T
  temp = 1.0/temp;
  // Converte de Kelvin para ºC
  temp -= 273.15;
 
if (isnan(temp)) {    
    return;
  }

  // Imprime o valor
  //Serial.print("Temperatura: ");
  //Serial.print(temp, 2);
  //Serial.println("ºC");
  //sinais = String(temp) + "|";
   //aqui todos os motores vão se movimentar
  s1.write(180);//movimento do motor
  s2.write(180);
  s3.write(180);
  s4.write(180);
  delay(500);//faz ele esperar
  
  //aqui ele volta pra posição inicial
  s1.write(0);
  s2.write(0);
  s3.write(0);
  s4.write(0);
  delay(500); 

  

  Serial.println(temp-10);
  delay(5000);
  
  

  if(temp-20 <= 21 ){
    digitalWrite(12, HIGH);
    delay(10000);
    digitalWrite(12, LOW);
  }
 
  //delay(1000);
} 