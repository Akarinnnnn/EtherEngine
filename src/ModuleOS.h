#ifndef _OS_H_
#define _OS_H_

#include "Module.h"
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

#define FILEATTRIB_ARCH			0
#define FILEATTRIB_HIDDEN		1
#define FILEATTRIB_NORMAL		2
#define FILEATTRIB_RDONLY		3
#define FILEATTRIB_SUBDIR		4
#define FILEATTRIB_SYSTEM		5

#define PATHMODE_FILE			6
#define PATHMODE_DIR			7
#define PATHMODE_FILEANDDIR		8

#define POWERSTATE_UNKOWN		9
#define POWERSTATE_ONBATTERY	10
#define POWERSTATE_NOBATTERY	11
#define POWERSTATE_CHARGING		12
#define POWERSTATE_CHARGEDN		13

class ModuleOS : public Module
{
public:
	static ModuleOS& Instance();
	~ModuleOS() {};

private:
	ModuleOS();

};

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
ETHER_API getPlatformType(lua_State * L);

// ��ȡ CPU �߼�������
// 0����
// 1����ֵ��CPU �߼���������number��
ETHER_API getCPUCount(lua_State* L);

// ��ȡϵͳ���ڴ��С
// 0����
// 1����ֵ��ϵͳ�ڴ��С��number����λΪMB��
ETHER_API getSystemTotalRAM(lua_State * L);

// ��ȡָ����֯��Ӧ���ڵ�ǰϵͳ�û��µ������ļ���·�������û���򴴽�
// 2��������֯����string����Ӧ������string��
// 1����ֵ�������ļ���·����string��
ETHER_API getAppDataPath(lua_State* L);

/*
* ��ȡ�豸��ǰ��Դ��Ϣ
* 0����
* 1����ֵ���豸��ǰ��Դ��Ϣ��table����ṹ���£���
	{
		state: ����״̬��Macro number��,
		remain_time���ɹ���Ϊʣ��ʹ��ʱ����number������λΪ�룬ʧ�ܻ�ǰ���ǵ�ع�����Ϊ -1��number��
		remain_percentage���ɹ��򷵻�ʣ������ٷֱȣ�number����ȡֵ��ΧΪ 0 - 100��ʧ����Ϊ -1��number��
	}
*/
ETHER_API getPowerInfo(lua_State* L);

/*
* ��ȡָ��Ŀ¼���ļ��б�
* 1������Ŀ¼·����string��
* 1����ֵ���ļ��б�table��
*/
ETHER_API listDirectory(lua_State* L);

/*
* �ж�ָ��·���Ƿ����
* 1��2������Ŀ¼���ļ����ڵ�·����string��������ѡ���ж�ģʽ��Macro number��
* 1����ֵ���Ƿ���ڣ�boolean��
*/
ETHER_API checkPathExist(lua_State* L);

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
		attributes���ļ����ԣ�table����
	}
* ��ʧ���򷵻�nil
*/
ETHER_API getPathInfo(lua_State* L);

/*
* �ϲ�Ŀ¼���ļ���Ϊ����·��
* 2������Ŀ¼��string�����ļ�����string��
* 1����ֵ������·����string��
*/
ETHER_API joinPath(lua_State* L);

/*
* ��·���л�ȡ�ļ���
* 1������·����string��
* 1����ֵ���ļ�����string��
*/
ETHER_API getFileNameFromPath(lua_State* L);

/*
* ��·���л�ȡ��Ŀ¼·��
* 1������·����string��
* 1����ֵ����Ŀ¼·����string��
*/
ETHER_API getBasePathFromPath(lua_State* L);

#endif // !_OS_H_
