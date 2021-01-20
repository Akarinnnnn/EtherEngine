#ifndef _OS_H_
#define _OS_H_

#include "Moudle.h"
#include "Macros.h"

#include <lua.hpp>
#include <SDL.h>

#include <string>
using namespace std;
#ifdef __WINDOWS__
#include <io.h>
#else
#include ""
#endif

// ��ȡ�������е�Ŀ¼
// 0����
// 1����ֵ����������Ŀ¼��string��
ETHER_API getBasePath(lua_State * L);

// ���ü��а��ı�
// 1���������а��ı���string��
// 0����ֵ
ETHER_API setClipboardText(lua_State * L);

// ��ȡ���а��ı�
// 0����
// 1����ֵ�����а��ı���string��
ETHER_API getClipboardText(lua_State * L);

// ��ȡƽ̨����
// 0����
// 1����ֵ��ƽ̨���ͣ�string��
ETHER_API getPlatform(lua_State * L);

// ��ȡϵͳ���ڴ��С
// 0����
// 1����ֵ��ϵͳ�ڴ棨number����λMB��
ETHER_API getSystemRAM(lua_State * L);

/*
* ��ȡĿ¼���ļ���Ϣ
* 1������Ŀ¼·����string��
* 1����ֵ���ļ��б�table��
*/
ETHER_API listDirectory(lua_State* L);

/*
* �ж�ָ��·���Ƿ����
* 1��2������Ŀ¼���ļ����ڵ�·����string��������ѡ���ж�ģʽ��Macro number��
* 1����ֵ���Ƿ���ڣ�boolean��
*/
ETHER_API ifPathExist(lua_State* L);

/*
* ��ȡָ��·������Ϣ
* 1������Ŀ¼���ļ����ڵ�·����string��
* 1����ֵ���ɹ��򷵻�·����Ϣ��table����ṹ���£���
	{
		name���ļ�����string����
		size���ļ���С��number����
		time��{
			create������ʱ�䣨number����
			access�����һ�η���ʱ�䣨number����
			write�����һ���޸�ʱ�䣨number����
		}��
		attributes���ļ����ԣ�
	}
* ��ʧ���򷵻�nil
*/
ETHER_API getPathInfo(lua_State* L);

/*
* �ϲ�Ŀ¼���ļ���Ϊһ��·��
* 2������Ŀ¼��string�����ļ�����string��
* 1����ֵ��·����string��
*/
ETHER_API joinPath(lua_State* L);


class MoudleOS : public Moudle
{
public:
	MoudleOS(lua_State* L);
	~MoudleOS() {};

};

#endif // !_OS_H_
