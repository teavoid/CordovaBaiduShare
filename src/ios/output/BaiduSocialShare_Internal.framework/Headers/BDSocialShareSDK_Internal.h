//
//  Created by Baidu Developer Center on 13-3-10.
//  官网地址:http://developer.baidu.com/soc/share
//  技术支持邮箱:dev_support@baidu.com
//  Copyright (c) 2013年 baidu.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BDSocialShareMacroDef.h"
#import "BDSocialEventHandler.h"
#import "BDSocialShareContent.h"
#import "BDSocialShareTheme.h"
#import "BDSocialUIDelegate.h"

/**
 * BDSocialShareSDK_Internal是百度社会化分享组件的主要功能类，提供了第三方平台授权信息管理、分享、获取用户信息等接口，分享平台包括新浪微博，腾讯微博，QQ空间，人人网，开心网，QQ好友，微信，短信、邮件和贴吧等。
 * 另外，BDSocialShareSDK_Internal还提供了功能完整的UI接口，将选择分享平台，分享内容编辑和发送分享功能相关页面封装在一起，提供给开发者使用。为了使得分享UI与开发者的应用风格保持一直，可以通过BDSocialShareTheme中的UI定制接口，对这些页面进行样式的定制，实现非常简便。
 */

@interface BDSocialShareSDK_Internal : NSObject

/** @name 初始化&销毁 */
/**
 *	@brief	注册应用,此方法在应用启动时调用一次
 *
 *	@param 	apiKey          应用Key
 *	@param 	platforms       支持的分享平台列表
 */
+ (void)registerApiKey:(NSString *)apiKey supportSharePlatforms:(NSArray *)platforms;

/**
 *	@brief	使用微信功能必须先注册微信的应用ID，此方法在应用启动时调用一次
 *
 *	@param 	appid      微信应用的id
 */
+ (void)registerWXApp:(NSString *)appId;

/**
 *	@brief	使用新浪微博客户端的SSO功能，需要调用此方法注册新浪微博的应用ID
 *
 *	@param 	appid      新浪微博应用的id
 */
+ (void)registerSinaWeiboApp:(NSString *)appId;

/**
 *	@brief	使用QQ客户端的SSO功能和QQ好友分享功能，需要调用此方法注册QQ的应用ID
 *
 *	@param 	appid      QQ应用的id
 *	@param 	enableSSO  条件满足的情况下，优先启用SSO授权
 */
+ (void)registerQQApp:(NSString *)appId enableSSO:(BOOL)enableSSO;

/**
 *	@brief	当百度账号的登录状态发生变更后，调用此方法更新第三方平台关联账号的授权状态
 *  @discussion 当百度账号登录成功，传入BDUSS，完成第三方平台关联账号的授权；当百度账号退出登录，传入nil，清空第三方平台关联账号的授权信息
 *
 *	@param 	Bduss           百度BDUSS
 */
+ (void)loginStatusChangedWithBduss:(NSString *)Bduss result:(BDSocialEventHandler)result;

/**
 *	@brief 释放分享组件使用的内存资源
 */
+(void)destroy;

/** @name 授权信息管理 */
/**
 *	@brief	返回授权信息是否有效
 *  @discussion 支持的分享平台标识包括：
 *  kBD_SOCIAL_SHARE_PLATFORM_SINAWEIBO
 *  kBD_SOCIAL_SHARE_PLATFORM_QQZONE
 *  kBD_SOCIAL_SHARE_PLATFORM_KAIXIN
 *  kBD_SOCIAL_SHARE_PLATFORM_QQWEIBO
 *  kBD_SOCIAL_SHARE_PLATFORM_RENREN
 *  分享平台标识可以参看BDSocialShareMacroDef.h文件中的定义。
 *
 *	@param 	shareType   分享平台类型
 *  @return 如果AccessToken是有效的返回YES,否则返回NO.
 */
+ (BOOL)isAccessTokenValidWithShareType:(NSString *)shareType;

/**
 *	@brief	清除单个平台授权信息
 *
 *	@param 	shareType   分享平台类型
 */
+ (void)clearAuthorizeWithShareType:(NSString *)shareType;

/**
 *	@brief	清楚所有账户授权信息
 *
 */
