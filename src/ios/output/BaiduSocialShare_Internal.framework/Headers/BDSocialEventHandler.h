//
//  Created by Baidu Developer Center on 13-3-10.
//  官网地址:http://developer.baidu.com/soc/share
//  技术支持邮箱:dev_support@baidu.com
//  Copyright (c) 2013年 baidu.com. All rights reserved.
//


#import <Foundation/Foundation.h>

/**
 *	@brief	回调结果状态
 */
typedef enum {
    BD_SOCIAL_SUCCESS = 0,        //成功
    BD_SOCIAL_FAIL,               //失败
    BD_SOCIAL_CANCEL,             //取消
} BD_SOCIAL_RESULT;


/**
 *	@brief	社会化服务错误码定义
 */
//未知错误
#define BD_SOCIAL_SERVER_ERRORCODE_UNKNOWN                        1
//服务暂时不可用
#define BD_SOCIAL_SERVER_ERRORCODE_SERVICE_UNAVAILABLE            2
//调用次数过于频繁
#define BD_SOCIAL_SERVER_ERRORCODE_REQUEST_FREQUENTLY             4
//第三方平台服务错误
#define BD_SOCIAL_SERVER_ERRORCODE_THIRD_PLATFORM                 12
//参数错误
#define BD_SOCIAL_SERVER_ERRORCODE_INVALID_PARAM                  100
//API KEY错误
#define BD_SOCIAL_SERVER_ERRORCODE_INVALID_APIKEY                 101
//Session Key错误
#define BD_SOCIAL_SERVER_ERRORCODE_INVALID_SESSION_KEY            102
//参数签名错误
#define BD_SOCIAL_SERVER_ERRORCODE_INVALID_SIG                    104
//Session Key过期失效
#define BD_SOCIAL_SERVER_ERRORCODE_EXPIRED_SESSION_KEY            112

/**
 *	@brief	社会化组件错误码定义
 */
//sdk未被初始化
#define BD_SOCIAL_LOCAL_ERRORCODE_UNINITIALIZED             1000
//无网络错误
#define BD_SOCIAL_LOCAL_ERRORCODE_NETWORK_UNAVAILABLE       1001
//无效的接口参数
#define BD_SOCIAL_LOCAL_ERRORCODE_INVALID_PARAM             1002
//未安装微信
#define BD_SOCIAL_LOCAL_ERRORCODE_WEIXIN_NOTINSTALL         1003
//微信版本过低
#define BD_SOCIAL_LOCAL_ERRORCODE_WEIXIN_VERSION_LOW        1004
//其他微信错误
#define BD_SOCIAL_LOCAL_ERRORCODE_WEIXIN_ERROR              1005
//未安装QQ客户端
#define BD_SOCIAL_LOCAL_ERRORCODE_QQ_NOTINSTALL             1006
//QQ版本过低
#define BD_SOCIAL_LOCAL_ERRORCODE_QQ_VERSION_LOW            1007
//QQ分享错误
#define BD_SOCIAL_LOCAL_ERRORCODE_QQ_ERROR                  1008
//发送短信错误
#define BD_SOCIAL_LOCAL_ERRORCODE_SEND_MESSAGE_FAIL         1009
//发送邮件错误
#define BD_SOCIAL_LOCAL_ERRORCODE_SEND_EMAIL_FAIL           1010
//其他百度hi错误
#define BD_SOCIAL_LOCAL_ERRORCODE_HI_ERROR                  1011
//未安装百度hi客户端
#define BD_SOCIAL_LOCAL_ERRORCODE_HI_NOTINSTALL             1012


/**
 *	@brief	请求回调事件处理
 *
 *  @param  requestResult   回调结果状态
 *  @param  platformType    分享平台类型
 *  @param  response        API请求返回的数据
 *  @param  error           请求失败的错误信息
 */
typedef void(^BDSocialEventHandler) (BD_SOCIAL_RESULT requestResult,NSString *platformType,id response,NSError *error);

