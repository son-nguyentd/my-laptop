#include "AGV.h"
#define number 10


int main(void) {
	Agv_parameter agv_list[number];

	Init_Agv(&agv_list[0], "AB2011", 20, 30, "IMUS");
	Init_Agv(&agv_list[1], "AB2012", 20, 30, "IMUS");
	Init_Agv(&agv_list[2], "AB2023", 50, 35, "IMUS");
	Init_Agv(&agv_list[3], "AB2024", 25, 30, "IMUS");
	Init_Agv(&agv_list[4], "AB2012", 45, 38, "IMUS");
	Init_Agv(&agv_list[5], "AB2023", 25, 15, "IMUS");
	Init_Agv(&agv_list[6], "AB2024", 20, 30, "IMUS");
	Init_Agv(&agv_list[7], "AB2012", 10, 30, "IMUS");
	Init_Agv(&agv_list[8], "AB2011", 12, 30, "IMUS");
	Init_Agv(&agv_list[9], "AB2011", 13, 30, "IMUS");
	printf("bat dau kiem tra agv du dieu kien di khong duong tu");
	for (int i = 0; i < number; i++) {
		if (check_run_Imu(&agv_list[i]) == SUCCESS) {
			printf(" AGV %d:, Phienban: %s, Dungluongpin: %d, Tocdohientai:%d, RFID: %s\n", i, agv_list[i].Phienban, agv_list[i].Dungluong_Pin, agv_list[i].Tocdo_Hientai, agv_list[i].RFID);
		}
	}

	return 0;
}