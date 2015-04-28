
#import "Baidushare.h"
#import <Cordova/CDVPlugin.h>
#import <BaiduSocialShare_Internal/BDSocialShareSDK_Internal.h>
#import <QuartzCore/QuartzCore.h>
@implementation Baidushare


- (void)bdshare:(CDVInvokedUrlCommand *)command{
    
        
    NSString* title = [command.arguments objectAtIndex:0];
    NSString* fxcontent = [command.arguments objectAtIndex:1];
    NSString* url = [command.arguments objectAtIndex:2];
    NSString* imageurl = [command.arguments objectAtIndex:3];
    
    NSArray *platforms = [NSArray arrayWithObjects:kBD_SOCIAL_SHARE_PLATFORM_SINAWEIBO,kBD_SOCIAL_SHARE_PLATFORM_QQWEIBO,kBD_SOCIAL_SHARE_PLATFORM_RENREN,kBD_SOCIAL_SHARE_PLATFORM_QQZONE,kBD_SOCIAL_SHARE_PLATFORM_KAIXIN,kBD_SOCIAL_SHARE_PLATFORM_QQFRIEND,kBD_SOCIAL_SHARE_PLATFORM_WEIXIN_SESSION,kBD_SOCIAL_SHARE_PLATFORM_WEIXIN_TIMELINE,kBD_SOCIAL_SHARE_PLATFORM_SMS,kBD_SOCIAL_SHARE_PLATFORM_EMAIL,kBD_SOCIAL_SHARE_PLATFORM_COPY,nil];
     //初始化分享组件
   [BDSocialShareSDK_Internal registerApiKey:@"NxtcfDZ09zZuCdI2Px2FoUWl" supportSharePlatforms:platforms];
// [BDSocialShareSDK_Internal registerSinaWeiboApp:@"319137445"]; //sina登陆
    [BDSocialShareSDK_Internal registerQQApp:@"100358052" enableSSO:NO]; // qq登陆
    
    [BDSocialShareSDK_Internal setAnimationTime:0.25f];
    
    [BDSocialShareSDK_Internal registerWXApp:@"wx712df8473f2a1dbe"]; //微信登陆
    
    //定义分享的ui界面主题
     BD_SOCIAL_SHARE_MENU_STYLE style = BD_SOCIAL_SHARE_MENU_STYLE_LIGHT_COLOR; // 亮色
    // BD_SOCIAL_SHARE_MENU_STYLE style = BD_SOCIAL_SHARE_MENU_STYLE_DARK_COLOR; // 暗色
    //BD_SOCIAL_SHARE_MENU_STYLE style = BD_SOCIAL_SHARE_MENU_STYLE_NIGHT_MODE; // 夜间模式
      [BDSocialShareTheme setShareMenuStyle:style];
    
    BDSocialEventHandler result = ^(BD_SOCIAL_RESULT requestResult, NSString *shareType, id response, NSError *error)
    {
        CDVPluginResult* pluginResult = nil;


        if (requestResult == BD_SOCIAL_SUCCESS) {
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"分享成功" message:[NSString stringWithFormat:@"%@分享成功",shareType] delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:nil];
            [alert show];
            [alert release];
            
             NSLog(@"%@分享成功",shareType);
             pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"1"];
            
        } else if (requestResult == BD_SOCIAL_CANCEL){
             NSLog(@"分享取消");
             pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"2"];
            
        } else if (requestResult == BD_SOCIAL_FAIL){
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"分享失败" message:[NSString stringWithFormat:@"%@分享失败\n error code:%ld;\n error message:%@",shareType,(long)error.code,[error localizedDescription]] delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:nil];
            [alert show];
            [alert release];
            NSLog(@"%@分享失败\n error code:%ld;\n error message:%@",shareType,(long)error.code,[error localizedDescription]);
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"3"];
        }
        
          [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    };
    
    
    
     BDSocialShareContent *content = [BDSocialShareContent shareContentWithDescription:fxcontent url:url title:title];
     [content addImageWithThumbImage:nil imageUrl:imageurl];
    
    [BDSocialShareSDK_Internal showShareMenuWithShareContent:content displayPlatforms:platforms hideMultiShare:NO  supportedInterfaceOrientations:UIInterfaceOrientationMaskAllButUpsideDown isStatusBarHidden:NO targetViewForPad:nil uiDelegate:self result:result];
         
}

 



@end
 
