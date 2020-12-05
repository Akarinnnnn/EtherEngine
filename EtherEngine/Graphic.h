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
// 1�������Ƿ���ʾ��boolean��
// 0����ֵ
extern "C" int setCursorShow(lua_State * L);

// ����ͼ���ļ�
// 1������ͼ���ļ�·����string��
// 1����ֵ���ɹ��򷵻�ͼ�����ݣ�userdata-IMAGE����ʧ���򷵻�nil
extern "C" int loadImage(lua_State * L);

// ���õ�ͼƬ�ļ��Ƿ�����ָ����ColorKey�����õ�Color����͸����
// 2������ͼ���ļ���userdata-IMAGE�����Ƿ����ã�boolean����ColorKey��table��
// 0����ֵ
extern "C" int setImageColorKey(lua_State * L);

// �ͷ��Ѽ��ص�ͼ��
// 1������ͼ�����ݣ�userdata-IMAGE��
// 0����ֵ
extern "C" int unloadImage(lua_State * L);

// ��ͼ�����ݴ������ڴ��ڵĿ���Ⱦ���������ڴ����������֮����У�
// 1������ͼ�����ݣ�userdata-IMAGE��
// 1����ֵ���������ݣ�userdata-TEXTURE��
extern "C" int createTexture(lua_State * L);

// ������������
// 1�������������ݣ�userdata-TEXTURE��
// 0����ֵ
extern "C" int destroyTexture(lua_State * L);

// ��������͸����
// 2�������������ݣ�userdata-TEXTURE����͸������ֵ��number��ȡֵ��Χ0-255��
// 0����ֵ
extern "C" int setTextureAlpha(lua_State * L);

// ��ȡ�Ѽ���ͼ��ߴ�
// 1������ͼ�����ݣ�userdata-IMAGE��
// 2����ֵ��ͼ���ȣ�number����ͼ��߶ȣ�number��
extern "C" int getImageSize(lua_State * L);

// ������������Ⱦ��������
// 2�������������ݣ�userdata-TEXTURE��������������ʾ����ľ��Σ�table��
// 0����ֵ
extern "C" int copyTexture(lua_State * L);

// ����ת�������������Ⱦ��������
// 5�������������ݣ�userdata-TEXTURE������ת�Ƕȣ�number������ת�������꣨table������תģʽ��table��������������ʾ����ľ��Σ�table��
// 0����ֵ
extern "C" int copyRotateTexture(lua_State * L);

// ���ü��������������Ⱦ��������
// 3�������������ݣ�userdata-TEXTURE�������������ü�����ľ��Σ�table��������������ʾ����ľ��Σ�table��
// 0����ֵ
extern "C" int copyReshapeTexture(lua_State * L);

// ����ת�Ҳü��������������Ⱦ��������
// 6�������������ݣ�userdata-TEXTURE������ת�Ƕȣ�number������ת�������꣨table������תģʽ��table�������������ü�����ľ��Σ�table��������������ʾ����ľ��Σ�table��
// 0����ֵ
extern "C" int copyRotateReshapeTexture(lua_State * L);

// ���ô��ڻ�ͼ��ɫ
// 1������������ɫ��RGBA��table��ȡֵ��Χ��Ϊ0-255��
// 0����ֵ
extern "C" int setDrawColor(lua_State * L);

// ��ȡ���ڻ�ͼ��ɫ
// 0����
// 1����ֵ������������ɫ��RGBA��table��ȡֵ��Χ��Ϊ0-255��
extern "C" int getDrawColor(lua_State * L);

// ��ָ��λ�û��Ƶ�
// 1�����������꣨table��
// 0����ֵ
extern "C" int point(lua_State * L);

// ��ָ��λ�û���ֱ��
// 2������������꣨table�����յ����꣨table��
// 0����ֵ
extern "C" int line(lua_State * L);

// ��ָ��λ�û��ƴ�ֱ��
// 3������������꣨table�����յ����꣨table����������ȣ�number��
// �޷���ֵ
extern "C" int thickLine(lua_State * L);

