//#define TEST
unsigned char KeepWorking[7]={ 0X7E ,0X02, 0X09 ,0XEF };
unsigned char StopPlay[7] = { 0X7E ,0X02, 0X0E ,0XEF };  //stop the speaker from playing sounds
unsigned char Button1[7] = { 0X7e,0X04,0X41,0X00,0X01,0XEF };  //Play the first sound.
unsigned char Button2[7] = { 0X7e,0X04,0X41,0X00,0X02,0XEF };
unsigned char Button3[7] = { 0X7e,0X04,0X41,0X00,0X03,0XEF };
unsigned char Button4[7] = { 0X7e,0X04,0X41,0X00,0X04,0XEF };
unsigned char Button5[7] = { 0X7e,0X04,0X41,0X00,0X05,0XEF };
unsigned char Button6[7] = { 0X7e,0X04,0X41,0X00,0X06,0XEF };
unsigned char Button7[7] = { 0X7e,0X04,0X41,0X00,0X07,0XEF };
unsigned char Button8[7] = { 0X7e,0X04,0X41,0X00,0X08,0XEF };
unsigned char Button9[7] = { 0X7e,0X04,0X41,0X00,0X09,0XEF };
unsigned char Button10[7] = { 0X7e,0X04,0X41,0X00,0X0A,0XEF };  //Play the tenth sound.
unsigned char *pButton[10]={Button1,Button2,Button3,Button4,Button5,Button6,Button7,Button8,Button9,Button10};

int button[5]={0};
const int numOfKey=5;
void setup() {
  pinMode(51,INPUT);
  pinMode(53,INPUT);
  pinMode(49,INPUT);
  pinMode(47,INPUT);
  pinMode(45,INPUT);
  button[0]=digitalRead(45);
  button[1]=digitalRead(47);
  button[2]=digitalRead(49);
  button[3]=digitalRead(51);
  button[4]=digitalRead(53);
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);
  delay(1000);
}

typedef struct _speaker { bool isOn; int button; int duration ;int tag;}Speaker;
Speaker sp1 = { false,0,0,1};
Speaker sp2 = { false,0,0,2};
Speaker sp3 = { false,0,0,3};

int* Sensor();//this function should return int array with 10 elements which are 0 or 1
int* findNumber(int* sensor);
int isStillPress(Speaker sp, int* keyNumber);
void Refresh(int* sensor);
void playSound(void);
void timeLapse();

int check_loop=0;
int durationCheck=50;

void loop() {
    int* sensor = Sensor();
    Refresh(sensor);
    free(sensor); 
    
    playSound();
    timeLapse();
    
    check_loop++;   
    delay(50);

    
    #ifdef TEST
    if((check_loop+1)/3==(int) (check_loop+1)/3){}
    #endif
}

void playSound(void){
  #ifdef TEST
  Serial.print("sp1: ");  Serial.print(sp1.isOn);Serial.print("-");Serial.print(sp1.button);Serial.print("-");Serial.println(sp1.duration);
  Serial.print("sp2: ");  Serial.print(sp2.isOn);Serial.print("-");Serial.print(sp2.button);Serial.print("-");Serial.println(sp2.duration);
  Serial.print("sp3: ");  Serial.print(sp3.isOn);Serial.print("-");Serial.print(sp3.button);Serial.print("-");Serial.println(sp3.duration);
  #endif
  
      if((sp1.isOn)&&(sp1.duration==0)){
        
          //Serial1.write(StopPlay,4);
          //Serial1.write(KeepWorking,4);
          Serial1.write(pButton[sp1.button],6);delay(5);Serial.println("niqiu1");}
     else if(sp1.isOn==0){Serial.write(StopPlay,4);delay(5);Serial.println("jyz1");}
      if((sp2.isOn)&&(sp2.duration==0)){
          Serial2.write(pButton[sp2.button],6);delay(5);Serial.println("niqiu2");}
          else if(sp2.isOn==0){Serial2.write(StopPlay,4);delay(5);Serial.println("jyz2");}
      if((sp3.isOn)&&(sp3.duration==0)){
          Serial3.write(pButton[sp3.button],6);delay(5);Serial.println("niqiu3");}
         else if(sp3.isOn==0){Serial3.write(StopPlay,4);delay(5);Serial.println("jyz3");}
      }

int isStillPress(Speaker sp, int* keyNumber)//judge whether the button of the speaker is still being pressed.If so, sp_button stays the same.If not, let sp_button=0.
{
  
  for (int i = 0; i < 3; i++)
  {
    
    if (sp.button == *(keyNumber+i))
    {
      int temp;
      temp = *(keyNumber+i);
      *(keyNumber+i) = 0;
    
      return temp;
    }
  }
  return 0;
}


void timeLapse()
{
    if (sp1.button!=0) { sp1.duration = sp1.duration+50; } 
  if (sp2.button!=0) { sp2.duration = sp2.duration+50; } 
  if (sp3.button!=0) { sp3.duration = sp3.duration+50; } 
}
void Refresh(int* sensor)//This function refresh the arrangement of speakers for buttons..
{
  int* keyNumber = findNumber(sensor);
  if (sp1.button!=0)
  { 
    sp1.button = isStillPress(sp1, keyNumber);
    if(sp1.button==0){sp1.duration=0;}
  }
  if (sp2.button!=0)
  { 
    sp2.button = isStillPress(sp2, keyNumber);
     if(sp2.button==0){sp2.duration=0;}
  } 
  if (sp3.button!=0)
  { 
    sp3.button = isStillPress(sp3, keyNumber);
     if(sp3.button==0){sp3.duration=0;}
  } 
  for (int i = 0; i < 3; i++)
  {
    
    if (keyNumber[i] != 0)
    {
      
      if (sp1.button==0) { sp1.button = *(keyNumber+i);  }
      else if (sp2.button==0) { sp2.button = *(keyNumber+i);  }
      else if (sp3.button==0) { sp3.button = *(keyNumber+i);  }
    }
  }


  if (sp1.button != 0) {sp1.isOn = true; }
  else { sp1.isOn = false; sp1.duration=0;}
  if (sp2.button != 0) {  sp2.isOn = true; }
  else { sp2.isOn = false;sp2.duration=0; }
  if (sp3.button!= 0) {  sp3.isOn = true; }
  else { sp3.isOn = false; sp3.duration=0;}
  
  free(keyNumber);
}

int* findNumber(int* sensor){//Process the sensor pointer and returns a int array[3] describing the buttons being pressed
  int* keyNumber=(int*)malloc(3*sizeof(int));
  int j = 0;
  for (int i = 0; i < numOfKey; i++)
  {
    if ((sensor[i] != 0) && (j < 3)) { *(keyNumber+j) = i + 1; j++; }
  }
  return keyNumber;
}

int* Sensor(){
  int* sensor=(int*) malloc(numOfKey*sizeof(int));

  for(int i=0;i<numOfKey;i++){
    *(sensor+i)=digitalRead(45+2*i);
  }
 
 

  return(sensor);
}


