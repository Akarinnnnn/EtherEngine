#ifndef _OTHERS_H_
#define _OTHERS_H_

#include <lua.hpp>
#include <SDL.h>

// ��ȡ�������е�Ŀ¼
// 0����
// 1����ֵ����������Ŀ¼��string��
extern "C" int getBasePath(lua_State * L);

// ���ü��а��ı�
// 1���������а��ı���string��
// 0����ֵ
extern "C" int setClipboardText(lua_State * L);

// ��ȡ���а��ı�
// 0����
// 1����ֵ�����а��ı���string��
extern "C" int getClipboardText(lua_State * L);

// ��ȡƽ̨����
// 0����
// 1����ֵ��ƽ̨���ͣ�string��
extern "C" int getPlatform(lua_State * L);

// ��ȡϵͳ���ڴ��С
// 0����
// 1����ֵ��ϵͳ�ڴ棨number����λMB��
extern "C" int getSystemRAM(lua_State * L);

#endif // !_OTHERS_H_