// ��ָ��λ�û�����������
// 1����������������ʾ����ľ��Σ�table��
// 0����ֵ
extern "C" int rectangle(lua_State * L);

// ��ָ��λ�û���������
// 1����������������ʾ����ľ��Σ�table��
// 0����ֵ
extern "C" int fillRectangle(lua_State * L);

// ��ָ��λ�û���Բ����������
// 2����������������ʾ����ľ��Σ�table����Բ�ǰ뾶��С��number��
// 0����ֵ
extern "C" int roundRectangle(lua_State * L);

// ��ָ��λ�û���Բ��������
// 2����������������ʾ����ľ��Σ�table����Բ�ǰ뾶��С��number��
// 0����ֵ
extern "C" int fillRoundRectangle(lua_State * L);

// ��ָ��λ�û��������Բ��
// 2������Բ�����꣨table����Բ�뾶��number��
// 0����ֵ
extern "C" int circle(lua_State * L);

// ��ָ��λ�û������Բ��
// 2������Բ�����꣨table����Բ�뾶��number��
// 0����ֵ
extern "C" int fillCircle(lua_State * L);

// ��ָ��λ�û����������Բ
// 3��������Բ�������꣨table������Բx��뾶��number������Բy��뾶��number��
// 0����ֵ
extern "C" int ellipse(lua_State * L);

// ��ָ��λ�û��������Բ
// 3��������Բ�������꣨table������Բx��뾶��number������Բy��뾶��number��
// 0����ֵ
extern "C" int fillEllipse(lua_State * L);

// ��ָ��λ�û������������
// 4��������������Բ��Բ�����꣨table������������Բ�İ뾶��number�������ο�ʼ�Ƕȣ�number�������ν����Ƕȣ�number�������δ���������Բ��Ϊԭ��Ķ�ά�ѿ�������ϵ��x��������ʼ���ƣ��Ƕȵ�������Ϊ˳ʱ�뷽��
// 0����ֵ
extern "C" int pie(lua_State * L);

// ��ָ��λ�û����������
// 4��������������Բ��Բ�����꣨table������������Բ�İ뾶��number�������ο�ʼ�Ƕȣ�number�������ν����Ƕȣ�number�������δ���������Բ��Ϊԭ��Ķ�ά�ѿ�������ϵ��x��������ʼ���ƣ��Ƕȵ�������Ϊ˳ʱ�뷽��
// 0����ֵ
extern "C" int fillPie(lua_State * L);

// ��ָ��λ�û��������������
// 6��������һ���������꣨table�����ڶ����������꣨table�����������������꣨table��
// 0����ֵ
extern "C" int triangle(lua_State * L);

// ��ָ��λ�û������������
// 6��������һ���������꣨table�����ڶ����������꣨table�����������������꣨table��
// 0����ֵ
extern "C" int fillTriangle(lua_State * L);

// ���������ļ�
// 2�����������ļ�·����string���������С��number��
// 1����ֵ���ɹ��򷵻��������ݣ�userdata-FONT����ʧ���򷵻�nil
extern "C" int loadFont(lua_State * L);

// �ͷ��Ѽ��ص�����
// 1�������������ݣ�userdata-FONT��
// 0����ֵ
extern "C" int unloadFont(lua_State * L);

// ��ȡ�Ѽ����������ʽ
// 1�������������ݣ�userdata-FONT��
// 1����ֵ����������������ʽ�ı�table��
extern "C" int getFontStyle(lua_State * L);

// �����Ѽ����������ʽ
// 2�������������ݣ�userdata-FONT������������������ʽ�ı�table��
// 0����ֵ
extern "C" int setFontStyle(lua_State * L);

// ��ȡ�Ѽ�������������߿��
// 1�������������ݣ�userdata-FONT��
// 1����ֵ�������߿�ȣ�number��
extern "C" int getFontOutlineWidth(lua_State * L);

// �����Ѽ�������������߿��
// 2�������������ݣ�userdata-FONT���������߿�ȣ�number��
// 0����ֵ
extern "C" int setFontOutlineWidth(lua_State * L);

// ��ȡ������
// 1�������������ݣ�userdata-FONT��
// 1����ֵ�������ࣨnumber��
extern "C" int getFontKerning(lua_State * L);

