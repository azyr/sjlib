#ifndef __RAPI_H_INCL
#define __RAPI_H_INCL

/*   =====================================================================   */

#ifdef MAKING_RAPI_LIB
#include "OmneStreamEngine.h"
#else

/*   =====================================================================   */
/*                                      KIT                                  */
/*   =====================================================================   */

#define OK               (1)
#define NOT_OK           (0)

typedef struct sNCharcb
     {
     char * pData;
     int    iDataLen;
     }
     tsNCharcb;

/*   =====================================================================   */
/*                                 error codes                               */
/*   =====================================================================   */

#define API_OK                 0
#define API_OS_ERROR           1
#define API_TBL_ERROR          2
#define API_MNM_ERROR          3
#define API_MISC_ERROR         4
#define API_LL_ERROR           5
#define API_BAD_INPUT          6
#define API_NO_DATA            7
#define API_ALREADY_EXISTS     8
#define API_HANDLE_IN_USE      9
#define API_IN_PROGRESS       10
#define API_NO_HANDLE         11
#define API_OUTPUT_INHIBITED  12
#define API_PERMISSION_DENIED 13
#define API_UNKNOWN_REQUEST   14
#define API_LEX_ERROR         15
#define API_HASH_ERROR        16
#define API_IGNORED           17
#define API_HSTGRM_ERROR      18
#define API_DUO_ERROR         19
#define API_SNM_ERROR         20
#define API_TOKEN_ERROR       21
#define API_KID_ERROR         22
#define API_MINOR_ERROR       23
#define API_ENVIRONMENT_ERROR 24
#define API_LIFO_ERROR        25
#define API_SQ_ERROR          26
#define API_FSM_ERROR         27
#define API_PARSE_ERROR       28
#define API_BTREE_ERROR       29
#define API_RDM_ERROR         30
#define API_STATE_ERROR       31
#define API_IDX_ERROR         32
#define API_VEC_ERROR         33
#define API_MIME_ERROR        34
#define API_MEM_ERROR         35
#define API_MTF_ERROR         36
#define API_EC_ERROR          37
#define API_DICT_ERROR        38
#define API_TNT_ERROR         39
#define API_ATRI_ERROR        40
#define API_NHASH_ERROR       41
#define API_AM_ERROR          42
#define API_OMC_ERROR         43
#define API_NCV_ERROR         44
#define API_OV_ERROR          45
#define API_NEO_ERROR         46
#define API_ENT_ERROR         47
#define API_AMI_ERROR         48
#define API_FIX_ERROR         49
#define API_CODEC_ERROR       50
#define API_LOC_ERROR         51
#define API_LIMIT_ERROR       52
#define API_DESTROYED         53
#define API_DNS_ERROR         54
#define API_FF_ERROR          55
#define API_BIT_ERROR         56
#define API_HUFF_ERROR        57
#define API_MHASH_ERROR       58
#define API_SB_ERROR          59
#define API_TB_ERROR          60
#define API_OTHER_ERROR       61

#define API_NUM_ERROR_CODES   62

/*   =====================================================================   */
/*                                 OmneEngine                                */
/*   =====================================================================   */

class OmneException
     {
     public :

     OmneException(int iError);

     int          getErrorCode();
     const char * getErrorString();

     virtual ~OmneException();

     private :

     int PRI_iError;
     };

namespace OmneEngineSpace
{
class OmneTimerCB
     {
     public :

     virtual int call(tsNCharcb * pTimerName,
                      void *      pContext,
                      int *       aiCode) = 0;

     virtual ~OmneTimerCB()
     {
     }
     };
};

#endif                                                  /* MAKING_RAPI_LIB   */
/*   =====================================================================   */

