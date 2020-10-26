#define ch_1 A5 //podlaczyc sonde nr 1
#define ch_2 A3 //podlaczyc sonde nr 2

//odstep ^ by zaklucenia ograniczyc, tak mi sie wydaje

#define pin_pauzy A0 //nie chcialo mi sie shielda zdejmowac; wyswietlacz + przyciski podlaczone pod A0

void setup() {

  pinMode(pin_pauzy, INPUT_PULLUP);
  pinMode(ch_1, INPUT);
  pinMode(ch_2, INPUT);
  Serial.begin(2000000);
}

//prędkości do wyboru 230400     2000000
//Im wieksza predkosc, tym czytelniejszy pomiar, ale bardziej miga i oczy bola :/

void loop() {


if(digitalRead(pin_pauzy) != 0){  //by dalo sie zatrzymac miganie i sie przyjrzec
int chanel_1 = analogRead(ch_1);
int chanel_2 = analogRead(ch_2);

Serial.print("Chanel_1:");
Serial.print(map(chanel_1,0,1023,0,5)); //map jest po to, by wartosci byly zblizone do napiecia w V; wartosci dobrane z zalozeniem zasilania badenego urzadzenia przez Arduino
Serial.print('\t'); //w necie cos pisali zeby odstep byl, bo cos bez tego nie bardzo dziala ze wzgledu ze dane z portu wysyla "ciurkiem"
Serial.print("Chanel_2:");
Serial.println(map(chanel_2,0,1023,0,5));


//skladnia funkcji map: map(variable1,0,1023,0,100))
}
}
