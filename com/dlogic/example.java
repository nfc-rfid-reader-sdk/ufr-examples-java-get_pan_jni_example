package com.dlogic;
public class example {
	
	private static String ByteArrayToString(byte[] ch_array)
	{
	    StringBuilder strB = new StringBuilder();
	    
	    for(int i = 0; i < ch_array.length; i++)
	    {
	        if(ch_array[i] == 0)
	            break;

	        strB.append((char)ch_array[i]);
	    }
	    
	    return strB.toString();
	}

    public static void main(String[] args ) {
    	try {
    		
	    	int status = uFCoder.ReaderOpen();
	    	System.out.println("ReaderOpen():> " + uFCoder.UFR_Status2String(status));
		    if (status == 0) {

		    	status = uFCoder.GreenLedBlinkingTurnOff();
		    	System.out.println("GreenLedBlinkingTurnOff():> " + uFCoder.UFR_Status2String(status));
		    	
		    	int[] serial_number = new int[1];
		    	status = uFCoder.GetReaderSerialNumber(serial_number);
		    	if (status == 0) {
		    		System.out.println("GetReaderSerialNumber():> " + uFCoder.UFR_Status2String(status) + " | serial_number: " + Integer.toString(serial_number[0]));
		    	} else {
		    		System.out.println("GetReaderSerialNumber():> " + uFCoder.UFR_Status2String(status));
		    	}
		    	
		    	int[] reader_type = new int[1];
		    	
		    	status = uFCoder.GetReaderType(reader_type);
		    	if (status == 0) {
		    		System.out.println("GetReaderType():> " + uFCoder.UFR_Status2String(status) + " | reader_type: " + Integer.toHexString(reader_type[0]).toUpperCase());
		    	} else {
		    		System.out.println("GetReaderType():> " + uFCoder.UFR_Status2String(status));
		    	}
		    	
		    	byte[] v_major = new byte[1];
		    	byte[] v_minor = new byte[1];
		    	
		    	status = uFCoder.GetReaderHardwareVersion(v_major, v_minor); 
		    	System.out.println("GetReaderHardwareVersion():> " + uFCoder.UFR_Status2String(status) + " | version_major: " + Byte.toString(v_major[0]) + ", version_minor: " + Byte.toString(v_minor[0]));
		    	status = uFCoder.GetReaderFirmwareVersion(v_major, v_minor);
		    	if (status == 0) {
		    		System.out.println("GetReaderFirmwareVersion():> " + uFCoder.UFR_Status2String(status) + " | version_major: " + Byte.toString(v_major[0]) + ", version_minor: " + Byte.toString(v_minor[0]));
		    	} else {
		    		System.out.println("GetReaderFirmwareVersion():> " + uFCoder.UFR_Status2String(status));
		    	}
		    	
		    	byte[] build = new byte[1];
		    	
		    	status = uFCoder.GetBuildNumber(build);
		    	if (status == 0) {
		    		System.out.println("GetBuildNumber():> " + uFCoder.UFR_Status2String(status) + " | build: " + Byte.toString(build[0]));
		    	} else {
		    		System.out.println("GetBuildNumber():> " + uFCoder.UFR_Status2String(status));
		    	}
		    	int[] connected = new int[1];
		    	//while (System.in.available() == 0) { //remove backslashes here and on the line 105 to enable this debug while loop
		    	status = uFCoder.ReaderStillConnected(connected);
		    	if (status == 0) {
		    		System.out.println("ReaderStillConnected():> " + uFCoder.UFR_Status2String(status) + " | connected: " + Integer.toString(connected[0]));
		    		if (connected[0] == 1) {
		    			//ufr.ReaderUISignal((byte)1, (byte)1);
		    			
		    			byte[] card_type = new byte[1];
		    			status = uFCoder.GetDlogicCardType(card_type);
		    			if (status == 0) {
		    				System.out.println("GetDlogicCardType():> " + uFCoder.UFR_Status2String(status) + " | card_type: 0x" + Integer.toHexString(card_type[0]));
		    				if (card_type[0] == 0x40) {
		    					status = uFCoder.SetISO14443_4_Mode();
						    	System.out.println("SetISO14443_4_Mode():> " + uFCoder.UFR_Status2String(status));
						    	if (status == 0) {
						    		String df_name = "2PAY.SYS.DDF01";	    		
						    		byte[] pan = new byte[128];
							    		
							    	status = uFCoder.EMV_GetPAN(df_name, pan);
							    	if (status == 0) {
							    		String card_nr = ByteArrayToString(pan).replaceAll("....", "$0-");
										card_nr = card_nr.substring(0, card_nr.length()-1);
										System.out.println("EMV_GetPan():> " + uFCoder.UFR_Status2String(status) + " | PAN: " + card_nr);
							    	} else {
							    		System.out.println("EMV_GetPan():> " + uFCoder.UFR_Status2String(status));
							    	}
							    	uFCoder.s_block_deselect((byte)100);
		    				} else {
		    					uFCoder.s_block_deselect((byte)100);
		    				}
					    	}
		    			} else {
		    				System.out.println("GetDlogicCardType():> " + uFCoder.UFR_Status2String(status));
		    			}	
		    		}
		    		
		    	} else {
		    		System.out.println("EMV_GetPan():> " + uFCoder.UFR_Status2String(status));
		    	}
		    	
		    	System.out.println("---------------------------------------");
		    //} // while (System.in.available() == 0) \\ pressing any key while in console will stop this debug loop.
		    }
    	}
    	catch (Exception ex) {
    		System.out.println(ex.getLocalizedMessage());
    	}
    }
}





