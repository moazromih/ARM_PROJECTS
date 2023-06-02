/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   22 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSCFG_interface.h"
#include "SYSCFG_private.h"
#include "SYSCFG_config.h"

void MSYSCFG_voidSelectInterruptPort(u8 Copy_u8LineID, u8 Copy_u8Port)
{
    switch (Copy_u8LineID)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        SYSCFG->EXTICR1 &= ~(FOUR_BITS_MSK<<((Copy_u8LineID%FOUT_BITS_SHIFT)*FOUT_BITS_SHIFT));
        SYSCFG->EXTICR1 |= (Copy_u8Port<<((Copy_u8LineID%FOUT_BITS_SHIFT)*FOUT_BITS_SHIFT));
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        SYSCFG->EXTICR2 &= ~(FOUR_BITS_MSK<<((Copy_u8LineID%FOUT_BITS_SHIFT)*FOUT_BITS_SHIFT));
        SYSCFG->EXTICR2 |= (Copy_u8Port<<((Copy_u8LineID%FOUT_BITS_SHIFT)*FOUT_BITS_SHIFT));
        break;
    case 8:
    case 9:
    case 10:
    case 11:
        SYSCFG->EXTICR3 &= ~(FOUR_BITS_MSK<<((Copy_u8LineID%FOUT_BITS_SHIFT)*FOUT_BITS_SHIFT));
        SYSCFG->EXTICR3 |= (Copy_u8Port<<((Copy_u8LineID%FOUT_BITS_SHIFT)*FOUT_BITS_SHIFT));
        break;
    case 12:
    case 13:
    case 14:
    case 15:
        SYSCFG->EXTICR4 &= ~(FOUR_BITS_MSK<<((Copy_u8LineID%FOUT_BITS_SHIFT)*FOUT_BITS_SHIFT));
        SYSCFG->EXTICR4 |= (Copy_u8Port<<((Copy_u8LineID%FOUT_BITS_SHIFT)*FOUT_BITS_SHIFT));
        break;
    default:
        /* ERROR */
        break;
    }
}
