#ifndef _NETWORK_H_
#define _NETWORK_H_

#include "Module.h"
#include "Macros.h"

#include <lua.hpp>
#include <SDL.h>

#define CPPHTTPLIB_ZLIB_SUPPORT
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>
using namespace httplib;

#include <vector>
#include <mutex>
using namespace std;

#define ERRCODE_SUCCESS						1354
#define ERRCODE_UNKNOWN						1355
#define ERRCODE_CONNECTION					1356
#define ERRCODE_BINDIPADDRESS				1357
#define ERRCODE_READ						1358
#define ERRCODE_WRITE						1359
#define ERRCODE_EXCEEDREDRICTCOUNT			1360
#define ERRCODE_CANCELED					1361
#define ERRCODE_SSLCONNECTION				1362
#define ERRCODE_SSLLOADINGCERTS				1363
#define ERRCODE_SSLSERVERVERIFY				1364
#define ERRCODE_UNSUPPORTEDMBC				1365
#define ERRCODE_COMPRESSION					1366

#define METANAME_CLIENT						"Network.Client"
#define METANAME_SERVER						"Network.Server"
#define METANAME_SERVER_REQ					"Network.Server.Request"
#define METANAME_SERVER_RES					"Network.Server.Response"

#define GetClientDataAtFirstPos()			(Client*)(*(void**)luaL_checkudata(L, 1, METANAME_CLIENT))
#define GetServerDataAtFirstPos()			(E_Server*)(*(void**)luaL_checkudata(L, 1, METANAME_SERVER))
#define GetServerReqDataAtFirstPos()		(Request*)(*(void**)luaL_checkudata(L, 1, METANAME_SERVER_REQ))
#define GetServerResDataAtFirstPos()		(Response*)(*(void**)luaL_checkudata(L, 1, METANAME_SERVER_RES))

#define CheckClientDataAtFirstPos(client)	luaL_argcheck(L, client, 1, "get client data failed")
#define CheckServerDataAtFirstPos(server)	luaL_argcheck(L, server && server->pServer, 1, "get server data failed")
#define CheckServerReqDataAtFirstPos(req)	luaL_argcheck(L, req, 1, "get request data failed")
#define CheckServerResDataAtFirstPos(res)	luaL_argcheck(L, res, 1, "get response data failed")

struct RequestParam
{
	string route;
	Headers headers;
	string str_params;
	Params tab_params;
	string content_type;
};

struct E_Server
{
	Server* pServer;
	string id;
	vector<string> refKeys;
	E_Server(Server* pServer, string id)
		: pServer(pServer), id(id) {}
};

class ModuleNetwork : public Module
{
public:
	static ModuleNetwork& Instance();
	static string GetServerID();
	~ModuleNetwork() {};

private:
	static size_t _stServerIndex;
	ModuleNetwork();

};

const char* GetRequestParamAtSecondPos(lua_State* L, RequestParam& reqParam);

/// <summary>
/// �� Error ת��Ϊ��
/// </summary>
/// <param name="error">Error</param>
/// <returns>��</returns>
int ConvertErrorCodeToMacro(const Error& error);

/// <summary>
/// �� response ѹ�� Lua ջ��
/// </summary>
/// <param name="error">Error</param>
/// <returns>��</returns>
void PushResponseToStack(lua_State* L, const Result& res);

/*
* ʹ�� Get ��������ĳ·��
* 2�������ͻ������ݣ�userdata-Client�����������ݣ�table���ṹ���£�
*	{
*		route��string����·�ɣ�
*		headers��table��������ͷ����ѡ��Ĭ��Ϊ�ջ�Ĭ������ͷ��
*	}
* 1����ֵ����Ӧ���ݣ�table���ṹ���£�
*	{
*		error��number����������룬
*		status��number����״̬�룬ʧ����Ϊ nil��
*		body��string������Ӧ���ݣ�ʧ����Ϊ nil��
*		headers��table������Ӧͷ��ʧ����Ϊ nil
*	}
*/
ETHER_API client_Get(lua_State* L);

/*
* ʹ�� Post ��������ĳ·��
* 2�������ͻ������ݣ�userdata-Client�����������ݣ�table���ṹ���£�
*	{
*		route��string����·�ɣ�
*		headers��table��������ͷ����ѡ��Ĭ��Ϊ�ջ�Ĭ������ͷ����
*		params��string/table���������������ѡ��Ĭ��Ϊ�գ���
*		type��string�����ĵ��� MIME Type����ѡ��Ĭ��Ϊ ��application/x-www-form-urlencoded����
*	}
* 1����ֵ����Ӧ���ݣ�table���ṹ���£�
*	{
*		error��number����������룬
*		status��number����״̬�룬ʧ����Ϊ nil��
*		body��string������Ӧ���ݣ�ʧ����Ϊ nil��
*		headers��table������Ӧͷ��ʧ����Ϊ nil
*	}
*/
ETHER_API client_Post(lua_State* L);

