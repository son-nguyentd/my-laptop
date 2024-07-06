#pragma once

#ifndef _AGV_H_
#define _AGV_H_
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// define parameter AGV ************************************/
typedef struct {
	char Phienban[4];
	uint8_t Dungluong_Pin;
	uint16_t Tocdo_Hientai;
	char RFID[4];
}Agv_parameter;

// define enum sattus  ************************************/
typedef enum {
	ERROR	 = 0,
	SUCCESS	 = 1,
}Status;

// define struct frame  ************************************/
typedef struct {
	uint8_t startByte;
	uint8_t length;
	uint8_t* data;
	uint8_t endByte;
} Frame;


/**
******************************************************************************
* @brief  ham khoi tao gia tri  AGV 
* @para : struct agv_parameter, phienban, dung luong pin, toc do hien tai, RFID
* @brief
* @retval Non
******************************************************************************
*/
void Init_Agv(Agv_parameter* agv, const char* Phienban, uint8_t Dungluong_pin, uint16_t Tocdo_hientai, const char* RFID);

/**
******************************************************************************
* @brief  thay doi  AGV phien ban
* @para : struct agv_parameter, phienban
* @brief
* @retval Non
******************************************************************************
*/
void Update_Phienban(Agv_parameter* agv, const char* Phienban);
/**
******************************************************************************
* @brief  thay doi  AGV dung luong pin
* @para : struct agv_parameter, Dungluong_pin
* @brief
* @retval Non
******************************************************************************
*/
void Update_Dungluong_pin(Agv_parameter* agv, uint8_t Dungluong_pin);

/**
******************************************************************************
* @brief  thay doi  AGV toc do hien tai
* @para : struct agv_parameter, Tocdo_hientai
* @brief
* @retval Non
******************************************************************************
*/
void Update_Tocdo_hientai(Agv_parameter* agv, uint16_t Tocdo_hientai);
/**
******************************************************************************
* @brief  thay doi  AGV RFID
* @para : struct agv_parameter, RFID
* @brief
* @retval Non
******************************************************************************
*/
void Update_RFID(Agv_parameter* agv, const char* RFID);
/**
******************************************************************************
* @brief  kiem tra dieu kien di khong duong tu
* @para : struct agv_parameter
* @brief
* @retval ERROR if fail, SUCCESS if ok
******************************************************************************
*/
int check_run_Imu(const Agv_parameter* agv);


/**
******************************************************************************
* @brief  ham cap phat cho frame
* @para : farme, kich thuowc farme
* @brief
* @retval frame
******************************************************************************
*/
Frame frame_st(const uint8_t* frame, size_t frameSite);

/**
******************************************************************************
* @brief  ham kiem tra
* @para : data, kich thuoc data
* @brief
* @retval checksum
******************************************************************************
*/
uint8_t Checksum(const uint8_t* data, uint8_t lenght);
/**
******************************************************************************
* @brief  ham giai phong bo nho cap phat dong
* @para : famre
* @brief
* @retval non
******************************************************************************
*/
uint8_t freeFrame(Frame *frame);


/**
******************************************************************************
* @brief  ham nhap ip
* @para : dia chi a,b,c,d
* @brief
* @retval non
******************************************************************************
*/
void getStaticIP(uint8_t a, uint8_t b, uint8_t c, uint8_t d);

/**
******************************************************************************
* @brief  ham tach ip
* @para :  ip
* @brief
* @retval non
******************************************************************************
*/
void SetIP(const char* ipString);


/******************************************/
#endif /* _AGV_H_ */
