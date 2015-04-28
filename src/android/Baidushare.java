package net.qdkf.Baidushare;

import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import com.baidu.frontia.Frontia;
import com.baidu.frontia.api.FrontiaAuthorization.MediaType;
import com.baidu.frontia.api.FrontiaSocialShare;
import com.baidu.frontia.api.FrontiaSocialShare.FrontiaTheme;
import com.baidu.frontia.api.FrontiaSocialShareContent;
import com.baidu.frontia.api.FrontiaSocialShareListener;

import android.net.Uri;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

/**
 * This class echoes a string called from JavaScript.
 */
public class Baidushare extends CordovaPlugin {

    private static final String bdshare = "bdshare";

    private static final String TITLE = "title";
    private static final String CONTENT = "content";
    private static final String URL = "url";
    private static final String IMAGE = "imageurl";

    public final static String APIKEY = "dHwDe5TTTtFEv4MOgoeTGLvX"; //百度注册的获取的appkey
	//sina的key
	public final static String SINA_APP_KEY = "319137445";
	//QZONE的key
	public final static String QZONE_APP_KEY = "100358052";
	//qq的key
	 public final static String QQFRIEND_APP_KEY = "100358052";
	//qq分享后的返回的app名字
	public final static String QQFRIEND = "百度";

	//微信分享key
	public final static String WX_APP_KEY = "wx5fc9c1c77ac86e7a";


	final Handler handler = new Handler(Looper.getMainLooper());


    public String callback;

    /**  * Constructor.*/
    private FrontiaSocialShare mSocialShare;

	private FrontiaSocialShareContent mImageContent = new FrontiaSocialShareContent();

    @Override
	public boolean execute(String action, JSONArray args, final CallbackContext callbackContext) {

        if (action.equals(bdshare)) {

        	 JSONObject sharect = args.optJSONObject(0);
        	 String title = sharect.optString(TITLE);
	  		 String content = sharect.optString(CONTENT);
	  		 String url = sharect.optString(URL);
	  		 String imageurl = sharect.optString(IMAGE);

	  		Frontia.init(this.cordova.getActivity().getApplicationContext(),APIKEY);
	  		mSocialShare = Frontia.getSocialShare();
			mSocialShare.setContext(this.cordova.getActivity());
			mSocialShare.setClientId(MediaType.SINAWEIBO.toString(), SINA_APP_KEY);
			mSocialShare.setClientId(MediaType.QZONE.toString(), QZONE_APP_KEY);
			mSocialShare.setClientId(MediaType.QQFRIEND.toString(), QQFRIEND_APP_KEY);
			mSocialShare.setClientName(MediaType.QQFRIEND.toString(), QQFRIEND);
			mSocialShare.setClientId(MediaType.WEIXIN.toString(), WX_APP_KEY);
			mImageContent.setTitle(title);
			mImageContent.setContent(content);
			mImageContent.setLinkUrl(url);
			mImageContent.setImageUri(Uri.parse(imageurl));


	  		this.cordova.getActivity().runOnUiThread(new Runnable()
	        {
	            @Override
				public void run()
	            {

	           mSocialShare.show(cordova.getActivity().getWindow().getDecorView(), mImageContent,
	        		   FrontiaTheme.LIGHT,  new ShareListener (){


				    	   @Override
				   		public void onSuccess() {
				   			Log.d("Test","share success");
				   			Toast.makeText(cordova.getActivity(), "分享成功！",
									Toast.LENGTH_SHORT).show();
							 callbackContext.success("1");
				   		}

				   		@Override
				   		public void onFailure(int errCode, String errMsg) {
				   			Log.d("Test","share errCode "+errCode);

				   			Toast.makeText(cordova.getActivity(),
				   					errMsg.toString(),
				   					Toast.LENGTH_SHORT).show();
				   			    callbackContext.error(errMsg.toString());
				   		}

				   		@Override
				   		public void onCancel() {
				   			Log.d("Test","cancel ");
				   			Toast.makeText(cordova.getActivity(), "分享取消！",
									Toast.LENGTH_SHORT).show();
							   callbackContext.success("2");
				   		}


	       });

             }

         });



        }else {
        	callbackContext.error("Invalid Action");
            return false;
        }

        return true;
    }


    private class ShareListener implements FrontiaSocialShareListener {

		@Override
		public void onSuccess() {
			Log.d("Test","share success");
		}

		@Override
		public void onFailure(int errCode, String errMsg) {
			Log.d("Test","share errCode "+errCode);

		}

		@Override
		public void onCancel() {
			Log.d("Test","cancel ");
		}

	}
}
