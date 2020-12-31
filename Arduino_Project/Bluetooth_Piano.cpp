#include <SoftwareSerial.h> // �ø��� ����� ���� ���̺귯��

int TX = 12;   // ������� ��ȣ�� ������ ��
int RX = 13;   // ������� ��ȣ�� �޴� ��
int PIANO = 10; //����Ŀ�� ����� �������� ����
SoftwareSerial mySerial(TX, RX);
String WhatNum = ""; // �Ҹ��� �� ���� ���� ���� �޴� ���ڿ�

void setup() {
    mySerial.begin(9600); // ������� �ø��� ���
    Serial.begin(9600); // �ø��� ���
}

void loop() {
    while (mySerial.available())  // mySerial ���� ������
    {
        char myChar = (char)mySerial.read();  // int������ mySerial�� ���� char�������� ��ȯ
        WhatNum += myChar;   // 1����Ʈ�� ���۵Ǿ� ���ŵǴ� ��� ���ڿ��� WhatNum�� ����
        delay(5);           // ���ŵǴ� ���ڿ��� ������ ����
        pinMode(0, OUTPUT); // �ɸ�� ����
        pinMode(1, OUTPUT); // �ɸ�� ����
        pinMode(2, OUTPUT); // �ɸ�� ����
        pinMode(3, OUTPUT); // �ɸ�� ����
        pinMode(4, OUTPUT); // �ɸ�� ����
        pinMode(5, OUTPUT); // �ɸ�� ����
        pinMode(6, OUTPUT); // �ɸ�� ����
        pinMode(7, OUTPUT); // �ɸ�� ����
        pinMode(8, OUTPUT); // �ɸ�� ����
        pinMode(9, OUTPUT); // �ɸ�� ����
        pinMode(10, OUTPUT); // �ɸ�� ����
    }

    if (!WhatNum.equals(""))  // WhatNum ���� �ִٸ�
    {
        Serial.println("input value: " + WhatNum); // �ø������Ϳ� WhatNum�� ���

        if (WhatNum == "1")  // WhatNum ���� '1' �̶��
        {
            tone(10, 523); // �ǿ��������� '��'�� ����
            digitalWrite(9, HIGH); // 9�� LED �� �ѱ�
            delay(200); // 0.2��
            noTone(10); // �ǿ��������� '��'�� ���°� ����
            digitalWrite(9, LOW); // 9�� LED �� ����
        }
        if (WhatNum == "2")  // WhatNum ���� '2' �̶��
        {
            tone(10, 587); // �ǿ��������� '��'�� ����
            digitalWrite(8, HIGH); // 8�� LED �� �ѱ�
            delay(200); // 0.2��
            noTone(10); // �ǿ��������� '��'�� ���°� ����
            digitalWrite(8, LOW); // 8�� LED �� ����
        }
        if (WhatNum == "3")  // WhatNum ���� '3' �̶��
        {
            tone(10, 659); // �ǿ��������� '��'�� ����
            digitalWrite(7, HIGH); // 7�� LED �� �ѱ�
            delay(200); // 0.2��
            noTone(10); // �ǿ��������� '��'�� ���°� ����
            digitalWrite(7, LOW); // 7�� LED �� ����
        }
        if (WhatNum == "4")  // WhatNum ���� '4' �̶��
        {
            tone(10, 698); // �ǿ��������� '��'�� ����
            digitalWrite(6, HIGH); // 6�� LED �� �ѱ�
            delay(200); // 0.2��
            noTone(10); // �ǿ��������� '��'�� ���°� ����
            digitalWrite(6, LOW); // 6�� LED �� ����
        }
        if (WhatNum == "5")  // WhatNum ���� '5' �̶��
        {
            tone(10, 784); // �ǿ��������� '��'�� ����
            digitalWrite(5, HIGH); // 5�� LED �� �ѱ�
            delay(200); // 0.2��
            noTone(10); // �ǿ��������� '��'�� ���°� ����
            digitalWrite(5, LOW); // 5�� LED �� ����
        }
        if (WhatNum == "6")  // WhatNum ���� '6' �̶��
        {
            tone(10, 880); // �ǿ��������� '��'�� ����
            digitalWrite(4, HIGH); // 4�� LED �� �ѱ�
            delay(200); // 0.2��
            noTone(10); // �ǿ��������� '��'�� ���°� ����
            digitalWrite(4, LOW); // 4�� LED �� ����
        }
        if (WhatNum == "7")  // WhatNum ���� '7' �̶��
        {
            tone(10, 988); // �ǿ��������� '��'�� ����
            digitalWrite(3, HIGH); // 3�� LED �� �ѱ�
            delay(200); // 0.2��
            noTone(10); // �ǿ��������� '��'�� ���°� ����
            digitalWrite(3, LOW); // 3�� LED �� ����
        }
        if (WhatNum == "8")  // WhatNum ���� '8' �̶��
        {
            int sing[] = { 659, 587, 523, 587, 659, 659, 659, 587, 587, 587, 659, 659, 659, 659, 587, 523, 587, 659, 659, 659, 587, 587, 659, 587, 523 }; // �뷡�� �ǵ��� �̸� ���� �迭�� ����
            for (int i = 0; i < 25; i++) {
                digitalWrite(2, HIGH); // 2�� LED �� �ѱ�
                tone(10, sing[i]); // �ǿ��������� �̸� �Է��ص� ���� �°� �뷡�Ҹ� ����
                delay(500); // 0.5��
                noTone(10); // �ǿ��������� �Ҹ� ���°� ����
            }
            noTone(10); // �ǿ��������� �Ҹ� ���°� ����
            digitalWrite(2, LOW); // 2�� LED �� ����
        }
        else {
            // WhatNum ���� �ٸ� 1~8�� �ƴ� �ٸ� ���̶�� �ƹ� ������ ���� ����
        }
        WhatNum = "";  // ���� �Է��� ���� WhatNum ������ �ʱ�ȭ
    }
}