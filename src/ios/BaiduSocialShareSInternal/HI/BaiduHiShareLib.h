//
//  BaiduHiShareLib.h
//  BaiduHiShareLib
//
//  Created by shuilin on 7/9/14.
//  Copyright (c) 2014 shuilin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaiduHiBean.h"

/*
 结果回调
 */
@protocol BaiduHiShareLibResult <NSObject>

/*
 分享结果通知
 */
- (void)didShareResult:(BaiduHiResponse*)response;

@end


@interface BaiduHiShareLib : NSObject

/*
 注册
 */
+ (void)registerApp:(NSString*)appId;

/*
 调用分享接口
 */
+ (BOOL)shareRequest:(BaiduHiRequest*)request;

/*
 分享程序被唤起时调用
 */
+ (BOOL)handleOpenURL:(NSURL *)url delegate:(id<BaiduHiShareLibResult>)delegate;

/*
 是否可以打开百度Hi，通常用于判断百度Hi是否安装在iOS上
 */
+ (BOOL)canOpenBaiduHi;

/*
 打开百度Hi
 */
+ (BOOL)openBaiduHi;

/*
 百度Hi的在线地址
 */
+ (NSString*)getBaiduHiInstall;

/*
 此分享SDK的版本号
 */
+ (NSString*)getSDKVersion;

@end
