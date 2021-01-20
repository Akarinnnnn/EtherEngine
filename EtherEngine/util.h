#ifndef _UTIL_H_
#define _UTIL_H_

#include "Macros.h"

#include <lua.hpp>
#include <SDL.h>
#include <httplib.h>
using namespace httplib;

#include <memory>
#include <string>
using namespace std;

/// <summary>
/// ��ȡ������λ�õı�Ĳ���
/// </summary>
/// <param name="L">��ǰLua���������</param>
/// <param name="index">����λ��</param>
/// <param name="funName">����������</param>
/// <returns>��λ��</returns>
SDL_Point GetPointParam(lua_State* L, int index, const char* funName);

/// <summary>
/// ��ȡ��������λ�úʹ�С�ı�Ĳ���
/// </summary>
/// <param name="L">��ǰLua���������</param>
/// <param name="index">����λ��</param>
/// <param name="funName">����������</param>
/// <returns>����λ�úʹ�С</returns>
SDL_Rect GetRectParam(lua_State* L, int index, const char* funName);

/// <summary>
/// ��ȡ������ɫ�ı�Ĳ���
/// </summary>
/// <param name="L">��ǰLua���������</param>
/// <param name="index">����λ��</param>
/// <param name="funName">����������</param>
/// <returns>��ɫ</returns>
SDL_Color GetColorParam(lua_State* L, int index, const char* funName);

/// <summary>
/// �������л�ȡ����
/// </summary>
/// <param name="link">����</param>
/// <returns>����</returns>
string GetLinkDomain(string link);

/// <summary>
/// �������л�ȡ·��
/// </summary>
/// <param name="link">����</param>
/// <returns>·��</returns>
string GetLinkRoute(string link);

/// <summary>
/// ��ָ����Response��ѹ�뵱ǰLua����ջ
/// </summary>
/// <param name="L">��ǰLua���������</param>
/// <param name="response">Response��</param>
void PushResponseTable(lua_State* L, shared_ptr<Response> response);

/// <summary>
/// ����ת��Ϊ MIME Type
/// </summary>
/// <param name="macro">��</param>
/// <returns>MIME Type</returns>
string ConvertMacroToMIMEType(int macro);

#endif // !_UTIL_H_

