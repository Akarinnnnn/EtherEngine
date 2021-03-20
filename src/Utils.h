#ifndef _UTIL_H_
#define _UTIL_H_

#include "Macros.h"

#include <lua.hpp>
#include <SDL.h>

#define CheckPointParam(L, index, point) luaL_argcheck(L, !GetPointParam(L, index, point), index, "table point expected") 
#define CheckRectParam(L, index, rect) luaL_argcheck(L, !GetRectParam(L, index, rect), index, "table rect expected") 
#define CheckColorParam(L, index, color) luaL_argcheck(L, !GetColorParam(L, index, color), index, "table color expected") 

#define CheckTableParam(L, index) luaL_argcheck(L, lua_istable(L, index), index, "table expected") 

/// <summary>
/// ��ȡ������λ�õı�Ĳ���
/// </summary>
/// <param name="L">��ǰLua���������</param>
/// <param name="index">����λ��</param>
/// <param name="point">��λ��</param>
/// <returns>�Ƿ�ɹ�</returns>
int GetPointParam(lua_State* L, int index, SDL_Point& point);

/// <summary>
/// ��ȡ��������λ�úʹ�С�ı�Ĳ���
/// </summary>
/// <param name="L">��ǰLua���������</param>
/// <param name="index">����λ��</param>
/// <param name="rect">����λ�úʹ�С</param>
/// <returns>�Ƿ�ɹ�</returns>
int GetRectParam(lua_State* L, int index, SDL_Rect& rect);

/// <summary>
/// ��ȡ������ɫ�ı�Ĳ���
/// </summary>
/// <param name="L">��ǰLua���������</param>
/// <param name="index">����λ��</param>
/// <param name="funName">��ɫ</param>
/// <returns>�Ƿ�ɹ�</returns>
int GetColorParam(lua_State* L, int index, SDL_Color& color);

#endif // !_UTIL_H_

