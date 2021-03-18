#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "Moudle.h"
#include "Macros.h"
#include "util.h"

#include <lua.hpp>
#include <SDL.h>

extern SDL_Window* window;
extern SDL_Renderer* renderer;

// ��ʾģ̬����ʾ��Ϣ����
// 3��������ʾ���ڱ��⣨string������ʾ��Ϣ���ݣ�string�����������ͣ�Macro number��
// 0����ֵ
ETHER_API showMessageBox(lua_State * L);

// �������ڣ������˴�����Ϊͼ�λ��ƵȲ�����������
// 5���������ڱ��⣬����������ʾ����ľ��Σ����������������Եı�table��
// 0����ֵ
ETHER_API createWindow(lua_State * L);

// �رմ���
// 0����
// 0����ֵ
ETHER_API closeWindow(lua_State * L);

// ���ô��ڱ���
// 1���������ڱ��⣨string��
// 0����ֵ
ETHER_API setWindowTitle(lua_State * L);

// ��ȡ���ڱ���
// 0����
// 1����ֵ�����ڱ��⣨string��
ETHER_API getWindowTitle(lua_State * L);

// ���ô���ģʽ
// 1����������ģʽ��Macro number��
// 0����ֵ
ETHER_API setWindowMode(lua_State * L);

// ���ô��ڴ�С�Ƿ�ɱ�
// 1�������Ƿ�ɱ䣨boolean��
// 0����ֵ
ETHER_API setWindowResizable(lua_State * L);

// ���ô���͸����
// 1������͸���ȴ�С��number��ȡֵ��Χ0-1��
// 0����ֵ
ETHER_API setWindowOpacity(lua_State * L);

// ���ô��ڴ�С
// 2���������ڿ�ȣ�number)�����ڸ߶ȣ�number��
// 0����ֵ
ETHER_API setWindowSize(lua_State * L);

// ��ȡ���ڴ�С
// 0����
// 2����ֵ�����ڿ�ȣ�number�������ڸ߶ȣ�number��
ETHER_API getWindowSize(lua_State * L);

// ���ô������ߴ�Ĵ�С
// 2��������������ȣ�number�����������߶ȣ�number��
// 0����ֵ
ETHER_API setWindowMaxSize(lua_State * L);

// ��ȡ�������ߴ�Ĵ�С
// 0����
// 2����ֵ����������ȣ�number�����������߶ȣ�number��
ETHER_API getWindowMaxSize(lua_State * L);

// ���ô�����С�ߴ�Ĵ�С
// 2������������С��ȣ�number����������С�߶ȣ�number��
// 0����ֵ
ETHER_API setWindowMinSize(lua_State * L);

// ��ȡ������С�ߴ�Ĵ�С
// 0����
// 2����ֵ��������С��ȣ�number����������С�߶ȣ�number��
ETHER_API getWindowMinSize(lua_State * L);

// ���ô���λ��
// 1����������λ�����꣨table��
// 0����ֵ
ETHER_API setWindowPosition(lua_State * L);

// ��ȡ����λ��
// 0����
// 1����ֵ������λ�����꣨table��
ETHER_API getWindowPosition(lua_State * L);

// ���ô���ͼ�� (Windowsƽ̨�´��ڽ�����ʹ�ÿ�ִ���ļ�ͼ����Դ)
// 1������ͼ�����ݣ�userdata-IMAGE��
// 0����ֵ
ETHER_API setWindowIcon(lua_State * L);

// ʹ�õ�ǰ��ͼ��ɫ��մ�������
// 0����
// 0����ֵ
ETHER_API clearWindow(lua_State * L);

// ����Ⱦ������������ˢ�µ���Ļ��
// 0����
// 0����ֵ
ETHER_API updateWindow(lua_State* L);


class MoudleWindow : public Moudle
{
public:
	MoudleWindow(lua_State* L);
	~MoudleWindow() {};

};

#endif // !_WINDOW_H_