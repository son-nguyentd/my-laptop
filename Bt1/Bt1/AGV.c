#include "AGV.h"
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE


void Init_Agv(Agv_parameter* agv, const char* Phienban, uint8_t Dungluong_pin, uint16_t Tocdo_hientai, const char* RFID) {
	size_t phienban_len = strlen(Phienban) + 1;
	if (phienban_len > sizeof(agv->Phienban)) {
		phienban_len = sizeof(agv->Phienban);
	}
	memcpy(agv->Phienban, Phienban, phienban_len);
	/*strcpy(agv->Phienban, Phienban);*/
	agv->Dungluong_Pin = Dungluong_pin;
	agv->Tocdo_Hientai = Tocdo_hientai;
	size_t rfid_len = strlen(RFID) + 1;
	if (rfid_len > sizeof(agv->RFID)) {
		rfid_len = sizeof(agv->RFID);
	}
	memcpy(agv->RFID, RFID, rfid_len);
	/*strcpy(agv->RFID, RFID);*/
}


void Update_Phienban(Agv_parameter* agv, const char* Phienban) {
	size_t phienban_len = strlen(Phienban) + 1;
	if (phienban_len > sizeof(agv->Phienban)) {
		phienban_len = sizeof(agv->Phienban);
	}
	memcpy(agv->Phienban, Phienban, phienban_len);
	/*strcpy(agv->Phienban, Phienban);*/
}


void Update_Dungluong_pin(Agv_parameter* agv, uint8_t Dungluong_pin) {
	agv->Dungluong_Pin = Dungluong_pin;
}


void Update_Tocdo_hientai(Agv_parameter* agv, uint16_t Tocdo_hientai) {
	agv->Tocdo_Hientai = Tocdo_hientai;
}


void Update_RFID(Agv_parameter* agv, const char* RFID) {
	size_t rfid_len = strlen(RFID) + 1;
	if (rfid_len > sizeof(agv->RFID)) {
		rfid_len = sizeof(agv->RFID);
	}
	memcpy(agv->RFID, RFID, rfid_len);
	/*strcpy(agv->RFID, RFID);*/
}


int check_run_Imu(const Agv_parameter* agv) {
	if (strcmp(agv->Phienban, "AB2023") >= 0 && agv->Dungluong_Pin > 35 && agv->Tocdo_Hientai >= 20 && agv->Tocdo_Hientai <= 35 && strcmp(agv->RFID, "IMUS") == 0) {
		return SUCCESS;
	}
	return 	ERROR;
}


Frame frame_st(const uint8_t* frame, size_t frameSite) {
	Frame frame_st;
	frame_st.startByte = frame[0];
	frame_st.length = frame[1];
	frame_st.data = (uint8_t*)malloc(frame_st.length * sizeof(uint8_t));
	if (frame_st.data != NULL) {
		memcpy(frame_st.data, frame + 2, frame_st.length);
	}
	frame_st.endByte = frame[2 + frame_st.length];
	return frame_st;
}

uint8_t Checksum(const uint8_t* data, uint8_t lenght) {
	uint8_t checksum = 0;
	for (uint8_t i = 0; i < lenght; i++) {
		checksum += data[i];
	}
	return checksum;
}

uint8_t freeFrame(Frame* frame) {
	if (frame) {
		if (frame->data) {
			free(frame->data);
		}
		free(frame);
	}
}


void getStaticIP(uint8_t a, uint8_t b, uint8_t c, uint8_t d) {
	printf("Configuring static IP: %d.%d.%d.%d\n", a, b, c, d);
}

void SetIP(const char* ipString) {
	uint8_t ipParts[4] = { 0 };
	int partIndex = 0;

	char temp[4] = { 0 };
	int tempIndex = 0;

	for (int i = 0; i <= strlen(ipString); i++) {
		if (ipString[i] == '.' || ipString[i] == '\0') {
			temp[tempIndex] = '\0';
			ipParts[partIndex] = (uint8_t)atoi(temp);
			partIndex++;
			tempIndex = 0; 
		}
		else {
			temp[tempIndex] = ipString[i];
			tempIndex++;
		}
	}

	if (partIndex == 4) {
		getStaticIP(ipParts[0], ipParts[1], ipParts[2], ipParts[3]);
	}
	else {
		printf("Invalid IP format\n");
	}
}