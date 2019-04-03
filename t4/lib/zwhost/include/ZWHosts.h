/*!
* @file
*  ZWHosts.h 
* @brief
*  ���������������ģ��
* @author
*  zw
* @date
*  2019��02��23��
* @version
*  1.0.0
*/

#ifndef ZW_HOSTS_H

#define ZW_HOSTS_H

#ifdef ZWHOSTS_EXPORTS

#define ZWHOSTS_API			extern "C"__declspec(dllexport)
#ifndef CALLSTACK
#define CALLSTACK			__stdcall
#endif

#elif defined(__cplusplus)

#ifdef _WIN32

#define ZWHOSTS_API			extern "C"__declspec(dllimport)
#ifndef CALLSTACK
#define CALLSTACK			__stdcall
#endif

#else

#define ZWHOSTS_API			extern "C" __attribute ((visibility("default")))
#ifndef CALLSTACK
#define CALLSTACK
#endif

#endif

#else

#define ZWHOSTS_API
#define CALLSTACK

#endif

#include "ZWHostsCommon.h"

/*
�����ļ�ΪIni��ʽ����������
[domain_0]
name=www.163.com
[domain_1]
name=www.sina.com.cn
[domain_2]
name=www.sohu.com
[timer]
interval=60
#interval��λΪ����
*/

/*!
* @brief
*	ģ���ʼ���ӿ�
* @param config
*	�����ļ�·�����������ļ�ΪZWHostsģ������������ļ���
* @param hosts
*	ϵͳ���������ļ�·��������ϵͳ�ں˵Ĳ�ͬ�У�/etc/hosts�ȣ�������ȷ���ں˲�����
* @param resolve
*	ϵͳDNS�����ļ�·�������磺/etc/resolve.conf��
* @return
*	����0��ʾ�ɹ�, �����ʾ������
* @note
*	ģ���ʼ���ӿڣ�ʹ�ù��ܽӿ�ǰ�����ȳ�ʼ��ģ��
* @note
*	�ӿ�����: ����ʽ
*/
ZWHOSTS_API int Hosts_Initialize(IN const char *config, IN const char *hosts, IN const char *resolve);

/*!
* @brief
*	ģ���ͷŽӿ�
* @return
*	����0��ʾ�ɹ�, �����ʾ������
* @note
*	ģ����Դ�ͷŽӿڣ�Ӧ���˳�ʱ���ͷ�ģ����Դ�����账����ֵ
* @note
*	�ӿ�����: ����ʽ
*/
ZWHOSTS_API int Hosts_Release(void);

/*!
* @brief
*	��������������½ӿ�
* @return
*	����0��ʾ�ɹ�, �����ʾ������
* @note
*	����������ӿڼ�·�ɵ��������ñ仯ʱ���ã��ýӿڻ����������������
* @note
*	�ӿ�����: ����ʽ
*/
ZWHOSTS_API int Hosts_Update(void);

#endif