/*
 * SPI.c
 *
 *  Created on: Nov 1, 2023
 *      Author: EVA
 */


#include "BIT_MATH.h"
#include"STD_TYPES.h"

#include"SPI_INTERFACE.h"
#include"SPI_CONFIG.h"
#include"SPI_REG.h"


/*Global flag for the SPI Busy State*/
static uint8 SPI_State= IDLE ;

/*timeout counter*/
 uint32 TIMEOUT=5000;


uint8 SPI_InitConfig (SPI_CONFIG * spi)
{
	uint8 Local_Error= OK ;

	if ((spi != NULL) && (spi->SPI_ClockPhase != NULL) && (spi->SPI_ClockPolarity != NULL) && (spi->SPI_ClockRate != NULL) && (spi->SPI_DataOrder != NULL) && (spi->SPI_InterruptEnable != NULL) && (spi->SPI_MasterSlaveSelect != NULL) && (spi->SPI_SPIEnable != NULL))
	{
			switch (spi->SPI_ClockPhase)
			{
			case SPI_SAMPLE_LEADING_SETUP_TRAILING: CLR_BIT(SPCR , SPCR_CPHA) ; break ;
			case SPI_SETUP_LEADING_SAMPLE_TRAILING: SET_BIT(SPCR , SPCR_CPHA) ; break ;
			default: 								Local_Error = NOK ; break ;
			}
			switch (spi->SPI_ClockPolarity)
			{
			case SPI_RISING_LEADING_FALLING_TRAILING: CLR_BIT(SPCR , SPCR_CPOL) ; break ;
			case SPI_FALLING_LEADING_RISING_TRAILING: SET_BIT(SPCR , SPCR_CPOL) ; break ;
			default:								  Local_Error= NOK ; break ;
			}
			switch (spi->SPI_ClockRate)
					{
					case SPI_FREQ_DIVIDED_BY_2:
						CLR_BIT(SPCR , SPCR_SPR0) ;
						CLR_BIT(SPCR , SPCR_SPR1) ;
						SET_BIT(SPSR , SPSR_SPI2X) ;
						break ;
					case SPI_FREQ_DIVIDED_BY_4:
						CLR_BIT(SPCR , SPCR_SPR0) ;
						CLR_BIT(SPCR , SPCR_SPR1) ;
						CLR_BIT(SPSR , SPSR_SPI2X) ;
						break ;
					case SPI_FREQ_DIVIDED_BY_8:
						SET_BIT(SPCR , SPCR_SPR0) ;
						CLR_BIT(SPCR , SPCR_SPR1) ;
						SET_BIT(SPSR , SPSR_SPI2X) ;
						break ;
					case SPI_FREQ_DIVIDED_BY_16:
						SET_BIT(SPCR , SPCR_SPR0) ;
						CLR_BIT(SPCR , SPCR_SPR1) ;
						CLR_BIT(SPSR , SPSR_SPI2X) ;
						break ;
					case SPI_FREQ_DIVIDED_BY_32:
						CLR_BIT(SPCR , SPCR_SPR0) ;
						SET_BIT(SPCR , SPCR_SPR1) ;
						SET_BIT(SPSR , SPSR_SPI2X) ;
						break ;
					case SPI_FREQ_DIVIDED_BY_64:
						CLR_BIT(SPCR , SPCR_SPR0) ;
						SET_BIT(SPCR , SPCR_SPR1) ;
						CLR_BIT(SPSR , SPSR_SPI2X) ;
						break ;
					case SPI_FREQ_DIVIDED_BY_128:
						SET_BIT(SPCR , SPCR_SPR0) ;
						SET_BIT(SPCR , SPCR_SPR1) ;
						CLR_BIT(SPSR , SPSR_SPI2X) ;
						break ;
					default:
						Local_Error = NOK ;
						break ;
					}
			switch (spi->SPI_DataOrder)
			{
			case SPI_DATA_MSB: CLR_BIT(SPCR , SPCR_DORD) ; break ;
			case SPI_DATA_LSB: SET_BIT(SPCR , SPCR_DORD) ; break ;
			default:				 Local_Error = NOK ; break ;
			}
			switch (spi->SPI_MasterSlaveSelect)
					{
					case SPI_MASTER: SET_BIT(SPCR , SPCR_MSTR) ; break ;
					case SPI_SLAVE:  CLR_BIT(SPCR , SPCR_MSTR) ; break ;
					default:		 Local_Error = NOK ; break ;
					}

			switch (spi->SPI_InterruptEnable)
					{
					case SPI_INTERRUPT_DISABLE: CLR_BIT(SPCR , SPCR_SPIE) ; break ;
					case SPI_INTERRRUPT_ENABLE:  SET_BIT(SPCR , SPCR_SPIE) ; break ;
					default:		 			Local_Error = NOK ; break ;
					}
			switch (spi->SPI_SPIEnable)
					{
					case SPI_DISABLE: CLR_BIT(SPCR , SPCR_SPE) ; break ;
					case SPI_ENABLE:  SET_BIT(SPCR , SPCR_SPE) ; break ;
					default:		  Local_Error = NOK ; break ;
					}
	}
		else
		{
			Local_Error = NULL_POINTER ;
		}
		return Local_Error ;
	}

	/**********************************************/


	uint8 SPI_Tranceive_Receive (uint8 Copy_TData , uint8 * Copy_RData)
	{
		uint8 Local_Error=OK;
		uint32 local_timeout=0;
		if (SPI_State == IDLE)
		{
			SPI_State=BUSY;
			SPDR = Copy_TData ;
			while (((GET_BIT(SPSR , SPSR_SPIF)) == 0) && (local_timeout <TIMEOUT))
			{
				local_timeout++;
			}
			if (local_timeout == TIMEOUT)
					{
						Local_Error= TIMEOUT_STATE ;
					}
			else
					{
						* Copy_RData = SPDR ;
					}
					SPI_State = IDLE ;
		}
		else
			{
				Local_Error = BUSY_STATE ;
			}
		return Local_Error;

	}


	/**********************************************/


	void SPI_SendByte(uint8 data)
	{
		SPDR = data;
		while(Bit_Is_Clear(SPSR,SPSR_SPIF));
	}

	/**********************************************/

	uint8 SPI_ReceiveByte()
	{
		while(Bit_Is_Clear(SPSR,SPSR_SPIF));
		return SPDR;
	}

	/**********************************************/

	void SPI_SendString(uint8 *str)
	{
		while(*str)
		{
			SPI_SendByte(*str);
			str++;
		}
	}

	/**********************************************/

	void SPI_ReceiveString(uint8 *str)
	{
		uint8 i = 0;
		str[i] = SPI_ReceiveByte();
		while(str[i] != '#')
		{
			i++;
			str[i] = SPI_ReceiveByte();
		}
		str[i] = '\0';
	}
