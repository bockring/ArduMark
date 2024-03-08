/*
  This is ArduMark v3 by @bockring. Don't copy this.

  Update features
  *Add progress bar
  *Add Simple user manual(like this)
  #Change "done prosesses/all prosesses" to percentage(progress)
  *Adjust score

  How to use
  1.select serial port
  2.open serial monitor
  3.compile and flash
  4.wait for prosessings finish
  5.check the monitor, and score

  Copyright @bockring 2024~
  bockring.scratcher@gmail.com
*/

unsigned count; //Prosessing progress
float sinsum; //Sine calculations
float cossum; //Cosine calculations
float tansum; //Tangent calculations
boolean start; //Excution for one time only(in one time boot)
int random1; //Save random number
int random2; //Save random number
float answer; //Integer calculation
unsigned long benchtime; //Benchmark prosessing time(ms)
unsigned long score; //Score
unsigned long calcpros; //Save one time calculation
int calcpros2; //Save number for rander graph

void setup() {
  Serial.begin(9600); //Start serial connection(9600bps)
}

void loop() {
  sinsum = 1;
  cossum = 1;
  tansum = 1; //Set sums to 0

  start = 0;
  Serial.println("Welcome to ArduMark v3 benchmark software by @bockring.");
  Serial.println("This is a Arduino benchmark. It will start in 5s.");
  Serial.println("Copyright @bockring 2024~");
  delay(4000);
  Serial.println(" ");
  Serial.println("↓Progress↓"); //These are starting

  //Sine calculation starting
  for (count = 0; count < 2048; count++) {
    sinsum = sinsum * sin(count);
    Serial.print("Progress : ");
    calcpros = count + 1;
    calcpros = calcpros / 81.92;
    Serial.print (calcpros);
    Serial.print("% Done [");
    calcpros = calcpros / 5;
    calcpros2 = 20 - calcpros;
    for (calcpros = calcpros; calcpros != 0; calcpros--) {
      Serial.print ("=");
    }
    for (calcpros2 = calcpros2; calcpros2 != 0; calcpros2--) {
      Serial.print(" ");
    }
    Serial.println("]");
  }
  Serial.println("Sine calculations are done.(Progress : 25% Done [=====               ])");

  //Cosine calculation starting
  for (count = 0; count < 2048; count++) {
    cossum = cossum * cos(count);
    Serial.print("Progress : ");
    calcpros = count + 2049;
    calcpros = calcpros / 81.92;
    Serial.print (calcpros);
    Serial.print("% Done [");
    calcpros = calcpros / 5;
    calcpros2 = 20 - calcpros;
    for (calcpros = calcpros; calcpros != 0; calcpros--) {
      Serial.print ("=");
    }
    for (calcpros2 = calcpros2; calcpros2 != 0; calcpros2--) {
      Serial.print(" ");
    }
    Serial.println("]");
  }
  Serial.println("Cosine calculations are done.(Progress : 50% Done [==========          ])");

  //Tangent calculation starting
  for (count = 0; count < 2048; count++) {
    tansum = tansum * tan(count);
    Serial.print("Progress : ");
    calcpros = count + 4097;
    calcpros = calcpros / 81.92;
    Serial.print (calcpros);
    Serial.print("% Done [");
    calcpros = calcpros / 5;
    calcpros2 = 20 - calcpros;
    for (calcpros = calcpros; calcpros != 0; calcpros--) {
      Serial.print ("=");
    }
    for (calcpros2 = calcpros2; calcpros2 != 0; calcpros2--) {
      Serial.print(" ");
    }
    Serial.println("]");
  }
  Serial.println("Tangent calculations are done.(Progress : 75% Done [===============     ])");
  Serial.println("It will start integer calculations benchmark soon.");
  delay(1000);

  //Integer calculation starting
  for (count = 0; count < 2048; count++) {
    random1 = random(0, 255);
    random2 = random(128, 255);
    Serial.print("Progress : ");
    calcpros = count + 6145;
    calcpros = calcpros / 81.92;
    Serial.print(calcpros);
    Serial.print("% Done [");
    calcpros = calcpros / 5;
    calcpros2 = 20 - calcpros;
    for (calcpros = calcpros; calcpros != 0; calcpros--) {
      Serial.print("=");
    }
    for (calcpros2 = calcpros2; calcpros2 != 0; calcpros2--) {
      Serial.print(" ");
    }
    Serial.println("]");
  }
  Serial.println("Integer calculations are done.(Progress : 100% Done [====================])");

  //These are ending message↓
  Serial.println(" ");
  Serial.println("All specification mesurements are done.");
  benchtime = millis - 5000;
  Serial.print("This is a time of wroking time : ");
  Serial.print(benchtime);
  Serial.println(" ms");
  score = 100000000000000 / benchtime;
  Serial.print("This is the your Arduino's score : ");
  Serial.println(score);
  Serial.println(" ");
  Serial.println("Thank you for using ArduMark v3 benchmark software by @bockring");
  Serial.println(" ");
  Serial.println("Copyright @bockring 2024~");
  Serial.println("You can use this in free, but DON'T COPY THIS SOFTWARE.");

  for (start = 0; start == 0; start = start + 0) {
    delay(3600000); //Stop to start second time
  }
}