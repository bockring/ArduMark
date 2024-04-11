/*
  This is ArduMark V1.1 by @bockring. Don't copy this.
  But if you credit, you can edit and share your one.(Open source software)
   From this version, ArduMark softwares are LTS(Long-Time-Support edition).

  Credit like this
  "
  This program was edited and remixed by XXXX(Your name).
  Remix source:https://github.com/bockring/ArduMark.git
  "
  Again, YOU HAVE TO CRADIT if you edit and share this.

  Update features
  *Add some calculation features(Remainder of division/Abs)
  *Add the calculation times of square root

  Status lamp(On-board LED ; Pin13) *Sometimes it doesn't works well
   Lamp ON :Processing
   Lamp OFF:Not processing(For example, cooling down time)
   Blinking:Tests are done

  How to use
  1.select serial port
  2.open serial monitor
  3.compile and flash
  4.wait for prosessings finish
  5.check the monitor, and score
   This program is made for genuine Arduino hardwares.(Especialy for Arduino UNO R3)
   If you have compiling error, please fix by yourself or send e-mail to me.

  Copyright @bockring 2024~
  bockring.scratcher@gmail.com
*/

long count; //Prosessing progress
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

void setup() {
  Serial.begin(115200); //Start serial connection(115200bps)
}

void loop() {
  sinsum = 1;
  cossum = 1;
  tansum = 1; //Set sums to 0

  start = 0;
  Serial.println("Welcome to ArduMark V1.1 benchmark software by @bockring."); //Short introduction
  Serial.println("This is a Arduino benchmark. It will start in 3s."); //Short introduction
  Serial.println("Copyright @bockring 2024~"); //Copyright
  delay(2000); //Wait 2s to start benchmark
  Serial.println(" "); //Go next
  Serial.println("↓Progress↓"); //These are starting

  //Sine calculation starting
  digitalWrite(13, HIGH); //Processing lamp for Arduino(If you use others, please set pin number)
  for (count = 0; count < 32768; count++) {  //Repeat 32768 times
    sinsum = sinsum * sin(count); //Calculate sine
  }
  digitalWrite(13, LOW);
  Serial.println("Sine calculations are done."); //Output that sine calculation is done.

  /*
    This is the alomost same as cosine and tangent calculations.
    So I don't write comment for cosine and tangent calculations.
  */

  //Cosine calculation starting
  digitalWrite(13, HIGH);
  for (count = 0; count < 32768; count++) {
    cossum = cossum * cos(count);
  }
  digitalWrite(13, LOW);
  Serial.println("Cosine calculations are done.");

  delay(1000); //cool down

  //Tangent calculation starting
  digitalWrite(13, HIGH);
  for (count = 0; count < 32768; count++) {
    tansum = tansum * tan(count);
  }
  digitalWrite(13, LOW);
  Serial.println("Tangent calculations are done.");
  Serial.println("It will start integer calculations benchmark soon."); //Output featured progress
  delay(1000);

  //Integer calculation starting
  Serial.println("Start");
  digitalWrite(13, HIGH);
  for (count = 0; count < 32768; count++) { //Repeat 32768 times
    random1 = random(0, 255); //Make random number 1
    random2 = random(128, 255); //Make random number 2
    calcpros = random1 / random2;
  }
  digitalWrite(13, LOW);

  //Square root calculation starting
  digitalWrite(13, HIGH);
  for (count = 0; count < 32768; count ++) {
    random1 = random(-255, 255); //Generate random number
    random2 = random1 - 1;
    random1 = sqrt(random1);
    random2 = sqrt(random2);
    answer = answer + random1 / random2;
    answer = abs(0 - answer);
    answer = sqrt(answer);
  }
  digitalWrite(13, LOW);
  Serial.println("Some integer calculations are done.");

  //These are ending message↓
  Serial.println(" ");
  Serial.println("All specification mesurements are done.");
  benchtime = millis() - 2000;
  Serial.print("This is a time of wroking time : ");
  Serial.print(benchtime);
  Serial.println(" ms");
  score = 100000000 / benchtime;
  Serial.print("This is the your Arduino's score : ");
  Serial.println(score);
  Serial.println(" ");
  Serial.println("Thank you for using ArduMark V1.1 benchmark software by @bockring");
  Serial.println(" ");
  Serial.println("Copyright @bockring 2024~");
  Serial.println("You can use this in free, but DON'T COPY THIS SOFTWARE.");

  for (start = 0; start == 0; start = start + 0) {
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
  }
}