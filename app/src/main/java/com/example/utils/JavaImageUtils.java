package com.example.utils;

import android.graphics.Bitmap;
import android.graphics.Bitmap.Config;
import android.graphics.Color;



/**
 * java图片处理
 */
public class JavaImageUtils {

	/**
	 * 提升的亮度，对比度
	 */
	public static float mBrightness = 0.2f, mConstract = 0.2f;
	
	public static Bitmap getImage(Bitmap bitmap){
		
		Bitmap result = null;
		if(bitmap != null){
			int width = bitmap.getWidth();
			int height = bitmap.getHeight();
			//创建一个白纸
			result = Bitmap.createBitmap(width, height, Config.ARGB_4444);
			//开始处理
			int a, r, g, b;
			//亮度
			int brightness = (int)(255 * mBrightness);
			//对比度变成了1.2倍
			float constractRate = 1.0f +  mConstract;
			//实际设置的对比度
			int cab = (int)(constractRate * 65536) + 1;
			//遍历所有的像素点
			for(int x = 0; x < width; x++){
				for(int y = 0; y < height; y++){
					//获得每个像素点的颜色值
					int color = bitmap.getPixel(x, y);
					a = Color.alpha(color);
					r = Color.red(color);
					g = Color.green(color);
					b = Color.blue(color);
					
					//美白argb的值都变大 
					
					//美黑argb的值都变小
					int rr = r - brightness;
					int gr = g - brightness;
					int br = b - brightness;
					
					//边界检测
					r = rr > 255 ? 255 : (rr < 0 ? 0 : rr);
					g = gr > 255 ? 255 : (gr < 0 ? 0 : gr);
					b = br > 255 ? 255 : (br < 0 ? 0 : br);
					
					//~~对比度变化，255的一半来比较  策略：让比较亮的更加量，让比较暗的更加暗
					int ri = r - 128;
					int gi = g - 128;
					int bi = b - 128;
					ri = (ri * cab) >> 16 + 128;  //位移十六位 相当于对比度扩大
					gi = (gi * cab) >> 16 + 128;
					bi = (bi * cab) >> 16 + 128;
					
					//边界检测
					r = rr > 255 ? 255 : (rr < 0 ? 0 : rr);
					g = gr > 255 ? 255 : (gr < 0 ? 0 : gr);
					b = br > 255 ? 255 : (br < 0 ? 0 : br);
					result.setPixel(x, y,  Color.argb(a, r, g, b));
				}
			}
		}
		return result;
	}
	
	
}