/*
* ʹ�� Put ��������ĳ·��
* 2�������ͻ������ݣ�userdata-Client�����������ݣ�table���ṹ���£�
*	{
*		route��string����·�ɣ�
*		headers��table��������ͷ����ѡ��Ĭ��Ϊ�ջ�Ĭ������ͷ����
*		params��string/table���������������ѡ��Ĭ��Ϊ�գ���
*		type��string�����ĵ��� MIME Type����ѡ��Ĭ��Ϊ ��application/x-www-form-urlencoded����
*	}
* 1����ֵ����Ӧ���ݣ�table���ṹ���£�
*	{
*		error��number����������룬
*		status��number����״̬�룬ʧ����Ϊ nil��
*		body��string������Ӧ���ݣ�ʧ����Ϊ nil��
*		headers��table������Ӧͷ��ʧ����Ϊ nil
*	}
*/
ETHER_API client_Put(lua_State* L);

/*
* ʹ�� Patch ��������ĳ·��
* 2�������ͻ������ݣ�userdata-Client�����������ݣ�table���ṹ���£�
*	{
*		route��string����·�ɣ�
*		headers��table��������ͷ����ѡ��Ĭ��Ϊ�ջ�Ĭ������ͷ����
*		params��string�����������ݣ���ѡ��Ĭ��Ϊ�գ���
*		type��string�����ĵ��� MIME Type����ѡ��Ĭ��Ϊ ��application/x-www-form-urlencoded����
*	}
* 1����ֵ����Ӧ���ݣ�table���ṹ���£�
*	{
*		error��number����������룬
*		status��number����״̬�룬ʧ����Ϊ nil��
*		body��string������Ӧ���ݣ�ʧ����Ϊ nil��
*		headers��table������Ӧͷ��ʧ����Ϊ nil
*	}
*/
ETHER_API client_Patch(lua_State* L);

/*
* ʹ�� Delete ��������ĳ·��
* 2�������ͻ������ݣ�userdata-Client�����������ݣ�table���ṹ���£�
*	{
*		route��string����·�ɣ�
*		headers��table��������ͷ����ѡ��Ĭ��Ϊ�ջ�Ĭ������ͷ����
*		params��string���������������ѡ��Ĭ��Ϊ�գ���
*		type��string�����ĵ��� MIME Type����ѡ��Ĭ��Ϊ ��application/x-www-form-urlencoded����
*	}
* 1����ֵ����Ӧ���ݣ�table���ṹ���£�
*	{
*		error��number����������룬
*		status��number����״̬�룬ʧ����Ϊ nil��
*		body��string������Ӧ���ݣ�ʧ����Ϊ nil��
*		headers��table������Ӧͷ��ʧ����Ϊ nil
*	}
*/
ETHER_API client_Delete(lua_State* L);

/*
* ʹ�� Options ��������ĳ·��
* 2�������ͻ������ݣ�userdata-Client�����������ݣ�table���ṹ���£�
*	{
*		route��string����·�ɣ�
*		headers��table��������ͷ����ѡ��Ĭ��Ϊ�ջ�Ĭ������ͷ��
*	}
* 1����ֵ����Ӧ���ݣ�table���ṹ���£�
*	{
*		error��number����������룬
*		status��number����״̬�룬ʧ����Ϊ nil��
*		body��string������Ӧ���ݣ�ʧ����Ϊ nil��
*		headers��table������Ӧͷ��ʧ����Ϊ nil
*	}
*/
ETHER_API client_Options(lua_State* L);

/*
* ���ÿͻ��˵�Ĭ������ͷ
* 2�������ͻ������ݣ�userdata-Client��������ͷ��table����ѡ��Ĭ��Ϊ�գ�
* 0����ֵ
*/
ETHER_API client_SetDefaultHeaders(lua_State* L);

/*
* ���ÿͻ��˵����ӳ�ʱʱ��
* 2�������ͻ������ݣ�userdata-Client������ʱʱ�䣨number����λΪ���룩
* 0����ֵ
*/
ETHER_API client_SetConnectTimeout(lua_State* L);

/*
* ���ÿͻ��˵���Դ��ȡ��ʱʱ��
* 2�������ͻ������ݣ�userdata-Client������ʱʱ�䣨number����λΪ�룩
* 0����ֵ
*/
ETHER_API client_SetReadTimeout(lua_State* L);

/*
* ���ÿͻ��˵���Դд�볬ʱʱ��
* 2�������ͻ������ݣ�userdata-Client������ʱʱ�䣨number����λΪ�룩
* 0����ֵ
*/
ETHER_API client_SetWriteTimeout(lua_State* L);

/*
* ���ÿͻ����Ƿ񱣳�����
* 2�������ͻ������ݣ�userdata-Client�����Ƿ񱣳����ӣ�boolean��
* 0����ֵ
*/
ETHER_API client_SetKeepAlive(lua_State* L);

