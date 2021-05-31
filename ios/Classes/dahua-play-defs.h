/************************************************************************/
/* dhplay   �汾:  3.34			                                    */
/************************************************************************/

#ifndef _DHPLAY_DEFS_H
#define _DHPLAY_DEFS_H

#if (defined(WIN32) || defined(WIN64))
	#ifdef dhplay_EXPORTS
		#define PLAYSDK_API __declspec(dllexport)
	#else
		#define PLAYSDK_API __declspec(dllimport)
	#endif
	#define CALLMETHOD __stdcall
	#define CALLBACK   __stdcall
#else
	#define CALLMETHOD
	#define CALLBACK
	#define PLAYSDK_API //extern "C"
#endif

#if defined(WIN32) || defined(WIN64)
#include <windows.h>
#else
#ifdef __OBJC__
#include "objc/objc.h"
#else
#define BOOL        int
#endif
#define BYTE		unsigned char
#define PBYTE		BYTE*
#define LPBYTE		BYTE*
#ifndef LONG
#define LONG		long
#endif
#ifndef DWORD
#define DWORD		unsigned int
#endif
#define WORD		unsigned short
#define COLORREF	DWORD
#define HDC			void*
#define HWND		void*
#define LPSTR		char*
#define UINT		unsigned int
#define TRUE		1
#define FALSE		0

