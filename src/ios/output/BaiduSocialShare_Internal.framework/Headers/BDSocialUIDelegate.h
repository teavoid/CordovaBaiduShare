//
//  BDSocialUIDelegate.h
//  BaiduSocialLoginSDK
//
//  Created by 夏文海 on 14-2-21.
//  Copyright (c) 2014年 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *	@brief	分享视图类型
 */
typedef enum{
    BD_SOCIAL_VIEW_AUTH,            //登录授权视图
    BD_SOCIAL_VIEW_SHAREMENU,       //分享菜单视图
    BD_SOCIAL_VIEW_EDIT,            //多平台分享编辑视图
    BD_SOCIAL_VIEW_SMS,             //短信发送视图
    BD_SOCIAL_VIEW_EMAIL,           //邮件发送视图
}BD_SOCIAL_VIEW_TYPE;


/**
 *	@brief	分享UI展示过程的Delegate
 */
@protocol BDSocialUIDelegate <NSObject>

@optional

/**
 *	@brief	将要展示分享视图
 *
 *	@param 	viewType       分享视图的类型
 */
- (void)socialUIWillShow:(BD_SOCIAL_VIEW_TYPE)viewType;

/**
 *	@brief	将要关闭分享视图
 *
 *	@param 	viewType       分享视图的类型
 */
- (void)socialUIWillClose:(BD_SOCIAL_VIEW_TYPE)viewType;

/**
 *	@brief	分享视图展示完成
 *
 *	@param 	viewType       分享视图的类型
 */
- (void)socialUIDidShow:(BD_SOCIAL_VIEW_TYPE)viewType;

/**
 *	@brief	分享视图关闭完成
 *
 *	@param 	viewType       分享视图的类型
 */
- (void)socialUIDidClose:(BD_SOCIAL_VIEW_TYPE)viewType;

@end
