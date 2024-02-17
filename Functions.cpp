////////////////////////////////////////////////////
// Functions.cpp
// Sample functions implementation file for example AmiBroker plug-in
//
// Copyright (C)2001 Tomasz Janeczko, amibroker.com
// All rights reserved.
//
// Last modified: 2001-09-24 TJ
// 
// You may use this code in your own projects provided that:
//
// 1. You are registered user of AmiBroker
// 2. The software you write using it is for personal, noncommercial use only
//
// For commercial use you have to obtain a separate license from Amibroker.com
//
////////////////////////////////////////////////////

#include "stdafx.h"
#include "Plugin.h"
#include <windows.h>
#include <winhttp.h>
#include <iostream> 
// Helper function

int SkipEmptyValues(int nSize, float* Src, float* Dst)
{
	int i;

	for (i = 0; i < nSize && IS_EMPTY(Src[i]); i++)
	{
		Dst[i] = EMPTY_VAL;
	}

	return i;
}


///////////////////////////////////////////
// Each AFL function has the following prototype:
//
// AmiVar FunctionName( int NumArgs, AmiVar *ArgsTable )
//
// You can define as many functions as you want.
// To make them visible you should add them to the function
// table at the bottom of this file
//
///////////////////////////////////////////////

/// <summary>
/// Rest Api Post Method
/// </summary>
/// <param name="server">Domain name</param>
/// <param name="path">Api method to call</param>
/// <param name="data">Text body</param>
/// <returns></returns>
bool SendHttpPostRequest(const wchar_t* server, const wchar_t* path, const char* data) {
	// Initialize WinHTTP
	HINTERNET hSession = WinHttpOpen(L"AFL", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);

	if (!hSession) {
		std::wcerr << L"Failed to initialize WinHTTP. Error code: " << GetLastError() << std::endl;
		return false;
	}

	// Open a connection to the server
	HINTERNET hConnect = WinHttpConnect(hSession, server, INTERNET_DEFAULT_HTTPS_PORT, 0);

	if (!hConnect) {
		std::wcerr << L"Failed to open a connection to the server. Error code: " << GetLastError() << std::endl;
		WinHttpCloseHandle(hSession);
		return false;
	}

	// Open a request handle
	HINTERNET hRequest = WinHttpOpenRequest(hConnect, L"POST", path, NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, WINHTTP_FLAG_SECURE);

	if (!hRequest) {
		std::wcerr << L"Failed to open request. Error code: " << GetLastError() << std::endl;
		WinHttpCloseHandle(hConnect);
		WinHttpCloseHandle(hSession);
		return false;
	}

	LPCWSTR headers = L"Content-Type: text/plain\r\nConnection: close\r\n"; // Explicitly set Connection: close

	// Calculate content length based on ASCII-encoded data
	DWORD data_len = static_cast<DWORD>(strlen(data));

	// Send the HTTP POST request
	if (!WinHttpSendRequest(hRequest, headers, -1, (LPVOID)data, data_len, data_len, 0)) {
		std::wcerr << L"Failed to send request. Error code: " << GetLastError() << std::endl;
		WinHttpCloseHandle(hRequest);
		WinHttpCloseHandle(hConnect);
		WinHttpCloseHandle(hSession);
		return false;
	}

	if (!WinHttpReceiveResponse(hRequest, NULL)) {
		std::wcerr << L"Failed to receive response. Error code: " << GetLastError() << std::endl;
		WinHttpCloseHandle(hRequest);
		WinHttpCloseHandle(hConnect);
		WinHttpCloseHandle(hSession);
		return false;
	}

	std::wcout << L"Request succeeded." << std::endl;

	// Close the request, connection, and session handles
	WinHttpCloseHandle(hRequest);
	WinHttpCloseHandle(hConnect);
	WinHttpCloseHandle(hSession);

	return true;
}
/// <summary>
/// Function to be called from AmiBroker App => PlaceOrder("");
/// </summary>
/// <param name="NumArgs"></param>
/// <param name="ArgsTable"></param>
/// <returns></returns>
AmiVar VPlaceOrder(int NumArgs, AmiVar* ArgsTable)
{

	///Testing Done Via https://webhook.site
	const wchar_t* server = L"webhook.site";
	const wchar_t* path = L"/e347db8b-ae1b-49c6-ac2f-15bd563704e4";

	const char* postData = ArgsTable[0].string; //L"IntType | buy_sell | symbol | qty | orderType | productType | limitPrice | triggerPrice | TSL | Strategy_tag";
	AmiVar var;
	var.type = VAR_STRING;

	if (SendHttpPostRequest(server, path, postData)) {
		// Handle a successful request here
		var.string = "Order Placed";
	}
	else {
		// Handle errors or retries here
		var.string = "Order Failed";
	}
	return var;
}

/////////////////////////////////////////////
// Function table now follows
//
// You have to specify each function that should be
// visible for AmiBroker.
// Each entry of the table must contain:
// "Function name", { FunctionPtr, <no. of array args>, <no. of string args>, <no. of float args>, <no. of default args>, <pointer to default values table float *>

FunctionTag gFunctionTable[] = {
								"PlaceOrder",		{ VPlaceOrder, 0, 1, 0, 0, NULL }
};

int gFunctionTableSize = sizeof(gFunctionTable) / sizeof(FunctionTag);
