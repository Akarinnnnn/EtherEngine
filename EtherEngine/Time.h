#ifndef _TIME_H_
#define _TIME_H_

#include <lua.hpp>
#include <SDL.h>

// ��ͣ����
// �޲���
// �޷���ֵ
extern "C" int pause(lua_State * L);

// �������ָ��ʱ��
// 1����������ʱ�䣨��λ�����룩
// �޷���ֵ
extern "C" int sleep(lua_State * L);

// ��ȡ����ӳ�ʼ�����е�����Ϊֹ��ʱ��
// �޲���
// 1����ֵ������ʱ�䣨��λ�����룩
extern "C" int getInitTime(lua_State * L);

// ��ȡ�߷ֱ��ʼ�������ǰֵ
// �޲���
// 1����ֵ����������ǰֵ
extern "C" int getAccurateCount(lua_State * L);

// ��ȡ�߷ֱ��ʼ�����Ƶ��
// �޲���
// 1����ֵ��������Ƶ�ʣ���λ�����ȣ�
extern "C" int getCounterFrequency(lua_State * L);

#endif // !_TIME_H_
