#include <ntddk.h>
#include <wdf.h>

//#pragma warning(push)
//#pragma warning(disable:4201)       // unnamed struct/union
//
//#include <fwpsk.h>
//
//#pragma warning(pop)
//
//#include <fwpmk.h>

#ifndef _CALLOUT_H_
#define _CALLOUT_H_

#include "DriverInit.h"

void NTAPI 
CalloutClasifyFunction(
	_In_ const FWPS_INCOMING_VALUES0* inFixedValues,
	_In_ const FWPS_INCOMING_METADATA_VALUES0* inMetaValues,
	_Inout_opt_ void* layerData,
	_In_opt_ const void* classifyContext,
	_In_ const FWPS_FILTER2* filter,
	_In_ UINT64 flowContext,
	_Inout_ FWPS_CLASSIFY_OUT0* classifyOut
	);

NTSTATUS NTAPI 
CalloutNotifyFunction(
	_In_ FWPS_CALLOUT_NOTIFY_TYPE notifyType,
	_In_ const GUID* filterKey,
	_Inout_ FWPS_FILTER2* filter
	);

NTSTATUS 
InsertNBs(
	_Inout_ KKDRV_PACKET_QUEUE *queue,
	_In_ NET_BUFFER_LIST *head,
	_Out_ BOOLEAN *awake
	);

__inline PKKDRV_PACKET
TailOfNetPacketChain(
	_In_ PKKDRV_PACKET packet
	);

#endif // !_CALLOUT_H_