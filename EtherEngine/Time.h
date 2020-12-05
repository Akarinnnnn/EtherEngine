#ifndef _TIME_H_
#define _TIME_H_

#include <lua.hpp>
#include <SDL.h>

// ��ͣ����
// 0����
// 0����ֵ
extern "C" int pause(lua_State * L);

// �������ָ��ʱ��
// 1����������ʱ�䣨number����λ�����룩
// 0����ֵ
extern "C" int sleep(lua_State * L);

// ��ȡ����ӳ�ʼ�����е�����Ϊֹ��ʱ��
// 0����
// 1����ֵ������ʱ�䣨number����λ�����룩
extern "C" int getInitTime(lua_State * L);

// ��ȡ�߷ֱ��ʼ�������ǰֵ
// 0����
// 1����ֵ����������ǰֵ��number��
extern "C" int getAccurateCount(lua_State * L);

// ��ȡ�߷ֱ��ʼ�����Ƶ��
// 0����
// 1����ֵ��������Ƶ�ʣ�number����λ�����ȣ�
extern "C" int getCounterFrequency(lua_State * L);

#endif // !_TIME_H_
