#include"server.h"
extern ST_cardData_t card_data;
extern ST_terminalData_t terminaldata;
extern ST_accountsDB_t accountrefrence;
extern ST_transaction_t trans;
static uint8_t size = 0;
static uint8_t account_number;
ST_accountsDB_t accountsDB[255] = { {2000.0, RUNNING, "8989374615436851"},{100000.0, BLOCKED, "5807007076043875"},
	{5000.0,RUNNING,"4573764412737702"},{20000.0,RUNNING,"9514097475031791"},{4000.0,BLOCKED,"1234123412341234"}
};
static ST_transaction_t transactionDB[255] = { 0 };
EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	float value;
	strcpy(transData->cardHolderData.cardHolderName, card_data.cardHolderName);
	strcpy(transData->cardHolderData.primaryAccountNumber, card_data.primaryAccountNumber);
	strcpy(transData->cardHolderData.cardExpirationDate, card_data.cardExpirationDate);
	strcpy(transData->terminalData.transactionDate, terminaldata.transactionDate);
	transData->terminalData.transAmount = terminaldata.transAmount;
	transData->terminalData.maxTransAmount = terminaldata.maxTransAmount;
	if (isValidAccount(&card_data, &accountrefrence) == ACCOUNT_NOT_FOUND)
	{
		transData->transState = FRAUD_CARD;
		return FRAUD_CARD;
	}
	else if (isBlockedAccount(&accountrefrence) == BLOCKED_ACCOUNT)
	{
		transData->transState = DECLINED_STOLEN_CARD;
		return DECLINED_STOLEN_CARD;
	}
	else if (isAmountAvailable(&terminaldata, &accountrefrence) == LOW_BALANCE)
	{
		transData->transState = DECLINED_INSUFFECIENT_FUND;
		return DECLINED_INSUFFECIENT_FUND;
	}
	else
	{
		transData->transState = APPROVED;
		accountsDB[account_number].balance=accountrefrence.balance - terminaldata.transAmount;
		return APPROVED;
	}

}
EN_serverError_t isValidAccount(ST_cardData_t* cardData,  ST_accountsDB_t* accountRefrence)
{
	for (account_number = 0;account_number < 255;account_number++)
	{
		if (strcmp(accountsDB[account_number].primaryAccountNumber ,cardData->primaryAccountNumber)==0)
		{

           strcpy(accountRefrence->primaryAccountNumber, accountsDB[account_number].primaryAccountNumber);
		   accountRefrence->balance = accountsDB[account_number].balance;
		   accountRefrence->state = accountsDB[account_number].state;
			return SERVER_OK;
		}
	}
	accountRefrence = NULL;
	return ACCOUNT_NOT_FOUND;
}
EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence)
{
	if (accountRefrence->state == RUNNING)
		return SERVER_OK;
	if (accountRefrence->state == BLOCKED)
		return BLOCKED_ACCOUNT;

}
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence)
{
	if (termData->transAmount > accountRefrence->balance)
		return LOW_BALANCE;
	if (termData->transAmount <= accountRefrence->balance)
	{

			return SERVER_OK;
	}
}
EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	static uint8_t i = 0;
	size++;

	transData->transactionSequenceNumber = size;
	if (size <= 255)
	{
		transactionDB[i].cardHolderData = transData->cardHolderData;
		transactionDB[i].terminalData = transData->terminalData;
		transactionDB[i].transState = transData->transState;
		transactionDB[i].transactionSequenceNumber = size;
		i++;
		return SERVER_OK;
	}
	else return SAVING_FAILED;

}
void listSavedTransactions(void)
{
	uint8_t st,i;

	for (i = 0;i < size;i++)
	{
			printf("#####################################\n");
			printf("Transaction Sequence Number : %d\n", transactionDB[i].transactionSequenceNumber);
			printf("Transaction Date : %s\n", transactionDB[i].terminalData.transactionDate);
			printf("Transaction Amount : %f\n", transactionDB[i].terminalData.transAmount);
			st = transactionDB[i].transState;
			if (st == APPROVED)
				printf("Transaction State : approved \n");
			else if (st == DECLINED_INSUFFECIENT_FUND)
				printf("Transaction State : DECLINED_INSUFFECIENT_FUND \n");
			else if (st == DECLINED_STOLEN_CARD)
				printf("Transaction State : blocked \n");
			else if (st == FRAUD_CARD)
				printf("Transaction State : FRAUD CARD \n");
			else
				printf("Transaction State : INTERNAL_SERVER_ERROR \n");
			printf("Terminal Max Amount : %f\n", transactionDB[i].terminalData.maxTransAmount);
			printf("Cardholder Name : %s\n", transactionDB[i].cardHolderData.cardHolderName);
			printf("Card Expiration Date : %s\n", transactionDB[i].cardHolderData.cardExpirationDate);
			printf("PAN: %s\n", transactionDB[i].cardHolderData.primaryAccountNumber);
			printf("#####################################\n");

	}
}
