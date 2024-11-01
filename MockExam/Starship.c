// ในจักรวาล Star Trek แต่ละยานอวกาศจะมี รหัสทะเบียน 
// เฉพาะตัวที่ใช้ระบุคุณสมบัติของยาน โดย Starfleet 
// ใช้รหัสนี้เพื่อแสดงถึงคุณลักษณะของยานอวกาศ ซึ่งมีเงื่อนไขการจำแนกดังนี้:

// 1.รหัสทะเบียน เป็นจำนวนเต็มบวกเสมอ
// 2.หากรหัสทะเบียนมีค่า น้อยกว่า 1000
//      ถ้าตัวเลขสุดท้ายของรหัสเป็น 0  จะเป็นยานประเภท Command-class starship
//      ถ้าตัวเลขสุดท้ายของรหัสเป็น 5  จะเป็นยานประเภท Exploration-class starship
//      ถ้าไม่ตรงตามเงื่อนไขใด ๆ ข้างต้น จะถือว่าเป็นยานประเภท General-class starship
// 3.หากรหัสทะเบียนมีค่า 1000 หรือมากกว่า
//      ตัวเลขหลักแรกของรหัสใช้กำหนดสถานะของยานว่าอยู่ในสถานะ ปฏิบัติการ (Active) หรือ สำรอง (Reserve)
//          ถ้าหลักแรกเป็น เลขคู่ จะอยู่ในสถานะ ปฏิบัติการ (Active)
//          ถ้าหลักแรกเป็น เลขคี่ จะอยู่ในสถานะ สำรอง (Reserve)
//      ตัวเลขสองหลักสุดท้าย ของรหัสทะเบียนเป็น 50 หรือ 75 จะเป็นยานประเภท Starfleet Flagship
//      หากไม่ตรงตามเงื่อนไขใด ๆ ข้างต้น จะถือเป็นยานประเภท Standard-class starship
// ตัวอย่าง
// อินพุต: 950 → เอาท์พุต: Command-class starship
// อินพุต: 10075 → เอาท์พุต: Reserve Starfleet Flagship
// อินพุต: 2700 → เอาท์พุต: Active Standard-class starship

#include <stdio.h>

int main() {
    int id, last, first, second_last, temp;

    scanf("%d", &id);

    last = id % 10;
    second_last = id % 100;

    temp = id;
    while (temp >= 10) {
        temp /= 10;
    }
    first = temp;

    if (id < 1000) {
        if (last == 0) {
            printf("Command-class starship");
        } else if (last == 5) {
            printf("Exploration-class starship");
        } else {
            printf("General-class starship");
        }
    } else if (id >= 1000) {
        if (first % 2 == 0) {
            printf("Active ");
        } else if (first % 2 != 0) {
            printf("Reserve ");
        }

        if (second_last == 50 || second_last == 75) {
            printf("Starfleet Flagship");
        } else {
            printf("Standard-class starship");
        }
    }
}