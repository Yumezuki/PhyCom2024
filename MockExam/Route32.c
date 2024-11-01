// ทางหลวงแผ่นดินหมายเลข 32 สายบางปะอิน–แยกหลวงพ่อโอเป็นทางหลวงแผ่นดินสายรองประธานที่แยกออกมาจากทางหลวงหมายเลข 1 (ถนนพหลโยธิน) 
// ที่ทางแยกต่างระดับบางปะอิน จังหวัดพระนครศรีอยุธยาและบรรจบกับทางหลวงหมายเลข 1 อีกครั้งที่แยกหลวงพ่อโอ จังหวัดนครสวรรค์ มีระยะทางตลอดทั้งสายรวม 150.545 กิโลเมตร
//  เป็นเส้นทางหลักที่เชื่อมต่อระหว่างกรุงเทพมหานครสู่จังหวัดในภาคเหนือของประเทศไทย โดยที่ถนนสายนี้วิ่งผ่านทั้งหมด 6 จังหวัดได้แก่ 
// อยุธยา (Ayutthaya), อ่างทอง (Ang Thong), สิงห์บุรี (Sing Buri), ลพบุรี (Lop Buri), ชัยนาท (Chai Nat) และ นครสวรรค์ (Nakhon Sawan) 
// โดยที่ตารางด้านล่างจะแสดงช่วงของหลักกิโลเมตรของทางหลวงแผ่นดินหมายเลข 32 ที่ผ่านในแต่ละเขตจังหวัด
 
// เขตจังหวัด	หลักกิโลเมตรเริ่มต้นตั้งแต่ (กม.)	หลักกิโลเมตรสิ้นสุด (กม.)
// อยุธยา	จุดที่แยกออกมาจากถนนพหลโยธิน	48.697
// อ่างทอง	48.697	66.456
// สิงห์บุรี	66.456	84.918
// ลพบุรี	84.918	85.900
// สิงห์บุรี	85.900	111.936
// ชัยนาท	111.936	150.019
// นครสวรรค์	150.019	จุดที่บรรจบกับถนนพหลโยธิน

// คุณละอองดาวต้องการที่จะซื้อบ้านหลังใหม่ในโครงการหมู่บ้านที่สร้างบริเวณถนนเส้นนี้ แต่ว่าโครงการหมู่บ้านที่สร้างใกล้ๆ กับถนนหมายเลข 32 
// จะชอบตั้งชื่อโครงการว่า “ถนนสายเอเชีย” เสมอ โชคดีที่เกาะกลางของถนนจะมีหลักกิโลเมตรติดเอาไว้ คุณละอองดาวจึงอยากได้โปรแกรมที่รับค่าเป็นหลักกิโลเมตรของถนนหมายเลข 32 
// เพื่อที่จะบอกว่าหลักกิโลเมตรนี้อยู่ในเขตจังหวัดอะไรเพื่อให้คุณละอองดาวตัดสินใจซื้อบ้านหลังใหม่ได้ถูก เช่นหมู่บ้านฉงนวิลล่า-สายเอเชียตั้งอยู่ที่หลักกิโลเมตรที่ 76 
// แปลว่าหมู่บ้านโครงการนี้ตั้งอยู่ในเขตจังหวัดสิงห์บุรี ถ้าหากว่าโปรแกรมรับค่าที่ไม่ถูกต้องเข้ามาให้แสดงผลลัพธ์ว่า “InValid” มั่นใจได้เลยว่าจะไม่มีหมู่บ้านไหนที่ตั้งอยู่ระหว่าง 2 จังหวัดแน่นอน

#include <stdio.h>

void getProvince(double kilometer) {
    if (kilometer < 0 || kilometer > 150.545) {
        printf("InValid");
    } else if (kilometer <= 48.697) {
        printf("Ayutthaya");
    } else if (kilometer <= 66.456) {
        printf("Ang Thong");
    } else if (kilometer <= 84.918) {
        printf("Sing Buri");
    } else if (kilometer <= 85.900) {
        printf("Lop Buri");
    } else if (kilometer <= 111.936) {
        printf("Sing Buri");
    } else if (kilometer <= 150.019) {
        printf("Chai Nat");
    } else {
        printf("Nakhon Sawan");
    }
}

int main() {
    double kilometer;
    scanf("%lf", &kilometer);
    getProvince(kilometer);

    return 0;
}
