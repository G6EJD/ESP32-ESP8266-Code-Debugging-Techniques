void setup() {
  Serial.begin(115200);
  Serial.println(ARDUINO);
  Serial.println(__FILE__);
  Serial.println(__DATE__);
  Serial.println(__TIME__);
  Serial.println(__LINE__);
}

void loop() {
  Serial.println(__LINE__);
  float thirdroot = nthroot(27,3);
  Serial.print("3rd Root of 27, Answer = "); Serial.println(thirdroot,6);
  Serial.println(__LINE__);
  float squareroot = nthroot(2,2);
  Serial.print("2nd Root of 2,  Answer = "); Serial.println(squareroot,6);
  Serial.println();
  Serial.println();
  delay(100000);
}

float nthroot(float number, int N){
  Serial.println(__FUNCTION__);
  Serial.println(__LINE__);
  Serial.println(__COUNTER__);
  if (number < 0) {Serial.println("Cannot solve for negative numbers"); return 0; }
  float guess = number;
  float new_guess = 0;
  float error = 0.00001;
  bool NotFoundResult = true;
  while (NotFoundResult){                                       // New guess = (number / guess^(N-1) + guess*(N-1) ) / N
    new_guess = (number/pow(guess,N-1) + guess*(N-1))/N;        // Solve using Newton Raphson method
    if(abs(new_guess - guess) <= error) NotFoundResult = false; // Keep going until difference between new and old guess is small.
    guess = new_guess;
  }
  Serial.println(__COUNTER__);
  Serial.println(__COUNTER__);
  Serial.println();
  return guess;
}
/*
 * 
#define true  0x1
#define false 0x0

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105

#define SERIAL  0x0
#define DISPLAY 0x1

#define LSBFIRST 0
#define MSBFIRST 1

#define CHANGE 1
#define FALLING 2
#define RISING 3

 */
