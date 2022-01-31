/* Copyright (c) 2017 STMicroelectronics
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/****************************************************
*           RAPID PROTOTYPING WITH NUCLEO           *
* Example Code 06: Variable resistor                *
* Author: Mauro D'Angelo                            *
* Organization: Perlatecnica APS ETS                *
*****************************************************/

#include "mbed.h"

// It creates an instance of the AnalogIn class.
// analog_value is the name of the variable (instance).
// The instance shall 'point' to the pin A0
AnalogIn analog_value(A0);
UnbufferedSerial pc(USBTX,USBRX);
DigitalOut led(LED1);

int main() {
    float meas;
    
    while(1) {
    	// It reads the analog input value (value from 0.0 to 1.0)
        meas = analog_value.read();
        // Change the value to be in the 0 to 3300 range
        meas = meas * 3300;

        // It prints the measure
        printf("measure = %.2f mV\r\n", meas);


        // If the value is greater than 2V then switch the LED on
        if (meas > 2000) {
          led = 1;
        }
        else {
          led = 0;
        }

        ThisThread::sleep_for(200ms); // wait for 200 ms
    }
}
