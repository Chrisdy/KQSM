#pragma once
#ifndef __TEST_KSMARKET_DATA_API_H__
#define __TEST_KSMARKET_DATA_API_H__

#ifndef WIN32

#define INVALID_HANDLE_VALUE   -1
#define _MAX_PATH       260 /* max. length of full pathname */
#define MAX_PATH        260
//#define TRUE                true
//#define FALSE               false
#define TRUE               1
#define FALSE              0
#define __stdcall
#define __declspec(x)
#define __cdecl
#define max(a,b)           (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#define INVALID_SOCKET  -1
#define  INFINITE      0xFFFFFFFF
#define  CALLBACK
#define  WINAPI
typedef void                *HINSTANCE;
typedef void                *HANDLE;
typedef void                *HMODULE;
typedef int                     BOOL;
typedef unsigned char       BYTE;
typedef float                     FLOAT;
typedef FLOAT                  *PFLOAT;
typedef char                      CHAR;
typedef unsigned char       UCHAR;
typedef unsigned char       *PUCHAR;
typedef short                    SHORT;
typedef unsigned short      USHORT;
typedef unsigned short      *PUSHORT;
typedef long                      LONG;
typedef unsigned short      WORD;
typedef unsigned int       DWORD;
typedef long long              LONGLONG;
typedef unsigned long long  ULONGLONG;
typedef ULONGLONG           *PULONGLONG;
typedef unsigned long       ULONG;
typedef int                 INT;
typedef unsigned int        UINT;
typedef unsigned int        *PUINT;
typedef void                VOID;
typedef char               *LPSTR;
typedef const char         *LPCSTR;
typedef wchar_t            WCHAR;
typedef WCHAR              *LPWSTR;
typedef const WCHAR        *LPCWSTR;
typedef DWORD              *LPDWORD;
typedef unsigned long      UINT_PTR;
typedef UINT_PTR           SIZE_T;
typedef LONGLONG           USN;
typedef BYTE               BOOLEAN;
typedef void                *PVOID;
typedef void                *LPVOID;
typedef char                *LPTSTR;

typedef unsigned char byte;
typedef struct _FILETIME {
	DWORD dwLowDateTime;
	DWORD dwHighDateTime;
}    FILETIME;
typedef union _ULARGE_INTEGER {
	struct {
		DWORD LowPart;
		DWORD HighPart;
	};
	struct {
		DWORD LowPart;
		DWORD HighPart;
	} u;
	ULONGLONG QuadPart;
} ULARGE_INTEGER,
*PULARGE_INTEGER;

#ifndef MAXPACKSIZE
#define MAXPACKSIZE             8192
#endif

#endif

#include "event.h"
#include "KSMarketDataAPI\KSMarketDataAPI.h"
using namespace KingstarAPI;

class KSMarketApiHandler : public CThostFtdcMdSpi
{
public:
	// 期货公司ID
	TThostFtdcBrokerIDType m_chBrokerID;
	// 用户ID
	TThostFtdcUserIDType m_chUserID;
	// 用户密码
	TThostFtdcPasswordType m_chPassword;
	// 合同号
	char m_chContract[80];
	// request id
	int m_nRequestID;
	// finish event
	HANDLE m_hEvent;
public:
	KSMarketApiHandler(CThostFtdcMdApi *pUserApi);
	~KSMarketApiHandler();
	// CTP服务器连接成功后，客户端发送登录请求
	virtual void OnFrontConnected();
	// 当客户端与CTP服务器断开连接时，下面方法将被执行
	virtual void OnFrontDisconnected(int nReason);
	// 接收到客户端的登录请求之后，CTP服务器将发送响应信息，通知客户端是否登录成功
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	// 返回市场行情订阅的响应信息
	virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	// 返回市场行情退订的响应信息
	virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	// 返回深度市场行情的响应信息
	virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);
	// 用户登出响应信息
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
private:
	// CThostFtdcMduserApi实例指针
	CThostFtdcMdApi *m_pUserApi;
};

#endif



