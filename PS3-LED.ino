//Include PS3 Controller Host
#include <Ps3Controller.h>

//Define LED pins
#define led1 13
#define led2 12
#define led3 14
#define led4 33

int player = 0;
int battery = 0;

void notify() {
    //--- Digital cross/square/triangle/circle button events ---
    if( Ps3.event.button_down.cross )
        Serial.println("Started pressing the cross button");
    if( Ps3.event.button_up.cross )
        Serial.println("Released the cross button");

    if( Ps3.event.button_down.square )
        Serial.println("Started pressing the square button");
    if( Ps3.event.button_up.square )
        Serial.println("Released the square button");

    if( Ps3.event.button_down.triangle )
        Serial.println("Started pressing the triangle button");
    if( Ps3.event.button_up.triangle )
        Serial.println("Released the triangle button");

    if( Ps3.event.button_down.circle )
        Serial.println("Started pressing the circle button");
    if( Ps3.event.button_up.circle )
        Serial.println("Released the circle button");

    //--------------- Digital D-pad button events --------------
    if( Ps3.event.button_down.up )
        Serial.println("Started pressing the up button");
    if( Ps3.event.button_up.up )
        Serial.println("Released the up button");

    if( Ps3.event.button_down.right )
        Serial.println("Started pressing the right button");
    if( Ps3.event.button_up.right )
        Serial.println("Released the right button");

    if( Ps3.event.button_down.down )
        Serial.println("Started pressing the down button");
    if( Ps3.event.button_up.down )
        Serial.println("Released the down button");

    if( Ps3.event.button_down.left )
        Serial.println("Started pressing the left button");
    if( Ps3.event.button_up.left )
        Serial.println("Released the left button");

   //---------------------- Battery events ---------------------
    if( battery != Ps3.data.status.battery ){
        battery = Ps3.data.status.battery;
        Serial.print("The controller battery is ");
        if( battery == ps3_status_battery_charging )      Serial.println("charging");
        else if( battery == ps3_status_battery_full )     Serial.println("FULL");
        else if( battery == ps3_status_battery_high )     Serial.println("HIGH");
        else if( battery == ps3_status_battery_low)       Serial.println("LOW");
        else if( battery == ps3_status_battery_dying )    Serial.println("DYING");
        else if( battery == ps3_status_battery_shutdown ) Serial.println("SHUTDOWN");
        else Serial.println("UNDEFINED");
    }
}

// On Connection function
void onConnect(){
    // Print to Serial Monitor
    Serial.println("Connected.");
}

void setup()
{  
    // Set up serial monitor
    Serial.begin(115200);
    
    // Define callback function
    Ps3.attach(notify);

    // Define On connection function
    Ps3.attachOnConnect(onConnect);

    // MAC address
    Ps3.begin("11:11:11:11:11:11");

    // Print to serial monitor
    Serial.println("Ready.");

    // Set led pins as output
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
}

void loop()
{
    if(!Ps3.isConnected())
        return;

    //-------------------- Player LEDs -------------------
    Serial.print("Setting LEDs to player "); Serial.println(player, DEC);
    Ps3.setPlayer(player);

    player += 1;
    if(player > 10) player = 0;

    //--- Digital cross/square/triangle/circle button events ---

    // Cross
    if( Ps3.event.button_down.cross )
        Serial.println("Started pressing the cross button");
        digitalWrite(led1, HIGH);
    if( Ps3.event.button_up.cross )
        Serial.println("Released the cross button");
        digitalWrite(led1, LOW);

    // Square
    if( Ps3.event.button_down.square )
        Serial.println("Started pressing the square button");
        digitalWrite(led2, HIGH);
    if( Ps3.event.button_up.square )
        Serial.println("Released the square button");
        digitalWrite(led2, LOW);

    //Triangle
    if( Ps3.event.button_down.triangle )
        Serial.println("Started pressing the triangle button");
        digitalWrite(led3, HIGH);
    if( Ps3.event.button_up.triangle )
        Serial.println("Released the triangle button");
        digitalWrite(led3, LOW);

    //Circle
    if( Ps3.event.button_down.circle ) 
        Serial.println("Started pressing the circle button");
        digitalWrite(led4, HIGH); 
    if( Ps3.event.button_up.circle ) {
        Serial.println("Released the circle button");
        digitalWrite(led4, LOW); }

    //--------------- Digital D-pad button events --------------

    //D-pad up
    if( Ps3.event.button_down.up ) {
        Serial.println("Started pressing the up button");
        for( int i=0; i<10; i++){
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        delay(500);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(500);
        } 
    }
    //D-pad right
    if( Ps3.event.button_down.right ) {
        Serial.println("Started pressing the right button");
        for( int i=0; i<10; i++){
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(500);
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(500);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, LOW);
        delay(500);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, HIGH);
        delay(500);
        }
    }
    //D-pad down
    if( Ps3.event.button_down.down ) {
        Serial.println("Started pressing the down button");
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
    }
    //D-pad left
    if( Ps3.event.button_down.left ) {
        Serial.println("Started pressing the left button");
        for( int i=0; i<10; i++){
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, HIGH);
        delay(500);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, LOW);
        delay(500);
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(500);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(500);
        }
    }
    delay(2000);
}
