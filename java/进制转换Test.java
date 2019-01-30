public class Test {

	/**
	 * @param args
	 * @author zouty
	 * @since 2012-12-8
	 */
	public static void main(String[] args) {
		
		//#整数转换成二进制字符串
		System.out.println( Integer.toBinaryString(95) );
		System.out.println( Integer.toBinaryString(0X0d) );
		
		//#整数转换成16进制字符串
		System.out.println( Integer.toHexString(46) );
		System.out.println( Integer.toHexString(0X0d) );
		
		//#十六进制、八进制转换成十进制正数
		System.out.println(Integer.parseInt("1100110", 2)); //returns 102
		System.out.println(Integer.parseInt("010", 8)); //八进制
		System.out.println(Integer.valueOf(0X0d)); //实际上是调用的上面的方法
		
		//#十六进制、八进制转换成byte
		System.out.println(Byte.decode("0X0d"));
		System.out.println(Byte.decode("010")); //八进制

		byte buf[] = new byte[]{11,-22};
		char[] hexChars = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
		//#字节数组、整数等，转换成自定义十六进制的字母
		String hexStr = byteArray2HexStr(buf,hexChars);
		System.out.println(hexStr);
		
		//#上面的逆转换，将十六进制字符串转换成字节数组
		hexStrToByte(hexStr,hexChars);
	}

	/**
	 * #字节数组、整数等，转换成自定义十六进制的字母
	 */
	private static String byteArray2HexStr(byte buf[],char[] hexChars) {
		StringBuffer strbuf = new StringBuffer(buf.length * 2);
		int len = buf.length;
		for (int i = 0; i < len; i++) {
			//int b = (int) buf[i] & 0xff; //将负数转换成正数 0xff=1111 1111
			strbuf.append( byte2HEX((int) buf[i] & 0xff,hexChars) );
		}
		return strbuf.toString();
	}
	private static String byte2HEX(int x,char[] hexChars) {
          char [] ob = new char[2];
          ob[0] = hexChars[(x >>> 4) & 0x0f]; //取得高4位的二进制,0X0F = 0000 1111
          ob[1] = hexChars[x & 0x0f]; //取得低4位的二进制
          String s = new String(ob);
          return s;
    }
	
	/**
	 * #上面的逆转换，将十六进制字符串转换成字节数组
	 */
	public static byte[] hexStrToByte(String hex, char[] hexChars) {
		int len = (hex.length() / 2);
		byte[] result = new byte[len];
		char[] achar = hex.toCharArray();
		for (int i = 0; i < len; i++) {
			int pos = i * 2;
			result[i] = (byte) (toByte(achar[pos],hexChars) << 4 | toByte(achar[pos + 1],hexChars));
		}
		return result;
	}
	private static int toByte(char c, char[] hexChars) {
		return (byte) binarySearch(hexChars,c);
	}
	/**
	 * 专用字符数组的二分查找算法
	 */
	private static int binarySearch(char array[], char v)
	{
		int left, right, middle;
		left = -1;
		right = 16;
		while (left + 1 != right) {
			middle = left + (right - left) / 2;
			if (array[middle] < v){
				left = middle;
			} else {
				right = middle;
			}
		}
//		if (right >= 16 || array[right] != v) {
//			right = -1;
//		}
		return right;
	}
	
}
