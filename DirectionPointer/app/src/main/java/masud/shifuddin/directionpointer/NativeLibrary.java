package masud.shifuddin.directionpointer;

/**
 * Created by shifuddin on 5/7/2016.
 */
public class NativeLibrary {

    static {
        System.loadLibrary("NativeLibrary");
    }
    public native void fetch_ident(String file_name);
    public native int match_ident(String file_name);
    public native void false_ident(String file_name);
}
