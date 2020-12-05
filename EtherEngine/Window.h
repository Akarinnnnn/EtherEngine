#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <lua.hpp>
#include <SDL.h>
#include "Macros.h"

#include <string>
using namespace std;

extern SDL_Window* window;
extern SDL_Renderer* renderer;

// ��ʾģ̬����ʾ��Ϣ����
// 3���������⣨string������ʾ��Ϣ���ݣ�string�����������ͣ�Macro number��
// 0����ֵ
extern "C" int showMessageBox(lua_State * L);

// �������ڣ������˴�����Ϊͼ�λ��ƵȲ�����������
// 5���������ڱ��⣬����������ʾ����ľ��Σ�table�������������������Եı�table��
// 0����ֵ
extern "C" int createWindow(lua_State * L);

// �رմ���
// 0����
// 0����ֵ
extern "C" int closeWindow(lua_State * L);

// ���ô��ڱ���
// 1�������������ݣ�string��
// 0����ֵ
extern "C" int setWindowTitle(lua_State * L);

// ��ȡ���ڱ���
// 0����
// 1����ֵ���������ݣ�string��
extern "C" int getWindowTitle(lua_State * L);

// ���ô���ģʽ
// 1����������ģʽ��Macro number��
// 0����ֵ
extern "C" int setWindowMode(lua_State * L);

// ���ô��ڴ�С�Ƿ�ɱ�
// 1�������Ƿ�ɱ䣨boolean��
// 0����ֵ
extern "C" int setWindowResizable(lua_State * L);

// ���ô���͸����
// 1������͸���ȴ�С��number��ȡֵ��Χ0-1��
// 0����ֵ
extern "C" int setWindowOpacity(lua_State * L);

// ���ô��ڴ�С
// 2���������ڿ�ȣ�number)�����ڸ߶ȣ�number��
// 0����ֵ
extern "C" int setWindowSize(lua_State * L);

// ��ȡ���ڴ�С
// 0����
// 2����ֵ�����ڿ�ȣ�number�������ڸ߶ȣ�number��
extern "C" int getWindowSize(lua_State * L);

// ���ô������ߴ�Ĵ�С
// 2��������������ȣ�number�����������߶ȣ�number��
// 0����ֵ
extern "C" int setWindowMaxSize(lua_State * L);

// ��ȡ�������ߴ�Ĵ�С
// 0����
// 2����ֵ����������ȣ�number�����������߶ȣ�number��
extern "C" int getWindowMaxSize(lua_State * L);

// ���ô�����С�ߴ�Ĵ�С
// 2������������С��ȣ�number����������С�߶ȣ�number��
// 0����ֵ
extern "C" int setWindowMinSize(lua_State * L);

// ��ȡ������С�ߴ�Ĵ�С
// 0����
// 2����ֵ��������С��ȣ�number����������С�߶ȣ�number��
extern "C" int getWindowMinSize(lua_State * L);

// ���ô�������
// 2����������λ�õ�x���꣨number��������λ�õ�y���꣨number��
// 0����ֵ
extern "C" int setWindowPosition(lua_State * L);

// ��ȡ��������
// 0����
// 2����ֵ������λ�õ�x���꣨number��������λ�õ�y���꣨number��
extern "C" int getWindowPosition(lua_State * L);

// ʹ�õ�ǰ��ͼ��ɫ��մ�������
// 0����
// 0����ֵ
extern "C" int clearWindow(lua_State * L);

#endif // !_WINDOW_H_