namespace RApi
{
const int ALERT_CONNECTION_OPENED =  1;
const int ALERT_CONNECTION_CLOSED =  2;
const int ALERT_CONNECTION_BROKEN =  3;
const int ALERT_LOGIN_COMPLETE    =  4;
const int ALERT_LOGIN_FAILED      =  5;
const int ALERT_SERVICE_ERROR     =  6;
const int ALERT_FORCED_LOGOUT     =  7;
const int ALERT_QUIET_HEARTBEAT   =  8;
const int ALERT_TRADING_DISABLED  =  9;
const int ALERT_TRADING_ENABLED   = 10;
const int ALERT_SHUTDOWN_SIGNAL   = 11;

const int MARKET_DATA_CONNECTION_ID      = 1;
const int TRADING_SYSTEM_CONNECTION_ID   = 2;
const int ORDER_RELEASE_CONNECTION_ID    = 3;
const int INTRADAY_HISTORY_CONNECTION_ID = 4;
const int PNL_CONNECTION_ID              = 5;

const int MD_NONE              = 0x00;
const int MD_PRINTS            = 0x01;
const int MD_QUOTES            = 0x02;
const int MD_BEST              = 0x04;
const int MD_CLOSE             = 0x08;
const int MD_PRINTS_COND       = 0x10;
const int MD_SETTLEMENT        = 0x20;
const int MD_OPEN              = 0x40;
const int MD_MARKET_MODE       = 0x80;
const int MD_HIGH_LOW          = 0x100;
const int MD_TRADE_VOLUME      = 0x200;
const int MD_CLOSING_INDICATOR = 0x400;
const int MD_OPENING_INDICATOR = 0x800;
const int MD_OPEN_INTEREST     = 0x1000;
const int MD_ALL               = MD_PRINTS |
                                 MD_QUOTES |
                                 MD_BEST |
                                 MD_CLOSE |
                                 MD_PRINTS_COND |
                                 MD_SETTLEMENT |
                                 MD_OPEN |
                                 MD_MARKET_MODE |
                                 MD_HIGH_LOW |
                                 MD_TRADE_VOLUME |
                                 MD_CLOSING_INDICATOR |
                                 MD_OPENING_INDICATOR |
                                 MD_OPEN_INTEREST;

const int MD_IMAGE_CB   = 1;
const int MD_UPDATE_CB  = 2;
const int MD_HISTORY_CB = 3;

const int UPDATE_TYPE_UNDEFINED  = 0;
const int UPDATE_TYPE_SOLO       = 1;
const int UPDATE_TYPE_BEGIN      = 2;
const int UPDATE_TYPE_MIDDLE     = 3;
const int UPDATE_TYPE_END        = 4;
const int UPDATE_TYPE_CLEAR      = 5;
const int UPDATE_TYPE_AGGREGATED = 6;

const int OP_NONE                     = (0);
const int OP_EQUAL_TO                 = (1);
const int OP_LESS_THAN                = (2);
const int OP_GREATER_THAN             = (3);
const int OP_LESS_THAN_OR_EQUAL_TO    = (4);
const int OP_GREATER_THAN_OR_EQUAL_TO = (5);
const int OP_NOT_EQUAL_TO             = (6);
const int OP_NOT_GREATER_THAN         = (7);
const int OP_NOT_LESS_THAN            = (8);

const int BEST_ASK_PRICE = 25;
const int BEST_BID_PRICE = 22;
const int TRADE_PRICE    = 6;

const tsNCharcb sORDER_TYPE_LIMIT          = {(char *)"L",    1};
const tsNCharcb sORDER_TYPE_MARKET         = {(char *)"M",    1};
const tsNCharcb sORDER_TYPE_STOP_MARKET    = {(char *)"STP",  3};
const tsNCharcb sORDER_TYPE_STOP_LIMIT     = {(char *)"SLMT", 4};
const tsNCharcb sORDER_TYPE_MKT_IF_TOUCHED = {(char *)"MIT",  3};
const tsNCharcb sORDER_TYPE_LMT_IF_TOUCHED = {(char *)"LIT",  3};
const tsNCharcb sORDER_TYPE_EXTERNAL       = {(char *)"E",    1};

const tsNCharcb sBUY_SELL_TYPE_BUY               = {(char *)"B",   1};
const tsNCharcb sBUY_SELL_TYPE_SELL              = {(char *)"S",   1};
const tsNCharcb sBUY_SELL_TYPE_SELL_SHORT        = {(char *)"SS",  2};
const tsNCharcb sBUY_SELL_TYPE_SELL_SHORT_EXEMPT = {(char *)"SSE", 3};

const tsNCharcb sORDER_DURATION_DAY = {(char *)"DAY", 3};
const tsNCharcb sORDER_DURATION_FOK = {(char *)"FOK", 3};
const tsNCharcb sORDER_DURATION_GTC = {(char *)"GTC", 3};
const tsNCharcb sORDER_DURATION_IOC = {(char *)"OC",  2};

const tsNCharcb sRELEASE_CMD_HOLD_ORDER    = {(char *)"hold_order", 10};

const tsNCharcb sORDER_ENTRY_TYPE_AUTO   = {(char *)"A", 1};
const tsNCharcb sORDER_ENTRY_TYPE_MANUAL = {(char *)"M", 1};

/*   =====================================================================   */
/*                          order completion reasons                         */
/*   =====================================================================   */

const tsNCharcb sCOMPLETION_REASON_CANCEL  = {(char *)"C",    1};
const tsNCharcb sCOMPLETION_REASON_REJECT  = {(char *)"R",    1};
const tsNCharcb sCOMPLETION_REASON_FILL    = {(char *)"F",    1};
const tsNCharcb sCOMPLETION_REASON_FAILURE = {(char *)"FA",   2};
const tsNCharcb sCOMPLETION_REASON_UNKNOWN = {(char *)"U",    1};
const tsNCharcb sCOMPLETION_REASON_PFBC    = {(char *)"PFBC", 4};

/*   =====================================================================   */
/*                       values for LineInfo::sStatus                        */
/*   =====================================================================   */

const tsNCharcb
sLINE_STATUS_OPEN_PENDING        = {(char *)"open pending",              12};
const tsNCharcb
sLINE_STATUS_OPEN                = {(char *)"open",                       4};
const tsNCharcb
sLINE_STATUS_MOD_TRIGGER_PENDING = {(char *)"modified, trigger pending", 25};
const tsNCharcb
sLINE_STATUS_TRIGGER_PENDING     = {(char *)"trigger pending",           15};
const tsNCharcb
sLINE_STATUS_PARTIAL             = {(char *)"partial",                    7};
const tsNCharcb
sLINE_STATUS_CANCEL_PENDING      = {(char *)"cancel pending",            14};
const tsNCharcb
sLINE_STATUS_COMPLETE            = {(char *)"complete",                   8};
const tsNCharcb
sLINE_STATUS_MODIFY_PENDING      = {(char *)"modify pending",            14};
const tsNCharcb
sLINE_STATUS_MODIFIED            = {(char *)"modified",                   8};
const tsNCharcb
sLINE_STATUS_SENT_TO_ORM         = {(char *)"order sent to ORM",         17};
const tsNCharcb
sLINE_STATUS_ORM_RELEASE_PENDING = {(char *)"ORM release pending",       19};
const tsNCharcb
sLINE_STATUS_ORM_ORDER_RELEASED  = {(char *)"order released by ORM",     21};

const tsNCharcb 
sLINE_STATUS_ORDER_SENT_TO_EXCH  = {(char *)"order sent to exch",        18};
const tsNCharcb 
sLINE_STATUS_CANCEL_SENT_TO_EXCH = {(char *)"cancel sent to exch",       19};
const tsNCharcb 
sLINE_STATUS_MODIFY_SENT_TO_EXCH = {(char *)"modify sent to exch",       19};

const tsNCharcb 
sLINE_STATUS_ORDER_RCVD_BY_EXCH_GWAY  = {(char *)"order received by exch gateway",  30};
const tsNCharcb 
sLINE_STATUS_CANCEL_RCVD_BY_EXCH_GWAY = {(char *)"cancel received by exch gateway", 31};
const tsNCharcb 
sLINE_STATUS_MODIFY_RCVD_BY_EXCH_GWAY = {(char *)"modify received by exch gateway", 31};

/*   =====================================================================   */
/*                             order statuses by OM                          */
/*   =====================================================================   */

const tsNCharcb
sLINE_STATUS_ORDER_RECEIVED  = {(char *)"Order received from client",  26};
const tsNCharcb
sLINE_STATUS_MODIFY_RECEIVED = {(char *)"Modify received from client", 27};
const tsNCharcb
sLINE_STATUS_CANCEL_RECEIVED = {(char *)"Cancel received from client", 27};
const tsNCharcb
sLINE_STATUS_MODIFY_FAILED   = {(char *)"Modification Failed",         19};
const tsNCharcb
sLINE_STATUS_CANCEL_FAILED   = {(char *)"Cancellation Failed",         19};

/*   =====================================================================   */
/*                           callback info classes                           */
/*   =====================================================================   */

class AccountInfo;
class AccountListInfo;
class AlertInfo;
class AskInfo;
class BidInfo;
class ClosePriceInfo;
class ClosingIndicatorInfo;
class EndQuoteInfo;
class EquityOptionListInfo;
class EquityOptionStrategyListInfo;
class ExchangeListInfo;
class ExecutionReplayInfo;
class HighPriceInfo;
class IndicatorData;
class IndicatorInfo;
class IndicatorListInfo;
class IndicatorReplayInfo;
class LimitOrderBookInfo;
class LineInfo;
class LowPriceInfo;
class MarketModeInfo;
class OpenInterestInfo;
class OpenPriceInfo;
class OpeningIndicatorInfo;
class OptionListInfo;
class OrderReplayInfo;
class PasswordChangeInfo;
class PnlInfo;
class PnlReplayInfo;
class PriceIncrInfo;
class PriceIncrRow;
class ProductRmsInfo;
class ProductRmsListInfo;
class RefDataInfo;
class RmsInfo;
class SettlementPriceInfo;
class StrategyInfo;
class StrategyLegInfo;
class StrategyListInfo;
class TimeBarInfo;
class TimeBarReplayInfo;
class TradeInfo;
class TradeReplayInfo;
class TradeVolumeInfo;

class SodReport;

/* order reports */

class OrderReport;
class OrderBustReport;
class OrderCancelReport;
class OrderFailureReport;
class OrderFillReport;
class OrderModifyReport;
class OrderNotCancelledReport;
class OrderNotModifiedReport;
class OrderRejectReport;
class OrderStatusReport;
class OrderTradeCorrectReport;
class OrderTriggerPulledReport;
class OrderTriggerReport;

/*   =====================================================================   */
/*                           parameter info classes                          */
/*   =====================================================================   */

class OrderParams;
class LimitOrderParams;
class MarketOrderParams;
class StopLimitOrderParams;
class StopMarketOrderParams;

class ModifyLimitOrderParams;
class ModifyStopLimitOrderParams;
class ModifyStopMarketOrderParams;
class ModifyOrderParams;

/*   =====================================================================   */
/*                                working classes                            */
/*   =====================================================================   */

class AdmCallbacks;
class REngineParams;
class RCallbacks;
class REngine;
class LoginParams;

class RIndicatorCallbacks;
class RIndicatorConn;

/*   =====================================================================   */
/*                           callback info classes                           */
/*   =====================================================================   */

class AccountInfo
     {
     public :
     AccountInfo();
     virtual ~AccountInfo();

     tsNCharcb sFcmId;
     tsNCharcb sIbId;
     tsNCharcb sAccountId;

     RmsInfo * pRmsInfo;

