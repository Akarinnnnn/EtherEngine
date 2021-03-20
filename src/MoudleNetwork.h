#ifndef _NETWORK_H_
#define _NETWORK_H_

#include "Moudle.h"
#include "Macros.h"

#include <lua.hpp>
#include <httplib.h>
using namespace httplib;

#define MIMETYPE_CSS 1315
#define MIMETYPE_CSV 1316
#define MIMETYPE_TEXT 1317
#define MIMETYPE_VTT 1318
#define MIMETYPE_HTML 1319
#define MIMETYPE_APNG 1320
#define MIMETYPE_SVG 1321
#define MIMETYPE_WEBP 1322
#define MIMETYPE_ICO 1323
#define MIMETYPE_TIFF 1324
#define MIMETYPE_JPG 1325
#define MIMETYPE_AVIF 1326
#define MIMETYPE_BMP 1327
#define MIMETYPE_GIF 1328
#define MIMETYPE_PNG 1329
#define MIMETYPE_MP4 1330
#define MIMETYPE_MPEG 1331
#define MIMETYPE_WEBM 1332
#define MIMETYPE_MPGA 1333
#define MIMETYPE_WEBA 1334
#define MIMETYPE_WAV 1335
#define MIMETYPE_OTF 1336
#define MIMETYPE_TTF 1337
#define MIMETYPE_WOFF 1338
#define MIMETYPE_WOFF2 1339
#define MIMETYPE_7Z 1340
#define MIMETYPE_ATOM 1341
#define MIMETYPE_PDF 1342
#define MIMETYPE_JS 1343
#define MIMETYPE_JSON 1344
#define MIMETYPE_RSS 1345
#define MIMETYPE_TAR 1346
#define MIMETYPE_XHTML 1347
#define MIMETYPE_XSLT 1348
#define MIMETYPE_XML 1349
#define MIMETYPE_GZ 1350
#define MIMETYPE_ZIP 1351
#define MIMETYPE_WASM 1352
#define MIMETYPE_MP3 1353

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
void PushResponseTable(lua_State* L, Result result);

/// <summary>
/// ����ת��Ϊ MIME Type
/// </summary>
/// <param name="macro">��</param>
/// <returns>MIME Type</returns>
string ConvertMacroToMIMEType(int macro);

/*
* �������л�ȡ����
* 1���������ӣ�string��
* 1����ֵ��������string��
*/
ETHER_API getLinkDomain(lua_State* L);

/*
* �������л�ȡ·��
* 1���������ӣ�string��
* 1����ֵ��·�ɣ�string��
*/
ETHER_API getLinkRoute(lua_State* L);

/*
* ʹ��Get�������ָ������
* 1��2���������ӣ�string��������ѡ��HttpHeaders��table��
* 1����ֵ���ɹ��򷵻�Response��table����
	{
		statue��״̬�루number����
		headers����Ӧͷ��table����
		body�����ģ�string����
	}
* ��ʧ���򷵻�nil
*/

ETHER_API requestGet(lua_State* L);

/*
* ʹ��Post������ָ�����ӷ�������
* 3��4���������ӣ�string���������壨string����MIME Type��Macro number��������ѡ��HttpHeaders��table��
* 1����ֵ���ɹ��򷵻�Response��table����ṹ���£�:
	{
		statue��״̬�루number����
		headers����Ӧͷ��table����
		body�����ģ�string����
	}
* ��ʧ���򷵻�nil
*/
ETHER_API requestPost(lua_State* L);


class MoudleNetwork : public Moudle
{
public:
	MoudleNetwork(lua_State* L, string name);
	~MoudleNetwork() {};

};

#endif // !_NETWORK_H_

