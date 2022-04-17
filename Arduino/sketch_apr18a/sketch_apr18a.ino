#define BLINKER_PRINT Serial
#define BLINKER_MIOT_LIGHT
#define BLINKER_WIFI


#include <Blinker.h>
#include <Blinker.h>
#include <Adafruit_NeoPixel.h>
int r0,g0,b0,l0=200;
// key，在点灯 App 中获取
char auth[] = "5883b3dd31d4";
char ssid[] = "XLP";
char pswd[] = "19791014++";
//  DIN PIN (GPIO15, D8)
#define PIN 15
// 灯带 LED 数量
#define NUMPIXELS 6  
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// 新建组件对象
BlinkerRGB RGB1("RGB");

// RGB和亮度
int LED_R=0,LED_G=0,LED_B=0,LED_Bright=180;
bool WIFI_Status = true;


void SET_RGB(int R,int G,int B,int bright)
{
    // 把灯条变色
    for (uint16_t i = 0; i < NUMPIXELS; i++)
    {
        pixels.setPixelColor(i,R,G,B);
    }
    // 设置亮度
    pixels.setBrightness(bright);
    // 送出显示
    pixels.show();
}

void miotPowerState(const String & state)
{
    BLINKER_LOG("need set power state: ", state);

    if (state == BLINKER_CMD_ON) {
        digitalWrite(LED_BUILTIN, HIGH);
        SET_RGB(255,255,255,200);
        r0 = 255;
        g0 = 255;
        b0 = 255;
        BlinkerMIOT.powerState("on");
        BlinkerMIOT.print();
    }
    else if (state == BLINKER_CMD_OFF) {
        digitalWrite(LED_BUILTIN, LOW);
        SET_RGB(0,0,0,200);
        r0 = 0;
        g0 = 0;
        b0 = 0;
        BlinkerMIOT.powerState("off");
        BlinkerMIOT.print();
    }
}

void miotColor(int32_t color)
{
    BLINKER_LOG("need set color: ", color);
    int colorR,colorG,colorB;
    r0=colorR = color >> 16 & 0xFF;
    g0=colorG = color >>  8 & 0xFF;
    b0=colorB = color       & 0xFF;

    BLINKER_LOG("colorR: ", colorR, ", colorG: ", colorG, ", colorB: ", colorB);
    SET_RGB(r0,g0,b0,l0);
    //pixels.Show();

    BlinkerMIOT.color(color);
    BlinkerMIOT.print();
}

void miotBright(const String & bright)
{
    BLINKER_LOG("need set brightness: ", bright);

    int colorW = bright.toInt();
    l0 = (int)((250.0/100)*colorW);
    SET_RGB(r0,g0,b0,l0);
    BLINKER_LOG("now set brightness: ", colorW);
    
    BlinkerMIOT.brightness(colorW);
    BlinkerMIOT.print();
}
//APP RGB颜色设置回调
void rgb1_callback(uint8_t r_value, uint8_t g_value, 
                    uint8_t b_value, uint8_t bright_value)
{
    
    //digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    BLINKER_LOG("R value: ", r_value);
    BLINKER_LOG("G value: ", g_value);
    BLINKER_LOG("B value: ", b_value);
    BLINKER_LOG("Rrightness value: ", bright_value);
    LED_Bright = bright_value;
    r0 = r_value;
    g0 = g_value;
    b0 = b_value;
    SET_RGB(r_value,g_value,b_value,LED_Bright);
}

void setup() {
    // 初始化串口
    Serial.begin(115200);
    // WS2812初始化
    pixels.begin();
    pixels.show();
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(A0,INPUT);
    #if defined(BLINKER_PRINT)
        BLINKER_DEBUG.stream(BLINKER_PRINT);
    #endif

    //WIFI_Set();
    // 初始化blinker
    Blinker.begin(auth, WiFi.SSID().c_str(), WiFi.psk().c_str());
    // 注册调节颜色的回调函数
    RGB1.attach(rgb1_callback);
    BlinkerMIOT.attachColor(miotColor);
    BlinkerMIOT.attachBrightness(miotBright);
    BlinkerMIOT.attachPowerState(miotPowerState);
}
/*
void AutoLight()
{
    int a = analogRead(A0);
    Serial.println(a);
    SET_RGB(r0,g0,b0,a/8);
      
}*/
void loop() {
    Blinker.run();
    //AutoLight();
}
