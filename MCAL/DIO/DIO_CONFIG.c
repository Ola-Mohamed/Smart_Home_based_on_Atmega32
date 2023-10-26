
#include "DIO_TYPES.h"

/****************************************************************************CONFIG PINS**********************************************************************************/
const DIO_PIN_DIRECTION_TYPE pin_StatusArr[TOTALPORTS_ID][TOTALPINS_ID] = { /* const to stop editing on pins status outer this array */
	{
		PIN_INPUT,   /* PORT A    PIN0 */
		PIN_INPUT,   /* PORT A    PIN1 */
		PIN_INPUT,   /* PORT A    PIN2 */
		PIN_INPUT,   /* PORT A    PIN3 */
		PIN_INPUT,   /* PORT A    PIN4 */
		PIN_INPUT,   /* PORT A    PIN5 */
		PIN_INPUT,   /* PORT A    PIN6 */
		PIN_INPUT    /* PORT A    PIN7 */
	},
	{
		PIN_INPUT,   /* PORT B    PIN0 */
		PIN_INPUT,   /* PORT B    PIN1 */
		PIN_INPUT,   /* PORT B    PIN2 */
		PIN_INPUT,   /* PORT B    PIN3 */
		PIN_INPUT,   /* PORT B    PIN4 */
		PIN_INPUT,   /* PORT B    PIN5 */
		PIN_INPUT,   /* PORT B    PIN6 */
		PIN_INPUT    /* PORT B    PIN7 */
	},
	{
		PIN_INPUT,   /* PORT C    PIN0 */
		PIN_INPUT,   /* PORT C    PIN1 */
		PIN_INPUT,   /* PORT C    PIN2 */
		PIN_INPUT,   /* PORT C    PIN3 */
		PIN_INPUT,   /* PORT C    PIN4 */
		PIN_INPUT,   /* PORT C    PIN5 */
		PIN_INPUT,   /* PORT C    PIN6 */
		PIN_INPUT    /* PORT C    PIN7 */
	},
	{
		PIN_INPUT,   /* PORT D    PIN0 */
		PIN_INPUT,   /* PORT D    PIN1 */
		PIN_INPUT,   /* PORT D    PIN2 */
		PIN_INPUT,   /* PORT D    PIN3 */
		PIN_INPUT,   /* PORT D    PIN4 */
		PIN_INPUT,   /* PORT D    PIN5 */
		PIN_INPUT,   /* PORT D    PIN6 */
		PIN_INPUT    /* PORT D    PIN7 */

	}
};
