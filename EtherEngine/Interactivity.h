#ifndef _INTERACTIVITY_H_
#define _INTERACTIVITY_H_

#include "Moudle.h"
#include "Macros.h"

#include <lua.hpp>
#include <SDL.h>

extern SDL_Event event;

// ��ȡ��ǰ���λ��
// 0����
// 1����ֵ�����λ�����꣨table��
ETHER_API getCursorPosition(lua_State * L);

// ��ȡ�����ֹ�������
// 0����
// 2����ֵ������ˮƽ����������루number������Ϊ��������Ϊ���������ִ�ֱ����������루number����ǰΪ�������Ϊ����
ETHER_API getScrollValue(lua_State * L);

// ��ȡ�����������¼�
// 0����
// 1����ֵ��false����ǰ�¼������޴�����¼���true����ǰ�¼������д�����¼�
ETHER_API updateEvent(lua_State * L);

// ��ȡ��ǰ�������¼����ͣ����ڲ����ַ������¼���Ӧ�������ڴ����������ֻ��ͨ����ϼ���ɣ�����Щ�ַ��İ����¼��ڴ���������Ͽ����޷�ͨ�����������
// 0����
// 1����ֵ���¼����ͣ�MACRO number��
ETHER_API getEventType(lua_State * L);


class MoudleInteractivity : public Moudle
{
public:
	MoudleInteractivity(lua_State* L);
	~MoudleInteractivity() {};

};

#endif // !_INTERACTIVITY_H_
