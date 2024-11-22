#include <Servo.h>

byte brushless1Pin = 9; // signal pin for the ESC.
byte brushless2Pin = 10; // signal pin for the ESC.
byte brushless3Pin = 11; // signal pin for the ESC.
byte brushless4Pin = 12; // signal pin for the ESC.
Servo esc1;
Servo esc2;
Servo esc3;
Servo esc4;

void help();

void setup() 
{
  Serial.begin(9600);
  
  Serial.println("Inicializando ESC 1");
  esc1.attach(brushless1Pin, 1000, 2000);
  esc1.writeMicroseconds(1500); //Enviado o sinal de Parada ao ESC. Necessário para armar o ESC.
  esc1.writeMicroseconds(0); //Condição Inicial de Aceleração do ESC deve ser zero.
  
  Serial.println("Inicializando ESC 2");
  esc2.attach(brushless2Pin, 1000, 2000);
  esc2.writeMicroseconds(1500); //Enviado o sinal de Parada ao ESC. Necessário para armar o ESC.
  esc2.writeMicroseconds(0); //Condição Inicial de Aceleração do ESC deve ser zero.

  Serial.println("Inicializando ESC 3");
  esc3.attach(brushless3Pin, 1000, 2000);
  esc3.writeMicroseconds(1500); //Enviado o sinal de Parada ao ESC. Necessário para armar o ESC.
  esc3.writeMicroseconds(0); //Condição Inicial de Aceleração do ESC deve ser zero.

  Serial.println("Inicializando ESC 4");
  esc4.attach(brushless4Pin, 1000, 2000);
  esc4.writeMicroseconds(1500); //Enviado o sinal de Parada ao ESC. Necessário para armar o ESC.
  esc4.writeMicroseconds(0); //Condição Inicial de Aceleração do ESC deve ser zero.

  delay(5000); // delay to allow the ESC to recognize the stopped signal.

  help();
}

String serialReceived;
String argcmd;
int argvalue;
int serialLength;

void loop() 
{
  if(Serial.available() > 0)
  {
    serialReceived = Serial.readString();
    //Serial.println(serialReceived);
    argcmd = serialReceived.substring(0, 4);
    //Serial.println(argcmd);
    if(argcmd.compareTo("esc1") == 0)
    {
      serialReceived.replace("esc1","");
      serialReceived.trim();
      argvalue = serialReceived.toInt();
      Serial.print("Acionando ESC1 com ");
      Serial.print(argvalue);
      Serial.println("% de carga");
      esc1.write(map(argvalue,0, 100, 0, 180));
    }
    else if(argcmd.compareTo("esc2") == 0)
    {
      serialReceived.replace("esc2","");
      serialReceived.trim();
      argvalue = serialReceived.toInt();
      Serial.print("Acionando ESC2 com ");
      Serial.print(argvalue);
      Serial.println("% de carga");
      esc2.write(map(argvalue,0, 100, 0, 180));
    }
    else if(argcmd.compareTo("esc3") == 0)
    {
      serialReceived.replace("esc3","");
      serialReceived.trim();
      argvalue = serialReceived.toInt();
      Serial.print("Acionando ESC3 com ");
      Serial.print(argvalue);
      Serial.println("% de carga");
      esc3.write(map(argvalue,0, 100, 0, 180));
    }
    else if(argcmd.compareTo("esc4") == 0)
    {
      serialReceived.replace("esc4","");
      serialReceived.trim();
      argvalue = serialReceived.toInt();
      Serial.print("Acionando ESC4 com ");
      Serial.print(argvalue);
      Serial.println("% de carga");
      esc4.write(map(argvalue,0, 100, 0, 180));
    }
    else
    {
      Serial.println("Comando Incorreto!");
      help();
    }
  }
  else
  {

  }
}

void help()
{
  Serial.println("");
  Serial.println("LISTA DE COMANDOS:");
  Serial.println("esc<[0-4]> <VALUE[0-100]>      Exemplo: esc1 0");
  Serial.println("esc<[0-4]> <VALUE[0-100]>      Exemplo: esc2 90");  
}