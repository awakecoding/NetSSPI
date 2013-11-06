/**
 * Network Security Support Provider Interface (NetSSPI)
 *
 * Copyright 2012-2013 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifndef WINPR_NETSSPI_H
#define WINPR_NETSSPI_H

#include <winpr/sspi.h>

#include <winpr/stream.h>

#define NETSSPI_ENUMERATE_SECURITY_PACKAGES		1
#define NETSSPI_QUERY_CREDENTIALS_ATTRIBUTES		2
#define NETSSPI_ACQUIRE_CREDENTIALS_HANDLE		3
#define NETSSPI_FREE_CREDENTIALS_HANDLE			4
#define NETSSPI_RESERVED2				5
#define NETSSPI_INITIALIZE_SECURITY_CONTEXT		6
#define NETSSPI_ACCEPT_SECURITY_CONTEXT			7
#define NETSSPI_COMPLETE_AUTH_TOKEN			8
#define NETSSPI_DELETE_SECURITY_CONTEXT			9
#define NETSSPI_APPLY_CONTROL_TOKEN			10
#define NETSSPI_QUERY_CONTEXT_ATTRIBUTES		11
#define NETSSPI_IMPERSONATE_SECURITY_CONTEXT		12
#define NETSSPI_REVERT_SECURITY_CONTEXT			13
#define NETSSPI_MAKE_SIGNATURE				14
#define NETSSPI_VERIFY_SIGNATURE			15
#define NETSSPI_FREE_CONTEXT_BUFFER			16
#define NETSSPI_QUERY_SECURITY_PACKAGE_INFO		17
#define NETSSPI_RESERVED3				18
#define NETSSPI_RESERVED4				19
#define NETSSPI_EXPORT_SECURITY_CONTEXT			20
#define NETSSPI_IMPORT_SECURITY_CONTEXT			21
#define NETSSPI_ADD_CREDENTIALS				22
#define NETSSPI_RESERVED8				23
#define NETSSPI_QUERY_SECURITY_CONTEXT_TOKEN		24
#define NETSSPI_ENCRYPT_MESSAGE				25
#define NETSSPI_DECRYPT_MESSAGE				26
#define NETSSPI_SET_CONTEXT_ATTRIBUTES			27

#define NETSSPI_FLAGS_UNICODE				0x80

#define NETSSPI_FIELD_01				0x000000000001
#define NETSSPI_FIELD_02				0x000000000002
#define NETSSPI_FIELD_03				0x000000000004
#define NETSSPI_FIELD_04				0x000000000008
#define NETSSPI_FIELD_05				0x000000000010
#define NETSSPI_FIELD_06				0x000000000020
#define NETSSPI_FIELD_07				0x000000000040
#define NETSSPI_FIELD_08				0x000000000080
#define NETSSPI_FIELD_09				0x000000000100
#define NETSSPI_FIELD_10				0x000000000200
#define NETSSPI_FIELD_11				0x000000000400
#define NETSSPI_FIELD_12				0x000000000800
#define NETSSPI_FIELD_13				0x000000001000
#define NETSSPI_FIELD_14				0x000000002000
#define NETSSPI_FIELD_15				0x000000004000
#define NETSSPI_FIELD_16				0x000000008000
#define NETSSPI_FIELD_17				0x000000010000
#define NETSSPI_FIELD_18				0x000000020000
#define NETSSPI_FIELD_19				0x000000040000
#define NETSSPI_FIELD_20				0x000000080000
#define NETSSPI_FIELD_21				0x000000100000
#define NETSSPI_FIELD_22				0x000000200000
#define NETSSPI_FIELD_23				0x000000400000
#define NETSSPI_FIELD_24				0x000000800000

#define NETSSPI_OPTION_01				0x000001000000
#define NETSSPI_OPTION_02				0x000002000000
#define NETSSPI_OPTION_03				0x000004000000
#define NETSSPI_OPTION_04				0x000008000000
#define NETSSPI_OPTION_05				0x000010000000
#define NETSSPI_OPTION_06				0x000020000000
#define NETSSPI_OPTION_07				0x000040000000
#define NETSSPI_OPTION_08				0x000080000000

#define NETSSPI_HEADER_REQ_LENGTH			10
#define NETSSPI_HEADER_RSP_LENGTH			14

#define NETSSPI_STRING_ANSI				0x0000
#define NETSSPI_STRING_UNICODE				0x8000
#define NETSSPI_STRING_LENGTH_MASK			0x7FFF

struct _NETSSPI_STRING
{
	UINT16 Length;
	BYTE* Buffer;
};
typedef struct _NETSSPI_STRING NETSSPI_STRING;

struct _NETSSPI_HANDLE
{
	UINT64 dwLower;
	UINT64 dwUpper;
};
typedef struct _NETSSPI_HANDLE NETSSPI_HANDLE;

struct _NETSSPI_TIMESTAMP
{
	UINT32 LowPart;
	INT32 HighPart;
};
typedef struct _NETSSPI_TIMESTAMP NETSSPI_TIMESTAMP;

struct _NETSSPI_LUID
{
	UINT32 LowPart;
	INT32 HighPart;
};
typedef struct _NETSSPI_LUID NETSSPI_LUID;

struct _NETSSPI_AUTH_IDENTITY
{
	UINT32 Flags;
	NETSSPI_STRING User;
	NETSSPI_STRING Domain;
	NETSSPI_STRING Password;
};
typedef struct _NETSSPI_AUTH_IDENTITY NETSSPI_AUTH_IDENTITY;

struct _NETSSPI_SEC_BUFFER
{
	UINT32 cbBuffer;
	UINT32 BufferType;
	void* pvBuffer;
};
typedef struct _NETSSPI_SEC_BUFFER NETSSPI_SEC_BUFFER;

struct _NETSSPI_SEC_BUFFER_DESC
{
	UINT32 ulVersion;
	UINT32 cBuffers;
	NETSSPI_SEC_BUFFER* pBuffers;
};
typedef struct _NETSSPI_SEC_BUFFER_DESC NETSSPI_SEC_BUFFER_DESC;

struct _NETSSPI_HEADER_REQ
{
	UINT32 TotalLength;
	UINT8 Flags;
	UINT8 FunctionId;
	UINT32 ExtFlags;
};
typedef struct _NETSSPI_HEADER_REQ NETSSPI_HEADER_REQ;

struct _NETSSPI_HEADER_RSP
{
	UINT32 TotalLength;
	UINT8 Flags;
	UINT8 FunctionId;
	UINT32 ExtFlags;
	UINT32 Status;
};
typedef struct _NETSSPI_HEADER_RSP NETSSPI_HEADER_RSP;

struct _NETSSPI_QUERY_SECURITY_PACKAGE_INFO_REQ
{
	NETSSPI_STRING PackageName;
};
typedef struct _NETSSPI_QUERY_SECURITY_PACKAGE_INFO_REQ NETSSPI_QUERY_SECURITY_PACKAGE_INFO_REQ;

struct _NETSSPI_QUERY_SECURITY_PACKAGE_INFO_RSP
{
	UINT32 fCapabilities;
	UINT16 wVersion;
	UINT16 wRPCID;
	UINT32 cbMaxToken;
	NETSSPI_STRING Name;
	NETSSPI_STRING Comment;
};
typedef struct _NETSSPI_QUERY_SECURITY_PACKAGE_INFO_RSP NETSSPI_QUERY_SECURITY_PACKAGE_INFO_RSP;

struct _NETSSPI_ACQUIRE_CREDENTIALS_HANDLE_REQ
{
	NETSSPI_STRING Principal;
	NETSSPI_STRING Package;
	UINT32 fCredentialUse;
	NETSSPI_LUID LogonID;
	UINT32 AuthDataLength;
	NETSSPI_AUTH_IDENTITY identity;
};
typedef struct _NETSSPI_ACQUIRE_CREDENTIALS_HANDLE_REQ NETSSPI_ACQUIRE_CREDENTIALS_HANDLE_REQ;

struct _NETSSPI_ACQUIRE_CREDENTIALS_HANDLE_RSP
{
	NETSSPI_HANDLE Credential;
	NETSSPI_TIMESTAMP Expiry;
};
typedef struct _NETSSPI_ACQUIRE_CREDENTIALS_HANDLE_RSP NETSSPI_ACQUIRE_CREDENTIALS_HANDLE_RSP;

struct _NETSSPI_ACCEPT_SECURITY_CONTEXT_REQ
{
	NETSSPI_HANDLE Credential;
	NETSSPI_HANDLE Context;
	NETSSPI_SEC_BUFFER_DESC Input;
	UINT32 fContextReq;
	UINT32 TargetDataRep;
	NETSSPI_HANDLE NewContext;
	NETSSPI_SEC_BUFFER_DESC Output;
	UINT32 fContextAttr;
	NETSSPI_TIMESTAMP TimeStamp;
};
typedef struct _NETSSPI_ACCEPT_SECURITY_CONTEXT_REQ NETSSPI_ACCEPT_SECURITY_CONTEXT_REQ;

struct _NETSSPI_ACCEPT_SECURITY_CONTEXT_RSP
{
	NETSSPI_HANDLE NewContext;
	NETSSPI_SEC_BUFFER_DESC Output;
	UINT32 fContextAttr;
	NETSSPI_TIMESTAMP TimeStamp;
};
typedef struct _NETSSPI_ACCEPT_SECURITY_CONTEXT_RSP NETSSPI_ACCEPT_SECURITY_CONTEXT_RSP;

struct _NETSSPI_QUERY_CONTEXT_ATTRIBUTES_REQ
{
	NETSSPI_HANDLE Context;
	UINT32 ulAttribute;
};
typedef struct _NETSSPI_QUERY_CONTEXT_ATTRIBUTES_REQ NETSSPI_QUERY_CONTEXT_ATTRIBUTES_REQ;

struct _NETSSPI_QUERY_CONTEXT_ATTRIBUTES_RSP
{
	UINT32 Length;
	BYTE* Buffer;
};
typedef struct _NETSSPI_QUERY_CONTEXT_ATTRIBUTES_RSP NETSSPI_QUERY_CONTEXT_ATTRIBUTES_RSP;

struct _NETSSPI_DECRYPT_MESSAGE_REQ
{
	NETSSPI_HANDLE Context;
	NETSSPI_SEC_BUFFER_DESC Message;
	UINT32 MessageSeqNo;
};
typedef struct _NETSSPI_DECRYPT_MESSAGE_REQ NETSSPI_DECRYPT_MESSAGE_REQ;

struct _NETSSPI_DECRYPT_MESSAGE_RSP
{
	NETSSPI_SEC_BUFFER_DESC Message;
	UINT32 fQOP;
};
typedef struct _NETSSPI_DECRYPT_MESSAGE_RSP NETSSPI_DECRYPT_MESSAGE_RSP;

struct _NETSSPI_ENCRYPT_MESSAGE_REQ
{
	NETSSPI_HANDLE Context;
	UINT32 fQOP;
	NETSSPI_SEC_BUFFER_DESC Message;
	UINT32 MessageSeqNo;
};
typedef struct _NETSSPI_ENCRYPT_MESSAGE_REQ NETSSPI_ENCRYPT_MESSAGE_REQ;

struct _NETSSPI_ENCRYPT_MESSAGE_RSP
{
	NETSSPI_SEC_BUFFER_DESC Message;
};
typedef struct _NETSSPI_ENCRYPT_MESSAGE_RSP NETSSPI_ENCRYPT_MESSAGE_RSP;

struct _NETSSPI_IMPERSONATE_SECURITY_CONTEXT_REQ
{
	NETSSPI_HANDLE Context;
};
typedef struct _NETSSPI_IMPERSONATE_SECURITY_CONTEXT_REQ NETSSPI_IMPERSONATE_SECURITY_CONTEXT_REQ;

struct _NETSSPI_IMPERSONATE_SECURITY_CONTEXT_RSP
{
	void* dummy;
};
typedef struct _NETSSPI_IMPERSONATE_SECURITY_CONTEXT_RSP NETSSPI_IMPERSONATE_SECURITY_CONTEXT_RSP;

struct _NETSSPI_REVERT_SECURITY_CONTEXT_REQ
{
	NETSSPI_HANDLE Context;
};
typedef struct _NETSSPI_REVERT_SECURITY_CONTEXT_REQ NETSSPI_REVERT_SECURITY_CONTEXT_REQ;

struct _NETSSPI_REVERT_SECURITY_CONTEXT_RSP
{
	void* dummy;
};
typedef struct _NETSSPI_REVERT_SECURITY_CONTEXT_RSP NETSSPI_REVERT_SECURITY_CONTEXT_RSP;

void netsspi_read_header_req(wStream* s, NETSSPI_HEADER_REQ* hdr_req);
void netsspi_write_header_req(wStream* s, NETSSPI_HEADER_REQ* hdr_req);

void netsspi_read_header_rsp(wStream* s, NETSSPI_HEADER_RSP* hdr_rsp);
void netsspi_write_header_rsp(wStream* s, NETSSPI_HEADER_RSP* hdr_rsp);

void netsspi_read_handle(wStream* s, NETSSPI_HANDLE* handle);
void netsspi_write_handle(wStream* s, NETSSPI_HANDLE* handle);

void netsspi_read_timestamp(wStream* s, NETSSPI_TIMESTAMP* timestamp);
void netsspi_write_timestamp(wStream* s, NETSSPI_TIMESTAMP* timestamp);

int netsspi_string_length(NETSSPI_STRING* string);
void netsspi_init_string(NETSSPI_STRING* string, BYTE* buffer, UINT16 encoding);
void netsspi_init_string_ex(NETSSPI_STRING* string, BYTE* buffer, UINT16 length, UINT16 encoding);
void netsspi_read_string(wStream* s, NETSSPI_STRING* string);
void netsspi_write_string(wStream* s, NETSSPI_STRING* string);
void netsspi_free_string(NETSSPI_STRING* string);

typedef struct _NETSSPI_CONTEXT NETSSPI_CONTEXT;

typedef int (*NETSSPI_OPEN_FN)(NETSSPI_CONTEXT* context);
typedef int (*NETSSPI_CLOSE_FN)(NETSSPI_CONTEXT* context);
typedef int (*NETSSPI_READ_FN)(NETSSPI_CONTEXT* context, BYTE* data, int length);
typedef int (*NETSSPI_WRITE_FN)(NETSSPI_CONTEXT* context, BYTE* data, int length);

struct _NETSSPI_CONTEXT
{
	int sockfd;
	void* handle;
	BOOL server;
	LPTSTR Target;
	LPTSTR Transport;
	NETSSPI_OPEN_FN Open;
	NETSSPI_CLOSE_FN Close;
	NETSSPI_READ_FN Read;
	NETSSPI_WRITE_FN Write;
};

void netsspi_send_message(NETSSPI_CONTEXT* context, wStream* s);
wStream* netsspi_recv_message(NETSSPI_CONTEXT* context);

void netsspi_serial_device_init(NETSSPI_CONTEXT* context);
void netsspi_ipc_socket_init(NETSSPI_CONTEXT* context);
void netsspi_tcp_socket_init(NETSSPI_CONTEXT* context);

int netsspi_tcp_socket_open(NETSSPI_CONTEXT* context);

NETSSPI_CONTEXT* netsspi_new(BOOL server);
void netsspi_free(NETSSPI_CONTEXT* context);

#ifndef _WIN32

int netsspi_ipc_socket_open(NETSSPI_CONTEXT* context);
int netsspi_ipc_socket_connect(NETSSPI_CONTEXT* context);

#else

int netsspi_serial_device_open(NETSSPI_CONTEXT* context);
int netsspi_serial_device_close(NETSSPI_CONTEXT* context);

#endif

#endif /* WINPR_NETSSPI_H */
