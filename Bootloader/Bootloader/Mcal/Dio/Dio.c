/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              Dio.c
* MODULE:            Dio
* AUTHOR:            ShroukRashwan
* DESCRIPTION:       Dio driver functional implementation
* CREATION DATE:     7/2/2020
* MODIFICATION DATE: 11/2/2020
**************************************************************************************************/

/**************************************************************************************************
*                                       INCLUDES & LIBRARIES                                      *
**************************************************************************************************/
#include "Dio.h"
#include "Dio_Internal.h"

/**************************************************************************************************
*                                         GLOBAL VARIABLES                                        *
**************************************************************************************************/
#if UNIT_TESTING == STD_ON
uint8 Dio_PINA                                                                                  =0;
uint8 Dio_PORTA                                                                                 =0;
uint8 Dio_DDRA                                                                                  =0;

uint8 Dio_PINB                                                                                  =0;
uint8 Dio_PORTB                                                                                 =0;
uint8 Dio_DDRB                                                                                  =0;

uint8 Dio_PINC                                                                                  =0;
uint8 Dio_PORTC                                                                                 =0;
uint8 Dio_DDRC                                                                                  =0;

uint8 Dio_PIND                                                                                  =0;
uint8 Dio_PORTD                                                                                 =0;
uint8 Dio_DDRD                                                                                  =0;
#endif

/**************************************************************************************************
*                                     FUNCTIONS IMPLEMENTATION                                    *
**************************************************************************************************/

boolean Dio_WritePin(uint8 Param_PortNumber, uint8 Param_PinNumber, uint8 Param_Value)
{
    boolean Loc_ReturnStatus = TRUE;
    /* Check if Port Number is right. (0-3) */
    /* Check if Pin Number is right. (0-7) */
    /* If passed the checks continue with code */
    if( (Param_PortNumber <= DIO_NUMBER_OF_PORTS ) && (Param_PinNumber <= DIO_NUMBER_OF_CHANNELS))
    {
        uint8* Loc_PortPtr;
        boolean Loc_ReturnStatus = TRUE;
        /* Get the suitable PORT according to port number */
        switch (Param_PortNumber)
        {
            case PORT_A:
            Loc_PortPtr = &DIO_PORTA;
            break;
            case PORT_B:
            Loc_PortPtr = &DIO_PORTB;
            break;
            case PORT_C:
            Loc_PortPtr = &DIO_PORTC;
            break;
            case PORT_D:
            Loc_PortPtr = &DIO_PORTD;
            break;
            default:
            break;
        }
        /* Check value passed by user */
        if(HIGH == Param_Value)
        {
            /* Set pin to high */
            SET_BIT(*Loc_PortPtr,Param_PinNumber);
        }
        else
        {
            /* Clear pin (LOW) */
            CLEAR_BIT(*Loc_PortPtr,Param_PinNumber);
        }
        
    }
    else
    {
        /* Parameter Error */
        Loc_ReturnStatus = FALSE;
    }

    return Loc_ReturnStatus;
}

boolean Dio_ReadPin(uint8 Param_PortNumber, uint8 Param_PinNumber, uint8* Param_ReturnValue)
{
    boolean Loc_ReturnStatus = TRUE;
    /* Check if Port Number is right. (0-3) */
    /* Check if Pin Number is right. (0-7) */
    /* If passed the checks continue with code */
    if( (Param_PortNumber <= DIO_NUMBER_OF_PORTS ) && (Param_PinNumber <= DIO_NUMBER_OF_CHANNELS)  && (Param_ReturnValue != NULL_PTR))
    {
        uint8 * Loc_PinPtr;
        uint8 Loc_ReturnValue = LOW;
        /* Get Suitable PIN register according to Port number */
        switch (Param_PortNumber)
        {
            case PORT_A:
            Loc_PinPtr = &DIO_PINA;
            break;
            case PORT_B:
            Loc_PinPtr = &DIO_PINB;
            break;
            case PORT_C:
            Loc_PinPtr = &DIO_PINC;
            break;
            case PORT_D:
            Loc_PinPtr = &DIO_PIND;
            break;
            default:
            break;
        }
        /* Get pin value and return it to the user*/
       *Param_ReturnValue = GET_BIT(*Loc_PinPtr,Param_PinNumber);
    }
    else
    {
        /* error invalid param */
        Loc_ReturnStatus =FALSE;
    }
    return Loc_ReturnStatus;
}

