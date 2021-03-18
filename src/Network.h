#ifndef _NETWORK_H_
#define _NETWORK_H_

#include "Moudle.h"
#include "Macros.h"
#include "util.h"

#include <lua.hpp>
#include <httplib.h>
using namespace httplib;
/*
* �������л�ȡ����
* 1���������ӣ�string��
* 1����ֵ��������string��
*/
ETHER_API getLinkDomain(lua_State* L);

/*
* �������л�ȡ·��
* 1���������ӣ�string��
* 1����ֵ��·�ɣ�string��
*/
ETHER_API getLinkRoute(lua_State* L);

/*
* ʹ��Get�������ָ������
* 1��2���������ӣ�string��������ѡ��HttpHeaders��table��
* 1����ֵ���ɹ��򷵻�Response��table����
	{
		statue��״̬�루number����
		headers����Ӧͷ��table����
		body�����ģ�string����
	}
* ��ʧ���򷵻�nil
*/

ETHER_API requestGet(lua_State* L);

/*
* ʹ��Post������ָ�����ӷ�������
* 3��4���������ӣ�string���������壨string����MIME Type��Macro number��������ѡ��HttpHeaders��table��
* 1����ֵ���ɹ��򷵻�Response��table����ṹ���£�:
	{
		statue��״̬�루number����
		headers����Ӧͷ��table����
		body�����ģ�string����
	}
* ��ʧ���򷵻�nil
*/
ETHER_API requestPost(lua_State* L);


class MoudleNetwork : public Moudle
{
public:
	MoudleNetwork(lua_State* L);
	~MoudleNetwork() {};

};

#endif // !_NETWORK_H_

