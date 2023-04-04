#include"card.h"


/**
 * @brief Get the Card Holder Name object
 *
 * @param cardData
 * @return EN_cardError_t
 */
EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	uint8_t name[25]={0};
	uint8_t NameLength =0;
	uint8_t i =0;
	printf("Enter The Card Holder Name : ");
	gets(name);
	NameLength = strlen(name);

	if( (NameLength< 20) || (NameLength >24) || (NULL == cardData))
		return WRONG_NAME;
    for (i = 0; i < NameLength; i++)
    {
        if((name[i] < 'A' && name[i] != ' ') || (name[i] > 'Z' && name[i] < 'a') || (name[i] > 'z'))
            return WRONG_NAME;
    }
    strcpy(cardData->cardHolderName, name);

    return  CARD_OK;
}


/**
 * @brief Get the Card Expiry Date object
 *
 * @param cardData
 * @return EN_cardError_t
 */
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	uint8_t exp_date[10]={0};
	uint8_t i=0;
	uint8_t expiryDatelenght=0;
	printf("Enter The Expirartion  Date : ");
	gets(exp_date);
	expiryDatelenght = strlen(exp_date);
	if ((expiryDatelenght < 5) || (expiryDatelenght >5 ) || ((NULL == cardData)))
		return WRONG_EXP_DATE;
	for (i = 0;i < expiryDatelenght;i++)
	{
	    /*"MM/YY", e.g "05/25"*/
		if ((exp_date[i] < '0' || exp_date[i] > '9') && i < 2)
			return WRONG_EXP_DATE;
		else if (exp_date[1] == '0' && exp_date[0] == '0')
			return WRONG_EXP_DATE;
		else if (i == 2 && exp_date[2] != '/')
			return WRONG_EXP_DATE;
		else if (i >2 && exp_date[i] == '0')
			return WRONG_EXP_DATE;
	}
	strcpy(cardData->cardExpirationDate, exp_date);
	return  CARD_OK;
}

/**
 * @brief Get the Card P A N object
 *
 * @param cardData
 * @return EN_cardError_t
 */
EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	uint8_t PAN[25]={0};
	uint8_t CardPanLenght, i;
	printf("Enter The Primary Account Number of The Card : ");
	gets(PAN);
	CardPanLenght= strlen(PAN);
	if (CardPanLenght < 16 || CardPanLenght >19)
		return WRONG_PAN;
	for (i = 0;i < CardPanLenght;i++)
	{
		if (PAN[i] < '0' || PAN[i] >'9')
			return WRONG_PAN;
	}
	strcpy(cardData->primaryAccountNumber, PAN);
	return  CARD_OK;
}
