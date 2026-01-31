package hou.utils;

import cn.hutool.crypto.digest.DigestUtil;

public class MD5Util {
    
	/**
	 * @return 密文
	 */
	// 带秘钥加密
	public static String md5(String text) {
		// 加密后的字符串
		String md5str = DigestUtil.md5Hex(text);
		return md5str;
	}

}