+ (void)clearAllAuthorize;

/**
 *	@brief	显示授权页面
 *  @discussion 支持的分享平台标识包括：
 *  kBD_SOCIAL_SHARE_PLATFORM_SINAWEIBO
 *  kBD_SOCIAL_SHARE_PLATFORM_QQZONE
 *  kBD_SOCIAL_SHARE_PLATFORM_KAIXIN
 *  kBD_SOCIAL_SHARE_PLATFORM_QQWEIBO
 *  kBD_SOCIAL_SHARE_PLATFORM_RENREN
 *  分享平台标识可以参看BDSocialShareMacroDef.h文件中的定义。
 *  orientations参数的赋值请参照枚举值UIInterfaceOrientationMask的定义。
 *
 *	@param 	shareType       分享平台类型
 *	@param 	orientations    分享组件UI界面所支持的屏幕旋转方向
 *	@param 	isHidden        控制隐藏状态栏(iOS6及以下系统设置无效)
 *	@param 	uiDelegate      分享UI的Delegate
 *  @param  lightApiKey     传入授权轻应用的APiKey统计使用
 *  @param  bduss           传入用户的bduss统计使用
 *	@param 	result          授权返回事件处理
 */
+ (void)authorizeWithShareType:(NSString *)shareType
supportedInterfaceOrientations:(NSInteger)orientations
             isStatusBarHidden:(BOOL)isHidden
                    uiDelegate:(id<BDSocialUIDelegate>)uiDelegate
                   lightApiKey:(NSString *)lightApiKey
                         bduss:(NSString *)bduss
                        result:(BDSocialEventHandler)result;

/**
 *	@brief	分享接口
 *  @discussion 支持的分享平台标识包括：
 *  kBD_SOCIAL_SHARE_PLATFORM_SINAWEIBO
 *  kBD_SOCIAL_SHARE_PLATFORM_QQZONE
 *  kBD_SOCIAL_SHARE_PLATFORM_KAIXIN
 *  kBD_SOCIAL_SHARE_PLATFORM_QQWEIBO
 *  kBD_SOCIAL_SHARE_PLATFORM_RENREN
 *  kBD_SOCIAL_SHARE_PLATFORM_QQFRIEND
 *  kBD_SOCIAL_SHARE_PLATFORM_WEIXIN_SESSION
 *  kBD_SOCIAL_SHARE_PLATFORM_WEIXIN_TIMELINE
 *  kBD_SOCIAL_SHARE_PLATFORM_EMAIL
 *  kBD_SOCIAL_SHARE_PLATFORM_SMS
 *  分享平台标识可以参看BDSocialShareMacroDef.h文件中的定义。
 *  orientations参数的赋值请参照枚举值UIInterfaceOrientationMask的定义。
 *
 *	@param 	shareType       分享平台类型
 *	@param 	content         分享内容
 *	@param 	orientations    分享组件UI界面所支持的屏幕旋转方向
 *	@param 	isHidden        控制隐藏状态栏(iOS6及以下系统设置无效)
 *	@param 	uiDelegate      分享UI的Delegate
 *	@param 	result          分享返回事件处理
 */
+ (void)shareWithShareType:(NSString *)shareType
                   content:(BDSocialShareContent*)content
supportedInterfaceOrientations:(NSInteger)orientations
         isStatusBarHidden:(BOOL)isHidden
                uiDelegate:(id<BDSocialUIDelegate>)uiDelegate
                    result:(BDSocialEventHandler)result;

/**
 *	@brief	第三方平台批量分享接口
 *  @discussion 支持的分享平台标识包括：
 *  kBD_SOCIAL_SHARE_PLATFORM_SINAWEIBO
 *  kBD_SOCIAL_SHARE_PLATFORM_KAIXIN
 *  kBD_SOCIAL_SHARE_PLATFORM_QQWEIBO
 *  kBD_SOCIAL_SHARE_PLATFORM_RENREN
 *  分享平台标识可以参看BDSocialShareMacroDef.h文件中的定义。
 *
 *	@param 	shareTypes  分享平台列表
 *	@param 	content     分享内容
 *	@param 	result      分享返回事件处理
 */
