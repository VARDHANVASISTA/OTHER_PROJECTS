//Declaration section
int red1=0;
int yellow1=1;
int green1=2;
int red2=3;
int yellow2=4;
int green2=5;
int red3=6;
int yellow3=7;
int green3=8;
int red4=9;
int yellow4=10;
int green4=11;

//void setup() section

void setup () {

pinMode (red1, OUTPUT); 
pinMode(green1, OUTPUT); 
pinMode(yellow1, OUTPUT); 
pinMode (red2, OUTPUT); 
pinMode(green2, OUTPUT); 
pinMode(yellow2, OUTPUT); 
pinMode (red3, OUTPUT); 
pinMode(green3, OUTPUT); 
pinMode(yellow3, OUTPUT); 
pinMode (red4, OUTPUT); 
pinMode(green4, OUTPUT); 
pinMode(yellow4, OUTPUT); 

}
//void loop() section

void loop() {

digitalWrite(green1, HIGH); 
digitalWrite(red2, HIGH); 
digitalWrite(red3, HIGH); 
digitalWrite(red4, HIGH); 
delay(2000); 
digitalWrite(yellow1, HIGH); 
digitalWrite(yellow2, HIGH); 
digitalWrite(green1, HIGH); 
digitalWrite(red2, HIGH);
digitalWrite(red3,HIGH); 
digitalWrite(red4, HIGH); 
delay(1000); 
digitalWrite(yellow1,LOW); 
digitalWrite(yellow2, LOW); 
digitalWrite(green1, LOW); 
digitalWrite(red2, LOW); 
digitalWrite(red3,LOW); 
digitalWrite(red4, LOW); 
//signal2
digitalWrite(green2, HIGH); 
digitalWrite(red1, HIGH); 
digitalWrite(red3, HIGH); 
digitalWrite(red4, HIGH);  
delay(2000); 
digitalWrite(yellow3,HIGH); 
digitalWrite(yellow2, HIGH); 
digitalWrite(green2, HIGH);
digitalWrite(red1, HIGH); 
digitalWrite(red3, HIGH); 
digitalWrite(red4, HIGH); 
delay(1000); 
digitalWrite(yellow2, LOW); 
digitalWrite(yellow3,LOW); 
digitalWrite(green2, LOW); 
digitalWrite(red1, LOW); 
digitalWrite(red3,LOW); 
digitalWrite(red4, LOW);
delay(100);
//signal3

digitalWrite(green3, HIGH); 
digitalWrite(red1, HIGH); 
digitalWrite(red2, HIGH); 
digitalWrite(red4,HIGH); 
delay(2000); 
digitalWrite(yellow3,HIGH); 
digitalWrite(yellow4,HIGH); 
digitalWrite(green3, HIGH);
digitalWrite(red1, HIGH); 
digitalWrite(red3,HIGH); 
digitalWrite(red4,HIGH); 
delay(1000); 
digitalWrite(yellow3,LOW); 
digitalWrite(yellow4,LOW); 
digitalWrite(green3, LOW); 
digitalWrite(red1, LOW); 
digitalWrite(red2, LOW); 
digitalWrite(red4, LOW); 
delay(100);
digitalWrite(green4, HIGH); 
digitalWrite(red1,HIGH); 
digitalWrite(red2, HIGH); 
digitalWrite(red3, HIGH); 
delay(2000); 
digitalWrite(yellow4, HIGH); 
digitalWrite(yellow1,HIGH); 
digitalWrite(green4, HIGH);
digitalWrite(red1,HIGH); 
digitalWrite(red3, HIGH); 
digitalWrite(red4,HIGH); 
delay(1000); 
digitalWrite(yellow4,LOW); 
digitalWrite(yellow1,LOW); 
digitalWrite(green4, LOW); 
digitalWrite(red1,LOW); 
digitalWrite(red2, LOW); 
digitalWrite(red3, LOW); 
delay(100);
}
