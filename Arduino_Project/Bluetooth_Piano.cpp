#include <SoftwareSerial.h> // 시리얼 통신을 위한 라이브러리

int TX = 12;   // 블루투스 신호를 보내는 핀
int RX = 13;   // 블루투스 신호를 받는 핀
int PIANO = 10; //스피커가 연결된 디지털핀 설정
SoftwareSerial mySerial(TX, RX);
String WhatNum = ""; // 소리를 와 빛을 내기 위해 받는 문자열

void setup() {
    mySerial.begin(9600); // 블루투스 시리얼 통신
    Serial.begin(9600); // 시리얼 통신
}

void loop() {
    while (mySerial.available())  // mySerial 값이 있으면
    {
        char myChar = (char)mySerial.read();  // int형식인 mySerial의 값을 char형식으로 변환
        WhatNum += myChar;   // 1바이트씩 전송되어 수신되는 모든 문자열을 WhatNum에 붙임
        delay(5);           // 수신되는 문자열의 끊김을 방지
        pinMode(0, OUTPUT); // 핀모드 설정
        pinMode(1, OUTPUT); // 핀모드 설정
        pinMode(2, OUTPUT); // 핀모드 설정
        pinMode(3, OUTPUT); // 핀모드 설정
        pinMode(4, OUTPUT); // 핀모드 설정
        pinMode(5, OUTPUT); // 핀모드 설정
        pinMode(6, OUTPUT); // 핀모드 설정
        pinMode(7, OUTPUT); // 핀모드 설정
        pinMode(8, OUTPUT); // 핀모드 설정
        pinMode(9, OUTPUT); // 핀모드 설정
        pinMode(10, OUTPUT); // 핀모드 설정
    }

    if (!WhatNum.equals(""))  // WhatNum 값이 있다면
    {
        Serial.println("input value: " + WhatNum); // 시리얼모니터에 WhatNum값 출력

        if (WhatNum == "1")  // WhatNum 값이 '1' 이라면
        {
            tone(10, 523); // 피에조부저에 '도'음 내기
            digitalWrite(9, HIGH); // 9번 LED 불 켜기
            delay(200); // 0.2초
            noTone(10); // 피에조부저에 '도'음 내는것 중지
            digitalWrite(9, LOW); // 9번 LED 불 끄기
        }
        if (WhatNum == "2")  // WhatNum 값이 '2' 이라면
        {
            tone(10, 587); // 피에조부저에 '레'음 내기
            digitalWrite(8, HIGH); // 8번 LED 불 켜기
            delay(200); // 0.2초
            noTone(10); // 피에조부저에 '레'음 내는것 중지
            digitalWrite(8, LOW); // 8번 LED 불 끄기
        }
        if (WhatNum == "3")  // WhatNum 값이 '3' 이라면
        {
            tone(10, 659); // 피에조부저에 '미'음 내기
            digitalWrite(7, HIGH); // 7번 LED 불 켜기
            delay(200); // 0.2초
            noTone(10); // 피에조부저에 '미'음 내는것 중지
            digitalWrite(7, LOW); // 7번 LED 불 끄기
        }
        if (WhatNum == "4")  // WhatNum 값이 '4' 이라면
        {
            tone(10, 698); // 피에조부저에 '파'음 내기
            digitalWrite(6, HIGH); // 6번 LED 불 켜기
            delay(200); // 0.2초
            noTone(10); // 피에조부저에 '파'음 내는것 중지
            digitalWrite(6, LOW); // 6번 LED 불 끄기
        }
        if (WhatNum == "5")  // WhatNum 값이 '5' 이라면
        {
            tone(10, 784); // 피에조부저에 '솔'음 내기
            digitalWrite(5, HIGH); // 5번 LED 불 켜기
            delay(200); // 0.2초
            noTone(10); // 피에조부저에 '솔'음 내는것 중지
            digitalWrite(5, LOW); // 5번 LED 불 끄기
        }
        if (WhatNum == "6")  // WhatNum 값이 '6' 이라면
        {
            tone(10, 880); // 피에조부저에 '라'음 내기
            digitalWrite(4, HIGH); // 4번 LED 불 켜기
            delay(200); // 0.2초
            noTone(10); // 피에조부저에 '라'음 내는것 중지
            digitalWrite(4, LOW); // 4번 LED 불 끄기
        }
        if (WhatNum == "7")  // WhatNum 값이 '7' 이라면
        {
            tone(10, 988); // 피에조부저에 '시'음 내기
            digitalWrite(3, HIGH); // 3번 LED 불 켜기
            delay(200); // 0.2초
            noTone(10); // 피에조부저에 '시'음 내는것 중지
            digitalWrite(3, LOW); // 3번 LED 불 끄기
        }
        if (WhatNum == "8")  // WhatNum 값이 '8' 이라면
        {
            int sing[] = { 659, 587, 523, 587, 659, 659, 659, 587, 587, 587, 659, 659, 659, 659, 587, 523, 587, 659, 659, 659, 587, 587, 659, 587, 523 }; // 노래가 되도록 미리 음을 배열로 설정
            for (int i = 0; i < 25; i++) {
                digitalWrite(2, HIGH); // 2번 LED 불 켜기
                tone(10, sing[i]); // 피에조부저에 미리 입력해둔 음에 맞게 노래소리 내기
                delay(500); // 0.5초
                noTone(10); // 피에조부저에 소리 내는것 중지
            }
            noTone(10); // 피에조부저에 소리 내는것 중지
            digitalWrite(2, LOW); // 2번 LED 불 끄기
        }
        else {
            // WhatNum 값이 다른 1~8이 아닌 다른 값이라면 아무 동작을 하지 않음
        }
        WhatNum = "";  // 다음 입력을 위해 WhatNum 변수값 초기화
    }
}