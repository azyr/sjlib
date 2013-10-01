#include "rapi_extensions.h"

#include <cstring>
#include <sstream>
#include <stdexcept>

using namespace RApi;


std::string RApi::RTime::to_string(const char* format) const
{
    time_t t1 = sysc::to_time_t(_tp);
    tm t2 = *std::gmtime(&t1);
    char output[100];
    strftime(output, 99, format, &t2);
    return output;
}

std::string RApi::RTime::to_string_usecs() const
{
    using namespace std::chrono;

    auto dur_us = duration_cast<usecs>(_tp.time_since_epoch());
    int us = dur_us.count() % 1000000;

    time_t t1 = sysc::to_time_t(_tp);
    tm t2 = *std::gmtime(&t1);
    char output[100];
    size_t pos = strftime(output, 99, "%H:%M:%S.", &t2);
    sprintf(output + pos, "%d", us);

    return output;
}

std::string RApi::RTime::to_string_long() const
{
    using namespace std::chrono;

    auto dur_us = duration_cast<usecs>(_tp.time_since_epoch());
    int us = dur_us.count() % 1000000;

    time_t t1 = sysc::to_time_t(_tp);
    tm t2 = *std::gmtime(&t1);
    char output[100];
    size_t pos = strftime(output, 99, "%F %H:%M:%S.", &t2);
    sprintf(output + pos, "%d", us);

    return output;
}

void REngineLockable::lock()
{
    int errcode = 0;
    // this hopefully will NEVER happen!
    if (!_engine->lock(&errcode))
    {
        std::stringstream ss;
        ss << "Failed to lock REngine: " << errcode;
        throw std::runtime_error(ss.str());
    }
}

void REngineLockable::unlock()
{
    int errcode = 0;
    // this hopefully will NEVER happen!
    if (!_engine->unlock(&errcode))
    {
        std::stringstream ss;
        ss << "Failed to unlock REngine: " << errcode;
        throw std::runtime_error(ss.str());
    }
}

RString RApi::rstrcpy(const RString &rapistr)
{
    if (rapistr.iDataLen == 0)
    {
        return RString { nullptr, 0 };
    }

    RString res;

    res.pData = new char[rapistr.iDataLen + 1];
    // RApi strings are NOT null terminated!
    strncpy(res.pData, rapistr.pData, rapistr.iDataLen);
    res.iDataLen = rapistr.iDataLen;

    return res;
}

RString RApi::string_to_rstring(const std::string& str)
{
    RString res;
    res.iDataLen = str.length();
    res.pData = nullptr;

    if (!str.empty())
    {
        res.pData = new char[100];
        strcpy(res.pData, str.c_str());
    }

    return res;
}

void RApi::accinfo_cpy(const AccountInfo& accinfo, AccountInfo& res)
{
    res.sAccountId = rstrcpy(accinfo.sAccountId);
    res.sFcmId = rstrcpy(accinfo.sFcmId);
    res.sIbId = rstrcpy(accinfo.sIbId);
    res.pRmsInfo = new RApi::RmsInfo();
    res.pRmsInfo->bCheckMinAccountBalance = accinfo.pRmsInfo->bCheckMinAccountBalance;
    res.pRmsInfo->bMinMarginBalanceFlag = accinfo.pRmsInfo->bMinMarginBalanceFlag;
    res.pRmsInfo->dCashOnHand = accinfo.pRmsInfo->dCashOnHand;
    res.pRmsInfo->dCommissionFillRate = accinfo.pRmsInfo->dCommissionFillRate;
    res.pRmsInfo->dLossLimit = accinfo.pRmsInfo->dLossLimit;
    res.pRmsInfo->dMinAccountBalance = accinfo.pRmsInfo->dMinAccountBalance;
    res.pRmsInfo->dMinMarginBalance = accinfo.pRmsInfo->dMinMarginBalance;
    res.pRmsInfo->iBuyLimit = accinfo.pRmsInfo->iBuyLimit;
    res.pRmsInfo->iMaxOrderQty = accinfo.pRmsInfo->iMaxOrderQty;
    res.pRmsInfo->iSellLimit = accinfo.pRmsInfo->iSellLimit;
    res.pRmsInfo->sAlgorithm = rstrcpy(accinfo.pRmsInfo->sAlgorithm);
    res.pRmsInfo->sStatus = rstrcpy(accinfo.pRmsInfo->sStatus);
}

bool RApi::operator ==(const RApi::RString& s1, const RApi::RString& s2) {
    if (s1.iDataLen != s2.iDataLen)
        return false;
    return !strncmp(s1.pData, s2.pData, s1.iDataLen);
}

std::ostream& operator <<(std::ostream& stream, const RApi::RString& str)
{
    return stream << std::string(str.pData, str.iDataLen);
}

std::ostream& RApi::operator <<(std::ostream& stream, const LineInfo* info)
{
    RTime time(info->iSsboe, info->iUsecs);

    stream << time.to_string_long() << " ";
    stream << "OrderNum: " << info->iOrderNum << " Status: \"" <<
          info->sStatus << "\"";
    if (info->sStatus == RApi::sLINE_STATUS_COMPLETE)
    {
        stream << " (" << info->sCompletionReason << ")";
    }
    if (info->bPossOutOfOrder)
        stream << " (out of order?)";
    stream << " " << info->sOrderType << " " << info->sBuySellType <<
          " (" << info->iFilled << "/"  << info->iQuantityToFill << ") @";
    if (info->bPriceToFillFlag)
        stream << " " << info->dPriceToFill;
    if (info->bTriggerPriceFlag)
        stream << " T" << info->dTriggerPrice;
    if (info->bAvgFillPriceFlag)
        stream << " Avg: " << info->dAvgFillPrice;

    return stream;
}


