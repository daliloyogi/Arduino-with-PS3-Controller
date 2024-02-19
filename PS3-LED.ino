#include <Ps3Controller.h>

//Define LED pins
#define led1 13
#define led2 12
#define led3 14
#define led4 33


int player = 0;

void notify()
{
    // Cross
    if( Ps3.event.button_down.cross ) digitalWrite(led1, HIGH);
    else if( Ps3.event.button_up.cross ) digitalWrite(led1, LOW);

    // Square
    if( Ps3.event.button_down.square )digitalWrite(led2, HIGH);
    else if( Ps3.event.button_up.square ) digitalWrite(led2, LOW);

    //Triangle
    if( Ps3.event.button_down.triangle )digitalWrite(led3, HIGH);
    else if( Ps3.event.button_up.triangle ) digitalWrite(led3, LOW);

    //Circle
    if( Ps3.event.button_down.circle )digitalWrite(led4, HIGH);
    else if( Ps3.event.button_up.circle ) digitalWrite(led4, LOW);

    //--------------- Digital D-pad button events --------------

    //D-pad up
    if( Ps3.event.button_down.up ){
        for( int i=0; i<5; i++){
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        delay(25);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(25);
        } 
    }
    else if( Ps3.event.button_up.up ){
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
    }
    
    //D-pad right
    if( Ps3.event.button_down.right ) {
        for( int i=0; i<5; i++){
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(25);
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(25);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, LOW);
        delay(25);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, HIGH);
        delay(25);
        }
    }
    else if( Ps3.event.button_up.right ){
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
    }

    //D-pad left
    if( Ps3.event.button_down.left ) {
        Serial.println("Started pressing the left button");
        for( int i=0; i<5; i++){
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, HIGH);
        delay(25);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, LOW);
        delay(25);
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(25);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(25);
        }
    }
    else if( Ps3.event.button_up.left ){
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
    }
}

void onConnect(){
    Serial.println("Connected.");
}

void setup()
{
    Serial.begin(115200);

    Ps3.attach(notify);
    Ps3.attachOnConnect(onConnect);
    Ps3.begin("01:02:03:04:05:06");

    Serial.println("Ready.");

    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
}

void loop()
{
}
