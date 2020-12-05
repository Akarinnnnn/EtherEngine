#ifndef _INTERACTIVITY_H_
#define _INTERACTIVITY_H_

#include <lua.hpp>
#include <SDL.h>
#include "Macros.h"

#include <iostream>
#include <string>
using namespace std;

extern SDL_Event event;

// ��ȡ��ǰ���λ��
// 0����
// 2����ֵ�����λ�õ�x���꣨number�������λ�õ�y���꣨number��
extern "C" int getCursorPosition(lua_State * L);

// ��ȡ�����ֹ�������
// 0����
// 2����ֵ������ˮƽ����������루number������Ϊ��������Ϊ���������ִ�ֱ����������루number����ǰΪ�������Ϊ����
extern "C" int getScrollValue(lua_State * L);

// ��ȡ�����������¼�
// 0����
// 1����ֵ��false����ǰ�¼������޴�����¼���true����ǰ�¼������д�����¼�
extern "C" int updateEvent(lua_State * L);

// ��ȡ��ǰ�������¼����ͣ����ڲ����ַ������¼���Ӧ�������ڴ����������ֻ��ͨ����ϼ���ɣ�����Щ�ַ��İ����¼��ڴ���������Ͽ����޷�ͨ�����������
// 0����
// 1����ֵ���¼����ͣ�MACRO number��
extern "C" int getEventType(lua_State * L);

#endif // !_INTERACTIVITY_H_
