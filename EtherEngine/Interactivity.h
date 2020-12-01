#ifndef _INTERACTIVITY_H_
#define _INTERACTIVITY_H_

#include <lua.hpp>
#include <SDL.h>
#include "Macros.h"

#include <iostream>
#include <string>
using namespace std;

extern SDL_Event event;

// ��ȡ���λ��
// �޲���
// 2����ֵ��λ�õ�x��y����
extern "C" int getCursorPosition(lua_State * L);

// ��ȡ�����ֹ�������
// �޲���
// 2����ֵ������ˮƽ����������루����Ϊ��������Ϊ���������ִ�ֱ����������루��ǰΪ�������Ϊ����
extern "C" int getScrollValue(lua_State * L);

// ��ȡ�������¼�
// �޲���
// 1����ֵ��false����ǰ�¼������޴�����¼���true����ȡ�����¼�
extern "C" int updateEvent(lua_State * L);

// ��ȡ��ǰ�¼�����
// �޲���
// 1����ֵ���¼����ͣ��ַ�����
// ע�⣺���ڲ����ַ������¼���Ӧ�������ڴ����������ֻ��ͨ����ϼ���ɣ�����Щ�ַ��İ����¼��ڴ���������Ͽ����޷�ͨ������������
extern "C" int getEventType(lua_State * L);

#endif // !_INTERACTIVITY_H_
