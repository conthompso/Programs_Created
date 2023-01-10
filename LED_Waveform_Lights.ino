#include <FastLED.h>

#define NUM_LEDS 150        // How many leds in your strip?
#define updateLEDS 1       // How many do you want to update every millisecond?
#define COLOR_SHIFT 10000  // Time for colours to shift to a new spectrum (in ms)
CRGB leds[NUM_LEDS];        // Define the array of leds


//Declare Spectrum Shield pin connections
#define STROBE 4
#define RESET 5
#define DC_One A0
#define DC_Two A1
#define DATA_PIN 8

//Define spectrum variables
int freq_amp;
int Frequencies_One[7];
int Frequencies_Two[7];

struct color{
  int r;
  int g;
  int b;
};

color c;


void setup() {
  //Set spectrum Shield pin configurations
  pinMode(STROBE, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(DC_One, INPUT);
  pinMode(DC_Two, INPUT);

  //Initialize Spectrum Analyzers
  digitalWrite(STROBE, LOW);
  digitalWrite(RESET, LOW);
  delay(50);

//  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);

  for(int i = 0; i < NUM_LEDS ; i++) {
      leds[i] = CRGB(0,0,0);
    }
    FastLED.show();


  Serial.begin(9600);
  
}

void loop() {
//  delay(50);
  int Vol = digitalRead(7);
  Serial.print("(");
  Serial.print(Vol);
  Serial.println(")");
  Read_Frequencies();
  
  for (int i = NUM_LEDS - 1; i >= updateLEDS; i--){
    leds[i] = leds[i - updateLEDS];
  }
  
  
  
//  Serial.print(" Frequencies ");
//  Serial.println(" ");
  int sensMax = 0;
  for (int i = 0; i < 7; i++){
//    Serial.print(Frequencies_One[i]);
//    Serial.print(" ");
//    Serial.print(Frequencies_Two[i]);
    
    sensMax = max(sensMax, Frequencies_One[i]);
//    Serial.print(" ");
  }
  pitchConv(sensMax);
  leds[0] = CRGB(c.r, c.g, c.b);
  

  
//  Serial.print("       ");
//  for (int i = 0; i < 7; i++){
//    Serial.print(Frequencies_Two[i]);
//    sensMax = max(sensMax, Frequencies_Two[i]);
//    Serial.print(" ");
//  }
//  Serial.println(" ");
}


void Read_Frequencies() {
  digitalWrite(RESET, HIGH);
  delayMicroseconds(200);
  digitalWrite(RESET, LOW);
  delayMicroseconds(200);

//  Serial.print("( ");
  //Read frequencies for each band
  for (freq_amp = 0; freq_amp < 7; freq_amp++)
  {
    digitalWrite(STROBE, HIGH);
    delayMicroseconds(50);
    digitalWrite(STROBE, LOW);
    delayMicroseconds(50);

    Frequencies_One[freq_amp] = analogRead(DC_One);
    Frequencies_Two[freq_amp] = analogRead(DC_Two);


//    Serial.print(Frequencies_One[1]);
//    Serial.print(", ");
  }
//  Serial.print(" )");
//  Serial.println(" ");
}


void pitchConv(int FreqMax) {
//    Serial.println(FreqMax);
  if(FreqMax < 85) {
    setColor( 0, 0, 0);
//        Serial.println("indonesia");
  }
////////////////OG///////////////////////OG/////////////////////////////OG/////////////////
//  else if(FreqMax >= 85 && FreqMax <= 90) {
//    setColor( 157, 50, 168);
//        Serial.println("fig");
//  }
//  else if(FreqMax <= 90 && FreqMax <= 120) {
//    setColor( 107, 50, 168);
//        Serial.println("elephant");
//  }
//  else if(FreqMax >= 120 && FreqMax <= 150) {
//    setColor( 80, 50, 168);
//        Serial.println("dog");
//  }
//  else if(FreqMax >= 150 && FreqMax <= 180) {
//    setColor( 143, 168, 50);
//        Serial.println("candy");
//  }
//  else if(FreqMax >= 180 && FreqMax <= 200) {
//    setColor(0, 100, 200);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 200 && FreqMax <= 230) {
//    setColor( 168, 164, 50);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 230 && FreqMax <= 260) {
//    setColor( 168, 145, 50);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 260 && FreqMax <= 290) {
//    setColor( 168, 119, 50);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 290 && FreqMax <= 320) {
//    setColor( 168, 100, 50);
//        Serial.println("banana");
//  }
//  else if(FreqMax >= 320 && FreqMax <= 350) {
//    setColor(168, 74, 50);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 350 && FreqMax <= 380) {
//    setColor( 168, 50, 66);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 380 && FreqMax <= 410) {
//    setColor( 168, 50, 111);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 410 && FreqMax <= 440) {
//    setColor( 168, 50, 147);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 440 && FreqMax <= 470) {
//    setColor( 157, 50, 168);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 470 && FreqMax <= 500) {
//    setColor( 125, 50, 168);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 500 && FreqMax <= 530) {
//    setColor( 94, 50, 168);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 530 && FreqMax <= 560) {
//    setColor( 50, 70, 168);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 560 && FreqMax <= 590) {
//    setColor( 50, 111, 168);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 590 && FreqMax <= 620) {
//    setColor( 50, 147, 168);
//        Serial.println("banana");
//  }
//  else if(FreqMax >= 620 && FreqMax <= 650) {
//    setColor( 50, 168, 153);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 650 && FreqMax <= 680) {
//    setColor( 50, 168, 117);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 680 && FreqMax <= 710) {
//    setColor( 50, 168, 84);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 710 && FreqMax <= 740) {
//    setColor( 66, 168, 50);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 740 && FreqMax <= 770) {
//    setColor( 113, 168, 50);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 770 && FreqMax <= 800) {
//    setColor( 147, 168, 50);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 800 && FreqMax <= 830) {
//    setColor( 168, 151, 50);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 830 && FreqMax <= 860) {
//    setColor(168, 100, 50);
//        Serial.println("banana");
//  }  
//  else if(FreqMax >= 860 && FreqMax <= 890) {
//    setColor(168, 74, 50);
//        Serial.println("banana");
//  }
//  else if(FreqMax >= 890 && FreqMax <= 915) {
//    setColor(168, 50, 92);
//        Serial.println("banana");
//  }
//  else if(FreqMax >= 915 && FreqMax <= 940) {
//    setColor(168, 50, 157);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 940 && FreqMax <= 955) {
//    setColor(147, 50, 168);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 955 && FreqMax <= 970) {
//    setColor(115,50,168);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 970 && FreqMax <= 985) {
//    setColor(50,135,168);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 985 && FreqMax <= 1000) {
//    setColor(0, 100, 200);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 1000 && FreqMax <= 1023) {
//    setColor(50, 168, 164);
//        Serial.println("banana");
//  }
/////////////////////RED////////////////////////RED//////////////////////////////RED///////////////////
//else if(FreqMax >= 85 && FreqMax <= 90) {
//    setColor( 153, 51, 51);
//        Serial.println("fig");
//  }
//  else if(FreqMax <= 90 && FreqMax <= 120) {
//    setColor( 128, 0, 0);
//        Serial.println("elephant");
//  }
//  else if(FreqMax >= 120 && FreqMax <= 150) {
//    setColor( 204, 0, 0);
//        Serial.println("dog");
//  }
//  else if(FreqMax >= 150 && FreqMax <= 180) {
//    setColor( 255, 0, 0);
//        Serial.println("candy");
//  }
//  else if(FreqMax >= 180 && FreqMax <= 200) {
//    setColor(255, 51, 0);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 200 && FreqMax <= 230) {
//    setColor( 168, 164, 50);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 230 && FreqMax <= 260) {
//    setColor( 255, 153, 0);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 260 && FreqMax <= 290) {
//    setColor( 204, 153, 0);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 290 && FreqMax <= 320) {
//    setColor( 255, 204, 0);
//        Serial.println("banana");
//  }
//  else if(FreqMax >= 320 && FreqMax <= 350) {
//    setColor(255, 153, 51);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 350 && FreqMax <= 380) {
//    setColor( 255, 80, 80);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 380 && FreqMax <= 410) {
//    setColor( 102, 0, 51);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 410 && FreqMax <= 440) {
//    setColor( 204, 102, 153);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 440 && FreqMax <= 470) {
//    setColor( 255, 102, 102);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 470 && FreqMax <= 500) {
//    setColor( 255, 102, 153);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 500 && FreqMax <= 530) {
//    setColor( 255, 51, 153);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 530 && FreqMax <= 560) {
//    setColor( 204, 51, 153);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 560 && FreqMax <= 590) {
//    setColor( 153, 0, 153);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 590 && FreqMax <= 630) {
//    setColor( 153, 51, 153);
//        Serial.println("banana");
//  }
//  else if(FreqMax >= 630 && FreqMax <= 675) {
//    setColor( 255, 51, 204);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 675 && FreqMax <= 725) {
//    setColor( 255, 102, 204);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 725 && FreqMax <= 770) {
//    setColor( 255, 153, 204);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 770 && FreqMax <= 820) {
//    setColor( 102, 0, 102);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 820 && FreqMax <= 865) {
//    setColor( 204, 0, 204);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 865 && FreqMax <= 905) {
//    setColor( 255, 0, 255);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 905 && FreqMax <= 965) {
//    setColor( 255, 102, 255);
//        Serial.println("banana");
//  }
//   else if(FreqMax >= 965 && FreqMax <= 1024) {
//    setColor(255, 153, 255);
//        Serial.println("banana");
//  }
/////////////////BLUE////////////////////////////////BLUE///////////////////////////BLUE//////////////////////////////
else if(FreqMax >= 85 && FreqMax <= 90) {
    setColor( 0, 0, 102);
//        Serial.println("alpha");
  }
  else if(FreqMax <= 90 && FreqMax <= 120) {
    setColor( 0, 0, 204);
//        Serial.println("bravo");
  }
  else if(FreqMax >= 120 && FreqMax <= 150) {
    setColor( 0, 51, 153);
//        Serial.println("charlie");
  }
  else if(FreqMax >= 150 && FreqMax <= 180) {
    setColor( 51, 102, 204);
//        Serial.println("delta");
  }
  else if(FreqMax >= 180 && FreqMax <= 200) {
    setColor(51, 51, 153);
//        Serial.println("echo");
  }
   else if(FreqMax >= 200 && FreqMax <= 230) {
    setColor( 51, 51, 255);
//        Serial.println("foxtrot");
  }
   else if(FreqMax >= 230 && FreqMax <= 260) {
    setColor( 0, 0, 255);
//        Serial.println("golf");
  }
   else if(FreqMax >= 260 && FreqMax <= 290) {
    setColor( 0, 51, 204);
//        Serial.println("hotel");
  }
   else if(FreqMax >= 290 && FreqMax <= 320) {
    setColor( 0, 102, 204);
//        Serial.println("india");
  }
  else if(FreqMax >= 320 && FreqMax <= 350) {
    setColor(102, 102, 153);
//        Serial.println("jones");
  }
   else if(FreqMax >= 350 && FreqMax <= 380) {
    setColor( 51, 51, 204);
//        Serial.println("kilo");
  }
   else if(FreqMax >= 380 && FreqMax <= 410) {
    setColor( 51, 102, 255);
//        Serial.println("lima");
  }
   else if(FreqMax >= 410 && FreqMax <= 440) {
    setColor( 0, 102, 25553);
//        Serial.println("mono");
  }
   else if(FreqMax >= 440 && FreqMax <= 470) {
    setColor( 0, 153, 255);
//        Serial.println("nana");
  }
   else if(FreqMax >= 470 && FreqMax <= 500) {
    setColor( 0, 204, 255);
//        Serial.println("octopus");
  }
   else if(FreqMax >= 500 && FreqMax <= 530) {
    setColor( 102, 0, 204);
//        Serial.println("pokemon");
  }
   else if(FreqMax >= 530 && FreqMax <= 560) {
    setColor( 102, 0, 255);
//        Serial.println("quest");
  }
   else if(FreqMax >= 560 && FreqMax <= 590) {
    setColor( 102, 102, 255);
//        Serial.println("rat");
  }
   else if(FreqMax >= 590 && FreqMax <= 630) {
    setColor( 102, 153, 255);
//        Serial.println("stop");
  }
  else if(FreqMax >= 630 && FreqMax <= 675) {
    setColor( 51, 153, 255);
//        Serial.println("thompson");
  }
   else if(FreqMax >= 675 && FreqMax <= 725) {
    setColor( 51, 204, 255);
//        Serial.println("under");
  }
   else if(FreqMax >= 725 && FreqMax <= 770) {
    setColor( 153, 0, 255);
//        Serial.println("venmo");
  }
   else if(FreqMax >= 770 && FreqMax <= 820) {
    setColor( 153, 51, 255);
//        Serial.println("west");
  }
   else if(FreqMax >= 820 && FreqMax <= 865) {
    setColor( 153, 102, 255);
//        Serial.println("xylophone");
  }
   else if(FreqMax >= 865 && FreqMax <= 905) {
    setColor( 153, 153, 255);
//        Serial.println("yell");
  }
   else if(FreqMax >= 905 && FreqMax <= 965) {
    setColor( 153, 0, 204);
//        Serial.println("zebra");
  }
   else if(FreqMax >= 965 && FreqMax <= 1024) {
    setColor(204, 0, 255);
//        Serial.println("hundop");
  }    
}

void setColor(int r, int g, int b){
  c.r = r;
  c.g = g;
  c.b = b;
}
