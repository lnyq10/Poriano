unsigned char StopPlay[7]={0X7E ,0X02, 0X02 ,0XEF};  //stop the speaker from playing sounds
unsigned char Button1[7]={0X7e,0X04,0X41,0X00,0X01,0XEF};  //Play the first sound.
unsigned char Button2[7]={0X7e,0X04,0X41,0X00,0X02,0XEF};  
unsigned char Button3[7]={0X7e,0X04,0X41,0X00,0X03,0XEF};  
unsigned char Button4[7]={0X7e,0X04,0X41,0X00,0X04,0XEF};  
unsigned char Button5[7]={0X7e,0X04,0X41,0X00,0X05,0XEF};  
unsigned char Button6[7]={0X7e,0X04,0X41,0X00,0X06,0XEF};  
unsigned char Button7[7]={0X7e,0X04,0X41,0X00,0X07,0XEF};  
unsigned char Button8[7]={0X7e,0X04,0X41,0X00,0X08,0XEF};  
unsigned char Button9[7]={0X7e,0X04,0X41,0X00,0X09,0XEF};  
unsigned char Button10[7]={0X7e,0X04,0X41,0X00,0X0A,0XEF};  //Play the tenth sound.

typedef  struct _speaker{bool isOn;int button;int duration;}Speaker;
Speaker sp1={false,0,0};
Speaker sp2={false,0,0};
Speaker sp3={false,0,0};


int* Sensor();//this function should return int array with 20 elements which are 0 or 1
void setup() {
  
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);
}

void loop() {
  int* sensor=Sensor();
  
  
  //For test
  Serial1.write(Button8,6);
  Serial2.write(Button9,6);
  
  /*delay(500);  
  Serial1.write(StopPlay,4);
  Serial2.write(StopPlay,4);*/




  free(sensor);
  delay(6000);
}
int* Sensor(){
  
}


/*Serial1.write(JDQdata3,4);
  Serial.println("I am excuting this command");*/ //下一曲
