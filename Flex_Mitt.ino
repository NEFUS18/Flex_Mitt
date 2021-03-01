#include <Keyboard.h>



int flexpin0 = A0;   
int flexpin1 = A1;
int flexpin2 = A2;
int flexpin3 = A3;
int one = 1, two = 1, three = 1, four = 1;


void setup() {
 Serial.begin(9600);
 delay(1000);
}

void loop() {
int flexVal0;
int flexVal1;
int flexVal2;
int flexVal3;


flexVal0 = analogRead(flexpin0);   //analogRead를 이용하여 flexpin에서 들어오는 값을 flexVal에 저장
flexVal1 = analogRead(flexpin1);
flexVal2 = analogRead(flexpin2);
flexVal3 = analogRead(flexpin3);


Serial.print("felx_0: ");   //확인을 위해 flexVal 값을 시리얼 모니터에 출력
Serial.println(flexVal0);

Serial.print("felx_1: ");
Serial.println(flexVal1);

Serial.print("felx_2: ");
Serial.println(flexVal2);

Serial.print("felx_3: ");
Serial.println(flexVal3);




//flex센서는 구부러질 수록 들어오는 값이 작아진다. (최대 1024)
if(flexVal0 <= 1010 && one == 1){    //손을 구부렸을때 들어오는 값이 1010 이하이고 , one의 값이 1이면
  one = 0;                           //one을 0으로 만들고
  Keyboard.press('a');               //키보드 a키를 입력한다
  delay(100);
}
else if(flexVal0 > 1010 && one == 0){   //만약 손가락이 구부려지지 않고 one이 0이 되면(손을 한 번 구부리고 다시 피면)
  one = 1;                              //one을 0으로 저장하고 키보드 a키를 뗀다
  Keyboard.release('a');
  }


if(flexVal1 <= 1010 && two == 1){
  two = 0;
  Keyboard.press('s');
  delay(100);
}
else if(flexVal0 > 1010 && two == 0){
  two = 1;
  Keyboard.release('s');
  }



if(flexVal2 <= 1010 && three == 1){
  three = 0;
  Keyboard.press('w');
  delay(100);
  }
else if(flexVal0 > 1010 && three == 0){
  three = 1;
  Keyboard.release('w');
  }

  
 
if(flexVal3 <= 1010 && four == 1){
  four = 0;
  Keyboard.press('d');
  delay(100);
  }
else if(flexVal0 > 101www0 && four == 0){
  four = 1;
  Keyboard.release('d');
  }

Serial.println();
delay(100);



/*while(Serial.available()){
  char data = Serial.read();
  Serial.print(data);
  }

 
 if(data <= 10 && data >= 0){
    Keyboard.press('s');
    }*/


  

}