/*
* ���ÿͻ����Ƿ�����ض���
* 2�������ͻ������ݣ�userdata-Client�����Ƿ�����ض���boolean��
* 0����ֵ
*/
ETHER_API client_SetFollowRedirect(lua_State* L);

/*
* ���ÿͻ����Ƿ�ѹ����������
* 2�������ͻ������ݣ�userdata-Client�����Ƿ�ѹ����boolean��
* 0����ֵ
*/
ETHER_API client_SetCompressRequest(lua_State* L);

/*
* ���ÿͻ����Ƿ�ѹ����Ӧ����
* 2�������ͻ������ݣ�userdata-Client�����Ƿ�ѹ����boolean��
* 0����ֵ
*/
ETHER_API client_SetCompressResponse(lua_State* L);

/*
* ���ÿͻ��� CACert �� SSL ����֤��·��
* 2�������ͻ������ݣ�userdata-Client��������֤��·����string��
* 0����ֵ
*/
ETHER_API client_SetCACertPath(lua_State* L);

/*
* ���ÿͻ��˵Ĵ�������
* 3�������ͻ������ݣ�userdata-Client��������������ַ��string�������������˿ڣ�number��
* 0����ֵ
*/
ETHER_API client_SetProxy(lua_State* L);

/*
* �����ͻ���
* 1������������ַ��string��
* 1����ֵ���ͻ������ݣ�userdata-Client��
*/
ETHER_API createClient(lua_State* L);

/*
* �ر�ָ���ͻ���
* 1�������ͻ������ݣ�userdata-Client��
* 1����ֵ��nil
*/
ETHER_API closeClient(lua_State* L);

/// <summary>
/// �ص���������
/// </summary>
/// <param name="req">�������ݶ���</param>
/// <param name="res">��Ӧ���ݶ���</param>
/// <param name="L">Lua �����ָ��</param>
/// <param name="refKey">�ص�����������ע����е�������</param>
/// <param name="err">�쳣��Ϣ</param>
void CallHandler(const Request& req, Response& res, lua_State* L, const string& refKey, const char* err = nullptr);

/*
* ��ȡ���󷽷�
* 1�������������ݶ������ݣ�userdata-Request��
* 1����ֵ�����󷽷���string��
*/
ETHER_API request_GetMethod(lua_State* L);

ETHER_API request_GetRoute(lua_State* L);

ETHER_API request_GetHeaders(lua_State* L);

ETHER_API request_GetBody(lua_State* L);

ETHER_API request_GetRemoteAddress(lua_State* L);

ETHER_API request_GetRemotePort(lua_State* L);

ETHER_API request_GetVersion(lua_State* L);

ETHER_API request_GetParams(lua_State* L);

ETHER_API request_CheckHeaderExist(lua_State* L);

ETHER_API request_GetHeaderValue(lua_State* L);

ETHER_API request_GetHeaderValueCount(lua_State* L);

ETHER_API request_CheckParamExist(lua_State* L);

ETHER_API request_GetParamValue(lua_State* L);

ETHER_API request_GetParamValueCount(lua_State* L);



ETHER_API response_SetVersion(lua_State* L);

ETHER_API response_SetStatus(lua_State* L);

ETHER_API response_GetHeaders(lua_State* L);

ETHER_API response_SetBody(lua_State* L);

ETHER_API response_CheckHeaderExist(lua_State* L);

ETHER_API response_GetHeaderValue(lua_State* L);

ETHER_API response_GetHeaderValueCount(lua_State* L);

ETHER_API response_SetHeaderValue(lua_State* L);

ETHER_API response_SetHeaders(lua_State* L);

ETHER_API response_SetRedirect(lua_State* L);

ETHER_API response_SetContent(lua_State* L);





ETHER_API server_Get(lua_State* L);

ETHER_API server_SetExceptionHandler(lua_State* L);

ETHER_API server_SetMaxKeepAliveCount(lua_State* L);

ETHER_API server_SetKeepAliveTimeout(lua_State* L);

ETHER_API server_SetReadTimeout(lua_State* L);

ETHER_API server_SetWriteTimeout(lua_State* L);

ETHER_API server_SetIdleInterval(lua_State* L);

ETHER_API server_SetMaxRequestLength(lua_State* L);

ETHER_API server_BindToAnyPort(lua_State* L);

ETHER_API server_ListenAfterBind(lua_State* L);

ETHER_API server_Listen(lua_State* L);

ETHER_API server_Stop(lua_State* L);


ETHER_API createServer(lua_State* L);

ETHER_API closeServer(lua_State* L);

/*
* �� HTTP/HTTPS ���ӷָ�Ϊ��������ַ��·�ɺͲ���
* 1������HTTP/HTTPS ���ӣ�string��
* 3����ֵ��������ַ��string��Ĭ��Ϊ���ַ�������·�ɣ�string��Ĭ��Ϊ ��/������������string��Ĭ��Ϊ���ַ�����
*/
ETHER_API splitLink(lua_State* L);

#endif // !_NETWORK_H_

