#include "esphome.h"
#include "Ultrasonic.h"


class GroveUltraSonic : public PollingComponent, public Sensor 
{
    Ultrasonic ultrasonic;
    
    public:

        GroveUltraSonic(uint32_t interval, uint8_t pin) : PollingComponent(interval), ultrasonic(pin) 
        { 

        }

        void setup() override 
        {
        }

        void update() override 
        {
            int distance = this->ultrasonic.MeasureInCentimeters();
            this->publish_state(distance);
        }
};