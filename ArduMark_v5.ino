/*
  This is ArduMark v5 by @bockring. Don't copy this.
  But if you credit, you can edit and share your one.(Open source software)

  Credit like this
  "
  This program was edited and remixed by XXXX(Your name).
  Remix source:https://github.com/bockring/ArduMark.git
  "
  Again, YOU HAVE TO CRADIT if you edit and share this.

  Update features
  *Add decimal numbers to the progress outputs
  *Speeding up
  *Debug
  *Adjust score
  
  Status lamp(On-board LED ; Pin13)
   Lamp ON :Processing
   Lamp OFF:Not processing(For example, cooling down time)
   Blinking:Tests are done

  How to use
  1.select serial port
  2.open serial monitor
  3.compile and flash(Please connect to USB2.0 port or higher)
  4.wait for prosessings finish
  5.check the monitor, and score
  (6.If you want to test again, please send "Again" to your device)
  *This program is made for genuine Arduino hardwares.
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
int calcpros2; //Save number for rander graph
float progress; //Parcent

void setup() {
  Serial.begin(115200); //Start serial connection(9600bps)
}

void loop() {
  sinsum = 1;
  cossum = 1;
  tansum = 1; //Set sums to 0

  start = 0;
  Serial.println("Welcome to ArduMark v5 benchmark software by @bockring."); //Short introduction
  Serial.println("This is a Arduino benchmark. It will start in 3s."); //Short introduction
  Serial.println("Copyright @bockring 2024~"); //Copyright
  delay(2000); //Wait 2s to start benchmark
  Serial.println(" "); //Go next 
  Serial.println("↓Progress↓"); //These are starting

  //Sine calculation starting
  digitalWrite(13, HIGH); //Processing lamp for Arduino(If you use others, please set pin number)
  for (count = 0; count < 2048; count++) {  //Repeat 2048 times
    sinsum = sinsum * sin(count); //Calculate sine
    Serial.print("Progress : "); //Progress output 1
    calcpros = count + 1; //Prepare to calculate parcent
    progress = calcpros / 81.92; //Calculate parcent
    progress = round(progress * 1000);
    progress = progress / 1000;
    Serial.print (progress); //Progress output 2
    Serial.print("% Done ["); //Progress output3
    calcpros = progress / 5; //Calculate to output progress bar 1
    calcpros2 = 20 - calcpros; //Calculate to output progress bar 2
    for (calcpros = calcpros; calcpros != 0; calcpros--) { //Output progress bar 1(Done)
      Serial.print ("="); //Print
    }
    for (calcpros2 = calcpros2; calcpros2 != 0; calcpros2--) { //Output progress bar 2(Not done)
      Serial.print(" "); //Print
    }
    Serial.print("] (Process number : "); //Progress output 4
    Serial.print(count + 1); //Progress output 5
    Serial.println("/8192)"); //Progress output 6
  }
  digitalWrite(13, LOW);
  Serial.println("Sine calculations are done.(Progress : 25.00% Done [=====               ])"); //Output that sine calculation is done.
  
  delay(1000); //cool down
/*
  This is the alomost same as cosine and tangent calculations. 
  So I don't write comment for cosine and tangent calculations.
*/

  //Cosine calculation starting
  digitalWrite(13, HIGH);
  for (count = 0; count < 2048; count++) {
    cossum = cossum * cos(count);
    Serial.print("Progress : ");
    calcpros = count + 2049;
    progress = calcpros / 81.92;
    progress = round(progress * 1000);
    progress = progress / 1000;
    Serial.print (progress);
    Serial.print("% Done [");
    calcpros = progress / 5;
    calcpros2 = 20 - calcpros;
    for (calcpros = calcpros; calcpros != 0; calcpros--) {
      Serial.print ("=");
    }
    for (calcpros2 = calcpros2; calcpros2 != 0; calcpros2--) {
      Serial.print(" ");
    }
    Serial.print("] (Process number : ");
    Serial.print(count + 2049);
    Serial.println("/8192)");
  }
  digitalWrite(13, LOW);
  Serial.println("Cosine calculations are done.(Progress : 50.00% Done [==========          ])");
  
  delay(1000); //cool down

  //Tangent calculation starting
  digitalWrite(13, HIGH);
  for (count = 0; count < 2048; count++) {
    tansum = tansum * tan(count);
    Serial.print("Progress : ");
    calcpros = count + 4097;
    progress = calcpros / 81.92;
    progress = round(progress * 1000);
    progress = progress / 1000;
    Serial.print (progress);
    Serial.print("% Done [");
    calcpros = progress / 5;
    calcpros2 = 20 - calcpros;
    for (calcpros = calcpros; calcpros != 0; calcpros--) {
      Serial.print ("=");
    }
    for (calcpros2 = calcpros2; calcpros2 != 0; calcpros2--) {
      Serial.print(" ");
    }
    Serial.print("] (Process number : ");
    Serial.print(count + 4049);
    Serial.println("/8192)");
  }
  digitalWrite(13, LOW);
  Serial.println("Tangent calculations are done.(Progress : 75.00% Done [===============     ])");
  Serial.println("It will start integer calculations benchmark soon."); //Output featured progress
  delay(1000);

  //Integer calculation starting
  digitalWrite(13, HIGH);
  for (count = 0; count < 2048; count++) { //Repeat 2048 times
    random1 = random(0, 255); //Make random number 1
    random2 = random(128, 255); //Make random number 2
    Serial.print("Progress : "); //Print progress(After I comment "*1".)
    calcpros = count + 6145; //Calculate(After I comment "*2".)
    progress = calcpros / 81.92; //*2
    progress = round(progress * 1000);
    progress = progress / 1000;
    Serial.print(progress); //*1
    Serial.print("% Done ["); //*1
    calcpros = progress / 5; //*2
    calcpros2 = 20 - calcpros; //*2
    for (calcpros = calcpros; calcpros != 0; calcpros--) { //Progress bar(After I comment "*3".)
      Serial.print("="); //*3
    }
    for (calcpros2 = calcpros2; calcpros2 != 0; calcpros2--) { //*3
      Serial.print(" "); //*3
    }
    Serial.print("] (Process number : "); //*1
    Serial.print(count + 6145); //*1
    Serial.println("/8192)"); //*1
  }
  digitalWrite(13, LOW);
  Serial.println("Integer calculations are done.(Progress : 100.00% Done [====================])");

  //These are ending message↓
  Serial.println(" ");
  Serial.println("All specification mesurements are done.");
  benchtime = millis() - 5000;
  Serial.print("This is a time of wroking time : ");
  Serial.print(benchtime);
  Serial.println(" ms");
  score = 100000000 / benchtime;
  Serial.print("This is the your Arduino's score : ");
  Serial.println(score);
  Serial.println(" ");
  Serial.println("Thank you for using ArduMark v5 benchmark software by @bockring");
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