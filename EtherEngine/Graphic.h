#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include "Macros.h"

#include <lua.hpp>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL2_gfxPrimitives.h>

extern SDL_Renderer* renderer;

// ��������Ƿ���ʾ
// 1�������Ƿ���ʾ
// �޷���ֵ
extern "C" int setCursorShow(lua_State * L);

// ����ͼ���ļ�
// 1������ͼ���ļ�·��
// 1����ֵ���ɹ��򷵻�ͼƬuserdata��ʧ���򷵻�nil
extern "C" int loadImage(lua_State * L);

// ����ʹ��ColorKey��ʾ͸�������ͼ���ļ�
// 4������ͼ���ļ�·����ColorKey��R��G��B����
// 1����ֵ��-1�������ļ�ʧ�ܣ��������Ѽ��ص�ͼ���ļ���ͼ����еı�־
extern "C" int setImageColorKey(lua_State * L);

// �ͷ��Ѽ��ص�ͼ��
// 1�������Ѽ��ص�ͼ���ļ���ͼ����еı�־
// 1����ֵ��-1���ͷ�ͼ��ʧ�ܣ�0���ͷ�ͼ��ɹ�
extern "C" int unloadImage(lua_State * L);

extern "C" int createTexture(lua_State * L);

extern "C" int destroyTexture(lua_State * L);

// �����Ѽ���ͼ���͸����
// 2�������Ѽ��ص�ͼ���ļ���ͼ����еı�־��͸������ֵ��0-255��
// 1����ֵ��-1������ͼ��͸����ʧ�ܣ�0������ͼ��͸���ȳɹ�
extern "C" int setTextureAlpha(lua_State * L);

// ��ȡ�Ѽ���ͼ��ߴ�
// 1�������Ѽ��ص�ͼ���ļ���ͼ����еı�־
// 2����ֵ��-1��-1����ȡͼ��ߴ�ʧ�ܣ��ɹ��򷵻�ͼ��ĳ��Ϳ�
extern "C" int getImageSize(lua_State * L);

// ��ʾ�Ѽ��ص�ͼ��
// 5�������Ѽ��ص�ͼ���ļ���ͼ����еı�־����ʾλ��x����ʾλ��y����ʾ��ȣ���ʾ�߶ȣ�-1ΪĬ�ϳߴ磩
// 1����ֵ��-1����ʾͼ��ʧ�ܣ�0����ʾͼ��ɹ�
extern "C" int copyTexture(lua_State * L);

// ��ʾ��ת����Ѽ���ͼ��
// 9�������Ѽ��ص�ͼ���ļ���ͼ����еı�־��˳ʱ����ת�Ƕȣ���ת����x���꣬��ת����y���꣬��ʾλ��x����ʾλ��y����ʾ��ȣ�-1ΪĬ�ϳߴ磩����ʾ�߶ȣ�-1ΪĬ�ϳߴ磩����תģʽ
// 1����ֵ��-1����ʾͼ��ʧ�ܣ�0����ʾͼ��ɹ�
extern "C" int copyRotateTexture(lua_State * L);

// ��ʾ�ü�����Ѽ���ͼ��
// 9�������Ѽ��ص�ͼ���ļ���ͼ����еı�־���ü�����x���ü�����y���ü������ȣ�-1ΪĬ�ϳߴ磩���ü�����߶ȣ�-1ΪĬ�ϳߴ磩����ʾλ��x����ʾλ��y����ʾ��ȣ�-1ΪĬ�ϳߴ磩����ʾ�߶ȣ�-1ΪĬ�ϳߴ磩
// 1����ֵ��-1����ʾͼ��ʧ�ܣ�0����ʾͼ��ɹ�
extern "C" int copyReshapeTexture(lua_State * L);

// ��ʾ��ת�Ҳü�����Ѽ���ͼ��
// 13�������Ѽ��ص�ͼ���ļ���ͼ����еı�־����ת�Ƕȣ���ת����x���꣬��ת����y���꣬��תģʽ���ü�����x���ü�����y���ü������ȣ�-1ΪĬ�ϳߴ磩���ü�����߶ȣ�-1ΪĬ�ϳߴ磩����ʾλ��x����ʾλ��y����ʾ��ȣ�-1ΪĬ�ϳߴ磩����ʾ�߶ȣ�-1ΪĬ�ϳߴ磩
// 1����ֵ��-1����ʾͼ��ʧ�ܣ�0����ʾͼ��ɹ�
extern "C" int copyRotateReshapeTexture(lua_State * L);

// ���ô��ڻ�ͼ��ɫ
// 4��������ɫ��R��G��B��A������ȡֵ��Χ��Ϊ0-255��
// �޷���ֵ
extern "C" int setDrawColor(lua_State * L);

