
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUM_LEDS 12

Adafruit_NeoPixel strip(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

String cmd = "";
int speedDelay = 40;

void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.show();
}

void setAll(int r,int g,int b){
  for(int i=0;i<NUM_LEDS;i++){
    strip.setPixelColor(i, strip.Color(r,g,b));
  }
  strip.show();
}

void rainbowCycle(){
  static int j=0;
  for(int i=0;i<NUM_LEDS;i++){
    int pos = (i*256/NUM_LEDS + j) & 255;
    strip.setPixelColor(i, Wheel(pos));
  }
  strip.show();
  j++;
  delay(speedDelay);
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  if(WheelPos < 170){
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void loop(){
  while(Serial.available()){
    char c = Serial.read();
    if(c=='\n'){
      process(cmd);
      cmd="";
    } else cmd+=c;
  }
}

void process(String c){
  if(c.startsWith("COLOR")){
    int r,g,b;
    sscanf(c.c_str(),"COLOR %d %d %d",&r,&g,&b);
    setAll(r,g,b);
  }

  if(c.startsWith("SPEED")){
    int s;
    sscanf(c.c_str(),"SPEED %d",&s);
    speedDelay = s;
  }

  if(c=="RAINBOW"){
    while(!Serial.available()){
      rainbowCycle();
    }
  }
}