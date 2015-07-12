#include "KSMarketApiHandler.h"

const int MAX_CONNECTION = 1;
CThostFtdcMdApi *pUserApi[MAX_CONNECTION] = { 0 };
KSMarketApiHandler *pSpi[MAX_CONNECTION] = { 0 };