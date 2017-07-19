public class HelloJNI{
	static {
		//load native library at runtime.
		//in windows, it loads hello.dll
		//in linux, it loads libhello.so
		System.loadLibrary("hello");//it contains sayHello() method's implementation.
		//the library should be included in java's librarypath, in java.library.path)
		//java -Djava.library.path=path_to_lib.
	}

	private native void sayHello();//a native method, means it's implemented in another language.
	private native int add(int a, int b);

	public static void main(String []args){
		new HelloJNI().sayHello();
		System.out.println(new HelloJNI().add(1, 3));
	}
}