// ����������
// 2�������������ݣ�userdata-FONT���������ࣨnumber��
// 0����ֵ
extern "C" int setFontKerning(lua_State * L);

// ��ȡ����߶�
// 1�������������ݣ�userdata-FONT��
// 1����ֵ������߶ȣ�number��
extern "C" int getFontHeight(lua_State * L);

// ��ȡ�ı��ߴ�
// 2�������������ݣ�userdata-FONT�����ı����ݣ�string��
// 2����ֵ���ı���ȣ�number�����ı��߶ȣ�number��
extern "C" int getTextSize(lua_State * L);

// ��ȡUTF-8�����ʽ���ı��ߴ�
// 2�������������ݣ�userdata-FONT����UTF-8�����ʽ���ı����ݣ�string��
// 2�������ı���ȣ�number�����ı��߶ȣ�number��
extern "C" int getUTF8TextSize(lua_State * L);

// ʹ��Solidģʽ�����ı�ͼ��
// 3�������������ݣ�userdata-FONT�����ı����ݣ�string�������������ı���ɫ��RGBA��table��ȡֵ��Χ��Ϊ0-255��
// 1����ֵ���ɹ��򷵻�ͼ�����ݣ�userdata-IMAGE����ʧ���򷵻�nil
extern "C" int createTextImageSolid(lua_State * L);

// ʹ��Solidģʽ����UTF-8�����ʽ���ı�ͼ��
// 3�������������ݣ�userdata-FONT����UTF-8�����ʽ���ı����ݣ�string�������������ı���ɫ��RGBA��table��ȡֵ��Χ��Ϊ0-255��
// 1����ֵ���ɹ��򷵻�ͼ�����ݣ�userdata-IMAGE����ʧ���򷵻�nil
extern "C" int createUTF8TextImageSolid(lua_State * L);

// ʹ��Shadedģʽ�����ı�ͼ��
// 3�������������ݣ�userdata-FONT�����ı����ݣ�string�������������ı���ɫ��RGBA��table��ȡֵ��Χ��Ϊ0-255�������������ı�������ɫ��RGBA��table��ȡֵ��Χ��Ϊ0-255��
// 1����ֵ���ɹ��򷵻�ͼ�����ݣ�userdata-IMAGE����ʧ���򷵻�nil
extern "C" int createTextImageShaded(lua_State * L);

// ʹ��Shadedģʽ����UTF-8�����ʽ���ı�ͼ��
// 3�������������ݣ�userdata-FONT����UTF-8�����ʽ���ı����ݣ�string�������������ı���ɫ��RGBA��table��ȡֵ��Χ��Ϊ0-255�������������ı�������ɫ��RGBA��table��ȡֵ��Χ��Ϊ0-255��
// 1����ֵ���ɹ��򷵻�ͼ�����ݣ�userdata-IMAGE����ʧ���򷵻�nil
extern "C" int createUTF8TextImageShaded(lua_State * L);

// ʹ��Blendedģʽ�����ı�ͼ��
// 3�������������ݣ�userdata-FONT�����ı����ݣ�string�������������ı���ɫ��RGBA��table��ȡֵ��Χ��Ϊ0-255��
// 1����ֵ���ɹ��򷵻�ͼ�����ݣ�userdata-IMAGE����ʧ���򷵻�nil
extern "C" int createTextImageBlended(lua_State * L);

// ʹ��Blendedģʽ����UTF-8�����ʽ���ı�ͼ��
// 3�������������ݣ�userdata-FONT����UTF-8�����ʽ���ı����ݣ�string�������������ı���ɫ��RGBA��table��ȡֵ��Χ��Ϊ0-255��
// 1����ֵ���ɹ��򷵻�ͼ�����ݣ�userdata-IMAGE����ʧ���򷵻�nil
extern "C" int createUTF8TextImageBlended(lua_State * L);

// ����Ⱦ������������ˢ�µ���Ļ��
// 0����
// 0����ֵ
extern "C" int updateWindow(lua_State * L);


#endif // !_GRAPHIC_H_
