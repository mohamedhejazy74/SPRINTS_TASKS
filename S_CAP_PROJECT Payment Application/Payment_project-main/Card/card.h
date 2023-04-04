#ifndef _CARD_H_
#define _CARD_H_
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include "../std_types.h"

/*
*
*
*T_cardData_t datatye hold the transaction data
*@struct_Members
*   (uint8_t cardHolderName[25])  card holder name
*   (uint8_t primaryAccountNumber[20]) holds PAN of card
*   (uint8_t cardExpirationDate[6]) holds EXP date
*
*/
typedef struct ST_cardData_t
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];
}ST_cardData_t;


/*
*
*
* EN_cardError_t datatype enum contains all return states
* @enum_members
*
* CARD_OK
* WRONG_NAME
* WRONG_EXP_DATE
* WRONG_PAN
*
*/
typedef enum EN_cardError_t
{
    CARD_OK,
    WRONG_NAME,
    WRONG_EXP_DATE,
    WRONG_PAN
}EN_cardError_t;



/**
 * @brief Get the Card Holder Name object
 *
 * @param cardData
 * @return EN_cardError_t
 */
EN_cardError_t getCardHolderName(ST_cardData_t* cardData);

/**
 * @brief Get the Card Expiry Date object
 *
 * @param cardData
 * @return EN_cardError_t
 */
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);


/**
 * @brief Get the Card P A N object
 *
 * @param cardData
 * @return EN_cardError_t
 */
EN_cardError_t getCardPAN(ST_cardData_t* cardData);
#endif  _CARD_H_
