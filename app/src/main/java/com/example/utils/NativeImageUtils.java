package com.example.utils;

/**
 * c实现的图片处理工具类
 */
public class NativeImageUtils {

	/**
	 * 获得亮度、饱和度都变小的图片
	 * @param buffer
	 * @param width
	 * @param height
	 * @return
	 */
	public static native int[] getImage(int[] buffer, int width, int height);
	
	
	static{
		System.loadLibrary("ndk_pic");
	}
}