typedef struct _SYSTEMTIME
{
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;

#endif

typedef struct _tagRECT
{
	LONG left;
	LONG top;
	LONG right;
	LONG bottom;
}DISPLAYRECT;

#ifdef	__cplusplus
extern "C" {
#endif

/************************************************************************/
/* �궨��			                                                    */
/************************************************************************/

#define  FUNC_MAX_PORT					501		//���ͨ����

#define MIN_WAVE_COEF					-100	//PLAY_AdjustWaveAudioʹ��
#define MAX_WAVE_COEF					100		//PLAY_AdjustWaveAudioʹ��

#define TIMER_1							1		//��ý�嶨ʱ��
#define TIMER_2							2		//�̶߳�ʱ��

#define BUF_VIDEO_SRC					1		//��ƵԴ����
#define BUF_AUDIO_SRC					2		//��ƵԴ����
#define BUF_VIDEO_RENDER				3		//�������Ƶ���ݻ���
#define BUF_AUDIO_RENDER				4		//�������Ƶ���ݻ���

#define MAX_DISPLAY_WND					4

#define DISPLAY_NORMAL					1		//�����ֱ�����ʾ
#define DISPLAY_QUARTER					2		//1/4�ֱ�����ʾ

#define MAX_DIS_FRAMES					50		//���Ż�������󻺳�֡��
#define MIN_DIS_FRAMES					6		//���Ż�������С����֡��

#define BY_FRAMENUM						1		//��֡�ŷ�ʽ(PLAY_GetKeyFramePosʹ��)
#define BY_FRAMETIME					2		//��ʱ�䷽ʽ(PLAY_GetKeyFramePosʹ��)

#define SOURCE_BUF_MAX					1024*100000	//��������������󳤶�
#define SOURCE_BUF_MIN					1024*50		//��������������С����

#define STREAME_REALTIME				0		//ʵʱ��ģʽ
#define STREAME_FILE					1		//�ļ���ģʽ

#define T_AUDIO16						101		//16λ��Ƶ��������
#define T_AUDIO8						100		//8λ��Ƶ��������

#define T_UYVY							1		//UYVY���͵�YUV����,���ڲ�֧��.
#define T_IYUV							3		//IYUV(I420)����YUV����
#define T_RGB32							7		//RGB32����

#define SUPPORT_DDRAW					1		//֧��DIRECTDRAW,�����֧��,�򲥷������ܹ���
#define SUPPORT_BLT						2		//�Կ�֧��BLT����,�����֧��,�򲥷������ܹ���
#define SUPPORT_BLTFOURCC				4		//�Կ�BLT֧����ɫת��,�����֧��,��������ʹ�������ʽ��RGBת��
#define SUPPORT_BLTSHRINKX				8		//�Կ�BLT֧��X����С,�����֧��,ϵͳʹ�������ʽת��
#define SUPPORT_BLTSHRINKY				16		//�Կ�BLT֧��Y����С,�����֧��,ϵͳʹ�������ʽת��
#define SUPPORT_BLTSTRETCHX				32		//�Կ�BLT֧��X��Ŵ�,�����֧��,ϵͳʹ�������ʽת��
#define SUPPORT_BLTSTRETCHY				64		//�Կ�BLT֧��Y��Ŵ�,�����֧��,ϵͳʹ�������ʽת��
#define SUPPORT_SSE						128		//CPU֧��SSEָ��,Intel Pentium3����֧��SSEָ��
#define SUPPORT_MMX						256		//CPU֧��MMXָ�

#define PLAY_CMD_GetTime				1		//������ʱ����Ϣ
#define PLAY_CMD_GetFileRate			2		//֡����Ϣ
#define PLAY_CMD_GetMediaInfo			3		//ý����Ϣ
#define PLAY_CMD_GetRenderNum			4		//��ǰҪ��Ⱦ��֡��
#define PLAY_CMD_GetRenderTime			5		//��ǰҪ��Ⱦ��ʱ��
#define PLAY_CMD_GetSrcTime				6

#define AVI_MEDIACHANGE_FRAMERATE		1		//֡�ʸı�
#define AVI_MEDIACHANGE_RESOLUTION		2		//�ֱ��ʸı�

#define WATERMARK_DATA_TEXT				0		//����
#define WATERMARK_DATA_JPEG_BMP			1		//JPEG����BMPͼƬ
#define WATERMARK_DATA_FRAMEDATA		3		//֡����

#define	DH_PLAY_NOERROR					0		//û�д���
#define DH_PLAY_PARA_OVER				1		//��������Ƿ�
#define DH_PLAY_ORDER_ERROR				2		//����˳�򲻶�
#define DH_PLAY_TIMER_ERROR				3		//��ý��ʱ������ʧ��
#define DH_PLAY_DEC_VIDEO_ERROR			4		//��Ƶ����ʧ��
#define DH_PLAY_DEC_AUDIO_ERROR			5		//��Ƶ����ʧ��
#define DH_PLAY_ALLOC_MEMORY_ERROR		6		//�����ڴ�ʧ��
#define DH_PLAY_OPEN_FILE_ERROR			7		//�ļ�����ʧ��
#define DH_PLAY_CREATE_OBJ_ERROR		8		//�����߳��¼���ʧ��
#define DH_PLAY_CREATE_DDRAW_ERROR		9		//����directDrawʧ��
#define DH_PLAY_CREATE_OFFSCREEN_ERROR	10		//������˻���ʧ��
#define DH_PLAY_BUF_OVER				11		//��������,������ʧ��
#define DH_PLAY_CREATE_SOUND_ERROR		12		//������Ƶ�豸ʧ��
#define DH_PLAY_SET_VOLUME_ERROR		13		//��������ʧ��
#define DH_PLAY_SUPPORT_FILE_ONLY		14		//ֻ���ڲ����ļ�ʱ����ʹ��
#define DH_PLAY_SUPPORT_STREAM_ONLY		15		//ֻ���ڲ�����ʱ����ʹ��
#define DH_PLAY_SYS_NOT_SUPPORT			16		//ϵͳ��֧��,������ֻ�ܹ�����Pentium 3����
#define DH_PLAY_FILEHEADER_UNKNOWN		17		//û���ļ�ͷ
#define DH_PLAY_VERSION_INCORRECT		18		//�������ͱ������汾����Ӧ
#define DH_PLAY_INIT_DECODER_ERROR		19		//��ʼ��������ʧ��
#define DH_PLAY_CHECK_FILE_ERROR		20		//�ļ�̫�̻������޷�ʶ��
#define DH_PLAY_INIT_TIMER_ERROR		21		//��ʼ����ý��ʱ��ʧ��
#define DH_PLAY_BLT_ERROR				22		//λ����ʧ��
#define DH_PLAY_UPDATE_ERROR			23		//��ʾoverlayʧ��
#define DH_PLAY_MEMORY_TOOSMALL			24		//����̫С


// ��SVAC�����궨��
//SVC  flags
#define SVC_LAYER_BASE    0x0001
#define SVC_LAYER_ENHANCE 0x0002

#define MAX_CUSTOM_EXT_COUNT            8
#define MAX_EXT_ROI_REGION_NUM          32  //���ROI������չ�ĸ���    //��׼Э����û�涨���ֵ�Ƕ��٣����������ݶ�Ϊ32Ӧ�ù���
#define MAX_EXT_EVENT_REGION_NUM        32  //������¼���չ�ĸ���
#define MAX_EXT_ALERT_NUM               32  //����ر�����չ�ĸ���

//��չ���ݵ�����
#define EXT_TYPE_ROI        0x0001      //ROI������չ
#define EXT_TYPE_TIME       0x0002      //����ʱ����չ
#define EXT_TYPE_ALERT      0x0004      //������չ
#define EXT_TYPE_EVENT      0x0008      //����¼���չ
#define EXT_TYPE_AUTH       0x0010      //��֤����
#define EXT_TYPE_CUSTOM     0x1000      //�Զ�����չ


/************************************************************************/
/* �ṹ��	                                                            */
/************************************************************************/

typedef enum __tPicFormats
{
	PicFormat_BMP = 0,				        //BMP32����
    PicFormat_JPEG,							//JPEG����
	PicFormat_JPEG_70,						//70%������JPEG����
	PicFormat_JPEG_50,						//50%������JPEG����
	PicFormat_JPEG_30,						//30%������JPEG����
	PicFormat_JPEG_10,						//10%������JPEG����
	PicFormat_BMP24,                        //BMP24����
	PicFormat_TIFF							//TIFF����
} tPicFormats;

typedef struct
{
	LONG			nFilePos;				//ָ��֡���ļ��е�ƫ��λ��
	LONG			nFrameLen;				//֡����
	LONG			nFrameNum;				//֡���
	LONG			nFrameTime;				//֡ʱ��
	LONG			nErrorFrameNum;			//����,����ʹ��
	SYSTEMTIME*		pErrorTime;				//����,����ʹ��
	LONG			nErrorLostFrameNum;		//����,����ʹ��
	LONG			nErrorFrameSize;		//����,����ʹ��
}FRAME_POS,*PFRAME_POS;

typedef struct
{
	LONG			nWidth;					//�����,��λ����.�������Ƶ������Ϊ0.
	LONG			nHeight;				//�����,�������Ƶ������Ϊ0
	LONG			nStamp;					//ʱ����Ϣ,��λ����
	LONG			nType;					//��Ƶ֡����,T_AUDIO16,T_RGB32,T_IYUV
	LONG			nFrameRate;				//����ʱ������ͼ��֡��
}FRAME_INFO;

typedef struct
{
	#define FRAME_TYPE_VIDEO 0				//��Ƶ֡
	#define FRAME_TYPE_AUDIO 1				//��Ƶ֡
	int				nFrameType;				//��Ƶ֡����,�����涨��
	int				nFrameSeq;				//֡���
	int				nStamp;					//ʱ����Ϣ,��λ����
	int				nWidth;					//�����,��λ����.�������Ƶ������Ϊ0.
	int 			nHeight;				//�����,�������Ƶ������Ϊ0
	int				nFrameRate;				//����ʱ������ͼ��֡��
	int				nChannels;				//��Ƶͨ����
	int				nBitPerSample;			//��Ƶ����λ��
	int				nSamplesPerSec;			//��Ƶ����Ƶ��
	int				nRemainData;			//����ʣ��������
	SYSTEMTIME		nDataTime;				//ʱ��
	int				nReserved[59];			//�����ֶ�
}FRAME_INFO_EX;

typedef struct 
{
	int				nFrameType;					//֡����,�����FRAME_INFO_EX��nFrameType�ֶ�
	
	void*			pAudioData;				//��Ƶ����,�������Ƶ֡
	int				nAudioDataLen;			//��Ƶ���ݳ���

	void*			pVideoData[3];			//�ֱ��ʾ��Ƶ��YUV��������
	int				nStride[3];				//�ֱ��ʾYUV���������Ŀ��
	int				nWidth[3];				//�ֱ��ʾYUV���������Ŀ��
	int				nHeight[3];				//�ֱ��ʾYUV���������ĸ߶�
	int				nReserved[64];			//�����ֶ�
}FRAME_DECODE_INFO;

typedef struct 
{
	int			lWidth;					//�����,��λ����.
	int			lHeight;				//�����
	int			lFrameRate;				//֡��
	int			lChannel;				//��Ƶͨ����
	int			lBitPerSample;			//��Ƶ����λ��
	int			lSamplesPerSec;			//��Ƶ����Ƶ��
}MEDIA_INFO;

typedef struct 
{
	char*			pDataBuf;				//֡����
	LONG			nSize;					//֡���ݳ���
	LONG			nFrameNum;				//֡���
	BOOL			bIsAudio;				//�Ƿ���Ƶ֡
	LONG			nReserved;				//����
}FRAME_TYPE;



// ���븽����Ϣ
typedef struct
{
    LONG			nVideoEncodeType;   // ��������
    LONG	        nDataLen;           // �������ݳ���
    char*           pUserData;              // ������Ϣ
    LONG	        nReserved[2];
}FRAME_DEC_EXT_INFO;

// ��SVAC�������븽����Ϣ�Զ����ֶ�
typedef struct
{
    unsigned char type;             // ��Ϣ����
    unsigned char length;           // ��Ϣ����
    unsigned char *pbuf;            // ��Ϣָ��
    unsigned char reserved[2];      // ����
}DEC_EXT_INFO_CUSTOM;

typedef struct
{
    int flags;                              //��չ�������ͱ��

    int time_year;                          //����ʱ����չ
    int time_month;
    int time_day;
    int time_hour;
    int time_minute;
    int time_second;
    int time_sec_fractional;
    int time_frame_num;

    int roi_region_num;                             // ROI������չ
    int roi_top_left_x[MAX_EXT_ROI_REGION_NUM];     // ROI�������Ͻ�����x����
    int roi_top_left_y[MAX_EXT_ROI_REGION_NUM];     // ROI�������Ͻ�����y����
    int roi_width[MAX_EXT_ROI_REGION_NUM];          // ROI������
    int roi_height[MAX_EXT_ROI_REGION_NUM];         // ROI����߶�

    int event_region_num;                           // ����¼���չ
    int event_num[MAX_EXT_EVENT_REGION_NUM];
    int event_region_event_id[MAX_EXT_EVENT_REGION_NUM][16];

    int alert_num;                                  // ��ر�����չ
    int alert_region_id[MAX_EXT_ALERT_NUM];
    int alert_event_id[MAX_EXT_ALERT_NUM];
    int alert_frame_num[MAX_EXT_ALERT_NUM];

    //��֤������ز���
    int *auth_buf[2];                               // ��֤����buf, auth_buf[0]�ǻ�������֤����, auth_buf[1]����ǿ����֤����
    int auth_len[2];                                // ��֤���ݳ���, ��������֤����ʱ������Ӧ������Ϊ 0
    int auth_signature_type[2];
    int auth_hash_hierarchy_flag[2];

    DEC_EXT_INFO_CUSTOM svac_ext_info_custom[MAX_CUSTOM_EXT_COUNT];     // ��չ
}DEC_EXT_PARAM_SVAC;

/***begin���۶���***/
typedef enum
{
	FISHEYEMOUNT_MODE_INVALID = 0,
	FISHEYEMOUNT_MODE_CEIL = 1,						/*��װ*/
	FISHEYEMOUNT_MODE_WALL,							/*��װ*/
	FISHEYEMOUNT_MODE_FLOOR,						/*��װ*/
	FISHEYEMOUNT_MODE_NUM
}FISHEYE_MOUNTMODE;

typedef enum
{
	FISHEYECALIBRATE_MODE_INVALID = 0,
	FISHEYECALIBRATE_MODE_OFF = 1,								/*�ر������㷨�⣬�ⲿ�ر�*/
	FISHEYECALIBRATE_MODE_ORIGINAL,								/*ԭʼģʽ(������),�����ű���*/
	FISHEYECALIBRATE_MODE_PANORAMA,								/*1p*/
	FISHEYECALIBRATE_MODE_PANORAMA_PLUS_ONE_EPTZ,				/*1p+1*/
	FISHEYECALIBRATE_MODE_DOUBLE_PANORAMA,						/*2p*/
	FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_DOUBLE_PANORAMA,		/*1+2p*/
	FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_THREE_EPTZ_REGION,		/*1+3*/
	FISHEYECALIBRATE_MODE_PANORAMA_PLUS_THREE_EPTZ_REGION,		/*1p+3*/
	FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_TWO_EPTZ_REGION,		/*1+2*/	
	FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_FOUR_EPTZ_REGION,		/*1+4*/
	FISHEYECALIBRATE_MODE_PANORAMA_PLUS_FOUR_EPTZ_REGION,		/*1p+4*/
	FISHEYECALIBRATE_MODE_PANORAMA_PLUS_SIX_EPTZ_REGION,		/*1p+6*/
	FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_EIGHT_EPTZ_REGION,		/*1+8*/
	FISHEYECALIBRATE_MODE_PANORAMA_PLUS_EIGHT_EPTZ_REGION,		/*1p+8*/
	FISHEYECALIBRATE_MODE_TWO_EPTZ_REGION_WITH_ORIGINAL,		/*1F+2*/	
	FISHEYECALIBRATE_MODE_FOUR_EPTZ_REGION_WITH_ORIGINAL,		/*1F+4*/	
	FISHEYECALIBRATE_MODE_DOUBLE_PANORAMA_WITH_ORIGINAL,		/*1F+2p*/
	FISHEYECALIBRATE_MODE_FOUR_EPTZ_REGION_WITH_PANORAMA,		/*1p(F)+4*/
	FISHEYECALIBRATE_MODE_TWO_EPTZ_REGION,		                /*2����*/
	FISHEYECALIBRATE_MODE_SINGLE,								/*������*/
	FISHEYECALIBRATE_MODE_FOUR_EPTZ_REGION,						/*4����*/
	FISHEYECALIBRATE_MODE_USER_DEFINED,				    		/*�û��Զ���*/
	FISHEYECALIBRATE_MODE_PHONE,								/*�ֻ�ģʽ*/
	FISHEYECALIBRATE_MODE_ORIGINAL_PLUS_ONE_EPTZ_REGION,		/*1+1*/
	FISHEYECALIBRATE_MODE_ONE_EPTZ_REGION,						/*1����*/

	FISHEYECALIBRATE_MODE_NUM
}FISHEYE_CALIBRATMODE;

typedef enum
{
	FISHEYEEPTZ_CMD_INVALID = 0,	
	FISHEYEEPTZ_CMD_ZOOM_IN = 1,						/*�Ŵ�*/
	FISHEYEEPTZ_CMD_ZOOM_OUT,							/*��С*/
	FISHEYEEPTZ_CMD_UP,									/*�����ƶ�*/
	FISHEYEEPTZ_CMD_DOWN,								/*�����ƶ�*/
	FISHEYEEPTZ_CMD_LEFT,								/*�����ƶ�*/
	FISHEYEEPTZ_CMD_RIGHT,								/*�����ƶ�*/
	FISHEYEEPTZ_CMD_ROTATE_CLOCKWISE_AUTO,				/*�Զ�˳ʱ����ת*/
	FISHEYEEPTZ_CMD_ROTATE_ANTICLOCKWISE_AUTO,			/*�Զ���ʱ����ת*/
	FISHEYEEPTZ_CMD_STOP,								/*ֹͣ*/
	FISHEYEEPTZ_CMD_SHOW_REGION,						/*��ѡ�Ŵ�*/
	FISHEYEEPTZ_CMD_EXIT_SHOW_REGION,					/*�˳���ѡ�Ŵ�*/
	FISHEYEEPTZ_CMD_DEFAULT,						    /*�ָ�Ĭ��*/
	FISHEYEEPTZ_CMD_ORIGIN_ROTATE,						/*Բ��ת*/

	FISHEYEEPTZ_CMD_SET_CUR_REGION = 0x20,             /*����ָ�����ڵ�λ����Ϣ*/
	FISHEYEEPTZ_CMD_GET_CUR_REGION,                    /*��ȡָ�����ڵ�λ����Ϣ*/
	FISHEYEEPTZ_CMD_IS_IN_PANORAMA_REGION,             /*������Ƿ��ڵ�ǰȫ������������*/
	FISHEYEEPTZ_CMD_TAP_VIEW,							/*��ʾָ��λ��,���㼴��*/
	FISHEYEEPTZ_CMD_SET_FOCUS,	 				        /*���ô���λ����Ϣ*/
	FISHEYEEPTZ_CMD_GET_FOCUS,							/*��ȡ����λ����Ϣ*/

	FISHEYEEPTZ_CMD_PTZ_CALI,							/*���������궨*/
	FISHEYEEPTZ_CMD_GET_PTZ_RLT,						/*��ȡ����������λ��Ϣ*/
	FISHEYEEPTZ_CMD_NUM
}FISHEYE_EPTZCMD;

typedef struct
{
	int w;
	int h;
}FISHEYE_SIZE;

typedef struct
{
	short x;
	short y;
}FISHEYE_POINT2D;

typedef struct
{
	FISHEYE_MOUNTMODE     subMountMode;			    /*��ͼ��װģʽ, ����ͼ����У��ģʽΪ�û��Զ���ģʽʱ, ��ֵ��Ч*/
	FISHEYE_CALIBRATMODE  subCalibrateMode;	        /*��ͼ��У��ģʽ, ����ͼ����У��ģʽΪ�û��Զ���ģʽʱ, ��ֵ��Ч*/
	FISHEYE_SIZE          imgOutput;                /*��ͼ������ֱ���*/
	FISHEYE_POINT2D       upperLeft;                /*��ͼ��ƫ��*/
	int					  reserved[3];				/*�����ֽ�*/
}FISHEYE_SUBMODE;

typedef struct
{
	FISHEYE_SIZE          mainShowSize;		        /*�ݲ�����, ����ʾ����, 4:3, 16:9��, �㷨�ݴ�����ʺϵ����Ž��������������¾����ﵽ�ñ�����*/
	FISHEYE_SIZE          floatMainShowSize;		/*���˫bufferʱʹ�ã�Ŀǰ��ʱ�������ϵĲ����������������ڵ�����ʾ���ڷֱ���, ����Բ�Ŀ�߱���ҪΪ1:1��������װȫ���Ŀ�߱���ҪΪ16:9*/
	FISHEYE_SIZE          imgOutput;                /*���ͼ��ֱ���(����ǰ), ͼ����У��ģʽΪ�û��Զ���ģʽʱΪ�ⲿ����, ����ģʽΪ�ڲ�����*/
	FISHEYE_SUBMODE*	  subMode;                  /*��ģʽ��Ϣ, ͼ����У��ģʽΪ�û��Զ���ģʽʱΪ�ⲿ����, ����ģʽΪ�ڲ�����*/
	int		              subModeNum;               /*��ģʽ��, ͼ����У��ģʽΪ�û��Զ���ģʽʱΪ�ⲿ����, ����ģʽΪ�ڲ�����*/
	int                   outputSizeRatio;		    /*�ݲ�����, У�����ͼ������ű�,Q8��ʽ,��Χ0-256, 256Ϊ�����������ֱ���*/
	int                   reserved[1];				/*�����ֽ�*/
}FISHEYE_OUTPUTFORMAT;

typedef struct
{
	int x;
	int y;
	int hAngle;
	int vAngle;
	int available;
	int reserved[3];
}FISHEYE_REGIONPARAM;

typedef struct
{
	FISHEYE_REGIONPARAM   regionParam[9];
	int              circularOffset;
	int              panoramaOffset;
	int              useRegionParam;           /*Ϊ1ʱ������Ч��ʹ�ø�ֵ���г�ʼ����û�б�����Ϣʱ����Ϊ0*/
	int              reserved[1];
}FISHEYE_MODEINITPARAM;

/*ǹ������*/
typedef enum CAM_TYPE
{
	//ǹ������
	IPCTYPE_200WN				= 0,	//
	IPCTYPE_130WN				= 1,
	IPCTYPE_D1WN				= 2,
	IPCTYPE_100WN				= 3,
	IPCTYPE_FE					= 4,	//����

	//�������
	SPCTYPE_D6501				= 100,	//sony��о65���
	HSPCTYPE_D6A2030E			= 101,	//�󻪻�о2030E��6A���
	HSPCTYPE_D65A2030E			= 102,	//�󻪻�о2030E��65A���
}CAM_TYPE;

/*��ͷ����*/
typedef enum LEN_TYPE
{
	LENTYPE_NORM				= 0,	//�޻��侵ͷ
	LENTYPE_Lens0361 			= 1,	//3.6����ǹ����ͷ
	LENTYPE_Lens2880			= 2,	//130�ȹ��ǹ����ͷ
	LENTYPE_Lens0362 			= 3,	//3.6����ǹ����ͷ
	LENTYPE_Lens0401 			= 4,	//4.0����ǹ����ͷ

	LENTYPE_TEST1				= 100,	//�����ò���
}LEN_TYPE;

typedef struct
{	
	/*�������*/
	int zoom_type;							//��������ģʽ----��������Ӧ�䱶�͸��ݿ�ѡĿ���С�䱶����ģʽ
	int hcam_wax;							//����������Ӧ����Ƕ�x��ˮƽ��
	int hcam_way;							//����������Ӧ����Ƕ�y����ֱ��
	int hcam_wmul;							//�����������ã���׼������
	int cfg_type;							//���÷�ʽ��Ĭ��Ϊ1��ʹ�����ò�����ʽ,1��ʹ�ò������÷�ʽ��0��ʹ���豸�������÷�ʽ

	//���������							         
	//��ͷ����
	int prm_re;								//ͶӰ�뾶
	int prm_mul;							//ͶӰ����
	int prm_dx;								//x����ƫ��
	int prm_dy;								//y����ƫ��
	int prm_cw;								//CMOS��ʵ��ʹ�ÿ�
	int prm_ch;								//CMOS�ߣ�ʵ��ʹ�øߣ�

	//������ʹ�����������ã�cfg_typeΪ0ʱ���øò�������Ч��            //Ĭ��130�ȡ�130��ǹ����200W65���
	LEN_TYPE mlen_type;						//�������ͷ����
	CAM_TYPE mcam_type;						//���������
	CAM_TYPE hcam_type;						//���������

	//�������
	int himg_width;                         //�����ͼ���
	int himg_height;                        //�����ͼ���
	int prm_fax;                            //���ˮƽ�ӳ���

	/*��Ĭ�ϵĲ���*/
	//���������
	int mcam_fc;							//�����Ч����
	int mcam_cw;							//��ͷ�����
	int mcam_ch;							//��ͷ����� 
	int cam_height;                         //�������߶ȣ��ף�������ʱδʹ�ã�
	int prm_ma;								//�������

	//���������
	//�������
	int prm_hw;								//CMOS��
	int prm_hh;								//CMOS��
	int prm_fo;								//��Ч����
	int prm_ca;								//��Ұ����
	int prm_mmul;							//�����
}MHFPTZ_CONFIGPARAM;

typedef struct
{
	FISHEYE_SIZE     mainStreamSize;		    /*��Ӧ������ԭʼ��ߣ�������ֱ�����֮����ʱ����Ϊ�������Ǵ˷ֱ������Ŷ���*/
	int              originX;					/*����ͼ��������Բ��Բ�ĺ�����, ��һ����0-8192����ϵ*/
	int              originY;					/*����ͼ��������Բ��Բ��������, ��һ����0-8192����ϵ*/
	int              radius;					/*����ͼ��������Բ�İ뾶, ��һ����0-8192����ϵ*/ 
	int              lensDirection;		        /*��ת�Ƕ�, Q7��ʽ, ��Χ0-360*128, һ����Ϊ0*/
	FISHEYE_MOUNTMODE     mainMountMode;		/*����װģʽ*/
	FISHEYE_CALIBRATMODE  mainCalibrateMode;	/*ͼ����У��ģʽ*/
	FISHEYE_MODEINITPARAM modeInitParam;        /*�ⲿ����ģʽ��ʼ����������Ϣ��������ģʽ�л��ָ�����һ�ε�״̬,*/
	FISHEYE_OUTPUTFORMAT *outputFormat;         /*���ͼ����Ϣ*/
	MHFPTZ_CONFIGPARAM   *configParam;          /*�����������ò���*/
	int              enableAutoContrast;       /*�����Զ��Աȶ�, 0�ر�, 1����, �ù��ܻ������㷨��ʱ, ��Ҫ���ܺõĻ����Ž��鿪��*/
	int              alphaHistogram;           /*ֱ��ͼIIRǿ��0-255, Ĭ��128, Խ��Խ�ο���ǰ֡*/
	int              alphaGray;                /*�Ҷ�����ǿ��0-255, Ĭ��245, Խ��Խ�Աȶ���*/
	FISHEYE_SIZE     captureSize;		       /*��Ӧ��ǰģʽ�µ�ץͼ�ֱ���*/

	int              reserved[1];				/*�����ֽ�*/
}FISHEYE_OPTPARAM;

typedef struct
{
	FISHEYE_EPTZCMD   ePtzCmd;			/*��̨������˵����FISHEYE_EPtzCmd����*/
	int          winId;				    /*Ҫ����eptz�Ĵ��ڱ�ţ����Ͻ�winIdΪ0�������ҵ���*/							
	int          arg1;
	int          arg2;
	int          arg3;
	int          arg4;
	int          arg5;
	int          arg6;
	int          reserved0[6];			   /*�����ֽ�*/
	void*        pParam;                   /*��������*/
	void*        pResult;
	void*        pArg;   

	int          reserved1[7];			   /*�����ֽ�*/

}FISHEYE_EPTZPARAM;

typedef enum
{
	FISHEYE_SETPARAM,
	FISHEYE_GETPARAM

}FISHEYE_OPERATETYPE;
/***end���۶���***/


// Extension API
    
    
#define PIC_BMP_32                      0       //BMP32
#define PIC_BMP_24                      1       //BMP24

/*���ݾɰ汾���۽ӿ�*/
typedef enum
{
    FISHSHOWMODE_WALL_PANORAMA = 0,       //��װȫ��ģʽ
    FISHSHOWMODE_CEIL_PANORAMA,           //��װ360��ȫ��
    FISHSHOWMODE_CEIL_PANORAMA_TWO,       //��װ180��ȫ��
    FISHSHOWMODE_FLOOR_PANORAMA,          //�ذ尲װ360��ȫ��
    FISHSHOWMODE_FLOOR_PANORAMA_TWO,      //�ذ尲װ180��ȫ��
    FISHSHOWMODE_ONE_O_THREE,             //1+3ģʽ
    FISHSHOWMODE_CEIL_ONE_REGION = 10,    //��װ������eptz
    FISHSHOWMODE_CEIL_FOUR_REGION,        //��װ4����eptz
    FISHSHOWMODE_ORIGINAL,                //ԭʼģʽ����������ֱ�����ԭʼ����
    FISHSHOWMODE_WALL_ONE_REGION,         //��װ������eptz
    FISHSHOWMODE_WALL_FOUR_REGION,        //��װ4����eptz
    FISHSHOWMODE_FLOOR_ONE_REGION,        //�ذ尲װ������eptz
    FISHSHOWMODE_FLOOR_FOUR_REGION,       //�ذ尲װ4����eptz����ԭʼ����
    FISHSHOWMODE_WALL_ONE_O_THREE,	      //�ذ�1+3ģʽ
    FISHSHOWMODE_CEIL_ONE_O_THREE,	      //��װ1+3ģʽ
    FISHSHOWMODE_FLOOR_ONE_O_THREE,	      //��װ1+3ģʽ
    
}FISHSHOWMODES;

typedef enum
{
    FISHEPTZOPT_UPDATE_FOCUS,                   //���½���
    FISHEPTZOPT_ZOOM_IN,                        //�Ŵ�
    FISHEPTZOPT_ZOOM_OUT,                       //��С
    FISHEPTZOPT_MOVE_UP,                        //�����ƶ�
    FISHEPTZOPT_MOVE_DOWN,                      //�����ƶ�
    FISHEPTZOPT_MOVE_LEFT,                      //�����ƶ�
    FISHEPTZOPT_MOVE_RIGHT,                     //�����ƶ�
    FISHEPTZOPT_AUTO_ROTATE_CLOCKWISE,          //�Զ�˳ʱ����ת
    FISHEPTZOPT_AUTO_ROTATE_COUNTERCLOCKWISE,   //�Զ���ʱ����ת
    FISHEPTZOPT_STOP_AUTO_ROTATE,				//ֹͣ�Զ���ת
    FISHEPTZOPT_GET_POSITION,					//��ȡ��ǰ��̨��������λ��
    FISHEPTZOPT_SELECT_REGION_ZOOMIN_ON,        //��ѡ�Ŵ�
    FISHEPTZOPT_SELECT_REGION_ZOOMIN_OFF,		//�˳���ѡ�Ŵ�
    FISHEPTZOPT_RESTORE_DEFAULT_LOCATION,		//��̨�ָ�Ĭ��λ��
    
}FISHEPTZOPTS;
/***************/

//@begin��������
typedef struct
{
    int   himg_width;                       //�����ͼ���
    int   himg_height;                      //�����ͼ���
    int   *zoom_list;						/*���������*/
    int    zoom_list_size;					/*���������λ����*/
}MHFPTZ_INITPARAM;
//@end��������

// ������Ϣ
typedef struct __DATETIME_INFO
{
    unsigned int			nYear;			// ��
    unsigned int			nMonth;			// ��
    unsigned int			nDay;			// ��
    unsigned int			nHour;			// ʱ
    unsigned int			nMinute;		// ��
    unsigned int			nSecond;		// ��
    unsigned int			nMilliSecond;	// ����
}DATETIME_INFO;

typedef struct
{
    char*	pHead;
    int		nLen;
    char*	pBody;
    int		nBodyLen;
    
    int		nRet;				//0: decode 1://don't decode
    char	reserved[128];
}DemuInfoEx;

typedef struct
{
    int type;			// 1:VIDEO, 2:AUDIO, 3:DATA
    int subtype;		// I Frame, BP Frame, PCM8, MS-ADPCM etc.
    int encode;			// MPEG4, H264, STDH264
    int sequence;		// I֡�����������
    
    // ͼ���С��Ϣ
    int width;
    int height;
    
    // ֡����Ϣ
    int rate;
    
    // ʱ����Ϣ
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int secode;
    LONG timestamp;
    
    int channels;
    int bitspersample;
    int samplespersecond;
}DEMUX_INFO;

// �ļ���Ϣ֡
typedef struct __FILE_INFO_FRAME
{
    unsigned int		nFrameSubType;	  // ֡�����ͣ���������֡���¼�֡��
    DATETIME_INFO*		pstDateTimeStart; // ��ʼʱ��
    DATETIME_INFO*		pstDateTimeEnd;   // ����ʱ��
    unsigned char*		pFrameData;		  // ֡����
    unsigned int		nFrameDataLen;	  // ֡���ݳ���
} FILE_INFO_FRAME;

typedef struct __FILE_INFO_FRAME_SEARCH
{
    unsigned int		nFileFrameType;		//�������ͣ�������ϣ��� PLAYER_INFO_TYPE_MOTIONDECT | PLAYER_INFO_TYPE_EVENT
    DATETIME_INFO		stStartDataTime;    //��ʼʱ��
    DATETIME_INFO		stEndDataTime;      //����ʱ��
    DISPLAYRECT			rtDetectedRegion;   //�������еĶ����ⷶΧ������֡ʱ��Ч���������Ϊ0ʱ����ʾȫ��������
    DISPLAYRECT			rtTotal;			//������, ����֡ʱ��Ч
} FILE_INFO_FRAME_SEARCH;

typedef struct __FILE_INFO_IMAGE
{
    tPicFormats	   imageType;				// ͼƬ������
    unsigned char* pPicBuf;					// ͼƬ�Ļ���ָ��
    unsigned int   nPicBufLen;				// ͼƬ�ĳ���
    
} FILE_INFO_IMAGE;

typedef struct NativeHandle
{
    void* display;
    void* context;
    void* surface;
    
}Android_NativeHandle;

// �ļ���Ϣ֡���������ͣ���ӦFILE_INFO_FRAME_SEARCH�ṹ���е�nFileFrameType
#define PLAY_INFO_TYPE_MOTIONDECT     1         // ����
#define PLAY_INFO_TYPE_EVENT		  2         // �¼�

/************************************************************************/
/* ��ǿ֧�ֵĹ���                                                         */
/************************************************************************/
typedef enum
{
    IVSEFUNCTYPE_DEHAZE,	    // ȥ��
    IVSEFUNCTYPE_DENOISE,		// ȥ��
    IVSEFUNCTYPE_WB,			// ƫɫУ��
    IVSEFUNCTYPE_LOWLIGHT,		// ���ն���ǿ
    IVSEFUNCTYPE_HDR,			// ��̬
    IVSEFUNCTYPE_NUM			// ֧����ǿ�Ĺ��ܸ���
}IVSEFUNCTYPE;

/************************************************************************/
/* ROI�������Ͷ���                                                        */
/************************************************************************/
typedef struct
{
    int x;          // ���Ͻ�x����
    int y;          // ���Ͻ�y����
    int width;      // ������
    int height;     // ����߶�
}IVSEROI;

/************************************************************************/
/* ��Ƶ��ǿ�㷨�������                                                           */
/************************************************************************/
typedef struct
{
    IVSEFUNCTYPE eFuncType;   // ����ѡ��
    IVSEROI		 cRoi;        // ROI ����
    int			 nMode;       // 0��ʾͼƬģʽ�� 1��ʾ��Ƶģʽ
    int			 nProcess_param[2];     // �����������Χ[1,5]
    /*
     ���ܺ���	                process_param[0]	    process_param[1]
     IVSEFUNCTYPE_DEHAZE	        ������	                ���Ͷ�
     IVSEFUNCTYPE_DENOISE	    ������	                - ����Ƶģʽ��Ч��
     IVSEFUNCTYPE_WB	        -	                    -
     IVSEFUNCTYPE_LOWLIGHT	-   ������	                ���Ͷ�
     IVSEFUNCTYPE_HDR	        0:���� 1:��ҹ 2:�Զ�  	������
     */
    
}IVSEPARAMS;
    
    
#ifdef __cplusplus
}
#endif

#endif  //  _DHPLAY_DEFS_H
