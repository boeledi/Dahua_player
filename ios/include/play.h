/************************************************************************/
/* dhplay   �汾:  3.34			                                    */
/************************************************************************/

#ifndef _DHPLAY_H
#define _DHPLAY_H

#include "dahua-play-defs.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
/************************************************************************/
/* �ӿ�		                                                            */
/************************************************************************/

//------------------------------------------------------------------------
// ����: PLAY_OpenFile
// ����: �򿪲����ļ��������ڲ����ļ�֮ǰ����. �ļ����ܳ���4G��С��4K
// ����: nPort,ͨ����
//		 sFileName,�ļ���
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenFile(LONG nPort,LPSTR sFileName);

//------------------------------------------------------------------------
// ����: PLAY_CloseFile
// ����: �ر��ļ�, ��PLAY_Stop�����
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CloseFile(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_OpenStream
// ����: ��������
// ����: nPort,ͨ����
//		 pFileHeadBuf,Ŀǰ��ʹ��,��NULL.
//		 nSize,Ŀǰ������,��0.
//		 nBufPoolSize,���ò������д���������Ļ�������С.
//			��Χ��[SOURCE_BUF_MIN,SOURCE_BUF_MAX].һ����Ϊ900*1024�������
//			���͹�����Ծ���,�ɵ�С��ֵ,������ݴ��䲻����,�������ֵ.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenStream(LONG nPort,PBYTE pFileHeadBuf,DWORD nSize,DWORD nBufPoolSize);

//------------------------------------------------------------------------
// ����: PLAY_CloseStream
// ����: �ر���
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CloseStream(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_Play
// ����: ��ʼ����.����Ѿ�����,�ı䵱ǰ����״̬Ϊ�����ٶȲ���.
// ����: nPort,ͨ����
//		 hWnd,���Ŵ��ھ��
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Play(LONG nPort, HWND hWnd);

//------------------------------------------------------------------------
// ����: PLAY_Stop
// ����: ֹͣ����
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Stop(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_InputData
// ����: ����������,PLAY_Play֮��ʹ��
// ����: nPort,ͨ����
//		 pBuf,��������ַ
//		 nSize,��������С
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.��ʧ��,һ���ǻ���������,�û�����ͣ
//			���룬һ��ʱ��֮������������ȷ�����ſⲻ��ʧ���ݡ�
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_InputData(LONG nPort,PBYTE pBuf,DWORD nSize);

//------------------------------------------------------------------------
// ����: PLAY_Pause
// ����: ��ͣ���߻ָ�����
// ����: nPort,ͨ����
//		 nPause,TRUE��ͣ,FLASE�ָ�
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Pause(LONG nPort,DWORD nPause);

//------------------------------------------------------------------------
// ����: PLAY_Fast
// ����: �����ٶȷ�Ϊ�ż�,�����ٶȷֱ�Ϊÿ�벥��1,3,6,12,25,50,75,100,125֡
//		 ͼ��.ÿ�ε��ò����ٶ�����һ��,������4��,Ҫ�ָ��������ŵ���
//		 PLAY_Play,�ӵ�ǰλ�ÿ�ʼ��������.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Fast(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_Slow
// ����: ÿ�ε��ò����ٶȽ�һ��,������4��,Ҫ�ָ��������ŵ���PLAY_Play.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Slow(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_OneByOne
// ����: ���岥��,Ҫ�ָ��������ŵ���PLAY_ Play.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OneByOne(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetPlayPos
// ����: �����ļ�����ָ������λ��(�ٷֱ�)
// ����: nPort,ͨ����
//		 fRelativePos,�ļ����ȵİٷֱ�
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayPos(LONG nPort,float fRelativePos);

//------------------------------------------------------------------------
// ����: PLAY_SetPlayDirection
// ����: ���ò��ŷ���
// ����: nPort,ͨ����
//		 emDirection,���ŷ���0����ǰ��1�����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayDirection(LONG nPort, DWORD emDirection);

//------------------------------------------------------------------------
// ����: PLAY_GetPlayPos
// ����: ��ȡ�ļ�����ָ������λ��(�ٷֱ�)
// ����: nPort,ͨ����
// ����: float,�ļ����ȵ����λ��,��Χ0-100%
//------------------------------------------------------------------------
PLAYSDK_API float CALLMETHOD PLAY_GetPlayPos(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetFileEndMsg
// ����: �����ļ�����ʱҪ���͵���Ϣ
// ����: nPort,�˿ں�
//       hWnd,��Ϣ���ʹ���
//       nMsg,�û��Զ�����������Ϣ�������ŵ��ļ�����ʱ�û���hWnd���ڹ�����
//			�յ������Ϣ������Ϣ�е�wParam����lParam�����Ի��nPort��ֵ.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileEndMsg(LONG nPort,HWND hWnd,UINT nMsg);

//------------------------------------------------------------------------
// ����: PLAY_SetVolume
// ����: ��������,���õ�������ָ�������������,��Ӱ������������Ӧ��.
// ����: nPort,ͨ����
//		 nVolume,������ֵ,��Χ[0,0xFFFF]
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVolume(LONG nPort,WORD nVolume);

//------------------------------------------------------------------------
// ����: PLAY_StopSound
// ����: �رն�ռ��ʽ����
// ����: 
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopSound();

//------------------------------------------------------------------------
// ����: PLAY_PlaySound
// ����: ��ռ��ʽ������,ͬһʱ��ֻ����һ·����,��������Ѿ��������򿪣���
//		 �Զ��ر�ԭ���Ѿ��򿪵�����.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_PlaySound(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetFileTime
// ����: ��ȡ�ļ���ʱ��
// ����: nPort,ͨ����
// ����: �ļ��ܵ�ʱ�䳤��ֵ,��λ��.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetFileTime(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetPlayedTime
// ����: ��ȡ��ǰ�ļ�����ʱ��
// ����: nPort,ͨ����
// ����: �ļ���ǰ���ŵ�ʱ��,��λ��
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetPlayedTime(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetPlayedFrames
// ����: ��ȡ�Ѳ��ŵ�����
// ����: nPort,ͨ����
// ����: �Ѿ��������Ƶ֡��
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetPlayedFrames(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetDecodeCallBack
// ����: ���ý���ص�,�滻�������е���ʾ����,���û��Լ�������ʾ,�ú�����
//			PLAY_Play֮ǰ����,��PLAY_Stopʱ�Զ�ʧЧ,�´ε���PLAY_Play֮ǰ
//			��Ҫ��������.���벿�ֲ������ٶ�,ֻҪ�û��ӻص������з���,������
//			�ͻ������һ��������.������ֻ���벻��ʾ�����Ρ�
// ����: nPort,ͨ����
//		 cbDec,����ص�����ָ��,����ΪNULL.�ص�����������������:
//			nPort,ͨ����
//			pFrameDecodeInfo,����������Ƶ����
//			pFrameInfo,ͼ���������Ϣ,��μ�FRAME_INFO�ṹ��
//			pUser,�û��Զ������
//		 pUser,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fCBDecode)(LONG nPort, FRAME_DECODE_INFO* pFrameDecodeInfo, FRAME_INFO_EX* pFrameInfo, void* pUser);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecodeCallBack(LONG nPort, fCBDecode cbDec, void* pUser);

//------------------------------------------------------------------------
// ����: PLAY_SetDisplayCallBack
// ����: ������Ƶץͼ�ص�����.���Ҫֹͣ�ص�,���԰ѻص�����ָ����ΪNULL,��
//			�����������κ�ʱ�����
// ����: nPort,ͨ����
//		 DisplayCBFun,ץͼ�ص�����,����ΪNULL,�������������
//			nPort,ͨ����
//			pBuf,����ͼ������
//			nSize,����ͼ�����ݴ�С
//			nWidth,�����,��λ����
//			nHeight,�����
//			nStamp,ʱ����Ϣ����λ����
//			nType,��������,T_RGB32,T_UYVY,����궨��˵��
//			nReceaved,��Ӧ�û��Զ������
//		 pUserData,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fDisplayCBFun)(LONG nPort,char * pBuf,LONG nSize,LONG nWidth,LONG nHeight,LONG nStamp,LONG nType, void* pReserved);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDisplayCallBack(LONG nPort, fDisplayCBFun DisplayCBFun, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_ConvertToBmpFile
// ����: ͼ���ʽתΪBMP��ʽ.
// ����: pBuf,ͼ������ָ��
//		 nSize,ͼ�����ݴ�С
//		 nWidth,ͼ�����
//		 nHeight,ͼ��߶�
//		 nType,��������.T_RGB32,T_UYVY��.
//		 sFileName,Ҫ������ļ���.�����BMP��Ϊ�ļ���չ��.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ConvertToBmpFile(char * pBuf,LONG nSize,LONG nWidth,LONG nHeight,LONG nType, char *sFileName);

//------------------------------------------------------------------------
// ����: PLAY_ConvertToJpegFile
// ����: ͼ���ʽתΪJPEG��ʽ.
// ����: pYUVBuf,ͼ������ָ��
//		 nWidth,ͼ�����
//		 nHeight,ͼ��߶�
//		 YUVtype,YUV��������,��T_YV12,T_UYVY
//		 quality,ͼƬѹ������,��Χ(0, 100].
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ConvertToJpegFile(char *pYUVBuf, LONG nWidth, LONG nHeight, int YUVtype, int quality, char *sFileName);

//------------------------------------------------------------------------
// ����: PLAY_GetFileTotalFrames
// ����: ��ȡ�ļ���֡��
// ����: nPort,ͨ����
// ����: DWORD,�ļ��е���֡��
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetFileTotalFrames(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetCurrentFrameRate
// ����: ��ȡ��ǰ֡��
// ����: nPort,ͨ����
// ����: DWORD,��ǰ�����б���ʱ��֡��ֵ
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetCurrentFrameRate(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetPlayedTimeEx
// ����: ��ȡ�ļ���ǰ����ʱ��
// ����: nPort,ͨ����
// ����: DWORD,�ļ���ǰ���ŵ�ʱ��,��λ����.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetPlayedTimeEx(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetPlayedTimeEx
// ����: �����ļ���ǰ����ʱ��.
// ����: nPort,ͨ����
//		 nTime,�����ļ�����λ�õ�ָ��ʱ��,��λ����.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayedTimeEx(LONG nPort,DWORD nTime);

//------------------------------------------------------------------------
// ����: PLAY_GetCurrentFrameNum
// ����: ��ȡ��ǰ���ŵ�֡���,PLAY_GetPlayedFrames���ܹ������֡��.����ļ�
//			����λ�ò����ı䣬��ô�����������ķ���ֵӦ�÷ǳ��ӽ�������������
//			ʧ����.
// ����: nPort,ͨ����
// ����: ��ǰ���ŵ�֡���.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetCurrentFrameNum(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetStreamOpenMode
// ����: ����������ģʽ,�����ڲ���֮ǰ����.
// ����: nPort,ͨ����
//		 nMode,STREAME_REALTIMEʵʱģʽ(Ĭ��);STREAME_FILE�ļ�ģʽ.ʵʱģ
//			ʽ,�ʺϲ�������ʵʱ����;�ļ�ģʽ,�ʺ��û����ļ�����������ʽ����.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetStreamOpenMode(LONG nPort,DWORD nMode);

//------------------------------------------------------------------------
// ����: PLAY_GetSdkVersion
// ����: ��ȡ���ſ�SDK�汾��,�ΰ汾�źͲ�����
// ����: 
// ����: DWORD,��16λ��ʾ��ǰ�����汾��;9~16λ��ʾ�ΰ汾��;1~8λ��ʾ�β�����;
//			��:����ֵ0x00030107��ʾ:���汾����3,�ΰ汾����1,��������7.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetSdkVersion();

//------------------------------------------------------------------------
// ����: PLAY_GetLastError
// ����: ��ȡ������
// ����: nPort,ͨ����
// ����: DWORD,��õ�ǰ����Ĵ�����.��μ�������궨��.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetLastError(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_RefreshPlay
// ����: ˢ����ʾ.���û���ͣʱ���ˢ���˴���,�򴰿��е�ͼ����Ϊˢ�¶���ʧ,
//			��ʱ��������ӿڿ������°�ͼ����ʾ����.ֻ������ͣ�͵�֡����ʱ��
//			ִ��,���������ֱ�ӷ���.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_RefreshPlay(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetPictureSize
// ����: ��ȡԭʼͼ���С,���ݴ˴�С��������ʾ���ڵ�����,���Բ����Կ�������
//			����,������Щ��֧��Ӳ�����ŵ��Կ���˵�ǳ�����.
// ����: nPort,ͨ����
//		 pWidth,�������,����ͼƬ����
//		 pHeight,�������,����ͼƬ�߶�
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPictureSize(LONG nPort,LONG *pWidth,LONG *pHeight);

//------------------------------------------------------------------------
// ����: PLAY_SetPicQuality
// ����: ����ͼ������,�����óɸ�����ʱ����Ч����,��CPU�����ʸ�.��֧�ֶ�·����ʱ��
//			������Ϊ������,�Խ���CPU������.��ĳ·�Ŵ󲥷�ʱ����·���óɸ�������
//			�Դﵽ�õĻ���Ч��.
// ����: nPort,ͨ����
//		 bHighQuality,ΪTRUE(1)ʱͼ�������,ΪFALSE(0)ʱ������(Ĭ��ֵ).
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPicQuality(LONG nPort,BOOL bHighQuality);

//------------------------------------------------------------------------
// ����: PLAY_PlaySoundShare
// ����: �Թ�����ʽ��������,���ű�·��������ȥ�ر�����·������.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_PlaySoundShare(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_StopSoundShare
// ����: �ر�����(������ʽ).��ͬһ��������,����ͨ������ʹ����ͬ�ķ�ʽ���Ż�ر�����.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopSoundShare(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetStreamOpenMode
// ����: ��ȡ������ģʽ
// ����: nPort,ͨ����
// ����: LONG,STREAME_REALTIME��STREAME_FILE.
//------------------------------------------------------------------------
PLAYSDK_API LONG CALLMETHOD PLAY_GetStreamOpenMode(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetVolume
// ����: ��ȡ����,�����������ָ�������������.
// ����: nPort,ͨ����
// ����: WORD,����ֵ
//------------------------------------------------------------------------
PLAYSDK_API WORD CALLMETHOD PLAY_GetVolume(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetPictureQuality
// ����: ��ȡͼ������
// ����: nPort,ͨ����
//		 bHighQuality,�������,TRUE��ʾ������,FALSE��ʾ������.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPictureQuality(LONG nPort,BOOL *bHighQuality);

//------------------------------------------------------------------------
// ����: PLAY_GetSourceBufferRemain
// ����: ��ȡ������ģʽ��Դ������ʣ�����ݴ�С
// ����: nPort,ͨ����
// ����: DWORD,��ǰԴ����Ĵ�С��λBYTE(�ֽ�).
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetSourceBufferRemain(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_ResetSourceBuffer
// ����: ���������ģʽ��Դ��������ʣ������
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ResetSourceBuffer(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_OneByOneBack
// ����: ��֡����,�˽ӿ�ֻ֧���ļ�����,�������ļ���������֮����ܵ���.ÿ��
//			��һ�ε���һ֡
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OneByOneBack(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetCurrentFrameNum
// ����: �����ļ���ǰ֡����֡��,�˺����������ļ���������֮����ܵ���.
// ����: nPort,ͨ����
//		 nFrameNum,֡���
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetCurrentFrameNum(LONG nPort,DWORD nFrameNum);

//------------------------------------------------------------------------
// ����: PLAY_GetKeyFramePos
// ����: ����ָ��λ��֮ǰ�Ĺؼ�֡λ��,ͼ��������ӹؼ�֡��ʼ������û�����
//			���ļ����Ǵӹؼ�֡��ʼ��,��ô����һ���ؼ�֮֡ǰ�����ݻᱻ����.��
//			���û�Ҫ��ȡ�ļ��е�һ������,��Ӧ�ÿ��Ǵӹؼ�֡��ʼ��ȡ.����λ��
//			���ϵ����,��ඪʧ3֡����.���ļ�����������ȫ��ǰ����,��
//			PLAY_GetNextKeyFramePos����ʹ��,��������ʵ�ּ���¼���ļ�,��������
//			��ؼ�֡����й�.
// ����: nPort,ͨ����
//		 nValue,��ǰλ��,������ʱ���֡��,������nTypeָ��.
//		 nType,ָ��nValue������.���nType��BY_FRAMENUM,��nValue��ʾ֡��;
//			���nType��BY_FRAMTIME,��nValue��ʾʱ��,��λms.
//		 pFramePos,���ҵ��Ĺؼ�֡���ļ�λ����Ϣ�ṹָ��,���PFRAME_POS.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PFRAME_POS pFramePos);

//------------------------------------------------------------------------
// ����: PLAY_GetNextKeyFramePos
// ����: ����ָ��λ��֮��Ĺؼ�֡λ��
// ����: nPort,ͨ����
//		 nValue,��ǰλ��,������ʱ���֡��,������nTypeָ��.
//		 nType,ָ��nValue������.���nType��BY_FRAMENUM,��nValue��ʾ֡��;
//			���nType��BY_FRAMTIME,��nValue��ʾʱ��,��λms.
//		 pFramePos,���ҵ��Ĺؼ�֡���ļ�λ����Ϣ�ṹָ��,���PFRAME_POS.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetNextKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PFRAME_POS pFramePos);

//------------------------------------------------------------------------
// ����: PLAY_SetDecCBStream
// ����: ���ý���ص�������,��PLAY_Play֮ǰ����.
// ����: nPort,ͨ����
//		 nStream,1 ��Ƶ��;2 ��Ƶ��;3 ������.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecCBStream(LONG nPort,DWORD nStream);

//------------------------------------------------------------------------
// ����: PLAY_SetDisplayRegion
// ����: ���û�������ʾ����,�������ֲ��Ŵ���ʾ.
// ����: nPort,ͨ����
//		 nRegionNum,��ʾ�������,0~(MAX_DISPLAY_WND-1),���Ϊ0,�����õ�������ʾ����������.
//		 pSrcRect,�ֲ���ʾ����
//		 hDestWnd,��ʾ���ھ��
//		 bEnable,��(����)��ر���ʾ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDisplayRegion(LONG nPort,DWORD nRegionNum, DISPLAYRECT *pSrcRect, HWND hDestWnd, BOOL bEnable);


//------------------------------------------------------------------------
// ����: PLAY_GetRefValue
// ����: ��ȡ�ļ�����,�Ա��´δ�ͬһ���ļ�ʱֱ��ʹ�������Ϣ.�������������ɺ���ܻ����Ϣ.
// ����: nPort,ͨ����
//		 pBuffer,������Ϣ
//		 pSize,����pBuffer�Ĵ�С,���������Ϣ��С.�����ڵ�һ��ָ��pSize=0,pBuffer=NULL,��
//			pSize�ķ���ֵ�����Ҫ�Ļ�������С.Ȼ������㹻�Ļ���,�ٵ���һ��.	 
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetRefValue(LONG nPort,BYTE *pBuffer, DWORD *pSize);

//------------------------------------------------------------------------
// ����: PLAY_SetRefValue
// ����: �����ļ�����,������Ϣ���䳤�ȱ���׼ȷ.����Ѿ������ļ�������Ϣ,����
//			���ٵ������������Ļص�����PLAY_SetFileRefCallBackEx,ֱ������������Ϣ.
// ����: nPort,ͨ����
//		 pBuffer,������Ϣ
//		 nSize,������Ϣ�ĳ���
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetRefValue(LONG nPort,BYTE *pBuffer, DWORD nSize);

//------------------------------------------------------------------------
// ����: PLAY_RigisterDrawFun
// ����: ע��һ���ص�����,��õ�ǰ�����device context,����������DC�ϻ�ͼ(������),
//			�ͺ����ڴ��ڵĿͻ���DC�ϻ�ͼ,�����DC���Ǵ��ڿͻ�����DC,����DirectDraw��
//			��Off-Screen�����DC.ע��,�����ʹ��overlay����,����ӿ���Ч,����ֱ����
//			�����ϻ�ͼ,ֻҪ����͸��ɫ�Ͳ��ᱻ����.
// ����: nPort,ͨ����
//		 DrawFun,��ͼ�ص�����,�������������:
//			nPort,ͨ����
//			hDc,OffScreen�����豸������.
//			pUserData,�û�����,��������������û�����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fDrawCBFun)(LONG nPort,HDC hDc, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_RigisterDrawFun(LONG nPort, fDrawCBFun DrawCBFun, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_ResetBuffer
// ����: ���ָ����������ʣ������
// ����: nPort,ͨ����
//		 nBufType,����:
//			BUF_VIDEO_SRC 1 ��ƵԴ����
//			BUF_AUDIO_SRC 2 ��ƵԴ����
//			BUF_VIDEO_RENDER 3 �������Ƶ���ݻ���
//			BUF_AUDIO_RENDER 4 �������Ƶ���ݻ���
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ResetBuffer(LONG nPort,DWORD nBufType);

//------------------------------------------------------------------------
// ����: PLAY_GetBufferValue
// ����: ��ȡָ���������Ĵ�С
// ����: nPort,ͨ����
//		 nBufType,����:
//			BUF_VIDEO_SRC 1 ��ƵԴ����
//			BUF_AUDIO_SRC 2 ��ƵԴ����
//			BUF_VIDEO_RENDER 3 �������Ƶ���ݻ���
//			BUF_AUDIO_RENDER 4 �������Ƶ���ݻ���
// ����: DWORD,���ݲ�ͬ�������ػ�����ֵ,Դ����������byte,����󻺳�������֡��.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetBufferValue(LONG nPort,DWORD nBufType);

//------------------------------------------------------------------------
// ����: PLAY_AdjustWaveAudio
// ����: ����WAVE����,���Ըı������Ĵ�С.����PLAY_SetVolume�Ĳ�ͬ����,���ǵ���
//			��������,ֻ�Ը�·������,��PLAY_SetVolume�ǵ�����������,������ϵͳ������.
// ����: nPort,ͨ����
//		 nCoefficient,�����Ĳ���,��Χ��MIN_WAVE_COEF��MAX_WAVE_COEF,0�ǲ�����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_AdjustWaveAudio(LONG nPort,LONG nCoefficient);

//------------------------------------------------------------------------
// ����: PLAY_SetAudioCallBack
// ����: ��Ƶ������WAVE���ݻص�.
// ����: nPort,ͨ����
//		 funAudio,��Ƶ����ص�����,�������������
//			nPort,ͨ����
//			pAudioBuf,wave��ʽ��Ƶ����
//			nSize,��Ƶ���ݳ���
//			nStamp,ʱ��(ms)
//			nType,��Ƶ����T_AUDIO16, ������8000����������ÿ��������16λ��ʾ
//			pUserData,�û��Զ�������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK * fAudioCBFun)(LONG nPort, char * pAudioBuf, LONG nSize, LONG nStamp, LONG nType, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetAudioCallBack(LONG nPort, fAudioCBFun AudioCBFun, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_SetEncTypeChangeCallBack
// ����: ����ͼ��ֱ��ʸı�֪ͨ�ص�,���ļ�ǰʹ��.
// ����: nPort,ͨ����
//		 funEncChange,�ص�����
//			nPort,ͨ����
//			pUserData,�û��Զ�������
//		 pUserData,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void(CALLBACK *fEncChangeCBFun)(LONG nPort, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetEncTypeChangeCallBack(LONG nPort, fEncChangeCBFun EncChangeCBFun, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_SetColor
// ����: ������Ƶ����
// ����: nPort,ͨ����
//		 nRegionNum,��ʾ����,�ο�PLAY_SetDisplayRegion;���ֻ��һ����ʾ����(ͨ�����)��Ϊ0.
//		 nBrightness,����,Ĭ��64;��Χ0-128.
//		 nContrast,�Աȶ�,Ĭ��64;��Χ0-128.
//		 nSaturation,���Ͷ�,Ĭ��64;��Χ0-128.
//		 nHue,ɫ��,Ĭ��64;��Χ0-128.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetColor(LONG nPort, DWORD nRegionNum, int nBrightness, int nContrast, int nSaturation, int nHue);

//------------------------------------------------------------------------
// ����: PLAY_GetColor
// ����: ��ȡ��Ƶ����
// ����: nPort,ͨ����
//		 nRegionNum,��ʾ����,�ο�PLAY_SetDisplayRegion;���ֻ��һ����ʾ����(ͨ�����)��Ϊ0.
//		 pBrightness,����,Ĭ��64;��Χ0-128.
//		 pContrast,�Աȶ�,Ĭ��64;��Χ0-128.
//		 pSaturation,���Ͷ�,Ĭ��64;��Χ0-128.
//		 pHue,ɫ��,Ĭ��64;��Χ0-128.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetColor(LONG nPort, DWORD nRegionNum, int *pBrightness, int *pContrast, int *pSaturation, int *pHue);

//------------------------------------------------------------------------
// ����: PLAY_SetEncChangeMsg
// ����: ���÷ֱ��ʸı�֪ͨ��Ϣ
// ����: nPort,ͨ����
//		 hWnd,��Ϣ���͵Ĵ���
//		 nMsg,�û��������Ϣ,������ʱ�����ʽ�����ı�ʱ�û���hWnd���ڹ������յ������Ϣ.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetEncChangeMsg(LONG nPort,HWND hWnd,UINT nMsg);

//------------------------------------------------------------------------
// ����: PLAY_CatchPic
// ����: ץͼ,��BMPͼƬ����Ϊָ�����ļ�.PLAY_SetDisplayCallBack���õ���Ƶ��
//			�ݻص�����,ֻ��������Ƶ���ݽ������ʱ�ŵ���,�����û�������Ƶ��
//			��(��ץͼ),��������н��������,�Ͳ��ϵ�������ص�����.��PLAY_
//			CatchPicһ��ֻץһ��ͼ,��������ͣ�͵�֡����ʱʵ��ץͼ.����:���
//			�û���ʵ��ץͼ(һ��ץһ��ͼ),����PLAY_CatchPic,�������õ�һ��
//			ʱ���ڵ���Ƶ����,����PLAY_SetDisplayCallBack.
// ����: nPort,ͨ����
//		 sFileName,�ļ�����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CatchPic(LONG nPort,char* sFileName) ;

//------------------------------------------------------------------------
// ����: PLAY_CatchPicEx
// ����: PLAY_CatchPic����չ�ӿ�,�÷������PLAY_CatchPic.��ָ��ͼƬ��ʽ
// ����: nPort,ͨ����
//		 sFileName,�ļ�����
//		 ePicfomat,ͼƬ��ʽ,��tPicFormats.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CatchPicEx(LONG nPort,char* sFileName,tPicFormats ePicfomat);

//------------------------------------------------------------------------
// ����: PLAY_SetFileEndCallBack
// ����: �����ļ������ص�
// ����: nPort,ͨ����
//		 pFileEnd,�ص�����ָ��,�������������:
//			nPort,ͨ����
//			pUserData,�û��Զ������
//		 pUserData,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK *fpFileEndCBFun)(DWORD nPort, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileEndCallBack(LONG nPort, fpFileEndCBFun pFileEndCBFun, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_StartDataRecord
// ����: ��ʼ������¼��,ֻ����ģʽ����,��PLAY_Play֮�����.
// ����: nPort,ͨ����
//		 sFileName,¼���ļ���,����ļ������в����ڵ��ļ���,�ʹ������ļ���.
//		 idataType,0��ʾԭʼ��Ƶ��;1��ʾת����AVI��ʽ;2��ʾת����ASF��ʽ;3�ֶα����ļ�
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StartDataRecord(LONG nPort, char *sFileName, int idataType);

//------------------------------------------------------------------------
// ����: PLAY_WriteData
// ����: ����ԭʼ����
// ����: nPort,ͨ����
//		 pBuf,������
//		 nSize,��С
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_WriteData(LONG nPort, PBYTE pBuf,DWORD nSize);

//------------------------------------------------------------------------
// ����: PLAY_StopDataRecord
// ����: ֹͣ������¼��
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopDataRecord(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetPlaySpeed
// ����: �ı�ͼ�񲥷ŵ��ٶ�,
// ����: nPort,ͨ����
//		 fCoff,�����ٶ�,��Χ[1/64~64.0],С��1��ʾ���ţ�����1��ʾ����.
//			   �������ٶȽϿ�ʱ���ܻ��֡����.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlaySpeed(LONG nPort, float fCoff);

//------------------------------------------------------------------------
// ����: PLAY_QueryInfo
// ����: Ŀǰʵ���˶Ե�ǰʱ���֡����Ϣ�Ĳ�ѯ.
// ����: nPort,ͨ����
//		 cmdType,ָ��״̬��ѯָ��,����
//			PLAY_CMD_GetTime   ��ȡ������ʱ����Ϣ,��λms.
//			PLAY_CMD_GetFileRate  ��ȡ֡����Ϣ
//			PLAY_CMD_GetMediaInfo  ��ȡý����Ϣ,��Ϣ�ṹΪ MEDIA_INFO
//		 buf,�����Ϣ�Ļ���
//		 buflen,���峤��
//		 returnlen,��ȡ����Ϣ����Ч���ݳ���
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_QueryInfo(LONG nPort , int cmdType, char* buf, int buflen, int* returnlen);

//------------------------------------------------------------------------
// ����: PLAY_OpenAudioRecord
// ����: ����Ƶ�ɼ�����.
// ����: pProc,��Ƶ�ɼ����ݻص�ָ��,�������������:
//			pDataBuffer,�ص�����ָ��
//			DataLength,�ص����ݳ���
//			pUserData,�û�����
//		 nBitsPerSample,��ʾÿ����������Ҫ��λ��
//		 nSamplesPerSec,������
//		 nLength,���ݻ���ĳ���
//		 nReserved,����
//		 pUserData,�û��Զ�������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK *pCallFunction)(LPBYTE pDataBuffer, DWORD DataLength, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenAudioRecord(pCallFunction pProc, LONG nBitsPerSample, LONG nSamplesPerSec, LONG nLength, LONG nReserved, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_CloseAudioRecord
// ����: �ر���Ƶ�ɼ�����
// ����: 
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CloseAudioRecord();

//------------------------------------------------------------------------
// ����: PLAY_SetWaterMarkCallBack
// ����: ����ˮӡ���ݻص���ע�⣺ˮӡУ��ص����ú󽫲�����н�����ʾ
// ����: nPort,ͨ����
//		 pFunc,ˮӡ��Ϣ��ȡ�ص�����,�������������:
//			buf,ˮӡ����bufferָ��
//			key,���ֲ�ͬˮӡ��Ϣ
//			len,�������󳤶�
//			reallen,�����ʵ�ʳ���
//			type,��ֵ��Χ[0,3],��������
//				0  I֡֡����ˮӡ��Ϣ
//				1  ֡ˮӡ
//				2  ˮӡУ�� 
//				3  ���ܷ���֡
//		 pUserData,�û��Զ������ 
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef int (CALLBACK* GetWaterMarkInfoCallbackFunc)(char* buf, LONG key, LONG len, LONG reallen, LONG type, void* pUserData);	
PLAYSDK_API BOOL CALLMETHOD PLAY_SetWaterMarkCallBack(LONG nPort, GetWaterMarkInfoCallbackFunc pFunc, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_CreateFile
// ����: ���ļ����Զ�����ͨ����
// ����: sFileName,�ļ���
// ����: DWORD,ʧ�ܷ���0,���򷵻�ͨ����.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_CreateFile(LPSTR sFileName);

//------------------------------------------------------------------------
// ����: PLAY_DestroyFile
// ����: �رղ����ļ����ͷ��Զ������ͨ����.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_DestroyFile(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_CreateStream
// ����: �����ӿڲ��Զ�����ͨ����
// ����: nBufPoolSize,�ò������д���������Ļ�������С,��Χ��[SOURCE_BUF_MIN,SOURCE_BUF_MAX].
// ����: DWORD,ʧ�ܷ���0,���򷵻�ͨ����.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_CreateStream(DWORD nBufPoolSize);

//------------------------------------------------------------------------
// ����: PLAY_DestroyStream
// ����: �ر�������,���ͷ��Զ������ͨ����.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_DestroyStream(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetFreePort
// ����: ��ȡ����ͨ����,����Ϊ501.��PLAY_ReleasePortƥ��ʹ��.
// ����: plPort,�������,���ػ�ȡ��ͨ����.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetFreePort(LONG *plPort);

//------------------------------------------------------------------------
// ����: PLAY_ReleasePort
// ����: �ͷ�ͨ����,��PLAY_RealsePortƥ��ʹ��.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ReleasePort(LONG lPort);

//------------------------------------------------------------------------
// ����: PLAY_VerticalSyncEnable
// ����: ��ֱͬ����ʾ����.�˽ӿ�����PLAY_Play֮�����,���²���ʱ����������.
//			�ڲ��Ŷ�̬ͼ����ֶϲ�ʱ,����ʹ�ô˽ӿڴ򿪴�ֱͬ������.
// ����: nPort,ͨ����
//		 bEnable,TRUE�򿪴�ֱͬ��;FALSE�رմ�ֱͬ��.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API	BOOL CALLMETHOD PLAY_VerticalSyncEnable(LONG nPort, BOOL bEnable);

//------------------------------------------------------------------------
// ����: PLAY_GetPicBMP
// ����: ץȡBMPͼ��
// ����: nPort,ͨ����
//		 pBmpBuf,���BMPͼ�����ݵĻ����ַ,���û�����,����С��bmp ͼ���С,
//			�Ƽ���С:sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+w*h*4,
//			����w��h�ֱ�Ϊͼ�����.
//		 dwBufSize,��������С
//		 pBmpSize,��ȡ����ʵ��bmp ͼ���С
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicBMP(LONG nPort, PBYTE pBmpBuf, DWORD dwBufSize, DWORD* pBmpSize);

//------------------------------------------------------------------------
// ����: PLAY_GetPicBMPEx
// ����: ץȡBMPͼ��
// ����: nPort,ͨ����
//		 pBmpBuf,���BMPͼ�����ݵĻ����ַ,���û�����,����С��bmp ͼ���С,
//			�Ƽ���С:sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+w*h*4,
//			����w��h�ֱ�Ϊͼ�����.
//		 dwBufSize,��������С
//		 pBmpSize,��ȡ����ʵ��bmp ͼ���С
//		 nWidth,ָ����bmp�Ŀ�
//		 nHeight,ָ����bmp�ĸ�
//		 nRgbType,ָ��RGB��ʽ 0��RGB32;1��RGB24;
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicBMPEx(LONG nPort, PBYTE pBmpBuf, DWORD dwBufSize, DWORD* pBmpSize, LONG nWidth, LONG nHeight, int nRgbType);

//------------------------------------------------------------------------
// ����: PLAY_GetPicJPEG
// ����: ץȡJPEGͼ��.
// ����: nPort,ͨ����
//		 pJpegBuf,���JPEGͼ�����ݵĻ����ַ,���û�����,����С��JPEGͼ���С,
//			�Ƽ���С:w*h*3/2,����w��h�ֱ�Ϊͼ�����.
//		 dwBufSize,��������С.
//		 pJpegSize,��ȡ����ʵ��JPEGͼ���С.
//		 quality,JPEGͼ���ѹ������,ȡֵ��ΧΪ(0,100].
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicJPEG(LONG nPort, PBYTE pJpegBuf, DWORD dwBufSize, DWORD* pJpegSize, int quality);

//------------------------------------------------------------------------
// ����: PLAY_GetPicTIFF
// ����: ץȡTIFFͼ��
// ����: nPort,ͨ����
//		 pTiffBuf,���TIFFͼ�����ݵĻ����ַ,���û�����,����С��tiffͼ���С,
//			�Ƽ���С:w*h*3+1024,
//			����w��h�ֱ�Ϊͼ�����.
//		 dwBufSize,��������С
//		 pTiffSize,��ȡ����ʵ��TIFFͼ���С
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicTIFF(LONG nPort, PBYTE pTiffBuf, DWORD dwBufSize, DWORD* pTiffSize);

//------------------------------------------------------------------------
// ����: PLAY_SetVisibleDecodeCallBack
// ����: ����ص�.��PLAY_SetDecodeCallBack������ͬ,��ͬ���ǽ���ص���ͬʱ����
//			��ʾ��Ƶ,���鲻Ҫ�ڻص�������������ʱ����߼�����,����������ʾ����ʱ.
// ����: nPort,ͨ����
//		 cbDec,����ص�����ָ��,����ΪNULL.�ص�����������������:
//			nPort,ͨ����
//			pFrameDecodeInfo,����������Ƶ����
//			pFrameInfo,ͼ���������Ϣ,��μ�FRAME_INFO�ṹ��
//			pUser,�û��Զ������
//		 pUser,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVisibleDecodeCallBack(LONG nPort, fCBDecode cbDec, void* pUser);

//------------------------------------------------------------------------
// ����: PLAY_RigisterDrawFunEx
// ����: ע��һ���ص�����,��õ�ǰ�����������(HDC),���DC���Ǵ��ڿͻ�����DC,
//			����DirectDraw���Off-Screen�����DC.ע��.�����ʹ��overlay����,
//			����ӿ���Ч,overlay��ʽ����ֱ���ڴ����ϻ�ͼ,ֻҪ����͸��ɫ�Ͳ��ᱻ����.
// ����: nPort,ͨ����
//		 nReginNum,��ʾ�������,��Χ[0,(MAX_DISPLAY_WND-1)].���nRegionNumΪ0,
//			�����õ�������ʾ����������.
//		 DrawFunEx,��ͼ�ص�����,�������������:
//			nPort,ͨ����
//			hDc,Off-Screen������豸������(DC)
//			pUserData,�û��Զ������
//		 pUserData,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fDrawCBFunEx)(LONG nPort,LONG nReginNum,HDC hDc, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_RigisterDrawFunEx(LONG nPort, LONG nReginNum, fDrawCBFunEx DrawFunEx, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_CatchResizePic
// ����: ץͼ,��ѡ���ʽ��ָ������.
// ����: nPort,ͨ����
//		 sFileName,�ļ�����
//		 lTargetWidth,ָ����ͼ�����
//		 lTargetHeight,ָ����ͼ��߶�
//		 ePicfomat,ͼƬ��ʽ,���tPicFomats
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CatchResizePic(LONG nPort, char* sFileName, LONG lTargetWidth, LONG lTargetHeight, tPicFormats ePicfomat);

//------------------------------------------------------------------------
// ����: PLAY_GetRealFrameBitRate
// ����: ��ȡ��Ƶʵʱ����
// ����: nPort,ͨ����
//		 pBitRate,�������,������Ƶ����.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetRealFrameBitRate(LONG nPort, double* pBitRate);


//------------------------------------------------------------------------
// ����: PLAY_SetFileRefCallBackEx
// ����: ���ý��������ص�,�Է��������������.
// ����: nPort,ͨ����
//		 pFileRefDoneEx,�ص�����ָ��,�������������:
//			nPort,ͨ����
//			bIndexCreated,����������־,TRUE���������ɹ�;FALSEʧ��.
//			pUserData,�û��Զ������
//		 pUserData,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK *fpFileRefDoneCBFunEx)(DWORD nPort, BOOL bIndexCreated, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileRefCallBackEx(LONG nPort, fpFileRefDoneCBFunEx pFileRefDoneCBFunEx, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_StartAVIConvert
// ����: ��ʼAVIת��������AVIת��״̬�ص�.
// ����: nPort,ͨ����
//		 pAVIFunc,�ص�����,�������������:
//			nPort,ͨ����
//			lMediaChangeType,AVI_MEDIACHANGE_FRAMERATE��ʾ֡�ʸı�;AVI_MEDIACHANGE_RESOLUTION��ʾ�ֱ��ʸı�
//			lUser,�û��Զ������
//			pbIfContinue,TRUE����ת��;FALSE ֹͣת��
//			sNewFileName,�������ת��,�µ�¼���ļ���
//		 lUser,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* AVIConvertCallback)(LONG nPort, LONG lMediaChangeType, void* pUserData, BOOL *pbIfContinue, char *sNewFileName);
PLAYSDK_API BOOL CALLMETHOD PLAY_StartAVIConvert(LONG nPort, char *sFileName, AVIConvertCallback pAVIFunc, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_StopAVIConvert
// ����: ֹͣAVIת��.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopAVIConvert(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetWaterMarkCallBackEx
// ����: ����ˮӡ���ݻص���ע�⣺ˮӡУ��ص����ú󽫲�����н�����ʾ
// ����: nPort,ͨ����
//		 pFunc,����ָ��,�������������:
//			nPort,ͨ����
//			buf,ˮӡ���ݻ���
//			lTimeStamp,ˮӡ��ʱ���
//			lInfoType,ˮӡ��Ϣ����,����������,WATERMARK_DATA_TEXT,
//				WATERMARK_DATA_JPEG_BMP,WATERMARK_DATA_FRAMEDATA
//		 len,�������󳤶�
//		 reallen,�����ʵ�ʳ���
//		 lCheckResult,1û�д���;2ˮӡ����;3֡���ݴ���;4֡�Ŵ���
//		 pUserData,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef int (CALLBACK* GetWaterMarkInfoCallbackFuncEx)(LONG nPort, char* buf, LONG lTimeStamp, LONG lInfoType, LONG len, LONG reallen, LONG lCheckResult, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetWaterMarkCallBackEx(LONG nPort, GetWaterMarkInfoCallbackFuncEx pFunc, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_SetAudioRecScaling
// ����: ������Ƶ�ɼ��������ű���
// ����: fRatio,���ű���.����0С��1Ϊ��Ƶ��С;1Ϊԭʼ��Ƶ;����1Ϊ��Ƶ�Ŵ�.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetAudioRecScaling(float fRatio);

//------------------------------------------------------------------------
// ����: PLAY_GetAudioRecScaling
// ����: ��ȡ��Ƶ�ɼ��������ű���
// ����: pfRatio,���ű���.����0С��1Ϊ��Ƶ��С;1Ϊԭʼ��Ƶ;����1Ϊ��Ƶ�Ŵ�.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetAudioRecScaling(float* pfRatio);

//------------------------------------------------------------------------
// ����: PLAY_SetAudioRenderScaling
// ����: ������Ƶ�������ű���
// ����: nPort,ͨ����
//		 fRatio,���ű���.����0С��1Ϊ��Ƶ��С;1Ϊԭʼ��Ƶ;����1Ϊ��Ƶ�Ŵ�.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetAudioRenderScaling(LONG nPort, float fRatio);

//------------------------------------------------------------------------
// ����: PLAY_GetAudioRenderScaling
// ����: ��ȡ��Ƶ�������ű���
// ����: nPort,ͨ����
//		 pfRatio,���ű���.����0С��1Ϊ��Ƶ��С;1Ϊԭʼ��Ƶ;����1Ϊ��Ƶ�Ŵ�.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetAudioRenderScaling(LONG nPort, float* pfRatio);

//------------------------------------------------------------------------
// ����: PLAY_SetRotateAngle
// ����: ͼ��ת
// ����: nrotateType,��ת����,��Χ[0,3]. 0����ת;1��ת90��;2��ת180��;3��ת270��.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetRotateAngle(LONG nPort , int nrotateType);

//------------------------------------------------------------------------
// ����: PLAY_SetDelayTime
// ����: �����ӳ�ʱ��
// ����: nDelay,�ӳ�ʱ�䣬�������ʱ�俪ʼ���ţ�����С�ڴ�ֵ��ʼ��΢����
//       nThreshold,��ֵʱ�䣬���﷧ֵ��ʼ��΢���
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDelayTime(LONG nPort, int nDelay, int nThreshold);

//------------------------------------------------------------------------
// ����: PLAY_SetPlayMethod
// ����: ���ò��Ų��Բ�����ֻ��ʵʱ����Ч
// ����: nStartTime,��ʼ���ŵ�ʱ��
//       nSlowTime,��ʼ���ŵ�ʱ��
//		 nFastTime,��ʼ��ŵ�ʱ��
//		 nFailedTime,������ʱ��Ͷ������ʧ��
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayMethod(LONG nPort, int nStartTime, int nSlowTime, int nFastTime, int nFailedTime);

//------------------------------------------------------------------------
// ����: PLAY_BackOne
// ����: ��PLAY_OneByOneBack�ظ�����ʹ��PLAY_OneByOneBack
// ����: 
// ����: 
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_BackOne(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetDecCallBack(����ʹ��PLAY_SetDecodeCallBack)
// ����: ���ý���ص�,�滻�������е���ʾ����,���û��Լ�������ʾ,�ú�����
//			PLAY_Play֮ǰ����,��PLAY_Stopʱ�Զ�ʧЧ,�´ε���PLAY_Play֮ǰ
//			��Ҫ��������.���벿�ֲ������ٶ�,ֻҪ�û��ӻص������з���,������
//			�ͻ������һ��������.������ֻ���벻��ʾ�����Ρ�
// ����: nPort,ͨ����
//		 DecCBFun,����ص�����ָ��,����ΪNULL.�ص�����������������:
//			nPort,ͨ����
//			pBuf,����������Ƶ����
//			nSize,����������Ƶ����pBuf�ĳ���
//			pFrameInfo,ͼ���������Ϣ,��μ�FRAME_INFO�ṹ��
//			nReserved1,��������
//			nReserved2,��������	
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fDecCBFun)(LONG nPort,char * pBuf,LONG nSize,FRAME_INFO * pFrameInfo, void* pUserData, LONG nReserved2);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecCallBack(LONG nPort, fDecCBFun DecCBFun);

//------------------------------------------------------------------------
// ����: PLAY_SetDecCallBackEx(����ʹ��PLAY_SetDecodeCallBack)
// ����: ���ý���ص�,�滻�������е���ʾ����,���û��Լ�������ʾ,�ú�����
//			PLAY_Play֮ǰ����,��PLAY_Stopʱ�Զ�ʧЧ,�´ε���PLAY_Play֮ǰ
//			��Ҫ��������.���벿�ֲ������ٶ�,ֻҪ�û��ӻص������з���,������
//			�ͻ������һ��������.������ֻ���벻��ʾ�����Ρ�
// ����: nPort,ͨ����
//		 DecCBFun,����ص�����ָ��,����ΪNULL.�ص�����������������:
//			nPort,ͨ����
//			pBuf,����������Ƶ����
//			nSize,����������Ƶ����pBuf�ĳ���
//			pFrameInfo,ͼ���������Ϣ,��μ�FRAME_INFO�ṹ��
//			nReserved1,�û��Զ������
//			nReserved2,��������	
//		 pUserData,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecCallBackEx(LONG nPort, fDecCBFun DecCBFun, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_SetVisibleDecCallBack(����ʹ��PLAY_SetVisibleDecodeCallBack)
// ����: ����ص�.��PLAY_SetDecCallBackEx������ͬ,��ͬ���ǽ���ص���ͬʱ����
//			��ʾ��Ƶ,���鲻Ҫ�ڻص�������������ʱ����߼�����,����������ʾ����ʱ.
// ����: nPort,ͨ����
//		 DecCBFun,�ص�����ָ��,����ΪNULL,�������������:
//			nPort,ͨ����
//			pBuf,����������Ƶ����
//			nSize,���ݳ���
//			pFrameInfo,֡��Ϣ,���FRAME_INFO�ṹ��.
//			pUserData,�û��Զ������
//			pReserved1,��������.
//		 pUserData,�û��Զ������.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fVisibleDecCBFun)(LONG nPort,char * pBuf,LONG nSize,FRAME_INFO * pFrameInfo, void* pUserData, LONG nReserved1);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVisibleDecCallBack(LONG nPort, fVisibleDecCBFun DecCBFun, void* pUserData);


//------------------------------------------------------------------------
// ����: PLAY_SetDisplayScale
// ����: ������ʾ������С��IOSר���Ա����䲻ͬ�Ļ���.
// ����: nPort,ͨ����
//		 fScale����ʾ������Ĭ��Ϊ1.0
//		 nRegionNum,��ʾ�������,0~(MAX_DISPLAY_WND-1),���Ϊ0,�����õ�������ʾ����������.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDisplayScale(LONG nPort, float fScale, DWORD nRegionNum);


//------------------------------------------------------------------------
//	������: PLAY_SetSecurityKey
//	����: ����aes������Կ
//  �������:   nPort:		����ͨ����
//				szKey:		��Կ��ָ��
//				nKeylen:	��Կ�ĳ���       
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetSecurityKey(LONG nPort,const char* szKey,DWORD nKeylen);

//------------------------------------------------------------------------
// ����: PLAY_StartFisheye
// ����: ������Ƶ�����㷨���ܣ���Ҫ����fisheye.dll��
// ����: [in]nPort : ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StartFisheye(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_OperateFisheyeParams
// ����: ����/��ȡ���۲���
// ����: [in]nPort					:  ͨ����
//		 [in]operatetype			:  ��������
//       [in]pOptParam	    		:  ���۲���
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//-----------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OptFisheyeParams(LONG nPort, FISHEYE_OPERATETYPE operatetype, FISHEYE_OPTPARAM* pOptParam);

//------------------------------------------------------------------------
// ����: PLAY_FisheyeSecondRegion
// ����: ���ڸ���ģʽ�¿�����رյڶ������۴���
// ����: [in]nPort			: ͨ����
//		 [in]hDestWnd		: ��ʾ���ھ��
//		 [in]pOptParam		: �ڶ������ڶ�Ӧ�����۲���
//		 [in]bEnable		: �򿪻�ر���ʾ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_FisheyeSecondRegion(LONG nPort, HWND hDestWnd, FISHEYE_OPTPARAM* pOptParam, BOOL bEnable);

//------------------------------------------------------------------------
// ����: PLAY_FisheyeEptzUpdate
// ����: ����eptz(������̨�������������ƶ�
// ����: [in]nPort           :  ͨ����
//       [in/out]pEptzParam  :  ���ڲ���
//		 [in]bSecondRegion	 ��	�Ƿ�Ϊ����ģʽ�µĵڶ������ڣ�1Ϊ�棬Ĭ����0
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_FisheyeEptzUpdate(LONG nPort, FISHEYE_EPTZPARAM* pEptzParam, BOOL bSecondRegion);

//------------------------------------------------------------------------
// ����: PLAY_StopFisheye
// ����: ֹͣ��Ƶ�����㷨����
// ����: [in]nPort : ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopFisheye(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetFishEyeInfoCallBack
// ����: ���û�ȡ���ۻص�
// ����: nPort,ͨ����
//		 pFishEyeInfoFun,�ص�����ָ��,����ΪNULL,�������������:
//			nPort,ͨ����
//          byCorrectMode,����ģʽ
//          wRadius,�뾶
//          wCircleX,Բ�ĺ�����
//          wCircleY,Բ��������
//			widthRatio, ������
//			heightRatio,�߱���
//			gain, ����
//			denoiseLevel, ����ȼ�
//			InstallStyle, ���۰�װ��ʽ
//		 pUserData,�û��Զ������.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fCBFishEyeInfoFun)( 
	LONG nPort,
	BYTE byCorrectMode,
	WORD wRadius,
	WORD wCircleX,
	WORD wCircleY,
	UINT widthRatio,
	UINT heightRatio,
	BYTE gain,
	BYTE denoiseLevel,
	BYTE installStyle,
	void* pUserData );
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFishEyeInfoCallBack(
	LONG nPort, 
	fCBFishEyeInfoFun pFishEyeInfoFun, 
	void* pUserData );

    
    
// Extension API




/********************************************************************
 *	������: 	    	PLAY_SetupPrepareTime
 *	Ŀ��:				����Ԥ¼�Ļ���
 *   �������:           nPort:		����ͨ����
 nTime:		Ԥ¼������
 tmpDir:		��ʱ��Ԥ¼Ŀ¼
 *   �������:
 *   ����ֵ:             TRUE:	�ɹ�.
 FALSE:	ʧ��
 *   ����ʱ��:	        2012:12:21
 *   �汾��Ϣ��¼:	    2012/12/21:YeYamin:modify......
 *********************************************************************/

PLAYSDK_API BOOL	CALLMETHOD PLAY_SetupPrepareTime(LONG nPort,int nTime,const char* tmpDirectory);

/********************************************************************
 *	������: 	    	PLAY_StartPrepareRecord
 *	Ŀ��:				��ʼԤ¼
 *   �������:		     nPort:		����ͨ����
 pFileName:	¼��λ��
 *   �������:
 *   ����ֵ:             TRUE:	�ɹ�.
 FALSE:	ʧ��
 *   ����ʱ��:	        2012:12:21
 *   �汾��Ϣ:			2012/12/21:YeYamin:modify......
 *********************************************************************/

PLAYSDK_API BOOL	CALLMETHOD PLAY_StartPrepareRecord(LONG nPort,const char* pFileName);

/********************************************************************
 *	������: 	    	PLAY_StopPrepareRecord
 *	Ŀ��:
 *   �������:			port:		����ͨ����
 *   �������:
 *   ����ֵ:             TRUE:	�ɹ�.
 FALSE:	ʧ��
 *   ����ʱ��:	        2012:12:21
 *   �汾��Ϣ��¼:		2012/12/21:YeYamin:modify......
 *********************************************************************/

PLAYSDK_API BOOL	CALLMETHOD PLAY_StopPrepareRecord(LONG nPort);

//
//
#define IVSINFOTYPE_PRESETPOS		1
#define IVSINFOTYPE_MOTINTRKS		2
#define IVSINFOTYPE_MOTINTRKS_EX	3
#define IVSINFOTYPE_LIGHT			4
#define IVSINFOTYPE_RAWDATA			5
#define IVSINFOTYPE_TRACK			6
#define IVSINFOTYPE_MOTIONFRAME		9 /*��̬�������֡*/
#define PSIVS						240
/********************************************************************
 *	������: 	    	PLAY_SetIVSCallBack
 *	Ŀ��:
 *   �������:	        nPort:		����ͨ��
 pFunc:		���ý���ص�
 nUser:		�����ģ����ڻص������Ĳ���
 *   �������:
 *   ����ֵ:             TRUE:	�ɹ�
 FALSE:	ʧ��
 *   ����ʱ��:	        2012:12:21
 *	�汾��Ϣ��¼:	    2012/12/21:YeYamin:modify......
 *********************************************************************/

typedef void (CALLMETHOD *GetIVSInfoCallbackFunc)(char* buf, LONG type, LONG len, LONG reallen, void* pReserved, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetIVSCallBack(LONG nPort, GetIVSInfoCallbackFunc pFunc, void* pUserData);

/********************************************************************
 *	������: 	    	PLAY_CatchResizePic
 *	Ŀ��:				�ı�ֱ��ʵ�ץͼ
 *   �������:			nPort:		����ͨ��
 sFileName:	ͼƬ��ַ.
 lTargetWidth & lTargetHeight: ͼƬ�Ŀ�����
 ePicfomat:	picture format (jpeg/bmp)	ͼƬ������
 *   �������:
 *   ����ֵ:             TRUE:	�ɹ�
 FALSE:	ʧ��
 *   ����ʱ��:	        2012:12:21
 *   �汾��Ϣ��¼:	    2012/12/21:YeYamin:modify......
 *********************************************************************/

PLAYSDK_API BOOL CALLMETHOD PLAY_CatchResizePic(LONG nPort, char* sFileName, LONG lTargetWidth, LONG lTargetHeight, tPicFormats ePicfomat);

/********************************************************************
 *	������: 	    	PLAY_GetRealFrameBitRate
 *	Ŀ��:				��ȡ���
 *   �������:           nPort:		����ͨ����
 *   �������:	        pBitRate:
 *   ����ֵ:             TRUE:	�ɹ�
 FALSE:	ʧ��
 *   ����ʱ��:	        2012:12:21
 *   �汾��Ϣ��¼:	    2012/12/21:YeYamin:modify......
 *********************************************************************/

PLAYSDK_API BOOL CALLMETHOD PLAY_GetRealFrameBitRate(LONG nPort, double* pBitRate);

/********************************************************************
 *	������: 	    	PLAY_StartAVIResizeConvert
 *	Ŀ��:				�ı�ֱ��ʵ�AVIת��
 *   �������:           nPort:		����ͨ����
 sFileName:	AVI��¼���ŵ�ַ
 lWidth & lHeight:AVI��¼��Ŀ�����
 *   �������:
 *   ����ֵ:             TRUE:	�ɹ�
 FALSE:	ʧ��
 *   ����ʱ��:	        2012:12:21
 *   �汾��Ϣ��¼:	    2012/12/21:YeYamin:modify......
 *********************************************************************/

PLAYSDK_API BOOL CALLMETHOD PLAY_StartAVIResizeConvert(LONG nPort, char *sFileName, LONG lWidth, LONG lHeight);

/********************************************************************
 *	������: 	    	PLAY_StopAVIResizeConvert
 *	Ŀ��:				����AVIת��
 *   �������:           nPort:		����ͨ����
 *   �������:
 *   ����ֵ:             TRUE:	�ɹ�
 FALSE:	ʧ��
 *   ����ʱ��:	        2012:12:21
 *   �汾��Ϣ��¼:	    2012/12/21:YeYamin:modify......
 *********************************************************************/

PLAYSDK_API BOOL CALLMETHOD PLAY_StopAVIResizeConvert(LONG nPort);

/********************************************************************
 *	������: 	    	PLAY_SetPandoraWaterMarkCallBack
 *	Ŀ��:				��Ч
 *   �������:
 *   �������:
 *   ����ֵ:             TRUE:	�ɹ�
 FALSE:	ʧ��
 *   ����ʱ��:	        2012:12:21
 *   �汾��Ϣ��¼:	    2012/12/21:YeYamin:modify......
 *********************************************************************/

PLAYSDK_API BOOL CALLMETHOD PLAY_SetPandoraWaterMarkCallBack(LONG nPort, GetWaterMarkInfoCallbackFunc pFunc, void* pUserData);


/********************************************************************
 *	������: 	    	PLAY_SetDigitalSignCallBack
 *	Ŀ��:				��������ǩ���ص�.
 *   �������:           nPort:		����ͨ����
 nFrameID:	֡���
 bSuccess:	У���Ƿ�ͨ��
 pUserData   �û�����
 *   �������:
 *   ����ֵ:             TRUE:	�ɹ�
 FALSE:	ʧ��
 *********************************************************************/
typedef void (CALLBACK* fCheckDigitalSignCB)(LONG nPort, int nFrameID, BOOL bSuccess, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDigitalSignCallBack(LONG nPort, fCheckDigitalSignCB pDigitalSignCB, void* pUserData);

/********************************************************************
 *	������: 	    	PLAY_GetTimePicture
 *	Ŀ��:				��þ���ʱ��������ͼƬ
 *   �������:           filepath:	������ļ�·��
 time:		����ʱ��
 DecCBFun:	���ý�ȥ�Ľ���ص�
 user:		�û�������
 *   �������:
 *   ����ֵ:             TRUE:	�ɹ�
 FALSE:	ʧ��
 *   ����ʱ��:	        2012:12:21
 *   �汾��Ϣ��¼:	    2012/12/21:YeYamin:modify......
 *********************************************************************/
PLAYSDK_API BOOL CALLMETHOD PLAY_GetTimePicture(const char* filepath, struct tm* time, fDecCBFun fcbDec, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_StartFisheyeEx
// ����: ��������������չ�ӿڣ���Ҫ����fisheye.dll MCL_FPTZ.dll��
// ����: [in]nPort : ͨ����
//		 [in] startType:  �������ͣ� 0ֻ��������У��, 1ͬʱ����������У��, 2ֻ�������������㷨
//       [in] ptzChannelParam: ����������ʼ��ͨ��������startTypeΪ0ʱ��ptzChannelParam��NULL
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StartFisheyeEx(LONG nPort, int startType, MHFPTZ_INITPARAM* ptzChannelParam);

//------------------------------------------------------------------------
// ����: PLAY_SetFisheyeParams, ���ݾɰ汾���۽ӿ�
// ����: �������۲���
// ����: [in]nPort           :  ͨ����
//		 [in]nX				 :  ����Բ�ĺ�����
//       [in]nY				 :  ����Բ��������
//       [in]nRadius         :  ���۰뾶
//       [in]nLensDirection  :  ��ͷ����
//       [in]mode            :  ͼ����ʾģʽ
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFisheyeParams(LONG nPort, int nX, int nY, int nRadius, int nLensDirection, FISHSHOWMODES mode);

//------------------------------------------------------------------------
// ����: PLAY_FisheyeGetPosition, ���ݾɰ汾���۽ӿ�
// ����: ���Ŀ�����Ķ�Ӧ������̨�Ľ���λ��
// ����: [in]nPort           :  ͨ����
//		 [in]row			 :  Ŀ������������
//       [in]column			 :  Ŀ������������
//		 [out]pX     		 :  Ŀ����������Ӧ������̨�Ľ��������
//       [out]pY		     :  Ŀ����������Ӧ������̨�Ľ���������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_FisheyeGetPosition(LONG nPort, int row, int column, int *pX, int *pY);

//------------------------------------------------------------------------
// ����: PLAY_FisheyeEptzUpdate, ���ݾɰ汾���۽ӿ�
// ����: ����eptz(������̨�������������ƶ�
// ����: [in]nPort           :  ͨ����
//		 [in/out]pX			 :  eptz��������̨���Ľ��������
//       [in/out]pY			 :  eptz�Ľ���������
//		 [in/out]pHangle		 :  eptz��ˮƽ�Ƕȷ�Χ(0-3600)
//       [in/out]pVangle		 :  eptz�Ĵ�ֱ�Ƕȷ�Χ(0-900)
//       [in]ops             :  FISHEPTZOPTS�ṹ��,Ϊ0ʱ��ָ���������ý��㣬Ϊ1��ʾ�Ŵ�2��ʾ��С��3��ʾ�����ƶ���
//                              4��ʾ�����ƶ���5��ʾ�����ƶ���6��ʾ�����ƶ���7��ʾ�Զ�˳ʱ����ת��8��ʾ�Զ���ʱ����ת
//								9��ʾֹͣ��̨������10��ʾ��ȡ��ǰ��̨��������λ��
//       [in]nWinNum         :  Ҫ����eptz�Ĵ��ڱ�ţ����Ͻ�win_numΪ1�������ҵ���
//       [in]nZoomStep       :  �Ŵ���С�Ĳ���, ��Χ1-8
//       [in]nPtStep		 :  ���������ƶ��Ĳ���, ��Χ1-8
//		 [in]nRotateStep	 :  ��ת�Ĳ���, ��Χ1-8
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OldFisheyeEptzUpdate(LONG nPort, int *pX, int *pY, int *pHAngle, int *pVAngle, FISHEPTZOPTS ops, int nWinNum,
                                                      int nZoomStep, int nPtStep, int nRotateStep);

/******************************************************************************
 *
 * ������  : PLAY_FishEyeTransFromCoordinate
 * ��  ��  : У��ͼ���Դͼ��֮������ת��
 * ��  ��  : - handle: �����㷨ʵ�����
 - x:��Ҫת��������
          y:��Ҫת��������
          winid:winid��������flag=0�����Ϊ�������  ��flag=1���������Ϊ�������
          u:ת���������
          v:ת���������
          flag��0ΪУ����ͼ��תԭʼͼ�����꣬1��ʾԭʼͼ������תУ����ͼ������
 * ��  ��  : ��
 * ����ֵ  : BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
 *******************************************************************************/
PLAYSDK_API BOOL PLAY_FishEyeTransFromCoordinate(LONG nPort, int x, int y, int *winid, int *u, int *v, int flag);

/******************************************************************************
 *
 * ������  : PLAY_FishEyeTransFromCoordinateFSTA(from source to adjust)
 * ��  ��  : Դͼ������תУ����ͼ������
 * ��  ��  : - handle: �����㷨ʵ�����
 - points:��Ҫת����ԭʼͼ���ϵ�����
          num:�������
          points_adjust:ת���������
          winid:ת����������Ӧ�Ĵ���id
          points_adjust_num    �����ĸ���
 * ��  ��  : ��
 * ����ֵ  : BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
 *           other: �������1��ԭʼͼ���ϵĵ��Ӧ����Ӵ��ڵĵ㣬��ô�������ж��points_adjuest
 ÿ��points_adjust��Ӧһ��winid��
 
 ���磨10,10�� �����ڴ���1�ʹ���2,�ڴ���1�ϵĶ�Ӧ�����ǣ�100,100�����ڴ���2�ϵ�
 ��Ӧ�����ǣ�1000,1000��
 ��ô	points_adjust[i].x = 100,		winid[i] = 1;
 points_adjust[i].y = 100,
 points_adjust[i+1].x = 1000,	winid[i+1] = 2;
 points_adjust[i+1].y = 1000,
 *******************************************************************************/
PLAYSDK_API BOOL PLAY_FishEyeTransFromCoordinateFSTA(LONG nPort, FISHEYE_POINT2D *points, int num, FISHEYE_POINT2D *points_adjust, int *winid, int *points_adjust_num);

/******************************************************************************
 *
 * ������  : PLAY_FishEyeTransFromCoordinateFATS(from adjust to source)
 * ��  ��  : У����ͼ������תԴͼ������
 * ��  ��  :	- handle: �����㷨ʵ�����
 - points:��Ҫת����У����ͼ���ϵ�����
          num:�������
          points_adjust:ת���������
          winid:��Ҫת��������Ĵ���id
 * ��  ��  : ��
 * ����ֵ  : BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
 *******************************************************************************/
PLAYSDK_API BOOL PLAY_FishEyeTransFromCoordinateFATS(LONG nPort, FISHEYE_POINT2D *points, int num, FISHEYE_POINT2D *points_adjust, int winid);

/******************************************************************************
 *
 * ������  : PLAY_FishEyeTransFromLineFATS(from adjust to source)
 * ��  ��  : У����ͼ������תԴͼ������
 * ��  ��  :	- handle: �����㷨ʵ�����
 - points:��Ҫת����У����ͼ�������ߵ���Ϣ
          num:�����
          points_adjust:ת�����������Ϣ
          winid:��Ҫת��������Ĵ���id
          pOpt :������Ϣ,��������ӿ�֮ǰ�ȵ���Fisheye_GetParam��ȡ
 * ��  ��  : ��
 * ����ֵ  : BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
 *******************************************************************************/
PLAYSDK_API BOOL PLAY_FishEyeTransFromLineFATS(LONG nPort, FISHEYE_POINT2D *points, int num, FISHEYE_POINT2D *points_adjust, int winid, FISHEYE_OPTPARAM *pOpt);


/******************************************************************************
 *
 * ������  : PLAY_FishEyeTransFromLineFSTA(from source to adjust)
 * ��  ��  : ԭʼͼ������תУ����ͼ������
 * ��  ��  : - handle: �����㷨ʵ�����
 - points:��Ҫת����ԭʼͼ���ϵ�����
 num:�������
 points_adjust:ת���������
 winid:ת����������Ӧ�Ĵ���id
 points_adjust_num    �����ĸ���
 pOpt:������Ϣ ��������ӿ�֮ǰ�ȵ���Fisheye_GetParam��ȡ
 * ��  ��  : ��
 * ����ֵ  : BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
 *other: �������1��ԭʼͼ���ϵĵ��Ӧ����Ӵ��ڵĵ㣬��ô�������ж��points_adjuest
 ÿ��points_adjust��Ӧһ��winid��
 
 ���磨10,10�� �����ڴ���1�ʹ���2,�ڴ���1�ϵĶ�Ӧ�����ǣ�100,100�����ڴ���2�ϵ�
 ��Ӧ�����ǣ�1000,1000��
 ��ô	points_adjust[i].x = 100,		winid[i] = 1;
 points_adjust[i].y = 100,
 points_adjust[i+1].x = 1000,	winid[i+1] = 2;
 points_adjust[i+1].y = 1000,
 *******************************************************************************/
PLAYSDK_API BOOL PLAY_FishEyeTransFromLineFSTA(LONG nPort, FISHEYE_POINT2D *points, int num, FISHEYE_POINT2D *points_adjust, int *winid, int *points_adjust_num, FISHEYE_OPTPARAM *pOpt);

/******************************************************************************
 *
 * ������  : PLAY_FishEyeTransFromLineFSTS(from source to source)
 * ��  ��  : ԭʼͼ������תԭʼͼ������
 * ��  ��  : - handle: �����㷨ʵ�����
 - points:��Ҫת����ԭʼͼ���ϵ�����
 num:�������
 points_adjust:ת���������
 points_adjust_num    �����ĸ���
 pOpt:������Ϣ ��������ӿ�֮ǰ�ȵ���Fisheye_GetParam��ȡ
 * ��  ��  : ��
 * ����ֵ  : BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
 *******************************************************************************/
PLAYSDK_API BOOL PLAY_FishEyeTransFromLineFSTS(LONG nPort, FISHEYE_POINT2D *points, int num, FISHEYE_POINT2D *points_adjust, int *points_adjust_num, FISHEYE_OPTPARAM *pOpt);

//------------------------------------------------------------------------
// ����: PLAY_StartDeNoise
// ����: ������Ƶȥ���㷨����,��Ҫ����3dnr.dll��
// ����: [in]nPort : ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StartDeNoise(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetDeNoiseParams
// ����: ������Ƶȥ�����
// ����: [in]nPort           :  ͨ����
//		 [in]nTemporal		 :  ʱ��ȥ��ǿ�� [0,32]
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDeNoiseParams(LONG nPort, int nTemporal);

//------------------------------------------------------------------------
// ����: PLAY_StopDeNoise
// ����: ֹͣ��Ƶȥ���㷨����
// ����: [in]nPort : ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopDeNoise(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_StartDeHaze
// ����: ������Ƶȥ���㷨���ܣ���Ҫ����dehazing.dll��
// ����: [in]nPort : ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StartDeHaze(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetDehazeParams
// ����: ������Ƶȥ������
// ����: [in]nPort           :  ͨ����
//		 [in]ALightValue	 :	�趨�Ĵ�����ǿ��ֵ����Χ0-255
//		 [in]AutoLightOn	 :  Ĭ��Ϊ1,���������Զ�Ѱ�Ҵ�����ǿ��0-�ر��Զ��������ֶ�
//       [in]AutoRun		 :	Ĭ��Ϊ1,����һֱ����ȥ�����ܣ�0-�Զ��ж��Ƿ����첢ȥ��
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDehazeParams(LONG nPort, int ALightValue, int AutoLightOn, int AutoRun);

//------------------------------------------------------------------------
// ����: PLAY_STOPDeHaze
// ����: ֹͣ��Ƶȥ���㷨����
// ����: [in]nPort : ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopDeHaze(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_StartIVSE
// ����: ������Ƶ��ǿ�㷨���ܣ���Ҫ����IvseDll.dll��
// ����: [in]nPort : ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//
// ע�⣺���㷨����ʱ��ϳ��������鴦��������Ƶ
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StartIVSE(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetIVSEParams
// ����: ������Ƶ��ǿ���������Զ�ε��������ʹ�ö���IVSE��Ĺ���
// ����: [in]nPort           :  ͨ����
//		 [in]pIVSEParams	 :	IVSEPARAMS�ṹ�����
//		 [in]bEnable		 :  ��Ӧ��IVSEPARAMS�е�IVSEFUNCTYPE����ѡ�ʹ�ܿ���
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetIVSEParams(LONG nPort, IVSEPARAMS* pIVSEParams, BOOL bEnable);

//------------------------------------------------------------------------
// ����: PLAY_StopIVSE
// ����: ֹͣ��Ƶ��ǿ�㷨����
// ����: [in]nPort : ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopIVSE(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_ConvertToBmpFile
// ����: ͼ���ʽתΪBMP��ʽ.
// ����: pBuf,ͼ������ָ��
//		 nSize,ͼ�����ݴ�С
//		 nWidth,ͼ�����
//		 nHeight,ͼ��߶�
//		 nType,��������.T_RGB32,T_UYVY��.
//		 sFileName,Ҫ������ļ���.�����BMP��Ϊ�ļ���չ��.
//       nBmpType, BMP���ͣ�PIC_BMP_32��ʾBMP32�� PIC_BMP_24��ʾBMP24
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ConvertToBmpFileEx(char * pBuf,LONG nSize,LONG nWidth,LONG nHeight,LONG nType, char *sFileName,int nBmpType);

//------------------------------------------------------------------------
// ����: PLAY_EnableLargePicAdjustment
// ����: �Ƿ����ø���ͼ���ڲ��������ԣ�Ĭ�����á��ò�������ʱ���ڿ��4��������ʱ��ֻ����I֡��������ʱ����ÿ֡������
// ����: [in]nPort           :  ͨ����
//		 [in]bEnable		 :  TRUE��ʾ���ô˹��ܣ�FALSE��ʾ�رմ˹���
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_EnableLargePicAdjustment(LONG nPort, BOOL bEnable);

//------------------------------------------------------------------------
// ͬ�����Žӿ�
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// ����: PLAY_OpenPlayGroup
// ����: ��ͬ������
// ����: ��
// ����: ͬ�����ſ��ƾ�����ڵ���ͬ�����ſ��ƽӿ�ʱ��Ҫ����þ��������NULL��ʾʧ��
//------------------------------------------------------------------------
PLAYSDK_API void* CALLMETHOD PLAY_OpenPlayGroup();

//------------------------------------------------------------------------
// ����: PLAY_AddToPlayGroup
// ����: ����һ·�Ѿ���������Ƶ��ͬ��������
// ����: hPlayGroup,ͬ�����ž������PLAY_OpenPlayGroup����
//       nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_AddToPlayGroup(void* hPlayGroup, LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_DelFromPlayGroup
// ����: ��ͬ�����Ŷ�����ɾ��ָ��ͨ����
// ����: hPlayGroup,ͬ�����ž������PLAY_OpenPlayGroup����
//       nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_DelFromPlayGroup(void* hPlayGroup, LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetPlayGroupDirection
// ����: �ӵ�ǰʱ������Ż򵹷�
// ����: hPlayGroup,ͬ�����ž������PLAY_OpenPlayGroup����
//		 nDirection,���ŷ���0����ǰ��1�����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayGroupDirection(void* hPlayGroup, int nDirection);

//------------------------------------------------------------------------
// ����: PLAY_SetPlayGroupSpeed
// ����: ���ò����ٶ�
// ����: hPlayGroup,ͬ�����ž������PLAY_OpenPlayGroup����
//		 fCoff,�����ٶ�,��Χ[1/64~64.0],С��1��ʾ���ţ�����1��ʾ����.
//			   �������ٶȽϿ�ʱ���ܻ��֡����.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayGroupSpeed(void* hPlayGroup, float fSpeed);

//------------------------------------------------------------------------
// ����: PLAY_PausePlayGroup
// ����: ��ͣ�����
// ����: hPlayGroup,ͬ�����ž������PLAY_OpenPlayGroup����
//		 bPause,TRUE��ͣ,FLASE�ָ�
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_PausePlayGroup(void* hPlayGroup, BOOL bPause);

//------------------------------------------------------------------------
// ����: PLAY_StepPlayGroup
// ����: ��֡����
// ����: hPlayGroup,ͬ�����ž������PLAY_OpenPlayGroup����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StepPlayGroup(void* hPlayGroup);

//------------------------------------------------------------------------
// ����: PLAY_StepPlayGroup
// ����: ���þ���ʱ����ж�λ
// ����: hPlayGroup,ͬ�����ž������PLAY_OpenPlayGroup����
//	     pstDateTime,����ʱ��
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SeekPlayGroup(void* hPlayGroup, DATETIME_INFO* pstDateTime);

//------------------------------------------------------------------------
// ����: PLAY_ClosePlayGroup
// ����: �ر�ͬ�����ſ���
// ����: hPlayGroup,ͬ�����ž������PLAY_OpenPlayGroup����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ClosePlayGroup(void* hPlayGroup);


//------------------------------------------------------------------------
// ����: PLAY_SetFileRefCallBack
// ����: ���ý��������ص�,���ļ���ʱ�����ļ�����.������̺�ʱ�Ƚϳ�,��Լ
//			ÿ�봦��40M���ҵ�����,��Ϊ��Ӳ�̶����ݱȽ���,���������Ĺ�������
//			��̨���,��Ҫʹ�������ĺ���Ҫ�ȴ�������̽���,�����ӿڲ���Ӱ��.
// ����: nPort,ͨ����
//		 pFileRefDone,�ص�����ָ��,�������������:
//			nPort,ͨ����
//			pUserData,�û��Զ������
//		 pUserData,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void(CALLBACK *fpFileRefDoneCBFun)(DWORD nPort, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileRefCallBack(LONG nPort,
                                                    fpFileRefDoneCBFun pFileRefDoneCBFunc,
                                                    void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_SetDemuxCallBack
// ����: Դ���ݷ���������ݻص�
// ����: nPort,ͨ����
//		 DecCBFun,�������ݻص�ָ��
//			nPort,ͨ����
//			pBuf,����ָ��
//			nSize,���ݳ���
//			pParam,֡��Ϣ  ָ��DEMUX_INFO����ṹ��
//			nReserved,����
//			pUserData,�û��Զ�������
//		 pUserData,�û��Զ�������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fDemuxDecCBFun)(LONG nPort,char * pBuf,	LONG nSize,void * pParam,void* pReserved, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDemuxCallBack(LONG nPort, fDemuxDecCBFun DecCBFun, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_SetFileDoneTimeCallBack
// ����: �ļ���ʼ������ʱ��ص����������ļ���ʼ�ͽ���ʱ������øûص���
// ����: nPort,ͨ����
//		 fFileTimeDoneCBFun,�ص�����ָ��,����ΪNULL,�������������:
//			nPort,ͨ����
//			nStartTime, �ļ���ʼʱ��.��1970��1��1��0��0��0�������.
//			nEndTime, �ļ�����ʱ��.��1970��1��1��0��0��0�������.
//			pUserData, �û��Զ������
//		 pUserData, �û��Զ������.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fFileTimeDoneCBFun)(LONG nPort, DWORD nStarTime, DWORD nEndTime, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileTimeDoneCallBack(LONG nPort, fFileTimeDoneCBFun FileTimeCBFun, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_GetKeyFramePosByAbsoluteTime
// ����: ������ʱ�����ָ��λ��֮ǰ�Ĺؼ�֡λ��.
// ����: nPort,ͨ����
//		 t,����ʱ��,���SYSTEMTIME.���õ�������ʱ����.ע����ִ�гɹ����ֵ�洢������I֡��ʱ���
//		 framePos,���ҵ��Ĺؼ�֡���ļ�λ����Ϣ�ṹָ��,���PFRAME_POS.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
PLAYSDK_API BOOL CALLMETHOD PLAY_GetKeyFramePosByAbsTime(LONG nPort, SYSTEMTIME* t, FRAME_POS* framePos);

//------------------------------------------------------------------------
// ����: PLAY_GetNextKeyFramePosByAbsoluteTime
// ����: ������ʱ�����ָ��λ��֮��Ĺؼ�֡λ��.
// ����: nPort,ͨ����
//		 t,����ʱ��,���SYSTEMTIME.���õ�������ʱ����.ע����ִ�гɹ����ֵ�洢�����ص�I֡��ʱ���
//		 framePos,���ҵ��Ĺؼ�֡���ļ�λ����Ϣ�ṹָ��,���PFRAME_POS.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
PLAYSDK_API BOOL CALLMETHOD PLAY_GetNextKeyFramePosByAbsTime(LONG nPort, SYSTEMTIME* t, FRAME_POS* framePos);

//------------------------------------------------------------------------
// ����: PLAY_QueryGroupPlayingTime
// ����: ��ѯ��ǰ�������ڲ��ŵ�ʱ��.
// ����: nPort,ͨ����
//		 pDateTime,ʱ��
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
PLAYSDK_API BOOL CALLMETHOD PLAY_QueryGroupPlayingTime(void* hPlayGroup,  DATETIME_INFO *pDateTime);

//------------------------------------------------------------------------
// ����: PLAY_GetAudioChannels
// ����: ��ȡ��Ƶͨ������
// ����: nPort,ͨ����
//       pChannels, ���������[0-255].
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetAudioChannels(LONG nPort, DWORD* pChannels);

//------------------------------------------------------------------------
// ����: PLAY_ChooseAudio
// ����: ѡ����Ƶͨ��
// ����: nPort,ͨ����
//       nChannelID, ��Ƶͨ����0��ʼ.
//       bFlag,TRUE��,FALSE�ر�
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ChooseAudio(LONG nPort, DWORD nChannelID, BOOL bFlag);

//------------------------------------------------------------------------
// ����: PLAY_GetAudioChooseState
// ����: ��ȡ��Ƶͨ���򿪹ر�״̬
// ����: nPort,ͨ����
//       nChannelID, ��Ƶͨ��[0-255].
//       pFlag,TRUE��,FALSE�ر�
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetAudioChooseState(LONG nPort, DWORD nChannelID, BOOL* bFlag);

//------------------------------------------------------------------------
// ����: PLAY_SetPlayedAbsTime
// ����: ������ʱ�����ò���ʱ��
// ����: nPort,ͨ����
//		 pDateTime,����ʱ��
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayedAbsTime(LONG nPort, DATETIME_INFO *pDateTime);

//------------------------------------------------------------------------
// ����: PLAY_SetPlayPosByFileOffset
// ����: ���ļ�ƫ�����ò���λ��
// ����: nPort,ͨ����
//		 nFileOffset,�ļ�ƫ��λ��
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayPosByFileOffset(LONG nPort, UINT nFileOffset);

//------------------------------------------------------------------------
// ����: PLAY_GetCurrentFrameRateEx
// ����: ��õ�ǰ֡�ʣ�С����ʽ��
// ����: nPort,ͨ����
// ����: float,��ǰ֡�
//------------------------------------------------------------------------
PLAYSDK_API float CALLMETHOD PLAY_GetCurrentFrameRateEx(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_InitDDraw
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_InitDDraw(HWND hWnd);

//------------------------------------------------------------------------
// ����: PLAY_GetCaps
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API int	CALLMETHOD PLAY_GetCaps();

//------------------------------------------------------------------------
// ����: PLAY_GetFileHeadLength
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetFileHeadLength();

//------------------------------------------------------------------------
// ����: PLAY_RealeseDDraw
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_RealeseDDraw();

//------------------------------------------------------------------------
// ����: PLAY_GetDDrawDeviceTotalNums
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetDDrawDeviceTotalNums();

//------------------------------------------------------------------------
// ����: PLAY_SetDDrawDevice
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDDrawDevice(LONG nPort,DWORD nDeviceNum);

//------------------------------------------------------------------------
// ����: PLAY_GetDDrawDeviceInfo
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetDDrawDeviceInfo(DWORD nDeviceNum,LPSTR  lpDriverDescription,DWORD nDespLen,LPSTR lpDriverName ,DWORD nNameLen,LONG *hhMonitor);

//------------------------------------------------------------------------
// ����: PLAY_GetCapsEx
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API int	CALLMETHOD PLAY_GetCapsEx(DWORD nDDrawDeviceNum);

//------------------------------------------------------------------------
// ����: PLAY_ThrowBFrameNum
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ThrowBFrameNum(LONG nPort,DWORD nNum);

//------------------------------------------------------------------------
// ����: PLAY_InitDDrawDevice
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL	CALLMETHOD PLAY_InitDDrawDevice();

//------------------------------------------------------------------------
// ����: PLAY_ReleaseDDrawDevice
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API void CALLMETHOD PLAY_ReleaseDDrawDevice();

//------------------------------------------------------------------------
// ����: PLAY_Back
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Back(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetDDrawDeviceEx
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDDrawDeviceEx(LONG nPort,DWORD nRegionNum,DWORD nDeviceNum);


//------------------------------------------------------------------------
// ����: PLAY_SetOverlayMode
// ����: �˽ӿ���Ч��overlayģʽ�Ѿ���ʱ
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetOverlayMode(LONG nPort,BOOL bOverlay,COLORREF colorKey);


//------------------------------------------------------------------------
// ����: PLAY_GetOverlayMode
// ����: �˽ӿ���Ч��overlayģʽ�Ѿ���ʱ
//------------------------------------------------------------------------
PLAYSDK_API LONG CALLMETHOD PLAY_GetOverlayMode(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetColorKey
// ����: �˽ӿ���Ч��overlayģʽ�Ѿ���ʱ
//------------------------------------------------------------------------
PLAYSDK_API COLORREF CALLMETHOD PLAY_GetColorKey(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_ChangeRate
// ����: ����ӿ�PLAY_SetPlaySpeed
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ChangeRate(LONG nPort, int rate);

//------------------------------------------------------------------------
// ����: PLAY_SetTimerType
// ����: �˽ӿ���Ч
PLAYSDK_API BOOL CALLMETHOD PLAY_SetTimerType(LONG nPort,DWORD nTimerType,DWORD nReserved);

//------------------------------------------------------------------------
// ����: PLAY_GetTimerType
// ����: �˽ӿ���Ч
PLAYSDK_API BOOL CALLMETHOD PLAY_GetTimerType(LONG nPort,DWORD *pTimerType,DWORD *pReserved);

//------------------------------------------------------------------------
// ����: PLAY_SetMDRange
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetMDRange(LONG nPort,DISPLAYRECT* rc,DWORD nVauleBegin,DWORD nValueEnd,DWORD nType);

//------------------------------------------------------------------------
// ����: PLAY_SetMDThreShold
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetMDThreShold(LONG nPort, DWORD ThreShold);

//------------------------------------------------------------------------
// ����: PLAY_GetMDPosition
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetMDPosition(LONG nPort, DWORD Direction, DWORD nFrame, DWORD* MDValue);


//------------------------------------------------------------------------
// ����: PLAY_CutFileSegment
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
typedef void (CALLBACK *CutProgressFunc)(DWORD nPort, int iProgress, DWORD dwUser);
PLAYSDK_API BOOL CALLMETHOD PLAY_CutFileSegment(LONG nPort,
                                                LONG lBeginTime,
                                                LONG lEndTime,
                                                CutProgressFunc pFunc,
                                                char *sOutFilePath,
                                                DWORD dwUser);

//------------------------------------------------------------------------
// ����: PLAY_SetVideoPerTimer
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVideoPerTimer(int iVal);


//------------------------------------------------------------------------
// ����: PLAY_GetVideoPerTimer
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetVideoPerTimer(int* pVal);

//------------------------------------------------------------------------
// ����: PLAY_InputVideoData
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_InputVideoData(LONG nPort,PBYTE pBuf,DWORD nSize);

//------------------------------------------------------------------------
// ����: PLAY_InputAudioData
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_InputAudioData(LONG nPort,PBYTE pBuf,DWORD nSize);

//------------------------------------------------------------------------
// ����: PLAY_SetVerifyCallBack
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
typedef void (CALLBACK * fVerifyCBFun)(LONG nPort, FRAME_POS * pFilePos, DWORD bIsVideo, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVerifyCallBack(LONG nPort, DWORD nBeginTime, DWORD nEndTime, fVerifyCBFun VerifyFun, void* pUserData);


//------------------------------------------------------------------------
// ����: PLAY_SetSourceBufCallBack
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
typedef void (CALLBACK * fSourceBufCBFun)(LONG nPort,DWORD nBufSize, void* pUserData,void*pResvered);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetSourceBufCallBack(LONG nPort,
                                                      DWORD nThreShold,
                                                      fSourceBufCBFun SourceBufCBFun,
                                                      void* pUserData,
                                                      void *pReserved);

//------------------------------------------------------------------------
// ����: PLAY_ResetSourceBufFlag
// ����: �˽ӿ���Ч
//------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ResetSourceBufFlag(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetPandoraWaterMarkCallBack
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPandoraWaterMarkCallBack(LONG nPort, GetWaterMarkInfoCallbackFunc pFunc, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_SetDisplayBuf
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDisplayBuf(LONG nPort,DWORD nNum);

//------------------------------------------------------------------------
// ����: PLAY_GetDisplayBuf
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetDisplayBuf(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetDisplayType
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDisplayType(LONG nPort,LONG nType);

//------------------------------------------------------------------------
// ����: PLAY_GetDisplayType
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API LONG CALLMETHOD PLAY_GetDisplayType(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_RefreshPlayEx
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_RefreshPlayEx(LONG nPort,DWORD nRegionNum);

//------------------------------------------------------------------------
// ����: PLAY_OpenStreamEx
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenStreamEx(LONG nPort,PBYTE pFileHeadBuf,DWORD nSize,DWORD nBufPoolSize);

//------------------------------------------------------------------------
// ����: PLAY_CloseStreamEx
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CloseStreamEx(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_AdjustFluency
// ����: �˽ӿ���Ч
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_AdjustFluency(LONG nPort, int level);

//------------------------------------------------------------------------
// ����: PLAY_SurfaceChange
// ����: Android�汾ר�ã�Surface������仯֪ͨ
// ����:
// ����:
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SurfaceChange(LONG nPort, HWND hWnd);

//------------------------------------------------------------------------
// ����: PLAYER_SetFileInfoFrameCallback
// ����: �����ļ���Ϣ֡�ص�����
// ����:
// ����:
//------------------------------------------------------------------------
typedef int (CALLBACK* fOnFileInfoFrame)(LONG nPort, FILE_INFO_IMAGE* pFileInfoImage, FILE_INFO_FRAME* pFileInfoFrame, void* pUserParam);
PLAYSDK_API BOOL CALLMETHOD	PLAY_SetFileInfoFrameCallback(LONG nPort, fOnFileInfoFrame fFileInfoFrame, tPicFormats imageType, void* pUserParam);

//------------------------------------------------------------------------
// ����: PLAYER_SetAnalyzePositionCallback
// ����: �����ļ���Ϣ֡�������Ȼص�����
// ����:
// ����:
//------------------------------------------------------------------------
typedef int (CALLBACK *fOnAnalyzePosition)(LONG nPort, DATETIME_INFO* pstDateTime, void* pUserParam);
PLAYSDK_API BOOL CALLMETHOD	PLAY_SetAnalyzePositionCallback(LONG nPort, fOnAnalyzePosition fAnalyzePosition, void* pUserParam);

//------------------------------------------------------------------------
// ����: PLAYER_StartFileFrameDetect
// ����: ��Ҫ�������������֮�󣬿�ʼ�ļ���Ϣ֡��⣬������������
// ����:
// ����:
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD	PLAY_StartFileFrameDetect(LONG nPort, FILE_INFO_FRAME_SEARCH* pFileInfoFrameSearch);

//------------------------------------------------------------------------
// ����: PLAYER_StopFileFrameDetect
// ����: ��ֹ����
// ����:
// ����:
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD	PLAY_StopFileFrameDetect(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_StartEdgeEnhance
// ����: ����ͼ���񻯴���
// ����: level	   -- �����ȼ�,0-�ر�,6-��ǿ,Ĭ�ϵȼ�4
//		 algMode   -- �㷨ģʽ,Ԥ���ӿ�,Ŀǰֻ֧��0
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StartEdgeEnhance(LONG nPort, int level, int algMode);

//------------------------------------------------------------------------
// ����: PLAY_StopEdgeEnhance
// ����: �ر�ͼ���񻯴���
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopEdgeEnhance(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_StartVideoStable
// ����: ������Ƶ����
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StartVideoStable(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_StopEdgeEnhance
// ����: �ر���Ƶ����
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopVideoStable(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_Scale
// ����: �ֻ��汾ͼ������
// ����: nPort  �˿ں�
//       scale	���ű���[1.0, 8.0]
//       nRegionNum,��ʾ�������, ������
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Scale(LONG nPort, float scale, DWORD nRegionNum);

//------------------------------------------------------------------------
// ����: PLAY_Translate
// ����: �ֻ��汾ͼ��ƽ��
// ����: nPort  �˿ں�
//       x	xƽ�����꣬����ֵ
//	     y	yƽ�����꣬����ֵ
//       nRegionNum,��ʾ�������, ������
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Translate(LONG nPort, float x, float y, DWORD nRegionNum);

//------------------------------------------------------------------------
// ����: PLAY_SetIdentity
// ����: �ֻ��汾ͼ���һ��������ƽ�ƣ����Ų�����
// ����: nPort  �˿ں�
//       nRegionNum,��ʾ�������, ������
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetIdentity(LONG nPort, DWORD nRegionNum);

//------------------------------------------------------------------------
// ����: PLAY_GetScale
// ����: �ֻ��汾��ȡ��ǰ����ֵ��
// ����: nPort  �˿ں�
//       nRegionNum,��ʾ�������, ������
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
PLAYSDK_API float CALLMETHOD PLAY_GetScale(LONG nPort, DWORD nRegionNum);

//------------------------------------------------------------------------
// ����: PLAY_GetTranslateX
// ����: �ֻ��汾��ȡ��ǰx��ƽ�����ꡣ
// ����: nPort  �˿ں�
//       nRegionNum,��ʾ�������, ������
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
PLAYSDK_API float CALLMETHOD PLAY_GetTranslateX(LONG nPort, DWORD nRegionNum);

//------------------------------------------------------------------------
// ����: PLAY_GetTranslateX
// ����: �ֻ��汾��ȡ��ǰy��ƽ�����ꡣ
// ����: nPort  �˿ں�
//       nRegionNum,��ʾ�������, ������
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
PLAYSDK_API float CALLMETHOD PLAY_GetTranslateY(LONG nPort, DWORD nRegionNum);

//------------------------------------------------------------------------
// ����: PLAY_CleanScreen
// ����: �ֻ��汾��������
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CleanScreen(LONG nPort, float red, float green, float blue, float alpha, DWORD nRegionNum);

//------------------------------------------------------------------------
// ����: PLAY_ViewResolutionChanged
// ����: Android�汾,SurfaceView��С�仯ʱ����
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ViewResolutionChanged(LONG nPort, int nWidth, int nHeight, DWORD nRegionNum);

//------------------------------------------------------------------------
// ����: PLAY_StartDataRecordEx
// ����: ��ʼ������¼��,ֻ����ģʽ����,��PLAY_Play֮�����.
// ����: nPort,ͨ����
//		 sFileName,¼���ļ���,����ļ������в����ڵ��ļ���,�ʹ������ļ���.
//		 idataType,0��ʾԭʼ��Ƶ��;1��ʾת����AVI��ʽ;2��ʾת����ASF��ʽ;3�ֶα����ļ�
//		 fListenter, �ص���������������д�����з�������.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fRecordErrorOccur)(LONG nPort, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_StartDataRecordEx(LONG nPort, char *sFileName, int idataType, fRecordErrorOccur fListenter, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_SetMultiFrameDecCallBack
// ����: ����������Ϣ�ص������SVAC�����е�Щ�����Ϣ��
// ����: nPort  �˿ں�
//       nRegionNum,��ʾ�������, ������
//		 DecInfoCallBack, �ص�����
//		 pUser, �û��ص�����
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
typedef void (CALLBACK* fMultiFrameDecCallBack)(LONG nPort, LONG nStreamID, char* pData, LONG nLen,
FRAME_INFO* stFrameInfo, void* pUserData, LONG nReserved1);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetMultiFrameDecCallBack(LONG nPort, fMultiFrameDecCallBack DecInfoCallBack, void* pUser);

//------------------------------------------------------------------------
// ����: PLAY_SetMultiFrameCallBack
// ����: ������֡��Ϣ�ص���Ŀǰ��Ҫ���SVAC���룬
//       SVC�����У�һ�����ݴ��л��������ǿ����������
// ����: nPort  �˿ں�
//       MultiFrameCallBack, �ص�������
//       pUser  �û�����
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
typedef void (CALLBACK* fMultiFrameCallBack)(LONG nPort, LONG nStreamID, void* pUserData, LONG nReserved);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetMultiFrameCallBack(LONG nPort, fMultiFrameCallBack MultiFrameCallBack, void* pUser);

//------------------------------------------------------------------------
// ����: PLAY_SetDecInfoCallBack
// ����: ������֡��Ϣ�ص������SVAC����
// ����: nPort  �˿ں�
//       nFrameID, ѡ����в��ŵ�֡
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
typedef void (CALLBACK* fDecInfoCallBack)(LONG nPort, FRAME_DEC_EXT_INFO* pDecInfo, void* pUserData, LONG nReserved);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecInfoCallBack(LONG nPort, fDecInfoCallBack DecInfoCallBack, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_ChooseFrame
// ����: ѡ����ʾSVAC����SVC�Ļ��������ǿ��
// ����: nPort  �˿ں�
//       nFrameID, Ҫ��ʾ�Ĳ�(0: �����㣬1: ��ǿ��)
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ChooseFrame(LONG nPort, LONG nFrameID);

//------------------------------------------------------------------------
// ����: PLAY_RenderPrivateData
// ����: ��ʾ˽�����ݣ��������򣬹���򱨾����ƶ�����
// ����: nPort  �˿ں�
//       bTrue TRUE:�� FALSE:�ر�
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_RenderPrivateData(LONG nPort, BOOL bTrue, LONG nReserve);

//------------------------------------------------------------------------
// ����: PLAY_SetFileIndexProgressCallBack
// ����: ���������������Ȼص�
// ����: nPort  �˿ں�
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
typedef void (CALLBACK* fIndexProgressCB)(LONG nPort, float fProgress, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileIndexProgressCallBack(LONG nPort, fIndexProgressCB IndexProgressCB, void* pUser);

//------------------------------------------------------------------------
// ����: PLAY_GetLastYUVFrame
// ����: ������ȡ��һ֡��Ӧ��YUV����
// ����: nPort  �˿ں�
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetLastYUVFrame(LONG nPort, FRAME_DECODE_INFO* pFrameDecodeInfo);

//IOS����Ҫ���ڴ��С�汾
PLAYSDK_API BOOL CALLMETHOD PLAY_SetMemMinimized(LONG nPort);

PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecodeThreadNum(LONG nPort, DWORD nNum);

//���ý�����Կ��SVAC����ʹ��
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecodeKey(LONG nPort, const unsigned char *key, unsigned int key_len);

PLAYSDK_API BOOL CALLMETHOD PLAY_GetIRefValue(LONG nPort, BYTE *pBuffer, DWORD *pSize);

//------------------------------------------------------------------------
// ����: PLAY_OutsideRender
// ����: nacl ui�̵߳��ô˽ӿ�
// ����: nPort  �˿ں�
// ����: nWidth  ���ڿ�
// ����: nHeight  ���ڸ�
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OutsideRender(LONG nPort, int nWidth, int nHeight);


typedef void (CALLBACK* fDoubleVisibleDecCBFun)(LONG nPort,char * pBuf, int nSize, int nWidth, int nHeight, 
char* pSecondBuf, int nSecondSize, int nSecondWidth, int nSecondHeight, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDoubleVisibleDecCallBack(LONG nPort, fDoubleVisibleDecCBFun DataCBFun, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_EnableAudioChannel
// ����: ��������������Ƶ���ţ���������������Ƶ��Ч��
// ����: nPort  �˿ں�
// ����: nChnNum  ����ͨ����0-��ͨ����1-��ͨ��
// ����: bEnable  ʹ�� TRUE-���ã� FALSE-����
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_EnableAudioChannel(LONG nPort, DWORD nChnNum, BOOL bEnable);

//------------------------------------------------------------------------
// ����: PLAY_SplitProc
// ����: yuv ƴ���㷨������4k��������ʾ
// ����: nPort  �˿ں�
// ����: nMode ģʽ��0��Ӧ����ģʽ��1��Ӧ1+3ģʽ��2��Ӧ1+5ģʽ
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SplitProc(LONG nPort, int nMode);

//------------------------------------------------------------------------
// ����: PLAY_SplitProcUpdate
// ����: yuv ƴ���㷨��������Ҫ�Ŵ�ľ���λ��
// ����: nPort  �˿ں�
// ����: pAreaRect ���������������ʼ��ַ
//       ���nMode��0����ӦΪNULL
//       ���nMode��1���������Ĵ�СӦΪ3
//       ���nMode��2���������Ĵ�СӦΪ5              | 
// ����: TRUE �ɹ� FALSE ʧ��
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SplitProcUpdate(LONG nPort, DISPLAYRECT* pAreaRect);
    
#ifdef	__cplusplus
}
#endif

#endif
