unsigned char JDQdata1[7]={0X7E ,0X02, 0X02 ,0XEF};  
unsigned char Number2[7]={0X7e,0X04,0X41,0X00,0X08,0XEF};  
unsigned char Number3[7]={0X7e,0X04,0X41,0X00,0X04,0XEF};   
unsigned char JDQdata4[7]={0X7e,0X04,0X41,0X00,0X01,0Xef};  

void setup() {
  
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
}

void loop() {
  
  
  
  
  Serial1.write(Number2,6);
  Serial2.write(Number3,6);
  Serial.println("i am here");
  delay(1000);
  
  
  Serial1.write(JDQdata1,4);
  Serial2.write(JDQdata1,4);
 
  delay(6000);
}





/*Serial1.write(JDQdata3,4);
  Serial.println("I am excuting this command");*/ //下一曲
