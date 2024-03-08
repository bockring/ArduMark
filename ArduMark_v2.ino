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

void setup() {
  Serial.begin(9600); //Start serial connection(9600bps)
}

void loop() {
  sinsum = 1;
  cossum = 1;
  tansum = 1; //Set sums to 0

  start = 0;
  Serial.println("Welcome to ArduMark v2 benchmark software by @bockring.");
  Serial.println("This is a Arduino benchmark. It will start in 5s.");
  Serial.println("Copyright @bockring 2024~");
  delay(3500);
  Serial.println(" ");
  Serial.println("↓Progress↓");//These are starting

  //Sine calculation starting
  for (count = 0; count < 2048; count++) {
    sinsum = sinsum * sin(count);
    Serial.print("Progress : ");
    calcpros = count + 1;
    Serial.print(calcpros);
    Serial.print("/");
    Serial.println(8192);
  }
  Serial.println("Sine calculations are done.(Progress : 1/4)");

  //Cosine calculation starting
  for (count = 0; count < 2048; count++) {
    cossum = cossum * cos(count);
    Serial.print("Progress : ");
    calcpros = count + 2049;
    Serial.print(calcpros);
    Serial.print("/");
    Serial.println(8192);
  }
  Serial.println("Cosine calculations are done.(Progress : 2/4)");

  //Tangent calculation starting
  for (count = 0; count < 2048; count++) {
    tansum = tansum * tan(count);
    Serial.print("Progress : ");
    calcpros = count + 4097;
    Serial.print(calcpros);
    Serial.print("/");
    Serial.println(8192);
  }
  Serial.println("Tangent calculations are done.(Progress : 3/4)");
  Serial.println("It will start integer calculations benchmark soon.");

  //Integer calculation starting
  for (count = 0; count < 2048; count ++) {
    random1 = random(0, 255);
    random2 = random(128, 255);
    Serial.print("Progress : ");
    calcpros = count + 6145;
    Serial.print(calcpros);
    Serial.print("/");
    Serial.println(8192);
  }
  Serial.println("Integer calculations are done.(Progress : 4/4)");

  //These are ending message↓
  Serial.println(" ");
  Serial.println("All specification mesurements are done.");
  benchtime = millis - 3500;
  Serial.print("This is a time of wroking time : ");
  Serial.print(benchtime);
  Serial.println(" ms");
  score = 1000000000000000 / benchtime;
  Serial.print("This is the your Arduino's score : ");
  Serial.println(score);
  Serial.println(" ");
  Serial.println("Thank you for using ArduMark v2 benchmark software by @bockring");
  Serial.println(" ");
  Serial.println("Copyright @bockring 2024~");
  Serial.println("You can use this in free, but DON'T COPY THIS SOFTWARE.");

  for (start = 0; start == 0; start = start + 0) {
    delay(3600000); //Stop to start second time
  }
}