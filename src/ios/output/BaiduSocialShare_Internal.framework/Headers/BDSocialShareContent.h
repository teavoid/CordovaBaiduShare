//
//  Created by Baidu Developer Center on 13-3-10.
//  官网地址:http://developer.baidu.com/soc/share
//  技术支持邮箱:dev_support@baidu.com
//  Copyright (c) 2013年 baidu.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
typedef enum{
    BD_SOCIAL_SHARE_TO_APP_CONTENT_TYPE_WEBPAGE,    //分享内容为网页(适用于直接分享到客户端，如微信，QQ)
    BD_SOCIAL_SHARE_TO_APP_CONTENT_TYPE_IMAGE       //分享内容为图片(适用于直接分享到客户端，如微信，QQ)
} BD_SOCIAL_SHARE_TO_APP_CONTENT_TYPE;

/**
 * BDSocialShareContent是分享的内容类，包括描述、url地址，分享内容的标题，分享附带的图片资源及地理位置信息。
 * BDSocialShareContent提供了方便的接口来生成一个内容类的对象，可以同时设置好描述，url地址，分享内容的标题等信息。BDSocialShareContent还提供了一个添加图片资源的接口。
 * 另外，提供了接口对客户端分享内容的类型进行设置
 */

@interface BDSocialShareContent : NSObject

/** @name 构造分享内容对象 */
/**
 *	@brief	生成分享内容对象,设置基本分享信息
 *	@param 	description         分享的描述
 *	@param 	url                 分享的URL
 *	@param 	title               分享的标题
 */
+(BDSocialShareContent *)shareContentWithDescription:(NSString *)description
                                                 url:(NSString *)url
                                               title:(NSString *)title;

/** @name 添加图片资源 */
/**
 *  @brief	添加网络图片
 *	@param 	thumbImage         图片对应的缩略图。可选参数，组件可通过网络图片构造缩略图
 *	@param 	imageUrl           图片的url地址
 *
 */

-(void)addImageWithThumbImage:(UIImage *)thumbImage imageUrl:(NSString *)imageUrl;

/**
 *  @brief	添加图片对象
 *	@param 	thumbImage         图片对应的缩略图。可选参数，组件可通过图片对象构造缩略图
 *	@param 	imageSource        图片资源对象
 *
 */

-(void)addImageWithThumbImage:(UIImage *)thumbImage imageSource:(UIImage *)imageSource;

/**
 *  @brief	添加图片数据
 *	@param 	thumbImage         图片对应的缩略图。可选参数，组件可通过图片数据构造缩略图
 *	@param 	imageData          图片数据
 *
 */
-(void)addImageWithThumbImage:(UIImage *)thumbImage imageData:(NSData *)imageData;

/** @name 设置其他附属信息 */
/**
 *  @brief	添加地理位置信息
 *	@param 	location         位置信息
 *
 *  定位功能可用的情况下，如果开发者通过此接口传入地理位置信息，分享内容优先使用开发者传入的地理位置信息。如果开发者没有传入地理位置信息，分享内容中默认使用自己缓存的定位信息。
 */

-(void)addLocationInfo:(CLLocation *)location;

/**
 *  @brief	设置分享到客户端的内容的类型
 *	@param 	type         分享类型
 *
 *  分享到客户端，默认的分享类型是网页类型，分享后图片会作为内容的缩略图进行展示。
 *  当分享内容的类型设置为图片类型，分享后图片作为分享内容，可以在客户端会话窗口内展示大图。
 *  如果没有添加图片资源，此方法设置无效，使用默认的网页类型进行分享。
 */
-(void)setShareToAPPContentType:(BD_SOCIAL_SHARE_TO_APP_CONTENT_TYPE)type;

/**
 * @brief 设置轻应用的apikey用来在框环境中设置分享统计使用
 * @param apikey
 *
 * 分享，登录等social api的接口中会使用该项用来统计使用
 *
 */
-(void)addApikey:(NSString *)apikey;

/**
 *
 * @brief 设置用户的bduss用来在框环境中设置分享统计使用
 * @param bduss
 *
 */
-(void)addBduss:(NSString *)bduss;
@end
