#include "Std_Types.h"
#include "MemMap.h"
#include "Utils.h"
#include "EEPROM.h"
#include "EEPROM_Private.h"
#include "I2C_REG.h"


static uint16 Arr_Address;  // Static variable to store the address for array operations.
static uint8* Arr_data;     // Pointer to the array data.
static uint16 Arr_index;    // Index variable for array operations.
static uint16 Arr_size;     // Size of the array.

static void (*EE_RDY_Fptr) (void)=NULL_PTR;  // Function pointer for EEPROM write completion callback.

void EEPROM_Init(void)
{
	// Initialization function for EEPROM (empty implementation).
}

Write_Status_type EEPROM_write(uint16 Address, uint8 Data)
{
	/*while(EECR & (1<<EEWE));*/
	Write_Status_type status;
	if (Address >= 0 && Address <=1023)
	{
		EEAR = Address;
		EEDR = Data;
		SET_BIT(EECR,EEMWE);
		SET_BIT(EECR,EEWE);
		status=DONE;
	}
	else
	{
		status=OUT_OF_RANGE;
	}
	return status;
}

uint8 EEPROM_read(uint16 Address)
{
	EEAR = Address;
	SET_BIT(EECR,EERE);
	return EEDR;
}

void EEPROM_InterruptEnable(void)
{
	SET_BIT(EECR,EERIE);
}

void EEPROM_InterruptDisable(void)
{
	CLEAR_BIT(EECR,EERIE);
}

void EEPROM_EE_RDY_SetCallBack(void(*LocalFptr)(void))
{
	EE_RDY_Fptr=LocalFptr;
}

ISR(EE_RDY_vect)
{
	if(EE_RDY_Fptr!=NULL_PTR)
	{
		EE_RDY_Fptr();
	}
}

static void Array_ISR (void)
{
	if (Arr_index < Arr_size)
	{
		EEPROM_write(Arr_Address,*(Arr_data+Arr_index));
		Arr_index++;
		Arr_Address++;
	}
	else
	{
		EEPROM_InterruptDisable();
		Arr_index=0;
		EEPROM_EE_RDY_SetCallBack(NULL_PTR);
	}
}

Write_Status_type EEPROM_write_array(uint16 Address,uint8* data,uint16 size)
{
	Write_Status_type status;
	if (Address >= 0 && Address+size <=1024)
	{
		Arr_Address=Address;
		Arr_data=data;
		Arr_size=size;
		EEPROM_EE_RDY_SetCallBack(Array_ISR);
		/*EEPROM_InterruptEnable();*/
		EEPROM_write(Address,*data);
		EEPROM_InterruptEnable();
		Arr_index=1;
		Arr_Address++;
		status=DONE;
	}
	else
	{
		status=OUT_OF_RANGE;
	}
	return status;
}

void EEPROM_read_array(uint16 Address, uint16 size, uint8* arr)
{
	for (uint16 i=0;i<size;i++)
	{
		*(arr+i)=EEPROM_read(Address+i);
	}
}
