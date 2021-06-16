package com.dlogic;

public class uFCoder  {
	
    static {
    	try {
    		//System.load("C:/Users/test/Desktop/jni_example/uFCoder_JNI.dll"); // modify absolute path that leads to "uFCoder_JNI.dll" file!   
    		String pwd = System.getProperty("user.dir");
    		System.load(pwd + "\\uFCoder_JNI.dll");
    	} catch (Exception ex) {
    		System.out.println(ex.getLocalizedMessage());
    	}
    }
    
    public native static int ReaderOpen();
    
    public native static int ReaderOpenEx(int reader_type, String port_name, int port_interface, String arg);

    public native static int ReaderReset();

    public native static int ReaderClose();
 
    public native static int GetReaderType( int[] lpulReaderType);

    public native static int GetReaderSerialNumber( int[] lpulSerialNumber);
    
    public native static int GetReaderFirmwareVersion(byte[] version_major, byte[] version_minor);
    
    public native static int GetReaderHardwareVersion(byte[] version_major, byte[] version_minor);
    
    public native static int GetBuildNumber(byte[] build);

    public native static int ReaderStillConnected(int[] connected);
    
    public native static int GreenLedBlinkingTurnOff();

    public native static int ReaderUISignal(byte light_signal_mode, byte beep_signal_mode);
    
    public native static int GetCardIdEx(byte[] lpucSak,  byte[] aucUid, byte[] lpucUidSize);
    
    public native static int GetDlogicCardType(byte[] lpucCardType);
    
    public native static int SetISO14443_4_Mode();
    
    public native static int s_block_deselect(byte timeout);
    
    public native static int EMV_GetPAN(String df_name, byte[] pan);
    
    public native static String UFR_Status2String(int status);
    
}