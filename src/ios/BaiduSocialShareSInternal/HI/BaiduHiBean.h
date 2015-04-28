//
//  BaiduHiBean.h
//  BaiduHiShareLib
//
//  Created by shuilin on 7/9/14.
//  Copyright (c) 2014 shuilin. All rights reserved.
//

#import <Foundation/Foundation.h>


enum  BaiduHiErrorCode
{
    BaiduHiUnknownError      = 0xff,   //未知错误
    
    BaiduHiSuccess           = 0x00,   //分享成功
    BaiduHiShareError        = 0x01,   //分享失败
    BaiduHiShareCancel       = 0x02,   //取消分享
    BaiduHiVerifyError       = 0x03,   //appid校验失败
    BaiduHiVersionLow        = 0x04,   //百度Hi版本比SDK低
    BaiduHiVersionHigh       = 0x05,   //百度Hi版本比SDK高
    BaiduHiRequestError      = 0x06,   //参数错误
};


@interface BaiduHiRequest : NSObject

@end

//分享URL需要的参数
@interface BaiduHiUrlRequest : BaiduHiRequest
@property(retain,nonatomic) NSString* title;//标题（必须），最大512字节
@property(retain,nonatomic) NSString* desc;//描述，最大1024字节
@property(retain,nonatomic) NSString* linkUrl;//连接地址（必须），最大1024字节
@property(retain,nonatomic) NSString* thumbUrl;//缩略图地址，最大1024字节
@property(retain,nonatomic) NSData* thumbData;//缩略图数据，最大32768字节
@end

//结果
@interface BaiduHiResponse : NSObject
@property(retain,nonatomic) NSError* error;//error.code 参见 BaiduHiErrorCode
@property(retain,nonatomic) BaiduHiRequest* request;//与此结果对应的请求
@end


//分享URL的结果
@interface BaiduHiUrlResponse : BaiduHiResponse

@end


//分享图片需要的参数
@interface BaiduHiPictureRequest : BaiduHiRequest
@property(retain,nonatomic) NSString* title;//标题（可选），最大512字节
@property(retain,nonatomic) NSData* imageData;//图片数据，最大10M
@property(retain,nonatomic) NSString* url;//图片网络地址，imageData为空时才有效(imageData和url不能同时为空)
@end


//分享图片的结果
@interface BaiduHiPictureResponse : BaiduHiResponse
@end


