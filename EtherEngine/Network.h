#ifndef _NETWORK_H_
#define _NETWORK_H_

#include "Macros.h"
#include "util.h"

#include <lua.hpp>
#include <httplib.h>
using namespace httplib;

// �������л�ȡ����
// 1���������ӣ�string��
// 1����ֵ��������string��
ETHER_API getLinkDomain(lua_State* L);

// �������л�ȡ·��
// 1���������ӣ�string��
// 1����ֵ��·�ɣ�string��
ETHER_API getLinkRoute(lua_State* L);

// ʹ��Get�������ָ������
// 1���������ӣ�string��
// 1����ֵ���ɹ��򷵻�Response��table����Ա��״̬��status��number������Ӧͷheaders��table��������body��string������ʧ���򷵻�nil
ETHER_API requestGet(lua_State* L);

#endif // !_NETWORK_H_

