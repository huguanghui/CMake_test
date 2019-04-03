/*!
* @file
*  ZWHosts.h 
* @brief
*  域名解析缓存管理模块
* @author
*  zw
* @date
*  2019年02月23日
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
配置文件为Ini格式，内容如下
[domain_0]
name=www.163.com
[domain_1]
name=www.sina.com.cn
[domain_2]
name=www.sohu.com
[timer]
interval=60
#interval单位为分钟
*/

/*!
* @brief
*	模块初始化接口
* @param config
*	配置文件路径（该配置文件为ZWHosts模块必须依赖的文件）
* @param hosts
*	系统域名缓存文件路径（根据系统内核的不同有：/etc/hosts等，具体请确认内核参数）
* @param resolve
*	系统DNS配置文件路径（例如：/etc/resolve.conf）
* @return
*	返回0表示成功, 否则表示错误码
* @note
*	模块初始化接口，使用功能接口前，请先初始化模块
* @note
*	接口类型: 阻塞式
*/
ZWHOSTS_API int Hosts_Initialize(IN const char *config, IN const char *hosts, IN const char *resolve);

/*!
* @brief
*	模块释放接口
* @return
*	返回0表示成功, 否则表示错误码
* @note
*	模块资源释放接口，应用退出时请释放模块资源，无需处理返回值
* @note
*	接口类型: 阻塞式
*/
ZWHOSTS_API int Hosts_Release(void);

/*!
* @brief
*	域名解析缓存更新接口
* @return
*	返回0表示成功, 否则表示错误码
* @note
*	建议在网络接口及路由等网络配置变化时调用，该接口会更新域名解析缓存
* @note
*	接口类型: 阻塞式
*/
ZWHOSTS_API int Hosts_Update(void);

#endif