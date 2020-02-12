 /******************************************************************************
 * Module: Common - Macros
 * File Name: Common_Macros.h
 * Description: Commonly used Macros for all modules.
 * Author: MahmoudMorsy
 ******************************************************************************/
#ifndef COMMON_MACROS
#define COMMON_MACROS

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Get a certain bit from any register */
#define GET_BIT(REG,BIT) ((REG >> BIT)&1)

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

/* Boolean Values definitions */
#define FALSE                                                         (boolean)0
#define TRUE                                                          (boolean)1

/* Boolean State Values definitions */
#define LOW                                                           (boolean)0
#define HIGH                                                          (boolean)1
#define STD_ON                                                                 0
#define STD_OFF                                                                1

/* Null Pointer definition */
#define NULL_PTR                                                     ((void *)0)

#endif /* COMMON_MACROS_H_ */