+ (void)shareToCommunitiesWithShareTypes:(NSArray *)shareTypes content:(BDSocialShareContent*)content result:(BDSocialEventHandler)result;

/** @name 获取用户信息API接口 */
/**
 *	@brief	取得用户信息
 *  @discussion 支持的分享平台标识包括：
 *  kBD_SOCIAL_SHARE_PLATFORM_SINAWEIBO
 *  kBD_SOCIAL_SHARE_PLATFORM_QQZONE
 *  kBD_SOCIAL_SHARE_PLATFORM_KAIXIN
 *  kBD_SOCIAL_SHARE_PLATFORM_QQWEIBO
 *  kBD_SOCIAL_SHARE_PLATFORM_RENREN
 *  分享平台标识可以参看BDSocialShareMacroDef.h文件中的定义。
 *
 *	@param 	shareType   分享平台类型
 *	@param 	result      取得用户信息返回事件处理
 */
+ (void)getUserInfoWithShareType:(NSString *)shareType result:(BDSocialEventHandler)result;

/**
 *	@brief	显示分享平台菜单
 *  @discussion orientations参数的赋值请参照枚举值UIInterfaceOrientationMask的定义。
 *
 *	@param 	content             分享内容
 *	@param 	platforms           菜单上显示的分享平台列表
 *	@param 	isHideMultiShare    隐藏一键分享
 *	@param 	orientations        分享组件UI界面所支持的屏幕旋转方向
 *	@param 	isHidden            控制隐藏状态栏(iOS6及以下系统设置无效)
 *	@param 	targetView          分享菜单气泡窗口指向的view。此参数仅在iPad设备上设置有效，iPhone设备上会忽略这个参数。如果在iPad设备上传入nil，将采用浮层方式弹出分享菜单
 *	@param 	uiDelegate      分享UI的Delegate
 *	@param 	result          取得用户信息返回事件处理
 */
+ (void)showShareMenuWithShareContent:(BDSocialShareContent *)content
                     displayPlatforms:(NSArray *)platforms
                       hideMultiShare:(BOOL)isHideMultiShare
       supportedInterfaceOrientations:(NSInteger)orientations
                    isStatusBarHidden:(BOOL)isHidden
                     targetViewForPad:(UIView *)targetView
                           uiDelegate:(id<BDSocialUIDelegate>)uiDelegate
                               result:(BDSocialEventHandler)result;

/**
 *	@brief	显示分享编辑页面
 *  @discussion 支持的分享平台标识包括：
 *  kBD_SOCIAL_SHARE_PLATFORM_SINAWEIBO
 *  kBD_SOCIAL_SHARE_PLATFORM_KAIXIN
 *  kBD_SOCIAL_SHARE_PLATFORM_QQWEIBO
 *  kBD_SOCIAL_SHARE_PLATFORM_RENREN
 *  分享平台标识可以参看BDSocialShareMacroDef.h文件中的定义。
 *  orientations参数的赋值请参照枚举值UIInterfaceOrientationMask的定义。
 *
 *	@param 	shareType       分享平台类型
 *	@param 	content         分享内容
 *	@param 	orientations    分享组件UI界面所支持的屏幕旋转方向
 *	@param 	isHidden        控制隐藏状态栏(iOS6及以下系统设置无效)
 *	@param 	uiDelegate      分享UI的Delegate
 *	@param 	result          分享返回事件处理
 */
+ (void)showEditViewWithShareType:(NSString *)shareType
                     shareContent:(BDSocialShareContent *)content
   supportedInterfaceOrientations:(NSInteger)orientations
                isStatusBarHidden:(BOOL)isHidden
                       uiDelegate:(id<BDSocialUIDelegate>)uiDelegate
                           result:(BDSocialEventHandler)result;

/**
 *	@brief	关闭分享页面
 *
 */
+ (void)closeShareViewController;

/** @name 第三方客户端回调处理 */
/**
 *	@brief 处理第三方客户端通过URL启动App时传递的数据
 *
 *	@param 	url         启动App的URL
 */
+(BOOL)handleOpenURL:(NSURL *)url;

/** @name 动画时间接口 */
/**
 *	@brief	设置UI页面切换动画时间
 *
 *	@param 	time     时间
 */
+ (void)setAnimationTime:(CGFloat)time;


@end
