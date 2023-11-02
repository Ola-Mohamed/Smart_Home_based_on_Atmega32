/*
 * SPI_INTERFACE.h
 *
 *  Created on: Nov 1, 2023
 *      Author: EVA
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_



#define	SPI_ENABLE		1
#define	SPI_DISABLE		0

#define	SPI_INTERRRUPT_ENABLE	1
#define	SPI_INTERRUPT_DISABLE	0

#define SPI_DATA_LSB			0
#define SPI_DATA_MSB			1

#define SPI_MASTER				0
#define SPI_SLAVE				1


#define SPI_FREQ_DIVIDED_BY_2					0
#define SPI_FREQ_DIVIDED_BY_4					1
#define SPI_FREQ_DIVIDED_BY_8					2
#define SPI_FREQ_DIVIDED_BY_16					3
#define SPI_FREQ_DIVIDED_BY_32					4
#define SPI_FREQ_DIVIDED_BY_64					5
#define SPI_FREQ_DIVIDED_BY_128					6


#define SPI_RISING_LEADING_FALLING_TRAILING 	0
#define SPI_FALLING_LEADING_RISING_TRAILING		1


#define SPI_SAMPLE_LEADING_SETUP_TRAILING 		0
#define SPI_SETUP_LEADING_SAMPLE_TRAILING		1

typedef struct
{
	uint8 SPI_InterruptEnable ;
	uint8 SPI_SPIEnable ;
	uint8 SPI_DataOrder ;
	uint8 SPI_MasterSlaveSelect ;
	uint8 SPI_ClockPolarity ;
	uint8 SPI_ClockPhase ;
	uint8 SPI_ClockRate ;
}SPI_CONFIG;


uint8 SPI_InitConfig (SPI_CONFIG * spi);
uint8 SPI_Tranceive_Receive (uint8 Copy_TData , uint8 * Copy_RData);
void SPI_SendByte(uint8 data);
uint8 SPI_ReceiveByte();
void SPI_SendString(uint8 *str);
void SPI_ReceiveString(uint8 *str);

#endif /* SPI_INTERFACE_H_ */
