#define THERMO_PIN                        A0
#define FILTER_THIS_MANY                 100
#define ANALOG_RESOLUTION                 12

unsigned long previousMillis = 0;
int samplesThisSec = 0;    // Used for calculating averaging array size
int samplesPerSec = 0;     // Used for displaying samplesPerSec updated every once second

void setup() {
  Serial.begin(115200);
  pinMode(THERMO_PIN, INPUT);
  analogReadResolution(ANALOG_RESOLUTION);
}

void loop() {
  // Calculate the sample rate:
  samplesThisSec++; //increment each time the loop cycles
  if(millis() - previousMillis >= 1000){ // Update value of samplesPerSec once every second:
    previousMillis=millis();
    samplesPerSec = samplesThisSec;
    samplesThisSec=0; 
  }
  
  //float tempC = ((3.3*analogRead(THERMO_PIN)/pow(2,ANALOG_RESOLUTION))-1.25)/0.005;   // Temperature formula, for use of the AD8595 amplifier before the amplifier was modified
  float tempC = 0.3264*analogRead(THERMO_PIN)-8.0083;                                   // Temperature formula, calibrated with a two point calibration
  //tempC = runningAverage(tempC, FILTER_THIS_MANY);                                    // uncomment to send the raw data through an averaging filter
  
  //Serial.print(samplesPerSec);    // uncomment to print samples per second
  //Serial.print("\t");
  Serial.print(micros());           // Print microseconds
  Serial.print("\t");
  Serial.println(tempC);            // Print temperature in degrees C
}


// Helper function to interpolate floating point values:
double mapf(double x, double in_min, double in_max, double out_min, double out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


// Optional averaging filter. Will not be used for a test requiring fast response:
bool f1 = true;
float data[FILTER_THIS_MANY] = {};
float previousData = 0;
float runningAverage(float newData, int samplesToAverage){
  float filteredData = 0;
  float sum = 0;
  if(f1){
    previousData = newData;
    f1 = false;  //only do this once...
    for(int i = 0; i < samplesToAverage; i++){
      data[i] = newData;   // initialize array
    }
    filteredData = newData;
  }
  else{ //do this the remaining times...
    for(int i = 1; i < samplesToAverage; i++){data[i-1] = data[i];} // Shift the data to make room for one more          
    data[samplesToAverage-1] = newData;        // Updated array full of data
    for(int i = 0; i < samplesToAverage; i++){
      sum += data[i];                  // Add all values
    }
    filteredData = (float)(sum / samplesToAverage);           // Divide by number of values
  }
  previousData = filteredData;
  return filteredData;
}
