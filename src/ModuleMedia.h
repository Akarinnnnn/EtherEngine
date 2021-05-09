#ifndef _MEDIA_H_
#define _MEDIA_H_

#include "Module.h"
#include "Macros.h"

#include <lua.hpp>
#include <SDL.h>
#include <SDL_mixer.h>

#define MUSIC_TYPE_WAV		1308
#define MUSIC_TYPE_MP3		1309
#define MUSIC_TYPE_OGG		1310
#define MUSIC_TYPE_CMD		1311
#define MUSIC_TYPE_MOD		1312
#define MUSIC_TYPE_MID		1313
#define MUSIC_TYPE_UNKONWN	1314

#define METANAME_MUSIC		"Graphic.Music"
#define METANAME_SOUND		"Graphic.Sound"

#define GetMusicDataAtFirstPos() (Mix_Music*)(*(void**)luaL_checkudata(L, 1, METANAME_MUSIC))
#define GetSoundDataAtFirstPos() (Mix_Chunk*)(*(void**)luaL_checkudata(L, 1, METANAME_SOUND))

#define CheckMusicDataAtFirstPos(music) luaL_argcheck(L, music, 1, "get music data failed")
#define CheckSoundDataAtFirstPos(sound) luaL_argcheck(L, sound, 1, "get sound data failed")

class ModuleMedia : public Module
{
public:
	static ModuleMedia& Instance();
	~ModuleMedia() {};

private:
	ModuleMedia();

};

// ���������ļ�
// 1�����������ļ�·��
// 1����ֵ���ɹ��򷵻��������ݣ�userdata-MUSIC����ʧ���򷵻�nil
ETHER_API loadMusic(lua_State * L);

// �ͷ��Ѽ��ص�����
// 1�������������ݣ�userdata-MUSIC��
// 1����ֵ��nil
ETHER_API __gc_Music(lua_State * L);

// �����Ѽ��ص�����
// 2�������������ݣ�userdata-MUSIC�������ֲ��ŵĴ�����number��-1Ϊѭ�����ţ�
// 0����ֵ
ETHER_API playMusic(lua_State * L);

// ʹ�õ���Ч�������Ѽ��ص�����
// 3�������������ݣ�userdata-MUSIC�������ֲ��ŵĴ�����number��-1Ϊѭ�����ţ���������Ч����ʱ�䣨number����λΪ���룩
// 0����ֵ
ETHER_API playMusicWithFadeIn(lua_State * L);

// ֹͣ���ڲ��ŵ�����
// 0����
// 0����ֵ
ETHER_API stopMusic(lua_State* L);

// ʹ�õ���Ч��ֹͣ���ڲ��ŵ�����
// 1������������Ч����ʱ�䣨number����λΪ���룩
// 0����ֵ
ETHER_API stopMusicWithFadeOut(lua_State * L);

// �������ֲ��ŵ�����
// 1������������С��number��ȡֵ��ΧΪ0-128��
// 0����ֵ
ETHER_API setMusicVolume(lua_State * L);

// ��ȡ��ǰ���ֲ��ŵ�����
// 0����
// 1����ֵ��������С��number��ȡֵ��ΧΪ0-128��
ETHER_API getMusicVolume(lua_State * L);

// ��ͣ��ǰ���ڲ��ŵ�����
// 0����
// 0����ֵ
ETHER_API pauseMusic(lua_State * L);

// �ָ���ǰ��ͣ״̬������
// 0����
// 0����ֵ
ETHER_API resumeMusic(lua_State * L);

// ���²��ŵ�ǰ���ڲ��ŵ�����
// 0����
// 0����ֵ
ETHER_API rewindMusic(lua_State * L);

// ��ȡָ�����ֵ�����
// 1�������������ݣ�userdata-MUSIC��nil��ʾ���ڲ��ŵ����֣�
// 1����ֵ���������ͣ�MACRO number��
ETHER_API music_GetType(lua_State * L);

// ������Ч�ļ�
// 1��������Ч�ļ�·��
// 1����ֵ���ɹ��򷵻���Ч���ݣ�userdata-SOUND����ʧ���򷵻�nil
ETHER_API loadSound(lua_State * L);

// �ͷ��Ѽ��ص���Ч
// 1��������Ч���ݣ�userdata-SOUND��
// 1����ֵ��nil
ETHER_API __gc_Sound(lua_State * L);

// �����Ѽ��ص���Ч
// 2��������Ч���ݣ�userdata-SOUND������Ч���ŵĴ�����number��-1Ϊѭ�����ţ�
// 0����ֵ
ETHER_API sound_Play(lua_State * L);

#endif // !_MEDIA_H_

