void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {

  bool A = digitalRead(2);
  bool B = digitalRead(3);
  bool C = digitalRead(4);
  bool D = digitalRead(5);
  bool X = digitalRead(6);
  bool Y = digitalRead(7);
  bool Z = digitalRead(8);

  //SUMA
  if (!X && !Y && Z) {
    if ((A && B && D) || (A && B && C) || (C && D)) {
      digitalWrite (12, HIGH);//ACARREO
    } else {
      digitalWrite(12, LOW);//ACARREO
    }
    if ((A && B && !C && !D) || (A && B && C && D) || (!A && !C && D) || (!B && !C && D) || (!A && C && !D) || (!B && C && !D)) {

      digitalWrite(11, HIGH); // SEGUNDO BIT
    } else {
      digitalWrite (11, LOW); //SEGUNDO BIT
    }
    if ((!A && B) || (A && !B)) {

      digitalWrite(13, HIGH); //PRIMER BIT

    } else {
      digitalWrite(13, LOW); //PRIMER BIT
    }
  }

  //RESTA
  if (!X && Y && !Z) {
    if ((!C && D) || (!A && B)) {
      digitalWrite(12, HIGH); //SIGNO
    } else {
      digitalWrite(12, LOW); //SIGNO
    }
    if ((!C && D) || (C && !D)) {
      digitalWrite(11, HIGH); //SEGUNDO BIT
    } else {
      digitalWrite(11, LOW); //SEGUNDO BIT
    }
    if ((!A && B) || (A && !B)) {
      digitalWrite(13, HIGH); //PRIMER BIT
    } else {
      digitalWrite(13, LOW); //PRIMER BIT
    }
  }

  //MULTIPLICACION
  if (!X && Y && Z) {
    if (D && C && B && A) {
      digitalWrite(10, HIGH); //CUARTO BIT
    } else {
      digitalWrite(10, LOW);  //CUARTO BIT
    }

    if ((!A && C && D) || (!B && C && D)) {
      digitalWrite(11, HIGH); //TERCER BIT
    } else {
      digitalWrite(11, LOW); //TERCER BIT
    }
    if ((!A && B && C) || (B && C && !D) || (A && !B && D) || (A && !C && D)) {
      digitalWrite(12, HIGH); //SEGUNDO BIT
    } else {
      digitalWrite(12, LOW);//SEGUNDO BIT
    }
    if (A && B) {
      digitalWrite(13, HIGH); //PRIMER BIT
    } else {
      digitalWrite(13, LOW); //PRIMER BIT
    }
  }

  //DIVISION
  if (X && !Y && !Z) {
    if (!A && !B && !C && !D) {
      digitalWrite(9, HIGH); //ERROR
    } else {
      digitalWrite(9, LOW);    //ERROR
    }

    if ((!B && C && !D) || (A && !B && !D)) {
      digitalWrite(9, HIGH); //INFINITO
    } else {
      digitalWrite(9, LOW); //INFINITO
    }
    if (B && C && !D) {
      digitalWrite(10, HIGH); //SEGUNDO BIT
    } else {
      digitalWrite(10, LOW);//SEGUNDO BIT
    }
    if ((!B && C && D) || (A && B && !D) || (A && B && C)) {
      digitalWrite(11, HIGH); //PRIMER BIT
    } else {
      digitalWrite(11, LOW); //PRIMER BIT
    }
    if (!A && B && C && D) {
      digitalWrite(12, HIGH); //RESIDUO 2
    } else {
      digitalWrite(12, LOW); //RESIDUO 2
    }
    if ((A && !B && D) || (A && !C && D)) {
      digitalWrite(13, HIGH); //RESIDUO 1
    } else {
      digitalWrite(13, LOW); //RESIDUO 1
    }
  }
//AND
  if (X && !Y && Z) {
    if (A && B && C && D) {
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
  }

  //OR
  if (X && Y && !Z) {
    if (A || B || C || D) {
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
  }

  //XOR
  if (X && Y && Z) {
    if (A ^ B ^ C ^ D) {
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
  }
 
}
