#ifndef _MEDIA_H_
#define _MEDIA_H_

#include "Macros.h"

#include <lua.hpp>
#include <SDL.h>
#include <SDL_mixer.h>

// ���������ļ�
// 1�����������ļ�·��
// 1����ֵ���ɹ��򷵻��������ݣ�userdata-MUSIC����ʧ���򷵻�nil
extern "C" int loadMusic(lua_State * L);

// �ͷ��Ѽ��ص�����
// 1�������������ݣ�userdata-MUSIC��
// 0����ֵ
extern "C" int unloadMusic(lua_State * L);

// �����Ѽ��ص�����
// 2�������������ݣ�userdata-MUSIC�������ֲ��ŵĴ�����number��-1Ϊѭ�����ţ�
// 0����ֵ
extern "C" int playMusic(lua_State * L);

// ʹ�õ���Ч�������Ѽ��ص�����
// 3�������������ݣ�userdata-MUSIC�������ֲ��ŵĴ�����number��-1Ϊѭ�����ţ���������Ч����ʱ�䣨number����λΪ���룩
// 0����ֵ
extern "C" int fadeInMusic(lua_State * L);

// ʹ�õ���Ч��ֹͣ���ڲ��ŵ�����
// 1������������Ч����ʱ�䣨number����λΪ���룩
// 0����ֵ
extern "C" int fadeOutMusic(lua_State * L);

// �������ֲ��ŵ�����
// 1������������С��number��ȡֵ��ΧΪ0-128��
// 0����ֵ
extern "C" int setMusicVolume(lua_State * L);

// ��ȡ��ǰ���ֲ��ŵ�����
// 0����
// 1����ֵ��������С��number��ȡֵ��ΧΪ0-128��
extern "C" int getMusicVolume(lua_State * L);

// ��ͣ��ǰ���ڲ��ŵ�����
// 0����
// 0����ֵ
extern "C" int pauseMusic(lua_State * L);

// �ָ���ǰ��ͣ״̬������
// 0����
// 0����ֵ
extern "C" int resumeMusic(lua_State * L);

// ���²��ŵ�ǰ���ڲ��ŵ�����
// 0����
// 0����ֵ
extern "C" int rewindMusic(lua_State * L);

// ��ȡָ�����ֵ�����
// 1�������������ݣ�userdata-MUSIC��nil��ʾ���ڲ��ŵ����֣�
// 1����ֵ���������ͣ�MACRO number��
extern "C" int getMusicType(lua_State * L);

// ������Ч�ļ�
// 1��������Ч�ļ�·��
// 1����ֵ���ɹ��򷵻���Ч���ݣ�userdata-SOUND����ʧ���򷵻�nil
extern "C" int loadSound(lua_State * L);

// �ͷ��Ѽ��ص���Ч
// 1��������Ч���ݣ�userdata-SOUND��
// 0����ֵ
extern "C" int unloadSound(lua_State * L);

// �����Ѽ��ص���Ч
// 2��������Ч���ݣ�userdata-MUSIC������Ч���ŵĴ�����number��-1Ϊѭ�����ţ�
// 0����ֵ
extern "C" int playSound(lua_State * L);


#endif // !_MEDIA_H_

