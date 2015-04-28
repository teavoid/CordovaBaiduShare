//
//  Created by Baidu Developer Center on 13-3-10.
//  官网地址:http://developer.baidu.com/soc/share
//  技术支持邮箱:dev_support@baidu.com
//  Copyright (c) 2013年 baidu.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * BDSocialShareTheme是分享UI的主题类，可以通过它生成属于自己应用风格的主题。
 */

typedef enum{
    BD_SOCIAL_SHARE_MENU_STYLE_LIGHT_COLOR,
    BD_SOCIAL_SHARE_MENU_STYLE_DARK_COLOR,
    BD_SOCIAL_SHARE_MENU_STYLE_NIGHT_MODE
}BD_SOCIAL_SHARE_MENU_STYLE;

@interface BDSocialShareTheme : NSObject

/** @name Header */
/**
 *	@brief	设置Header的主题风格
 *
 *	@param 	backgroundImage     header的背景颜色
 *	@param 	headerTitleColor    header上标题的文本颜色
 *	@param 	buttonImage         header上Button的背景图片
 *  @param 	buttonTitleColor    header上Button的字体颜色
 */
+(void)setHeaderThemeWithBackgroundColor:(UIColor *)backgroundColor
                        headerTitleColor:(UIColor *)headerTitleColor
                             buttonImage:(UIImage *)buttonImage
                        buttonTitleColor:(UIColor *)buttonTitleColor;

/** @name 授权页面 */
/**
 *	@brief	设置授权页面的主题
 *
 *	@param 	goBackImage          授权页面返回button的图片
 */
+(void)setAuthorizeViewThemeWithGoBackImage:(UIImage *)goBackImage;

/** @name 分享菜单页面 */
/**
 *	@brief	设置分享菜单样式
 *
 *	@param 	menuStyle            分享菜单页面的样式
 */
+(void)setShareMenuStyle:(BD_SOCIAL_SHARE_MENU_STYLE)menuStyle;

/**
 *	@brief	设置浮层边角是否是圆角（适用于iPad设备）
 *
 *	@param 	isRoundCorner     是否是圆角
 */
+(void)setLayerRoundCorner:(BOOL)isRoundCorner;

/**
 *	@brief	设置状态栏样式（适用于iOS7）
 *
 *	@param 	style   状态栏样式
 */
+(void)setStatusBarStyle:(UIStatusBarStyle)style;

/**
 *	@brief	设置分享页面下层遮罩透明度
 *
 *	@param 	menuStyle            分享菜单页面的样式
 */
+(void)setShadeLayerAlpha:(CGFloat)alpha;

/** @name 所有页面主题 */
/**
 *	@brief	回复默认主题
 */
+ (void)buildDefaultTheme;

@end
