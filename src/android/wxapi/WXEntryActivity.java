package net.qdkf.wxapi;

import com.baidu.frontia.activity.share.FrontiaWeixinShareActivity;

 
public class WXEntryActivity extends FrontiaWeixinShareActivity {
	
	@Override
	protected boolean handleIntent() {
		if (super.handleIntent()) {
			return true;
		} else {
			return false;
		}
	}
}
