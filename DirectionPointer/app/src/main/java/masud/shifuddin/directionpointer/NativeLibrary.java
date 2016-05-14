package masud.shifuddin.directionpointer;

/**
 * Created by shifuddin on 5/7/2016.
 */
public class NativeLibrary {

    static {
        System.loadLibrary("NativeLibrary");
    }

    // Fetch current device information
    public native void fetch_ident(String file_name);
    // Match current device information with previously loaded information
    public native int match_ident(String file_name);
    // Load false device information
    public native void false_ident(String file_name);
}
