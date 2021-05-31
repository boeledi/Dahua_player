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

#ifndef _DAHUA_P2P_DEFS_H_
#define _DAHUA_P2P_DEFS_H_

//#ifndef __INCLUDE_DAHUA_TOU_DEFS_H__
//#define __INCLUDE_DAHUA_TOU_DEFS_H__

// WIN32 Dynamic Link Library
#ifdef _MSC_VER

#ifdef TOU_DLL_BUILD
#define  TOU_API _declspec(dllexport)
#elif defined TOU_DLL_USE
#define  TOU_API _declspec(dllimport)
#else
#define TOU_API
#endif

#else //_MSC_VER

#define TOU_API

#endif //_MSC_VER



#ifdef  __cplusplus

namespace Dahua{
    namespace Tou{
        
#ifndef DISALLOW_ASSIGN
#define DISALLOW_ASSIGN(TypeName) \
void operator=(const TypeName&)
#endif
        
// A macro to disallow the evil copy constructor and operator= functions
// This should be used in the private: declarations for a class
#ifndef DISALLOW_COPY_AND_ASSIGN
#define DISALLOW_COPY_AND_ASSIGN(TypeName)    \
TypeName(const TypeName&);                    \
DISALLOW_ASSIGN(TypeName)
#endif
        
// Alternative, less-accurate legacy name.
#ifndef DISALLOW_EVIL_CONSTRUCTORS
#define DISALLOW_EVIL_CONSTRUCTORS(TypeName) \
DISALLOW_COPY_AND_ASSIGN(TypeName)
#endif
        
// A macro to disallow all the implicit constructors, namely the
// default constructor, copy constructor and operator= functions.
//
// This should be used in the private: declarations for a class
// that wants to prevent anyone from instantiating it. This is
// especially useful for classes containing only static methods.
#ifndef DISALLOW_IMPLICIT_CONSTRUCTORS
#define DISALLOW_IMPLICIT_CONSTRUCTORS(TypeName) \
TypeName();                                    \
DISALLOW_EVIL_CONSTRUCTORS(TypeName)
#endif
        
    }//Tou
}//Dahua

#endif //__cplusplus

//#endif  //__INCLUDE_DAHUA_TOU_DEFS_H__


#ifdef WIN32
typedef unsigned __int64 UINT64;
#else
typedef unsigned long long UINT64;
#endif

#ifdef  __cplusplus
extern "C" {
#endif

///\brief ����״̬
typedef enum
{
    DHProxyStateUnauthorized,           ///< ������֤ʧ�ܣ����кŷǷ�����Կ����
    DHProxyStateForbidden,              ///< �����ֹ��½���豸ID�ظ����������ܾ���
    DHProxyStateOffline,                ///< ��������
    DHProxyStateOnline,                 ///< ��������
} DHProxyClientProxyState;

///\brief P2Pͨ��״̬
typedef enum
{
    DHP2PChannelStateInit,              ///< P2Pͨ����ʼ����
    DHP2PChannelStateActive,            ///< P2Pͨ������ͨ
    DHP2PChannelStateNonExist,          ///< P2Pͨ��������
	DHP2PChannelStateUnauthorized,      ///< P2Pͨ����Ȩʧ��
} DHProxyClientP2PChannelState;

///\brief ӳ��˿�����ͳ��
typedef struct
{
    UINT64               recvBytes;     ///< �ܽ����ֽ�KB
    UINT64               sendBytes;     ///< �ܷ����ֽ�KB

    double               curRecvRate;   ///< ��ǰ��������Kb/s
    double               curSendRate;   ///< ��ǰ��������Kb/s

    double               lostRate;      ///< ������
    double               liveTime;      ///< ͨ���ʱ��(��S)
} DHProxyClientMapPortRate;

///\brief Զ�̴�����Ϣ
typedef struct
{
    char                remoteId[64];      ///< ������ID
    char                remoteIp[64];      ///< Զ�̴���IP
    int                 remotePort;        ///< Զ�̴���˿�
} DHProxyClientRemotePortInfo;

typedef enum
{
    DHP2POptionPortGuess,                 ///< �˿ڲ²�ѡ�� ����ֵ: 0 �ر� 1 ����
    DHP2POptionSetMTU,                    ///< MTUѡ��	  ����ֵ: ����ֵ
    DHP2POptionUPNP,                      ///< UPNPѡ��	  ����ֵ: 0 �ر� 1 ����
    DHP2POptionRelay,                     ///< Relayѡ��  ����ֵ: 0 ��֧����ת 1 ֧����ת
}DHProxyOption;

///\brief ���
typedef void*	ProxyClientHandler;

#ifdef  __cplusplus
}
#endif

#endif /* _DAHUA_P2P_DEFS_H_ */
