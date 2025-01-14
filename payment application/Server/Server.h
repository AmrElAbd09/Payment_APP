#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED
#endif // SERVER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include"../Card/Card.h"
#include"../Terminal/Terminal.h"


typedef unsigned char uint8_t ;
typedef unsigned long int uint32_t ;


// for transaction state
typedef enum EN_transState_t
{
     APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, FRAUD_CARD, INTERNAL_SERVER_ERROR
}EN_transState_t ;




typedef struct ST_transaction_t
{
    ST_cardData_t cardHolderData;
    ST_terminalData_t terminalData;
    EN_transState_t transState;
    uint32_t transactionSequenceNumber;
} ST_transaction_t;



typedef enum EN_serverError_t
{
    SERVER_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE, BLOCKED_ACCOUNT
} EN_serverError_t ;



typedef enum EN_accountState_t
{
    RUNNING,
    BLOCKED
} EN_accountState_t;




typedef struct ST_accountsDB_t
{
    float balance;
    EN_accountState_t state;
    uint8_t primaryAccountNumber[20];
} ST_accountsDB_t;



/******************* Functions prototypes *************************/

EN_transState_t recieveTransactionData(ST_transaction_t *transData);

EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t *accountRefrence);
void isValidAccountTest(void);

EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence);

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountRefrence);

EN_serverError_t saveTransaction(ST_transaction_t *transData);

void listSavedTransactions(void);

