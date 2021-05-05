#ifndef _NETWORK_H_
#define _NETWORK_H_

#include "Module.h"
#include "Macros.h"

#include <lua.hpp>

#define CPPHTTPLIB_ZLIB_SUPPORT
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>
using namespace httplib;

#include <iostream>
using namespace std;

#define ERRCODE_SUCCESS				1354
#define ERRCODE_UNKNOWN				1355
#define ERRCODE_CONNECTION			1356
#define ERRCODE_BINDIPADDRESS		1357
#define ERRCODE_READ				1358
#define ERRCODE_WRITE				1359
#define ERRCODE_EXCEEDREDRICTCOUNT	1360
#define ERRCODE_CANCELED			1361
#define ERRCODE_SSLCONNECTION		1362
#define ERRCODE_SSLLOADINGCERTS		1363
#define ERRCODE_SSLSERVERVERIFY		1364
#define ERRCODE_UNSUPPORTEDMBC		1365
#define ERRCODE_COMPRESSION			1366

#define METANAME_CLIENT		"Network.Client"

#define GetClientDataAtFirstPos() (Client*)(*(void**)luaL_checkudata(L, 1, METANAME_CLIENT))

#define CheckClientDataAtFirstPos(client) luaL_argcheck(L, client, 1, "get client data failed")

struct RequestParam
{
	string route;
	Headers headers;
	string str_params;
	Params tab_params;
	string content_type;
};

class ModuleNetwork : public Module
{
public:
	static ModuleNetwork& Instance();
	~ModuleNetwork() {};

private:
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
*		parmas��string/table���������������ѡ��Ĭ��Ϊ�գ���
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
*		parmas��string/table���������������ѡ��Ĭ��Ϊ�գ���
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
*		parmas��string�����������ݣ���ѡ��Ĭ��Ϊ�գ���
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
*		parmas��string���������������ѡ��Ĭ��Ϊ�գ���
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
* 2�������ͻ������ݣ�userdata-Client������ʱʱ�䣨number����λΪ�룩
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

/*
* �� HTTP/HTTPS ���ӷָ�Ϊ��������ַ��·�ɺͲ���
* 1������HTTP/HTTPS ���ӣ�string��
* 3����ֵ��������ַ��string��Ĭ��Ϊ���ַ�������·�ɣ�string��Ĭ��Ϊ ��/������������string��Ĭ��Ϊ���ַ�����
*/
ETHER_API splitLink(lua_State* L);

#endif // !_NETWORK_H_

