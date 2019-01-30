public class Test {

	/**
	 * @param args
	 * @author zouty
	 * @since 2012-12-8
	 */
	public static void main(String[] args) {
		
		//#����ת���ɶ������ַ���
		System.out.println( Integer.toBinaryString(95) );
		System.out.println( Integer.toBinaryString(0X0d) );
		
		//#����ת����16�����ַ���
		System.out.println( Integer.toHexString(46) );
		System.out.println( Integer.toHexString(0X0d) );
		
		//#ʮ�����ơ��˽���ת����ʮ��������
		System.out.println(Integer.parseInt("1100110", 2)); //returns 102
		System.out.println(Integer.parseInt("010", 8)); //�˽���
		System.out.println(Integer.valueOf(0X0d)); //ʵ�����ǵ��õ�����ķ���
		
		//#ʮ�����ơ��˽���ת����byte
		System.out.println(Byte.decode("0X0d"));
		System.out.println(Byte.decode("010")); //�˽���

		byte buf[] = new byte[]{11,-22};
		char[] hexChars = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
		//#�ֽ����顢�����ȣ�ת�����Զ���ʮ�����Ƶ���ĸ
		String hexStr = byteArray2HexStr(buf,hexChars);
		System.out.println(hexStr);
		
		//#�������ת������ʮ�������ַ���ת�����ֽ�����
		hexStrToByte(hexStr,hexChars);
	}

	/**
	 * #�ֽ����顢�����ȣ�ת�����Զ���ʮ�����Ƶ���ĸ
	 */
	private static String byteArray2HexStr(byte buf[],char[] hexChars) {
		StringBuffer strbuf = new StringBuffer(buf.length * 2);
		int len = buf.length;
		for (int i = 0; i < len; i++) {
			//int b = (int) buf[i] & 0xff; //������ת�������� 0xff=1111 1111
			strbuf.append( byte2HEX((int) buf[i] & 0xff,hexChars) );
		}
		return strbuf.toString();
	}
	private static String byte2HEX(int x,char[] hexChars) {
          char [] ob = new char[2];
          ob[0] = hexChars[(x >>> 4) & 0x0f]; //ȡ�ø�4λ�Ķ�����,0X0F = 0000 1111
          ob[1] = hexChars[x & 0x0f]; //ȡ�õ�4λ�Ķ�����
          String s = new String(ob);
          return s;
    }
	
	/**
	 * #�������ת������ʮ�������ַ���ת�����ֽ�����
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
	 * ר���ַ�����Ķ��ֲ����㷨
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
