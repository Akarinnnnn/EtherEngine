#ifndef _OTHERS_H_
#define _OTHERS_H_

#include "Macros.h"

#include <lua.hpp>
#include <SDL.h>

// ��ȡ�������е�Ŀ¼
// 0����
// 1����ֵ����������Ŀ¼��string��
ETHER_API getBasePath(lua_State * L);

// ���ü��а��ı�
// 1���������а��ı���string��
// 0����ֵ
ETHER_API setClipboardText(lua_State * L);

// ��ȡ���а��ı�
// 0����
// 1����ֵ�����а��ı���string��
ETHER_API getClipboardText(lua_State * L);

// ��ȡƽ̨����
// 0����
// 1����ֵ��ƽ̨���ͣ�string��
ETHER_API getPlatform(lua_State * L);

// ��ȡϵͳ���ڴ��С
// 0����
// 1����ֵ��ϵͳ�ڴ棨number����λMB��
ETHER_API getSystemRAM(lua_State * L);

#endif // !_OTHERS_H_