boolean Dio_WritePort(uint8 Param_PortNumber, uint8 Param_Value)
{
    boolean Loc_ReturnStatus = TRUE;
    /* Check if Port Number is right. (0-3) */
    /* If passed the checks continue with code */
    if(Param_PortNumber <= DIO_NUMBER_OF_PORTS)
    {
        uint8* Loc_PortPtr;
        /* Get suitable PORT register according to port number*/
        switch (Param_PortNumber)
        {
            case PORT_A:
            Loc_PortPtr = &DIO_PORTA;
            break;
            case PORT_B:
            Loc_PortPtr = &DIO_PORTB;
            break;
            case PORT_C:
            Loc_PortPtr = &DIO_PORTC;
            break;
            case PORT_D:
            Loc_PortPtr = &DIO_PORTD;
            break;
            default:
            break;
        }
        /* Set port with given value */
        *Loc_PortPtr = Param_Value;
    }
    else
    {
        /* error invalid param */
        Loc_ReturnStatus = FALSE;
    }
    return Loc_ReturnStatus;
}

boolean Dio_ReadPort(uint8 Param_PortNumber, uint8* Param_ReturnValue)
{
    boolean Loc_ReturnStatus = TRUE;
    /* Check if Port Number is right. (0-3) */
    /* If passed the checks continue with code */
    if( (Param_PortNumber <= DIO_NUMBER_OF_PORTS) && (Param_ReturnValue != NULL_PTR) )
    {
        uint8 * Loc_PinPtr;
        /* Determine suitable PIN register according to given port number*/
        switch (Param_PortNumber)
        {
            case PORT_A:
            Loc_PinPtr = &DIO_PINA;
            break;
            case PORT_B:
            Loc_PinPtr = &DIO_PINB;
            break;
            case PORT_C:
            Loc_PinPtr = &DIO_PINC;
            break;
            case PORT_D:
            Loc_PinPtr = &DIO_PIND;
            break;
            default:
            break;
        }
        
        /* Return port value to user */
        *Param_ReturnValue = *Loc_PinPtr;
    }
    else
    {
        /* error invalid param */
        Loc_ReturnStatus = FALSE;
    }
    return Loc_ReturnStatus;
}

boolean Dio_SetPinDirection(uint8 Param_PortNumber, uint8 Param_PinNumber, uint8 Param_Mode)
{
    boolean Loc_ReturnStatus = TRUE;
    /* Check if Port Number is right. (0-3) */
    /* Check if Pin Number is right. (0-7) */
    /* If passed the checks continue with code */
    if( (Param_PortNumber <= DIO_NUMBER_OF_PORTS ) && (Param_PinNumber <= DIO_NUMBER_OF_CHANNELS) && (Param_Mode < 2) )
    {
        uint8* Loc_DdrPtr;
        /* Get suitable DDR register according to given port number */
        switch (Param_PortNumber)
        {
            case PORT_A:
            Loc_DdrPtr = &DIO_DDRA;
            break;
            case PORT_B:
            Loc_DdrPtr = &DIO_DDRB;
            break;
            case PORT_C:
            Loc_DdrPtr = &DIO_DDRC;
            break;
            case PORT_C:
            Loc_DdrPtr = &DIO_DDRD;
            break;
            default:
            break;
        }
        
        /* Set pin with given value */
        if(INPUT == Param_Mode)
        {
            SET_BIT(*Loc_DdrPtr,Param_PinNumber);
        }
        else
        {
            CLEAR_BIT(*Loc_DdrPtr,Param_PinNumber);
        }
    }
    else
    {
        /* error invalid param */
        Loc_ReturnStatus = FALSE;
    }
    return Loc_ReturnStatus;
}

boolean Dio_SetPortDirection(uint8 Param_PortNumber, uint8 Param_Mode)
{
    boolean Loc_ReturnStatus = TRUE;
    /* Check if Port Number is right. (0-3) */
    /* If passed the checks continue with code */
    if( (Param_PortNumber <= DIO_NUMBER_OF_PORTS))
    {
        uint8* Loc_DdrPtr;
        /* Get suitable DDR register according to given port number */
        switch (Param_PortNumber)
        {
            case PORT_A:
            Loc_DdrPtr = &DIO_DDRA;
            break;
            case PORT_B:
            Loc_DdrPtr = &DIO_DDRB;
            break;
            case PORT_C:
            Loc_DdrPtr = &DIO_DDRC;
            break;
            case PORT_D:
            Loc_DdrPtr = &DIO_DDRD;
            break;
            default:
            break;
        }
        
        /* Set port with given value */
        *Loc_DdrPtr = Param_Mode;
    }
    else
    {
        /* error invalid param */
        Loc_ReturnStatus = FALSE;
    }

    return Loc_ReturnStatus;
}