std::ostream& RApi::operator <<(std::ostream& stream, const OrderFillReport* info)
{
    RTime time(info->iSsboe, info->iUsecs);

    stream << time.to_string_long() << " FillReport: ";

    stream << info->iFillSize << " @ ";

    if (!info->bFillPriceFlag)
    {
        stream << "Unknown!";
        return stream;
    }
    stream << info->dFillPrice;

    if (info->sFillType.iDataLen > 0)
    {
        stream << " FillType: " << info->sFillType;
    }

    if (info->sLiquidityIndicator.iDataLen > 0)
    {
        stream << " LiqInd: " << info->sLiquidityIndicator;
    }

    if (info->sSettlementCurrency.iDataLen > 0)
    {
        stream << " SettlementCurrency: " << info->sSettlementCurrency;
    }

    if (info->sSettlementDate.iDataLen > 0)
    {
        stream << " SettlementDate: " << info->sSettlementDate;
    }

    if (info->sTradeDate.iDataLen > 0)
    {
        stream << " TradeDate: " << info->sTradeDate;
    }

    return stream;
}


std::ostream& RApi::operator <<(std::ostream& stream, const PnlInfo* info)
{
    if (info->sTicker.iDataLen > 0)
    {
        stream << info->sTicker << "." << info->sExchange << ":";
    }
    else
    {
        stream << "Total:";
    }

    if (info->bPossOutOfOrder)
    {
        stream << " [Out of order?]";
    }
    if (info->bAccountBalance)
    {
        stream << " AccountBalance: " << info->dAccountBalance;
    }
    if (info->bMarginBalance)
    {
        stream << " MarginBalance: " << info->dMarginBalance;
    }
    if (info->bPosition)
    {
        stream << " Position: " << info->lPosition;
    }
    if (info->bOpenPnl)
    {
        stream << " OpenPnl: " << info->dOpenPnl;
    }
    if (info->bClosedPnl)
    {
        stream << " ClosedPnl: " << info->dClosedPnl;
    }
    if (info->bAvgOpenFillPrice)
    {
        stream << " AvgOpenFillPrice: " << info->dAvgOpenFillPrice;
    }

    return stream;
}

std::ostream& RApi::operator<<(std::ostream& stream, const RApi::TradeInfo* info)
{
    RTime timestamp(info->iSsboe, info->iUsecs);
    stream << "TradePrint [" << info->iType << "] " <<
        timestamp.to_string_usecs() << " " << info->sAggressorSide <<
        " " << info->iSize << " @ " << info->dPrice;
    if (info->bPercentChangeFlag)
        stream << " %change: " << info->dPercentChange;
    if (info->bNetChangeFlag)
        stream << " netchange: " << info->dNetChange;

    return stream;
}




std::ostream& RApi::operator <<(std::ostream& stream, const ProductRmsInfo* info)
{
    stream << info->sProductCode << ":";

    if (info->bMaxOrderQty)
    {
        stream << " MaxOrderQty: " << info->iMaxOrderQty;
    }
    if (info->bBuyLimit)
    {
        stream << " BuyLimit: " << info->iBuyLimit;
    }
    if (info->bBuyLongMarginRate)
    {
        stream << " BuyLongMarginRate: " << info->dBuyLongMarginRate;
    }
    if (info->bSellLimit)
    {
        stream << " SellLimit: " << info->iSellLimit;
    }
    if (info->bSellShortMarginRate)
    {
        stream << " SellShortMarginRate: " << info->dSellShortMarginRate;
    }
    if (info->bCommissionFillRate)
    {
        stream << " CommissionFillRate: " << info->dCommissionFillRate;
    }
    if (info->bLossLimit)
    {
        stream << " LossLimit: " << info->dLossLimit;
    }

    return stream;
}

std::ostream& RApi::operator<<(std::ostream& stream, const BidInfo* info)
{
    if (info->iType == RApi::MD_UPDATE_CB)
    {
        stream << "[Update]";
    }
    else if (info->iType == RApi::MD_IMAGE_CB)
    {
        stream << "[Image]";
    }
    else
    {
        stream << "[" << info->iType << "]";
    }

    stream << " " << info->sTicker << "." << info->sExchange;

    stream << " Bid:";

    stream << " Price = ";
    if (info->bPriceFlag)
        stream << info->dPrice;
    else
        stream << "undefined";

    stream << " Size = ";
    if (info->bSizeFlag)
    {
        stream << info->iSize;
        stream << " NumOrders = " << info->iNumOrders;
    }
    else
    {
        stream << "undefined";
    }

    RTime timestamp(info->iSsboe, info->iUsecs);
    stream << " TimeStamp = " << timestamp.to_string_usecs();

    stream << " UpdateType = " << info->iUpdateType;

    return stream;
}


std::ostream& RApi::operator<<(std::ostream& stream, const AskInfo* info)
{
    if (info->iType == RApi::MD_UPDATE_CB)
    {
        stream << "[Update]";
    }
    else if (info->iType == RApi::MD_IMAGE_CB)
    {
        stream << "[Image]";
    }
    else
    {
        stream << "[" << info->iType << "]";
    }

    stream << " " << info->sTicker << "." << info->sExchange;

    stream << " Ask:";

    stream << " Price = ";
    if (info->bPriceFlag)
        stream << info->dPrice;
    else
        stream << "undefined";

    stream << " Size = ";
    if (info->bSizeFlag)
    {
        stream << info->iSize;
        stream << " NumOrders = " << info->iNumOrders;
    }
    else
    {
        stream << "undefined";
    }

    RTime timestamp(info->iSsboe, info->iUsecs);
    stream << " TimeStamp = " << timestamp.to_string_usecs();

    stream << " UpdateType = " << info->iUpdateType;

    return stream;
}
