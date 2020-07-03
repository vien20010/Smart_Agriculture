int incomingByte = 0;   // dùng để lưu giá trị được gửi

void setup() {
        Serial.begin(9600);     // mở serial với baudrate 9600
}

void loop() {
        // nếu còn có thể đọc được 
        if (Serial.available() > 0) {
                // đọc chữ liệu
                incomingByte = Serial.read();

                // trả về những gì nhận được
                //Serial.print("Toi nhan duoc: ");
                if (incomingByte == -1) {
                  Serial.println("Toi khong nhan duoc gi ca");
                } else 
                  Serial.print(char(incomingByte));
        }
} 
