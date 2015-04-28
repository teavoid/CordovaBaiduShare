# 新版百度分享插件

----
##注意需要手动引入对应平台的js。
我这里提供一个 js 异步引入 js 的方法,请自行修改为对应路径

```javascript
function addShareJS(){

    var shareJS = document.createElement("script");
    if($.os.android){
        shareJS.src = "./script/Baidushare_Android.js";
    }
    if($.os.ios){
        shareJS.src = "./script/Baidushare_iOS.js";
    }
    $("head").append(shareJS);
    
}
```


------

##1、添加插件
```cmd
cordova plugin add https://coding.net/por/CordovaBaidushare.git
```
---
##2、Android 端代码修改

`Baidushare.java`文件中的key修改为自己对应申请的key。由于现在各平台都在加强审核。如果不自己申请key的话可能导致无法分享成功

`CordovaApp.java`

import com.baidu.frontia.FrontiaApplication; //引入百度分享类

//在 onCreate 里面

loadUrl(launchUrl);  //之后

//初始化插件
FrontiaApplication. initFrontiaApplication(getApplicationContext());


```java
//完整的CordovaApp.java文件如下
package 包名;

import android.os.Bundle;
import org.apache.cordova.*;

//引入需要的类
import com.baidu.frontia.FrontiaApplication;

public class CordovaApp extends CordovaActivity
{
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        super.init();
        // Set by <content src="index.html" /> in config.xml
        loadUrl(launchUrl);
        
        //初始化分享插件
        FrontiaApplication. initFrontiaApplication(getApplicationContext());
    }
}
```


---
##3、iOS 端代码修改


---
##4、JS调用
```javascript
function shareClick(){
    var title= "分享测试";
    var content = "分享测试";
    var url = "http://www.qdkf.net";
    var imageurl = "http://appicon.coding.io/img/hlb.png";//注意图片连接需要真实有效
    window.plugins.Baidushare.bdshare(title,content,url,imageurl,function(success) {
        if(success == 1){
            alert("分享成功！"); //做业务处理
        }else if(success == 2){
            alert("未分享成功！");//做业务处理
        }else{
            alert("encode success: " + success);
        }
    }, function(fail) {
        alert("encoding failed: " + fail);
    });
}
```
---
###5、微信分享

`微信分享就比较麻烦。最好去微信开放平台看看开发文档，需要做好包名和签名，并提交后审核，只有审核通过的才能分享。而且微信的分享是有限制的所有分享的内容和图片最好是小一些。`

对于微信分享不能成功的需要说明的几个问题：

首先你要创建Android程序的 .keystore 对自己的应用进行签名打包
微信分享需要先通过微信开放平台的开发者注册，
然后提交你的应用进行审核，获取对应的`AppID`和`AppSecret`

然后下载微信提供的签名校验工具
[工具下载地址-->签名生成工具][apk]
[apk]: https://res.wx.qq.com/open/zh_CN/htmledition/res/dev/download/sdk/Gen_Signature_Android221cbf.apk

用我们正式那个签名文件xxx.keystore对程序进行正式的打包，然后安装到手机中，然后再次运行微信那个签名apk工具，将我们的包名输入到里面，重新生成一个MD5的签名，然后到[微信开放平台官网][weixin]
[weixin]:http://open.weixin.qq.com/agreement
，找到你之前等级那个应用，拉到最后，点击修改，将刚刚生成的那个签名输入到里面，然后保存重新提交审核。

**对于微信分享，关键在于微信的签名问题，一定记得获取签名的时候是用正式打包后的apk，安装到手机再来获取微信的签名，这样联机调试虽然不能分享，但打包出来之后就能分享了。**
---
###6、其他URL

百度key 创建 http://developer.baidu.com/console#app/project
微博key http://open.weibo.com/apps/3424906494/info/basic?action=review#req




---

#iOS

###1.配置Target链接参数

选择 Build Settings | Linking | Other Linker Flags, 将该选项的 Debug/Release 键都配置为 -ObjC （一般默认都有这个参数。可以自己确认一下）


###2.添加 依赖的系统框架和系统库如下: （插件已自动导入，无需再手动添加）
MobileCoreServices.framework
SystemConfiguration.framework
QuartzCore.framework
UIKit.framework
Foundation.framework
CoreGraphics.framework
MessageUI.framework
CoreLocation.framework———————-如果不使用组件的定位功能，可以不用添加
CoreTelephony.framework———————如果不使用QQ官方SDK，可以不用添加
libsqlite3.dylib—————————-如果不使用QQ官方SDK，可以不用添加
libstdc++.dylib—————————–如果不使用QQ官方SDK，可以不用添加
libz.dylib———————————-如果不使用QQ官方SDK，可以不用添加

###3.导入 SDK

【先吧 BaiduSocialShareSInternal 和 output 放入对应目录】

把 BaiduSocialShareSInternal 文件夹拖放到项目的根目录下。
把output 文件夹放拖放到项目的class目录下

然后打开 文件夹把文件拖放到 xcode 中

会弹出一个  choose options for adding these files 的窗口

folders radio 二选一中选【第一个 create groups for any added folders】


###4.设置 url types。 具体看截图：

info => URL Types => 点 加号 添加

Identifier 中输入 com.baidu.BaiduSocialShare
URL Schemes 中输入 QQ05FB57A4, NxtcfDZ09zZuCdI2Px2FoUWl, wx712df8473f2a1dbe, tencent100358052, wb319137445

注意吧 URL Schemes 中的 key 替换为自己申请的

其他为空即可

###5.如果 baidushare.m 再 编译的时候报错 ，需要要在Build Phases里修改
 Build Phases => Compile Sources => Baidushare.m => Complier Flags 栏目中填写 -fno-objc-arc


###6. 手动引入 Baidushare_iOS.js 或者用 js 动态插入

###7.在对应位置调用 js
```javascript
function shareClick(){
    var title= "分享测试";
    var content = "分享测试";
    var url = "http://www.qdkf.net";
    var imageurl = "http://appicon.coding.io/img/hlb.png";//注意图片连接需要真实有效
    Baidushare.bdshare(
        function(success) {
            alert("encode success: " + success);
        }, function(fail) {
            alert("encoding failed: " + fail);
        },
        title,
        content,
        url,
        imageurl
    );
}

```
