//使用其他库
#include<android/bitmap.h>

JNIEXPORT jintArray JNICALL Java_com_example_utils_NativeImageUtils_getImage
  (JNIEnv * env, jclass jclz, jintArray buffer, jint width, jint height){

	jint* source = (*env)->GetIntArrayElements(env, buffer, 0);
	int newsize = width * height;
	//亮度、对比度 这两个参数可以传进来
	float brightness = 0.2f, constrat = 0.2f;
	int bab = (int)(255 * brightness);

	//开始处理
	int a, r, g, b;
	//实际设置的对比度
	int cab = (int)(constrat * 65536) + 1;
	//遍历所有的像素点
	int x = 0, y = 0;
	for(x = 0; x < width; x++){
		for(y = 0; y < height; y++){
			//获得每个像素点的颜色值
			int color = source[y * width + x];
			/*可以看android的源码中的实现
		    a = Color.alpha(color);  a = color >>> 24; 但是c中不支持左移24位
			r = Color.red(color);
			g = Color.green(color);
			b = Color.blue(color);*/
			a = (color >> 24) & 0xFF;
			r = (color >> 16) & 0xFF;
			g = (color >> 8) & 0xFF;
			b = color & 0xFF;
			//美白argb的值都变大
			//美黑argb的值都变小
			int rr = r - bab;
			int gr = g - bab;
			int br = b - bab;

			//边界检测
			r = rr > 255 ? 255 : (rr < 0 ? 0 : rr);
			g = gr > 255 ? 255 : (gr < 0 ? 0 : gr);
			b = br > 255 ? 255 : (br < 0 ? 0 : br);

			//~~对比度变化，255的一半来比较  策略：让比较亮的更加量，让比较暗的更加暗
			//int ri = r - 128;
			//int gi = g - 128;
			//int bi = b - 128;
			int ri = ((r - 128) * cab) >> 16 + 128;  //位移十六位 相当于对比度扩大
			int gi = ((g - 128) * cab) >> 16 + 128;
			int bi = ((b - 128) * cab) >> 16 + 128;

			//边界检测
			r = rr > 255 ? 255 : (rr < 0 ? 0 : rr);
			g = gr > 255 ? 255 : (gr < 0 ? 0 : gr);
			b = br > 255 ? 255 : (br < 0 ? 0 : br);

			//设置图像像素点的调整后的色值
			//result.setPixel(x, y,  Color.argb(a, r, g, b));//参照android的源码
			int newColor = (a << 24) | (r << 16) | (g << 8) | b;
			source[y * width + x] = newColor;   //设置到原先值
		}
	}
	//指针转成jint
	jintArray result = (*env)->NewIntArray(env, newsize);
	(*env)->SetIntArrayRegion(env, result , 0, newsize, source);
	//释放内存
	(*env)->ReleaseIntArrayElements(env, buffer, source, 0);
	return result;
}
