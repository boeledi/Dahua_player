/*************************************************************************
 ** ��Ȩ����(C), 2001-2013, �㽭�󻪼����ɷ����޹�˾.
 ** ��Ȩ����.
 **
 ** $Id$
 **
 ** ��������   : Proxy Client C�����
 **
 ** �޸���ʷ     : 2013��12��23�� zhu_long Modification
*************************************************************************/

#ifndef _DAHUA_P2P_PROXY_CLIENT_CWRAP_H_
#define _DAHUA_P2P_PROXY_CLIENT_CWRAP_H_

#include "dahua-p2p-defs.h"

#ifdef  __cplusplus
extern "C" {
#endif    
    

TOU_API ProxyClientHandler DHProxyClientInit(const char* svrip, int svrport, const char* passwd);


TOU_API void DHProxyClientRelease(ProxyClientHandler handler);


TOU_API int DHProxyClientAddPort(ProxyClientHandler handler,
		const char* deviceId, int targetPort, int *localPort);

TOU_API int DHProxyClientDelPort(ProxyClientHandler handler, int port);


TOU_API int DHProxyClientQueryRate(ProxyClientHandler handler,
		int port, DHProxyClientMapPortRate *rate);


TOU_API int DHProxyClientChannelstate(ProxyClientHandler handler, int port, int *state);


TOU_API int DHProxyClientState(ProxyClientHandler handler, int *state);

TOU_API int DHProxyClientServerState(ProxyClientHandler handler, const char* deviceId, int *state);


TOU_API int DHProxyClientQueryRemoetInfo(ProxyClientHandler handler, int port, DHProxyClientRemotePortInfo *info);


TOU_API ProxyClientHandler DHProxyClientInitWtihName(const char* svrip, int svrport, const char* passwd, const char* username);


TOU_API	int DHProxySetOption(ProxyClientHandler handler, DHProxyOption option, int value);


TOU_API int DHProxyGetOption(ProxyClientHandler handler, DHProxyOption option);

#ifdef  __cplusplus
}
#endif

#endif /* _DAHUA_P2P_PROXY_CLIENT_CWRAP_H_ */