// ��ȡ���ڻ�ͼ��ɫ
// �޲���
// 4����ֵ����ɫ��R��G��B��A������ȡֵ��Χ��Ϊ0-255��
extern "C" int getDrawColor(lua_State * L);

// ��ָ��λ�û��Ƶ�
// 2�����������ڵ�x��y����
// �޷���ֵ
extern "C" int point(lua_State * L);

// ��ָ��λ�û���ֱ��
// 4���������x��y���꣬�յ�x��y����
// �޷���ֵ
extern "C" int line(lua_State * L);

// ��ָ��λ�û��ƴ�ֱ��
// 5���������x��y���꣬�յ�x��y���꣬�������
// �޷���ֵ
extern "C" int thickLine(lua_State * L);

// ��ָ��λ�û�����������
// 4�������������Ͻ�x��y���꣬���ο�͸�
// �޷���ֵ
extern "C" int rectangle(lua_State * L);

// ��ָ��λ�û���������
// 4�������������Ͻ�x��y���꣬���ο�͸�
// �޷���ֵ
extern "C" int fillRectangle(lua_State * L);

// ��ָ��λ�û���Բ����������
// 5�������������Ͻ�x��y���꣬���ο�͸ߣ�Բ�ǰ뾶��С
// �޷���ֵ
extern "C" int roundRectangle(lua_State * L);

// ��ָ��λ�û���Բ��������
// 5�������������Ͻ�x��y���꣬���ο�͸ߣ�Բ�ǰ뾶��С
// �޷���ֵ
extern "C" int fillRoundRectangle(lua_State * L);

// ��ָ��λ�û��������Բ��
// 3������Բ��x��y���꣬Բ�뾶
// �޷���ֵ
extern "C" int circle(lua_State * L);

// ��ָ��λ�û������Բ��
// 3������Բ��x��y���꣬Բ�뾶
// �޷���ֵ
extern "C" int fillCircle(lua_State * L);

// ��ָ��λ�û����������Բ
// 4��������Բ����x��y���꣬��Բx��뾶��y��뾶
// �޷���ֵ
extern "C" int ellipse(lua_State * L);

// ��ָ��λ�û��������Բ
// 4��������Բ����x��y���꣬��Բx��뾶��y��뾶
// �޷���ֵ
extern "C" int fillEllipse(lua_State * L);

// ��ָ��λ�û������������
// 5��������������Բ��Բ��x��y���꣬��������Բ�뾶����ʼ�ͽ����Ƕ�
// �޷���ֵ
extern "C" int pie(lua_State * L);

// ��ָ��λ�û����������
// 5��������������Բ��Բ��x��y���꣬��������Բ�뾶����ʼ�ͽ����Ƕ�
// �޷���ֵ
extern "C" int fillPie(lua_State * L);

// ��ָ��λ�û��������������
// 6���������������������x��y����
// �޷���ֵ
extern "C" int triangle(lua_State * L);

// ��ָ��λ�û������������
// 6���������������������x��y����
// �޷���ֵ
extern "C" int fillTriangle(lua_State * L);

// ���������ļ�
// 2�����������ļ�·���������С
// 1����ֵ��-1�������ļ�ʧ�ܣ��������Ѽ��ص������ļ���������еı�־
extern "C" int loadFont(lua_State * L);

// �ͷ��Ѽ��ص�����
// 1�������Ѽ��ص������ļ���������еı�־
// 1����ֵ��-1���ͷ�����ʧ�ܣ�0���ͷ�����ɹ�
extern "C" int unloadFont(lua_State * L);

extern "C" int getFontStyle(lua_State * L);

extern "C" int setFontStyle(lua_State * L);

extern "C" int getFontOutlineWidth(lua_State * L);

extern "C" int setFontOutlineWidth(lua_State * L);

extern "C" int getFontKerning(lua_State * L);

extern "C" int setFontKerning(lua_State * L);

extern "C" int getFontHeight(lua_State * L);

extern "C" int getTextSize(lua_State * L);

extern "C" int getUTF8TextSize(lua_State * L);

extern "C" int createTextImageSolid(lua_State * L);

extern "C" int createUTF8TextImageSolid(lua_State * L);

extern "C" int createTextImageShaded(lua_State * L);

extern "C" int createUTF8TextImageShaded(lua_State * L);

extern "C" int createTextImageBlended(lua_State * L);

extern "C" int createUTF8TextImageBlended(lua_State * L);

// ����Ⱦ������������ˢ�µ���Ļ��
// �޲���
// �޷���ֵ
extern "C" int updateWindow(lua_State * L);


#endif // !_GRAPHIC_H_
