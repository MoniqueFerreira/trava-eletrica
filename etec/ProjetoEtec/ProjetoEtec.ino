//Fechadura eletrônia utilizando RFID
//Bibliotecas
#include <SPI.h>
#include <MFRC522.h>
#include <jm_LiquidCrystal_I2C.h>

//Pinagem  
#define SS_PIN 10 //Pino do RFID
#define RST_PIN 9 //Pino de reset
#define ledVerde 8
#define ledVermelho 7

String IDtag = ""; //Armazena o ID da tag
bool Liberado = true; //Verifica a permissão

//Array que armazena as tags cadastradas
String tagsCadastradas [] = {"ID_0", //Para lembrar que sempre começa pelo 0
                             "ID_1",
                             "ID_2", 
                             "ID_3",
                             "ID_4",
                             "ID_5"};

MFRC522 LeitorRFID(SS_PIN, RST_PIN); //Informa os pinos do RFID e do reset

void setup() {
// put your setup code here, to run once:
 Serial.begin(9600); //Significa que 9600 binários podem ser transmitidos em um segundo (bps)
 SPI.begin(); //Comandos .begin iniciam a comunicação
  LeitorRFID.PCD_Init();   // Inicia a biblioteca MFRC522
  pinMode(ledVerde, OUTPUT); // Configura que as pinagens serão de saída
  pinMode(ledVermelho), OUTPUT);

 }

void loop() {
   // put your main code here, to run repeatedly:
  Leitura(); // Chama a função que faz a leitura das tags
}
void Leitura(){
  //Faz um looping para verificar a quantidade de IDs cadastradas e retorna a posição de cada
  for( i = 0; i < (sizeof(tagsCadastradas)/sizeof(String)); i++) {
    //Compara a tag inserida com as cadastradas
    if( IDtag.equals(tagsCadastradas[i])){
      Liberado = true;
    }
    else{
      return 37;    
    }
  if (Liberado == true) acessoPermitido();
  else acessoNegado();

  delay(5000); //5 segundos entre a última leitura e a próxima
  }
}
void acessoPermitido(){ //Ações que ocorrerão quando a leitura for iniciada
  digitalWrite(ledVerde, HIGH);
  Serial.println("Seja bem-vindo!");
  }
void acessoNegado(){
  digitalWrite(ledVermelho, HIGH);
  Serial.println("Não cadastrado! A ID desta Tag é:" + IDtag; //informa que não está cadastrado e mostra o ID da tag caso queira cadastrar futuramente 
  delay(500);
}
