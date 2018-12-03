void setup() {
  Serial.begin(115200);
  Serial.println("Setup");
}

void loop() {
  Serial.println("Stage-1");
  float thirdroot = nthroot(27,3);
  Serial.print("3rd Root of 27, Answer = "); Serial.println(thirdroot,6);
  Serial.println("Stage-2");
  float squareroot = nthroot(2,2);
  Serial.print("2nd Root of 2,  Answer = "); Serial.println(squareroot,6);
  delay(1000);
  Serial.println("Finished main");
}

float nthroot(float number, int N){
  Serial.println(__LINE__);
  if (number < 0) {Serial.println("Cannot solve for negative numbers"); return 0; }
  float guess = number;
  float new_guess = 0;
  float error = 0.00001;
  bool NotFoundResult = true;
  while (NotFoundResult){                                       // New guess = (number / guess^(N-1) + guess*(N-1) ) / N
    new_guess = (number/pow(guess,N-1) + guess*(N-1))/N;        // Solve nth root using Newton Raphson method
    if(abs(new_guess - guess) <= error) NotFoundResult = false; // Keep going until difference between new and old guess is small.
    guess = new_guess;                                          // Make the guess the new value and repeat
  }
  return guess;
}
