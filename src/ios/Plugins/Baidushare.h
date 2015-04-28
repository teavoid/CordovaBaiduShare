//
//  baidumap.h
//  pgtest
//
//  Created by breadth on 13-6-27.
//
//

#import <Foundation/Foundation.h>
#import <Cordova/CDVPlugin.h>
#import <BaiduSocialShare_Internal/BDSocialShareSDK_Internal.h>
#import <UIKit/UIKit.h>

@interface Baidushare : CDVPlugin <BDSocialUIDelegate>

 
// Instance Method

  - (void)bdshare:(CDVInvokedUrlCommand*)command;
 
@end
