#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "Macros.h"
#include "util.h"

#include <lua.hpp>
#include <SDL.h>

#include <math.h>

// �����޶�
// 1��3���������޶�ֵ��number�������޺����ޣ�number��Ĭ��Ϊ0��1��
// 1����ֵ���޶���ֵ
ETHER_API clamp(lua_State * L);

// �жϵ��Ƿ�λ��ָ������������(�������α߽磩
// 2�����������꣨table������������table��
// 1����ֵ���Ƿ�λ�������ڣ�boolean��
ETHER_API ifPointInRect(lua_State* L);

// �жϵ��Ƿ��ϸ�λ��ָ�����������ڣ����������α߽磩
// 2�����������꣨table������������table��
// 1����ֵ���Ƿ��ϸ�λ�������ڣ�boolean��
ETHER_API ifPointInRectStrict(lua_State* L);

// �жϵ��Ƿ�λ��ָ��Բ��������(����Բ�α߽磩
// 3�����������꣨table����Բ�����꣨table����Բ�뾶��number��
// 1����ֵ���Ƿ�λ�������ڣ�boolean��
ETHER_API ifPointInCircle(lua_State* L);

// �жϵ��Ƿ��ϸ�λ��ָ��Բ��������(������Բ�α߽磩
// 3�����������꣨table����Բ�����꣨table����Բ�뾶��number��
// 1����ֵ���Ƿ��ϸ�λ�������ڣ�boolean��
ETHER_API ifPointInCircleStrict(lua_State* L);

// �ж������������Ƿ��ཻ���������α߽磩
// 2����������1����table��������2����table��
// 1����ֵ���Ƿ��ཻ��boolean��
ETHER_API ifRectsOverlap(lua_State* L);

// �ϸ��ж������������Ƿ��ϸ��ཻ�����������α߽磩
// 2����������1����table��������2����table��
// 1����ֵ���Ƿ��ϸ��ཻ��boolean��
ETHER_API ifRectsOverlapStrict(lua_State* L);

// �ж���Բ�Ƿ��ཻ������Բ�߽磩
// 2������Բ1Բ�����꣨table����Բ1�뾶��number����Բ2Բ�����꣨table����Բ2�뾶��number��
// 1����ֵ���Ƿ��ཻ��boolean��
ETHER_API ifCirclesOverlap(lua_State* L);

// �ж���Բ�Ƿ��ϸ��ཻ��������Բ�߽磩
// 2������Բ1Բ�����꣨table����Բ1�뾶��number����Բ2Բ�����꣨table����Բ2�뾶��number��
// 1����ֵ���Ƿ��ϸ��ཻ��boolean��
ETHER_API ifCirclesOverlapStrict(lua_State* L);

// ��ȡ�����ֱ�߾���
// 2��������1���꣨table������2���꣨table��
// 1����ֵ�������ֱ�߾��루number��
ETHER_API getPointsDistance(lua_State* L);

// ��ȡ��ֱ�߼����
// 2������ֱ��1������꣨table����ֱ��1�յ����꣨table����ֱ��2������꣨table����ֱ��2�յ����꣨table��
// 1����ֵ����ֱ�߼���루number��
ETHER_API getLinesDistance(lua_State* L);

// ��ȡ�㵽ֱ�ߵĴ�ֱ����
// 3�����������꣨table����ֱ��������꣨table����ֱ���յ����꣨table��
// 1����ֵ���㵽ֱ�ߵľ��루number��
ETHER_API getPointLineDistance(lua_State* L);

//
//
//
ETHER_API rgbaToHSLA(lua_State* L);

#endif // !_ALGORITHM_H_