     int clearHandles(int * aiCode);
     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class AccountListInfo
     {
     public :
     AccountListInfo();
     virtual ~AccountListInfo();

     AccountInfo * asAccountInfoArray;
     int           iArrayLen;
     int           iRpCode;
     tsNCharcb     sRpCode;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class AlertInfo
     {
     public :
     AlertInfo();
     virtual ~AlertInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;
     tsNCharcb sMessage;
     int       iAlertType;
     int       iConnectionId;
     int       iRpCode;
     tsNCharcb sRpCode;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class AskInfo
     {
     public :
     AskInfo();
     virtual ~AskInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;
     double    dPrice;
     bool      bPriceFlag;
     int       iSize;
     bool      bSizeFlag;
     int       iNumOrders;

     int       iUpdateType;

     int       iType;

     int       iSsboe;
     int       iUsecs;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class BidInfo
     {
     public :
     BidInfo();
     virtual ~BidInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;
     double    dPrice;
     bool      bPriceFlag;
     int       iSize;
     bool      bSizeFlag;
     int       iNumOrders;

     int       iUpdateType;

     int       iType;

     int       iSsboe;
     int       iUsecs;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class ClosePriceInfo
     {
     public :
     ClosePriceInfo();
     virtual ~ClosePriceInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;
     double    dPrice;
     bool      bPriceFlag;

     int       iType;

     int       iSsboe;
     int       iUsecs;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class ClosingIndicatorInfo
     {
     public :
     ClosingIndicatorInfo();
     virtual ~ClosingIndicatorInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;
     double    dPrice;
     bool      bPriceFlag;

     int       iType;

     int       iSsboe;
     int       iUsecs;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class EndQuoteInfo
     {
     public :
     EndQuoteInfo();
     virtual ~EndQuoteInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;

     int       iUpdateType;

     int       iType;

     int       iSsboe;
     int       iUsecs;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class EquityOptionListInfo
     {
     public :
     EquityOptionListInfo();
     virtual ~EquityOptionListInfo();

     virtual int clearHandles(int * aiCode);
     int dump(int * aiCode);

     tsNCharcb *   pUnderlyingArray;
     int           iUnderlyingArrayLen;
     tsNCharcb *   pExchangeArray;
     int           iExchangeArrayLen;
     tsNCharcb *   pExpirationArray;
     int           iExpirationArrayLen;
     RefDataInfo * asRefDataInfoArray;
     int           iArrayLen;

     int           iRpCode;
     tsNCharcb     sRpCode;

     void *        pContext;

     private :
     };

/*   =====================================================================   */

class EquityOptionStrategyListInfo
     {
     public :
     EquityOptionStrategyListInfo();
     virtual ~EquityOptionStrategyListInfo();

     virtual int clearHandles(int * aiCode);
     int dump(int * aiCode);

     tsNCharcb *   pExchangeArray;
     int           iExchangeArrayLen;
     tsNCharcb *   pUnderlyingArray;
     int           iUnderlyingArrayLen;
     tsNCharcb *   pStrategyTypeArray;
     int           iStrategyTypeArrayLen;
     tsNCharcb *   pExpirationArray;
     int           iExpirationArrayLen;
     tsNCharcb *   pTickerArray;
     int           iTickerArrayLen;

     int           iRpCode;

     void *        pContext;

     private :
     };

/*   =====================================================================   */

class ExchangeListInfo
     {
     public :
     ExchangeListInfo();
     virtual ~ExchangeListInfo();

     tsNCharcb * asExchangeArray;
     int         iArrayLen;
     int         iRpCode;
     tsNCharcb   sRpCode;

     void *      pContext;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class ExecutionReplayInfo
     {
     public :
     ExecutionReplayInfo();
     virtual ~ExecutionReplayInfo();

     AccountInfo       oAccount;

     OrderFillReport * asFillReportArray;
     int               iArrayLen;
     int               iRpCode;
     tsNCharcb         sRpCode;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class HighPriceInfo
     {
     public :
     HighPriceInfo();
     virtual ~HighPriceInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;
     double    dPrice;
     bool      bPriceFlag;

     int       iType;

     int       iSsboe;
     int       iUsecs;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class IndicatorData
     {
     public :
     IndicatorData();
     virtual ~IndicatorData();

     int       iFieldId;
     tsNCharcb sData;
     };

class IndicatorInfo
     {
     public :
     IndicatorInfo();
     virtual ~IndicatorInfo();

     tsNCharcb       sSource;
     tsNCharcb       sIndicator;
     tsNCharcb       sSymbol;
     int             iSsboe;
     int             iType;

     IndicatorData * pDataArray;
     int             iArrayLen;

     void *          pContext;

     int clearHandles(int * aiCode);
     int dump(int * aiCode);

     private :
     };

class IndicatorListInfo
     {
     public :
     IndicatorListInfo();
     virtual ~IndicatorListInfo();

     virtual int clearHandles(int * aiCode);
     int dump(int * aiCode);

     tsNCharcb   sSource;

     tsNCharcb * pIndicatorArray;
     tsNCharcb * pDescriptionArray;
     int         iArrayLen;

     void *      pContext;

     int         iRpCode;
     tsNCharcb   sRpCode;

     private :
     };

/*   =====================================================================   */

class IndicatorReplayInfo
     {
     public :
     IndicatorReplayInfo();
     virtual ~IndicatorReplayInfo();

     tsNCharcb sSource;
     tsNCharcb sIndicator;
     tsNCharcb sSymbol;

     int       iStartSsboe;
     int       iEndSsboe;

     void *    pContext;

     int       iRpCode;
     tsNCharcb sRpCode;

     int clearHandles(int * aiCode);
     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class LimitOrderBookInfo
     {
     public :
     LimitOrderBookInfo();
     virtual ~LimitOrderBookInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;

     double *  adAskPriceArray;
     int *     aiAskSizeArray;
     int *     aiAskNumOrdersArray;
     int *     aiAskSsboeArray;
     int *     aiAskUsecsArray;
     int       iAskArrayLen;

     double *  adBidPriceArray;
     int *     aiBidSizeArray;
     int *     aiBidNumOrdersArray;
     int *     aiBidSsboeArray;
     int *     aiBidUsecsArray;
     int       iBidArrayLen;

     int       iType;

     int       iRpCode;
     tsNCharcb sRpCode;

     int       iSsboe;
     int       iUsecs;

     int clearHandles(int * aiCode);
     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class LineInfo
     {
     public :
     LineInfo();
     virtual ~LineInfo();

     AccountInfo oAccount;

     tsNCharcb   sTicker;
     tsNCharcb   sExchange;

     int         iOrderNum;
     tsNCharcb   sInitialSequenceNumber;
     tsNCharcb   sCurrentSequenceNumber;
     tsNCharcb   sOmnibusAccount;

     tsNCharcb   sOrderType;
     tsNCharcb   sBuySellType;
     tsNCharcb   sOrderDuration;
     tsNCharcb   sEntryType;

     tsNCharcb   sTradeRoute;
     tsNCharcb   sRoutingInstructions;

     tsNCharcb   sReleaseCommand;
     bool        bReleaseSsboe;
     int         iReleaseSsboe;
     bool        bReleaseUsecs;
     int         iReleaseUsecs;

     tsNCharcb   sStatus;
     tsNCharcb   sCompletionReason;
     tsNCharcb   sText;

     tsNCharcb   sTag;
     tsNCharcb   sUserMsg;
     void *      pContext;

     tsNCharcb   sUser;

     int         iSsboe;
     int         iUsecs;

     int         iQuantityToFill;
     int         iMinQty;
     int         iMaxShowQty;
     int         iFilled;
     int         iUnfilled;
     int         iCancelled;

     int         iReleasePendingSize;
     int         iCancelPendingSize;
     int         iModifyPendingSize;

     double      dPriceToFill;
     bool        bPriceToFillFlag;
     double      dAvgFillPrice;
     bool        bAvgFillPriceFlag;
     double      dTriggerPrice;
     bool        bTriggerPriceFlag;

     tsNCharcb   sTriggerTicker;
     tsNCharcb   sTriggerExchange;
     int         iTriggerPriceId;
     int         iTriggerCmpOperator;

     bool        bPossOutOfOrder;

     int         iRpCode;
     tsNCharcb   sRpCode;

     int clearHandles(int * aiCode);
     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class LowPriceInfo
     {
     public :
     LowPriceInfo();
     virtual ~LowPriceInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;
     double    dPrice;
     bool      bPriceFlag;

     int       iType;

     int       iSsboe;
     int       iUsecs;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class MarketModeInfo
     {
     public :
     MarketModeInfo();
     virtual ~MarketModeInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;
     tsNCharcb sMarketMode;

     int       iType;

     int       iSsboe;
     int       iUsecs;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class OpenInterestInfo
     {
     public :
     OpenInterestInfo();
     virtual ~OpenInterestInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;
     int       iQuantity;
     bool      bQuantityFlag;

     int       iType;

     int       iSsboe;
     int       iUsecs;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class OpenPriceInfo
     {
     public :
     OpenPriceInfo();
     virtual ~OpenPriceInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;
     double    dPrice;
     bool      bPriceFlag;

     int       iType;

     int       iSsboe;
     int       iUsecs;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class OpeningIndicatorInfo
     {
     public :
     OpeningIndicatorInfo();
     virtual ~OpeningIndicatorInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;
     double    dPrice;
     bool      bPriceFlag;

     int       iType;

     int       iSsboe;
     int       iUsecs;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class OptionListInfo
     {
     public :
     OptionListInfo();
     virtual ~OptionListInfo();

     virtual int clearHandles(int * aiCode);
     int dump(int * aiCode);

     tsNCharcb *   pExchangeArray;
     int           iExchangeArrayLen;
     tsNCharcb *   pProductCodeArray;
     int           iProductCodeArrayLen;
     tsNCharcb *   pExpirationCCYYMMArray;
     int           iExpirationCCYYMMArrayLen;
     RefDataInfo * asRefDataInfoArray;
     int           iArrayLen;

     int           iRpCode;
     tsNCharcb     sRpCode;

     void *        pContext;

     private :
     };

/*   =====================================================================   */

class OrderReplayInfo
     {
     public :
     OrderReplayInfo();
     virtual ~OrderReplayInfo();

     AccountInfo oAccount;

     LineInfo *  asLineInfoArray;
     int         iArrayLen;
     int         iRpCode;
     tsNCharcb   sRpCode;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class PasswordChangeInfo
     {
     public :
     PasswordChangeInfo();
     virtual ~PasswordChangeInfo();

     int         iRpCode;
     tsNCharcb   sRpCode;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class PnlInfo
     {
     public :
     PnlInfo();
     virtual ~PnlInfo();

     AccountInfo oAccount;

     tsNCharcb   sTicker;
     tsNCharcb   sExchange;

     bool        bOpenPnl;
     double      dOpenPnl;

     bool        bClosedPnl;
     double      dClosedPnl;

     bool        bAccountBalance;
     double      dAccountBalance;

     bool        bMarginBalance;
     double      dMarginBalance;

     bool        bPosition;
     long        lPosition;

     bool        bAvgOpenFillPrice;
     double      dAvgOpenFillPrice;

     bool        bPossOutOfOrder;

     int clearHandles(int * aiCode);
     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class PnlReplayInfo
     {
     public :
     PnlReplayInfo();
     virtual ~PnlReplayInfo();

     AccountInfo oAccount;

     PnlInfo *   asPnlInfoArray;
     int         iArrayLen;
     int         iRpCode;
     tsNCharcb   sRpCode;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class PriceIncrInfo
     {
     public :
     PriceIncrInfo();
     virtual ~PriceIncrInfo();

     /*   ----------------------------------------------------------------   */

     tsNCharcb sExchange;
     tsNCharcb sTicker;

     /*   ----------------------------------------------------------------   */

     int            iArrayLen;
     PriceIncrRow * asPriceIncrArray;

     /*   ----------------------------------------------------------------   */

     int         iRpCode;
     tsNCharcb   sRpCode;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class PriceIncrRow
     {
     public :
     PriceIncrRow();
     virtual ~PriceIncrRow();

     /*   ----------------------------------------------------------------   */

     double    dPriceIncr;
     int       iPrecision;          /* double-to-string conversion precision */

     int       iFirstOperator;
     double    dFirstPrice;

     int       iLastOperator;
     double    dLastPrice;

     /*   ----------------------------------------------------------------   */

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class ProductRmsInfo
     {
     public :
     ProductRmsInfo();
     virtual ~ProductRmsInfo();

     /*   ----------------------------------------------------------------   */

     AccountInfo oAccount;
     tsNCharcb   sProductCode;

     bool        bBuyLimit;
     int         iBuyLimit;

     bool        bSellLimit;
     int         iSellLimit;

     bool        bLossLimit;
     double      dLossLimit;

     bool        bMaxOrderQty;
     int         iMaxOrderQty;

     bool        bCommissionFillRate;
     double      dCommissionFillRate;

     bool        bBuyLongMarginRate;
     double      dBuyLongMarginRate;

     bool        bSellShortMarginRate;
     double      dSellShortMarginRate;

     /*   ----------------------------------------------------------------   */

     int clearHandles(int * aiCode);
     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class ProductRmsListInfo
     {
     public :
     ProductRmsListInfo();
     virtual ~ProductRmsListInfo();

     ProductRmsInfo * asProductRmsInfoArray;
     int              iArrayLen;
     int              iRpCode;
     tsNCharcb        sRpCode;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class RefDataInfo
     {
     public :
     RefDataInfo();
     virtual ~RefDataInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;
     tsNCharcb sDescription;
     tsNCharcb sExpiration;
     tsNCharcb sProductCode;
     tsNCharcb sInstrumentType;
     tsNCharcb sPutCallIndicator;
     tsNCharcb sUnderlying;

     bool      bSinglePointValue;
     double    dSinglePointValue;
     tsNCharcb sCurrency;

     bool      bStrikePrice;
     double    dStrikePrice;

     int       iSsboe;

     int       iRpCode;
     tsNCharcb sRpCode;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class RmsInfo
     {
     public :
     RmsInfo();
     virtual ~RmsInfo();

     tsNCharcb   sStatus;

     int         iBuyLimit;
     int         iSellLimit;
     int         iMaxOrderQty;

     double      dCommissionFillRate;
     double      dMinAccountBalance;
     double      dLossLimit;
     double      dCashOnHand;

     bool        bCheckMinAccountBalance;

     bool        bMinMarginBalanceFlag;
     double      dMinMarginBalance;

     tsNCharcb   sAlgorithm;

     int clearHandles(int * aiCode);
     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class SettlementPriceInfo
     {
     public :
     SettlementPriceInfo();
     virtual ~SettlementPriceInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;
     double    dPrice;
     bool      bPriceFlag;
     tsNCharcb sPriceType;
     tsNCharcb sDate;

     int       iType;

     int       iSsboe;
     int       iUsecs;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class TimeBarInfo
     {
     public :
     TimeBarInfo();
     virtual ~TimeBarInfo();

     int dump(int * aiCode);

     tsNCharcb sExchange;
     tsNCharcb sTicker;

     int iSsboe;
     int iPeriod;
     int iVolume;
     int iNumTrades;                                        /* can be zero   */

     /* open */
     double dOpenPrice;
     int    iOpenSize;

     bool   bOpenBestBid;
     double dOpenBestBidPrice;
     int    iOpenBestBidSize;

     bool   bOpenBestAsk;
     double dOpenBestAskPrice;
     int    iOpenBestAskSize;

     /* high */
     double dHighPrice;
     int    iHighVolume;
     int    iHighNumTrades;

     /* low */
     double dLowPrice;
     int    iLowVolume;
     int    iLowNumTrades;

     /* close */
     double dClosePrice;
     int    iCloseSize;

     bool   bCloseBestBid;
     double dCloseBestBidPrice;
     int    iCloseBestBidSize;

     bool   bCloseBestAsk;
     double dCloseBestAskPrice;
     int    iCloseBestAskSize;

     void * pContext;
     };

/*   =====================================================================   */

class StrategyLegInfo
     {
     public :
     StrategyLegInfo();
     virtual ~StrategyLegInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;
     tsNCharcb sProductCode;
     tsNCharcb sInstrumentType;

     int       iRatio;

     int clearHandles(int * aiCode);
     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class StrategyInfo
     {
     public :
     StrategyInfo();
     virtual ~StrategyInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;
     tsNCharcb sProductCode;
     tsNCharcb sType;

     StrategyLegInfo * asLegArray;
     int               iLegArrayLen;

     void *    pContext;

     int       iRpCode;
     tsNCharcb sRpCode;

     int clearHandles(int * aiCode);
     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class StrategyListInfo
     {
     public :
     StrategyListInfo();
     virtual ~StrategyListInfo();

     virtual int clearHandles(int * aiCode);
     int dump(int * aiCode);

     tsNCharcb *   pExchangeArray;
     int           iExchangeArrayLen;
     tsNCharcb *   pProductCodeArray;
     int           iProductCodeArrayLen;
     tsNCharcb *   pStrategyTypeArray;
     int           iStrategyTypeArrayLen;
     tsNCharcb *   pExpirationCCYYMMArray;
     int           iExpirationCCYYMMArrayLen;
     tsNCharcb *   pTickerArray;
     int           iTickerArrayLen;

     int           iRpCode;
     tsNCharcb     sRpCode;

     void *        pContext;

     private :
     };

/*   =====================================================================   */

class TimeBarReplayInfo
     {
     public :
     TimeBarReplayInfo();
     virtual ~TimeBarReplayInfo();

     tsNCharcb sExchange;
     tsNCharcb sTicker;

     int       iStartSsboe;
     int       iEndSsboe;

     void *    pContext;

     int       iRpCode;
     tsNCharcb sRpCode;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class TradeInfo
     {
     public :
     TradeInfo();
     virtual ~TradeInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;
     double    dPrice;
     bool      bPriceFlag;
     int       iSize;

     double    dNetChange;
     bool      bNetChangeFlag;
     double    dPercentChange;
     bool      bPercentChangeFlag;

     tsNCharcb sAggressorSide;
     tsNCharcb sCondition;

     int       iType;

     int       iSourceSsboe;
     int       iSourceUsecs;

     int       iSsboe;
     int       iUsecs;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class TradeReplayInfo
     {
     public :
     TradeReplayInfo();
     virtual ~TradeReplayInfo();

     tsNCharcb   sExchange;
     tsNCharcb   sTicker;

     int         iStartSsboe;
     int         iEndSsboe;

     int         iRpCode;
     tsNCharcb   sRpCode;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */

class TradeVolumeInfo
     {
     public :
     TradeVolumeInfo();
     virtual ~TradeVolumeInfo();

     tsNCharcb sTicker;
     tsNCharcb sExchange;

     bool      bTotalVolumeFlag;
     int       iTotalVolume;

     int       iType;

     int       iSsboe;
     int       iUsecs;

     int dump(int * aiCode);

     private :
     };

/*   =====================================================================   */
/*   Reports                                                                 */
/*   =====================================================================   */

class SodReport
     {
     public :
     SodReport();
     virtual ~SodReport();

     AccountInfo oAccount;

     tsNCharcb   sTicker;
     tsNCharcb   sExchange;

     double      dPrevClosePrice;

     long        lCarriedSize;

     int         iSsboe;

     tsNCharcb   sReportType;

     int clearHandles(int * aiCode);
     int dump(int * aiCode);
     };

/*   =====================================================================   */

class OrderReport
     {
     public :
     OrderReport();
     virtual ~OrderReport();

     AccountInfo oAccount;

     tsNCharcb   sTicker;
     tsNCharcb   sExchange;

     int         iOrderNum;
     tsNCharcb   sInitialSequenceNumber;
     tsNCharcb   sCurrentSequenceNumber;
     tsNCharcb   sExchOrdId;

     tsNCharcb   sOmnibusAccount;
     tsNCharcb   sPositionDisposition;

     tsNCharcb   sOrderType;
     tsNCharcb   sBuySellType;
     tsNCharcb   sOrderDuration;
     tsNCharcb   sEntryType;

     double      dPriceToFill;
     bool        bPriceToFillFlag;
     double      dTriggerPrice;
     bool        bTriggerPriceFlag;

     tsNCharcb   sTriggerTicker;
     tsNCharcb   sTriggerExchange;
     int         iTriggerCmpOperator;
     int         iTriggerPriceId;

     int         iTotalFilled;
     int         iTotalUnfilled;

     double      dAvgFillPrice;
     bool        bAvgFillPriceFlag;

     tsNCharcb   sReportId;
     tsNCharcb   sReportType;
     tsNCharcb   sText;

     tsNCharcb   sTag;
     tsNCharcb   sUserMsg;
     void *      pContext;

     tsNCharcb   sUser;

     bool        bPossOutOfOrder;
     int         iConnId;

     int         iSsboe;
     int         iUsecs;

     virtual int clearHandles(int * aiCode);
     virtual int dump(int * aiCode);

     private :
     };

class OrderBustReport : public OrderReport
     {
     public :
     OrderBustReport();
     virtual ~OrderBustReport();

     double    dFillPrice;
     bool      bFillPriceFlag;
     int       iFillSize;
     tsNCharcb sFillType;

     tsNCharcb sTradeDate;

     tsNCharcb sSettlementDate;
     tsNCharcb sSettlementCurrency;

     int dump(int * aiCode);
     };

class OrderCancelReport : public OrderReport
     {
     public :
     OrderCancelReport();
     virtual ~OrderCancelReport();

     int       iCancelledSize;

     int dump(int * aiCode);
     };

class OrderFailureReport : public OrderReport
     {
     public :
     OrderFailureReport();
     virtual ~OrderFailureReport();

     int       iCancelledSize;
     tsNCharcb sStatus;

     int dump(int * aiCode);
     };

class OrderFillReport : public OrderReport
     {
     public :
     OrderFillReport();
     virtual ~OrderFillReport();

     double    dFillPrice;
     bool      bFillPriceFlag;
     int       iFillSize;
     tsNCharcb sFillType;

     tsNCharcb sTradeDate;

     tsNCharcb sSettlementDate;
     tsNCharcb sSettlementCurrency;

     tsNCharcb sLiquidityIndicator;

     int       iRpCode;
     tsNCharcb sRpCode;

     int clearHandles(int * aiCode);
     int dump(int * aiCode);
     };

class OrderModifyReport : public OrderReport
     {
     public :
     OrderModifyReport();
     virtual ~OrderModifyReport();

     int       iNewSize;

     int dump(int * aiCode);
     };

class OrderNotCancelledReport : public OrderReport
     {
     public :
     OrderNotCancelledReport();
     virtual ~OrderNotCancelledReport();

     int       iNotCancelledSize;

     int dump(int * aiCode);
     };

class OrderNotModifiedReport : public OrderReport
     {
     public :
     OrderNotModifiedReport();
     virtual ~OrderNotModifiedReport();

     int       iNotModifiedSize;

     int dump(int * aiCode);
     };

class OrderRejectReport : public OrderReport
     {
     public :
     OrderRejectReport();
     virtual ~OrderRejectReport();

     int       iRejectedSize;

     int dump(int * aiCode);
     };

class OrderStatusReport : public OrderReport
     {
     public :
     OrderStatusReport();
     virtual ~OrderStatusReport();

     int       iConfirmedSize;

     int dump(int * aiCode);
     };

class OrderTradeCorrectReport : public OrderReport
     {
     public :
     OrderTradeCorrectReport();
     virtual ~OrderTradeCorrectReport();

     double    dFillPrice;
     bool      bFillPriceFlag;
     int       iFillSize;
     tsNCharcb sFillType;

     tsNCharcb sTradeDate;

     tsNCharcb sSettlementDate;
     tsNCharcb sSettlementCurrency;

     int dump(int * aiCode);
     };

class OrderTriggerPulledReport : public OrderReport
     {
     public :
     OrderTriggerPulledReport();
     virtual ~OrderTriggerPulledReport();

     int dump(int * aiCode);
     };

class OrderTriggerReport : public OrderReport
     {
     public :
     OrderTriggerReport();
     virtual ~OrderTriggerReport();

     int       iConfirmedSize;

     int dump(int * aiCode);
     };

/*   =====================================================================   */
/*                       order parameter info classes                        */
/*   =====================================================================   */

class OrderParams
     {
     public :
     OrderParams();
     OrderParams(LimitOrderParams * pParamsIn);
     OrderParams(MarketOrderParams * pParamsIn);
     OrderParams(StopLimitOrderParams * pParamsIn);
     OrderParams(StopMarketOrderParams * pParamsIn);
     virtual ~OrderParams();

     int clearHandles(int * aiCode);

     AccountInfo * pAccount;

     tsNCharcb     sExchange;
     tsNCharcb     sTicker;

     tsNCharcb     sBuySellType;                     /* B/S                  */
     tsNCharcb     sOrderType;                       /* L/M/SLMT/STP/MIT/LIT */
     tsNCharcb     sDuration;                        /* DAY/FOK/GTC/OC       */
     tsNCharcb     sEntryType;                       /* A/M                  */

     int           iQty;
     bool          bMinQty;
     int           iMinQty;
     bool          bMaxShowQty;
     int           iMaxShowQty;

     double        dPrice;                           /* L/SLMT/LIT           */
     double        dTriggerPrice;                    /* SLMT/STP/MIT/LIT     */

     tsNCharcb     sTriggerExchange;                 /* MIT/LIT              */
     tsNCharcb     sTriggerTicker;                   /* MIT/LIT              */
     int           iTriggerPriceId;                  /* MIT/LIT              */
     int           iTriggerCmpOperator;              /* MIT/LIT              */

     tsNCharcb     sTradeRoute;                      /*                      */
     tsNCharcb     sRoutingInstructions;             /*                      */

     tsNCharcb     sReleaseCommand;                  /* hold_order           */

     bool          bReleaseSsboe;
     int           iReleaseSsboe;
     bool          bReleaseUsecs;
     int           iReleaseUsecs;

     tsNCharcb     sTag;
     tsNCharcb     sUserMsg;
     void *        pContext;

     private :
     };

/*   =====================================================================   */

class LimitOrderParams
     {
     public :
     LimitOrderParams();
     virtual ~LimitOrderParams();

     AccountInfo * pAccount;

     tsNCharcb     sExchange;
     tsNCharcb     sTicker;

     tsNCharcb     sBuySellType;
     tsNCharcb     sDuration;
     tsNCharcb     sEntryType;

     int           iQty;
     double        dPrice;

     tsNCharcb     sTradeRoute;
     tsNCharcb     sRoutingInstructions;

     tsNCharcb     sTag;
     tsNCharcb     sUserMsg;
     void *        pContext;

     int clearHandles(int * aiCode);

     private :
     };

/*   =====================================================================   */

class MarketOrderParams
     {
     public :
     MarketOrderParams();
     virtual ~MarketOrderParams();

     AccountInfo * pAccount;

     tsNCharcb     sExchange;
     tsNCharcb     sTicker;

     tsNCharcb     sBuySellType;
     tsNCharcb     sDuration;
     tsNCharcb     sEntryType;

     int           iQty;

     tsNCharcb     sTradeRoute;
     tsNCharcb     sRoutingInstructions;

     tsNCharcb     sTag;
     tsNCharcb     sUserMsg;
     void *        pContext;

     int clearHandles(int * aiCode);

     private :
     };

/*   =====================================================================   */

class StopLimitOrderParams : public LimitOrderParams
     {
     public :
     StopLimitOrderParams();
     virtual ~StopLimitOrderParams();

     double    dTriggerPrice;

     int clearHandles(int * aiCode);

     private :
     };

/*   =====================================================================   */

class StopMarketOrderParams : public MarketOrderParams
     {
     public :
     StopMarketOrderParams();
     virtual ~StopMarketOrderParams();

     double    dTriggerPrice;

     int clearHandles(int * aiCode);

     private :
     };

/*   =====================================================================   */

class ModifyOrderParams
     {
     public :
     ModifyOrderParams();
     ModifyOrderParams(ModifyLimitOrderParams * pParamsIn);
     ModifyOrderParams(ModifyStopLimitOrderParams * pParamsIn);
     ModifyOrderParams(ModifyStopMarketOrderParams * pParamsIn);
     virtual ~ModifyOrderParams();

     int clearHandles(int * aiCode);

     AccountInfo * pAccount;

     tsNCharcb     sExchange;
     tsNCharcb     sTicker;
     int           iOrderNum;

     tsNCharcb     sOrderType;
     tsNCharcb     sDuration;
     tsNCharcb     sEntryType;

     bool          bQty;
     int           iQty;
     bool          bMinQty;
     int           iMinQty;

     double        dPrice;
     bool          bPrice;
     double        dTriggerPrice;
     bool          bTriggerPrice;

     tsNCharcb     sTriggerExchange;
     tsNCharcb     sTriggerTicker;
     bool          bTriggerPriceId;
     int           iTriggerPriceId;
     bool          bTriggerCmpOperator;
     int           iTriggerCmpOperator;

     tsNCharcb     sUserMsg;
     void *        pContext;

     private :
     };

/*   =====================================================================   */

class ModifyLimitOrderParams
     {
     public :
     ModifyLimitOrderParams();
     virtual ~ModifyLimitOrderParams();

     int clearHandles(int * aiCode);

     AccountInfo * pAccount;

     tsNCharcb     sExchange;
     tsNCharcb     sTicker;
     tsNCharcb     sEntryType;
     int           iOrderNum;

     int           iQty;
     double        dPrice;

     tsNCharcb     sUserMsg;
     void *        pContext;

     private :
     };

/*   =====================================================================   */

class ModifyStopLimitOrderParams
     {
     public :
     ModifyStopLimitOrderParams();
     virtual ~ModifyStopLimitOrderParams();

     int clearHandles(int * aiCode);

     AccountInfo * pAccount;

     tsNCharcb     sExchange;
     tsNCharcb     sTicker;
     tsNCharcb     sEntryType;
     int           iOrderNum;

     int           iQty;
     double        dPrice;
     double        dTriggerPrice;

     tsNCharcb     sUserMsg;
     void *        pContext;

     private :
     };

/*   =====================================================================   */

class ModifyStopMarketOrderParams
     {
     public :
     ModifyStopMarketOrderParams();
     virtual ~ModifyStopMarketOrderParams();

     int clearHandles(int * aiCode);

     AccountInfo * pAccount;

     tsNCharcb     sExchange;
     tsNCharcb     sTicker;
     tsNCharcb     sEntryType;
     int           iOrderNum;

     int           iQty;
     double        dTriggerPrice;

     tsNCharcb     sUserMsg;
     void *        pContext;

     private :
     };

/*   =====================================================================   */
/*                    engine and login parameter info classes                */
/*   =====================================================================   */

class REngineParams
     {
     public :

     REngineParams();
     virtual ~REngineParams();

     tsNCharcb sAppName;
     tsNCharcb sAppVersion;

     tsNCharcb sAdmCnnctPt;
     tsNCharcb sLogFilePath;
     char * *  envp;
     void *    pContext;

     AdmCallbacks * pAdmCallbacks;

     private :
     };

/*   =====================================================================   */

class LoginParams
     {
     public :

     LoginParams();
     virtual ~LoginParams();

     tsNCharcb sUser;
     tsNCharcb sPassword;

     tsNCharcb sIhCnnctPt;
     tsNCharcb sMdCnnctPt;
     tsNCharcb sPnlCnnctPt;
     tsNCharcb sTsCnnctPt;

     RCallbacks * pCallbacks;

     private :
     };

/*   =====================================================================   */
/*                                working classes                            */
/*   =====================================================================   */

class RIndicatorCallbacks
     {
     public :
     virtual ~RIndicatorCallbacks();

     /*   ----------------------------------------------------------------   */

     virtual int Alert(AlertInfo * pInfo,
                       int *       aiCode) = 0;

     virtual int Indicator(IndicatorInfo * pInfo,
                           int *           aiCode) = 0;

     virtual int IndicatorReplay(IndicatorReplayInfo * pInfo,
				 int *                 aiCode) = 0;

     virtual int IndicatorList(IndicatorListInfo * pInfo,
			       int *               aiCode) = 0;

     /*   ----------------------------------------------------------------   */

     private :
     };

/*   =====================================================================   */

class RIndicatorConn
     {
     public :
     RIndicatorConn(REngine * pREngine);
     virtual ~RIndicatorConn();

     /*   ----------------------------------------------------------------   */

     int login(tsNCharcb *           pCnnctPt,
	       tsNCharcb *           pSource,
	       tsNCharcb *           pUser,
	       tsNCharcb *           pPassword,
	       RIndicatorCallbacks * pCallbacks,
	       int *                 aiCode);

     int logout(int * aiCode);

     /*   ----------------------------------------------------------------   */

     int listIndicators(tsNCharcb * pSource,
			void *      pContext,
			int *       aiCode);

     int replayIndicator(tsNCharcb * pSource,
			 tsNCharcb * pIndicator,
			 tsNCharcb * pSymbol,
			 int         iStartSsboe,
			 int         iEndSsboe,
			 void *      pContext,
			 int *       aiCode);

     int subscribeIndicator(tsNCharcb * pSource,
			    tsNCharcb * pIndicator,
			    tsNCharcb * pSymbol,
			    void *      pContext,
			    int *       aiCode);

     int unsubscribeIndicator(tsNCharcb * pSource,
			      tsNCharcb * pIndicator,
			      tsNCharcb * pSymbol,
			      int *       aiCode);

     /*   ----------------------------------------------------------------   */

     int getCnnctPt(tsNCharcb * pCnnctPt,
		    int *       aiCode);

     int getConnId(int * aiConnId,
		   int * aiCode);

     /*   ----------------------------------------------------------------   */

     private :
     void * PRI_pIntHndl;
     };

/*   =====================================================================   */

class AdmCallbacks
     {
     public :
     AdmCallbacks();
     virtual ~AdmCallbacks();

     /*   ----------------------------------------------------------------   */

     virtual int Alert(AlertInfo * pInfo,
                       void *      pContext,
                       int *       aiCode) = 0;

     private :
     };

/*   =====================================================================   */

class RCallbacks
     {
     public :
     virtual ~RCallbacks();

     /*   ----------------------------------------------------------------   */

     virtual int AccountList(AccountListInfo * pInfo,
                             void *            pContext,
                             int *             aiCode) = 0;

     virtual int Alert(AlertInfo * pInfo,
                       void *      pContext,
                       int *       aiCode) = 0;

     virtual int AskQuote(AskInfo * pInfo,
                          void *    pContext,
                          int *     aiCode) = 0;

     virtual int BestAskQuote(AskInfo * pInfo,
                              void *    pContext,
                              int *     aiCode) = 0;

     virtual int BestBidQuote(BidInfo * pInfo,
                              void *    pContext,
                              int *     aiCode) = 0;

     virtual int BidQuote(BidInfo * pInfo,
                          void *    pContext,
                          int *     aiCode) = 0;

     virtual int BustReport(OrderBustReport * pReport,
                            void *            pContext,
                            int *             aiCode) = 0;

     virtual int CancelReport(OrderCancelReport * pReport,
                              void *              pContext,
                              int *               aiCode) = 0;

     virtual int ClosePrice(ClosePriceInfo * pInfo,
                            void *           pContext,
                            int *            aiCode) = 0;

     virtual int ClosingIndicator(ClosingIndicatorInfo * pInfo,
                                  void *                 pContext,
                                  int *                  aiCode) = 0;

     virtual int EndQuote(EndQuoteInfo * pInfo,
                          void *         pContext,
                          int *          aiCode) = 0;

     virtual int EquityOptionList(EquityOptionListInfo * pInfo,
                                  void *                 pContext,
                                  int *                  aiCode) = 0;

     virtual int EquityOptionStrategyList(EquityOptionStrategyListInfo * pInfo,
					  void *                         pContext,
					  int *                          aiCode) = 0;

     virtual int ExchangeList(ExchangeListInfo * pInfo,
			      void *             pContext,
			      int *              aiCode) = 0;

     virtual int ExecutionReplay(ExecutionReplayInfo * pInfo,
                                 void *                pContext,
                                 int *                 aiCode) = 0;

     virtual int FailureReport(OrderFailureReport * pReport,
                               void *               pContext,
                               int *                aiCode) = 0;

     virtual int FillReport(OrderFillReport * pReport,
                             void *           pContext,
                            int *             aiCode) = 0;

     virtual int HighPrice(HighPriceInfo * pInfo,
                           void *          pContext,
                           int *           aiCode) = 0;

     virtual int LimitOrderBook(LimitOrderBookInfo * pInfo,
                                void *               pContext,
                                int *                aiCode) = 0;

     virtual int LineUpdate(LineInfo * pInfo,
                            void *     pContext,
                            int *      aiCode) = 0;

     virtual int LowPrice(LowPriceInfo * pInfo,
                          void *         pContext,
                          int *          aiCode) = 0;

     virtual int MarketMode(MarketModeInfo * pInfo,
                            void *           pContext,
                            int *            aiCode) = 0;

     virtual int ModifyReport(OrderModifyReport * pReport,
                              void *              pContext,
                              int *               aiCode) = 0;

     virtual int NotCancelledReport(OrderNotCancelledReport * pReport,
                                    void *                    pContext,
                                    int *                     aiCode) = 0;

     virtual int NotModifiedReport(OrderNotModifiedReport * pReport,
                                   void *                   pContext,
                                   int *                    aiCode) = 0;

     virtual int OpenInterest(OpenInterestInfo * pInfo,
			      void *             pContext,
			      int *              aiCode) = 0;

     virtual int OpenOrderReplay(OrderReplayInfo * pInfo,
                                 void *            pContext,
                                 int *             aiCode) = 0;

     virtual int OpenPrice(OpenPriceInfo * pInfo,
                           void *          pContext,
                           int *           aiCode) = 0;

     virtual int OpeningIndicator(OpeningIndicatorInfo * pInfo,
                                  void *                 pContext,
                                  int *                  aiCode) = 0;

     virtual int OptionList(OptionListInfo * pInfo,
                            void *           pContext,
                            int *            aiCode) = 0;

     virtual int OrderReplay(OrderReplayInfo * pInfo,
                             void *            pContext,
                             int *             aiCode) = 0;

     virtual int OtherReport(OrderReport * pReport,
                             void *        pContext,
                             int *         aiCode) = 0;

     virtual int PasswordChange(PasswordChangeInfo * pInfo,
				void *               pContext,
				int *                aiCode) = 0;

     virtual int PnlReplay(PnlReplayInfo * pInfo,
                           void *          pContext,
                           int *           aiCode) = 0;

     virtual int PnlUpdate(PnlInfo * pInfo,
                           void *    pContext,
                           int *     aiCode) = 0;

     virtual int PriceIncrUpdate(PriceIncrInfo * pInfo,
                                 void *          pContext,
                                 int *           aiCode) = 0;

     virtual int ProductRmsList(ProductRmsListInfo * pInfo,
				void *               pContext,
				int *                aiCode) = 0;

     virtual int RefData(RefDataInfo * pInfo,
                         void *        pContext,
                         int *         aiCode) = 0;

     virtual int RejectReport(OrderRejectReport * pReport,
                              void *              pContext,
                              int *               aiCode) = 0;

     virtual int SettlementPrice(SettlementPriceInfo * pInfo,
                                 void *                pContext,
                                 int *                 aiCode) = 0;

     virtual int SodUpdate(SodReport * pReport,
                           void *      pContext,
                           int *       aiCode) = 0;

     virtual int StatusReport(OrderStatusReport * pReport,
                              void *              pContext,
                              int *               aiCode) = 0;

     virtual int Strategy(StrategyInfo * pInfo,
                          void *         pContext,
                          int *          aiCode) = 0;

     virtual int StrategyList(StrategyListInfo * pInfo,
                              void *             pContext,
                              int *              aiCode) = 0;

     virtual int TimeBar(TimeBarInfo * pInfo,
                         void *        pContext,
                         int *         aiCode) = 0;

     virtual int TimeBarReplay(TimeBarReplayInfo * pInfo,
                               void *              pContext,
                               int *               aiCode) = 0;

     virtual int TradeReplay(TradeReplayInfo * pInfo,
                             void *            pContext,
                             int *             aiCode) = 0;

     virtual int TriggerPulledReport(OrderTriggerPulledReport * pReport,
                                     void *                     pContext,
                                     int *                      aiCode) = 0;

     virtual int TriggerReport(OrderTriggerReport * pReport,
                               void *               pContext,
                               int *                aiCode) = 0;

     virtual int TradeCondition(TradeInfo * pInfo,
                                void *      pContext,
                                int *       aiCode) = 0;

     virtual int TradeCorrectReport(OrderTradeCorrectReport * pReport,
                                    void *                    pContext,
                                    int *                     aiCode) = 0;

     virtual int TradePrint(TradeInfo * pInfo,
                            void *      pContext,
                            int *       aiCode) = 0;

     virtual int TradeVolume(TradeVolumeInfo * pInfo,
                             void *            pContext,
                             int *             aiCode) = 0;

     /*   ----------------------------------------------------------------   */

     private :
     };

/*   =====================================================================   */

class REngine
     {
     public :
     REngine(REngineParams * pParams);
     virtual ~REngine();

     /*   ----------------------------------------------------------------   */

     int getAccounts(int * aiCode);

     int getAdmCallbacks(AdmCallbacks * * apCallbacks,
                         int *            aiCode);

     int getAdmCnnctPt(tsNCharcb * pAdmCnnctPt,
                       int *       aiCode);

     int getAdminName(tsNCharcb * pAdminName,
                      int *       aiCode);

     int getAppName(tsNCharcb * pAppName,
                    int *       aiCode);

     int getAppVersion(tsNCharcb * pAppVersion,
                       int *       aiCode);

     int getCallbacks(RCallbacks * * apCallbacks,
                      int *          aiCode);

     int getContext(void * * apContext,
                    int *    aiCode);

     int getIhCnnctPt(tsNCharcb * pIhCnnctPt,
                      int *       aiCode);

     int getMdCnnctPt(tsNCharcb * pMdCnnctPt,
                      int *       aiCode);

     int getOmne(void * * apOmne,
                 int *    aiCode);

     int getOrderContext(int      iOrderNum,
                         void * * apContext,
                         int *    aiCode);

     int getPassword(tsNCharcb * pPassword,
                     int *       aiCode);

     int getPnlCnnctPt(tsNCharcb * pPnlCnnctPt,
		       int *       aiCode);

     int getTsCnnctPt(tsNCharcb * pTsCnnctPt,
                      int *       aiCode);

     int getUser(tsNCharcb * pUser,
                 int *       aiCode);

     static int getVersion(tsNCharcb * pVersion,
			   int *       aiCode);

     /*   ----------------------------------------------------------------   */

     int setContext(void * pContext,
                    int *  aiCode);

     int setOrderContext(int    iOrderNum,
                         void * pContext,
                         int *  aiCode);

     /*   ----------------------------------------------------------------   */

     int addTimer(tsNCharcb * const                    pTimerName,
                  const OmneEngineSpace::OmneTimerCB * pTimerCB,
                  long                                 lFreq,
                  void *                               pContext,
                  int *                                aiCode);

     int cancelAllOrders(AccountInfo * pAccount,
			 tsNCharcb *   pEntryType,
                         int *         aiCode);

     int cancelOrder(AccountInfo * pAccount,
                     int           iOrderNum,
                     tsNCharcb *   pEntryType,
                     tsNCharcb *   pUserMsg,
		     void *        pContext,
                     int *         aiCode);

     int cancelOrderList(AccountInfo * aoAccountArray,
			 int *         aiOrderNumArray,
			 tsNCharcb *   asEntryTypeArray,
			 tsNCharcb *   asUserMsgArray,
			 void * *      apContextArray,
			 int           iArrayLen,
			 int *         aiCode);

     int changePassword(tsNCharcb * pOldPassword,
			tsNCharcb * pNewPassword,
			int *       aiCode);

     int getEquityOptionList(tsNCharcb * pUnderlying,
			     tsNCharcb * pExchange,
                             tsNCharcb * pExpiration,
                             void *      pContext,
                             int *       aiCode);

     int getEquityOptionStrategyList(tsNCharcb * pExchange,
				     tsNCharcb * pUnderlying,
				     tsNCharcb * pStrategyType,
				     tsNCharcb * pExpiration,
				     void *      pContext,
				     int *       aiCode);

     int getOptionList(tsNCharcb * pExchange,
                       tsNCharcb * pProductCode,
                       tsNCharcb * pExpirationCCYYMM,
                       void *      pContext,
                       int *       aiCode);

     int getPriceIncrInfo(tsNCharcb * pExchange,
                          tsNCharcb * pTicker,
                          int *       aiCode);

     int getProductRmsInfo(AccountInfo * pAccount,
			   int *         aiCode);

     int getRefData(tsNCharcb * pExchange,
                    tsNCharcb * pTicker,
                    int *       aiCode);

     int getStrategyInfo(tsNCharcb * pExchange,
                         tsNCharcb * pTicker,
                         void *      pContext,
                         int *       aiCode);

     int getStrategyList(tsNCharcb * pExchange,
                         tsNCharcb * pProductCode,
                         tsNCharcb * pStrategyType,
                         tsNCharcb * pExpirationCCYYMM,
                         void *      pContext,
                         int *       aiCode);

     int listExchanges(void * pContext,
		       int *  aiCode);

     int lock(int * aiCode);

     int login(LoginParams * pParams,
               int *         aiCode);

     int logout(int * aiCode);

     int modifyOrder(ModifyLimitOrderParams * pParams,
                     int *                    aiCode);

     int modifyOrder(ModifyStopLimitOrderParams * pParams,
                     int *                        aiCode);

     int modifyOrder(ModifyStopMarketOrderParams * pParams,
                     int *                         aiCode);

     int modifyOrder(ModifyOrderParams * pParams,
                     int *               aiCode);

     int rebuildBook(tsNCharcb * pExchange,
                     tsNCharcb * pTicker,
                     int *       aiCode);

     int reconnect(int   iConnectionId,
                   int * aiCode);

     int removeTimer(tsNCharcb * const pTimerName,
                     int *             aiCode);

     int replayAllOrders(AccountInfo * pAccount,
                         int           iStartSsboe,
                         int           iEndSsboe,
                         int *         aiCode);

     int replayExecutions(AccountInfo * pAccount,
                          int           iStartSsboe,
                          int           iEndSsboe,
                          int *         aiCode);

     int replayOpenOrders(AccountInfo * pAccount,
                          int *         aiCode);

     int replayPnl(AccountInfo * pAccount,
                   int *         aiCode);

     int replayTimeBars(tsNCharcb * pExchange,
                        tsNCharcb * pTicker,
                        int         iStartSsboe,
                        int         iEndSsboe,
                        void *      pContext,
                        int *       aiCode);

     int replayTrades(tsNCharcb * pExchange,
                      tsNCharcb * pTicker,
                      int         iStartSsboe,
                      int         iEndSsboe,
                      int *       aiCode);

     int resumeInput(int * aiCode);

     int sendOrder(LimitOrderParams * pParams,
                   int *              aiCode);

     int sendOrder(MarketOrderParams * pParams,
                   int *               aiCode);

     int sendOrder(StopLimitOrderParams * pParams,
                   int *                  aiCode);

     int sendOrder(StopMarketOrderParams * pParams,
                   int *                   aiCode);

     int sendOrderList(OrderParams * pParamsArray,
                       int           iArrayLen,
                       int *         aiCode);

     int startTimer(tsNCharcb * const pTimerName,
                    int *             aiCode);

     int stopTimer(tsNCharcb * const pTimerName,
                   int *             aiCode);

     int subscribe(tsNCharcb * pExchange,
                   tsNCharcb * pTicker,
                   int         iFlags,
                   int *       aiCode);

     int subscribeByUnderlying(tsNCharcb * pUnderlying,
			       tsNCharcb * pExchange,
			       tsNCharcb * pExpiration,
			       int         iFlags,
			       bool        bRefData,
			       void *      pContext,
			       int *       aiCode);

     int subscribeExchange(tsNCharcb * pExchange,
                           int         iFlags,
                           int *       aiCode);

     int subscribeOrder(AccountInfo * pAccount,
			int *         aiCode);

     int subscribePnl(AccountInfo * pAccount,
		      int *         aiCode);

     int subscribeTimeBar(tsNCharcb * pExchange,
                          tsNCharcb * pTicker,
                          void *      pContext,
                          int *       aiCode);

     int suspendInput(int * aiCode);

     int unlock(int * aiCode);

     int unsubscribe(tsNCharcb * pExchange,
                     tsNCharcb * pTicker,
                     int *       aiCode);

     int unsubscribeByUnderlying(tsNCharcb * pUnderlying,
				 tsNCharcb * pExchange,
				 tsNCharcb * pExpiration,
				 int *       aiCode);

     int unsubscribeExchange(tsNCharcb * pExchange,
                             int *       aiCode);

     int unsubscribeOrder(AccountInfo * pAccount,
			  int *         aiCode);

     int unsubscribePnl(AccountInfo * pAccount,
			int *         aiCode);

     int unsubscribeTimeBar(tsNCharcb * pExchange,
                            tsNCharcb * pTicker,
                            int *       aiCode);

     /*   ----------------------------------------------------------------   */

     private :
     void * PRI_pIntHndl;
     };

/*   =====================================================================   */

}                                                        /* namespace RApi   */

#endif                                                   /* __RAPI_H_INCL    */

/*   =====================================================================   */
