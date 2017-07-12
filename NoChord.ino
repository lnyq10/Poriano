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
unsigned char *pButton[10]={Button1,Button2,Button3,Button4,Button5,Button6,Button7,Button8,Button9,Button10};


typedef  struct _speaker{bool isOn;int button;int duration;}Speaker;
Speaker sp1={false,0,0};
Speaker sp2={false,0,0};
Speaker sp3={false,0,0};

int button[3]={0,0,0};
void setup() {
  pinMode(51,INPUT);
  pinMode(53,INPUT);
  pinMode(49,INPUT);
  button[0]=digitalRead(49);
  button[1]=digitalRead(51);
  button[2]=digitalRead(53);
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);
  delay(1000);
}
int* Sensor();


void loop() {
  int* sensor=Sensor();
  if(sensor[0]==1){
    Serial1.write(pButton[0],6);
  }
  if(sensor[1]==1){
    Serial1.write(pButton[1],6);
  }
  if(sensor[2]==1){
    Serial1.write(pButton[2],6);
  }
  Serial.println(sensor[0]);
  Serial.println(sensor[1]);
  Serial.println(sensor[2]);
  Serial.println("*******");


  free(sensor);
  delay(50);
}
int* Sensor(){
  int* sensor=(int*) malloc(3*sizeof(int));
  int button_new[3]={0};
  for(int i=0;i<3;i++){
    *(sensor+i)=0;
    button_new[i]=digitalRead(49+2*i);
  }
 
  for(int i=0;i<3;i++){
     if(button_new[i]!=button[i]){
       *(sensor+i)=1;
     }
     button[i]=button_new[i];
  }

  return(sensor);
}

