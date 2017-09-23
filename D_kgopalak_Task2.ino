int potpin=0,bri,ledpin=9;


int potPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;   // select the pin for the LED
int val = 0;       // variable to store the value coming from the sensor
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int inpin0=2;
char color;

char invalue;
int value_bright;

int inPin = 3;         // the number of the input pin
int outPin = 9;       // the number of the output pin

int state = HIGH;      // the current state of the output pin
int reading; 
int reading1;
int state_val=0;// the current reading from the input pin
int previous = LOW;
int previous1 = LOW;// the previous reading from the input pin

long time = 0;         // the last time output pin was toggled
long debounce = 200; 


void setup() {
  // put your setup code here, to run once:
 //state0 set up
  pinMode(inPin, INPUT);
  pinMode(outPin, OUTPUT);
  //state1 set up
  analogReference(DEFAULT);
  pinMode(ledpin,OUTPUT);
  //state2 set up
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
  analogWrite(redPin, 255);
  analogWrite(bluePin, 255);
  analogWrite(greenPin, 255);
  //interrupt set up
  pinMode(inpin0, INPUT);
}

void loop() 
{
  reading1 = digitalRead(inpin0);

  if(reading1 != previous1)
  {
    if (reading1 == HIGH)
  {
    state_val+=1;
    Serial.print("state changed to ");
      
    if(state_val >3)
    {
      state_val=1;
      
    }
    Serial.println(state_val-1);
  }
      
     delay(50);  
  }

  previous1=reading1;
  
  if (state_val==1)
  {state0();}
  else if (state_val==2)
  {state1();}
  else if (state_val==3)
  {
    state2();  
  }
  // put your main code here, to run repeatedly:

}

void state2()
{
  String inp;
String num; 
int val; 
while (Serial.available() > 0) 
{
    inp= Serial.readString();
    Serial.println(inp);
    int valid=0;
    int i=0;
    while(i<inp.length()){
      /*if(inp[i]==' '){
        Serial.println('space detected');
        i+=1;
        continue;
      }
      else*/
      if(inp[i]=='r'|| inp[i]=='g'|| inp[i]=='b'){
        color=inp[i];
        //Serial.println(color);
        int j=i+1;
        int trial=1;
        valid=1;
        while(j<inp.length()){
          if (trial==1 && isDigit(inp[j])){
            num+=inp[j];
          }
          else if(inp[j]==' '){
            trial=0;
            continue;
          }
          
          else{
            valid=0;
            break;
          }
          j=j+1;
          
        }
        if(valid==1){
          //do analog write
          
          Serial.println(color);            
          val=num.toInt();
          Serial.println(val);
          if(val>=0 and val<=255){
            if(color=='r'){
              analogWrite(redPin,255-val);
              //analogWrite(bluePin,0);
              //analogWrite(greenPin,0);
            }
            else if(color=='g'){
              analogWrite(greenPin, 255-val);
            }
            else if(color=='b'){
              analogWrite(bluePin, 255-val);
            }
          }
          
        }
        else{
          break;
        }        
      }
      else{
        valid=0;
        break;
      }
      i=i+1;
    }
}
}

void state1()
{
  val=analogRead(potpin);

 bri=map(val , 0 , 1023 , 0, 255 );

analogWrite(ledpin,bri);
}

void state0()
{
  {
  reading = digitalRead(inPin);
  //Serial.println(reading);

  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH)
      state = LOW;
    else
      state = HIGH;
    time = millis();    
  }

  digitalWrite(redPin, state);
  digitalWrite(bluePin, state);
  digitalWrite(greenPin, state);
  previous = reading;
}
}



