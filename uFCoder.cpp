#include <jni.h>
#include <uFCoder.h>
#include <unistd.h>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;
void mySleep(int sleepMs)
{
    usleep(sleepMs * 1000);   // usleep takes sleep time in us (1 millionth of a second)

}

stringstream funcStatus;
jclass ufCoderClass;

extern "C"
{
	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_ReaderOpenEx(JNIEnv *env, jobject instance, jint reader_type, jstring port_name_, jint port_interface, jstring arg_) {
	   

		const char *port_name = env->GetStringUTFChars(port_name_, 0);
		const char *arg = env->GetStringUTFChars(arg_, 0);

		UFR_STATUS status;

		status = ReaderOpenEx(reader_type, port_name, port_interface, (void*)arg);

		if(port_interface == 'L' || port_interface == 'B')
		{
		if(status != UFR_OK)
		{
			usleep(500000);
			status = ReaderOpenEx(reader_type, port_name, port_interface, (void*)arg);
		}

		if(status != UFR_OK)
		{
			usleep(500000);
			status = ReaderOpenEx(reader_type, port_name, port_interface, (void*)arg);
			if(status != UFR_OK)
			{
				usleep(500000);
				status = ReaderOpenEx(reader_type, port_name, port_interface, (void*)arg);
			}

		}
		}
		env->ReleaseStringUTFChars(port_name_, port_name);
		env->ReleaseStringUTFChars(arg_, arg);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_ReaderOpen_1uFROnline(JNIEnv *env, jobject instance, jstring serial_number) {
		UFR_STATUS status;
		

		const char *serial_number_ = env->GetStringUTFChars(serial_number, 0);

		status = ReaderOpen_uFROnline((const char *)serial_number_);

		env->ReleaseStringUTFChars(serial_number, serial_number_);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_ReaderOpen(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = ReaderOpen();

		 return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_ReaderOpenByType(JNIEnv *env, jobject instance, jint reader_type) {
		
		UFR_STATUS status;

		status = ReaderOpenByType((uint32_t)reader_type);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReaderReset(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = ReaderReset();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReaderClose(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = ReaderClose();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReaderSoftRestart(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = ReaderSoftRestart();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReaderHwReset(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = ReaderHwReset();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetReaderType(JNIEnv *env, jobject instance,  jintArray lpulReaderType) {
		
		UFR_STATUS status;

		jint *lpulReaderType_ = env->GetIntArrayElements(lpulReaderType, 0);
		status = GetReaderType((uint32_t *)lpulReaderType_);

		env->ReleaseIntArrayElements(lpulReaderType,lpulReaderType_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetReaderSerialNumber(JNIEnv *env, jobject instance,  jintArray lpulSerialNumber) {
		
		UFR_STATUS status;

		jint *lpulSerialNumber_ = env->GetIntArrayElements(lpulSerialNumber, 0);
		status = GetReaderSerialNumber((uint32_t *)lpulSerialNumber_);

		env->ReleaseIntArrayElements(lpulSerialNumber,lpulSerialNumber_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReaderStillConnected(JNIEnv *env, jobject instance, jintArray connected) {
		
		UFR_STATUS status;

		jint *connected_ = env->GetIntArrayElements(connected, 0);
		status = ReaderStillConnected((uint32_t *)connected_);

		env->ReleaseIntArrayElements(connected,connected_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReaderKeyWrite(JNIEnv *env, jobject instance,  jbyteArray aucKey, jbyte ucKeyIndex) {
		
		UFR_STATUS status;

		jbyte *aucKey_ = env->GetByteArrayElements(aucKey, 0);
		status = ReaderKeyWrite((uint8_t *)aucKey_,(uint8_t)ucKeyIndex);

		env->ReleaseByteArrayElements(aucKey,aucKey_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReaderKeysLock(JNIEnv *env, jobject instance,  jbyteArray password) {
		
		UFR_STATUS status;

		jbyte *password_ = env->GetByteArrayElements(password, 0);
		status = ReaderKeysLock((uint8_t *)password_);

		env->ReleaseByteArrayElements(password,password_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReaderKeysUnlock(JNIEnv *env, jobject instance,  jbyteArray password) {
		
		UFR_STATUS status;

		jbyte *password_ = env->GetByteArrayElements(password, 0);
		status = ReaderKeysUnlock((uint8_t *)password_);

		env->ReleaseByteArrayElements(password,password_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReaderUISignal(JNIEnv *env, jobject instance, jbyte light_signal_mode, jbyte beep_signal_mode) {
		
		UFR_STATUS status;

		status = ReaderUISignal((uint8_t)light_signal_mode,(uint8_t)beep_signal_mode);

		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadUserData(JNIEnv *env, jobject instance,  jbyteArray aucData) {
		
		UFR_STATUS status;

		jbyte *aucData_ = env->GetByteArrayElements(aucData, 0);
		status = ReadUserData((uint8_t *)aucData_);

		env->ReleaseByteArrayElements(aucData,aucData_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteUserData(JNIEnv *env, jobject instance,  jbyteArray aucData) {
		
		UFR_STATUS status;

		jbyte *aucData_ = env->GetByteArrayElements(aucData, 0);
		status = WriteUserData((uint8_t *)aucData_);

		env->ReleaseByteArrayElements(aucData,aucData_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetCardId(JNIEnv *env, jobject instance, jbyteArray lpucCardType,  jintArray lpulCardSerial) {
		
		UFR_STATUS status;

		jbyte *lpucCardType_ = env->GetByteArrayElements(lpucCardType, 0);
		jint *lpulCardSerial_ = env->GetIntArrayElements(lpulCardSerial, 0);
		status = GetCardId((uint8_t *)lpucCardType_,(uint32_t *)lpulCardSerial_);

		env->ReleaseByteArrayElements(lpucCardType,lpucCardType_, 0);
		env->ReleaseIntArrayElements(lpulCardSerial,lpulCardSerial_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BlockRead(JNIEnv *env, jobject instance,  jbyteArray data, jbyte block_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		status = BlockRead((uint8_t *)data_,(uint8_t)block_address,(uint8_t)auth_mode,(uint8_t)key_index);

		env->ReleaseByteArrayElements(data,data_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BlockWrite(JNIEnv *env, jobject instance,  jbyteArray data, jbyte block_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		status = BlockWrite((uint8_t *)data_,(uint8_t)block_address,(uint8_t)auth_mode,(uint8_t)key_index);

		env->ReleaseByteArrayElements(data,data_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BlockInSectorRead(JNIEnv *env, jobject instance,  jbyteArray data, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		status = BlockInSectorRead((uint8_t *)data_,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode,(uint8_t)key_index);

		env->ReleaseByteArrayElements(data,data_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BlockInSectorWrite(JNIEnv *env, jobject instance,  jbyteArray data, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		status = BlockInSectorWrite((uint8_t *)data_,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode,(uint8_t)key_index);

		env->ReleaseByteArrayElements(data,data_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_LinearRead(JNIEnv *env, jobject instance,  jbyteArray aucData, jshort usLinearAddress, jshort usDataLength, jshortArray lpusBytesReturned, jbyte ucKeyMode, jbyte ucReaderKeyIndex) {
		
		UFR_STATUS status;

		jbyte *aucData_ = env->GetByteArrayElements(aucData, 0);
		jshort *lpusBytesReturned_ = env->GetShortArrayElements(lpusBytesReturned, 0);
		status = LinearRead((uint8_t *)aucData_,(uint16_t)usLinearAddress,(uint16_t)usDataLength,(uint16_t *)lpusBytesReturned_,(uint8_t)ucKeyMode,(uint8_t)ucReaderKeyIndex);

		env->ReleaseByteArrayElements(aucData,aucData_, 0);
		env->ReleaseShortArrayElements(lpusBytesReturned,lpusBytesReturned_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_LinRowRead(JNIEnv *env, jobject instance,  jbyteArray aucData, jshort usLinearAddress, jshort usDataLength, jshortArray lpusBytesReturned, jbyte ucKeyMode, jbyte ucReaderKeyIndex) {
		
		UFR_STATUS status;

		jbyte *aucData_ = env->GetByteArrayElements(aucData, 0);
		jshort *lpusBytesReturned_ = env->GetShortArrayElements(lpusBytesReturned, 0);
		status = LinRowRead((uint8_t *)aucData_,(uint16_t)usLinearAddress,(uint16_t)usDataLength,(uint16_t *)lpusBytesReturned_,(uint8_t)ucKeyMode,(uint8_t)ucReaderKeyIndex);

		env->ReleaseByteArrayElements(aucData,aucData_, 0);
		env->ReleaseShortArrayElements(lpusBytesReturned,lpusBytesReturned_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_LinearWrite(JNIEnv *env, jobject instance,  jbyteArray aucData, jshort usLinearAddress, jshort usDataLength, jshortArray lpusBytesWritten, jbyte ucKeyMode, jbyte ucReaderKeyIndex) {
		
		UFR_STATUS status;

		jbyte *aucData_ = env->GetByteArrayElements(aucData, 0);
		jshort *lpusBytesWritten_ = env->GetShortArrayElements(lpusBytesWritten, 0);
		status = LinearWrite((uint8_t *)aucData_,(uint16_t)usLinearAddress,(uint16_t)usDataLength,(uint16_t *)lpusBytesWritten_,(uint8_t)ucKeyMode,(uint8_t)ucReaderKeyIndex);

		env->ReleaseByteArrayElements(aucData,aucData_, 0);
		env->ReleaseShortArrayElements(lpusBytesWritten,lpusBytesWritten_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_LinearFormatCard(JNIEnv *env, jobject instance,  jbyteArray new_key_A, jbyte blocks_access_bits, jbyte sector_trailers_access_bits, jbyte sector_trailers_byte9,  jbyteArray new_key_B, jbyteArray lpucSectorsFormatted, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;

		jbyte *new_key_A_ = env->GetByteArrayElements(new_key_A, 0);
		jbyte *new_key_B_ = env->GetByteArrayElements(new_key_B, 0);
		jbyte *lpucSectorsFormatted_ = env->GetByteArrayElements(lpucSectorsFormatted, 0);
		status = LinearFormatCard((uint8_t *)new_key_A_,(uint8_t)blocks_access_bits,(uint8_t)sector_trailers_access_bits,(uint8_t)sector_trailers_byte9,(uint8_t *)new_key_B_,(uint8_t *)lpucSectorsFormatted_,(uint8_t)auth_mode,(uint8_t)key_index);

		env->ReleaseByteArrayElements(new_key_A,new_key_A_, 0);
		env->ReleaseByteArrayElements(new_key_B,new_key_B_, 0);
		env->ReleaseByteArrayElements(lpucSectorsFormatted,lpucSectorsFormatted_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SectorTrailerWrite(JNIEnv *env, jobject instance, jbyte addressing_mode, jbyte address,  jbyteArray new_key_A, jbyte block0_access_bits, jbyte block1_access_bits, jbyte block2_access_bits, jbyte sector_trailer_access_bits, jbyte sector_trailer_byte9,  jbyteArray new_key_B, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;

		jbyte *new_key_A_ = env->GetByteArrayElements(new_key_A, 0);
		jbyte *new_key_B_ = env->GetByteArrayElements(new_key_B, 0);
		status = SectorTrailerWrite((uint8_t)addressing_mode,(uint8_t)address,(uint8_t *)new_key_A_,(uint8_t)block0_access_bits,(uint8_t)block1_access_bits,(uint8_t)block2_access_bits,(uint8_t)sector_trailer_access_bits,(uint8_t)sector_trailer_byte9,(uint8_t *)new_key_B_,(uint8_t)auth_mode,(uint8_t)key_index);

		env->ReleaseByteArrayElements(new_key_A,new_key_A_, 0);
		env->ReleaseByteArrayElements(new_key_B,new_key_B_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SectorTrailerWriteSamKey(JNIEnv *env, jobject instance, jbyte addressing_mode, jbyte address,  jbyteArray new_key_A, jbyte block0_access_bits, jbyte block1_access_bits, jbyte block2_access_bits, jbyte sector_trailer_access_bits, jbyte sector_trailer_byte9,  jbyteArray new_key_B, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;

		jbyte *new_key_A_ = env->GetByteArrayElements(new_key_A, 0);
		jbyte *new_key_B_ = env->GetByteArrayElements(new_key_B, 0);
		status = SectorTrailerWriteSamKey((uint8_t)addressing_mode,(uint8_t)address,(uint8_t *)new_key_A_,(uint8_t)block0_access_bits,(uint8_t)block1_access_bits,(uint8_t)block2_access_bits,(uint8_t)sector_trailer_access_bits,(uint8_t)sector_trailer_byte9,(uint8_t *)new_key_B_,(uint8_t)auth_mode,(uint8_t)key_index);

		env->ReleaseByteArrayElements(new_key_A,new_key_A_, 0);
		env->ReleaseByteArrayElements(new_key_B,new_key_B_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SectorTrailerWriteUnsafe(JNIEnv *env, jobject instance, jbyte addressing_mode, jbyte address,  jbyteArray sector_trailer, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;

		jbyte *sector_trailer_ = env->GetByteArrayElements(sector_trailer, 0);
		status = SectorTrailerWriteUnsafe((uint8_t)addressing_mode,(uint8_t)address,(uint8_t *)sector_trailer_,(uint8_t)auth_mode,(uint8_t)key_index);

		env->ReleaseByteArrayElements(sector_trailer,sector_trailer_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockRead(JNIEnv *env, jobject instance, jintArray value, jbyteArray value_addr, jbyte block_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;

		jint *value_ = env->GetIntArrayElements(value, 0);
		jbyte *value_addr_ = env->GetByteArrayElements(value_addr, 0);
		status = ValueBlockRead((int32_t *)value_,(uint8_t *)value_addr_,(uint8_t)block_address,(uint8_t)auth_mode,(uint8_t)key_index);

		env->ReleaseIntArrayElements(value,value_, 0);
		env->ReleaseByteArrayElements(value_addr,value_addr_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockInSectorRead(JNIEnv *env, jobject instance, jintArray value, jbyteArray value_addr, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;

		jint *value_ = env->GetIntArrayElements(value, 0);
		jbyte *value_addr_ = env->GetByteArrayElements(value_addr, 0);
		status = ValueBlockInSectorRead((int32_t *)value_,(uint8_t *)value_addr_,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode,(uint8_t)key_index);

		env->ReleaseIntArrayElements(value,value_, 0);
		env->ReleaseByteArrayElements(value_addr,value_addr_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockWrite(JNIEnv *env, jobject instance, jint value, jbyte value_addr, jbyte block_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;

		status = ValueBlockWrite((int32_t)value,(uint8_t)value_addr,(uint8_t)block_address,(uint8_t)auth_mode,(uint8_t)key_index);

		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockInSectorWrite(JNIEnv *env, jobject instance, jint value, jbyte value_addr, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;

		status = ValueBlockInSectorWrite((int32_t)value,(uint8_t)value_addr,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode,(uint8_t)key_index);

		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockIncrement(JNIEnv *env, jobject instance, jint increment_value, jbyte block_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;

		status = ValueBlockIncrement((int32_t)increment_value,(uint8_t)block_address,(uint8_t)auth_mode,(uint8_t)key_index);

		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockInSectorIncrement(JNIEnv *env, jobject instance, jint increment_value, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;

		status = ValueBlockInSectorIncrement((int32_t)increment_value,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode,(uint8_t)key_index);

		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockDecrement(JNIEnv *env, jobject instance, jint decrement_value, jbyte block_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;

		status = ValueBlockDecrement((int32_t)decrement_value,(uint8_t)block_address,(uint8_t)auth_mode,(uint8_t)key_index);

		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockInSectorDecrement(JNIEnv *env, jobject instance, jint decrement_value, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;

		status = ValueBlockInSectorDecrement((int32_t)decrement_value,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode,(uint8_t)key_index);

		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BlockRead_1AKM1(JNIEnv *env, jobject instance,  jbyteArray data, jbyte block_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		status = BlockRead_AKM1((uint8_t *)data_,(uint8_t)block_address,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(data,data_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BlockWrite_1AKM1(JNIEnv *env, jobject instance,  jbyteArray data, jbyte block_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		status = BlockWrite_AKM1((uint8_t *)data_,(uint8_t)block_address,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(data,data_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BlockInSectorRead_1AKM1(JNIEnv *env, jobject instance,  jbyteArray data, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		status = BlockInSectorRead_AKM1((uint8_t *)data_,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(data,data_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BlockInSectorWrite_1AKM1(JNIEnv *env, jobject instance,  jbyteArray data, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		status = BlockInSectorWrite_AKM1((uint8_t *)data_,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(data,data_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_LinearRead_1AKM1(JNIEnv *env, jobject instance,  jbyteArray data, jshort linear_address, jshort length, jshortArray bytes_returned, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *bytes_returned_ = env->GetShortArrayElements(bytes_returned, 0);
		status = LinearRead_AKM1((uint8_t *)data_,(uint16_t)linear_address,(uint16_t)length,(uint16_t *)bytes_returned_,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseShortArrayElements(bytes_returned,bytes_returned_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_LinRowRead_1AKM1(JNIEnv *env, jobject instance,  jbyteArray data, jshort linear_address, jshort length, jshortArray bytes_returned, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *bytes_returned_ = env->GetShortArrayElements(bytes_returned, 0);
		status = LinRowRead_AKM1((uint8_t *)data_,(uint16_t)linear_address,(uint16_t)length,(uint16_t *)bytes_returned_,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseShortArrayElements(bytes_returned,bytes_returned_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_LinearWrite_1AKM1(JNIEnv *env, jobject instance,  jbyteArray data, jshort linear_address, jshort length, jshortArray bytes_written, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *bytes_written_ = env->GetShortArrayElements(bytes_written, 0);
		status = LinearWrite_AKM1((uint8_t *)data_,(uint16_t)linear_address,(uint16_t)length,(uint16_t *)bytes_written_,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseShortArrayElements(bytes_written,bytes_written_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_LinearFormatCard_1AKM1(JNIEnv *env, jobject instance,  jbyteArray new_key_A, jbyte blocks_access_bits, jbyte sector_trailers_access_bits, jbyte sector_trailers_byte9,  jbyteArray new_key_B, jbyteArray lpucSectorsFormatted, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *new_key_A_ = env->GetByteArrayElements(new_key_A, 0);
		jbyte *new_key_B_ = env->GetByteArrayElements(new_key_B, 0);
		jbyte *lpucSectorsFormatted_ = env->GetByteArrayElements(lpucSectorsFormatted, 0);
		status = LinearFormatCard_AKM1((uint8_t *)new_key_A_,(uint8_t)blocks_access_bits,(uint8_t)sector_trailers_access_bits,(uint8_t)sector_trailers_byte9,(uint8_t *)new_key_B_,(uint8_t *)lpucSectorsFormatted_,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(new_key_A,new_key_A_, 0);
		env->ReleaseByteArrayElements(new_key_B,new_key_B_, 0);
		env->ReleaseByteArrayElements(lpucSectorsFormatted,lpucSectorsFormatted_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SectorTrailerWrite_1AKM1(JNIEnv *env, jobject instance, jbyte addressing_mode, jbyte address,  jbyteArray new_key_A, jbyte block0_access_bits, jbyte block1_access_bits, jbyte block2_access_bits, jbyte sector_trailer_access_bits, jbyte sector_trailer_byte9,  jbyteArray new_key_B, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *new_key_A_ = env->GetByteArrayElements(new_key_A, 0);
		jbyte *new_key_B_ = env->GetByteArrayElements(new_key_B, 0);
		status = SectorTrailerWrite_AKM1((uint8_t)addressing_mode,(uint8_t)address,(uint8_t *)new_key_A_,(uint8_t)block0_access_bits,(uint8_t)block1_access_bits,(uint8_t)block2_access_bits,(uint8_t)sector_trailer_access_bits,(uint8_t)sector_trailer_byte9,(uint8_t *)new_key_B_,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(new_key_A,new_key_A_, 0);
		env->ReleaseByteArrayElements(new_key_B,new_key_B_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SectorTrailerWriteUnsafe_1AKM1(JNIEnv *env, jobject instance, jbyte addressing_mode, jbyte address,  jbyteArray sector_trailer, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *sector_trailer_ = env->GetByteArrayElements(sector_trailer, 0);
		status = SectorTrailerWriteUnsafe_AKM1((uint8_t)addressing_mode,(uint8_t)address,(uint8_t *)sector_trailer_,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(sector_trailer,sector_trailer_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockRead_1AKM1(JNIEnv *env, jobject instance, jintArray value, jbyteArray value_addr, jbyte block_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		jint *value_ = env->GetIntArrayElements(value, 0);
		jbyte *value_addr_ = env->GetByteArrayElements(value_addr, 0);
		status = ValueBlockRead_AKM1((int32_t *)value_,(uint8_t *)value_addr_,(uint8_t)block_address,(uint8_t)auth_mode);

		env->ReleaseIntArrayElements(value,value_, 0);
		env->ReleaseByteArrayElements(value_addr,value_addr_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockInSectorRead_1AKM1(JNIEnv *env, jobject instance, jintArray value, jbyteArray value_addr, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		jint *value_ = env->GetIntArrayElements(value, 0);
		jbyte *value_addr_ = env->GetByteArrayElements(value_addr, 0);
		status = ValueBlockInSectorRead_AKM1((int32_t *)value_,(uint8_t *)value_addr_,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode);

		env->ReleaseIntArrayElements(value,value_, 0);
		env->ReleaseByteArrayElements(value_addr,value_addr_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockWrite_1AKM1(JNIEnv *env, jobject instance, jint value, jbyte value_addr, jbyte block_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		status = ValueBlockWrite_AKM1((int32_t)value,(uint8_t)value_addr,(uint8_t)block_address,(uint8_t)auth_mode);

		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockInSectorWrite_1AKM1(JNIEnv *env, jobject instance, jint value, jbyte value_addr, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		status = ValueBlockInSectorWrite_AKM1((int32_t)value,(uint8_t)value_addr,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode);

		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockIncrement_1AKM1(JNIEnv *env, jobject instance, jint increment_value, jbyte block_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		status = ValueBlockIncrement_AKM1((int32_t)increment_value,(uint8_t)block_address,(uint8_t)auth_mode);

		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockInSectorIncrement_1AKM1(JNIEnv *env, jobject instance, jint increment_value, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		status = ValueBlockInSectorIncrement_AKM1((int32_t)increment_value,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode);

		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockDecrement_1AKM1(JNIEnv *env, jobject instance, jint decrement_value, jbyte block_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		status = ValueBlockDecrement_AKM1((int32_t)decrement_value,(uint8_t)block_address,(uint8_t)auth_mode);

		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockInSectorDecrement_1AKM1(JNIEnv *env, jobject instance, jint decrement_value, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		status = ValueBlockInSectorDecrement_AKM1((int32_t)decrement_value,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode);

		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BlockRead_1AKM2(JNIEnv *env, jobject instance,  jbyteArray data, jbyte block_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		status = BlockRead_AKM2((uint8_t *)data_,(uint8_t)block_address,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(data,data_, 0);
		return status;
	}
	
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BlockWrite_1AKM2(JNIEnv *env, jobject instance,  jbyteArray data, jbyte block_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		status = BlockWrite_AKM2((uint8_t *)data_,(uint8_t)block_address,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(data,data_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BlockInSectorRead_1AKM2(JNIEnv *env, jobject instance,  jbyteArray data, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		status = BlockInSectorRead_AKM2((uint8_t *)data_,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(data,data_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BlockInSectorWrite_1AKM2(JNIEnv *env, jobject instance,  jbyteArray data, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		status = BlockInSectorWrite_AKM2((uint8_t *)data_,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(data,data_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_LinearRead_1AKM2(JNIEnv *env, jobject instance,  jbyteArray data, jshort linear_address, jshort length, jshortArray bytes_returned, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *bytes_returned_ = env->GetShortArrayElements(bytes_returned, 0);
		status = LinearRead_AKM2((uint8_t *)data_,(uint16_t)linear_address,(uint16_t)length,(uint16_t *)bytes_returned_,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseShortArrayElements(bytes_returned,bytes_returned_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_LinRowRead_1AKM2(JNIEnv *env, jobject instance,  jbyteArray data, jshort linear_address, jshort length, jshortArray bytes_returned, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *bytes_returned_ = env->GetShortArrayElements(bytes_returned, 0);
		status = LinRowRead_AKM2((uint8_t *)data_,(uint16_t)linear_address,(uint16_t)length,(uint16_t *)bytes_returned_,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseShortArrayElements(bytes_returned,bytes_returned_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_LinearWrite_1AKM2(JNIEnv *env, jobject instance,  jbyteArray data, jshort linear_address, jshort length, jshortArray bytes_written, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *bytes_written_ = env->GetShortArrayElements(bytes_written, 0);
		status = LinearWrite_AKM2((uint8_t *)data_,(uint16_t)linear_address,(uint16_t)length,(uint16_t *)bytes_written_,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseShortArrayElements(bytes_written,bytes_written_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_LinearFormatCard_1AKM2(JNIEnv *env, jobject instance,  jbyteArray new_key_A, jbyte blocks_access_bits, jbyte sector_trailers_access_bits, jbyte sector_trailers_byte9,  jbyteArray new_key_B, jbyteArray lpucSectorsFormatted, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *new_key_A_ = env->GetByteArrayElements(new_key_A, 0);
		jbyte *new_key_B_ = env->GetByteArrayElements(new_key_B, 0);
		jbyte *lpucSectorsFormatted_ = env->GetByteArrayElements(lpucSectorsFormatted, 0);
		status = LinearFormatCard_AKM2((uint8_t *)new_key_A_,(uint8_t)blocks_access_bits,(uint8_t)sector_trailers_access_bits,(uint8_t)sector_trailers_byte9,(uint8_t *)new_key_B_,(uint8_t *)lpucSectorsFormatted_,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(new_key_A,new_key_A_, 0);
		env->ReleaseByteArrayElements(new_key_B,new_key_B_, 0);
		env->ReleaseByteArrayElements(lpucSectorsFormatted,lpucSectorsFormatted_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SectorTrailerWrite_1AKM2(JNIEnv *env, jobject instance, jbyte addressing_mode, jbyte address,  jbyteArray new_key_A, jbyte block0_access_bits, jbyte block1_access_bits, jbyte block2_access_bits, jbyte sector_trailer_access_bits, jbyte sector_trailer_byte9,  jbyteArray new_key_B, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *new_key_A_ = env->GetByteArrayElements(new_key_A, 0);
		jbyte *new_key_B_ = env->GetByteArrayElements(new_key_B, 0);
		status = SectorTrailerWrite_AKM2((uint8_t)addressing_mode,(uint8_t)address,(uint8_t *)new_key_A_,(uint8_t)block0_access_bits,(uint8_t)block1_access_bits,(uint8_t)block2_access_bits,(uint8_t)sector_trailer_access_bits,(uint8_t)sector_trailer_byte9,(uint8_t *)new_key_B_,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(new_key_A,new_key_A_, 0);
		env->ReleaseByteArrayElements(new_key_B,new_key_B_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SectorTrailerWriteUnsafe_1AKM2(JNIEnv *env, jobject instance, jbyte addressing_mode, jbyte address,  jbyteArray sector_trailer, jbyte auth_mode) {
		
		UFR_STATUS status;

		jbyte *sector_trailer_ = env->GetByteArrayElements(sector_trailer, 0);
		status = SectorTrailerWriteUnsafe_AKM2((uint8_t)addressing_mode,(uint8_t)address,(uint8_t *)sector_trailer_,(uint8_t)auth_mode);

		env->ReleaseByteArrayElements(sector_trailer,sector_trailer_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockRead_1AKM2(JNIEnv *env, jobject instance, jintArray value, jbyteArray value_addr, jbyte block_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		jint *value_ = env->GetIntArrayElements(value, 0);
		jbyte *value_addr_ = env->GetByteArrayElements(value_addr, 0);
		status = ValueBlockRead_AKM2((int32_t *)value_,(uint8_t *)value_addr_,(uint8_t)block_address,(uint8_t)auth_mode);

		env->ReleaseIntArrayElements(value,value_, 0);
		env->ReleaseByteArrayElements(value_addr,value_addr_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockInSectorRead_1AKM2(JNIEnv *env, jobject instance, jintArray value, jbyteArray value_addr, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		jint *value_ = env->GetIntArrayElements(value, 0);
		jbyte *value_addr_ = env->GetByteArrayElements(value_addr, 0);
		status = ValueBlockInSectorRead_AKM2((int32_t *)value_,(uint8_t *)value_addr_,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode);

		env->ReleaseIntArrayElements(value,value_, 0);
		env->ReleaseByteArrayElements(value_addr,value_addr_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockWrite_1AKM2(JNIEnv *env, jobject instance, jint value, jbyte value_addr, jbyte block_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		status = ValueBlockWrite_AKM2((int32_t)value,(uint8_t)value_addr,(uint8_t)block_address,(uint8_t)auth_mode);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockInSectorWrite_1AKM2(JNIEnv *env, jobject instance, jint value, jbyte value_addr, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		status = ValueBlockInSectorWrite_AKM2((int32_t)value,(uint8_t)value_addr,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockIncrement_1AKM2(JNIEnv *env, jobject instance, jint increment_value, jbyte block_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		status = ValueBlockIncrement_AKM2((int32_t)increment_value,(uint8_t)block_address,(uint8_t)auth_mode);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockInSectorIncrement_1AKM2(JNIEnv *env, jobject instance, jint increment_value, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		status = ValueBlockInSectorIncrement_AKM2((int32_t)increment_value,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockDecrement_1AKM2(JNIEnv *env, jobject instance, jint decrement_value, jbyte block_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		status = ValueBlockDecrement_AKM2((int32_t)decrement_value,(uint8_t)block_address,(uint8_t)auth_mode);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockInSectorDecrement_1AKM2(JNIEnv *env, jobject instance, jint decrement_value, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode) {
		
		UFR_STATUS status;

		status = ValueBlockInSectorDecrement_AKM2((int32_t)decrement_value,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BlockRead_1PK(JNIEnv *env, jobject instance,  jbyteArray data, jbyte block_address, jbyte auth_mode,  jbyteArray key) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = BlockRead_PK((uint8_t *)data_,(uint8_t)block_address,(uint8_t)auth_mode,(uint8_t *)key_);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BlockWrite_1PK(JNIEnv *env, jobject instance,  jbyteArray data, jbyte block_address, jbyte auth_mode,  jbyteArray key) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = BlockWrite_PK((uint8_t *)data_,(uint8_t)block_address,(uint8_t)auth_mode,(uint8_t *)key_);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BlockInSectorRead_1PK(JNIEnv *env, jobject instance,  jbyteArray data, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode,  jbyteArray key) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = BlockInSectorRead_PK((uint8_t *)data_,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode,(uint8_t *)key_);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BlockInSectorWrite_1PK(JNIEnv *env, jobject instance,  jbyteArray data, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode,  jbyteArray key) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = BlockInSectorWrite_PK((uint8_t *)data_,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode,(uint8_t *)key_);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_LinearRead_1PK(JNIEnv *env, jobject instance,  jbyteArray data, jshort linear_address, jshort length, jshortArray bytes_returned, jbyte auth_mode,  jbyteArray key) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *bytes_returned_ = env->GetShortArrayElements(bytes_returned, 0);
		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = LinearRead_PK((uint8_t *)data_,(uint16_t)linear_address,(uint16_t)length,(uint16_t *)bytes_returned_,(uint8_t)auth_mode,(uint8_t *)key_);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseShortArrayElements(bytes_returned,bytes_returned_, 0);
		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_LinRowRead_1PK(JNIEnv *env, jobject instance,  jbyteArray data, jshort linear_address, jshort length, jshortArray bytes_returned, jbyte auth_mode,  jbyteArray key) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *bytes_returned_ = env->GetShortArrayElements(bytes_returned, 0);
		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = LinRowRead_PK((uint8_t *)data_,(uint16_t)linear_address,(uint16_t)length,(uint16_t *)bytes_returned_,(uint8_t)auth_mode,(uint8_t *)key_);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseShortArrayElements(bytes_returned,bytes_returned_, 0);
		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_LinearWrite_1PK(JNIEnv *env, jobject instance,  jbyteArray data, jshort linear_address, jshort length, jshortArray bytes_written, jbyte auth_mode,  jbyteArray key) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *bytes_written_ = env->GetShortArrayElements(bytes_written, 0);
		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = LinearWrite_PK((uint8_t *)data_,(uint16_t)linear_address,(uint16_t)length,(uint16_t *)bytes_written_,(uint8_t)auth_mode,(uint8_t *)key_);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseShortArrayElements(bytes_written,bytes_written_, 0);
		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_LinearFormatCard_1PK(JNIEnv *env, jobject instance,  jbyteArray new_key_A, jbyte blocks_access_bits, jbyte sector_trailers_access_bits, jbyte sector_trailers_byte9,  jbyteArray new_key_B, jbyteArray lpucSectorsFormatted, jbyte auth_mode,  jbyteArray key) {
		
		UFR_STATUS status;

		jbyte *new_key_A_ = env->GetByteArrayElements(new_key_A, 0);
		jbyte *new_key_B_ = env->GetByteArrayElements(new_key_B, 0);
		jbyte *lpucSectorsFormatted_ = env->GetByteArrayElements(lpucSectorsFormatted, 0);
		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = LinearFormatCard_PK((uint8_t *)new_key_A_,(uint8_t)blocks_access_bits,(uint8_t)sector_trailers_access_bits,(uint8_t)sector_trailers_byte9,(uint8_t *)new_key_B_,(uint8_t *)lpucSectorsFormatted_,(uint8_t)auth_mode,(uint8_t *)key_);

		env->ReleaseByteArrayElements(new_key_A,new_key_A_, 0);
		env->ReleaseByteArrayElements(new_key_B,new_key_B_, 0);
		env->ReleaseByteArrayElements(lpucSectorsFormatted,lpucSectorsFormatted_, 0);
		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SectorTrailerWrite_1PK(JNIEnv *env, jobject instance, jbyte addressing_mode, jbyte address,  jbyteArray new_key_A, jbyte block0_access_bits, jbyte block1_access_bits, jbyte block2_access_bits, jbyte sector_trailer_access_bits, jbyte sector_trailer_byte9,  jbyteArray new_key_B, jbyte auth_mode,  jbyteArray key) {
		
		UFR_STATUS status;

		jbyte *new_key_A_ = env->GetByteArrayElements(new_key_A, 0);
		jbyte *new_key_B_ = env->GetByteArrayElements(new_key_B, 0);
		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = SectorTrailerWrite_PK((uint8_t)addressing_mode,(uint8_t)address,(uint8_t *)new_key_A_,(uint8_t)block0_access_bits,(uint8_t)block1_access_bits,(uint8_t)block2_access_bits,(uint8_t)sector_trailer_access_bits,(uint8_t)sector_trailer_byte9,(uint8_t *)new_key_B_,(uint8_t)auth_mode,(uint8_t *)key_);

		env->ReleaseByteArrayElements(new_key_A,new_key_A_, 0);
		env->ReleaseByteArrayElements(new_key_B,new_key_B_, 0);
		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SectorTrailerWriteUnsafe_1PK(JNIEnv *env, jobject instance, jbyte addressing_mode, jbyte address,  jbyteArray sector_trailer, jbyte auth_mode,  jbyteArray key) {
		
		UFR_STATUS status;

		jbyte *sector_trailer_ = env->GetByteArrayElements(sector_trailer, 0);
		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = SectorTrailerWriteUnsafe_PK((uint8_t)addressing_mode,(uint8_t)address,(uint8_t *)sector_trailer_,(uint8_t)auth_mode,(uint8_t *)key_);

		env->ReleaseByteArrayElements(sector_trailer,sector_trailer_, 0);
		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockRead_1PK(JNIEnv *env, jobject instance, jintArray value, jbyteArray value_addr, jbyte block_address, jbyte auth_mode,  jbyteArray key) {
		
		UFR_STATUS status;

		jint *value_ = env->GetIntArrayElements(value, 0);
		jbyte *value_addr_ = env->GetByteArrayElements(value_addr, 0);
		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = ValueBlockRead_PK((int32_t *)value_,(uint8_t *)value_addr_,(uint8_t)block_address,(uint8_t)auth_mode,(uint8_t *)key_);

		env->ReleaseIntArrayElements(value,value_, 0);
		env->ReleaseByteArrayElements(value_addr,value_addr_, 0);
		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockInSectorRead_1PK(JNIEnv *env, jobject instance, jintArray value, jbyteArray value_addr, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode,  jbyteArray key) {
		
		UFR_STATUS status;

		jint *value_ = env->GetIntArrayElements(value, 0);
		jbyte *value_addr_ = env->GetByteArrayElements(value_addr, 0);
		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = ValueBlockInSectorRead_PK((int32_t *)value_,(uint8_t *)value_addr_,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode,(uint8_t *)key_);

		env->ReleaseIntArrayElements(value,value_, 0);
		env->ReleaseByteArrayElements(value_addr,value_addr_, 0);
		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockWrite_1PK(JNIEnv *env, jobject instance, jint value, jbyte value_addr, jbyte block_address, jbyte auth_mode,  jbyteArray key) {
		
		UFR_STATUS status;

		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = ValueBlockWrite_PK((int32_t)value,(uint8_t)value_addr,(uint8_t)block_address,(uint8_t)auth_mode,(uint8_t *)key_);

		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockInSectorWrite_1PK(JNIEnv *env, jobject instance, jint value, jbyte value_addr, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode,  jbyteArray key) {
		
		UFR_STATUS status;

		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = ValueBlockInSectorWrite_PK((int32_t)value,(uint8_t)value_addr,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode,(uint8_t *)key_);

		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockIncrement_1PK(JNIEnv *env, jobject instance, jint increment_value, jbyte block_address, jbyte auth_mode,  jbyteArray key) {
		
		UFR_STATUS status;

		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = ValueBlockIncrement_PK((int32_t)increment_value,(uint8_t)block_address,(uint8_t)auth_mode,(uint8_t *)key_);

		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockInSectorIncrement_1PK(JNIEnv *env, jobject instance, jint increment_value, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode,  jbyteArray key) {
		
		UFR_STATUS status;

		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = ValueBlockInSectorIncrement_PK((int32_t)increment_value,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode,(uint8_t *)key_);

		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockDecrement_1PK(JNIEnv *env, jobject instance, jint decrement_value, jbyte block_address, jbyte auth_mode,  jbyteArray key) {
		
		UFR_STATUS status;

		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = ValueBlockDecrement_PK((int32_t)decrement_value,(uint8_t)block_address,(uint8_t)auth_mode,(uint8_t *)key_);

		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ValueBlockInSectorDecrement_1PK(JNIEnv *env, jobject instance, jint decrement_value, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode,  jbyteArray key) {
		
		UFR_STATUS status;

		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = ValueBlockInSectorDecrement_PK((int32_t)decrement_value,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode,(uint8_t *)key_);

		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetReaderHardwareVersion(JNIEnv *env, jobject instance, jbyteArray version_major, jbyteArray version_minor) {
		
		UFR_STATUS status;

		jbyte *version_major_ = env->GetByteArrayElements(version_major, 0);
		jbyte *version_minor_ = env->GetByteArrayElements(version_minor, 0);
		status = GetReaderHardwareVersion((uint8_t *)version_major_,(uint8_t *)version_minor_);

		env->ReleaseByteArrayElements(version_major,version_major_, 0);
		env->ReleaseByteArrayElements(version_minor,version_minor_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetReaderFirmwareVersion(JNIEnv *env, jobject instance, jbyteArray version_major, jbyteArray version_minor) {
		
		UFR_STATUS status;

		jbyte *version_major_ = env->GetByteArrayElements(version_major, 0);
		jbyte *version_minor_ = env->GetByteArrayElements(version_minor, 0);
		status = GetReaderFirmwareVersion((uint8_t *)version_major_,(uint8_t *)version_minor_);

		env->ReleaseByteArrayElements(version_major,version_major_, 0);
		env->ReleaseByteArrayElements(version_minor,version_minor_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetReaderTime(JNIEnv *env, jobject instance, jbyteArray time) {
		
		UFR_STATUS status;

		jbyte *time_ = env->GetByteArrayElements(time, 0);
		status = GetReaderTime((uint8_t *)time_);

		env->ReleaseByteArrayElements(time,time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetReaderTime(JNIEnv *env, jobject instance,  jbyteArray password, jbyteArray time) {
		
		UFR_STATUS status;

		jbyte *password_ = env->GetByteArrayElements(password, 0);
		jbyte *time_ = env->GetByteArrayElements(time, 0);
		status = SetReaderTime((uint8_t *)password_,(uint8_t *)time_);

		env->ReleaseByteArrayElements(password,password_, 0);
		env->ReleaseByteArrayElements(time,time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ChangeReaderPassword(JNIEnv *env, jobject instance,  jbyteArray old_password,  jbyteArray new_password) {
		
		UFR_STATUS status;

		jbyte *old_password_ = env->GetByteArrayElements(old_password, 0);
		jbyte *new_password_ = env->GetByteArrayElements(new_password, 0);
		status = ChangeReaderPassword((uint8_t *)old_password_,(uint8_t *)new_password_);

		env->ReleaseByteArrayElements(old_password,old_password_, 0);
		env->ReleaseByteArrayElements(new_password,new_password_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReaderEepromWrite(JNIEnv *env, jobject instance,  jbyteArray data, jint address, jint size,  jbyteArray password) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jbyte *password_ = env->GetByteArrayElements(password, 0);
		status = ReaderEepromWrite((uint8_t *)data_,(uint32_t)address,(uint32_t)size,(uint8_t *)password_);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseByteArrayElements(password,password_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReaderEepromRead(JNIEnv *env, jobject instance,  jbyteArray data, jint address, jint size) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		status = ReaderEepromRead((uint8_t *)data_,(uint32_t)address,(uint32_t)size);

		env->ReleaseByteArrayElements(data,data_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SubscribeSector(JNIEnv *env, jobject instance, jbyte block_nr, jint admin_serial) {
		
		UFR_STATUS status;

		status = SubscribeSector((uint8_t)block_nr,(uint32_t)admin_serial);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SubscribeBlock(JNIEnv *env, jobject instance, jbyte block_nr, jint admin_serial) {
		
		UFR_STATUS status;

		status = SubscribeBlock((uint8_t)block_nr,(uint32_t)admin_serial);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BusAdminCardMake(JNIEnv *env, jobject instance, jint serial,  jbyteArray password) {
		
		UFR_STATUS status;

		jbyte *password_ = env->GetByteArrayElements(password, 0);
		status = BusAdminCardMake((uint32_t)serial,(uint8_t *)password_);

		env->ReleaseByteArrayElements(password,password_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetReaderSerialDescription(JNIEnv *env, jobject instance,  jbyteArray pSerialDescription) {
		
		UFR_STATUS status;

		jbyte *pSerialDescription_ = env->GetByteArrayElements(pSerialDescription, 0);
		status = GetReaderSerialDescription((uint8_t *)pSerialDescription_);

		env->ReleaseByteArrayElements(pSerialDescription,pSerialDescription_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetBuildNumber(JNIEnv *env, jobject instance, jbyteArray build) {
		
		UFR_STATUS status;

		jbyte *build_ = env->GetByteArrayElements(build, 0);
		status = GetBuildNumber((uint8_t *)build_);

		env->ReleaseByteArrayElements(build,build_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetCardIdEx(JNIEnv *env, jobject instance, jbyteArray lpucSak,  jbyteArray aucUid, jbyteArray lpucUidSize) {
		
		UFR_STATUS status;

		jbyte *lpucSak_ = env->GetByteArrayElements(lpucSak, 0);
		jbyte *aucUid_ = env->GetByteArrayElements(aucUid, 0);
		jbyte *lpucUidSize_ = env->GetByteArrayElements(lpucUidSize, 0);
		status = GetCardIdEx((uint8_t *)lpucSak_,(uint8_t *)aucUid_,(uint8_t *)lpucUidSize_);

		env->ReleaseByteArrayElements(lpucSak,lpucSak_, 0);
		env->ReleaseByteArrayElements(aucUid,aucUid_, 0);
		env->ReleaseByteArrayElements(lpucUidSize,lpucUidSize_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetLastCardIdEx(JNIEnv *env, jobject instance, jbyteArray lpucSak,  jbyteArray aucUid, jbyteArray lpucUidSize) {
		
		UFR_STATUS status;

		jbyte *lpucSak_ = env->GetByteArrayElements(lpucSak, 0);
		jbyte *aucUid_ = env->GetByteArrayElements(aucUid, 0);
		jbyte *lpucUidSize_ = env->GetByteArrayElements(lpucUidSize, 0);
		status = GetLastCardIdEx((uint8_t *)lpucSak_,(uint8_t *)aucUid_,(uint8_t *)lpucUidSize_);

		env->ReleaseByteArrayElements(lpucSak,lpucSak_, 0);
		env->ReleaseByteArrayElements(aucUid,aucUid_, 0);
		env->ReleaseByteArrayElements(lpucUidSize,lpucUidSize_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_EnableAntiCollision(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = EnableAntiCollision();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_DisableAntiCollision(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = DisableAntiCollision();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_EnumCards(JNIEnv *env, jobject instance, jbyteArray lpucCardsNumber,  jbyteArray lpucUidListSize) {
		
		UFR_STATUS status;

		jbyte *lpucCardsNumber_ = env->GetByteArrayElements(lpucCardsNumber, 0);
		jbyte *lpucUidListSize_ = env->GetByteArrayElements(lpucUidListSize, 0);
		status = EnumCards((uint8_t *)lpucCardsNumber_,(uint8_t *)lpucUidListSize_);

		env->ReleaseByteArrayElements(lpucCardsNumber,lpucCardsNumber_, 0);
		env->ReleaseByteArrayElements(lpucUidListSize,lpucUidListSize_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ListCards(JNIEnv *env, jobject instance,  jbyteArray aucUidList, jbyte ucUidListSize) {
		
		UFR_STATUS status;

		jbyte *aucUidList_ = env->GetByteArrayElements(aucUidList, 0);
		status = ListCards((uint8_t *)aucUidList_,(uint8_t)ucUidListSize);

		env->ReleaseByteArrayElements(aucUidList,aucUidList_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SelectCard(JNIEnv *env, jobject instance,  jbyteArray aucUid, jbyte ucUidSize,  jbyteArray lpucSelctedCardType) {
		
		UFR_STATUS status;

		jbyte *aucUid_ = env->GetByteArrayElements(aucUid, 0);
		jbyte *lpucSelctedCardType_ = env->GetByteArrayElements(lpucSelctedCardType, 0);
		status = SelectCard((uint8_t *)aucUid_,(uint8_t)ucUidSize,(uint8_t *)lpucSelctedCardType_);

		env->ReleaseByteArrayElements(aucUid,aucUid_, 0);
		env->ReleaseByteArrayElements(lpucSelctedCardType,lpucSelctedCardType_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_DeslectCard(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = DeslectCard();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetAntiCollisionStatus(JNIEnv *env, jobject instance, jbyteArray lpcIsAntiCollEnabled, jbyteArray lpcIsAnyCardSelected) {
		
		UFR_STATUS status;

		jbyte *lpcIsAntiCollEnabled_ = env->GetByteArrayElements(lpcIsAntiCollEnabled, 0);
		jbyte *lpcIsAnyCardSelected_ = env->GetByteArrayElements(lpcIsAnyCardSelected, 0);
		status = GetAntiCollisionStatus((int8_t *)lpcIsAntiCollEnabled_,(int8_t *)lpcIsAnyCardSelected_);

		env->ReleaseByteArrayElements(lpcIsAntiCollEnabled,lpcIsAntiCollEnabled_, 0);
		env->ReleaseByteArrayElements(lpcIsAnyCardSelected,lpcIsAnyCardSelected_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetDlogicCardType(JNIEnv *env, jobject instance, jbyteArray lpucCardType) {
		
		UFR_STATUS status;

		jbyte *lpucCardType_ = env->GetByteArrayElements(lpucCardType, 0);
		status = GetDlogicCardType((uint8_t *)lpucCardType_);

		env->ReleaseByteArrayElements(lpucCardType,lpucCardType_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetNfcT2TVersion(JNIEnv *env, jobject instance,  jbyteArray lpucVersionResponse) {
		
		UFR_STATUS status;

		jbyte *lpucVersionResponse_ = env->GetByteArrayElements(lpucVersionResponse, 0);
		status = GetNfcT2TVersion((uint8_t *)lpucVersionResponse_);

		env->ReleaseByteArrayElements(lpucVersionResponse,lpucVersionResponse_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetCardSize(JNIEnv *env, jobject instance, jintArray lpulLinearSize, jintArray lpulRawSize) {
		
		UFR_STATUS status;

		jint *lpulLinearSize_ = env->GetIntArrayElements(lpulLinearSize, 0);
		jint *lpulRawSize_ = env->GetIntArrayElements(lpulRawSize, 0);
		status = GetCardSize((uint32_t *)lpulLinearSize_,(uint32_t *)lpulRawSize_);

		env->ReleaseIntArrayElements(lpulLinearSize,lpulLinearSize_, 0);
		env->ReleaseIntArrayElements(lpulRawSize,lpulRawSize_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetReaderProMode(JNIEnv *env, jobject instance, jintArray pReaderProMode,  jintArray pReaderProConfig) {
		
		UFR_STATUS status;

		jint *pReaderProMode_ = env->GetIntArrayElements(pReaderProMode, 0);
		jint *pReaderProConfig_ = env->GetIntArrayElements(pReaderProConfig, 0);
		status = GetReaderProMode((uint32_t *)pReaderProMode_,(uint32_t *)pReaderProConfig_);

		env->ReleaseIntArrayElements(pReaderProMode,pReaderProMode_, 0);
		env->ReleaseIntArrayElements(pReaderProConfig,pReaderProConfig_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetReaderProMode(JNIEnv *env, jobject instance,  uint32_t ReaderProMode) {
		
		UFR_STATUS status;

		status = SetReaderProMode((uint32_t)ReaderProMode);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_CardEncryption_1Initialize(JNIEnv *env, jobject instance,  jbyteArray TBSerialString, jshort job_number) {
		
		UFR_STATUS status;

		jbyte *TBSerialString_ = env->GetByteArrayElements(TBSerialString, 0);
		status = CardEncryption_Initialize((uint8_t *)TBSerialString_,(uint16_t)job_number);

		env->ReleaseByteArrayElements(TBSerialString,TBSerialString_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_CardEncryption_1GetNextEncryptedCard(JNIEnv *env, jobject instance,  uint32_t from_timestamp,  uint32_t to_timestamp,  jbyteArray out_card_data) {
		
		UFR_STATUS status;

		jbyte *out_card_data_ = env->GetByteArrayElements(out_card_data, 0);
		status = CardEncryption_GetNextEncryptedCard((uint32_t)from_timestamp,(uint32_t)to_timestamp,(uint8_t *)out_card_data_);

		env->ReleaseByteArrayElements(out_card_data,out_card_data_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_CardEncryption_1GetNext(JNIEnv *env, jobject instance,  uint32_t code_type,  uint32_t from_timestamp,  uint32_t to_timestamp,  uint32_t additional_data_size,  jbyteArray additional_data, jintArray out_card_data_size,  jbyteArray out_card_data) {
		
		UFR_STATUS status;

		jbyte *additional_data_ = env->GetByteArrayElements(additional_data, 0);
		jint *out_card_data_size_ = env->GetIntArrayElements(out_card_data_size, 0);
		jbyte *out_card_data_ = env->GetByteArrayElements(out_card_data, 0);
		status = CardEncryption_GetNext((uint32_t)code_type,(uint32_t)from_timestamp,(uint32_t)to_timestamp,(uint32_t)additional_data_size,(uint8_t *)additional_data_,(uint32_t *)out_card_data_size_,(uint8_t *)out_card_data_);

		env->ReleaseByteArrayElements(additional_data,additional_data_, 0);
		env->ReleaseIntArrayElements(out_card_data_size,out_card_data_size_, 0);
		env->ReleaseByteArrayElements(out_card_data,out_card_data_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_CardEncryption_1GetActualCardSN(JNIEnv *env, jobject instance,  jintArray ActualCard_SN, jintArray ActualCard_SN_LOG) {
		
		UFR_STATUS status;

		jint *ActualCard_SN_ = env->GetIntArrayElements(ActualCard_SN, 0);
		jint *ActualCard_SN_LOG_ = env->GetIntArrayElements(ActualCard_SN_LOG, 0);
		status = CardEncryption_GetActualCardSN((uint32_t *)ActualCard_SN_,(uint32_t *)ActualCard_SN_LOG_);

		env->ReleaseIntArrayElements(ActualCard_SN,ActualCard_SN_, 0);
		env->ReleaseIntArrayElements(ActualCard_SN_LOG,ActualCard_SN_LOG_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_CardEncryption_1GetJobSN(JNIEnv *env, jobject instance, jintArray JobSN) {
		
		UFR_STATUS status;

		jint *JobSN_ = env->GetIntArrayElements(JobSN, 0);
		status = CardEncryption_GetJobSN((uint32_t *)JobSN_);

		env->ReleaseIntArrayElements(JobSN,JobSN_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_CardEncryption_1GetSalterSN(JNIEnv *env, jobject instance,  jbyteArray SalterSN, jbyteArray magicByte) {
		
		UFR_STATUS status;

		jbyte *SalterSN_ = env->GetByteArrayElements(SalterSN, 0);
		jbyte *magicByte_ = env->GetByteArrayElements(magicByte, 0);
		status = CardEncryption_GetSalterSN((uint8_t *)SalterSN_,(uint8_t *)magicByte_);

		env->ReleaseByteArrayElements(SalterSN,SalterSN_, 0);
		env->ReleaseByteArrayElements(magicByte,magicByte_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_read_1ndef_1record(JNIEnv *env, jobject instance, jbyte message_nr, jbyte record_nr, jbyteArray tnf,  jbyteArray type_record, jbyteArray type_length,  jbyteArray id, jbyteArray id_length,  jbyteArray payload, jintArray payload_length) {
		
		UFR_STATUS status;

		jbyte *tnf_ = env->GetByteArrayElements(tnf, 0);
		jbyte *type_record_ = env->GetByteArrayElements(type_record, 0);
		jbyte *type_length_ = env->GetByteArrayElements(type_length, 0);
		jbyte *id_ = env->GetByteArrayElements(id, 0);
		jbyte *id_length_ = env->GetByteArrayElements(id_length, 0);
		jbyte *payload_ = env->GetByteArrayElements(payload, 0);
		jint *payload_length_ = env->GetIntArrayElements(payload_length, 0);
		status = read_ndef_record((uint8_t)message_nr,(uint8_t)record_nr,(uint8_t *)tnf_,(uint8_t *)type_record_,(uint8_t *)type_length_,(uint8_t *)id_,(uint8_t *)id_length_,(uint8_t *)payload_,(uint32_t *)payload_length_);

		env->ReleaseByteArrayElements(tnf,tnf_, 0);
		env->ReleaseByteArrayElements(type_record,type_record_, 0);
		env->ReleaseByteArrayElements(type_length,type_length_, 0);
		env->ReleaseByteArrayElements(id,id_, 0);
		env->ReleaseByteArrayElements(id_length,id_length_, 0);
		env->ReleaseByteArrayElements(payload,payload_, 0);
		env->ReleaseIntArrayElements(payload_length,payload_length_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_write_1ndef_1record(JNIEnv *env, jobject instance, jbyte message_nr, jbyteArray tnf,  jbyteArray type_record, jbyteArray type_length,  jbyteArray id, jbyteArray id_length,  jbyteArray payload, jintArray payload_length, jbyteArray card_formated) {
		
		UFR_STATUS status;

		jbyte *tnf_ = env->GetByteArrayElements(tnf, 0);
		jbyte *type_record_ = env->GetByteArrayElements(type_record, 0);
		jbyte *type_length_ = env->GetByteArrayElements(type_length, 0);
		jbyte *id_ = env->GetByteArrayElements(id, 0);
		jbyte *id_length_ = env->GetByteArrayElements(id_length, 0);
		jbyte *payload_ = env->GetByteArrayElements(payload, 0);
		jint *payload_length_ = env->GetIntArrayElements(payload_length, 0);
		jbyte *card_formated_ = env->GetByteArrayElements(card_formated, 0);
		status = write_ndef_record((uint8_t)message_nr,(uint8_t *)tnf_,(uint8_t *)type_record_,(uint8_t *)type_length_,(uint8_t *)id_,(uint8_t *)id_length_,(uint8_t *)payload_,(uint32_t *)payload_length_,(uint8_t *)card_formated_);

		env->ReleaseByteArrayElements(tnf,tnf_, 0);
		env->ReleaseByteArrayElements(type_record,type_record_, 0);
		env->ReleaseByteArrayElements(type_length,type_length_, 0);
		env->ReleaseByteArrayElements(id,id_, 0);
		env->ReleaseByteArrayElements(id_length,id_length_, 0);
		env->ReleaseByteArrayElements(payload,payload_, 0);
		env->ReleaseIntArrayElements(payload_length,payload_length_, 0);
		env->ReleaseByteArrayElements(card_formated,card_formated_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_write_1ndef_1record_1mirroring(JNIEnv *env, jobject instance, jbyte message_nr, jbyteArray tnf,  jbyteArray type_record, jbyteArray type_length,  jbyteArray id, jbyteArray id_length,  jbyteArray payload, jintArray payload_length, jbyteArray card_formated, int use_uid_ascii_mirror, int use_counter_ascii_mirror, jint payload_mirroring_pos) {
		
		UFR_STATUS status;

		jbyte *tnf_ = env->GetByteArrayElements(tnf, 0);
		jbyte *type_record_ = env->GetByteArrayElements(type_record, 0);
		jbyte *type_length_ = env->GetByteArrayElements(type_length, 0);
		jbyte *id_ = env->GetByteArrayElements(id, 0);
		jbyte *id_length_ = env->GetByteArrayElements(id_length, 0);
		jbyte *payload_ = env->GetByteArrayElements(payload, 0);
		jint *payload_length_ = env->GetIntArrayElements(payload_length, 0);
		jbyte *card_formated_ = env->GetByteArrayElements(card_formated, 0);
		status = write_ndef_record_mirroring((uint8_t)message_nr,(uint8_t *)tnf_,(uint8_t *)type_record_,(uint8_t *)type_length_,(uint8_t *)id_,(uint8_t *)id_length_,(uint8_t *)payload_,(uint32_t *)payload_length_,(uint8_t *)card_formated_,(int)use_uid_ascii_mirror,(int)use_counter_ascii_mirror,(uint32_t)payload_mirroring_pos);

		env->ReleaseByteArrayElements(tnf,tnf_, 0);
		env->ReleaseByteArrayElements(type_record,type_record_, 0);
		env->ReleaseByteArrayElements(type_length,type_length_, 0);
		env->ReleaseByteArrayElements(id,id_, 0);
		env->ReleaseByteArrayElements(id_length,id_length_, 0);
		env->ReleaseByteArrayElements(payload,payload_, 0);
		env->ReleaseIntArrayElements(payload_length,payload_length_, 0);
		env->ReleaseByteArrayElements(card_formated,card_formated_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_get_1ndef_1record_1count(JNIEnv *env, jobject instance, jbyteArray ndef_message_cnt, jbyteArray ndef_record_cnt,  jbyteArray ndef_record_array, jbyteArray empty_ndef_message_cnt) {
		
		UFR_STATUS status;

		jbyte *ndef_message_cnt_ = env->GetByteArrayElements(ndef_message_cnt, 0);
		jbyte *ndef_record_cnt_ = env->GetByteArrayElements(ndef_record_cnt, 0);
		jbyte *ndef_record_array_ = env->GetByteArrayElements(ndef_record_array, 0);
		jbyte *empty_ndef_message_cnt_ = env->GetByteArrayElements(empty_ndef_message_cnt, 0);
		status = get_ndef_record_count((uint8_t *)ndef_message_cnt_,(uint8_t *)ndef_record_cnt_,(uint8_t *)ndef_record_array_,(uint8_t *)empty_ndef_message_cnt_);

		env->ReleaseByteArrayElements(ndef_message_cnt,ndef_message_cnt_, 0);
		env->ReleaseByteArrayElements(ndef_record_cnt,ndef_record_cnt_, 0);
		env->ReleaseByteArrayElements(ndef_record_array,ndef_record_array_, 0);
		env->ReleaseByteArrayElements(empty_ndef_message_cnt,empty_ndef_message_cnt_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_erase_1last_1ndef_1record(JNIEnv *env, jobject instance, jbyte message_nr) {
		
		UFR_STATUS status;

		status = erase_last_ndef_record((uint8_t)message_nr);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_erase_1all_1ndef_1records(JNIEnv *env, jobject instance, jbyte message_nr) {
		
		UFR_STATUS status;

		status = erase_all_ndef_records((uint8_t)message_nr);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ndef_1card_1initialization(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = ndef_card_initialization();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteEmulationNdef(JNIEnv *env, jobject instance, jbyte tnf,  jbyteArray type_record, jbyte type_length,  jbyteArray id, jbyte id_length,  jbyteArray payload, jbyte payload_length) {
		
		UFR_STATUS status;

		jbyte *type_record_ = env->GetByteArrayElements(type_record, 0);
		jbyte *id_ = env->GetByteArrayElements(id, 0);
		jbyte *payload_ = env->GetByteArrayElements(payload, 0);
		status = WriteEmulationNdef((uint8_t)tnf,(uint8_t *)type_record_,(uint8_t)type_length,(uint8_t *)id_,(uint8_t)id_length,(uint8_t *)payload_,(uint8_t)payload_length);

		env->ReleaseByteArrayElements(type_record,type_record_, 0);
		env->ReleaseByteArrayElements(id,id_, 0);
		env->ReleaseByteArrayElements(payload,payload_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteEmulationNdefWithAAR(JNIEnv *env, jobject instance, jbyte tnf,  jbyteArray type_record, jbyte type_length,  jbyteArray id, jbyte id_length,  jbyteArray payload, jbyte payload_length,  jbyteArray aar, jbyte aar_length) {
		
		UFR_STATUS status;

		jbyte *type_record_ = env->GetByteArrayElements(type_record, 0);
		jbyte *id_ = env->GetByteArrayElements(id, 0);
		jbyte *payload_ = env->GetByteArrayElements(payload, 0);
		jbyte *aar_ = env->GetByteArrayElements(aar, 0);
		status = WriteEmulationNdefWithAAR((uint8_t)tnf,(uint8_t *)type_record_,(uint8_t)type_length,(uint8_t *)id_,(uint8_t)id_length,(uint8_t *)payload_,(uint8_t)payload_length,(uint8_t *)aar_,(uint8_t)aar_length);

		env->ReleaseByteArrayElements(type_record,type_record_, 0);
		env->ReleaseByteArrayElements(id,id_, 0);
		env->ReleaseByteArrayElements(payload,payload_, 0);
		env->ReleaseByteArrayElements(aar,aar_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_TagEmulationStart(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = TagEmulationStart();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_TagEmulationStop(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = TagEmulationStop();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_CombinedModeEmulationStart(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = CombinedModeEmulationStart();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_AdHocEmulationStart(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = AdHocEmulationStart();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_AdHocEmulationStop(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = AdHocEmulationStop();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetAdHocEmulationParams(JNIEnv *env, jobject instance, jbyteArray ThresholdMinLevel, jbyteArray ThresholdCollLevel, jbyteArray RFLevelAmp, jbyteArray RxGain, jbyteArray RFLevel) {
		
		UFR_STATUS status;

		jbyte *ThresholdMinLevel_ = env->GetByteArrayElements(ThresholdMinLevel, 0);
		jbyte *ThresholdCollLevel_ = env->GetByteArrayElements(ThresholdCollLevel, 0);
		jbyte *RFLevelAmp_ = env->GetByteArrayElements(RFLevelAmp, 0);
		jbyte *RxGain_ = env->GetByteArrayElements(RxGain, 0);
		jbyte *RFLevel_ = env->GetByteArrayElements(RFLevel, 0);
		status = GetAdHocEmulationParams((uint8_t *)ThresholdMinLevel_,(uint8_t *)ThresholdCollLevel_,(uint8_t *)RFLevelAmp_,(uint8_t *)RxGain_,(uint8_t *)RFLevel_);

		env->ReleaseByteArrayElements(ThresholdMinLevel,ThresholdMinLevel_, 0);
		env->ReleaseByteArrayElements(ThresholdCollLevel,ThresholdCollLevel_, 0);
		env->ReleaseByteArrayElements(RFLevelAmp,RFLevelAmp_, 0);
		env->ReleaseByteArrayElements(RxGain,RxGain_, 0);
		env->ReleaseByteArrayElements(RFLevel,RFLevel_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetAdHocEmulationParams(JNIEnv *env, jobject instance, jbyte ThresholdMinLevel, jbyte ThresholdCollLevel, jbyte RFLevelAmp, jbyte RxGain, jbyte RFLevel) {
		
		UFR_STATUS status;

		status = SetAdHocEmulationParams((uint8_t)ThresholdMinLevel,(uint8_t)ThresholdCollLevel,(uint8_t)RFLevelAmp,(uint8_t)RxGain,(uint8_t)RFLevel);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetExternalFieldState(JNIEnv *env, jobject instance, jbyteArray is_field_present) {
		
		UFR_STATUS status;

		jbyte *is_field_present_ = env->GetByteArrayElements(is_field_present, 0);
		status = GetExternalFieldState((uint8_t *)is_field_present_);

		env->ReleaseByteArrayElements(is_field_present,is_field_present_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_EnterShareRamCommMode(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = EnterShareRamCommMode();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ExitShareRamCommMode(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = ExitShareRamCommMode();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteShareRam(JNIEnv *env, jobject instance,  jbyteArray ram_data, jbyte addr, jbyte data_len) {
		
		UFR_STATUS status;

		jbyte *ram_data_ = env->GetByteArrayElements(ram_data, 0);
		status = WriteShareRam((uint8_t *)ram_data_,(uint8_t)addr,(uint8_t)data_len);

		env->ReleaseByteArrayElements(ram_data,ram_data_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadShareRam(JNIEnv *env, jobject instance,  jbyteArray ram_data, jbyte addr, jbyte data_len) {
		
		UFR_STATUS status;

		jbyte *ram_data_ = env->GetByteArrayElements(ram_data, 0);
		status = ReadShareRam((uint8_t *)ram_data_,(uint8_t)addr,(uint8_t)data_len);

		env->ReleaseByteArrayElements(ram_data,ram_data_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadECCSignature(JNIEnv *env, jobject instance,  jbyteArray lpucECCSignature,  jbyteArray lpucUid, jbyteArray lpucUidLen, jbyteArray lpucDlogicCardType) {
		
		UFR_STATUS status;

		jbyte *lpucECCSignature_ = env->GetByteArrayElements(lpucECCSignature, 0);
		jbyte *lpucUid_ = env->GetByteArrayElements(lpucUid, 0);
		jbyte *lpucUidLen_ = env->GetByteArrayElements(lpucUidLen, 0);
		jbyte *lpucDlogicCardType_ = env->GetByteArrayElements(lpucDlogicCardType, 0);
		status = ReadECCSignature((uint8_t *)lpucECCSignature_,(uint8_t *)lpucUid_,(uint8_t *)lpucUidLen_,(uint8_t *)lpucDlogicCardType_);

		env->ReleaseByteArrayElements(lpucECCSignature,lpucECCSignature_, 0);
		env->ReleaseByteArrayElements(lpucUid,lpucUid_, 0);
		env->ReleaseByteArrayElements(lpucUidLen,lpucUidLen_, 0);
		env->ReleaseByteArrayElements(lpucDlogicCardType,lpucDlogicCardType_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadCounter(JNIEnv *env, jobject instance, jbyte counter_address, jintArray value) {
		
		UFR_STATUS status;

		jint *value_ = env->GetIntArrayElements(value, 0);
		status = ReadCounter((uint8_t)counter_address,(uint32_t *)value_);

		env->ReleaseIntArrayElements(value,value_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_IncrementCounter(JNIEnv *env, jobject instance, jbyte counter_address, jint inc_value) {
		
		UFR_STATUS status;

		status = IncrementCounter((uint8_t)counter_address,(uint32_t)inc_value);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNFCCounter(JNIEnv *env, jobject instance, jintArray value) {
		
		UFR_STATUS status;

		jint *value_ = env->GetIntArrayElements(value, 0);
		status = ReadNFCCounter((uint32_t *)value_);

		env->ReleaseIntArrayElements(value,value_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNFCCounterPwdAuth_RK(JNIEnv *env, jobject instance, jintArray value, jbyte reader_key_index) {
		
		UFR_STATUS status;

		jint *value_ = env->GetIntArrayElements(value, 0);
		status = ReadNFCCounterPwdAuth_RK((uint32_t *)value_,(uint8_t)reader_key_index);

		env->ReleaseIntArrayElements(value,value_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNFCCounterPwdAuth_1PK(JNIEnv *env, jobject instance, jintArray value,  jbyteArray key) {
		
		UFR_STATUS status;

		jint *value_ = env->GetIntArrayElements(value, 0);
		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = ReadNFCCounterPwdAuth_PK((uint32_t *)value_,(uint8_t *)key_);

		env->ReleaseIntArrayElements(value,value_, 0);
		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetAsyncCardIdSendConfig(JNIEnv *env, jobject instance, jbyte send_enable, jbyte prefix_enable, jbyte prefix, jbyte suffix, jbyte send_removed_enable, jint async_baud_rate) {
		
		UFR_STATUS status;

		status = SetAsyncCardIdSendConfig((uint8_t)send_enable,(uint8_t)prefix_enable,(uint8_t)prefix,(uint8_t)suffix,(uint8_t)send_removed_enable,(uint32_t)async_baud_rate);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetAsyncCardIdSendConfigEx(JNIEnv *env, jobject instance, jbyte send_enable, jbyte prefix_enable, jbyte prefix, jbyte suffix, jbyte send_removed_enable, jbyte reverse_byte_order, jbyte decimal_representation, jint async_baud_rate) {
		
		UFR_STATUS status;

		status = SetAsyncCardIdSendConfigEx((uint8_t)send_enable,(uint8_t)prefix_enable,(uint8_t)prefix,(uint8_t)suffix,(uint8_t)send_removed_enable,(uint8_t)reverse_byte_order,(uint8_t)decimal_representation,(uint32_t)async_baud_rate);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetAsyncCardIdSendConfig(JNIEnv *env, jobject instance, jbyteArray send_enable, jbyteArray prefix_enable, jbyteArray prefix, jbyteArray suffix, jbyteArray send_removed_enable, jintArray async_baud_rate) {
		
		UFR_STATUS status;

		jbyte *send_enable_ = env->GetByteArrayElements(send_enable, 0);
		jbyte *prefix_enable_ = env->GetByteArrayElements(prefix_enable, 0);
		jbyte *prefix_ = env->GetByteArrayElements(prefix, 0);
		jbyte *suffix_ = env->GetByteArrayElements(suffix, 0);
		jbyte *send_removed_enable_ = env->GetByteArrayElements(send_removed_enable, 0);
		jint *async_baud_rate_ = env->GetIntArrayElements(async_baud_rate, 0);
		status = GetAsyncCardIdSendConfig((uint8_t *)send_enable_,(uint8_t *)prefix_enable_,(uint8_t *)prefix_,(uint8_t *)suffix_,(uint8_t *)send_removed_enable_,(uint32_t *)async_baud_rate_);

		env->ReleaseByteArrayElements(send_enable,send_enable_, 0);
		env->ReleaseByteArrayElements(prefix_enable,prefix_enable_, 0);
		env->ReleaseByteArrayElements(prefix,prefix_, 0);
		env->ReleaseByteArrayElements(suffix,suffix_, 0);
		env->ReleaseByteArrayElements(send_removed_enable,send_removed_enable_, 0);
		env->ReleaseIntArrayElements(async_baud_rate,async_baud_rate_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetAsyncCardIdSendConfigEx(JNIEnv *env, jobject instance, jbyteArray send_enable, jbyteArray prefix_enable, jbyteArray prefix, jbyteArray suffix, jbyteArray send_removed_enable, jbyteArray reverse_byte_order, jbyteArray decimal_representation, jintArray async_baud_rate) {
		
		UFR_STATUS status;

		jbyte *send_enable_ = env->GetByteArrayElements(send_enable, 0);
		jbyte *prefix_enable_ = env->GetByteArrayElements(prefix_enable, 0);
		jbyte *prefix_ = env->GetByteArrayElements(prefix, 0);
		jbyte *suffix_ = env->GetByteArrayElements(suffix, 0);
		jbyte *send_removed_enable_ = env->GetByteArrayElements(send_removed_enable, 0);
		jbyte *reverse_byte_order_ = env->GetByteArrayElements(reverse_byte_order, 0);
		jbyte *decimal_representation_ = env->GetByteArrayElements(decimal_representation, 0);
		jint *async_baud_rate_ = env->GetIntArrayElements(async_baud_rate, 0);
		status = GetAsyncCardIdSendConfigEx((uint8_t *)send_enable_,(uint8_t *)prefix_enable_,(uint8_t *)prefix_,(uint8_t *)suffix_,(uint8_t *)send_removed_enable_,(uint8_t *)reverse_byte_order_,(uint8_t *)decimal_representation_,(uint32_t *)async_baud_rate_);

		env->ReleaseByteArrayElements(send_enable,send_enable_, 0);
		env->ReleaseByteArrayElements(prefix_enable,prefix_enable_, 0);
		env->ReleaseByteArrayElements(prefix,prefix_, 0);
		env->ReleaseByteArrayElements(suffix,suffix_, 0);
		env->ReleaseByteArrayElements(send_removed_enable,send_removed_enable_, 0);
		env->ReleaseByteArrayElements(reverse_byte_order,reverse_byte_order_, 0);
		env->ReleaseByteArrayElements(decimal_representation,decimal_representation_, 0);
		env->ReleaseIntArrayElements(async_baud_rate,async_baud_rate_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ais_1get_1card_1number(JNIEnv *env, jobject instance, jintArray card_number) {
		
		UFR_STATUS status;

		jint *card_number_ = env->GetIntArrayElements(card_number, 0);
		status = ais_get_card_number((uint32_t *)card_number_);

		env->ReleaseIntArrayElements(card_number,card_number_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ais_1set_1right_1record(JNIEnv *env, jobject instance, jbyte record_number, jshort first_reader_nr, jshort last_reader_nr, jbyte start_hour, jbyte start_minute, jbyte end_hour, jbyte end_minute,  jbyteArray days) {
		
		UFR_STATUS status;

		jbyte *days_ = env->GetByteArrayElements(days, 0);
		status = ais_set_right_record((uint8_t)record_number,(uint16_t)first_reader_nr,(uint16_t)last_reader_nr,(uint8_t)start_hour,(uint8_t)start_minute,(uint8_t)end_hour,(uint8_t)end_minute,(uint8_t *)days_);

		env->ReleaseByteArrayElements(days,days_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ais_1get_1right_1record(JNIEnv *env, jobject instance, jbyte record_number, jshortArray first_reader_nr, jshortArray last_reader_nr, jbyteArray start_hour, jbyteArray start_minute, jbyteArray end_hour, jbyteArray end_minute,  jbyteArray days) {
		
		UFR_STATUS status;

		jshort *first_reader_nr_ = env->GetShortArrayElements(first_reader_nr, 0);
		jshort *last_reader_nr_ = env->GetShortArrayElements(last_reader_nr, 0);
		jbyte *start_hour_ = env->GetByteArrayElements(start_hour, 0);
		jbyte *start_minute_ = env->GetByteArrayElements(start_minute, 0);
		jbyte *end_hour_ = env->GetByteArrayElements(end_hour, 0);
		jbyte *end_minute_ = env->GetByteArrayElements(end_minute, 0);
		jbyte *days_ = env->GetByteArrayElements(days, 0);
		status = ais_get_right_record((uint8_t)record_number,(uint16_t *)first_reader_nr_,(uint16_t *)last_reader_nr_,(uint8_t *)start_hour_,(uint8_t *)start_minute_,(uint8_t *)end_hour_,(uint8_t *)end_minute_,(uint8_t *)days_);

		env->ReleaseShortArrayElements(first_reader_nr,first_reader_nr_, 0);
		env->ReleaseShortArrayElements(last_reader_nr,last_reader_nr_, 0);
		env->ReleaseByteArrayElements(start_hour,start_hour_, 0);
		env->ReleaseByteArrayElements(start_minute,start_minute_, 0);
		env->ReleaseByteArrayElements(end_hour,end_hour_, 0);
		env->ReleaseByteArrayElements(end_minute,end_minute_, 0);
		env->ReleaseByteArrayElements(days,days_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ais_1erase_1right_1record(JNIEnv *env, jobject instance, jbyte record_number) {
		
		UFR_STATUS status;

		status = ais_erase_right_record((uint8_t)record_number);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ais_1set_1validate_1record(JNIEnv *env, jobject instance, jbyte begin_year, jbyte begin_month, jbyte begin_day, jbyte begin_hour, jbyte begin_minute, jbyte end_year, jbyte end_month, jbyte end_day, jbyte end_hour, jbyte end_minute) {
		
		UFR_STATUS status;

		status = ais_set_validate_record((uint8_t)begin_year,(uint8_t)begin_month,(uint8_t)begin_day,(uint8_t)begin_hour,(uint8_t)begin_minute,(uint8_t)end_year,(uint8_t)end_month,(uint8_t)end_day,(uint8_t)end_hour,(uint8_t)end_minute);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ais_1get_1validate_1record(JNIEnv *env, jobject instance, jbyteArray begin_year, jbyteArray begin_month, jbyteArray begin_day, jbyteArray begin_hour, jbyteArray begin_minute, jbyteArray end_year, jbyteArray end_month, jbyteArray end_day, jbyteArray end_hour, jbyteArray end_minute) {
		
		UFR_STATUS status;

		jbyte *begin_year_ = env->GetByteArrayElements(begin_year, 0);
		jbyte *begin_month_ = env->GetByteArrayElements(begin_month, 0);
		jbyte *begin_day_ = env->GetByteArrayElements(begin_day, 0);
		jbyte *begin_hour_ = env->GetByteArrayElements(begin_hour, 0);
		jbyte *begin_minute_ = env->GetByteArrayElements(begin_minute, 0);
		jbyte *end_year_ = env->GetByteArrayElements(end_year, 0);
		jbyte *end_month_ = env->GetByteArrayElements(end_month, 0);
		jbyte *end_day_ = env->GetByteArrayElements(end_day, 0);
		jbyte *end_hour_ = env->GetByteArrayElements(end_hour, 0);
		jbyte *end_minute_ = env->GetByteArrayElements(end_minute, 0);
		status = ais_get_validate_record((uint8_t *)begin_year_,(uint8_t *)begin_month_,(uint8_t *)begin_day_,(uint8_t *)begin_hour_,(uint8_t *)begin_minute_,(uint8_t *)end_year_,(uint8_t *)end_month_,(uint8_t *)end_day_,(uint8_t *)end_hour_,(uint8_t *)end_minute_);

		env->ReleaseByteArrayElements(begin_year,begin_year_, 0);
		env->ReleaseByteArrayElements(begin_month,begin_month_, 0);
		env->ReleaseByteArrayElements(begin_day,begin_day_, 0);
		env->ReleaseByteArrayElements(begin_hour,begin_hour_, 0);
		env->ReleaseByteArrayElements(begin_minute,begin_minute_, 0);
		env->ReleaseByteArrayElements(end_year,end_year_, 0);
		env->ReleaseByteArrayElements(end_month,end_month_, 0);
		env->ReleaseByteArrayElements(end_day,end_day_, 0);
		env->ReleaseByteArrayElements(end_hour,end_hour_, 0);
		env->ReleaseByteArrayElements(end_minute,end_minute_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ais_1set_1card_1type(JNIEnv *env, jobject instance, jbyte card_type) {
		
		UFR_STATUS status;

		status = ais_set_card_type((uint8_t)card_type);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ais_1get_1card_1type(JNIEnv *env, jobject instance, jbyteArray card_type) {
		
		UFR_STATUS status;

		jbyte *card_type_ = env->GetByteArrayElements(card_type, 0);
		status = ais_get_card_type((uint8_t *)card_type_);

		env->ReleaseByteArrayElements(card_type,card_type_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ais_1set_1card_1daily_1duration(JNIEnv *env, jobject instance, jshort duration) {
		
		UFR_STATUS status;

		status = ais_set_card_daily_duration((uint16_t)duration);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ais_1get_1card_1daily_1duration(JNIEnv *env, jobject instance, jshortArray duration) {
		
		UFR_STATUS status;

		jshort *duration_ = env->GetShortArrayElements(duration, 0);
		status = ais_get_card_daily_duration((uint16_t *)duration_);

		env->ReleaseShortArrayElements(duration,duration_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ais_1set_1card_1total_1duration(JNIEnv *env, jobject instance, jint duration) {
		
		UFR_STATUS status;

		status = ais_set_card_total_duration((uint32_t)duration);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ais_1get_1card_1total_1duration(JNIEnv *env, jobject instance, jintArray duration) {
		
		UFR_STATUS status;

		jint *duration_ = env->GetIntArrayElements(duration, 0);
		status = ais_get_card_total_duration((uint32_t *)duration_);

		env->ReleaseIntArrayElements(duration,duration_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ais_1get_1credit_1and_1period_1validity(JNIEnv *env, jobject instance, jintArray credit, jintArray begin_year, jintArray begin_month, jintArray begin_day, jintArray begin_hour, jintArray begin_minute, jintArray end_year, jintArray end_month, jintArray end_day, jintArray end_hour, jintArray end_minute) {
		
		UFR_STATUS status;

		jint *credit_ = env->GetIntArrayElements(credit, 0);
		jint *begin_year_ = env->GetIntArrayElements(begin_year, 0);
		jint *begin_month_ = env->GetIntArrayElements(begin_month, 0);
		jint *begin_day_ = env->GetIntArrayElements(begin_day, 0);
		jint *begin_hour_ = env->GetIntArrayElements(begin_hour, 0);
		jint *begin_minute_ = env->GetIntArrayElements(begin_minute, 0);
		jint *end_year_ = env->GetIntArrayElements(end_year, 0);
		jint *end_month_ = env->GetIntArrayElements(end_month, 0);
		jint *end_day_ = env->GetIntArrayElements(end_day, 0);
		jint *end_hour_ = env->GetIntArrayElements(end_hour, 0);
		jint *end_minute_ = env->GetIntArrayElements(end_minute, 0);
		status = ais_get_credit_and_period_validity((int32_t *)credit_,(uint32_t *)begin_year_,(uint32_t *)begin_month_,(uint32_t *)begin_day_,(uint32_t *)begin_hour_,(uint32_t *)begin_minute_,(uint32_t *)end_year_,(uint32_t *)end_month_,(uint32_t *)end_day_,(uint32_t *)end_hour_,(uint32_t *)end_minute_);

		env->ReleaseIntArrayElements(credit,credit_, 0);
		env->ReleaseIntArrayElements(begin_year,begin_year_, 0);
		env->ReleaseIntArrayElements(begin_month,begin_month_, 0);
		env->ReleaseIntArrayElements(begin_day,begin_day_, 0);
		env->ReleaseIntArrayElements(begin_hour,begin_hour_, 0);
		env->ReleaseIntArrayElements(begin_minute,begin_minute_, 0);
		env->ReleaseIntArrayElements(end_year,end_year_, 0);
		env->ReleaseIntArrayElements(end_month,end_month_, 0);
		env->ReleaseIntArrayElements(end_day,end_day_, 0);
		env->ReleaseIntArrayElements(end_hour,end_hour_, 0);
		env->ReleaseIntArrayElements(end_minute,end_minute_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ais_1set_1credit_1and_1period_1validity(JNIEnv *env, jobject instance, jint credit, jint begin_year, jint begin_month, jint begin_day, jint begin_hour, jint begin_minute, jint end_year, jint end_month, jint end_day, jint end_hour, jint end_minute) {
		
		UFR_STATUS status;

		status = ais_set_credit_and_period_validity((int32_t)credit,(uint32_t)begin_year,(uint32_t)begin_month,(uint32_t)begin_day,(uint32_t)begin_hour,(uint32_t)begin_minute,(uint32_t)end_year,(uint32_t)end_month,(uint32_t)end_day,(uint32_t)end_hour,(uint32_t)end_minute);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ais_1set_1right_1type_1record(JNIEnv *env, jobject instance, jbyte record_number, jbyte right_record_type,  jbyteArray right_data) {
		
		UFR_STATUS status;

		jbyte *right_data_ = env->GetByteArrayElements(right_data, 0);
		status = ais_set_right_type_record((uint8_t)record_number,(uint8_t)right_record_type,(uint8_t *)right_data_);

		env->ReleaseByteArrayElements(right_data,right_data_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ais_1get_1right_1type_1record(JNIEnv *env, jobject instance, jbyte record_number, jbyteArray right_record_type,  jbyteArray right_data) {
		
		UFR_STATUS status;

		jbyte *right_record_type_ = env->GetByteArrayElements(right_record_type, 0);
		jbyte *right_data_ = env->GetByteArrayElements(right_data, 0);
		status = ais_get_right_type_record((uint8_t)record_number,(uint8_t *)right_record_type_,(uint8_t *)right_data_);

		env->ReleaseByteArrayElements(right_record_type,right_record_type_, 0);
		env->ReleaseByteArrayElements(right_data,right_data_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ais_1set_1right_1record_1type_1max_1daily_1counter(JNIEnv *env, jobject instance, jbyte record_number, jshort first_reader_nr, jshort last_reader_nr, jbyte start_hour, jbyte start_minute, jbyte end_hour, jbyte end_minute,  jbyteArray days, jbyte max_daily_counter) {
		
		UFR_STATUS status;

		jbyte *days_ = env->GetByteArrayElements(days, 0);
		status = ais_set_right_record_type_max_daily_counter((uint8_t)record_number,(uint16_t)first_reader_nr,(uint16_t)last_reader_nr,(uint8_t)start_hour,(uint8_t)start_minute,(uint8_t)end_hour,(uint8_t)end_minute,(uint8_t *)days_,(uint8_t)max_daily_counter);

		env->ReleaseByteArrayElements(days,days_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ais_1get_1right_1record_1type_1max_1daily_1counter(JNIEnv *env, jobject instance, jbyte record_number, jshortArray first_reader_nr, jshortArray last_reader_nr, jbyteArray start_hour, jbyteArray start_minute, jbyteArray end_hour, jbyteArray end_minute,  jbyteArray days, jbyteArray max_daily_counter) {
		
		UFR_STATUS status;

		jshort *first_reader_nr_ = env->GetShortArrayElements(first_reader_nr, 0);
		jshort *last_reader_nr_ = env->GetShortArrayElements(last_reader_nr, 0);
		jbyte *start_hour_ = env->GetByteArrayElements(start_hour, 0);
		jbyte *start_minute_ = env->GetByteArrayElements(start_minute, 0);
		jbyte *end_hour_ = env->GetByteArrayElements(end_hour, 0);
		jbyte *end_minute_ = env->GetByteArrayElements(end_minute, 0);
		jbyte *days_ = env->GetByteArrayElements(days, 0);
		jbyte *max_daily_counter_ = env->GetByteArrayElements(max_daily_counter, 0);
		status = ais_get_right_record_type_max_daily_counter((uint8_t)record_number,(uint16_t *)first_reader_nr_,(uint16_t *)last_reader_nr_,(uint8_t *)start_hour_,(uint8_t *)start_minute_,(uint8_t *)end_hour_,(uint8_t *)end_minute_,(uint8_t *)days_,(uint8_t *)max_daily_counter_);

		env->ReleaseShortArrayElements(first_reader_nr,first_reader_nr_, 0);
		env->ReleaseShortArrayElements(last_reader_nr,last_reader_nr_, 0);
		env->ReleaseByteArrayElements(start_hour,start_hour_, 0);
		env->ReleaseByteArrayElements(start_minute,start_minute_, 0);
		env->ReleaseByteArrayElements(end_hour,end_hour_, 0);
		env->ReleaseByteArrayElements(end_minute,end_minute_, 0);
		env->ReleaseByteArrayElements(days,days_, 0);
		env->ReleaseByteArrayElements(max_daily_counter,max_daily_counter_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_UfrXrcLockOn(JNIEnv *env, jobject instance, jshort pulse_duration) {
		
		UFR_STATUS status;

		status = UfrXrcLockOn((uint16_t)pulse_duration);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_UfrXrcRelayState(JNIEnv *env, jobject instance, jbyte state) {
		
		UFR_STATUS status;

		status = UfrXrcRelayState((uint8_t)state);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_UfrXrcGetIoState(JNIEnv *env, jobject instance, jbyteArray intercom, jbyteArray door, jbyteArray relay_state) {
		
		UFR_STATUS status;

		jbyte *intercom_ = env->GetByteArrayElements(intercom, 0);
		jbyte *door_ = env->GetByteArrayElements(door, 0);
		jbyte *relay_state_ = env->GetByteArrayElements(relay_state, 0);
		status = UfrXrcGetIoState((uint8_t *)intercom_,(uint8_t *)door_,(uint8_t *)relay_state_);

		env->ReleaseByteArrayElements(intercom,intercom_, 0);
		env->ReleaseByteArrayElements(door,door_, 0);
		env->ReleaseByteArrayElements(relay_state,relay_state_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_UfrRedLightControl(JNIEnv *env, jobject instance, jbyte light_status) {
		
		UFR_STATUS status;

		status = UfrRedLightControl((uint8_t)light_status);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_UfrRgbLightControl(JNIEnv *env, jobject instance, jbyte red, jbyte green, jbyte blue, jbyte intensity, jbyte enable) {
		
		UFR_STATUS status;

		status = UfrRgbLightControl((uint8_t)red,(uint8_t)green,(uint8_t)blue,(uint8_t)intensity,(uint8_t)enable);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_UfrSetBadSelectCardNrMax(JNIEnv *env, jobject instance, jbyte bad_select_nr_max) {
		
		UFR_STATUS status;

		status = UfrSetBadSelectCardNrMax((uint8_t)bad_select_nr_max);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_UfrGetBadSelectCardNrMax(JNIEnv *env, jobject instance, jbyteArray bad_select_nr_max) {
		
		UFR_STATUS status;

		jbyte *bad_select_nr_max_ = env->GetByteArrayElements(bad_select_nr_max, 0);
		status = UfrGetBadSelectCardNrMax((uint8_t *)bad_select_nr_max_);

		env->ReleaseByteArrayElements(bad_select_nr_max,bad_select_nr_max_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_UfrEnterSleepMode(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = UfrEnterSleepMode();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_UfrLeaveSleepMode(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = UfrLeaveSleepMode();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_AutoSleepSet(JNIEnv *env, jobject instance, jbyte seconds_wait) {
		
		UFR_STATUS status;

		status = AutoSleepSet((uint8_t)seconds_wait);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_AutoSleepGet(JNIEnv *env, jobject instance, jbyteArray seconds_wait) {
		
		UFR_STATUS status;

		jbyte *seconds_wait_ = env->GetByteArrayElements(seconds_wait, 0);
		status = AutoSleepGet((uint8_t *)seconds_wait_);

		env->ReleaseByteArrayElements(seconds_wait,seconds_wait_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetSpeedPermanently(JNIEnv *env, jobject instance, jbyte tx_speed, jbyte rx_speed) {
		
		UFR_STATUS status;

		status = SetSpeedPermanently((uint8_t)tx_speed,(uint8_t)rx_speed);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetSpeedParameters(JNIEnv *env, jobject instance, jbyteArray tx_speed, jbyteArray rx_speed) {
		
		UFR_STATUS status;

		jbyte *tx_speed_ = env->GetByteArrayElements(tx_speed, 0);
		jbyte *rx_speed_ = env->GetByteArrayElements(rx_speed, 0);
		status = GetSpeedParameters((uint8_t *)tx_speed_,(uint8_t *)rx_speed_);

		env->ReleaseByteArrayElements(tx_speed,tx_speed_, 0);
		env->ReleaseByteArrayElements(rx_speed,rx_speed_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetDisplayData(JNIEnv *env, jobject instance,  jbyteArray display_data, jbyte data_length) {
		
		UFR_STATUS status;

		jbyte *display_data_ = env->GetByteArrayElements(display_data, 0);
		status = SetDisplayData((uint8_t *)display_data_,(uint8_t)data_length);

		env->ReleaseByteArrayElements(display_data,display_data_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetSpeakerFrequency(JNIEnv *env, jobject instance, jshort frequency) {
		
		UFR_STATUS status;

		status = SetSpeakerFrequency((uint16_t)frequency);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetDisplayIntensity(JNIEnv *env, jobject instance, jbyte intensity) {
		
		UFR_STATUS status;

		status = SetDisplayIntensity((uint8_t)intensity);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetDisplayIntensity(JNIEnv *env, jobject instance, jbyteArray intensity) {
		
		UFR_STATUS status;

		jbyte *intensity_ = env->GetByteArrayElements(intensity, 0);
		status = GetDisplayIntensity((uint8_t *)intensity_);

		env->ReleaseByteArrayElements(intensity,intensity_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetISO14443_14_1Mode(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = SetISO14443_4_Mode();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1i_1block_1transceive(JNIEnv *env, jobject instance, jbyte chaining, jbyte timeout, jbyte block_length,  jbyteArray snd_data_array, jintArray rcv_length,  jbyteArray rcv_data_array, jintArray ufr_status) {
		
		UFR_STATUS status;

		jbyte *snd_data_array_ = env->GetByteArrayElements(snd_data_array, 0);
		jint *rcv_length_ = env->GetIntArrayElements(rcv_length, 0);
		jbyte *rcv_data_array_ = env->GetByteArrayElements(rcv_data_array, 0);
		jint *ufr_status_ = env->GetIntArrayElements(ufr_status, 0);
		status = uFR_i_block_transceive((uint8_t)chaining,(uint8_t)timeout,(uint8_t)block_length,(uint8_t *)snd_data_array_,(size_t *)rcv_length_,(uint8_t *)rcv_data_array_,(uint32_t *)ufr_status_);

		env->ReleaseByteArrayElements(snd_data_array,snd_data_array_, 0);
		env->ReleaseIntArrayElements(rcv_length,rcv_length_, 0);
		env->ReleaseByteArrayElements(rcv_data_array,rcv_data_array_, 0);
		env->ReleaseIntArrayElements(ufr_status,ufr_status_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1APDU_1Transceive(JNIEnv *env, jobject instance, jbyte cls, jbyte ins, jbyte p1, jbyte p2,  jbyteArray data_out, jbyte data_out_len,  jbyteArray data_in, jint max_data_in_len, jintArray response_len, jbyte send_le,  jbyteArray apdu_status) {
		
		UFR_STATUS status;

		jbyte *data_out_ = env->GetByteArrayElements(data_out, 0);
		jbyte *data_in_ = env->GetByteArrayElements(data_in, 0);
		jint *response_len_ = env->GetIntArrayElements(response_len, 0);
		jbyte *apdu_status_ = env->GetByteArrayElements(apdu_status, 0);
		status = uFR_APDU_Transceive((uint8_t)cls,(uint8_t)ins,(uint8_t)p1,(uint8_t)p2,(uint8_t *)data_out_,(uint8_t)data_out_len,(uint8_t *)data_in_,(uint32_t)max_data_in_len,(uint32_t *)response_len_,(uint8_t)send_le,(uint8_t *)apdu_status_);

		env->ReleaseByteArrayElements(data_out,data_out_, 0);
		env->ReleaseByteArrayElements(data_in,data_in_, 0);
		env->ReleaseIntArrayElements(response_len,response_len_, 0);
		env->ReleaseByteArrayElements(apdu_status,apdu_status_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_APDUHexStrTransceive(JNIEnv *env, jobject instance,  jstring c_apdu,  jstring r_apdu) {
		
		UFR_STATUS status;
		const char *c_apdu_ = env->GetStringUTFChars(c_apdu, 0);
		const char *r_apdu_ = env->GetStringUTFChars(r_apdu, 0);

		status = APDUHexStrTransceive((const char *)c_apdu_,(char **)r_apdu_);

		env->ReleaseStringUTFChars(c_apdu, c_apdu_);
		env->ReleaseStringUTFChars(r_apdu, r_apdu_);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_APDUPlainTransceive(JNIEnv *env, jobject instance,  jbyteArray c_apdu, jint c_apdu_len,  jbyteArray r_apdu, jintArray r_apdu_len) {
		
		UFR_STATUS status;

		jbyte *c_apdu_ = env->GetByteArrayElements(c_apdu, 0);
		jbyte *r_apdu_ = env->GetByteArrayElements(r_apdu, 0);
		jint *r_apdu_len_ = env->GetIntArrayElements(r_apdu_len, 0);
		status = APDUPlainTransceive((uint8_t *)c_apdu_,(uint32_t)c_apdu_len,(uint8_t *)r_apdu_,(uint32_t *)r_apdu_len_);

		env->ReleaseByteArrayElements(c_apdu,c_apdu_, 0);
		env->ReleaseByteArrayElements(r_apdu,r_apdu_, 0);
		env->ReleaseIntArrayElements(r_apdu_len,r_apdu_len_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_APDUTransceive(JNIEnv *env, jobject instance, jbyte cls, jbyte ins, jbyte p1, jbyte p2,  jbyteArray data_out, jint Nc,  jbyteArray data_in, jintArray Ne, jbyte send_le,  jbyteArray apdu_status) {
		
		UFR_STATUS status;

		jbyte *data_out_ = env->GetByteArrayElements(data_out, 0);
		jbyte *data_in_ = env->GetByteArrayElements(data_in, 0);
		jint *Ne_ = env->GetIntArrayElements(Ne, 0);
		jbyte *apdu_status_ = env->GetByteArrayElements(apdu_status, 0);
		status = APDUTransceive((uint8_t)cls,(uint8_t)ins,(uint8_t)p1,(uint8_t)p2,(uint8_t *)data_out_,(uint32_t)Nc,(uint8_t *)data_in_,(uint32_t *)Ne_,(uint8_t)send_le,(uint8_t *)apdu_status_);

		env->ReleaseByteArrayElements(data_out,data_out_, 0);
		env->ReleaseByteArrayElements(data_in,data_in_, 0);
		env->ReleaseIntArrayElements(Ne,Ne_, 0);
		env->ReleaseByteArrayElements(apdu_status,apdu_status_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_i_1block_1trans_1rcv_1chain(JNIEnv *env, jobject instance, jbyte chaining, jbyte timeout, jbyte block_length,  jbyteArray snd_data_array, jbyteArray rcv_length,  jbyteArray rcv_data_array, jbyteArray rcv_chained, jintArray ufr_status) {
		
		UFR_STATUS status;

		jbyte *snd_data_array_ = env->GetByteArrayElements(snd_data_array, 0);
		jbyte *rcv_length_ = env->GetByteArrayElements(rcv_length, 0);
		jbyte *rcv_data_array_ = env->GetByteArrayElements(rcv_data_array, 0);
		jbyte *rcv_chained_ = env->GetByteArrayElements(rcv_chained, 0);
		jint *ufr_status_ = env->GetIntArrayElements(ufr_status, 0);
		status = i_block_trans_rcv_chain((uint8_t)chaining,(uint8_t)timeout,(uint8_t)block_length,(uint8_t *)snd_data_array_,(uint8_t *)rcv_length_,(uint8_t *)rcv_data_array_,(uint8_t *)rcv_chained_,(uint32_t *)ufr_status_);

		env->ReleaseByteArrayElements(snd_data_array,snd_data_array_, 0);
		env->ReleaseByteArrayElements(rcv_length,rcv_length_, 0);
		env->ReleaseByteArrayElements(rcv_data_array,rcv_data_array_, 0);
		env->ReleaseByteArrayElements(rcv_chained,rcv_chained_, 0);
		env->ReleaseIntArrayElements(ufr_status,ufr_status_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_r_1block_1transceive(JNIEnv *env, jobject instance, jbyte ack, jbyte timeout, jbyteArray rcv_length,  jbyteArray rcv_data_array, jbyteArray rcv_chained, jintArray ufr_status) {
		
		UFR_STATUS status;

		jbyte *rcv_length_ = env->GetByteArrayElements(rcv_length, 0);
		jbyte *rcv_data_array_ = env->GetByteArrayElements(rcv_data_array, 0);
		jbyte *rcv_chained_ = env->GetByteArrayElements(rcv_chained, 0);
		jint *ufr_status_ = env->GetIntArrayElements(ufr_status, 0);
		status = r_block_transceive((uint8_t)ack,(uint8_t)timeout,(uint8_t *)rcv_length_,(uint8_t *)rcv_data_array_,(uint8_t *)rcv_chained_,(uint32_t *)ufr_status_);

		env->ReleaseByteArrayElements(rcv_length,rcv_length_, 0);
		env->ReleaseByteArrayElements(rcv_data_array,rcv_data_array_, 0);
		env->ReleaseByteArrayElements(rcv_chained,rcv_chained_, 0);
		env->ReleaseIntArrayElements(ufr_status,ufr_status_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_s_1block_1deselect(JNIEnv *env, jobject instance, jbyte timeout) {
		
		UFR_STATUS status;
		
		status = s_block_deselect((uint8_t)timeout);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_card_1transceive(JNIEnv *env, jobject instance, jbyte card_activate, jbyte card_halted, jbyte tx_crc, jbyte rx_crc, jbyte crypto1, jint timeout,  jbyteArray tx_data, jbyte tx_data_len,  jbyteArray rx_data, jbyteArray rx_data_len) {
		
		UFR_STATUS status;

		jbyte *tx_data_ = env->GetByteArrayElements(tx_data, 0);
		jbyte *rx_data_ = env->GetByteArrayElements(rx_data, 0);
		jbyte *rx_data_len_ = env->GetByteArrayElements(rx_data_len, 0);
		status = card_transceive((uint8_t)card_activate,(uint8_t)card_halted,(uint8_t)tx_crc,(uint8_t)rx_crc,(uint8_t)crypto1,(uint32_t)timeout,(uint8_t *)tx_data_,(uint8_t)tx_data_len,(uint8_t *)rx_data_,(uint8_t *)rx_data_len_);

		env->ReleaseByteArrayElements(tx_data,tx_data_, 0);
		env->ReleaseByteArrayElements(rx_data,rx_data_, 0);
		env->ReleaseByteArrayElements(rx_data_len,rx_data_len_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_card_1transceive_1mode_1start(JNIEnv *env, jobject instance, jbyte tx_crc, jbyte rx_crc, jint rf_timeout, jint uart_timeout) {
		
		UFR_STATUS status;

		status = card_transceive_mode_start((uint8_t)tx_crc,(uint8_t)rx_crc,(uint32_t)rf_timeout,(uint32_t)uart_timeout);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_card_1transceive_1mode_1stop(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = card_transceive_mode_stop();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_card_1halt_1enable(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = card_halt_enable();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uart_1transceive(JNIEnv *env, jobject instance,  jbyteArray send_data, jbyte send_len,  jbyteArray rcv_data, jint bytes_to_receive, jintArray rcv_len) {
		
		UFR_STATUS status;

		jbyte *send_data_ = env->GetByteArrayElements(send_data, 0);
		jbyte *rcv_data_ = env->GetByteArrayElements(rcv_data, 0);
		jint *rcv_len_ = env->GetIntArrayElements(rcv_len, 0);
		status = uart_transceive((uint8_t *)send_data_,(uint8_t)send_len,(uint8_t *)rcv_data_,(uint32_t)bytes_to_receive,(uint32_t *)rcv_len_);

		env->ReleaseByteArrayElements(send_data,send_data_, 0);
		env->ReleaseByteArrayElements(rcv_data,rcv_data_, 0);
		env->ReleaseIntArrayElements(rcv_len,rcv_len_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_open_1ISO7816_1interface(JNIEnv *env, jobject instance,  jbyteArray atr_data, jbyteArray atr_len) {
		
		UFR_STATUS status;

		jbyte *atr_data_ = env->GetByteArrayElements(atr_data, 0);
		jbyte *atr_len_ = env->GetByteArrayElements(atr_len, 0);
		status = open_ISO7816_interface((uint8_t *)atr_data_,(uint8_t *)atr_len_);

		env->ReleaseByteArrayElements(atr_data,atr_data_, 0);
		env->ReleaseByteArrayElements(atr_len,atr_len_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_APDU_1switch_1to_1ISO7816_1interface(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = APDU_switch_to_ISO7816_interface();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_close_1ISO7816_1interface_1no_1APDU(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = close_ISO7816_interface_no_APDU();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_close_1ISO7816_1interface_1APDU_1ISO14443_4(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = close_ISO7816_interface_APDU_ISO14443_4();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_APDU_1switch_1to_1ISO14443_14_1interface(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = APDU_switch_to_ISO14443_4_interface();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_APDU_1switch_1off_1from_1ISO7816_1interface(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = APDU_switch_off_from_ISO7816_interface();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_DES_1to_1AES_1key_1type(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = DES_to_AES_key_type();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_AES_1to_1DES_1key_1type(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = AES_to_DES_key_type();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1GetDesfireUid(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr,  jbyteArray card_uid, jbyteArray card_uid_len, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
		jbyte *card_uid_len_ = env->GetByteArrayElements(card_uid_len, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_GetDesfireUid((uint8_t)aes_key_nr,(uint32_t)aid,(uint32_t)aid_key_nr,(uint8_t *)card_uid_,(uint8_t *)card_uid_len_,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(card_uid,card_uid_, 0);
		env->ReleaseByteArrayElements(card_uid_len,card_uid_len_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1GetDesfireUid_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr,  jbyteArray card_uid, jbyteArray card_uid_len, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
		jbyte *card_uid_len_ = env->GetByteArrayElements(card_uid_len, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_GetDesfireUid_PK((uint8_t *)aes_key_ext_,(uint32_t)aid,(uint32_t)aid_key_nr,(uint8_t *)card_uid_,(uint8_t *)card_uid_len_,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(aes_key_ext,aes_key_ext_, 0);
		env->ReleaseByteArrayElements(card_uid,card_uid_, 0);
		env->ReleaseByteArrayElements(card_uid_len,card_uid_len_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireFreeMem(JNIEnv *env, jobject instance, jintArray free_mem_byte, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jint *free_mem_byte_ = env->GetIntArrayElements(free_mem_byte, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireFreeMem((uint32_t *)free_mem_byte_,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseIntArrayElements(free_mem_byte,free_mem_byte_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireFormatCard(JNIEnv *env, jobject instance, jbyte aes_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireFormatCard((uint8_t)aes_key_nr,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireFormatCard_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireFormatCard_PK((uint8_t *)aes_key_ext_,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(aes_key_ext,aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateStdDataFile(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte file_id, jint file_size, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireCreateStdDataFile((uint8_t)aes_key_nr,(uint32_t)aid,(uint8_t)file_id,(uint32_t)file_size,(uint8_t)read_key_no,(uint8_t)write_key_no,(uint8_t)read_write_key_no,(uint8_t)change_key_no,(uint8_t)communication_settings,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateStdDataFile_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte file_id, jint file_size, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireCreateStdDataFile_PK((uint8_t *)aes_key_ext_,(uint32_t)aid,(uint8_t)file_id,(uint32_t)file_size,(uint8_t)read_key_no,(uint8_t)write_key_no,(uint8_t)read_write_key_no,(uint8_t)change_key_no,(uint8_t)communication_settings,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(aes_key_ext,aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateStdDataFile_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte file_id, jint file_size, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireCreateStdDataFile_no_auth((uint32_t)aid,(uint8_t)file_id,(uint32_t)file_size,(uint8_t)read_key_no,(uint8_t)write_key_no,(uint8_t)read_write_key_no,(uint8_t)change_key_no,(uint8_t)communication_settings,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteFile(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireDeleteFile((uint8_t)aes_key_nr,(uint32_t)aid,(uint8_t)file_id,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteFile_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireDeleteFile_PK((uint8_t *)aes_key_ext_,(uint32_t)aid,(uint8_t)file_id,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(aes_key_ext,aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteFile_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireDeleteFile_no_auth((uint32_t)aid,(uint8_t)file_id,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateAesApplication(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireCreateAesApplication((uint8_t)aes_key_nr,(uint32_t)aid,(uint8_t)setting,(uint8_t)max_key_no,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateAesApplication_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireCreateAesApplication_PK((uint8_t *)aes_key_ext_,(uint32_t)aid,(uint8_t)setting,(uint8_t)max_key_no,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(aes_key_ext,aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateAesApplication_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireCreateAesApplication_no_auth((uint32_t)aid,(uint8_t)setting,(uint8_t)max_key_no,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireDeleteApplication((uint8_t)aes_key_nr,(uint32_t)aid,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireDeleteApplication_PK((uint8_t *)aes_key_ext_,(uint32_t)aid,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(aes_key_ext,aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireSetConfiguration(JNIEnv *env, jobject instance, jbyte aes_key_nr, jbyte random_uid, jbyte format_disable, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireSetConfiguration((uint8_t)aes_key_nr,(uint8_t)random_uid,(uint8_t)format_disable,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireSetConfiguration_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jbyte random_uid, jbyte format_disable, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireSetConfiguration_PK((uint8_t *)aes_key_ext_,(uint8_t)random_uid,(uint8_t)format_disable,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(aes_key_ext,aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetKeySettings(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyteArray setting, jbyteArray max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *setting_ = env->GetByteArrayElements(setting, 0);
		jbyte *max_key_no_ = env->GetByteArrayElements(max_key_no, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireGetKeySettings((uint8_t)aes_key_nr,(uint32_t)aid,(uint8_t *)setting_,(uint8_t *)max_key_no_,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(setting,setting_, 0);
		env->ReleaseByteArrayElements(max_key_no,max_key_no_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetKeySettings_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyteArray setting, jbyteArray max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jbyte *setting_ = env->GetByteArrayElements(setting, 0);
		jbyte *max_key_no_ = env->GetByteArrayElements(max_key_no, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireGetKeySettings_PK((uint8_t *)aes_key_ext_,(uint32_t)aid,(uint8_t *)setting_,(uint8_t *)max_key_no_,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(aes_key_ext,aes_key_ext_, 0);
		env->ReleaseByteArrayElements(setting,setting_, 0);
		env->ReleaseByteArrayElements(max_key_no,max_key_no_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeKeySettings(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte setting, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireChangeKeySettings((uint8_t)aes_key_nr,(uint32_t)aid,(uint8_t)setting,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeKeySettings_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte setting, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireChangeKeySettings_PK((uint8_t *)aes_key_ext_,(uint32_t)aid,(uint8_t)setting,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(aes_key_ext,aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeAesKey(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_no_auth,  jbyteArray new_aes_key, jbyte aid_key_no,  jbyteArray old_aes_key, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *new_aes_key_ = env->GetByteArrayElements(new_aes_key, 0);
		jbyte *old_aes_key_ = env->GetByteArrayElements(old_aes_key, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireChangeAesKey((uint8_t)aes_key_nr,(uint32_t)aid,(uint32_t)aid_key_no_auth,(uint8_t *)new_aes_key_,(uint32_t)aid_key_no,(uint8_t *)old_aes_key_,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(new_aes_key,new_aes_key_, 0);
		env->ReleaseByteArrayElements(old_aes_key,old_aes_key_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeAesKey_1A(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_no_auth, jbyte new_aes_key_nr, jbyte aid_key_no, jbyte old_aes_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireChangeAesKey_A((uint8_t)aes_key_nr,(uint32_t)aid,(uint32_t)aid_key_no_auth,(uint8_t)new_aes_key_nr,(uint32_t)aid_key_no,(uint8_t)old_aes_key_nr,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeAesKey_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_no_auth,  jbyteArray new_aes_key, jbyte aid_key_no,  jbyteArray old_aes_key, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jbyte *new_aes_key_ = env->GetByteArrayElements(new_aes_key, 0);
		jbyte *old_aes_key_ = env->GetByteArrayElements(old_aes_key, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireChangeAesKey_PK((uint8_t *)aes_key_ext_,(uint32_t)aid,(uint32_t)aid_key_no_auth,(uint8_t *)new_aes_key_,(uint32_t)aid_key_no,(uint8_t *)old_aes_key_,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(aes_key_ext,aes_key_ext_, 0);
		env->ReleaseByteArrayElements(new_aes_key,new_aes_key_, 0);
		env->ReleaseByteArrayElements(old_aes_key,old_aes_key_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteAesKey(JNIEnv *env, jobject instance, jbyte aes_key_no,  jbyteArray aes_key) {
		
		UFR_STATUS status;

		jbyte *aes_key_ = env->GetByteArrayElements(aes_key, 0);
		status = uFR_int_DesfireWriteAesKey((uint8_t)aes_key_no,(uint8_t *)aes_key_);

		env->ReleaseByteArrayElements(aes_key,aes_key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadStdDataFile(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireReadStdDataFile((uint8_t)aes_key_nr,(uint32_t)aid,(uint32_t)aid_key_nr,(uint8_t)file_id,(uint16_t)offset,(uint16_t)data_length,(uint8_t)communication_settings,(uint8_t *)data_,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadStdDataFile_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireReadStdDataFile_PK((uint8_t *)aes_key_ext_,(uint32_t)aid,(uint32_t)aid_key_nr,(uint8_t)file_id,(uint16_t)offset,(uint16_t)data_length,(uint8_t)communication_settings,(uint8_t *)data_,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(aes_key_ext,aes_key_ext_, 0);
		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadStdDataFile_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireReadStdDataFile_no_auth((uint32_t)aid,(uint32_t)aid_key_nr,(uint8_t)file_id,(uint16_t)offset,(uint16_t)data_length,(uint8_t)communication_settings,(uint8_t *)data_,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteStdDataFile(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireWriteStdDataFile((uint8_t)aes_key_nr,(uint32_t)aid,(uint32_t)aid_key_nr,(uint8_t)file_id,(uint16_t)offset,(uint16_t)data_length,(uint8_t)communication_settings,(uint8_t *)data_,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteStdDataFile_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireWriteStdDataFile_PK((uint8_t *)aes_key_ext_,(uint32_t)aid,(uint32_t)aid_key_nr,(uint8_t)file_id,(uint16_t)offset,(uint16_t)data_length,(uint8_t)communication_settings,(uint8_t *)data_,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(aes_key_ext,aes_key_ext_, 0);
		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteStdDataFile_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireWriteStdDataFile_no_auth((uint32_t)aid,(uint32_t)aid_key_nr,(uint8_t)file_id,(uint16_t)offset,(uint16_t)data_length,(uint8_t)communication_settings,(uint8_t *)data_,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateValueFile(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte file_id, jint lower_limit, jint upper_limit, jint value, jbyte limited_credit_enabled, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireCreateValueFile((uint8_t)aes_key_nr,(uint32_t)aid,(uint8_t)file_id,(int32_t)lower_limit,(int32_t)upper_limit,(int32_t)value,(uint8_t)limited_credit_enabled,(uint8_t)read_key_no,(uint8_t)write_key_no,(uint8_t)read_write_key_no,(uint8_t)change_key_no,(uint8_t)communication_settings,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateValueFile_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte file_id, jint lower_limit, jint upper_limit, jint value, jbyte limited_credit_enabled, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireCreateValueFile_PK((uint8_t *)aes_key_ext_,(uint32_t)aid,(uint8_t)file_id,(int32_t)lower_limit,(int32_t)upper_limit,(int32_t)value,(uint8_t)limited_credit_enabled,(uint8_t)read_key_no,(uint8_t)write_key_no,(uint8_t)read_write_key_no,(uint8_t)change_key_no,(uint8_t)communication_settings,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(aes_key_ext,aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateValueFile_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte file_id, jint lower_limit, jint upper_limit, jint value, jbyte limited_credit_enabled, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireCreateValueFile_no_auth((uint32_t)aid,(uint8_t)file_id,(int32_t)lower_limit,(int32_t)upper_limit,(int32_t)value,(uint8_t)limited_credit_enabled,(uint8_t)read_key_no,(uint8_t)write_key_no,(uint8_t)read_write_key_no,(uint8_t)change_key_no,(uint8_t)communication_settings,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadValueFile(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jintArray value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jint *value_ = env->GetIntArrayElements(value, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireReadValueFile((uint8_t)aes_key_nr,(uint32_t)aid,(uint32_t)aid_key_nr,(uint8_t)file_id,(uint8_t)communication_settings,(int32_t *)value_,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseIntArrayElements(value,value_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadValueFile_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jintArray value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jint *value_ = env->GetIntArrayElements(value, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireReadValueFile_PK((uint8_t *)aes_key_ext_,(uint32_t)aid,(uint32_t)aid_key_nr,(uint8_t)file_id,(uint8_t)communication_settings,(int32_t *)value_,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(aes_key_ext,aes_key_ext_, 0);
		env->ReleaseIntArrayElements(value,value_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadValueFile_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jintArray value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jint *value_ = env->GetIntArrayElements(value, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireReadValueFile_no_auth((uint32_t)aid,(uint32_t)aid_key_nr,(uint8_t)file_id,(uint8_t)communication_settings,(int32_t *)value_,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseIntArrayElements(value,value_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireIncreaseValueFile((uint8_t)aes_key_nr,(uint32_t)aid,(uint32_t)aid_key_nr,(uint8_t)file_id,(uint8_t)communication_settings,(uint32_t)value,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireIncreaseValueFile_PK((uint8_t *)aes_key_ext_,(uint32_t)aid,(uint32_t)aid_key_nr,(uint8_t)file_id,(uint8_t)communication_settings,(uint32_t)value,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(aes_key_ext,aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireIncreaseValueFile_no_auth((uint32_t)aid,(uint32_t)aid_key_nr,(uint8_t)file_id,(uint8_t)communication_settings,(uint32_t)value,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireDecreaseValueFile((uint8_t)aes_key_nr,(uint32_t)aid,(uint32_t)aid_key_nr,(uint8_t)file_id,(uint8_t)communication_settings,(uint32_t)value,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireDecreaseValueFile_PK((uint8_t *)aes_key_ext_,(uint32_t)aid,(uint32_t)aid_key_nr,(uint8_t)file_id,(uint8_t)communication_settings,(uint32_t)value,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(aes_key_ext,aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		status = uFR_int_DesfireDecreaseValueFile_no_auth((uint32_t)aid,(uint32_t)aid_key_nr,(uint8_t)file_id,(uint8_t)communication_settings,(uint32_t)value,(uint16_t *)card_status_,(uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status,card_status_, 0);
		env->ReleaseShortArrayElements(exec_time,exec_time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GreenLedBlinkingTurnOn(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = GreenLedBlinkingTurnOn();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GreenLedBlinkingTurnOff(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = GreenLedBlinkingTurnOff();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetRfAnalogRegistersTypeA(JNIEnv *env, jobject instance, jbyte ThresholdMinLevel, jbyte ThresholdCollLevel, jbyte RFLevelAmp, jbyte RxGain, jbyte RFLevel) {
		
		UFR_STATUS status;

		status = SetRfAnalogRegistersTypeA((uint8_t)ThresholdMinLevel,(uint8_t)ThresholdCollLevel,(uint8_t)RFLevelAmp,(uint8_t)RxGain,(uint8_t)RFLevel);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetRfAnalogRegistersTypeB(JNIEnv *env, jobject instance, jbyte ThresholdMinLevel, jbyte ThresholdCollLevel, jbyte RFLevelAmp, jbyte RxGain, jbyte RFLevel) {
		
		UFR_STATUS status;

		status = SetRfAnalogRegistersTypeB((uint8_t)ThresholdMinLevel,(uint8_t)ThresholdCollLevel,(uint8_t)RFLevelAmp,(uint8_t)RxGain,(uint8_t)RFLevel);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetRfAnalogRegistersISO14443_1212(JNIEnv *env, jobject instance, jbyte ThresholdMinLevel, jbyte ThresholdCollLevel, jbyte RFLevelAmp, jbyte RxGain, jbyte RFLevel) {
		
		UFR_STATUS status;

		status = SetRfAnalogRegistersISO14443_212((uint8_t)ThresholdMinLevel,(uint8_t)ThresholdCollLevel,(uint8_t)RFLevelAmp,(uint8_t)RxGain,(uint8_t)RFLevel);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetRfAnalogRegistersISO14443_1424(JNIEnv *env, jobject instance, jbyte ThresholdMinLevel, jbyte ThresholdCollLevel, jbyte RFLevelAmp, jbyte RxGain, jbyte RFLevel) {
		
		UFR_STATUS status;

		status = SetRfAnalogRegistersISO14443_424((uint8_t)ThresholdMinLevel,(uint8_t)ThresholdCollLevel,(uint8_t)RFLevelAmp,(uint8_t)RxGain,(uint8_t)RFLevel);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetRfAnalogRegistersTypeADefault(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = SetRfAnalogRegistersTypeADefault();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetRfAnalogRegistersTypeBDefault(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = SetRfAnalogRegistersTypeBDefault();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetRfAnalogRegistersISO14443_1212Default(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = SetRfAnalogRegistersISO14443_212Default();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetRfAnalogRegistersISO14443_1424Default(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = SetRfAnalogRegistersISO14443_424Default();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetRfAnalogRegistersTypeA(JNIEnv *env, jobject instance, jbyteArray ThresholdMinLevel, jbyteArray ThresholdCollLevel, jbyteArray RFLevelAmp, jbyteArray RxGain, jbyteArray RFLevel) {
		
		UFR_STATUS status;

		jbyte *ThresholdMinLevel_ = env->GetByteArrayElements(ThresholdMinLevel, 0);
		jbyte *ThresholdCollLevel_ = env->GetByteArrayElements(ThresholdCollLevel, 0);
		jbyte *RFLevelAmp_ = env->GetByteArrayElements(RFLevelAmp, 0);
		jbyte *RxGain_ = env->GetByteArrayElements(RxGain, 0);
		jbyte *RFLevel_ = env->GetByteArrayElements(RFLevel, 0);
		status = GetRfAnalogRegistersTypeA((uint8_t *)ThresholdMinLevel_,(uint8_t *)ThresholdCollLevel_,(uint8_t *)RFLevelAmp_,(uint8_t *)RxGain_,(uint8_t *)RFLevel_);

		env->ReleaseByteArrayElements(ThresholdMinLevel,ThresholdMinLevel_, 0);
		env->ReleaseByteArrayElements(ThresholdCollLevel,ThresholdCollLevel_, 0);
		env->ReleaseByteArrayElements(RFLevelAmp,RFLevelAmp_, 0);
		env->ReleaseByteArrayElements(RxGain,RxGain_, 0);
		env->ReleaseByteArrayElements(RFLevel,RFLevel_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetRfAnalogRegistersTypeB(JNIEnv *env, jobject instance, jbyteArray ThresholdMinLevel, jbyteArray ThresholdCollLevel, jbyteArray RFLevelAmp, jbyteArray RxGain, jbyteArray RFLevel) {
		
		UFR_STATUS status;

		jbyte *ThresholdMinLevel_ = env->GetByteArrayElements(ThresholdMinLevel, 0);
		jbyte *ThresholdCollLevel_ = env->GetByteArrayElements(ThresholdCollLevel, 0);
		jbyte *RFLevelAmp_ = env->GetByteArrayElements(RFLevelAmp, 0);
		jbyte *RxGain_ = env->GetByteArrayElements(RxGain, 0);
		jbyte *RFLevel_ = env->GetByteArrayElements(RFLevel, 0);
		status = GetRfAnalogRegistersTypeB((uint8_t *)ThresholdMinLevel_,(uint8_t *)ThresholdCollLevel_,(uint8_t *)RFLevelAmp_,(uint8_t *)RxGain_,(uint8_t *)RFLevel_);

		env->ReleaseByteArrayElements(ThresholdMinLevel,ThresholdMinLevel_, 0);
		env->ReleaseByteArrayElements(ThresholdCollLevel,ThresholdCollLevel_, 0);
		env->ReleaseByteArrayElements(RFLevelAmp,RFLevelAmp_, 0);
		env->ReleaseByteArrayElements(RxGain,RxGain_, 0);
		env->ReleaseByteArrayElements(RFLevel,RFLevel_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetRfAnalogRegistersISO14443_1212(JNIEnv *env, jobject instance, jbyteArray ThresholdMinLevel, jbyteArray ThresholdCollLevel, jbyteArray RFLevelAmp, jbyteArray RxGain, jbyteArray RFLevel) {
		
		UFR_STATUS status;

		jbyte *ThresholdMinLevel_ = env->GetByteArrayElements(ThresholdMinLevel, 0);
		jbyte *ThresholdCollLevel_ = env->GetByteArrayElements(ThresholdCollLevel, 0);
		jbyte *RFLevelAmp_ = env->GetByteArrayElements(RFLevelAmp, 0);
		jbyte *RxGain_ = env->GetByteArrayElements(RxGain, 0);
		jbyte *RFLevel_ = env->GetByteArrayElements(RFLevel, 0);
		status = GetRfAnalogRegistersISO14443_212((uint8_t *)ThresholdMinLevel_,(uint8_t *)ThresholdCollLevel_,(uint8_t *)RFLevelAmp_,(uint8_t *)RxGain_,(uint8_t *)RFLevel_);

		env->ReleaseByteArrayElements(ThresholdMinLevel,ThresholdMinLevel_, 0);
		env->ReleaseByteArrayElements(ThresholdCollLevel,ThresholdCollLevel_, 0);
		env->ReleaseByteArrayElements(RFLevelAmp,RFLevelAmp_, 0);
		env->ReleaseByteArrayElements(RxGain,RxGain_, 0);
		env->ReleaseByteArrayElements(RFLevel,RFLevel_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetRfAnalogRegistersISO14443_1424(JNIEnv *env, jobject instance, jbyteArray ThresholdMinLevel, jbyteArray ThresholdCollLevel, jbyteArray RFLevelAmp, jbyteArray RxGain, jbyteArray RFLevel) {
		
		UFR_STATUS status;

		jbyte *ThresholdMinLevel_ = env->GetByteArrayElements(ThresholdMinLevel, 0);
		jbyte *ThresholdCollLevel_ = env->GetByteArrayElements(ThresholdCollLevel, 0);
		jbyte *RFLevelAmp_ = env->GetByteArrayElements(RFLevelAmp, 0);
		jbyte *RxGain_ = env->GetByteArrayElements(RxGain, 0);
		jbyte *RFLevel_ = env->GetByteArrayElements(RFLevel, 0);
		status = GetRfAnalogRegistersISO14443_424((uint8_t *)ThresholdMinLevel_,(uint8_t *)ThresholdCollLevel_,(uint8_t *)RFLevelAmp_,(uint8_t *)RxGain_,(uint8_t *)RFLevel_);

		env->ReleaseByteArrayElements(ThresholdMinLevel,ThresholdMinLevel_, 0);
		env->ReleaseByteArrayElements(ThresholdCollLevel,ThresholdCollLevel_, 0);
		env->ReleaseByteArrayElements(RFLevelAmp,RFLevelAmp_, 0);
		env->ReleaseByteArrayElements(RxGain,RxGain_, 0);
		env->ReleaseByteArrayElements(RFLevel,RFLevel_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetRfAnalogRegistersTypeATrans(JNIEnv *env, jobject instance, jbyte ThresholdMinLevel, jbyte ThresholdCollLevel, jbyte RFLevelAmp, jbyte RxGain, jbyte RFLevel, jbyte CWGsNOn, jbyte ModGsNOn, jbyte CWGsP, jbyte CWGsNOff, jbyte ModGsNOff) {
		
		UFR_STATUS status;

		status = SetRfAnalogRegistersTypeATrans((uint8_t)ThresholdMinLevel,(uint8_t)ThresholdCollLevel,(uint8_t)RFLevelAmp,(uint8_t)RxGain,(uint8_t)RFLevel,(uint8_t)CWGsNOn,(uint8_t)ModGsNOn,(uint8_t)CWGsP,(uint8_t)CWGsNOff,(uint8_t)ModGsNOff);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SetRfAnalogRegistersTypeBTrans(JNIEnv *env, jobject instance, jbyte ThresholdMinLevel, jbyte ThresholdCollLevel, jbyte RFLevelAmp, jbyte RxGain, jbyte RFLevel, jbyte CWGsNOn, jbyte ModGsNOn, jbyte CWGsP, jbyte ModGsP) {
		
		UFR_STATUS status;

		status = SetRfAnalogRegistersTypeBTrans((uint8_t)ThresholdMinLevel,(uint8_t)ThresholdCollLevel,(uint8_t)RFLevelAmp,(uint8_t)RxGain,(uint8_t)RFLevel,(uint8_t)CWGsNOn,(uint8_t)ModGsNOn,(uint8_t)CWGsP,(uint8_t)ModGsP);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetRfAnalogRegistersTypeATrans(JNIEnv *env, jobject instance, jbyteArray ThresholdMinLevel, jbyteArray ThresholdCollLevel, jbyteArray RFLevelAmp, jbyteArray RxGain, jbyteArray RFLevel, jbyteArray CWGsNOn, jbyteArray ModGsNOn, jbyteArray CWGsP, jbyteArray CWGsNOff, jbyteArray ModGsNOff) {
		
		UFR_STATUS status;

		jbyte *ThresholdMinLevel_ = env->GetByteArrayElements(ThresholdMinLevel, 0);
		jbyte *ThresholdCollLevel_ = env->GetByteArrayElements(ThresholdCollLevel, 0);
		jbyte *RFLevelAmp_ = env->GetByteArrayElements(RFLevelAmp, 0);
		jbyte *RxGain_ = env->GetByteArrayElements(RxGain, 0);
		jbyte *RFLevel_ = env->GetByteArrayElements(RFLevel, 0);
		jbyte *CWGsNOn_ = env->GetByteArrayElements(CWGsNOn, 0);
		jbyte *ModGsNOn_ = env->GetByteArrayElements(ModGsNOn, 0);
		jbyte *CWGsP_ = env->GetByteArrayElements(CWGsP, 0);
		jbyte *CWGsNOff_ = env->GetByteArrayElements(CWGsNOff, 0);
		jbyte *ModGsNOff_ = env->GetByteArrayElements(ModGsNOff, 0);
		status = GetRfAnalogRegistersTypeATrans((uint8_t *)ThresholdMinLevel_,(uint8_t *)ThresholdCollLevel_,(uint8_t *)RFLevelAmp_,(uint8_t *)RxGain_,(uint8_t *)RFLevel_,(uint8_t *)CWGsNOn_,(uint8_t *)ModGsNOn_,(uint8_t *)CWGsP_,(uint8_t *)CWGsNOff_,(uint8_t *)ModGsNOff_);

		env->ReleaseByteArrayElements(ThresholdMinLevel,ThresholdMinLevel_, 0);
		env->ReleaseByteArrayElements(ThresholdCollLevel,ThresholdCollLevel_, 0);
		env->ReleaseByteArrayElements(RFLevelAmp,RFLevelAmp_, 0);
		env->ReleaseByteArrayElements(RxGain,RxGain_, 0);
		env->ReleaseByteArrayElements(RFLevel,RFLevel_, 0);
		env->ReleaseByteArrayElements(CWGsNOn,CWGsNOn_, 0);
		env->ReleaseByteArrayElements(ModGsNOn,ModGsNOn_, 0);
		env->ReleaseByteArrayElements(CWGsP,CWGsP_, 0);
		env->ReleaseByteArrayElements(CWGsNOff,CWGsNOff_, 0);
		env->ReleaseByteArrayElements(ModGsNOff,ModGsNOff_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetRfAnalogRegistersTypeBTrans(JNIEnv *env, jobject instance, jbyteArray ThresholdMinLevel, jbyteArray ThresholdCollLevel, jbyteArray RFLevelAmp, jbyteArray RxGain, jbyteArray RFLevel, jbyteArray CWGsNOn, jbyteArray ModGsNOn, jbyteArray CWGsP, jbyteArray ModGsP) {
		
		UFR_STATUS status;

		jbyte *ThresholdMinLevel_ = env->GetByteArrayElements(ThresholdMinLevel, 0);
		jbyte *ThresholdCollLevel_ = env->GetByteArrayElements(ThresholdCollLevel, 0);
		jbyte *RFLevelAmp_ = env->GetByteArrayElements(RFLevelAmp, 0);
		jbyte *RxGain_ = env->GetByteArrayElements(RxGain, 0);
		jbyte *RFLevel_ = env->GetByteArrayElements(RFLevel, 0);
		jbyte *CWGsNOn_ = env->GetByteArrayElements(CWGsNOn, 0);
		jbyte *ModGsNOn_ = env->GetByteArrayElements(ModGsNOn, 0);
		jbyte *CWGsP_ = env->GetByteArrayElements(CWGsP, 0);
		jbyte *ModGsP_ = env->GetByteArrayElements(ModGsP, 0);
		status = GetRfAnalogRegistersTypeBTrans((uint8_t *)ThresholdMinLevel_,(uint8_t *)ThresholdCollLevel_,(uint8_t *)RFLevelAmp_,(uint8_t *)RxGain_,(uint8_t *)RFLevel_,(uint8_t *)CWGsNOn_,(uint8_t *)ModGsNOn_,(uint8_t *)CWGsP_,(uint8_t *)ModGsP_);

		env->ReleaseByteArrayElements(ThresholdMinLevel,ThresholdMinLevel_, 0);
		env->ReleaseByteArrayElements(ThresholdCollLevel,ThresholdCollLevel_, 0);
		env->ReleaseByteArrayElements(RFLevelAmp,RFLevelAmp_, 0);
		env->ReleaseByteArrayElements(RxGain,RxGain_, 0);
		env->ReleaseByteArrayElements(RFLevel,RFLevel_, 0);
		env->ReleaseByteArrayElements(CWGsNOn,CWGsNOn_, 0);
		env->ReleaseByteArrayElements(ModGsNOn,ModGsNOn_, 0);
		env->ReleaseByteArrayElements(CWGsP,CWGsP_, 0);
		env->ReleaseByteArrayElements(ModGsP,ModGsP_, 0);
		return status;
	}
	/* JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_CheckBootFirmware(JNIEnv *env, jobject instance, jbyteArray exec_location) {
		
		UFR_STATUS status;

		jbyte *exec_location_ = env->GetByteArrayElements(exec_location, 0);
		status = CheckBootFirmware((uint8_t *)exec_location_);

		env->ReleaseByteArrayElements(exec_location,exec_location_, 0);
		return status;
	}*/
	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_FastFlashCheck(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = FastFlashCheck();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_DefaultBaudrateFlashCheck(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = DefaultBaudrateFlashCheck();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SAM_1get_1version_1raw(JNIEnv *env, jobject instance,  jbyteArray data, jbyteArray length) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jbyte *length_ = env->GetByteArrayElements(length, 0);
		status = SAM_get_version_raw((uint8_t *)data_,(uint8_t *)length_);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseByteArrayElements(length,length_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_SAM_1get_1version(JNIEnv *env, jobject instance, jintArray sam_type,  jbyteArray sam_uid) {
		
		UFR_STATUS status;

		jint *sam_type_ = env->GetIntArrayElements(sam_type, 0);
		jbyte *sam_uid_ = env->GetByteArrayElements(sam_uid, 0);
		status = SAM_get_version((SAM_HW_TYPE *)sam_type_,(uint8_t *)sam_uid_);

		env->ReleaseIntArrayElements(sam_type,sam_type_, 0);
		env->ReleaseByteArrayElements(sam_uid,sam_uid_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1WritePerso(JNIEnv *env, jobject instance, jshort address,  jbyteArray data) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		status = MFP_WritePerso((uint16_t)address,(uint8_t *)data_);

		env->ReleaseByteArrayElements(data,data_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1CommitPerso(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = MFP_CommitPerso();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1PersonalizationMinimal(JNIEnv *env, jobject instance,  jbyteArray card_master_key,  jbyteArray card_config_key,  jbyteArray level_2_switch_key,  jbyteArray level_3_switch_key,  jbyteArray level_1_auth_key,  jbyteArray select_vc_key,  jbyteArray prox_chk_key,  jbyteArray vc_poll_enc_key,  jbyteArray vc_poll_mac_key) {
		
		UFR_STATUS status;

		jbyte *card_master_key_ = env->GetByteArrayElements(card_master_key, 0);
		jbyte *card_config_key_ = env->GetByteArrayElements(card_config_key, 0);
		jbyte *level_2_switch_key_ = env->GetByteArrayElements(level_2_switch_key, 0);
		jbyte *level_3_switch_key_ = env->GetByteArrayElements(level_3_switch_key, 0);
		jbyte *level_1_auth_key_ = env->GetByteArrayElements(level_1_auth_key, 0);
		jbyte *select_vc_key_ = env->GetByteArrayElements(select_vc_key, 0);
		jbyte *prox_chk_key_ = env->GetByteArrayElements(prox_chk_key, 0);
		jbyte *vc_poll_enc_key_ = env->GetByteArrayElements(vc_poll_enc_key, 0);
		jbyte *vc_poll_mac_key_ = env->GetByteArrayElements(vc_poll_mac_key, 0);
		status = MFP_PersonalizationMinimal((uint8_t *)card_master_key_,(uint8_t *)card_config_key_,(uint8_t *)level_2_switch_key_,(uint8_t *)level_3_switch_key_,(uint8_t *)level_1_auth_key_,(uint8_t *)select_vc_key_,(uint8_t *)prox_chk_key_,(uint8_t *)vc_poll_enc_key_,(uint8_t *)vc_poll_mac_key_);

		env->ReleaseByteArrayElements(card_master_key,card_master_key_, 0);
		env->ReleaseByteArrayElements(card_config_key,card_config_key_, 0);
		env->ReleaseByteArrayElements(level_2_switch_key,level_2_switch_key_, 0);
		env->ReleaseByteArrayElements(level_3_switch_key,level_3_switch_key_, 0);
		env->ReleaseByteArrayElements(level_1_auth_key,level_1_auth_key_, 0);
		env->ReleaseByteArrayElements(select_vc_key,select_vc_key_, 0);
		env->ReleaseByteArrayElements(prox_chk_key,prox_chk_key_, 0);
		env->ReleaseByteArrayElements(vc_poll_enc_key,vc_poll_enc_key_, 0);
		env->ReleaseByteArrayElements(vc_poll_mac_key,vc_poll_mac_key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1SwitchToSecurityLevel3(JNIEnv *env, jobject instance, jbyte key_index) {
		
		UFR_STATUS status;

		status = MFP_SwitchToSecurityLevel3((uint8_t)key_index);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1SwitchToSecurityLevel3_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key) {
		
		UFR_STATUS status;

		jbyte *aes_key_ = env->GetByteArrayElements(aes_key, 0);
		status = MFP_SwitchToSecurityLevel3_PK((uint8_t *)aes_key_);

		env->ReleaseByteArrayElements(aes_key,aes_key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1AesAuthSecurityLevel1(JNIEnv *env, jobject instance, jbyte key_index) {
		
		UFR_STATUS status;

		status = MFP_AesAuthSecurityLevel1((uint8_t)key_index);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1AesAuthSecurityLevel1_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key) {
		
		UFR_STATUS status;

		jbyte *aes_key_ = env->GetByteArrayElements(aes_key, 0);
		status = MFP_AesAuthSecurityLevel1_PK((uint8_t *)aes_key_);

		env->ReleaseByteArrayElements(aes_key,aes_key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1ChangeMasterKey(JNIEnv *env, jobject instance, jbyte key_index,  jbyteArray new_key) {
		
		UFR_STATUS status;

		jbyte *new_key_ = env->GetByteArrayElements(new_key, 0);
		status = MFP_ChangeMasterKey((uint8_t)key_index,(uint8_t *)new_key_);

		env->ReleaseByteArrayElements(new_key,new_key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1ChangeMasterKey_1PK(JNIEnv *env, jobject instance,  jbyteArray old_key,  jbyteArray new_key) {
		
		UFR_STATUS status;

		jbyte *old_key_ = env->GetByteArrayElements(old_key, 0);
		jbyte *new_key_ = env->GetByteArrayElements(new_key, 0);
		status = MFP_ChangeMasterKey_PK((uint8_t *)old_key_,(uint8_t *)new_key_);

		env->ReleaseByteArrayElements(old_key,old_key_, 0);
		env->ReleaseByteArrayElements(new_key,new_key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1ChangeMasterKeySamKey(JNIEnv *env, jobject instance, jbyte key_index,  jbyte new_key_index) {
		
		UFR_STATUS status;

		status = MFP_ChangeMasterKeySamKey((uint8_t)key_index,(uint8_t)new_key_index);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1ChangeConfigurationKey(JNIEnv *env, jobject instance, jbyte key_index,  jbyteArray new_key) {
		
		UFR_STATUS status;

		jbyte *new_key_ = env->GetByteArrayElements(new_key, 0);
		status = MFP_ChangeConfigurationKey((uint8_t)key_index,(uint8_t *)new_key_);

		env->ReleaseByteArrayElements(new_key,new_key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1ChangeConfigurationKey_1PK(JNIEnv *env, jobject instance,  jbyteArray old_key,  jbyteArray new_key) {
		
		UFR_STATUS status;

		jbyte *old_key_ = env->GetByteArrayElements(old_key, 0);
		jbyte *new_key_ = env->GetByteArrayElements(new_key, 0);
		status = MFP_ChangeConfigurationKey_PK((uint8_t *)old_key_,(uint8_t *)new_key_);

		env->ReleaseByteArrayElements(old_key,old_key_, 0);
		env->ReleaseByteArrayElements(new_key,new_key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1FieldConfigurationSet(JNIEnv *env, jobject instance, jbyte configuration_key_index, jbyte rid_use, jbyte prox_check_use) {
		
		UFR_STATUS status;

		status = MFP_FieldConfigurationSet((uint8_t)configuration_key_index,(uint8_t)rid_use,(uint8_t)prox_check_use);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1FieldConfigurationSet_1PK(JNIEnv *env, jobject instance,  jbyteArray configuration_key, jbyte rid_use, jbyte prox_check_use) {
		
		UFR_STATUS status;

		jbyte *configuration_key_ = env->GetByteArrayElements(configuration_key, 0);
		status = MFP_FieldConfigurationSet_PK((uint8_t *)configuration_key_,(uint8_t)rid_use,(uint8_t)prox_check_use);

		env->ReleaseByteArrayElements(configuration_key,configuration_key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1ChangeSectorKey(JNIEnv *env, jobject instance, jbyte sector_nr, jbyte auth_mode, jbyte key_index,  jbyteArray new_key) {
		
		UFR_STATUS status;

		jbyte *new_key_ = env->GetByteArrayElements(new_key, 0);
		status = MFP_ChangeSectorKey((uint8_t)sector_nr,(uint8_t)auth_mode,(uint8_t)key_index,(uint8_t *)new_key_);

		env->ReleaseByteArrayElements(new_key,new_key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1ChangeSectorKey_1PK(JNIEnv *env, jobject instance, jbyte sector_nr, jbyte auth_mode,  jbyteArray old_key,  jbyteArray new_key) {
		
		UFR_STATUS status;

		jbyte *old_key_ = env->GetByteArrayElements(old_key, 0);
		jbyte *new_key_ = env->GetByteArrayElements(new_key, 0);
		status = MFP_ChangeSectorKey_PK((uint8_t)sector_nr,(uint8_t)auth_mode,(uint8_t *)old_key_,(uint8_t *)new_key_);

		env->ReleaseByteArrayElements(old_key,old_key_, 0);
		env->ReleaseByteArrayElements(new_key,new_key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1ChangeSectorKeySamKey(JNIEnv *env, jobject instance, jbyte sector_nr, jbyte auth_mode, jbyte key_index,  jbyte new_key_index) {
		
		UFR_STATUS status;

		status = MFP_ChangeSectorKeySamKey((uint8_t)sector_nr,(uint8_t)auth_mode,(uint8_t)key_index,(uint8_t)new_key_index);

		return status;
	} 

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1GetUid(JNIEnv *env, jobject instance, jbyte key_index_vc_poll_enc_key, jbyte key_index_vc_poll_mac_key,  jbyteArray uid, jbyteArray uid_len) {
		
		UFR_STATUS status;

		jbyte *uid_ = env->GetByteArrayElements(uid, 0);
		jbyte *uid_len_ = env->GetByteArrayElements(uid_len, 0);
		status = MFP_GetUid((uint8_t)key_index_vc_poll_enc_key,(uint8_t)key_index_vc_poll_mac_key,(uint8_t *)uid_,(uint8_t *)uid_len_);

		env->ReleaseByteArrayElements(uid,uid_, 0);
		env->ReleaseByteArrayElements(uid_len,uid_len_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1GetUid_1PK(JNIEnv *env, jobject instance,  jbyteArray vc_poll_enc_key,  jbyteArray vc_poll_mac_key,  jbyteArray uid, jbyteArray uid_len) {
		
		UFR_STATUS status;

		jbyte *vc_poll_enc_key_ = env->GetByteArrayElements(vc_poll_enc_key, 0);
		jbyte *vc_poll_mac_key_ = env->GetByteArrayElements(vc_poll_mac_key, 0);
		jbyte *uid_ = env->GetByteArrayElements(uid, 0);
		jbyte *uid_len_ = env->GetByteArrayElements(uid_len, 0);
		status = MFP_GetUid_PK((uint8_t *)vc_poll_enc_key_,(uint8_t *)vc_poll_mac_key_,(uint8_t *)uid_,(uint8_t *)uid_len_);

		env->ReleaseByteArrayElements(vc_poll_enc_key,vc_poll_enc_key_, 0);
		env->ReleaseByteArrayElements(vc_poll_mac_key,vc_poll_mac_key_, 0);
		env->ReleaseByteArrayElements(uid,uid_, 0);
		env->ReleaseByteArrayElements(uid_len,uid_len_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1ChangeVcPollingEncKey(JNIEnv *env, jobject instance, jbyte configuration_key_index,  jbyteArray new_key) {
		
		UFR_STATUS status;

		jbyte *new_key_ = env->GetByteArrayElements(new_key, 0);
		status = MFP_ChangeVcPollingEncKey((uint8_t)configuration_key_index,(uint8_t *)new_key_);

		env->ReleaseByteArrayElements(new_key,new_key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1ChangeVcPollingEncKey_1PK(JNIEnv *env, jobject instance,  jbyteArray configuration_key,  jbyteArray new_key) {
		
		UFR_STATUS status;

		jbyte *configuration_key_ = env->GetByteArrayElements(configuration_key, 0);
		jbyte *new_key_ = env->GetByteArrayElements(new_key, 0);
		status = MFP_ChangeVcPollingEncKey_PK((uint8_t *)configuration_key_,(uint8_t *)new_key_);

		env->ReleaseByteArrayElements(configuration_key,configuration_key_, 0);
		env->ReleaseByteArrayElements(new_key,new_key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1ChangeVcPollingMacKey(JNIEnv *env, jobject instance, jbyte configuration_key_index,  jbyteArray new_key) {
		
		UFR_STATUS status;

		jbyte *new_key_ = env->GetByteArrayElements(new_key, 0);
		status = MFP_ChangeVcPollingMacKey((uint8_t)configuration_key_index,(uint8_t *)new_key_);

		env->ReleaseByteArrayElements(new_key,new_key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_MFP_1ChangeVcPollingMacKey_1PK(JNIEnv *env, jobject instance,  jbyteArray configuration_key,  jbyteArray new_key) {
		
		UFR_STATUS status;

		jbyte *configuration_key_ = env->GetByteArrayElements(configuration_key, 0);
		jbyte *new_key_ = env->GetByteArrayElements(new_key, 0);
		status = MFP_ChangeVcPollingMacKey_PK((uint8_t *)configuration_key_,(uint8_t *)new_key_);

		env->ReleaseByteArrayElements(configuration_key,configuration_key_, 0);
		env->ReleaseByteArrayElements(new_key,new_key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ULC_1ExternalAuth_1PK(JNIEnv *env, jobject instance,  jbyteArray key) {
		
		UFR_STATUS status;

		jbyte *key_ = env->GetByteArrayElements(key, 0);
		status = ULC_ExternalAuth_PK((uint8_t *)key_);

		env->ReleaseByteArrayElements(key,key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ULC_1write_13des_1key_1no_1auth(JNIEnv *env, jobject instance,  jbyteArray new_3des_key) {
		
		UFR_STATUS status;

		jbyte *new_3des_key_ = env->GetByteArrayElements(new_3des_key, 0);
		status = ULC_write_3des_key_no_auth((uint8_t *)new_3des_key_);

		env->ReleaseByteArrayElements(new_3des_key,new_3des_key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ULC_1write_13des_1key_1factory_1key(JNIEnv *env, jobject instance,  jbyteArray new_3des_key) {
		
		UFR_STATUS status;

		jbyte *new_3des_key_ = env->GetByteArrayElements(new_3des_key, 0);
		status = ULC_write_3des_key_factory_key((uint8_t *)new_3des_key_);

		env->ReleaseByteArrayElements(new_3des_key,new_3des_key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ULC_1write_13des_1key(JNIEnv *env, jobject instance,  jbyteArray new_3des_key,  jbyteArray old_3des_key) {
		
		UFR_STATUS status;

		jbyte *new_3des_key_ = env->GetByteArrayElements(new_3des_key, 0);
		jbyte *old_3des_key_ = env->GetByteArrayElements(old_3des_key, 0);
		status = ULC_write_3des_key((uint8_t *)new_3des_key_,(uint8_t *)old_3des_key_);

		env->ReleaseByteArrayElements(new_3des_key,new_3des_key_, 0);
		env->ReleaseByteArrayElements(old_3des_key,old_3des_key_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BalanceGet(JNIEnv *env, jobject instance,  jint auth_mode,  jbyteArray auth_value, jintArray credit) {
		
		UFR_STATUS status;

		jbyte *auth_value_ = env->GetByteArrayElements(auth_value, 0);
		jint *credit_ = env->GetIntArrayElements(credit, 0);
		status = BalanceGet((uint32_t)auth_mode,(uint8_t *)auth_value_, (int32_t*) credit_);

		env->ReleaseByteArrayElements(auth_value,auth_value_, 0);
		env->ReleaseIntArrayElements(credit,credit_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_BalanceSet(JNIEnv *env, jobject instance,  jint auth_mode,  jbyteArray auth_value, jint credit) {
		
		UFR_STATUS status;

		jbyte *auth_value_ = env->GetByteArrayElements(auth_value, 0);
		status = BalanceSet((uint32_t)auth_mode,(uint8_t *)auth_value_, (int32_t) credit);

		env->ReleaseByteArrayElements(auth_value,auth_value_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_EspSetDisplayData(JNIEnv *env, jobject instance, jbyteArray display_data, jint data_length, jshort duration) {
		
		UFR_STATUS status;

		jbyte *display_data_ = env->GetByteArrayElements(display_data, 0);
		status = EspSetDisplayData((uint8_t*)display_data_,(uint8_t)data_length, (uint16_t) duration);

		env->ReleaseByteArrayElements(display_data,display_data_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_EspReaderReset(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		status = EspReaderReset();

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_EspChangeReaderPassword(JNIEnv *env, jobject instance, jbyteArray old_password, jbyteArray new_password) {
		
		UFR_STATUS status;

		jbyte *old_password_ = env->GetByteArrayElements(old_password, 0);
		jbyte *new_password_ = env->GetByteArrayElements(new_password, 0);
		status = EspChangeReaderPassword((uint8_t*)old_password_,(uint8_t*)new_password_);

		env->ReleaseByteArrayElements(old_password,old_password_, 0);
		env->ReleaseByteArrayElements(new_password,new_password_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_EspReaderEepromWrite(JNIEnv *env, jobject instance, jbyteArray data, jint address, jint size, jbyteArray password) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jbyte *password_ = env->GetByteArrayElements(password, 0);
		status = EspReaderEepromWrite((uint8_t*)data_, (int)address, (int) size, (uint8_t*)password_);

		env->ReleaseByteArrayElements(data,data_, 0);
		env->ReleaseByteArrayElements(password,password_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_EspReaderEepromRead(JNIEnv *env, jobject instance, jbyteArray data, jint address, jint size) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		status = EspReaderEepromRead((uint8_t*)data, (int)address, (int) size);

		env->ReleaseByteArrayElements(data,data_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_EspGetReaderTime(JNIEnv *env, jobject instance, jbyteArray time) {
		
		UFR_STATUS status;

		jbyte *time_ = env->GetByteArrayElements(time, 0);
		status = EspGetReaderTime((uint8_t*)time_);

		env->ReleaseByteArrayElements(time,time_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_EspSetReaderTime(JNIEnv *env, jobject instance, jbyteArray password, jbyteArray time) {
		
		UFR_STATUS status;

		jbyte *time_ = env->GetByteArrayElements(time, 0);
		jbyte *password_ = env->GetByteArrayElements(password, 0);
		status = EspSetReaderTime((uint8_t*)password_, (uint8_t*)time_);

		env->ReleaseByteArrayElements(time,time_, 0);
		env->ReleaseByteArrayElements(password,password_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_EspSetIOState(JNIEnv *env, jobject instance, jbyte pin, jbyte state) {
		
		UFR_STATUS status;

		status = EspSetIOState((uint8_t)pin, (uint8_t)state);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_EspGetIOState(JNIEnv *env, jobject instance, jbyteArray state) {
		
		UFR_STATUS status;

		jbyte *state_ = env->GetByteArrayElements(state, 0);
		status = EspGetIOState((uint8_t*)state_);

		env->ReleaseByteArrayElements(state,state_, 0);
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_EspSetTransparentReader(JNIEnv *env, jobject instance, jbyte reader) {
		
		UFR_STATUS status;

		status = EspSetTransparentReader((uint8_t)reader);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_GetDllVersion(JNIEnv *env, jobject instance) {
		

		return GetDllVersion();
	}

	JNIEXPORT jstring JNICALL
	Java_com_dlogic_uFCoder_GetDllVersionStr(JNIEnv *env, jobject instance) {
		

		c_string returnValue = GetDllVersionStr();

		return env->NewStringUTF(returnValue);
	}

	JNIEXPORT jstring JNICALL
	Java_com_dlogic_uFCoder_UFR_1Status2String(JNIEnv *env, jobject instance, jint status) {
		
		
		c_string returnValue = UFR_Status2String((const UFR_STATUS)status);

		return env->NewStringUTF(returnValue);
	}

	JNIEXPORT jstring JNICALL
	 Java_com_dlogic_uFCoder_UFR_1DLCardType2String(JNIEnv *env, jobject instance, jbyte dl_type_code) {

		 

		 c_string returnValue = UFR_DLCardType2String((uint8_t)dl_type_code);

		 return env->NewStringUTF(returnValue);
	 }
	   JNIEXPORT jstring JNICALL
	  Java_com_dlogic_uFCoder_GetReaderDescription(JNIEnv *env, jobject instance) {

		  

		  c_string returnValue = GetReaderDescription();

		  return env->NewStringUTF(returnValue);
	  }
		JNIEXPORT jint JNICALL    Java_com_dlogic_uFCoder_OriginalityCheck(JNIEnv *env, jobject instance, jbyteArray signature, jbyteArray uid, jbyte uid_len, jbyte DlogicCardType) {
		
		UFR_STATUS status;

		jbyte *signature_ = env->GetByteArrayElements(signature, 0);
		jbyte *uid_ = env->GetByteArrayElements(uid, 0);
		status = OriginalityCheck((uint8_t*)signature_, (uint8_t*)uid_, (uint8_t) uid_len, (uint8_t) DlogicCardType);

		env->ReleaseByteArrayElements(signature,signature_, 0);
		env->ReleaseByteArrayElements(uid,uid_, 0);
		return status;
	  }

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteNdefRecord_1WiFi(JNIEnv *env, jobject instance,  jbyte ndef_storage,  jstring ssid, jbyte auth_type, jbyte encryption_type, jstring password) {
		
		UFR_STATUS status;
		
		const char *ssid_ = env->GetStringUTFChars(ssid, 0);
		const char *password_ = env->GetStringUTFChars(password, 0);
		
		status = WriteNdefRecord_WiFi((uint8_t)ndef_storage, (const char *)ssid_, (uint8_t)auth_type, (uint8_t)encryption_type, (const char *)password_);
		
		env->ReleaseStringUTFChars(ssid, ssid_);
		env->ReleaseStringUTFChars(password, password_);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteNdefRecord_1Bluetooth(JNIEnv *env, jobject instance,  jbyte ndef_storage,  jstring bt_mac_address) {
		
		UFR_STATUS status;
		
		const char *bt_mac_address_ = env->GetStringUTFChars(bt_mac_address, 0);
		
		status = WriteNdefRecord_Bluetooth((uint8_t)ndef_storage, (const char *)bt_mac_address_);
		
		env->ReleaseStringUTFChars(bt_mac_address, bt_mac_address_);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteNdefRecord_1SMS(JNIEnv *env, jobject instance,  jbyte ndef_storage,  jstring phone_number, jstring message) {
		
		UFR_STATUS status;
		
		const char *phone_number_= env->GetStringUTFChars(phone_number, 0);
		const char *message_= env->GetStringUTFChars(message, 0);
		
		status = WriteNdefRecord_SMS((uint8_t)ndef_storage, (const char *)phone_number_, (const char *)message_);
		
		env->ReleaseStringUTFChars(phone_number, phone_number_);
		env->ReleaseStringUTFChars(message, message_);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteNdefRecord_1Bitcoin(JNIEnv *env, jobject instance,  jbyte ndef_storage,  jstring bitcoin_address, jstring amount, jstring message) {
		
		UFR_STATUS status;
		
		const char *bitcoin_address_= env->GetStringUTFChars(bitcoin_address, 0);
		const char *amount_ = env->GetStringUTFChars(amount, 0);
		const char *message_= env->GetStringUTFChars(message, 0);
		
		status = WriteNdefRecord_Bitcoin((uint8_t)ndef_storage, (const char *)bitcoin_address_, (const char *)amount_, (const char *)message_);
		
		env->ReleaseStringUTFChars(bitcoin_address, bitcoin_address_);
		env->ReleaseStringUTFChars(amount, amount_);
		env->ReleaseStringUTFChars(message, message_);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteNdefRecord_1GeoLocation(JNIEnv *env, jobject instance,  jbyte ndef_storage,  jstring latitude, jstring longitude) {
		
		UFR_STATUS status;
		
		const char *latitude_= env->GetStringUTFChars(latitude, 0);
		const char *longitude_ = env->GetStringUTFChars(longitude, 0);
		
		status = WriteNdefRecord_GeoLocation((uint8_t)ndef_storage, (const char *)latitude_, (const char *)longitude_);
		
		env->ReleaseStringUTFChars(latitude, latitude_);
		env->ReleaseStringUTFChars(longitude, longitude_);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteNdefRecord_1NaviDestination(JNIEnv *env, jobject instance,  jbyte ndef_storage,  jstring destination) {
		
		UFR_STATUS status;
		
		const char *destination_= env->GetStringUTFChars(destination, 0);
		
		status = WriteNdefRecord_NaviDestination((uint8_t)ndef_storage, (const char *)destination_);
		
		env->ReleaseStringUTFChars(destination, destination_);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteNdefRecord_1Email(JNIEnv *env, jobject instance,  jbyte ndef_storage,  jstring email, jstring subject, jstring message) {
		
		UFR_STATUS status;
		
		const char *email_= env->GetStringUTFChars(email, 0);
		const char *subject_= env->GetStringUTFChars(subject, 0);
		const char *message_= env->GetStringUTFChars(message, 0);
		
		status = WriteNdefRecord_Email((uint8_t)ndef_storage, (const char *)email_, (const char *)subject_, (const char *)message_);
		
		env->ReleaseStringUTFChars(email, email_);
		env->ReleaseStringUTFChars(subject, subject_);
		env->ReleaseStringUTFChars(message, message_);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteNdefRecord_1Address(JNIEnv *env, jobject instance,  jbyte ndef_storage,  jstring address) {
		
		UFR_STATUS status;
		
		const char *address_= env->GetStringUTFChars(address, 0);
		
		status = WriteNdefRecord_Address((uint8_t)ndef_storage, (const char *)address_);
		
		env->ReleaseStringUTFChars(address, address_);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteNdefRecord_1AndroidApp(JNIEnv *env, jobject instance,  jbyte ndef_storage,  jstring package_name) {
		
		UFR_STATUS status;
		
		const char *package_name_ = env->GetStringUTFChars(package_name, 0);
		
		status = WriteNdefRecord_AndroidApp((uint8_t)ndef_storage, (const char *)package_name_);
		
		env->ReleaseStringUTFChars(package_name, package_name_);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteNdefRecord_1Text(JNIEnv *env, jobject instance,  jbyte ndef_storage,  jstring text) {
		
		UFR_STATUS status;
		
		const char *text_ = env->GetStringUTFChars(text, 0);
		
		status = WriteNdefRecord_Text((uint8_t)ndef_storage, (const char *)text_);
		
		env->ReleaseStringUTFChars(text, text_);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteNdefRecord_1StreetView(JNIEnv *env, jobject instance,  jbyte ndef_storage,  jstring latitude, jstring longitude) {
		
		UFR_STATUS status;
		
		const char *latitude_= env->GetStringUTFChars(latitude, 0);
		const char *longitude_ = env->GetStringUTFChars(longitude, 0);
		
		status = WriteNdefRecord_StreetView((uint8_t)ndef_storage, (const char *)latitude_, (const char *)longitude_);
		
		env->ReleaseStringUTFChars(latitude, latitude_);
		env->ReleaseStringUTFChars(longitude, longitude_);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteNdefRecord_1Skype(JNIEnv *env, jobject instance,  jbyte ndef_storage,  jstring user_name, jbyte action) {
		
		UFR_STATUS status;
		
		const char *user_name_ = env->GetStringUTFChars(user_name, 0);
		
		status = WriteNdefRecord_Skype((uint8_t)ndef_storage, (const char *)user_name_, (uint8_t)action);
		
		env->ReleaseStringUTFChars(user_name, user_name_);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteNdefRecord_1Whatsapp(JNIEnv *env, jobject instance,  jbyte ndef_storage,  jstring message) {
		
		UFR_STATUS status;
		
		const char *message_ = env->GetStringUTFChars(message, 0);
		
		status = WriteNdefRecord_Whatsapp((uint8_t)ndef_storage, (const char *)message_);
		
		env->ReleaseStringUTFChars(message, message_);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteNdefRecord_1Viber(JNIEnv *env, jobject instance,  jbyte ndef_storage,  jstring message) {
		
		UFR_STATUS status;
		
		const char *message_ = env->GetStringUTFChars(message, 0);
		
		status = WriteNdefRecord_Viber((uint8_t)ndef_storage, (const char *)message_);
		
		env->ReleaseStringUTFChars(message, message_);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteNdefRecord_1Contact(JNIEnv *env, jobject instance,  jbyte ndef_storage,  jstring name, jstring company, jstring address, jstring phone, jstring email, jstring website) {
		
		UFR_STATUS status;
		
		const char *name_ = env->GetStringUTFChars(name, 0);
		const char *company_ = env->GetStringUTFChars(company, 0);
		const char *address_ = env->GetStringUTFChars(address, 0);
		const char *phone_ = env->GetStringUTFChars(phone, 0);
		const char *email_ = env->GetStringUTFChars(email, 0);
		const char *website_ = env->GetStringUTFChars(website, 0);
		
		status = WriteNdefRecord_Contact((uint8_t)ndef_storage, (const char *)name_, (const char *)company_, (const char *)address_, (const char *)phone_, (const char *)email_, (const char *)website_);
		
		env->ReleaseStringUTFChars(name, name_);
		env->ReleaseStringUTFChars(company, company_);
		env->ReleaseStringUTFChars(address, address_);
		env->ReleaseStringUTFChars(phone, phone_);
		env->ReleaseStringUTFChars(email, email_);
		env->ReleaseStringUTFChars(website, website_);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_WriteNdefRecord_1Phone(JNIEnv *env, jobject instance,  jbyte ndef_storage,  jstring phone) {
		
		UFR_STATUS status;
		
		const char *phone_ = env->GetStringUTFChars(phone, 0);
		
		status = WriteNdefRecord_Phone((uint8_t)ndef_storage, (const char *)phone_);
		
		env->ReleaseStringUTFChars(phone, phone_);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNdefRecord_1WiFi(JNIEnv *env, jobject instance, jbyteArray ssid, jbyteArray auth_type, jbyteArray encryption_type, jbyteArray password) {
		
		UFR_STATUS status;
		
		jbyte *ssid_ = env->GetByteArrayElements(ssid, 0);
		jbyte *password_ = env->GetByteArrayElements(password, 0);
		jbyte *auth_type_ = env->GetByteArrayElements(auth_type, 0);
		jbyte *encryption_type_ = env->GetByteArrayElements(encryption_type, 0);
		
		status = ReadNdefRecord_WiFi((char *)ssid_, (char *)auth_type_, (char *)encryption_type_, (char *)password_);
		
		env->ReleaseByteArrayElements(ssid, ssid_, 0);
		env->ReleaseByteArrayElements(password, password_, 0);
		env->ReleaseByteArrayElements(auth_type, auth_type_, 0);
		env->ReleaseByteArrayElements(encryption_type, encryption_type_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNdefRecord_1Bluetooth(JNIEnv *env, jobject instance, jbyteArray bt_mac_address) {
		
		UFR_STATUS status;
		
		jbyte *bt_mac_address_ = env->GetByteArrayElements(bt_mac_address, 0);
		
		status = ReadNdefRecord_Bluetooth((char *)bt_mac_address_);
		
		env->ReleaseByteArrayElements(bt_mac_address, bt_mac_address_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNdefRecord_1SMS(JNIEnv *env, jobject instance, jbyteArray phone_number, jbyteArray message) {
		
		UFR_STATUS status;
		
		jbyte *phone_number_= env->GetByteArrayElements(phone_number, 0);
		jbyte *message_= env->GetByteArrayElements(message, 0);
		
		status = ReadNdefRecord_SMS((char *)phone_number_, (char *)message_);
		
		env->ReleaseByteArrayElements(phone_number, phone_number_, 0);
		env->ReleaseByteArrayElements(message, message_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNdefRecord_1Bitcoin(JNIEnv *env, jobject instance, jbyteArray bitcoin_address, jbyteArray amount, jbyteArray message) {
		
		UFR_STATUS status;
		
		 jbyte *bitcoin_address_= env->GetByteArrayElements(bitcoin_address, 0);
		 jbyte *amount_ = env->GetByteArrayElements(amount, 0);
		 jbyte *message_= env->GetByteArrayElements(message, 0);
		
		status = ReadNdefRecord_Bitcoin((char *)bitcoin_address_, (char *)amount_, (char *)message_);
		
		env->ReleaseByteArrayElements(bitcoin_address, bitcoin_address_, 0);
		env->ReleaseByteArrayElements(amount, amount_, 0);
		env->ReleaseByteArrayElements(message, message_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNdefRecord_1GeoLocation(JNIEnv *env, jobject instance,  jbyteArray latitude, jbyteArray longitude) {
		
		UFR_STATUS status;
		
		 jbyte *latitude_= env->GetByteArrayElements(latitude, 0);
		 jbyte *longitude_ = env->GetByteArrayElements(longitude, 0);
		
		status = ReadNdefRecord_GeoLocation((char *)latitude_, (char *)longitude_);
		
		env->ReleaseByteArrayElements(latitude, latitude_, 0);
		env->ReleaseByteArrayElements(longitude, longitude_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNdefRecord_1NaviDestination(JNIEnv *env, jobject instance,  jbyteArray destination) {
		
		UFR_STATUS status;
		
		jbyte *destination_= env->GetByteArrayElements(destination, 0);
		
		status = ReadNdefRecord_NaviDestination((char *)destination_);
		
		env->ReleaseByteArrayElements(destination, destination_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNdefRecord_1Email(JNIEnv *env, jobject instance,  jbyteArray email, jbyteArray subject, jbyteArray message) {
		
		UFR_STATUS status;
		
		 jbyte *email_= env->GetByteArrayElements(email, 0);
		 jbyte *subject_= env->GetByteArrayElements(subject, 0);
		 jbyte *message_= env->GetByteArrayElements(message, 0);
		
		status = ReadNdefRecord_Email((char *)email_, (char *)subject_, (char *)message_);
		
		env->ReleaseByteArrayElements(email, email_, 0);
		env->ReleaseByteArrayElements(subject, subject_, 0);
		env->ReleaseByteArrayElements(message, message_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNdefRecord_1Address(JNIEnv *env, jobject instance,  jbyteArray address) {
		
		UFR_STATUS status;
		
		jbyte *address_= env->GetByteArrayElements(address, 0);
		
		status = ReadNdefRecord_Address((char *)address_);
		
		env->ReleaseByteArrayElements(address, address_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNdefRecord_1AndroidApp(JNIEnv *env, jobject instance, jbyteArray package_name) {
		
		UFR_STATUS status;

		jbyte *package_name_ = env->GetByteArrayElements(package_name, 0);
		
		status = ReadNdefRecord_AndroidApp((char *)package_name_);

		env->ReleaseByteArrayElements(package_name, package_name_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNdefRecord_1Text(JNIEnv *env, jobject instance,  jbyteArray text) {
		
		UFR_STATUS status;
		
		jbyte *text_ = env->GetByteArrayElements(text, 0);
		
		status = ReadNdefRecord_Text((char *)text_);
		
		env->ReleaseByteArrayElements(text, text_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNdefRecord_1StreetView(JNIEnv *env, jobject instance,  jbyteArray latitude, jbyteArray longitude) {
		
		UFR_STATUS status;
		
		jbyte *latitude_= env->GetByteArrayElements(latitude, 0);
		jbyte *longitude_ = env->GetByteArrayElements(longitude, 0);
		
		status = ReadNdefRecord_StreetView((char *)latitude_, (char *)longitude_);
		
		env->ReleaseByteArrayElements(latitude, latitude_, 0);
		env->ReleaseByteArrayElements(longitude, longitude_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNdefRecord_1Skype(JNIEnv *env, jobject instance,  jbyteArray user_name, jbyteArray action) {
		
		UFR_STATUS status;
		
		jbyte *user_name_ = env->GetByteArrayElements(user_name, 0);
		jbyte *action_ = env->GetByteArrayElements(action, 0);
		
		status = ReadNdefRecord_Skype((char *)user_name_, (char *)action_);
		
		env->ReleaseByteArrayElements(user_name, user_name_, 0);
		env->ReleaseByteArrayElements(action, action_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNdefRecord_1Whatsapp(JNIEnv *env, jobject instance,  jbyteArray message) {
		
		UFR_STATUS status;
		
		jbyte *message_ = env->GetByteArrayElements(message, 0);
		
		status = ReadNdefRecord_Whatsapp((char *)message_);
		
		env->ReleaseByteArrayElements(message, message_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNdefRecord_1Viber(JNIEnv *env, jobject instance,  jbyteArray message) {
		
		UFR_STATUS status;
		
		jbyte *message_ = env->GetByteArrayElements(message, 0);
		
		status = ReadNdefRecord_Viber((char *)message_);
		
		env->ReleaseByteArrayElements(message, message_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNdefRecord_1Contact(JNIEnv *env, jobject instance,  jbyteArray vCard) {
		
		UFR_STATUS status;
		
		jbyte *vCard_ = env->GetByteArrayElements(vCard, 0);
		
		status = ReadNdefRecord_Contact((char *)vCard_);
		
		env->ReleaseByteArrayElements(vCard, vCard_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReadNdefRecord_1Phone(JNIEnv *env, jobject instance,  jbyteArray phone) {
		
		UFR_STATUS status;
		
		jbyte *phone_ = env->GetByteArrayElements(phone, 0);
		
		status = ReadNdefRecord_Phone((char *)phone_);
		
		env->ReleaseByteArrayElements(phone, phone_, 0);

		return status;
	}

	JNIEXPORT jstring JNICALL
	 Java_com_dlogic_uFCoder_ParseNdefMessage(JNIEnv *env, jobject instance,  jbyteArray type_record, jbyte type_length, jbyteArray payload, jint payload_length) {
		
		
		jbyte *type_record_ = env->GetByteArrayElements(type_record, 0);
		jbyte *payload_ = env->GetByteArrayElements(payload, 0);
		
		c_string returnValue = ParseNdefMessage((uint8_t *)type_record_, (uint8_t)type_length, (uint8_t *)payload_, (uint32_t)payload_length);
		
		env->ReleaseByteArrayElements(type_record, type_record_, 0);
		env->ReleaseByteArrayElements(payload, payload_, 0);
		
		return env->NewStringUTF(returnValue);
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_BlockReadSamKey(JNIEnv *env, jobject instance,  jbyteArray data, jbyte block_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		
		status = BlockReadSamKey((uint8_t *)data_, (uint8_t)block_address, (uint8_t)auth_mode, (uint8_t)key_index);
		
		env->ReleaseByteArrayElements(data, data_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_BlockWriteSamKey(JNIEnv *env, jobject instance, jbyteArray data, jbyte block_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		
		status = BlockWriteSamKey((uint8_t *)data_, (uint8_t)block_address, (uint8_t)auth_mode, (uint8_t)key_index);
		
		env->ReleaseByteArrayElements(data, data_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_BlockInSectorReadSamKey(JNIEnv *env, jobject instance,  jbyteArray data, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		
		status = BlockInSectorReadSamKey((uint8_t *)data_, (uint8_t)sector_address, (uint8_t)block_in_sector_address, (uint8_t)auth_mode, (uint8_t)key_index);
		
		env->ReleaseByteArrayElements(data, data_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_BlockInSectorWriteSamKey(JNIEnv *env, jobject instance,   jbyteArray data, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		
		status = BlockInSectorWriteSamKey((uint8_t *)data_, (uint8_t)sector_address, (uint8_t)block_in_sector_address, (uint8_t)auth_mode, (uint8_t)key_index);
		
		env->ReleaseByteArrayElements(data, data_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_LinearReadSamKey(JNIEnv *env, jobject instance,  jbyteArray aucData, jshort usLinearAddress, jshort usDataLength, jshortArray lpusBytesReturned, jbyte ucKeyMode, jbyte ucReaderKeyIndex) {
		
		UFR_STATUS status;
		
		jbyte *aucData_ = env->GetByteArrayElements(aucData, 0);
		jshort *lpusBytesReturned_ = env->GetShortArrayElements(lpusBytesReturned, 0);
		
		status = LinearReadSamKey((uint8_t *)aucData_, (uint16_t)usLinearAddress, (uint16_t)usDataLength, (uint16_t *)lpusBytesReturned_, (uint8_t)ucKeyMode, (uint8_t)ucReaderKeyIndex);

		env->ReleaseByteArrayElements(aucData,aucData_, 0);
		env->ReleaseShortArrayElements(lpusBytesReturned,lpusBytesReturned_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_LinearWriteSamKey(JNIEnv *env, jobject instance,   jbyteArray aucData, jshort usLinearAddress, jshort usDataLength, jshortArray lpusBytesWritten, jbyte ucKeyMode, jbyte ucReaderKeyIndex) {
		
		UFR_STATUS status;
		
		jbyte *aucData_ = env->GetByteArrayElements(aucData, 0);
		jshort *lpusBytesWritten_ = env->GetShortArrayElements(lpusBytesWritten, 0);
		
		status = LinearWriteSamKey((uint8_t *)aucData, (uint16_t)usLinearAddress, (uint16_t)usDataLength, (uint16_t *)lpusBytesWritten_, (uint8_t)ucKeyMode, (uint8_t)ucReaderKeyIndex);

		env->ReleaseByteArrayElements(aucData,aucData_, 0);
		env->ReleaseShortArrayElements(lpusBytesWritten,lpusBytesWritten_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_ValueBlockReadSamKey(JNIEnv *env, jobject instance, jintArray value, jbyteArray value_addr, jbyte block_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;
		
		jint *value_ = env->GetIntArrayElements(value, 0);
		jbyte *value_addr_ = env->GetByteArrayElements(value_addr, 0);
		
		status = ValueBlockReadSamKey((int32_t *)value_,(uint8_t *)value_addr_,(uint8_t)block_address,(uint8_t)auth_mode,(uint8_t)key_index);

		env->ReleaseIntArrayElements(value,value_, 0);
		env->ReleaseByteArrayElements(value_addr,value_addr_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_ValueBlockInSectorReadSamKey(JNIEnv *env, jobject instance, jintArray value, jbyteArray value_addr, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;
		
		jint *value_ = env->GetIntArrayElements(value, 0);
		jbyte *value_addr_ = env->GetByteArrayElements(value_addr, 0);
		
		status = ValueBlockInSectorReadSamKey((int32_t *)value_,(uint8_t *)value_addr_,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode,(uint8_t)key_index);

		env->ReleaseIntArrayElements(value,value_, 0);
		env->ReleaseByteArrayElements(value_addr,value_addr_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_ValueBlockWriteSamKey(JNIEnv *env, jobject instance, jint value, jbyte value_addr, jbyte block_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;
		
		status = ValueBlockWriteSamKey((int32_t)value,(uint8_t)value_addr,(uint8_t)block_address,(uint8_t)auth_mode,(uint8_t)key_index);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_ValueBlockInSectorWriteSamKey(JNIEnv *env, jobject instance, jint value, jbyte value_addr, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;
		
		status = ValueBlockInSectorWriteSamKey((int32_t)value,(uint8_t)value_addr,(uint8_t)sector_address,(uint8_t)block_in_sector_address,(uint8_t)auth_mode,(uint8_t)key_index);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_ValueBlockIncrementSamKey(JNIEnv *env, jobject instance, jint increment_value, jbyte block_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;

		status = ValueBlockIncrementSamKey((int32_t)increment_value, (uint8_t)block_address, (uint8_t)auth_mode, (uint8_t)key_index);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_ValueBlockInSectorIncrementSamKey(JNIEnv *env, jobject instance, jint increment_value, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;
		
		status = ValueBlockInSectorIncrementSamKey((int32_t)increment_value, (uint8_t)sector_address, (uint8_t)block_in_sector_address, (uint8_t)auth_mode, (uint8_t)key_index);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_ValueBlockDecrementSamKey(JNIEnv *env, jobject instance, jint decrement_value, jbyte block_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;

		status = ValueBlockDecrementSamKey((int32_t)decrement_value, (uint8_t)block_address, (uint8_t)auth_mode, (uint8_t)key_index);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_ValueBlockInSectorDecrementSamKey(JNIEnv *env, jobject instance, jint decrement_value, jbyte sector_address, jbyte block_in_sector_address, jbyte auth_mode, jbyte key_index) {
		
		UFR_STATUS status;
		
		status = ValueBlockInSectorIncrementSamKey((int32_t)decrement_value, (uint8_t)sector_address, (uint8_t)block_in_sector_address, (uint8_t)auth_mode, (uint8_t)key_index);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppSelectByAid(JNIEnv *env, jobject instance, jbyteArray aid, jbyte aid_len, jbyteArray selection_response) {
		
		UFR_STATUS status;
		
		jbyte *aid_ = env->GetByteArrayElements(aid, 0);
		jbyte *selection_response_ = env->GetByteArrayElements(selection_response, 0);

		status = JCAppSelectByAid((uint8_t *)aid_, (uint8_t)aid_len, (uint8_t *)selection_response_);
		
		env->ReleaseByteArrayElements(aid, aid_, 0);
		env->ReleaseByteArrayElements(selection_response, selection_response_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppPutPrivateKey(JNIEnv *env, jobject instance, jbyte key_type, jbyte key_index, jbyteArray key, jshort key_bit_len, jbyteArray key_param, jshort key_param_len) {
		
		UFR_STATUS status;
		
		jbyte *key_ = env->GetByteArrayElements(key, 0);
		jbyte *key_param_ = env->GetByteArrayElements(key_param, 0);

		status = JCAppPutPrivateKey((uint8_t)key_type, (uint8_t)key_index, (uint8_t *)key_, (uint16_t)key_bit_len, (uint8_t *)key_param_, (uint16_t)key_param_len);
		
		env->ReleaseByteArrayElements(key, key_, 0);
		env->ReleaseByteArrayElements(key_param, key_param_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppGenerateKeyPair(JNIEnv *env, jobject instance, jbyte key_type, jbyte key_index, jbyte key_designator, jshort key_bit_len, jbyteArray params, jshort params_size) {
		
		UFR_STATUS status;
		
		jbyte *params_ = env->GetByteArrayElements(params, 0);

		status = JCAppGenerateKeyPair((uint8_t)key_type, (uint8_t)key_index, (uint8_t)key_designator, (uint16_t)key_bit_len, (uint8_t *)params, (uint16_t)params_size);
		
		env->ReleaseByteArrayElements(params, params_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppDeleteRsaKeyPair(JNIEnv *env, jobject instance, jbyte key_index) {
		
		UFR_STATUS status;

		status = JCAppDeleteRsaKeyPair((uint8_t)key_index);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppDeleteEcKeyPair(JNIEnv *env, jobject instance, jbyte key_index) {
		
		UFR_STATUS status;

		status = JCAppDeleteEcKeyPair((uint8_t)key_index);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppSignatureBegin(JNIEnv *env, jobject instance, jbyte cipher, jbyte digest, jbyte padding, jbyte key_index, jbyteArray chunk, jshort chunk_len, jbyteArray alg_param, jshort alg_param_len) {
		
		UFR_STATUS status;
		
		jbyte *chunk_ = env->GetByteArrayElements(chunk, 0);
		jbyte *alg_param_ = env->GetByteArrayElements(alg_param, 0);

		status = JCAppSignatureBegin((uint8_t)cipher, (uint8_t)digest, (uint8_t)padding, (uint8_t)key_index, (uint8_t *)chunk_, (uint16_t)chunk_len, (uint8_t *)alg_param_, (uint16_t)alg_param_len);
		
		env->ReleaseByteArrayElements(chunk, chunk_, 0);
		env->ReleaseByteArrayElements(alg_param, alg_param_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppSignatureUpdate(JNIEnv *env, jobject instance, jbyteArray chunk, jshort chunk_len) {
		
		UFR_STATUS status;
		
		jbyte *chunk_ = env->GetByteArrayElements(chunk, 0);

		status = JCAppSignatureUpdate((uint8_t *)chunk_, (uint16_t)chunk_len);
		
		env->ReleaseByteArrayElements(chunk, chunk_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppSignatureEnd(JNIEnv *env, jobject instance, jshortArray sig_len) {
		
		UFR_STATUS status;
		
		jshort *sig_len_ = env->GetShortArrayElements(sig_len, 0);

		status = JCAppSignatureEnd((uint16_t *)sig_len_);
		
		env->ReleaseShortArrayElements(sig_len, sig_len_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppGenerateSignature(JNIEnv *env, jobject instance, jbyte cipher, jbyte digest, jbyte padding, jbyte key_index, jbyteArray plain_data, jshort plain_data_len, jshortArray sig_len, jbyteArray alg_param, jshort alg_param_len) {
		
		UFR_STATUS status;
		
		jbyte *plain_data_ = env->GetByteArrayElements(plain_data, 0);
		jbyte *alg_param_ = env->GetByteArrayElements(alg_param, 0);
		jshort *sig_len_ = env->GetShortArrayElements(sig_len, 0);

		status = JCAppGenerateSignature((uint8_t)cipher, (uint8_t)digest, (uint8_t)padding, (uint8_t)key_index, (uint8_t *)plain_data_, (uint16_t)plain_data_len, (uint16_t *)sig_len_, (uint8_t *)alg_param_, (uint16_t)alg_param_len);
		
		env->ReleaseByteArrayElements(plain_data, plain_data_, 0);
		env->ReleaseByteArrayElements(alg_param, alg_param_, 0);
		env->ReleaseShortArrayElements(sig_len, sig_len_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppGetSignature(JNIEnv *env, jobject instance, jbyteArray sig, jshort sig_len) {
		
		UFR_STATUS status;
		
		jbyte *sig_ = env->GetByteArrayElements(sig, 0);

		status = JCAppGetSignature((uint8_t *)sig_, (uint16_t)sig_len);
		
		env->ReleaseByteArrayElements(sig, sig_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppPutObj(JNIEnv *env, jobject instance, jbyte obj_type, jbyte obj_index, jbyteArray obj, jshort obj_size, jbyteArray id, jbyte id_size) {
		
		UFR_STATUS status;
		
		jbyte *obj_ = env->GetByteArrayElements(obj, 0);
		jbyte *id_ = env->GetByteArrayElements(id, 0);

		status = JCAppPutObj((uint8_t)obj_type, (uint8_t)obj_index, (uint8_t *)obj_, (uint16_t)obj_size, (uint8_t *)id_, (uint8_t)id_size);
		
		env->ReleaseByteArrayElements(obj, obj_, 0);
		env->ReleaseByteArrayElements(id, id_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppPutObjSubject(JNIEnv *env, jobject instance, jbyte obj_type, jbyte obj_index, jbyteArray subject, jbyte size) {
		
		UFR_STATUS status;
		
		jbyte *subject_ = env->GetByteArrayElements(subject, 0);

		status = JCAppPutObjSubject((uint8_t)obj_type, (uint8_t)obj_index, (uint8_t *)subject_, (uint8_t)size);
		
		env->ReleaseByteArrayElements(subject, subject_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppInvalidateCert(JNIEnv *env, jobject instance, jbyte obj_type, jbyte obj_index) {
		
		UFR_STATUS status;

		status = JCAppInvalidateCert((uint8_t)obj_type, (uint8_t)obj_index);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppGetObjId(JNIEnv *env, jobject instance, jbyte obj_type, jbyte obj_index, jbyteArray id, jshortArray id_size) {
		
		UFR_STATUS status;
		
		jbyte *id_ = env->GetByteArrayElements(id, 0);
		jshort *id_size_ = env->GetShortArrayElements(id_size, 0);

		status = JCAppGetObjId((uint8_t)obj_type, (uint8_t)obj_index, (uint8_t *)id_, (uint16_t *)id_size_);
		
		env->ReleaseByteArrayElements(id, id_, 0);
		env->ReleaseShortArrayElements(id_size, id_size_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppGetObjSubject(JNIEnv *env, jobject instance, jbyte obj_type, jbyte obj_index, jbyteArray subject, jshortArray size) {
		
		UFR_STATUS status;
		
		jbyte *subject_ = env->GetByteArrayElements(subject, 0);
		jshort *size_ = env->GetShortArrayElements(size, 0);

		status = JCAppGetObjSubject((uint8_t)obj_type, (uint8_t)obj_index, (uint8_t *)subject_, (uint16_t *)size_);
		
		env->ReleaseByteArrayElements(subject, subject_, 0);
		env->ReleaseShortArrayElements(size, size_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppGetObj(JNIEnv *env, jobject instance, jbyte obj_type, jbyte obj_index, jbyteArray obj, jshort size) {
		
		UFR_STATUS status;
		
		jbyte *obj_ = env->GetByteArrayElements(obj, 0);

		status = JCAppGetObj((uint8_t)obj_type, (uint8_t)obj_index, (uint8_t *)obj_, (int16_t)size);
		
		env->ReleaseByteArrayElements(obj, obj_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppLogin(JNIEnv *env, jobject instance, jbyte SO, jbyteArray pin, jbyte pinSize) {
		
		UFR_STATUS status;
		
		jbyte *pin_ = env->GetByteArrayElements(pin, 0);

		status = JCAppLogin((uint8_t)SO, (uint8_t *)pin_, (uint8_t)pinSize);
		
		env->ReleaseByteArrayElements(pin, pin_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppGetPinTriesRemaining(JNIEnv *env, jobject instance, jbyte secureCodeType, jshortArray triesRemaining) {
		
		UFR_STATUS status;
		
		jshort *triesRemaining_ = env->GetShortArrayElements(triesRemaining, 0);

		status = JCAppGetPinTriesRemaining((dl_sec_code_t)secureCodeType, (uint16_t *)triesRemaining_);
		
		env->ReleaseShortArrayElements(triesRemaining, triesRemaining_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppPinChange(JNIEnv *env, jobject instance, jbyte secureCodeType, jbyteArray newPin, jbyte newPinSize) {
		
		UFR_STATUS status;
		
		jbyte *newPin_ = env->GetByteArrayElements(newPin, 0);

		status = JCAppPinChange((dl_sec_code_t)secureCodeType, (uint8_t *)newPin_, (uint8_t)newPinSize);
		
		env->ReleaseByteArrayElements(newPin, newPin_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppPinEnable(JNIEnv *env, jobject instance, jbyte SO) {
		
		UFR_STATUS status;

		status = JCAppPinEnable((uint8_t)SO);
		
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppPinDisable(JNIEnv *env, jobject instance, jbyte SO) {
		
		UFR_STATUS status;

		status = JCAppPinDisable((uint8_t)SO);
		
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppGetRsaPublicKey(JNIEnv *env, jobject instance, jbyte key_index, jbyteArray modulus, jshortArray modulus_size, jbyteArray exponent, jshortArray exponent_size) {
		
		UFR_STATUS status;
		
		jbyte *modulus_ = env->GetByteArrayElements(modulus, 0);
		jbyte *exponent_ = env->GetByteArrayElements(exponent, 0);
		jshort *modulus_size_ = env->GetShortArrayElements(modulus_size, 0);
		jshort *exponent_size_ = env->GetShortArrayElements(exponent_size, 0);

		status = JCAppGetRsaPublicKey((uint8_t)key_index, (uint8_t *)modulus_, (uint16_t *)modulus_size_, (uint8_t *)exponent_, (uint16_t *)exponent_size_);
		
		env->ReleaseByteArrayElements(modulus, modulus_, 0);
		env->ReleaseByteArrayElements(exponent, exponent_, 0);
		env->ReleaseShortArrayElements(modulus_size, modulus_size_, 0);
		env->ReleaseShortArrayElements(exponent_size, exponent_size_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppGetEcPublicKey(JNIEnv *env, jobject instance, jbyte key_index, jbyteArray keyW, jshortArray kexWSize, jbyteArray field, jshortArray field_size,
												jbyteArray ab , jshortArray ab_size, jbyteArray g, jshortArray g_size,
												jbyteArray r, jshortArray r_size, jshortArray k, jshortArray key_size_bits, jshortArray key_designator) {
		
		UFR_STATUS status;
		
		jbyte *keyW_ = env->GetByteArrayElements(keyW, 0);
		jbyte *field_ = env->GetByteArrayElements(field, 0);
		jbyte *ab_ = env->GetByteArrayElements(ab, 0);
		jbyte *r_ = env->GetByteArrayElements(r, 0);
		jbyte *g_ = env->GetByteArrayElements(g, 0);
		jshort *kexWSize_ = env->GetShortArrayElements(kexWSize, 0);
		jshort *field_size_ = env->GetShortArrayElements(field_size, 0);
		jshort *ab_size_ = env->GetShortArrayElements(ab_size, 0);
		jshort *g_size_ = env->GetShortArrayElements(g_size, 0);
		jshort *r_size_ = env->GetShortArrayElements(r_size, 0);
		jshort *k_ = env->GetShortArrayElements(k, 0);
		jshort *key_size_bits_ = env->GetShortArrayElements(key_size_bits, 0);
		jshort *key_designator_ = env->GetShortArrayElements(key_designator, 0);

		status = JCAppGetEcPublicKey((uint8_t)key_index, (uint8_t *)keyW_, (uint16_t *)kexWSize_, (uint8_t *)field_, (uint16_t *)field_size_, 
									 (uint8_t *)ab_, (uint16_t *)ab_size_, (uint8_t *)g_, (uint16_t *)g_size_, (uint8_t *)r_, (uint16_t *)r_size_,
									 (uint16_t *)k_, (uint16_t *)key_size_bits_, (uint16_t *)key_designator_);
		
		env->ReleaseByteArrayElements(keyW, keyW_, 0);
		env->ReleaseByteArrayElements(field, field_, 0);
		env->ReleaseByteArrayElements(r, r_, 0);
		env->ReleaseByteArrayElements(ab, ab_, 0);
		env->ReleaseByteArrayElements(g, g_, 0);
		env->ReleaseShortArrayElements(kexWSize, kexWSize_, 0);
		env->ReleaseShortArrayElements(field_size, field_size_, 0);
		env->ReleaseShortArrayElements(ab_size, ab_size_, 0);
		env->ReleaseShortArrayElements(g_size, g_size_, 0);
		env->ReleaseShortArrayElements(r_size, r_size_, 0);
		env->ReleaseShortArrayElements(k, k_, 0);
		env->ReleaseShortArrayElements(key_size_bits, key_size_bits_, 0);
		env->ReleaseShortArrayElements(key_designator, key_designator_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppGetEcKeySizeBits(JNIEnv *env, jobject instance, jbyte key_index, jshortArray key_size_bits, jshortArray key_designator) {
		
		UFR_STATUS status;
		
		jshort *key_size_bits_ = env->GetShortArrayElements(key_size_bits, 0);
		jshort *key_designator_ = env->GetShortArrayElements(key_designator, 0);

		status = JCAppGetEcKeySizeBits((uint8_t)key_index, (uint16_t *)key_size_bits_, (uint16_t *)key_designator_);

		env->ReleaseShortArrayElements(key_size_bits, key_size_bits_, 0);
		env->ReleaseShortArrayElements(key_designator, key_designator_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCAppPinUnblock(JNIEnv *env, jobject instance, jbyte SO, jbyteArray puk, jbyte pukSize) {
		
		UFR_STATUS status;
		
		jbyte *puk_ = env->GetByteArrayElements(puk, 0);

		status = JCAppPinUnblock((uint8_t)SO, (uint8_t *)puk_, (uint8_t)pukSize);
		
		env->ReleaseByteArrayElements(puk, puk_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_SetISO14443_14_1DLStorage(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		status = SetISO14443_4_DLStorage();

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCStorageGetFilesListSize(JNIEnv *env, jobject instance, jintArray list_size) {
		
		UFR_STATUS status;
		
		jint *list_size_ = env->GetIntArrayElements(list_size, 0);
		
		status = JCStorageGetFilesListSize((uint32_t *)list_size_);
		
		env->ReleaseIntArrayElements(list_size,list_size_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCStorageListFiles(JNIEnv *env, jobject instance,  jbyteArray list, jint list_bytes_allocated) {
		
		UFR_STATUS status;
		
		jbyte *list_ = env->GetByteArrayElements(list, 0);
		
		status = JCStorageListFiles((uint8_t *)list_, (uint32_t)list_bytes_allocated);
		
		env->ReleaseByteArrayElements(list, list_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCStorageGetFileSize(JNIEnv *env, jobject instance, jbyte card_file_index, jintArray file_size) {
		
		UFR_STATUS status;
		
		jint *file_size_ = env->GetIntArrayElements(file_size, 0);
		
		status = JCStorageGetFileSize((uint8_t)card_file_index, (uint32_t *)file_size_);
		
		env->ReleaseIntArrayElements(file_size, file_size_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCStorageReadFile(JNIEnv *env, jobject instance, jbyte card_file_index,  jbyteArray data, jint data_bytes_allocated) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		
		status = JCStorageReadFile((uint8_t)card_file_index, (uint8_t *)data_, (uint32_t)data_bytes_allocated);
		
		env->ReleaseByteArrayElements(data, data_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCStorageReadFileToFileSystem(JNIEnv *env, jobject instance, jbyte card_file_index,   jstring file_system_path_name_) {
		
		UFR_STATUS status;
		
		const char *file_system_path_name = env->GetStringUTFChars(file_system_path_name_, 0);
		
		status = JCStorageReadFileToFileSystem((uint8_t)card_file_index, file_system_path_name);

		env->ReleaseStringUTFChars(file_system_path_name_, file_system_path_name);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCStorageWriteFile(JNIEnv *env, jobject instance, jbyte card_file_index,   jbyteArray data, jint data_size) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		
		status = JCStorageWriteFile((uint8_t)card_file_index, (uint8_t *)data, (uint32_t)data_size);
		
		env->ReleaseByteArrayElements(data, data_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCStorageWriteFileFromFileSystem(JNIEnv *env, jobject instance, jbyte card_file_index,   jstring file_system_path_name_) {
		
		UFR_STATUS status;
		
		const char *file_system_path_name = env->GetStringUTFChars(file_system_path_name_, 0);
		
		status = JCStorageWriteFileFromFileSystem((uint8_t)card_file_index, file_system_path_name);

		env->ReleaseStringUTFChars(file_system_path_name_, file_system_path_name);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_JCStorageDeleteFile(JNIEnv *env, jobject instance, jbyte file_index) {
		
		UFR_STATUS status;
		
		status = JCStorageDeleteFile((uint8_t)file_index);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1GetDesfireUid_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr,  jbyteArray card_uid, jbyteArray card_uid_len, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
		jbyte *card_uid_len_ = env->GetByteArrayElements(card_uid_len, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_GetDesfireUid_des((uint8_t)des_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)card_uid_len_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
		env->ReleaseByteArrayElements(card_uid_len, card_uid_len_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1GetDesfireUid_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr,  jbyteArray card_uid, jbyteArray card_uid_len, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
		jbyte *card_uid_len_ = env->GetByteArrayElements(card_uid_len, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_GetDesfireUid_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)card_uid_len_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
		env->ReleaseByteArrayElements(card_uid_len, card_uid_len_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1GetDesfireUid_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr,  jbyteArray card_uid, jbyteArray card_uid_len, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
		jbyte *card_uid_len_ = env->GetByteArrayElements(card_uid_len, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_GetDesfireUid_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)card_uid_len_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
		env->ReleaseByteArrayElements(card_uid_len, card_uid_len_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1GetDesfireUid_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte aid_key_nr,  jbyteArray card_uid, jbyteArray card_uid_len, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
		jbyte *card_uid_len_ = env->GetByteArrayElements(card_uid_len, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_GetDesfireUid_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)card_uid_len_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
		env->ReleaseByteArrayElements(card_uid_len, card_uid_len_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1GetDesfireUid_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte aid_key_nr,  jbyteArray card_uid, jbyteArray card_uid_len, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
		jbyte *card_uid_len_ = env->GetByteArrayElements(card_uid_len, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_GetDesfireUid_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)card_uid_len_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
		env->ReleaseByteArrayElements(card_uid_len, card_uid_len_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1GetDesfireUid_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte aid_key_nr,  jbyteArray card_uid, jbyteArray card_uid_len, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
		jbyte *card_uid_len_ = env->GetByteArrayElements(card_uid_len, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_GetDesfireUid_2k3des_PK((uint8_t *)des3k_key_ext, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)card_uid_len_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
		env->ReleaseByteArrayElements(card_uid_len, card_uid_len_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireWriteStdDataFile2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireWriteStdDataFile2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireWriteStdDataFileDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireWriteStdDataFileDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1GetDesfireUidAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr,  jbyteArray card_uid, jbyteArray card_uid_len, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
		jbyte *card_uid_len_ = env->GetByteArrayElements(card_uid_len, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_GetDesfireUidAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)card_uid_len_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
		env->ReleaseByteArrayElements(card_uid_len, card_uid_len_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1GetDesfireUid3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr,  jbyteArray card_uid, jbyteArray card_uid_len, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
		jbyte *card_uid_len_ = env->GetByteArrayElements(card_uid_len, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_GetDesfireUid3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)card_uid_len_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
		env->ReleaseByteArrayElements(card_uid_len, card_uid_len_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1GetDesfireUidDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr,  jbyteArray card_uid, jbyteArray card_uid_len, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
		jbyte *card_uid_len_ = env->GetByteArrayElements(card_uid_len, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_GetDesfireUidDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)card_uid_len_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
		env->ReleaseByteArrayElements(card_uid_len, card_uid_len_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1GetDesfireUid2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr,  jbyteArray card_uid, jbyteArray card_uid_len, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
		jbyte *card_uid_len_ = env->GetByteArrayElements(card_uid_len, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_GetDesfireUid2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)card_uid_len_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
		env->ReleaseByteArrayElements(card_uid_len, card_uid_len_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireFormatCard_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireFormatCard_des((uint8_t)des_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireFormatCard_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireFormatCard_2k3des((uint8_t)des2k_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireFormatCard_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireFormatCard_3k3des((uint8_t)des3k_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireFormatCard_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireFormatCard_des_PK((uint8_t *)des_key_ext_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireFormatCard_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireFormatCard_2k3des_PK((uint8_t *)des2k_key_ext_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireFormatCard_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireFormatCard_3k3des_PK((uint8_t *)des3k_key_ext_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireFormatCardAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireFormatCardAesAuth((uint8_t)aes_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireFormatCard3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireFormatCard3k3desAuth((uint8_t)des3k_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireFormatCardDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireFormatCardDesAuth((uint8_t)des_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireFormatCard2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireFormatCard2k3desAuth((uint8_t)des2k_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateStdDataFile_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte file_id, jint file_size, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateStdDataFile_des((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint32_t)file_size, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateStdDataFile_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte file_id, jint file_size, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateStdDataFile_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint32_t)file_size, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateStdDataFile_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte file_id, jint file_size, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateStdDataFile_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint32_t)file_size, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateStdDataFile_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte file_id, jint file_size, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateStdDataFile_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint32_t)file_size, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateStdDataFile_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte file_id, jint file_size, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateStdDataFile_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint32_t)file_size, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateStdDataFile_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte file_id, jint file_size, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateStdDataFile_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint32_t)file_size, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateStdDataFileAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte file_id, jint file_size, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateStdDataFileAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint32_t)file_size, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateStdDataFile3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte file_id, jint file_size, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateStdDataFile3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint32_t)file_size, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateStdDataFileDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte file_id, jint file_size, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateStdDataFileDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint32_t)file_size, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateStdDataFile2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte file_id, jint file_size, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateStdDataFile2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint32_t)file_size, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteFile_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDeleteFile_des((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteFile_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDeleteFile_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteFile_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDeleteFile_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteFile_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDeleteFile_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteFile_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDeleteFile_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteFile_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDeleteFile_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDeleteFileAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireDeleteFileAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDeleteFile3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireDeleteFile3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDeleteFileDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireDeleteFileDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDeleteFile2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireDeleteFile2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreate3k3desApplication_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreate3k3desApplication_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateDesApplication_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateDesApplication_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateAesApplication_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateAesApplication_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreate3k3desApplication_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreate3k3desApplication_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateDesApplication_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateDesApplication_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateAesApplication_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateAesApplication_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreate3k3desApplication_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreate3k3desApplication_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateDesApplication_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateDesApplication_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateAesApplication_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateAesApplication_des((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreate3k3desApplication_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreate3k3desApplication_des((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateDesApplication_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateDesApplication_des((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateAesApplication_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateAesApplication_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreate3k3desApplication_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreate3k3desApplication_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateDesApplication_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateDesApplication_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateAesApplication_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateAesApplication_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreate3k3desApplication_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte  *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreate3k3desApplication_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateDesApplication_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte  *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateDesApplication_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateAesApplication_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte  *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateAesApplication_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreate3k3desApplication_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte  *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreate3k3desApplication_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateDesApplication_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte  *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateDesApplication_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateAesApplicationAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateAesApplicationAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreate3k3desApplicationAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreate3k3desApplicationAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateDesApplicationAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateDesApplicationAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateAesApplication3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateAesApplication3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreate3k3desApplication3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreate3k3desApplication3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateDesApplication3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateDesApplication3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateAesApplicationDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateAesApplicationDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreate3k3desApplicationDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreate3k3desApplicationDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateDesApplicationDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateDesApplicationDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateAesApplication2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateAesApplication2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreate3k3desApplication2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreate3k3desApplication2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateDesApplication2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateDesApplication2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreate3k3desApplication_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreate3k3desApplication_no_auth((uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateDesApplication_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateDesApplication_no_auth((uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDeleteApplication_des((uint8_t)des_key_nr, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDeleteApplication_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDeleteApplication_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDeleteApplication_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDeleteApplication_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDeleteApplication_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDeleteApplicationAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireDeleteApplicationAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDeleteApplication3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireDeleteApplication3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDeleteApplicationDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireDeleteApplicationDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDeleteApplication2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireDeleteApplication2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireSetConfiguration_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jbyte random_uid, jbyte format_disable, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireSetConfiguration_des((uint8_t)des_key_nr, (uint8_t)random_uid, (uint8_t)format_disable, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireSetConfiguration_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jbyte random_uid, jbyte format_disable, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireSetConfiguration_2k3des((uint8_t)des2k_key_nr, (uint8_t)random_uid, (uint8_t)format_disable, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireSetConfiguration_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jbyte random_uid, jbyte format_disable, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireSetConfiguration_2k3des((uint8_t)des3k_key_nr, (uint8_t)random_uid, (uint8_t)format_disable, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireSetConfiguration_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jbyte random_uid, jbyte format_disable, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte  *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireSetConfiguration_des_PK((uint8_t *)des_key_ext_, (uint8_t)random_uid, (uint8_t)format_disable, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireSetConfiguration_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jbyte random_uid, jbyte format_disable, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte  *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireSetConfiguration_2k3des_PK((uint8_t *)des2k_key_ext_, (uint8_t)random_uid, (uint8_t)format_disable, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireSetConfiguration_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jbyte random_uid, jbyte format_disable, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte  *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireSetConfiguration_3k3des_PK((uint8_t *)des3k_key_ext_, (uint8_t)random_uid, (uint8_t)format_disable, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireSetConfigurationAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jbyte random_uid, jbyte format_disable, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireSetConfigurationAesAuth((uint8_t)aes_key_nr, (uint8_t)random_uid, (uint8_t)format_disable, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireSetConfiguration3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jbyte random_uid, jbyte format_disable, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireSetConfiguration3k3desAuth((uint8_t)des3k_key_nr, (uint8_t)random_uid, (uint8_t)format_disable, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireSetConfigurationDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jbyte random_uid, jbyte format_disable, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireSetConfigurationDesAuth((uint8_t)des_key_nr, (uint8_t)random_uid, (uint8_t)format_disable, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireSetConfiguration2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jbyte random_uid, jbyte format_disable, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireSetConfiguration2k3desAuth((uint8_t)des2k_key_nr, (uint8_t)random_uid, (uint8_t)format_disable, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetKeySettings_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyteArray setting, jbyteArray max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *setting_ = env->GetByteArrayElements(setting, 0);
		jbyte *max_key_no_ = env->GetByteArrayElements(max_key_no, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetKeySettings_des((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t *)setting_, (uint8_t *)max_key_no_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(setting, setting_, 0);
		env->ReleaseByteArrayElements(max_key_no, max_key_no_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetKeySettings_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyteArray setting, jbyteArray max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *setting_ = env->GetByteArrayElements(setting, 0);
		jbyte *max_key_no_ = env->GetByteArrayElements(max_key_no, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetKeySettings_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t *)setting_, (uint8_t *)max_key_no_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(setting, setting_, 0);
		env->ReleaseByteArrayElements(max_key_no, max_key_no_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetKeySettings_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyteArray setting, jbyteArray max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *setting_ = env->GetByteArrayElements(setting, 0);
		jbyte *max_key_no_ = env->GetByteArrayElements(max_key_no, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetKeySettings_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t *)setting_, (uint8_t *)max_key_no_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(setting, setting_, 0);
		env->ReleaseByteArrayElements(max_key_no, max_key_no_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetKeySettings_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyteArray setting, jbyteArray max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jbyte *setting_ = env->GetByteArrayElements(setting, 0);
		jbyte *max_key_no_ = env->GetByteArrayElements(max_key_no, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetKeySettings_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t *)setting_, (uint8_t *)max_key_no_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseByteArrayElements(setting, setting_, 0);
		env->ReleaseByteArrayElements(max_key_no, max_key_no_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetKeySettings_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyteArray setting, jbyteArray max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jbyte *setting_ = env->GetByteArrayElements(setting, 0);
		jbyte *max_key_no_ = env->GetByteArrayElements(max_key_no, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetKeySettings_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t *)setting_, (uint8_t *)max_key_no_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseByteArrayElements(setting, setting_, 0);
		env->ReleaseByteArrayElements(max_key_no, max_key_no_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetKeySettings_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyteArray setting, jbyteArray max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jbyte *setting_ = env->GetByteArrayElements(setting, 0);
		jbyte *max_key_no_ = env->GetByteArrayElements(max_key_no, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetKeySettings_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t *)setting_, (uint8_t *)max_key_no_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseByteArrayElements(setting, setting_, 0);
		env->ReleaseByteArrayElements(max_key_no, max_key_no_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireGetKeySettingsAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyteArray setting, jbyteArray max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *setting_ = env->GetByteArrayElements(setting, 0);
		jbyte *max_key_no_ = env->GetByteArrayElements(max_key_no, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireGetKeySettingsAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t *)setting_, (uint8_t *)max_key_no_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(setting, setting_, 0);
		env->ReleaseByteArrayElements(max_key_no, max_key_no_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireGetKeySettings3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyteArray setting, jbyteArray max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *setting_ = env->GetByteArrayElements(setting, 0);
		jbyte *max_key_no_ = env->GetByteArrayElements(max_key_no, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireGetKeySettings3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t *)setting_, (uint8_t *)max_key_no_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(setting, setting_, 0);
		env->ReleaseByteArrayElements(max_key_no, max_key_no_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireGetKeySettingsDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyteArray setting, jbyteArray max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *setting_ = env->GetByteArrayElements(setting, 0);
		jbyte *max_key_no_ = env->GetByteArrayElements(max_key_no, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireGetKeySettingsDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t *)setting_, (uint8_t *)max_key_no_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(setting, setting_, 0);
		env->ReleaseByteArrayElements(max_key_no, max_key_no_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireGetKeySettings2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyteArray setting, jbyteArray max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *setting_ = env->GetByteArrayElements(setting, 0);
		jbyte *max_key_no_ = env->GetByteArrayElements(max_key_no, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireGetKeySettings2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t *)setting_, (uint8_t *)max_key_no_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(setting, setting_, 0);
		env->ReleaseByteArrayElements(max_key_no, max_key_no_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeKeySettings_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte setting, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChangeKeySettings_des((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)setting, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeKeySettings_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte setting, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChangeKeySettings_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)setting, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeKeySettings_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte setting, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChangeKeySettings_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)setting, (uint16_t *)card_status_, (uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeKeySettings_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte setting, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChangeKeySettings_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t)setting, (uint16_t *)card_status_, (uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeKeySettings_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte setting, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChangeKeySettings_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)setting, (uint16_t *)card_status_, (uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeKeySettings_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte setting, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChangeKeySettings_des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t)setting, (uint16_t *)card_status_, (uint16_t *)exec_time_);

		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireChangeKeySettingsAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte setting, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireChangeKeySettingsAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)setting, (uint16_t *)card_status_, (uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireChangeKeySettings3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte setting, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireChangeKeySettings3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)setting, (uint16_t *)card_status_, (uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireChangeKeySettingsDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte setting, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireChangeKeySettingsDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)setting, (uint16_t *)card_status_, (uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireChangeKeySettings2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte setting, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireChangeKeySettings2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)setting, (uint16_t *)card_status_, (uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeDesKey_1des(JNIEnv *env, jobject instance, jbyte auth_des_key_nr, jint aid, jbyte aid_key_no_auth, jbyte new_des_key_nr, jbyte aid_key_no, jbyte old_des_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChangeDesKey_des((uint8_t)auth_des_key_nr, (uint32_t)aid, (uint32_t)aid_key_no_auth, (uint8_t)new_des_key_nr, (uint32_t)aid_key_no, (uint8_t)old_des_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChange2K3DesKey_1des(JNIEnv *env, jobject instance, jbyte auth_des_key_nr, jint aid, jbyte aid_key_no_auth, jbyte new_2k3des_key_nr, jbyte aid_key_no, jbyte old_2k3des_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChange2K3DesKey_des((uint8_t)auth_des_key_nr, (uint32_t)aid, (uint32_t)aid_key_no_auth, (uint8_t)new_2k3des_key_nr, (uint32_t)aid_key_no, (uint8_t)old_2k3des_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeDesKey_12k3des(JNIEnv *env, jobject instance, jbyte auth_des2k_key_nr, jint aid, jbyte aid_key_no_auth, jbyte new_des_key_nr, jbyte aid_key_no, jbyte old_des_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChangeDesKey_2k3des((uint8_t)auth_des2k_key_nr, (uint32_t)aid, (uint32_t)aid_key_no_auth, (uint8_t)new_des_key_nr, (uint32_t)aid_key_no, (uint8_t)old_des_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChange3K3DesKey_13k3des(JNIEnv *env, jobject instance, jbyte auth_des3k_key_nr, jint aid, jbyte aid_key_no_auth, jbyte new_3k3des_key_nr, jbyte aid_key_no, jbyte old_3k3des_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChange3K3DesKey_3k3des((uint8_t)auth_des3k_key_nr, (uint32_t)aid, (uint32_t)aid_key_no_auth, (uint8_t)new_3k3des_key_nr, (uint32_t)aid_key_no, (uint8_t)old_3k3des_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeMasterKey(JNIEnv *env, jobject instance, jbyte auth_key_nr, jbyte auth_key_type, jbyte new_key_nr, jbyte new_key_type, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChangeMasterKey((uint8_t)auth_key_nr, (uint32_t)auth_key_type, (uint8_t)new_key_nr, (uint8_t)new_key_type, (uint16_t *)card_status_, (uint16_t *)exec_time_);

		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeDesKey_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray auth_des_key, jint aid, jbyte aid_key_no_auth,  jbyteArray new_des_key, jbyte aid_key_no,  jbyteArray old_des_key, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *auth_des_key_ = env->GetByteArrayElements(auth_des_key, 0);
		jbyte *new_des_key_ = env->GetByteArrayElements(new_des_key, 0);
		jbyte *old_des_key_ = env->GetByteArrayElements(old_des_key, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChangeDesKey_des_PK((uint8_t *)auth_des_key_, (uint32_t)aid, (uint32_t)aid_key_no_auth, (uint8_t *)new_des_key_, (uint32_t)aid_key_no, (uint8_t *)old_des_key_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(auth_des_key, auth_des_key_, 0);
		env->ReleaseByteArrayElements(new_des_key, new_des_key_, 0);
		env->ReleaseByteArrayElements(old_des_key, old_des_key_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChange2K3DesKey_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray auth_des_key, jint aid, jbyte aid_key_no_auth,  jbyteArray new_2k3des_key, jbyte aid_key_no,  jbyteArray old_2k3des_key, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *auth_des_key_ = env->GetByteArrayElements(auth_des_key, 0);
		jbyte *new_2k3des_key_ = env->GetByteArrayElements(new_2k3des_key, 0);
		jbyte *old_2k3des_key_ = env->GetByteArrayElements(old_2k3des_key, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChange2K3DesKey_des_PK((uint8_t *)auth_des_key_, (uint32_t)aid, (uint32_t)aid_key_no_auth, (uint8_t *)new_2k3des_key_, (uint32_t)aid_key_no, (uint8_t *)old_2k3des_key_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(auth_des_key, auth_des_key_, 0);
		env->ReleaseByteArrayElements(new_2k3des_key, new_2k3des_key_, 0);
		env->ReleaseByteArrayElements(old_2k3des_key, old_2k3des_key_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeDesKey_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray auth_des2k_key, jint aid, jbyte aid_key_no_auth,  jbyteArray new_des_key, jbyte aid_key_no,  jbyteArray old_des_key, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *auth_des2k_key_ = env->GetByteArrayElements(auth_des2k_key, 0);
		jbyte *new_des_key_ = env->GetByteArrayElements(new_des_key, 0);
		jbyte *old_des_key_ = env->GetByteArrayElements(old_des_key, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChangeDesKey_2k3des_PK((uint8_t *)auth_des2k_key_, (uint32_t)aid, (uint32_t)aid_key_no_auth, (uint8_t *)new_des_key_, (uint32_t)aid_key_no, (uint8_t *)old_des_key_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(auth_des2k_key, auth_des2k_key_, 0);
		env->ReleaseByteArrayElements(new_des_key, new_des_key_, 0);
		env->ReleaseByteArrayElements(old_des_key, old_des_key_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChange2K3DesKey_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray auth_des2k_key, jint aid, jbyte aid_key_no_auth,  jbyteArray new_2k3des_key, jbyte aid_key_no,  jbyteArray old_2k3des_key, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *auth_des2k_key_ = env->GetByteArrayElements(auth_des2k_key, 0);
		jbyte *new_2k3des_key_ = env->GetByteArrayElements(new_2k3des_key, 0);
		jbyte *old_2k3des_key_ = env->GetByteArrayElements(old_2k3des_key, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChange2K3DesKey_2k3des_PK((uint8_t *)auth_des2k_key_, (uint32_t)aid, (uint8_t)aid_key_no_auth, (uint8_t *)new_2k3des_key_, (uint8_t)aid_key_no, (uint8_t *)old_2k3des_key_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(auth_des2k_key, auth_des2k_key_, 0);
		env->ReleaseByteArrayElements(new_2k3des_key, new_2k3des_key_, 0);
		env->ReleaseByteArrayElements(old_2k3des_key, old_2k3des_key_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChange2K3DesKey_12k3des(JNIEnv *env, jobject instance,  jbyte auth_des2k_nr, jint aid, jbyte aid_key_no_auth,  jbyte new_2k3des_key, jbyte aid_key_no,  jbyte old_2k3des_key, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChange2K3DesKey_2k3des((uint8_t)auth_des2k_nr, (uint32_t)aid, (uint8_t)aid_key_no_auth, (uint8_t)new_2k3des_key, (uint8_t)aid_key_no, (uint8_t)old_2k3des_key, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChange3K3DesKey_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray auth_des3k_key, jint aid, jbyte aid_key_no_auth,  jbyteArray new_3k3des_key, jbyte aid_key_no,  jbyteArray old_3k3des_key, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *auth_des3k_key_ = env->GetByteArrayElements(auth_des3k_key, 0);
		jbyte *new_3k3des_key_ = env->GetByteArrayElements(new_3k3des_key, 0);
		jbyte *old_3k3des_key_ = env->GetByteArrayElements(old_3k3des_key, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChange3K3DesKey_3k3des_PK((uint8_t *)auth_des3k_key_, (uint32_t)aid, (uint32_t)aid_key_no_auth, (uint8_t *)new_3k3des_key_, (uint32_t)aid_key_no, (uint8_t *)old_3k3des_key_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(auth_des3k_key, auth_des3k_key_, 0);
		env->ReleaseByteArrayElements(new_3k3des_key, new_3k3des_key_, 0);
		env->ReleaseByteArrayElements(old_3k3des_key, old_3k3des_key_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeMasterKey_1PK(JNIEnv *env, jobject instance,  jbyteArray auth_key, jbyte auth_key_type,  jbyteArray new_key, jbyte new_key_type, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *auth_key_ = env->GetByteArrayElements(auth_key, 0);
		jbyte *new_key_ = env->GetByteArrayElements(new_key, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChangeMasterKey_PK((uint8_t *)auth_key, (uint32_t)auth_key_type, (uint8_t *)new_key_, (uint8_t)new_key_type, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(auth_key, auth_key_, 0);
		env->ReleaseByteArrayElements(new_key, new_key_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireChangeAesKey_1AesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_no_auth, jbyte new_aes_key_nr, jbyte aid_key_no, jbyte old_aes_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireChangeAesKey_AesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint32_t)aid_key_no_auth, (uint8_t)new_aes_key_nr, (uint32_t)aid_key_no, (uint8_t)old_aes_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireChange3k3desKey_13k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_no_auth, jbyte new_des3k_key_nr, jbyte aid_key_no, jbyte old_des3k_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireChange3k3desKey_3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint32_t)aid_key_no_auth, (uint8_t)new_des3k_key_nr, (uint32_t)aid_key_no, (uint8_t)old_des3k_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireChangeDesKey_1DesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_no_auth, jbyte new_des_key_nr, jbyte aid_key_no, jbyte old_des_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireChangeDesKey_DesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint32_t)aid_key_no_auth, (uint8_t)new_des_key_nr, (uint32_t)aid_key_no, (uint8_t)old_des_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireChange2k3desKey_1DesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_no_auth, jbyte new_des2k_key_nr, jbyte aid_key_no, jbyte old_des_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireChange2k3desKey_DesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint32_t)aid_key_no_auth, (uint8_t)new_des2k_key_nr, (uint32_t)aid_key_no, (uint8_t)old_des_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireChangeDesKey_12k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_no_auth, jbyte new_des_key_nr, jbyte aid_key_no, jbyte old_des2k_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireChangeDesKey_2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint32_t)aid_key_no_auth, (uint8_t)new_des_key_nr, (uint32_t)aid_key_no, (uint8_t)old_des2k_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireChange2k3desKey_12k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_no_auth, jbyte new_des2k_key_nr, jbyte aid_key_no, jbyte old_des2k_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireChange2k3desKey_2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint32_t)aid_key_no_auth, (uint8_t)new_des2k_key_nr, (uint32_t)aid_key_no, (uint8_t)old_des2k_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireChangeMasterKey(JNIEnv *env, jobject instance, jbyte auth_key_nr, jbyte auth_key_type, jbyte new_key_nr, jbyte new_key_type, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireChangeMasterKey((uint8_t)auth_key_nr, (uint8_t)auth_key_type, (uint8_t)new_key_nr,  (uint8_t)new_key_type, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}


	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteKey(JNIEnv *env, jobject instance, jbyte key_no,  jbyteArray key, jbyte key_type) {
		
		UFR_STATUS status;
		
		jbyte *key_ = env->GetByteArrayElements(key, 0);

		status = uFR_int_DesfireWriteKey((uint8_t)key_no, (uint8_t *)key_, (uint8_t)key_type);

		env->ReleaseByteArrayElements(key, key_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadStdDataFile_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadStdDataFile_des((uint8_t)des_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t)file_id, (uint8_t)offset, (uint8_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadStdDataFile_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadStdDataFile_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t)file_id, (uint8_t)offset, (uint8_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadStdDataFile_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadStdDataFile_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t)file_id, (uint8_t)offset, (uint8_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadStdDataFile_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadStdDataFile_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t)file_id, (uint8_t)offset, (uint8_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadStdDataFile_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadStdDataFile_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t)file_id, (uint8_t)offset, (uint8_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadStdDataFile_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadStdDataFile_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t)file_id, (uint8_t)offset, (uint8_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireReadStdDataFileAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireReadStdDataFileAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t)file_id, (uint8_t)offset, (uint8_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireReadStdDataFile3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireReadStdDataFile3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t)file_id, (uint8_t)offset, (uint8_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireReadStdDataFileDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireReadStdDataFileDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t)file_id, (uint8_t)offset, (uint8_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireReadStdDataFile2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireReadStdDataFile2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t)file_id, (uint8_t)offset, (uint8_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteStdDataFile_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireWriteStdDataFile_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t)file_id, (uint8_t)offset, (uint8_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteStdDataFile_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireWriteStdDataFile_des((uint8_t)des_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t)file_id, (uint8_t)offset, (uint8_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteStdDataFile_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireWriteStdDataFile_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteStdDataFile_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireWriteStdDataFile_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t)file_id, (uint8_t)offset, (uint8_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteStdDataFile_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireWriteStdDataFile_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t)file_id, (uint8_t)offset, (uint8_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteStdDataFile_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireWriteStdDataFile_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireWriteStdDataFileAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireWriteStdDataFileAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t)file_id, (uint8_t)offset, (uint8_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireWriteStdDataFile3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireWriteStdDataFile3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (uint8_t)file_id, (uint8_t)offset, (uint8_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateValueFile_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte file_id, jint lower_limit, jint upper_limit, jint value, jbyte limited_credit_enabled, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateValueFile_des((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)file_id, (int32_t)lower_limit, (int32_t)upper_limit, (int32_t)value, (uint8_t)limited_credit_enabled, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateValueFile_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte file_id, jint lower_limit, jint upper_limit, jint value, jbyte limited_credit_enabled, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateValueFile_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)file_id, (int32_t)lower_limit, (int32_t)upper_limit, (int32_t)value, (uint8_t)limited_credit_enabled, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateValueFile_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte file_id, jint lower_limit, jint upper_limit, jint value, jbyte limited_credit_enabled, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateValueFile_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)file_id, (int32_t)lower_limit, (int32_t)upper_limit, (int32_t)value, (uint8_t)limited_credit_enabled, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateValueFile_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte file_id, jint lower_limit, jint upper_limit, jint value, jbyte limited_credit_enabled, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateValueFile_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t)file_id, (int32_t)lower_limit, (int32_t)upper_limit, (int32_t)value, (uint8_t)limited_credit_enabled, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateValueFile_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte file_id, jint lower_limit, jint upper_limit, jint value, jbyte limited_credit_enabled, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateValueFile_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)file_id, (int32_t)lower_limit, (int32_t)upper_limit, (int32_t)value, (uint8_t)limited_credit_enabled, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateValueFile_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte file_id, jint lower_limit, jint upper_limit, jint value, jbyte limited_credit_enabled, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateValueFile_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t)file_id, (int32_t)lower_limit, (int32_t)upper_limit, (int32_t)value, (uint8_t)limited_credit_enabled, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateValueFileAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte file_id, jint lower_limit, jint upper_limit, jint value, jbyte limited_credit_enabled, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateValueFileAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)file_id, (int32_t)lower_limit, (int32_t)upper_limit, (int32_t)value, (uint8_t)limited_credit_enabled, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateValueFile3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte file_id, jint lower_limit, jint upper_limit, jint value, jbyte limited_credit_enabled, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateValueFile3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)file_id, (int32_t)lower_limit, (int32_t)upper_limit, (int32_t)value, (uint8_t)limited_credit_enabled, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateValueFileDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte file_id, jint lower_limit, jint upper_limit, jint value, jbyte limited_credit_enabled, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateValueFileDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)file_id, (int32_t)lower_limit, (int32_t)upper_limit, (int32_t)value, (uint8_t)limited_credit_enabled, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateValueFile2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte file_id, jint lower_limit, jint upper_limit, jint value, jbyte limited_credit_enabled, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateValueFile2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)file_id, (int32_t)lower_limit, (int32_t)upper_limit, (int32_t)value, (uint8_t)limited_credit_enabled, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadValueFile_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jintArray value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jint *value_ = env->GetIntArrayElements(value, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadValueFile_des((uint8_t)des_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t *)value_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseIntArrayElements(value, value_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadValueFile_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jintArray value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jint *value_ = env->GetIntArrayElements(value, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadValueFile_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t *)value_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseIntArrayElements(value, value_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadValueFile_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jintArray value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jint *value_ = env->GetIntArrayElements(value, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadValueFile_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t *)value_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseIntArrayElements(value, value_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadValueFile_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jintArray value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jint *value_ = env->GetIntArrayElements(value, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadValueFile_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t *)value_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseIntArrayElements(value, value_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadValueFile_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jintArray value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jint *value_ = env->GetIntArrayElements(value, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadValueFile_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t *)value_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseIntArrayElements(value, value_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadValueFile_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jintArray value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jint *value_ = env->GetIntArrayElements(value, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadValueFile_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t *)value_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseIntArrayElements(value, value_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireReadValueFileAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jintArray value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jint *value_ = env->GetIntArrayElements(value, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireReadValueFileAesAuth((uint8_t )aes_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t *)value_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseIntArrayElements(value, value_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireReadValueFile3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jintArray value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jint *value_ = env->GetIntArrayElements(value, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireReadValueFile3k3desAuth((uint8_t )des3k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t *)value_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseIntArrayElements(value, value_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireReadValueFileDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jintArray value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jint *value_ = env->GetIntArrayElements(value, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireReadValueFileDesAuth((uint8_t )des_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t *)value_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseIntArrayElements(value, value_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireReadValueFile2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jintArray value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jint *value_ = env->GetIntArrayElements(value, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireReadValueFile2k3desAuth((uint8_t )des2k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t *)value_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseIntArrayElements(value, value_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireIncreaseValueFile_des((uint8_t )des_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireIncreaseValueFile_2k3des((uint8_t )des2k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireIncreaseValueFile_3k3des((uint8_t )des3k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireIncreaseValueFile_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireIncreaseValueFile_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireIncreaseValueFile_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireIncreaseValueFileAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireIncreaseValueFileAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireIncreaseValueFile3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireIncreaseValueFile3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireIncreaseValueFileDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireIncreaseValueFileDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireIncreaseValueFile2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireIncreaseValueFile2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDecreaseValueFile_des((uint8_t)des_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDecreaseValueFile_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_13k3des(JNIEnv *env, jobject instance, jbyte des3_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDecreaseValueFile_3k3des((uint8_t)des3_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0); 
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDecreaseValueFile_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0); 
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDecreaseValueFile_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0); 
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDecreaseValueFile_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDecreaseValueFileAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireDecreaseValueFileAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDecreaseValueFile3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireDecreaseValueFile3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDecreaseValueFileDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireDecreaseValueFileDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDecreaseValueFile2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireDecreaseValueFile2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint32_t)aid_key_nr, (int32_t)file_id, (int32_t)communication_settings, (int32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetApplicationIds(JNIEnv *env, jobject instance, jbyte aes_key_nr,  jintArray application_ids, jbyteArray number_of_aplication_ids, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jint *application_ids_ = env->GetIntArrayElements(application_ids, 0);
		jbyte *number_of_application_ids_ = env->GetByteArrayElements(number_of_aplication_ids, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetApplicationIds((uint8_t)aes_key_nr, (uint32_t *)application_ids, (uint8_t *)number_of_aplication_ids, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseIntArrayElements(application_ids, application_ids_, 0);
		env->ReleaseByteArrayElements(number_of_aplication_ids, number_of_application_ids_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetApplicationIds_1des(JNIEnv *env, jobject instance, jbyte des_key_nr,  jintArray application_ids, jbyteArray number_of_aplication_ids, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jint *application_ids_ = env->GetIntArrayElements(application_ids, 0);
		jbyte *number_of_application_ids_ = env->GetByteArrayElements(number_of_aplication_ids, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetApplicationIds_des((uint8_t)des_key_nr, (uint32_t *)application_ids, (uint8_t *)number_of_aplication_ids, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseIntArrayElements(application_ids, application_ids_, 0);
		env->ReleaseByteArrayElements(number_of_aplication_ids, number_of_application_ids_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetApplicationIds_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr,  jintArray application_ids, jbyteArray number_of_aplication_ids, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jint *application_ids_ = env->GetIntArrayElements(application_ids, 0);
		jbyte *number_of_application_ids_ = env->GetByteArrayElements(number_of_aplication_ids, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetApplicationIds_2k3des((uint8_t)des2k_key_nr, (uint32_t *)application_ids, (uint8_t *)number_of_aplication_ids, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseIntArrayElements(application_ids, application_ids_, 0);
		env->ReleaseByteArrayElements(number_of_aplication_ids, number_of_application_ids_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_int_DesfireGetApplicationIds_3k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr,  jintArray application_ids, jbyteArray number_of_aplication_ids, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jint *application_ids_ = env->GetIntArrayElements(application_ids, 0);
		jbyte *number_of_application_ids_ = env->GetByteArrayElements(number_of_aplication_ids, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetApplicationIds_3k3des((uint8_t)des3k_key_nr, (uint32_t *)application_ids, (uint8_t *)number_of_aplication_ids, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseIntArrayElements(application_ids, application_ids_, 0);
		env->ReleaseByteArrayElements(number_of_aplication_ids, number_of_application_ids_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireGetApplicationIdsAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr,  jintArray application_ids, jbyteArray number_of_aplication_ids, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jint *application_ids_ = env->GetIntArrayElements(application_ids, 0);
		jbyte *number_of_application_ids_ = env->GetByteArrayElements(number_of_aplication_ids, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireGetApplicationIdsAesAuth((uint8_t)aes_key_nr, (uint32_t *)application_ids, (uint8_t *)number_of_aplication_ids, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseIntArrayElements(application_ids, application_ids_, 0);
		env->ReleaseByteArrayElements(number_of_aplication_ids, number_of_application_ids_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_SAM_DesfireGetApplicationIds3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr,  jintArray application_ids, jbyteArray number_of_aplication_ids, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jint *application_ids_ = env->GetIntArrayElements(application_ids, 0);
		jbyte *number_of_application_ids_ = env->GetByteArrayElements(number_of_aplication_ids, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireGetApplicationIds3k3desAuth((uint8_t)des3k_key_nr, (uint32_t *)application_ids, (uint8_t *)number_of_aplication_ids, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseIntArrayElements(application_ids, application_ids_, 0);
		env->ReleaseByteArrayElements(number_of_aplication_ids, number_of_application_ids_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_SAM_DesfireGetApplicationIdsDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr,  jintArray application_ids, jbyteArray number_of_aplication_ids, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jint *application_ids_ = env->GetIntArrayElements(application_ids, 0);
		jbyte *number_of_application_ids_ = env->GetByteArrayElements(number_of_aplication_ids, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireGetApplicationIdsDesAuth((uint8_t)des_key_nr, (uint32_t *)application_ids, (uint8_t *)number_of_aplication_ids, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseIntArrayElements(application_ids, application_ids_, 0);
		env->ReleaseByteArrayElements(number_of_aplication_ids, number_of_application_ids_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_SAM_DesfireGetApplicationIds2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr,  jintArray application_ids, jbyteArray number_of_aplication_ids, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jint *application_ids_ = env->GetIntArrayElements(application_ids, 0);
		jbyte *number_of_application_ids_ = env->GetByteArrayElements(number_of_aplication_ids, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireGetApplicationIds2k3desAuth((uint8_t)des2k_key_nr, (uint32_t *)application_ids, (uint8_t *)number_of_aplication_ids, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseIntArrayElements(application_ids, application_ids_, 0);
		env->ReleaseByteArrayElements(number_of_aplication_ids, number_of_application_ids_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetApplicationIds_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext,  jintArray application_ids, jbyteArray number_of_aplication_ids, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jint *application_ids_ = env->GetIntArrayElements(application_ids, 0);
		jbyte *number_of_application_ids_ = env->GetByteArrayElements(number_of_aplication_ids, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetApplicationIds_PK((uint8_t *)aes_key_ext_, (uint32_t *)application_ids, (uint8_t *)number_of_aplication_ids, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseIntArrayElements(application_ids, application_ids_, 0);
		env->ReleaseByteArrayElements(number_of_aplication_ids, number_of_application_ids_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetApplicationIds_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext,  jintArray application_ids, jbyteArray number_of_aplication_ids, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jint *application_ids_ = env->GetIntArrayElements(application_ids, 0);
		jbyte *number_of_application_ids_ = env->GetByteArrayElements(number_of_aplication_ids, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetApplicationIds_des_PK((uint8_t *)des_key_ext_, (uint32_t *)application_ids, (uint8_t *)number_of_aplication_ids, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseIntArrayElements(application_ids, application_ids_, 0);
		env->ReleaseByteArrayElements(number_of_aplication_ids, number_of_application_ids_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetApplicationIds_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext,  jintArray application_ids, jbyteArray number_of_aplication_ids, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jint *application_ids_ = env->GetIntArrayElements(application_ids, 0);
		jbyte *number_of_application_ids_ = env->GetByteArrayElements(number_of_aplication_ids, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetApplicationIds_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t *)application_ids, (uint8_t *)number_of_aplication_ids, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseIntArrayElements(application_ids, application_ids_, 0);
		env->ReleaseByteArrayElements(number_of_aplication_ids, number_of_application_ids_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetApplicationIds_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext,  jintArray application_ids, jbyteArray number_of_aplication_ids, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jint *application_ids_ = env->GetIntArrayElements(application_ids, 0);
		jbyte *number_of_application_ids_ = env->GetByteArrayElements(number_of_aplication_ids, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetApplicationIds_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t *)application_ids, (uint8_t *)number_of_aplication_ids, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseIntArrayElements(application_ids, application_ids_, 0);
		env->ReleaseByteArrayElements(number_of_aplication_ids, number_of_application_ids_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetApplicationIds_1no_1auth(JNIEnv *env, jobject instance,  jintArray application_ids, jbyteArray number_of_aplication_ids, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jint *application_ids_ = env->GetIntArrayElements(application_ids, 0);
		jbyte *number_of_application_ids_ = env->GetByteArrayElements(number_of_aplication_ids, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetApplicationIds_no_auth((uint32_t *)application_ids, (uint8_t *)number_of_aplication_ids, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseIntArrayElements(application_ids, application_ids_, 0);
		env->ReleaseByteArrayElements(number_of_aplication_ids, number_of_application_ids_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateLinearRecordFile_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateLinearRecordFile_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateLinearRecordFile_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateLinearRecordFile_des((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateLinearRecordFile_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateLinearRecordFile_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateLinearRecordFile_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateLinearRecordFile_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateLinearRecordFileAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateLinearRecordFileAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateLinearRecordFile3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateLinearRecordFile3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateLinearRecordFileDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateLinearRecordFileDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateLinearRecordFile2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateLinearRecordFile2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateLinearRecordFile_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateLinearRecordFile_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateLinearRecordFile_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateLinearRecordFile_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateLinearRecordFile_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateLinearRecordFile_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateLinearRecordFile_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateLinearRecordFile_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateLinearRecordFile_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateLinearRecordFile_no_auth((uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateCyclicRecordFile_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateCyclicRecordFile_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateCyclicRecordFile_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateCyclicRecordFile_des((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateCyclicRecordFile_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateCyclicRecordFile_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateCyclicRecordFile_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateCyclicRecordFile_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateCyclicRecordFileAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateCyclicRecordFileAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateCyclicRecordFile3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateCyclicRecordFile3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateCyclicRecordFileDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateCyclicRecordFileDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateCyclicRecordFile2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireCreateCyclicRecordFile2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateCyclicRecordFile_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext , 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateCyclicRecordFile_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateCyclicRecordFile_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext , 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateCyclicRecordFile_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateCyclicRecordFile_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext , 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateCyclicRecordFile_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateCyclicRecordFile_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext , 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateCyclicRecordFile_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateCyclicRecordFile_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte file_id, jint record_size, jint max_rec_no, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateCyclicRecordFile_no_auth((uint32_t)aid, (uint8_t)file_id, (uint8_t)record_size, (uint8_t)max_rec_no, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteRecord_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireWriteRecord_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteRecord_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireWriteRecord_des((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteRecord_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireWriteRecord_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteRecord_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireWriteRecord_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireWriteRecordAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireWriteRecordAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireWriteRecord3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireWriteRecord3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireWriteRecordDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireWriteRecordDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireWriteRecord2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireWriteRecord2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteRecord_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireWriteRecord_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteRecord_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireWriteRecord_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteRecord_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireWriteRecord_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteRecord_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireWriteRecord_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteRecord_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireWriteRecord_no_auth((uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadRecords_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort number_of_records, jshort record_size, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadRecords_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)number_of_records, (uint16_t)record_size, (uint8_t) communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadRecords_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort number_of_records, jshort record_size, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadRecords_des((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)number_of_records, (uint16_t)record_size, (uint8_t) communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadRecords_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort number_of_records, jshort record_size, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadRecords_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)number_of_records, (uint16_t)record_size, (uint8_t) communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadRecords_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort number_of_records, jshort record_size, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadRecords_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)number_of_records, (uint16_t)record_size, (uint8_t) communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireReadRecordsAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort number_of_records, jshort record_size, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireReadRecordsAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)number_of_records, (uint16_t)record_size, (uint8_t) communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireReadRecords3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort number_of_records, jshort record_size, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireReadRecords3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)number_of_records, (uint16_t)record_size, (uint8_t) communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireReadRecordsDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort number_of_records, jshort record_size, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireReadRecordsDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)number_of_records, (uint16_t)record_size, (uint8_t) communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireReadRecords2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort number_of_records, jshort record_size, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireReadRecords2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)number_of_records, (uint16_t)record_size, (uint8_t) communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadRecords_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort number_of_records, jshort record_size, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadRecords_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)number_of_records, (uint16_t)record_size, (uint8_t) communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadRecords_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort number_of_records, jshort record_size, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadRecords_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)number_of_records, (uint16_t)record_size, (uint8_t) communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadRecords_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort number_of_records, jshort record_size, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadRecords_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)number_of_records, (uint16_t)record_size, (uint8_t) communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadRecords_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort number_of_records, jshort record_size, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadRecords_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)number_of_records, (uint16_t)record_size, (uint8_t) communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadRecords_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort number_of_records, jshort record_size, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadRecords_no_auth((uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)number_of_records, (uint16_t)record_size, (uint8_t) communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireClearRecordFile_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireClearRecordFile_des((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireClearRecordFile_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireClearRecordFile_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireClearRecordFileAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireClearRecordFileAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireClearRecordFile3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireClearRecordFile3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireClearRecordFileDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireClearRecordFileDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireClearRecordFile2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireClearRecordFile2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireClearRecordFile_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireClearRecordFile_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireClearRecordFile_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireClearRecordFile_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireClearRecordFile_no_auth((uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}
	
	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1aes_12(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireClearRecordFile_aes_2((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1des_12(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireClearRecordFile_des_2((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_12k3des_12(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireClearRecordFile_2k3des_2((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_13k3des_12(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireClearRecordFile_3k3des_2((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireClearRecordFileAesAuth_12(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireClearRecordFileAesAuth_2((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireClearRecordFile3k3desAuth_12(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireClearRecordFile3k3desAuth_2((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireClearRecordFileDesAuth_12(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireClearRecordFileDesAuth_2((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireClearRecordFile2k3desAuth_12(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_SAM_DesfireClearRecordFile2k3desAuth_2((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1aes_1PK_12(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireClearRecordFile_aes_PK_2((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1des_1PK_12(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireClearRecordFile_des_PK_2((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_12k3des_1PK_12(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireClearRecordFile_2k3des_PK_2((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_13k3des_1PK_12(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireClearRecordFile_3k3des_PK_2((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_GetReaderParameters(JNIEnv *env, jobject instance,  jbyteArray mui,  jbyteArray serial_nr, jbyteArray hw_type, jbyteArray hw_ver, jbyteArray device_type, jbyteArray fw_ver_major, jbyteArray fw_ver_minor, jbyteArray fw_ver_build) {
		
		UFR_STATUS status;
		
		jbyte *mui_ = env->GetByteArrayElements(mui, 0);
		jbyte *serial_nr_ = env->GetByteArrayElements(serial_nr, 0);
		jbyte *hw_type_ = env->GetByteArrayElements(hw_type, 0);
		jbyte *hw_ver_ = env->GetByteArrayElements(hw_ver, 0);
		jbyte *device_type_ = env->GetByteArrayElements(device_type, 0);
		jbyte *fw_ver_major_ = env->GetByteArrayElements(fw_ver_major, 0);
		jbyte *fw_ver_minor_ = env->GetByteArrayElements(fw_ver_minor, 0);
		jbyte *fw_ver_build_ = env->GetByteArrayElements(fw_ver_build, 0);
		
		status = GetReaderParameters((uint8_t *)mui_, (uint8_t *)serial_nr_, (uint8_t *)hw_type_, (uint8_t *)hw_ver_, (uint8_t *)device_type_, (uint8_t *)fw_ver_major_, (uint8_t *)fw_ver_minor_, (uint8_t *)fw_ver_build_);
		
		env->ReleaseByteArrayElements(mui, mui_, 0);
		env->ReleaseByteArrayElements(serial_nr, serial_nr_, 0);
		env->ReleaseByteArrayElements(hw_type, hw_type_, 0);
		env->ReleaseByteArrayElements(hw_ver, hw_ver_, 0);
		env->ReleaseByteArrayElements(device_type, device_type_, 0);
		env->ReleaseByteArrayElements(fw_ver_major, fw_ver_major_, 0);
		env->ReleaseByteArrayElements(fw_ver_minor, fw_ver_minor_, 0);
		env->ReleaseByteArrayElements(fw_ver_build, fw_ver_build_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_SAM_1get_1key_1entry_1raw(JNIEnv *env, jobject instance, jbyte key_no,  jbyteArray key_entry, jbyteArray key_length,  jbyteArray apdu_sw) {
		
		UFR_STATUS status;
		
		jbyte *key_entry_ = env->GetByteArrayElements(key_entry, 0);
		jbyte *key_length_ = env->GetByteArrayElements(key_length, 0);
		jbyte *apdu_sw_ = env->GetByteArrayElements(apdu_sw, 0);
		
		status = SAM_get_key_entry_raw((uint8_t)key_no, (uint8_t *)key_entry_, (uint8_t *)key_length, (uint8_t *)apdu_sw);
		
		env->ReleaseByteArrayElements(key_entry, key_entry_, 0);
		env->ReleaseByteArrayElements(key_length, key_length_, 0);
		env->ReleaseByteArrayElements(apdu_sw, apdu_sw_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_SAM_1authenticate_1host_1no_1div_1des(JNIEnv *env, jobject instance, jbyte key_no, jbyte key_v,  jbyteArray des_key) {
		
		UFR_STATUS status;

		jbyte *des_key_ = env->GetByteArrayElements(des_key, 0);
		
		status = SAM_authenticate_host_no_div_des((uint8_t)key_no, (uint8_t)key_v, (uint8_t *)des_key_);
		
		env->ReleaseByteArrayElements(des_key, des_key_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_SAM_1pre_1pesonalization_1master_1AES128_1key(JNIEnv *env, jobject instance,  jbyteArray aes_key_ver_a, jbyte ver_a,  jbyteArray aes_key_ver_b, jbyte ver_b,  jbyteArray aes_key_ver_c, jbyte ver_c,  jbyteArray apdu_sw) {
		
		UFR_STATUS status;

		jbyte *aes_key_ver_a_ = env->GetByteArrayElements(aes_key_ver_a, 0);
		jbyte *aes_key_ver_b_ = env->GetByteArrayElements(aes_key_ver_b, 0);
		jbyte *aes_key_ver_c_ = env->GetByteArrayElements(aes_key_ver_c, 0);
		jbyte *apdu_sw_ = env->GetByteArrayElements(apdu_sw, 0);
		
		status = SAM_pre_pesonalization_master_AES128_key((uint8_t *)aes_key_ver_a_, (uint8_t)ver_a, (uint8_t *)aes_key_ver_b_, (uint8_t)ver_b, (uint8_t *)aes_key_ver_c_, (uint8_t)ver_c, (uint8_t *)apdu_sw_);
		
		env->ReleaseByteArrayElements(aes_key_ver_a, aes_key_ver_a_, 0);
		env->ReleaseByteArrayElements(aes_key_ver_b, aes_key_ver_b_, 0);
		env->ReleaseByteArrayElements(aes_key_ver_c, aes_key_ver_c_, 0);
		env->ReleaseByteArrayElements(apdu_sw, apdu_sw_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_SAM_1pre_1personalization_1switch_1to_1AV2_1mode(JNIEnv *env, jobject instance,  jbyteArray master_aes_key, jbyte key_version,  jbyteArray apdu_sw) {
		
		UFR_STATUS status;

		jbyte *master_aes_key_ = env->GetByteArrayElements(master_aes_key, 0);
		jbyte *apdu_sw_ = env->GetByteArrayElements(apdu_sw, 0);
		
		status = SAM_pre_personalization_switch_to_AV2_mode((uint8_t *)master_aes_key_, (uint8_t)key_version, (uint8_t *)apdu_sw_);
		
		env->ReleaseByteArrayElements(master_aes_key, master_aes_key_, 0);
		env->ReleaseByteArrayElements(apdu_sw, apdu_sw_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_SAM_1authenticate_1host_1AV2_1plain(JNIEnv *env, jobject instance,  jbyteArray master_aes_key, jbyte key_nr, jbyte key_version,  jbyteArray apdu_sw) {
		
		UFR_STATUS status;

		jbyte *master_aes_key_ = env->GetByteArrayElements(master_aes_key, 0);
		jbyte *apdu_sw_ = env->GetByteArrayElements(apdu_sw, 0);
		
		status = SAM_authenticate_host_AV2_plain((uint8_t *)master_aes_key_, (uint8_t)key_nr, (uint8_t)key_version, (uint8_t *)apdu_sw_);
		
		env->ReleaseByteArrayElements(master_aes_key, master_aes_key_, 0);
		env->ReleaseByteArrayElements(apdu_sw, apdu_sw_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_SAM_1change_1key_1entry_1mifare_1AV2_1plain_1one_1key(JNIEnv *env, jobject instance, jbyte key_entry_no,  jbyteArray keyA,  jbyteArray keyB, jbyte key_no_CEK, jbyte key_v_CEK, jbyte ref_no_KUC,  jbyteArray apdu_sw) {
		
		UFR_STATUS status;
		
		jbyte *keyA_ = env->GetByteArrayElements(keyA, 0);
		jbyte *keyB_ = env->GetByteArrayElements(keyB, 0);
		jbyte *apdu_sw_ = env->GetByteArrayElements(apdu_sw, 0);
		
		status = SAM_change_key_entry_mifare_AV2_plain_one_key((uint8_t)key_entry_no, (uint8_t *)keyA_, (uint8_t *)keyB_, (uint8_t)key_no_CEK, (uint8_t)key_v_CEK, (uint8_t)ref_no_KUC, (uint8_t *)apdu_sw_);
		
		env->ReleaseByteArrayElements(keyA, keyA_, 0);
		env->ReleaseByteArrayElements(keyB, keyB_, 0);
		env->ReleaseByteArrayElements(apdu_sw, apdu_sw_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_SAM_1change_1key_1entry_1AES_1AV2_1plain_1one_1key(JNIEnv *env, jobject instance, jbyte key_entry_no,  jbyteArray key, jbyte key_no_CEK, jbyte key_v_CEK, jbyte ref_no_KUC,  jbyteArray apdu_sw) {
		
		UFR_STATUS status;

		jbyte *key_ = env->GetByteArrayElements(key, 0);
		jbyte *apdu_sw_ = env->GetByteArrayElements(apdu_sw, 0);
		
		status = SAM_change_key_entry_AES_AV2_plain_one_key((uint8_t)key_entry_no, (uint8_t *)key_, (uint8_t)key_no_CEK, (uint8_t)key_v_CEK, (uint8_t)ref_no_KUC, (uint8_t *)apdu_sw_);
		
		env->ReleaseByteArrayElements(key, key_, 0);
		env->ReleaseByteArrayElements(apdu_sw, apdu_sw_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_SAM_1change_1key_1entry_13K3DES_1AV2_1plain_1one_1key(JNIEnv *env, jobject instance, jbyte key_entry_no,  jbyteArray key, jbyte key_no_CEK, jbyte key_v_CEK, jbyte ref_no_KUC,  jbyteArray apdu_sw) {
		
		UFR_STATUS status;

		jbyte *key_ = env->GetByteArrayElements(key, 0);
		jbyte *apdu_sw_ = env->GetByteArrayElements(apdu_sw, 0);
		
		status = SAM_change_key_entry_3K3DES_AV2_plain_one_key((uint8_t)key_entry_no, (uint8_t *)key_, (uint8_t)key_no_CEK, (uint8_t)key_v_CEK, (uint8_t)ref_no_KUC, (uint8_t *)apdu_sw_);
		
		env->ReleaseByteArrayElements(key, key_, 0);
		env->ReleaseByteArrayElements(apdu_sw, apdu_sw_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_SAM_1change_1key_1entry_12K3DES_1ULC_1AV2_1plain_1one_1key(JNIEnv *env, jobject instance, jbyte key_entry_no,  jbyteArray key, jbyte key_no_CEK, jbyte key_v_CEK, jbyte ref_no_KUC,  jbyteArray apdu_sw) {
		
		UFR_STATUS status;
		
		jbyte *key_ = env->GetByteArrayElements(key, 0);
		jbyte *apdu_sw_ = env->GetByteArrayElements(apdu_sw, 0);
		
		status = SAM_change_key_entry_2K3DES_ULC_AV2_plain_one_key((uint8_t)key_entry_no, (uint8_t *)key_, (uint8_t)key_no_CEK, (uint8_t)key_v_CEK, (uint8_t)ref_no_KUC, (uint8_t *)apdu_sw_);
		
		env->ReleaseByteArrayElements(key, key_, 0);
		env->ReleaseByteArrayElements(apdu_sw, apdu_sw_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_SAM_1change_1key_1entry_12K3DES_1desfire_1AV2_1plain_1one_1key(JNIEnv *env, jobject instance, jbyte key_entry_no,  jbyteArray key, jbyte key_no_CEK, jbyte key_v_CEK, jbyte ref_no_KUC,  jbyteArray apdu_sw) {
		
		UFR_STATUS status;
		
		jbyte *key_ = env->GetByteArrayElements(key, 0);
		jbyte *apdu_sw_ = env->GetByteArrayElements(apdu_sw, 0);
		
		status = SAM_change_key_entry_2K3DES_desfire_AV2_plain_one_key((uint8_t)key_entry_no, (uint8_t *)key_, (uint8_t)key_no_CEK, (uint8_t)key_v_CEK, (uint8_t)ref_no_KUC, (uint8_t *)apdu_sw_);
		
		env->ReleaseByteArrayElements(key, key_, 0);
		env->ReleaseByteArrayElements(apdu_sw, apdu_sw_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_SAM_1change_1key_1entry_1DES_1AV2_1plain_1one_1key(JNIEnv *env, jobject instance, jbyte key_entry_no,  jbyteArray key, jbyte key_no_CEK, jbyte key_v_CEK, jbyte ref_no_KUC,  jbyteArray apdu_sw) {
		
		UFR_STATUS status;
		
		jbyte *key_ = env->GetByteArrayElements(key, 0);
		jbyte *apdu_sw_ = env->GetByteArrayElements(apdu_sw, 0);
		
		status = SAM_change_key_entry_DES_AV2_plain_one_key((uint8_t)key_entry_no, (uint8_t *)key_, (uint8_t)key_no_CEK, (uint8_t)key_v_CEK, (uint8_t)ref_no_KUC, (uint8_t *)apdu_sw_);
		
		env->ReleaseByteArrayElements(key, key_, 0);
		env->ReleaseByteArrayElements(apdu_sw, apdu_sw_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_SAM_1change_1key_1entry_1aes_1AV2_1plain_1host_1key(JNIEnv *env, jobject instance, jbyte key_entry_no,  jbyteArray aes_key_ver_a, jbyte ver_a,  jbyteArray aes_key_ver_b, jbyte ver_b,  jbyteArray aes_key_ver_c, jbyte ver_c, jbyte key_no_CEK, jbyte key_v_CEK, jbyte ref_no_KUC, jbyte sam_lock_unlock, jbyte sam_auth_host, jbyteArray apdu_sw) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ver_a_ = env->GetByteArrayElements(aes_key_ver_a, 0);
		jbyte *aes_key_ver_b_ = env->GetByteArrayElements(aes_key_ver_b, 0);
		jbyte *aes_key_ver_c_ = env->GetByteArrayElements(aes_key_ver_c, 0);
		jbyte *apdu_sw_ = env->GetByteArrayElements(apdu_sw, 0);
		
		status = SAM_change_key_entry_aes_AV2_plain_host_key((uint8_t)key_entry_no, (uint8_t *)aes_key_ver_a_, (uint8_t)ver_a, (uint8_t *)aes_key_ver_b_, (uint8_t)ver_b, (uint8_t *)aes_key_ver_c_, (uint8_t)ver_c, (uint8_t)key_no_CEK, (uint8_t)key_v_CEK, (uint8_t)ref_no_KUC, (uint8_t)sam_lock_unlock, (uint8_t)sam_auth_host, (uint8_t *)apdu_sw_);
		
		env->ReleaseByteArrayElements(aes_key_ver_a, aes_key_ver_a_, 0);
		env->ReleaseByteArrayElements(aes_key_ver_b, aes_key_ver_b_, 0);
		env->ReleaseByteArrayElements(aes_key_ver_c, aes_key_ver_c_, 0);
		env->ReleaseByteArrayElements(apdu_sw, apdu_sw_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_WriteSamUnlockKey(JNIEnv *env, jobject instance, jbyte key_no, jbyte key_ver,  jbyteArray aes_key) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ = env->GetByteArrayElements(aes_key, 0);

		status = WriteSamUnlockKey((uint8_t)key_no, (uint8_t)key_ver, (uint8_t *)aes_key_);
		
		env->ReleaseByteArrayElements(aes_key, aes_key_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_MFP_1ChangeConfigurationKeySamKey(JNIEnv *env, jobject instance, jbyte key_index, jbyte new_key_index) {
		
		UFR_STATUS status;
		
		status = MFP_ChangeConfigurationKeySamKey((uint8_t)key_index, (uint8_t)new_key_index);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_MFP_1FieldConfigurationSetSamKey(JNIEnv *env, jobject instance, jbyte configuration_key_index, jbyte rid_use, jbyte prox_check_use) {
		
		UFR_STATUS status;

		status = MFP_FieldConfigurationSetSamKey((uint8_t)configuration_key_index, (uint8_t)rid_use, (uint8_t)prox_check_use);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_MFP_1GetUidSamKey(JNIEnv *env, jobject instance, jbyte key_index_vc_poll_enc_key, jbyte key_index_vc_poll_mac_key,  jbyteArray uid, jbyteArray uid_len) {
		
		UFR_STATUS status;
		
		jbyte *uid_ = env->GetByteArrayElements(uid, 0);
		jbyte *uid_len_ = env->GetByteArrayElements(uid_len, 0);
		
		status = MFP_GetUidSamKey((uint8_t)key_index_vc_poll_enc_key, (uint8_t)key_index_vc_poll_mac_key, (uint8_t *)uid_, (uint8_t *)uid_len_);

		env->ReleaseByteArrayElements(uid, uid_, 0);
		env->ReleaseByteArrayElements(uid_len, uid_len_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_MFP_1ChangeVcPollingEncKeySamKey(JNIEnv *env, jobject instance, jbyte configuration_key_index, jbyte new_key_index) {
		
		UFR_STATUS status;

		status = MFP_ChangeVcPollingEncKeySamKey((uint8_t)configuration_key_index, (uint8_t)new_key_index);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_MFP_1ChangeVcPollingMacKeySamKey(JNIEnv *env, jobject instance, jbyte configuration_key_index, jbyte new_key_index) {
		
		UFR_STATUS status;
		
		status = MFP_ChangeVcPollingMacKeySamKey((uint8_t)configuration_key_index, (uint8_t)new_key_index);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_DESFIRE_Start(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		status = uFR_DESFIRE_Start();

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_DESFIRE_Stop(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		status = uFR_DESFIRE_Stop();

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_APDU_Start(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		status = uFR_APDU_Start();

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_APDU_Stop(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		status = uFR_APDU_Stop();

		return status;
	}



	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1GetDesfireUid_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr,  jbyteArray card_uid, jbyteArray card_uid_len, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
		jbyte *card_uid_len_ = env->GetByteArrayElements(card_uid_len, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_GetDesfireUid_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)card_uid_len_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
		env->ReleaseByteArrayElements(card_uid_len, card_uid_len_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1GetDesfireUid_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr,  jbyteArray card_uid, jbyteArray card_uid_len, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
		jbyte *card_uid_len_ = env->GetByteArrayElements(card_uid_len, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_GetDesfireUid_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)card_uid_len_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
		env->ReleaseByteArrayElements(card_uid_len, card_uid_len_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireFormatCard_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireFormatCard_aes((uint8_t)aes_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireFormatCard_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireFormatCard_aes_PK((uint8_t *)aes_key_ext_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateStdDataFile_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte file_id, jint file_size, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateStdDataFile_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint32_t)file_size, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateStdDataFile_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte file_id, jint file_size, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateStdDataFile_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint32_t)file_size, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteFile_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDeleteFile_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteFile_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDeleteFile_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateAesApplication_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateAesApplication_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateAesApplication_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateAesApplication_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreate3k3desApplication_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreate3k3desApplication_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateDesApplication_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte setting, jbyte max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateDesApplication_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)setting, (uint8_t)max_key_no, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDeleteApplication_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDeleteApplication_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireSetConfiguration_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jbyte random_uid, jbyte format_disable, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireSetConfiguration_aes((uint8_t)aes_key_nr, (uint8_t)random_uid, (uint8_t)format_disable, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireSetConfiguration_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jbyte random_uid, jbyte format_disable, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireSetConfiguration_aes_PK((uint8_t *)aes_key_ext_, (uint8_t)random_uid, (uint8_t)format_disable, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetKeySettings_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyteArray setting, jbyteArray max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *setting_ = env->GetByteArrayElements(setting, 0);
		jbyte *max_key_no_ = env->GetByteArrayElements(max_key_no, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetKeySettings_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t *)setting_, (uint8_t *)max_key_no_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(setting, setting_, 0);
		env->ReleaseByteArrayElements(max_key_no, max_key_no_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetKeySettings_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyteArray setting, jbyteArray max_key_no, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jbyte *setting_ = env->GetByteArrayElements(setting, 0);
		jbyte *max_key_no_ = env->GetByteArrayElements(max_key_no, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetKeySettings_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t *)setting_, (uint8_t *)max_key_no_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseByteArrayElements(setting, setting_, 0);
		env->ReleaseByteArrayElements(max_key_no, max_key_no_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeKeySettings_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte setting, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChangeKeySettings_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)setting, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeKeySettings_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte setting, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChangeKeySettings_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)setting, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeAesKey_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_no_auth, jbyte new_aes_key_nr, jbyte aid_key_no, jbyte old_aes_key_nr, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChangeAesKey_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_no_auth, (uint8_t)new_aes_key_nr, (uint8_t)aid_key_no, (uint8_t)old_aes_key_nr, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireChangeAesKey_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_no_auth,  jbyteArray new_aes_key, jbyte aid_key_no,  jbyteArray old_aes_key, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jbyte *new_aes_key_ = env->GetByteArrayElements(new_aes_key, 0);
		jbyte *old_aes_key_ = env->GetByteArrayElements(old_aes_key, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireChangeAesKey_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)aid_key_no_auth, (uint8_t *)new_aes_key_, (uint8_t)aid_key_no, (uint8_t *)old_aes_key_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseByteArrayElements(new_aes_key, new_aes_key_, 0);
		env->ReleaseByteArrayElements(old_aes_key, old_aes_key_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadStdDataFile_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadStdDataFile_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadStdDataFile_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadStdDataFile_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteStdDataFile_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireWriteStdDataFile_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteStdDataFile_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jbyte *data_ = env->GetByteArrayElements(data, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireWriteStdDataFile_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseByteArrayElements(data, data_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateValueFile_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte file_id, jint lower_limit, jint upper_limit, jint value, jbyte limited_credit_enabled, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;

		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateValueFile_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)file_id, (int32_t)lower_limit, (int32_t)upper_limit, (int32_t)value, (uint8_t)limited_credit_enabled, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateValueFile_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte file_id, jint lower_limit, jint upper_limit, jint value, jbyte limited_credit_enabled, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte communication_settings, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireCreateValueFile_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)file_id, (int32_t)lower_limit, (int32_t)upper_limit, (int32_t)value, (uint8_t)limited_credit_enabled, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadValueFile_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jintArray value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jint *value_ = env->GetIntArrayElements(value, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadValueFile_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (int32_t *)value_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseIntArrayElements(value, value_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireReadValueFile_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jintArray value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jint *value_ = env->GetIntArrayElements(value, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireReadValueFile_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (int32_t *)value_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseIntArrayElements(value, value_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireIncreaseValueFile_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireIncreaseValueFile_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDecreaseValueFile_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireDecreaseValueFile_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetApplicationIds_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr,  jintArray application_ids, jbyteArray number_of_aplication_ids, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jint *application_ids_ = env->GetIntArrayElements(application_ids, 0);
		jbyte *number_of_aplication_ids_ = env->GetByteArrayElements(number_of_aplication_ids, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetApplicationIds_aes((uint8_t)aes_key_nr, (uint32_t *)application_ids_, (uint8_t *)number_of_aplication_ids_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseIntArrayElements(application_ids, application_ids_, 0);
		env->ReleaseByteArrayElements(number_of_aplication_ids, number_of_aplication_ids_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetApplicationIds_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext,  jintArray application_ids, jbyteArray number_of_aplication_ids, jshortArray card_status, jshortArray exec_time) {
		
		UFR_STATUS status;
		
		jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
		jint *application_ids_ = env->GetIntArrayElements(application_ids, 0);
		jbyte *number_of_aplication_ids_ = env->GetByteArrayElements(number_of_aplication_ids, 0);
		jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
		jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
		
		status = uFR_int_DesfireGetApplicationIds_aes_PK((uint8_t *)aes_key_ext_, (uint32_t *)application_ids_, (uint8_t *)number_of_aplication_ids_, (uint16_t *)card_status_, (uint16_t *)exec_time_);
		
		env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
		env->ReleaseIntArrayElements(application_ids, application_ids_, 0);
		env->ReleaseByteArrayElements(number_of_aplication_ids, number_of_aplication_ids_, 0);
		env->ReleaseShortArrayElements(card_status, card_status_, 0);
		env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_CheckUidChangeable(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = CheckUidChangeable();

		 return status;
	}

	JNIEXPORT jint JNICALL  Java_com_dlogic_uFCoder_ReaderRfReset(JNIEnv *env, jobject instance) {
		
		UFR_STATUS status;

		 status = ReaderRfReset();

		 return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_DLGetHashOutputByteLength(JNIEnv *env, jobject instance, jint hash_algo, jintArray out_byte_len) {
		UFR_STATUS status;
		

		jint *out_byte_len_ = env->GetIntArrayElements(out_byte_len, 0);
		status = DLGetHashOutputByteLength((uint32_t)hash_algo, (uint32_t *)out_byte_len_);
		env->ReleaseIntArrayElements(out_byte_len, out_byte_len_, 0);
		
		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_DLGetHash(JNIEnv *env, jobject instance, int hash_algo, jbyteArray in, jbyteArray hash) {
		UFR_STATUS status;
		
		
		jbyte *in_ =  env->GetByteArrayElements(in, 0);
		jbyte *hash_ =  env->GetByteArrayElements(hash, 0);
		jsize in_len = env->GetArrayLength(in);
		jsize hash_alocated = env->GetArrayLength(hash);
		status = DLGetHash((uint32_t)hash_algo, (uint8_t *)in_, (uint32_t)in_len, (uint8_t *)hash_, (uint32_t)hash_alocated);
		env->ReleaseByteArrayElements(in, in_, 0);
		env->ReleaseByteArrayElements(hash, hash_, 0);

		return status;	
	}

	JNIEXPORT jbyteArray JNICALL
	Java_com_dlogic_uFCoder_DLGetHashToHeap(JNIEnv *env, jobject instance, jintArray status, jint hash_algo, jbyteArray in) {
		
		uint8_t *hash;
		uint32_t hash_len;

		jint *status_ =  env->GetIntArrayElements(status, 0);
		jbyte *in_ =  env->GetByteArrayElements(in, 0);
		jsize in_len = env->GetArrayLength(in);
		status_[0] = DLGetHashToHeap((uint32_t)hash_algo, (uint8_t *)in_, (uint32_t)in_len, &hash, &hash_len);
		env->ReleaseIntArrayElements(status, status_, 0);
		env->ReleaseByteArrayElements(in, in_, 0);

        jbyteArray ret;
		
		if(status_[0] == 0)
		{
			if (hash) {
				
  		    ret = env->NewByteArray((jsize) hash_len);
  		    env->SetByteArrayRegion(ret, 0, (jsize) hash_len, (jbyte *) hash);
  		    DLFree(hash);
			
			}
			else
			{
				return NULL;
			}
		}
		else
		{
			return NULL;
		}

		return ret;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_DLHashInitChunked(JNIEnv *env, jobject instance, jint hash_algo) {
		UFR_STATUS status;
		

		status = DLHashInitChunked((uint32_t)hash_algo);

		return status;	
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_DLHashUpdateChunked(JNIEnv *env, jobject instance, jbyteArray in) {
		UFR_STATUS status;
		

		jbyte *in_ =  env->GetByteArrayElements(in, 0);
		jsize in_len = env->GetArrayLength(in);
		status = DLHashUpdateChunked((uint8_t *)in_, (uint32_t)in_len);
		env->ReleaseByteArrayElements(in, in_, 0);

		return status;	
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_DLHashFinishChunked(JNIEnv *env, jobject instance, jbyteArray hash) {
		UFR_STATUS status;
		

		jbyte *hash_ =  env->GetByteArrayElements(hash, 0);
		jsize hash_alocated = env->GetArrayLength(hash);
		status = DLHashFinishChunked((uint8_t *)hash_, (uint32_t)hash_alocated);
		env->ReleaseByteArrayElements(hash, hash_, 0);

		return status;	
	}

	JNIEXPORT jbyteArray JNICALL
	Java_com_dlogic_uFCoder_DLHashFinishChunkedToHeap(JNIEnv *env, jobject instance, jintArray status) {
		
		uint8_t *hash;
		uint32_t hash_len;

		jint *status_ =  env->GetIntArrayElements(status, 0);
		status_[0] = DLHashFinishChunkedToHeap(&hash, &hash_len);
		env->ReleaseIntArrayElements(status, status_, 0);

		jbyteArray ret;
		
		if(status_[0] == 0)
		{
			if (hash) {
				ret = env->NewByteArray((jsize) hash_len);
				env->SetByteArrayRegion(ret, 0, (jsize) hash_len, (jbyte *) hash);
				DLFree(hash);
			}
			else
			{
				return NULL;
			}
		}
		else
		{
			return NULL;
		}

		return ret;
	}

	JNIEXPORT jstring JNICALL
	Java_com_dlogic_uFCoder_DLGetHashName(JNIEnv *env, jobject instance, jint hash_algo) {
		

		c_string ret = DLGetHashName((uint32_t)hash_algo);
		
		return env->NewStringUTF(ret);
	}

	JNIEXPORT jstring JNICALL
	Java_com_dlogic_uFCoder_DLGetEccCurveName(JNIEnv *env, jobject instance, jint eccCurve) {
		

		c_string ret = DLGetEccCurveName((uint32_t)eccCurve);
		
		return env->NewStringUTF(ret);
	}

	JNIEXPORT jstring JNICALL
	Java_com_dlogic_uFCoder_DLGetSignatureSchemeName(JNIEnv *env, jobject instance, jint signatureScheme) {
		

		c_string ret = DLGetSignatureSchemeName((uint32_t)signatureScheme);
		
		return env->NewStringUTF(ret);
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_DigitalSignatureVerifyHash(JNIEnv *env, jobject instance, jint digest_alg, jint padding_alg, jint cypher_alg, jbyteArray tbs,
													   jbyteArray signature, jbyteArray sig_params, jbyteArray pub_key, jbyteArray pub_key_params) {
		UFR_STATUS status;
		

		jbyte *tbs_ = env->GetByteArrayElements(tbs, 0);
		jbyte *signature_ = env->GetByteArrayElements(signature, 0);
		jbyte *sig_params_ = env->GetByteArrayElements(sig_params, 0);
		jbyte *pub_key_ = env->GetByteArrayElements(pub_key, 0);
		jbyte *pub_key_params_ = env->GetByteArrayElements(pub_key_params, 0);
		jsize tbs_len = env->GetArrayLength(tbs);
		jsize signature_len = env->GetArrayLength(signature);
		jsize sig_params_len = env->GetArrayLength(sig_params);
		jsize pub_key_len = env->GetArrayLength(pub_key);
		jsize pub_key_params_len = env->GetArrayLength(pub_key_params);
		status = DigitalSignatureVerifyHash((uint32_t)digest_alg, (uint32_t)padding_alg, (uint32_t)cypher_alg, (uint8_t *)tbs_, (uint32_t)tbs_len, 
											(uint8_t *)signature_, (uint32_t)signature_len, (uint8_t *)sig_params_, (uint32_t)sig_params_len, 
											(uint8_t *)pub_key_, (uint32_t)pub_key_len, (uint8_t *)pub_key_params_, (uint32_t)pub_key_params_len);
		env->ReleaseByteArrayElements(tbs, tbs_, 0);
		env->ReleaseByteArrayElements(signature, signature_, 0);
		env->ReleaseByteArrayElements(sig_params, sig_params_, 0);
		env->ReleaseByteArrayElements(pub_key, pub_key_, 0);
		env->ReleaseByteArrayElements(pub_key_params, pub_key_params_, 0);

		return status;	
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_MRTDAppSelectAndAuthenticateBac(JNIEnv *env, jobject instance, jbyteArray mrz_proto_key, jbyteArray ksenc, jbyteArray ksmac, jlongArray send_sequence_cnt) {
		
		UFR_STATUS status;
		

		jbyte *mrz_proto_key_ = env->GetByteArrayElements(mrz_proto_key, 0);
		jbyte *ksenc_ = env->GetByteArrayElements(ksenc, 0);
		jbyte *ksmac_ = env->GetByteArrayElements(ksmac, 0);
		jlong *send_sequence_cnt_ = env->GetLongArrayElements(send_sequence_cnt, 0);

		status = MRTDAppSelectAndAuthenticateBac((uint8_t *)mrz_proto_key_, (uint8_t *)ksenc_, (uint8_t *)ksmac_, (uint64_t *)send_sequence_cnt_);

		env->ReleaseByteArrayElements(mrz_proto_key, mrz_proto_key_, 0);
		env->ReleaseByteArrayElements(ksenc, ksenc_, 0);
		env->ReleaseByteArrayElements(ksmac, ksmac_, 0);
		env->ReleaseLongArrayElements(send_sequence_cnt, send_sequence_cnt_, 0);

		return status;
	}

	JNIEXPORT jbyteArray JNICALL
	Java_com_dlogic_uFCoder_MRTDFileReadBacToHeap(JNIEnv *env, jobject instance, jintArray status, jbyteArray file_index, jbyteArray ksenc, jbyteArray ksmac, jlongArray send_sequence_cnt) {
		
		uint8_t *output;
		uint32_t output_length;

		jint *status_ =  env->GetIntArrayElements(status, 0);
		jbyte *file_index_ = env->GetByteArrayElements(file_index, 0);
		jbyte *ksenc_ = env->GetByteArrayElements(ksenc, 0);
		jbyte *ksmac_ = env->GetByteArrayElements(ksmac, 0);
		jlong *send_sequence_cnt_ = env->GetLongArrayElements(send_sequence_cnt, 0);
		status_[0] = MRTDFileReadBacToHeap((uint8_t *)file_index_, &output, &output_length, (uint8_t *)ksenc_, (uint8_t *)ksmac_, (uint64_t *)send_sequence_cnt_);
		env->ReleaseIntArrayElements(status, status_, 0);
		env->ReleaseByteArrayElements(file_index, file_index_, 0);
		env->ReleaseByteArrayElements(ksenc, ksenc_, 0);
		env->ReleaseByteArrayElements(ksmac, ksmac_, 0);
		env->ReleaseLongArrayElements(send_sequence_cnt, send_sequence_cnt_, 0);
        
        jbyteArray ret;
		
		if(status_[0] == 0)
		{
			if (output) {
				ret = env->NewByteArray((jsize) output_length);
				env->SetByteArrayRegion(ret, 0, (jsize) output_length, (jbyte *) output);
				DLFree(output);
			}
			else
			{
				return NULL;
			}
		}
		else
		{
			return NULL;
		}

		return ret;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_MRTD_1MRZDataToMRZProtoKey(JNIEnv *env, jobject instance, jstring doc_number, jstring date_of_birth, jstring date_of_expiry, jbyteArray mrz_proto_key) {
		UFR_STATUS status;
		

		const char *doc_number_ = env->GetStringUTFChars(doc_number, 0);
		const char *date_of_birth_ = env->GetStringUTFChars(date_of_birth, 0);
		const char *date_of_expiry_ = env->GetStringUTFChars(date_of_expiry, 0);
		jbyte *mrz_proto_key_ = env->GetByteArrayElements(mrz_proto_key, 0);

		status = MRTD_MRZDataToMRZProtoKey((const char *)doc_number_, (const char *)date_of_birth_, (const char *)date_of_expiry_, (uint8_t *)mrz_proto_key_);

		env->ReleaseStringUTFChars(doc_number, doc_number_);
		env->ReleaseStringUTFChars(date_of_birth, date_of_birth_);
		env->ReleaseStringUTFChars(date_of_expiry, date_of_expiry_);
		env->ReleaseByteArrayElements(mrz_proto_key, mrz_proto_key_, 0);

		return status;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_MRTD_1MRZSubjacentToMRZProtoKey(JNIEnv *env, jobject instance, jstring mrz, jbyteArray mrz_proto_key) {
		UFR_STATUS status;
		

		const char *mrz_ = env->GetStringUTFChars(mrz, 0);
		jbyte *mrz_proto_key_ = env->GetByteArrayElements(mrz_proto_key, 0);
		status = MRTD_MRZSubjacentToMRZProtoKey(mrz_, (uint8_t *)mrz_proto_key_);
		env->ReleaseStringUTFChars(mrz, mrz_);
		env->ReleaseByteArrayElements(mrz_proto_key, mrz_proto_key_, 0);

		return status;
	}
    
    JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_MRTD_1MRZSubjacentCheck(JNIEnv *env, jobject instance, jstring mrz) {
		UFR_STATUS status;
		

		const char *mrz_ = env->GetStringUTFChars(mrz, 0);
		status = MRTD_MRZSubjacentCheck(mrz_);
		env->ReleaseStringUTFChars(mrz, mrz_);

		return status;
    }

	JNIEXPORT jstring JNICALL
	Java_com_dlogic_uFCoder_MRTDValidate(JNIEnv *env, jobject instance, jintArray status, jstring cert_storage_folder, jstring endln, jint verbose_level,
										 jbyteArray ksenc, jbyteArray ksmac, jlongArray send_sequence_cnt) {
		
		char *out_str;

		jint *status_ =  env->GetIntArrayElements(status, 0);
		const char *cert_storage_folder_ = env->GetStringUTFChars(cert_storage_folder, 0);
		const char *endln_ = env->GetStringUTFChars(endln, 0);
		jbyte *ksenc_ = env->GetByteArrayElements(ksenc, 0);
		jbyte *ksmac_ = env->GetByteArrayElements(ksmac, 0);
		jlong *send_sequence_cnt_ = env->GetLongArrayElements(send_sequence_cnt, 0);

		status_[0] = MRTDValidate(cert_storage_folder_, &out_str, (const char *)endln_, (uint32_t)verbose_level, (uint8_t *)ksenc_, (uint8_t *)ksmac_, (uint64_t *)send_sequence_cnt_);

		env->ReleaseIntArrayElements(status, status_, 0);
		env->ReleaseStringUTFChars(cert_storage_folder, cert_storage_folder_);
		env->ReleaseStringUTFChars(endln, endln_);
		env->ReleaseByteArrayElements(ksenc, ksenc_, 0);
		env->ReleaseByteArrayElements(ksmac, ksmac_, 0);
		env->ReleaseLongArrayElements(send_sequence_cnt, send_sequence_cnt_, 0);

		jstring ret = env->NewStringUTF(out_str);
		DLFree((void *)out_str);

		return ret;	
	}

	JNIEXPORT jstring JNICALL
	Java_com_dlogic_uFCoder_MRTDParseDG1ToHeap(JNIEnv *env, jobject instance, jintArray status, jstring endln, jbyteArray dg1) {
		
		char *out_str;

		jint *status_ =  env->GetIntArrayElements(status, 0);
		const char *endln_ = env->GetStringUTFChars(endln, 0);
		jbyte *dg1_ =  env->GetByteArrayElements(dg1, 0);
		jsize dg1_len = env->GetArrayLength(dg1);

		status_[0] = MRTDParseDG1ToHeap(&out_str, (const char *)endln_, (uint8_t *)dg1_, (uint32_t)dg1_len);

		env->ReleaseIntArrayElements(status, status_, 0);
		env->ReleaseStringUTFChars(endln, endln_);
		env->ReleaseByteArrayElements(dg1, dg1_, 0);

		jstring ret = env->NewStringUTF(out_str);
		DLFree(out_str);

		return ret;	
	}

	JNIEXPORT jbyteArray JNICALL
	Java_com_dlogic_uFCoder_MRTDGetImageFromDG2(JNIEnv *env, jobject instance, jintArray status, jbyteArray dg2, jintArray img_type) {
		
		uint8_t *image;
		uint32_t image_len;

		jint *status_ =  env->GetIntArrayElements(status, 0);
		jbyte *dg2_ =  env->GetByteArrayElements(dg2, 0);
		jsize dg2_len = env->GetArrayLength(dg2);
		jint *img_type_ =  env->GetIntArrayElements(img_type, 0);
		
		status_[0] = MRTDGetImageFromDG2((uint8_t *)dg2_, (uint32_t)dg2_len, &image, &image_len, (uint32_t *)img_type_);
		
		env->ReleaseIntArrayElements(status, status_, 0);
		env->ReleaseIntArrayElements(img_type, img_type_, 0);

		jbyteArray ret;
		env->ReleaseByteArrayElements(dg2, dg2_, 0);
				
		if(status_[0] == 0)
		{
			if (image) {
				ret = env->NewByteArray((jsize) image_len);
				env->SetByteArrayRegion(ret, 0, (jsize) image_len, (jbyte *) image);
				// There is no call to DLFree() because image pointed into array pointed by dg2
				//       Important is to call env->ReleaseByteArrayElements(dg2, dg2_, 0); after setting the elements of the ret
			}
			else
			{
				return NULL;
			}
		}
		else
		{
			return NULL;
		}

		return ret;
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_MRTDGetImageFromDG2ToFile(JNIEnv *env, jobject instance, jbyteArray dg2, jstring file_name_without_extension) {
		UFR_STATUS status;
		

		jbyte *dg2_ =  env->GetByteArrayElements(dg2, 0);
		jsize dg2_len = env->GetArrayLength(dg2);
		const char *file_name_without_extension_ = env->GetStringUTFChars(file_name_without_extension, 0);

		status = MRTDGetImageFromDG2ToFile((uint8_t *)dg2_, (uint32_t)dg2_len, file_name_without_extension_);
		
		env->ReleaseByteArrayElements(dg2, dg2_, 0);
		env->ReleaseStringUTFChars(file_name_without_extension, file_name_without_extension_);

		return status;	
	}

	JNIEXPORT jint JNICALL Java_com_dlogic_uFCoder_MRTDGetDgIndex(JNIEnv *env, jobject instance, jbyte dg_tag) {
		

		return MRTDGetDgIndex((uint8_t) dg_tag);
	}

	JNIEXPORT jbyteArray JNICALL
	Java_com_dlogic_uFCoder_MRTDGetDGTagListFromCOM(JNIEnv *env, jobject instance, jintArray status, jbyteArray com) {
		
		uint8_t *dg_list;
		uint8_t dg_list_cnt;

		jint *status_ =  env->GetIntArrayElements(status, 0);
		jbyte *com_ =  env->GetByteArrayElements(com, 0);
		jsize com_len = env->GetArrayLength(com);
		
		status_[0] = MRTDGetDGTagListFromCOM((uint8_t *)com_, (uint32_t)com_len, &dg_list, &dg_list_cnt);
		
		env->ReleaseIntArrayElements(status, status_, 0);

		jbyteArray ret;
		env->ReleaseByteArrayElements(com, com_, 0);
		
		if(status_[0] == 0)
		{
			if (dg_list) {
				ret = env->NewByteArray((jsize) dg_list_cnt);
				env->SetByteArrayRegion(ret, 0, (jsize) dg_list_cnt, (jbyte *) dg_list);
				// There is no call to DLFree() because dg_list pointed into array pointed by com_
				//       Important is to call env->ReleaseByteArrayElements(com, com_, 0); after setting the elements of the ret
			}
			else
			{
				return NULL;
			}
		}
		else
		{
			return NULL;
		}
		
		return ret;
	}

	
	JNIEXPORT jbyteArray JNICALL
	Java_com_dlogic_uFCoder_GetCertificateFromCard(JNIEnv *env, jobject instance, jintArray status, jbyte obj_type, jbyte obj_index) {
		
		
		jint *status_ =  env->GetIntArrayElements(status, 0);
		uint16_t id_size;
		uint8_t *id = NULL;
		uint8_t selection_response[16];
		const uint8_t JCDL_AID[9] = {0xF0, 0x44, 0x4C, 0x6F, 0x67, 0x69, 0x63, 0x00, 0x01};
		
		status_[0] = JCAppSelectByAid(JCDL_AID, 9, selection_response);
		
		if(status_[0])
		{
			env->ReleaseIntArrayElements(status, status_, 0);
			return NULL;
		}
			
		status_[0] = JCAppGetObjId((uint8_t)obj_type, (uint8_t)obj_index, id, &id_size);
		
		if (status_[0])
		{
			env->ReleaseIntArrayElements(status, status_, 0);
			return NULL;
		}
		
		id = (uint8_t *)malloc(id_size);

		status_[0] = JCAppGetObjId((uint8_t)obj_type, (uint8_t)obj_index, id, &id_size);
		
		free(id);
		
		if (status_[0])
		{
			env->ReleaseIntArrayElements(status, status_, 0);
			return NULL;
		}

		uint8_t *cert = (uint8_t *)malloc(id_size);
		status_[0] = JCAppGetObj((uint8_t)obj_type, (uint8_t)obj_index, cert, id_size);

		if (status_[0])
		{
			env->ReleaseIntArrayElements(status, status_, 0);
			return NULL;
		}
		
		env->ReleaseIntArrayElements(status, status_, 0);
		
		jbyteArray ret = env->NewByteArray((jsize) id_size);
		env->SetByteArrayRegion(ret, 0, (jsize) id_size, (jbyte *) cert);

		return ret;	
	}
	
		JNIEXPORT jbyteArray JNICALL
	Java_com_dlogic_uFCoder_GetECPublicKeyFromCard(JNIEnv *env, jobject instance, jintArray status) {
		
		
		jint *status_ =  env->GetIntArrayElements(status, 0);
		
		uint8_t selection_response[16];
		uint16_t keyW_size = 0;
		uint16_t field_size = 0;
		uint16_t ab_size = 0;
		uint16_t g_size = 0;
		uint16_t r_size = 0;
		uint16_t key_size_bits = 0;
		uint16_t k = 0;
		uint16_t key_designator = 0;

		uint8_t *keyW = NULL;
		uint8_t *field = NULL;
		uint8_t *ab = NULL;
		uint8_t *g = NULL;
		uint8_t *r = NULL;
		
		const uint8_t JCDL_AID[9] = {0xF0, 0x44, 0x4C, 0x6F, 0x67, 0x69, 0x63, 0x00, 0x01};
		
		status_[0] = JCAppSelectByAid(JCDL_AID, 9, selection_response);
		
		if(status_[0])
		{
			env->ReleaseIntArrayElements(status, status_, 0);
			return NULL;
		}
		
		status_[0] = JCAppGetEcPublicKey(0, keyW, &keyW_size, field, &field_size, ab, &ab_size, g, &g_size,
									 r, &r_size, &k, &key_size_bits, &key_designator);

		if (status_[0])
		{
			env->ReleaseIntArrayElements(status, status_, 0);
			return NULL;
		}
		else
		{
			keyW = (uint8_t *)malloc(keyW_size);
			field = (uint8_t *)malloc(field_size);
			ab = (uint8_t *)malloc(ab_size);
			g = (uint8_t *)malloc(g_size);
			r = (uint8_t *)malloc(r_size);

			status_[0] = JCAppGetEcPublicKey(0, keyW, &keyW_size, field, &field_size, ab, &ab_size, g, &g_size,
										 r, &r_size, &k, &key_size_bits, &key_designator);
		}
		
		if (status_[0])
		{
			env->ReleaseIntArrayElements(status, status_, 0);
			return NULL;
		}
		
		env->ReleaseIntArrayElements(status, status_, 0);
		
		jbyteArray ret = env->NewByteArray((jsize) keyW_size);
		env->SetByteArrayRegion(ret, 0, (jsize) keyW_size, (jbyte *) keyW);
		
		free(keyW);
		free(field);
		free(ab);
		free(g);
		free(r);

		return ret;
	}
	
			JNIEXPORT jbyteArray JNICALL
	Java_com_dlogic_uFCoder_GetDigitalSignature(JNIEnv *env, jobject instance, jintArray status, jbyteArray sha2_data, jbyteArray dsPin, jbyte dsPinSize) {
		
		
		jint *status_ =  env->GetIntArrayElements(status, 0);
		
		const uint8_t JCDL_AID[9] = {0xF0, 0x44, 0x4C, 0x6F, 0x67, 0x69, 0x63, 0x00, 0x01};
		uint8_t signature[256];
		uint16_t signatureLen;
		uint8_t selectResponse[16];
		
		jbyte *sha2_data_ =  env->GetByteArrayElements(sha2_data, 0);
		jbyte *dsPin_ =  env->GetByteArrayElements(dsPin, 0);

		  status_[0] = JCAppSelectByAid(JCDL_AID, 9, selectResponse);
		  if (status_[0]) {
			env->ReleaseIntArrayElements(status, status_, 0);
			env->ReleaseByteArrayElements(sha2_data, sha2_data_, 0);
			env->ReleaseByteArrayElements(dsPin, dsPin_, 0);
		    return NULL;
		  }

		  status_[0] = JCAppLogin(false, (uint8_t *)dsPin_, (uint8_t)dsPinSize);

		  if (status_[0]) {
			env->ReleaseIntArrayElements(status, status_, 0);
			env->ReleaseByteArrayElements(sha2_data, sha2_data_, 0);
			env->ReleaseByteArrayElements(dsPin, dsPin_, 0);
		    return NULL;
		  }

		  signatureLen = 0;
		  status_[0] = JCAppGenerateSignature(1, 0, 0, 0, (const uint8_t *)sha2_data_, 32, &signatureLen, NULL, 0);
		  
		  if (status_[0]) {
			env->ReleaseIntArrayElements(status, status_, 0);
			env->ReleaseByteArrayElements(sha2_data, sha2_data_, 0);
			env->ReleaseByteArrayElements(dsPin, dsPin_, 0);
		    return NULL;
		  }

		  status_[0] = JCAppGetSignature(signature, signatureLen);
		  if (status_[0]) {
			env->ReleaseIntArrayElements(status, status_, 0);
			env->ReleaseByteArrayElements(sha2_data, sha2_data_, 0);
			env->ReleaseByteArrayElements(dsPin, dsPin_, 0);
		    return NULL;
		  }
		  signatureLen = signatureLen - 2;

		
		jbyteArray ret = env->NewByteArray((jsize) signatureLen);
		env->SetByteArrayRegion(ret, 0, (jsize) signatureLen, (jbyte *) signature);
		
		env->ReleaseByteArrayElements(sha2_data, sha2_data_, 0);
		env->ReleaseByteArrayElements(dsPin, dsPin_, 0);
		
		return ret;
	}

    extern "C"
    JNIEXPORT jint JNICALL
    Java_com_dlogic_uFCoder_SetISO14443_14_1Mode_1GetATS(JNIEnv *env, jobject instance, jbyteArray ats, jbyteArray ats_len,  jbyteArray uid, jbyteArray uid_len, jbyteArray sak) {

        
        UFR_STATUS status;

        jbyte *ats_ = env->GetByteArrayElements(ats, 0);
        jbyte *ats_len_ = env->GetByteArrayElements(ats_len, 0);
        jbyte *uid_ = env->GetByteArrayElements(uid, 0);
        jbyte *uid_len_ = env->GetByteArrayElements(uid_len, 0);
        jbyte *sak_ = env->GetByteArrayElements(sak, 0);

        status = SetISO14443_4_Mode_GetATS((uint8_t *)ats_, (uint8_t *)ats_len_, (uint8_t *)uid_, (uint8_t *)uid_len_, (uint8_t *)sak_);

        env->ReleaseByteArrayElements(ats, ats_, 0);
        env->ReleaseByteArrayElements(ats_len, ats_len_, 0);
        env->ReleaseByteArrayElements(uid, uid_, 0);
        env->ReleaseByteArrayElements(uid_len, uid_len_, 0);
        env->ReleaseByteArrayElements(sak, sak_, 0);

        return status;
    }
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireClearRecordFile_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_SetUartSpeed(JNIEnv *env, jobject instance, jint baud_rate) {

	
	UFR_STATUS status;


	status = SetUartSpeed((uint32_t)baud_rate);


	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_SetDefaultUartSpeed(JNIEnv *env, jobject instance, jbyte reader_type, jbyte comm_type,  jstring port_name) {

	
	UFR_STATUS status;


	status = SetDefaultUartSpeed((uint8_t)reader_type, (uint8_t)comm_type, (c_string)port_name);


	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1set_1global_1parameters(JNIEnv *env, jobject instance, jbyte file_no, jbyte key_no, jbyte communication_mode) {

	
	UFR_STATUS status;


	status = nt4h_set_global_parameters((uint8_t)file_no, (uint8_t)key_no, (uint8_t)communication_mode);


	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1change_1standard_1file_1settings_1pk(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jbyte file_no, jbyte key_no, jbyte curr_communication_mode, jbyte new_communication_mode, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no) {

	
	UFR_STATUS status;

	jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);

	status = nt4h_change_standard_file_settings_pk((uint8_t *)aes_key_ext_, (uint8_t)file_no, (uint8_t)key_no, (uint8_t)curr_communication_mode, (uint8_t)new_communication_mode, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no);

	env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1change_1standard_1file_1settings(JNIEnv *env, jobject instance, jbyte aes_key_no, jbyte file_no, jbyte key_no, jbyte curr_communication_mode, jbyte new_communication_mode, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no) {

	
	UFR_STATUS status;


	status = nt4h_change_standard_file_settings((uint8_t)aes_key_no, (uint8_t)file_no, (uint8_t)key_no, (uint8_t)curr_communication_mode, (uint8_t)new_communication_mode, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no);


	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1change_1sdm_1file_1settings_1pk(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jbyte file_no, jbyte key_no, jbyte curr_communication_mode, jbyte new_communication_mode, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte uid_enable, jbyte read_ctr_enable, jbyte read_ctr_limit_enable, jbyte enc_file_data_enable, jbyte meta_data_key_no, jbyte file_data_read_key_no, jbyte read_ctr_key_no, jint uid_offset, jint read_ctr_offset, jint picc_data_offset, jint mac_input_offset, jint enc_offset, jint enc_length, jint mac_offset, jint read_ctr_limit) {

	
	UFR_STATUS status;

	jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);

	status = nt4h_change_sdm_file_settings_pk((uint8_t *)aes_key_ext_, (uint8_t)file_no, (uint8_t)key_no, (uint8_t)curr_communication_mode, (uint8_t)new_communication_mode, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)uid_enable, (uint8_t)read_ctr_enable, (uint8_t)read_ctr_limit_enable, (uint8_t)enc_file_data_enable, (uint8_t)meta_data_key_no, (uint8_t)file_data_read_key_no, (uint8_t)read_ctr_key_no, (uint32_t)uid_offset, (uint32_t)read_ctr_offset, (uint32_t)picc_data_offset, (uint32_t)mac_input_offset, (uint32_t)enc_offset, (uint32_t)enc_length, (uint32_t)mac_offset, (uint32_t)read_ctr_limit);

	env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1change_1sdm_1file_1settings(JNIEnv *env, jobject instance, jbyte aes_key_no, jbyte file_no, jbyte key_no, jbyte curr_communication_mode, jbyte new_communication_mode, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte uid_enable, jbyte read_ctr_enable, jbyte read_ctr_limit_enable, jbyte enc_file_data_enable, jbyte meta_data_key_no, jbyte file_data_read_key_no, jbyte read_ctr_key_no, jint uid_offset, jint read_ctr_offset, jint picc_data_offset, jint mac_input_offset, jint enc_offset, jint enc_length, jint mac_offset, jint read_ctr_limit) {

	
	UFR_STATUS status;


	status = nt4h_change_sdm_file_settings((uint8_t)aes_key_no, (uint8_t)file_no, (uint8_t)key_no, (uint8_t)curr_communication_mode, (uint8_t)new_communication_mode, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)uid_enable, (uint8_t)read_ctr_enable, (uint8_t)read_ctr_limit_enable, (uint8_t)enc_file_data_enable, (uint8_t)meta_data_key_no, (uint8_t)file_data_read_key_no, (uint8_t)read_ctr_key_no, (uint32_t)uid_offset, (uint32_t)read_ctr_offset, (uint32_t)picc_data_offset, (uint32_t)mac_input_offset, (uint32_t)enc_offset, (uint32_t)enc_length, (uint32_t)mac_offset, (uint32_t)read_ctr_limit);


	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1get_1file_1settings(JNIEnv *env, jobject instance, jbyte file_no, jbyteArray file_type, jbyteArray communication_mode, jbyteArray sdm_enable, jintArray file_size, jbyteArray read_key_no, jbyteArray write_key_no, jbyteArray read_write_key_no, jbyteArray change_key_no, jbyteArray uid_enable, jbyteArray read_ctr_enable, jbyteArray read_ctr_limit_enable, jbyteArray enc_file_data_enable, jbyteArray meta_data_key_no, jbyteArray file_data_read_key_no, jbyteArray read_ctr_key_no, jintArray uid_offset, jintArray read_ctr_offset, jintArray picc_data_offset, jintArray mac_input_offset, jintArray enc_offset, jintArray enc_length, jintArray mac_offset, jintArray read_ctr_limit) {

	
	UFR_STATUS status;

	jbyte *file_type_ = env->GetByteArrayElements(file_type, 0);
	jbyte *communication_mode_ = env->GetByteArrayElements(communication_mode, 0);
	jbyte *sdm_enable_ = env->GetByteArrayElements(sdm_enable, 0);
	jint *file_size_ = env->GetIntArrayElements(file_size, 0);
	jbyte *read_key_no_ = env->GetByteArrayElements(read_key_no, 0);
	jbyte *write_key_no_ = env->GetByteArrayElements(write_key_no, 0);
	jbyte *read_write_key_no_ = env->GetByteArrayElements(read_write_key_no, 0);
	jbyte *change_key_no_ = env->GetByteArrayElements(change_key_no, 0);
	jbyte *uid_enable_ = env->GetByteArrayElements(uid_enable, 0);
	jbyte *read_ctr_enable_ = env->GetByteArrayElements(read_ctr_enable, 0);
	jbyte *read_ctr_limit_enable_ = env->GetByteArrayElements(read_ctr_limit_enable, 0);
	jbyte *enc_file_data_enable_ = env->GetByteArrayElements(enc_file_data_enable, 0);
	jbyte *meta_data_key_no_ = env->GetByteArrayElements(meta_data_key_no, 0);
	jbyte *file_data_read_key_no_ = env->GetByteArrayElements(file_data_read_key_no, 0);
	jbyte *read_ctr_key_no_ = env->GetByteArrayElements(read_ctr_key_no, 0);
	jint *uid_offset_ = env->GetIntArrayElements(uid_offset, 0);
	jint *read_ctr_offset_ = env->GetIntArrayElements(read_ctr_offset, 0);
	jint *picc_data_offset_ = env->GetIntArrayElements(picc_data_offset, 0);
	jint *mac_input_offset_ = env->GetIntArrayElements(mac_input_offset, 0);
	jint *enc_offset_ = env->GetIntArrayElements(enc_offset, 0);
	jint *enc_length_ = env->GetIntArrayElements(enc_length, 0);
	jint *mac_offset_ = env->GetIntArrayElements(mac_offset, 0);
	jint *read_ctr_limit_ = env->GetIntArrayElements(read_ctr_limit, 0);

	status = nt4h_get_file_settings((uint8_t)file_no, (uint8_t *)file_type_, (uint8_t *)communication_mode_, (uint8_t *)sdm_enable_, (uint32_t *)file_size_, (uint8_t *)read_key_no_, (uint8_t *)write_key_no_, (uint8_t *)read_write_key_no_, (uint8_t *)change_key_no_, (uint8_t *)uid_enable_, (uint8_t *)read_ctr_enable_, (uint8_t *)read_ctr_limit_enable_, (uint8_t *)enc_file_data_enable_, (uint8_t *)meta_data_key_no_, (uint8_t *)file_data_read_key_no_, (uint8_t *)read_ctr_key_no_, (uint32_t *)uid_offset_, (uint32_t *)read_ctr_offset_, (uint32_t *)picc_data_offset_, (uint32_t *)mac_input_offset_, (uint32_t *)enc_offset_, (uint32_t *)enc_length_, (uint32_t *)mac_offset_, (uint32_t *)read_ctr_limit_);

	env->ReleaseByteArrayElements(file_type, file_type_, 0);
	env->ReleaseByteArrayElements(communication_mode, communication_mode_, 0);
	env->ReleaseByteArrayElements(sdm_enable, sdm_enable_, 0);
	env->ReleaseIntArrayElements(file_size, file_size_, 0);
	env->ReleaseByteArrayElements(read_key_no, read_key_no_, 0);
	env->ReleaseByteArrayElements(write_key_no, write_key_no_, 0);
	env->ReleaseByteArrayElements(read_write_key_no, read_write_key_no_, 0);
	env->ReleaseByteArrayElements(change_key_no, change_key_no_, 0);
	env->ReleaseByteArrayElements(uid_enable, uid_enable_, 0);
	env->ReleaseByteArrayElements(read_ctr_enable, read_ctr_enable_, 0);
	env->ReleaseByteArrayElements(read_ctr_limit_enable, read_ctr_limit_enable_, 0);
	env->ReleaseByteArrayElements(enc_file_data_enable, enc_file_data_enable_, 0);
	env->ReleaseByteArrayElements(meta_data_key_no, meta_data_key_no_, 0);
	env->ReleaseByteArrayElements(file_data_read_key_no, file_data_read_key_no_, 0);
	env->ReleaseByteArrayElements(read_ctr_key_no, read_ctr_key_no_, 0);
	env->ReleaseIntArrayElements(uid_offset, uid_offset_, 0);
	env->ReleaseIntArrayElements(read_ctr_offset, read_ctr_offset_, 0);
	env->ReleaseIntArrayElements(picc_data_offset, picc_data_offset_, 0);
	env->ReleaseIntArrayElements(mac_input_offset, mac_input_offset_, 0);
	env->ReleaseIntArrayElements(enc_offset, enc_offset_, 0);
	env->ReleaseIntArrayElements(enc_length, enc_length_, 0);
	env->ReleaseIntArrayElements(mac_offset, mac_offset_, 0);
	env->ReleaseIntArrayElements(read_ctr_limit, read_ctr_limit_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1set_1rid_1pk(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext) {

	
	UFR_STATUS status;

	jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);

	status = nt4h_set_rid_pk((uint8_t *)aes_key_ext_);

	env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1set_1rid(JNIEnv *env, jobject instance, jbyte aes_key_no) {

	
	UFR_STATUS status;


	status = nt4h_set_rid((uint8_t)aes_key_no);


	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1get_1uid_1pk(JNIEnv *env, jobject instance,  jbyteArray auth_key, jbyte key_no,  jbyteArray uid) {

	
	UFR_STATUS status;

	jbyte *auth_key_ = env->GetByteArrayElements(auth_key, 0);
	jbyte *uid_ = env->GetByteArrayElements(uid, 0);

	status = nt4h_get_uid_pk((uint8_t *)auth_key_, (uint8_t)key_no, (uint8_t *)uid_);

	env->ReleaseByteArrayElements(auth_key, auth_key_, 0);
	env->ReleaseByteArrayElements(uid, uid_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1get_1uid(JNIEnv *env, jobject instance, jbyte auth_key_no, jbyte key_no,  jbyteArray uid) {

	
	UFR_STATUS status;

	jbyte *uid_ = env->GetByteArrayElements(uid, 0);

	status = nt4h_get_uid((uint8_t)auth_key_no, (uint8_t)key_no, (uint8_t *)uid_);

	env->ReleaseByteArrayElements(uid, uid_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1change_1key_1pk(JNIEnv *env, jobject instance,  jbyteArray auth_key, jbyte key_no,  jbyteArray new_key,  jbyteArray old_key) {

	
	UFR_STATUS status;

	jbyte *auth_key_ = env->GetByteArrayElements(auth_key, 0);
	jbyte *new_key_ = env->GetByteArrayElements(new_key, 0);
	jbyte *old_key_ = env->GetByteArrayElements(old_key, 0);

	status = nt4h_change_key_pk((uint8_t *)auth_key_, (uint8_t)key_no, (uint8_t *)new_key_, (uint8_t *)old_key_);

	env->ReleaseByteArrayElements(auth_key, auth_key_, 0);
	env->ReleaseByteArrayElements(new_key, new_key_, 0);
	env->ReleaseByteArrayElements(old_key, old_key_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1change_1key(JNIEnv *env, jobject instance, jbyte auth_key_no, jbyte key_no,  jbyteArray new_key,  jbyteArray old_key) {

	
	UFR_STATUS status;

	jbyte *new_key_ = env->GetByteArrayElements(new_key, 0);
	jbyte *old_key_ = env->GetByteArrayElements(old_key, 0);

	status = nt4h_change_key((uint8_t)auth_key_no, (uint8_t)key_no, (uint8_t *)new_key_, (uint8_t *)old_key_);

	env->ReleaseByteArrayElements(new_key, new_key_, 0);
	env->ReleaseByteArrayElements(old_key, old_key_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1get_1sdm_1ctr_1pk(JNIEnv *env, jobject instance,  jbyteArray auth_key, jbyte file_no, jbyte key_no, jintArray sdm_read_ctr) {

	
	UFR_STATUS status;

	jbyte *auth_key_ = env->GetByteArrayElements(auth_key, 0);
	jint *sdm_read_ctr_ = env->GetIntArrayElements(sdm_read_ctr, 0);

	status = nt4h_get_sdm_ctr_pk((uint8_t *)auth_key_, (uint8_t)file_no, (uint8_t)key_no, (uint32_t *)sdm_read_ctr_);

	env->ReleaseByteArrayElements(auth_key, auth_key_, 0);
	env->ReleaseIntArrayElements(sdm_read_ctr, sdm_read_ctr_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1get_1sdm_1ctr(JNIEnv *env, jobject instance, jbyte auth_key_no, jbyte file_no, jbyte key_no, jintArray sdm_read_ctr) {

	
	UFR_STATUS status;

	jint *sdm_read_ctr_ = env->GetIntArrayElements(sdm_read_ctr, 0);

	status = nt4h_get_sdm_ctr((uint8_t)auth_key_no, (uint8_t)file_no, (uint8_t)key_no, (uint32_t *)sdm_read_ctr_);

	env->ReleaseIntArrayElements(sdm_read_ctr, sdm_read_ctr_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1get_1sdm_1ctr_1no_1auth(JNIEnv *env, jobject instance, jbyte file_no, jintArray sdm_read_ctr) {

	
	UFR_STATUS status;

	jint *sdm_read_ctr_ = env->GetIntArrayElements(sdm_read_ctr, 0);

	status = nt4h_get_sdm_ctr_no_auth((uint8_t)file_no, (uint32_t *)sdm_read_ctr_);

	env->ReleaseIntArrayElements(sdm_read_ctr, sdm_read_ctr_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1check_1sdm_1mac(JNIEnv *env, jobject instance, jint smd_read_counter,  jbyteArray uid,  jbyteArray auth_key,  jbyteArray mac_in_data,  jbyte mac_in_len,  jbyteArray sdm_mac) {

	
	UFR_STATUS status;

	jbyte *uid_ = env->GetByteArrayElements(uid, 0);
	jbyte *auth_key_ = env->GetByteArrayElements(auth_key, 0);
	jbyte *mac_in_data_ = env->GetByteArrayElements(mac_in_data, 0);
	jbyte *sdm_mac_ = env->GetByteArrayElements(sdm_mac, 0);

	status = nt4h_check_sdm_mac((uint32_t)smd_read_counter, (uint8_t *)uid_, (uint8_t *)auth_key_, (uint8_t *)mac_in_data_, (uint8_t)mac_in_len, (uint8_t *)sdm_mac_);

	env->ReleaseByteArrayElements(uid, uid_, 0);
	env->ReleaseByteArrayElements(auth_key, auth_key_, 0);
	env->ReleaseByteArrayElements(mac_in_data, mac_in_data_, 0);
	env->ReleaseByteArrayElements(sdm_mac, sdm_mac_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1decrypt_1sdm_1enc_1file_1data(JNIEnv *env, jobject instance, jint smd_read_counter,  jbyteArray uid,  jbyteArray auth_key,  jbyteArray enc_file_data,  jbyte enc_file_data_len) {

	
	UFR_STATUS status;

	jbyte *uid_ = env->GetByteArrayElements(uid, 0);
	jbyte *auth_key_ = env->GetByteArrayElements(auth_key, 0);
	jbyte *enc_file_data_ = env->GetByteArrayElements(enc_file_data, 0);

	status = nt4h_decrypt_sdm_enc_file_data((uint32_t)smd_read_counter, (uint8_t *)uid_, (uint8_t *)auth_key_, (uint8_t *)enc_file_data_, (uint8_t)enc_file_data_len);

	env->ReleaseByteArrayElements(uid, uid_, 0);
	env->ReleaseByteArrayElements(auth_key, auth_key_, 0);
	env->ReleaseByteArrayElements(enc_file_data, enc_file_data_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1decrypt_1picc_1data(JNIEnv *env, jobject instance,  jbyteArray picc_data,  jbyteArray auth_key,  jbyteArray picc_data_tag,  jbyteArray uid,  jintArray smd_read_cnt) {

	
	UFR_STATUS status;

	jbyte *picc_data_ = env->GetByteArrayElements(picc_data, 0);
	jbyte *auth_key_ = env->GetByteArrayElements(auth_key, 0);
	jbyte *picc_data_tag_ = env->GetByteArrayElements(picc_data_tag, 0);
	jbyte *uid_ = env->GetByteArrayElements(uid, 0);
	jint *smd_read_cnt_ = env->GetIntArrayElements(smd_read_cnt, 0);

	status = nt4h_decrypt_picc_data((uint8_t *)picc_data_, (uint8_t *)auth_key_, (uint8_t *)picc_data_tag_, (uint8_t *)uid_, (uint32_t *)smd_read_cnt_);

	env->ReleaseByteArrayElements(picc_data, picc_data_, 0);
	env->ReleaseByteArrayElements(auth_key, auth_key_, 0);
	env->ReleaseByteArrayElements(picc_data_tag, picc_data_tag_, 0);
	env->ReleaseByteArrayElements(uid, uid_, 0);
	env->ReleaseIntArrayElements(smd_read_cnt, smd_read_cnt_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_dfl_1get_1file_1settings(JNIEnv *env, jobject instance, jbyte file_no, jbyteArray file_type, jbyteArray communication_mode, jbyteArray read_key_no, jbyteArray write_key_no, jbyteArray read_write_key_no, jbyteArray change_key_no, jintArray file_size, jintArray lower_limit, jintArray upper_limit, jintArray limited_credit_value, jbyteArray limited_credit_enable, jbyteArray free_get_value, jintArray record_size, jintArray max_number_of_rec, jintArray curr_number_of_rec, jbyteArray ex_unauth_operation, jbyteArray tmc_limit_conf, jbyteArray tm_key_type, jbyteArray tm_key_version, jintArray tmc_limit) {

	
	UFR_STATUS status;

	jbyte *file_type_ = env->GetByteArrayElements(file_type, 0);
	jbyte *communication_mode_ = env->GetByteArrayElements(communication_mode, 0);
	jbyte *read_key_no_ = env->GetByteArrayElements(read_key_no, 0);
	jbyte *write_key_no_ = env->GetByteArrayElements(write_key_no, 0);
	jbyte *read_write_key_no_ = env->GetByteArrayElements(read_write_key_no, 0);
	jbyte *change_key_no_ = env->GetByteArrayElements(change_key_no, 0);
	jint *file_size_ = env->GetIntArrayElements(file_size, 0);
	jint *lower_limit_ = env->GetIntArrayElements(lower_limit, 0);
	jint *upper_limit_ = env->GetIntArrayElements(upper_limit, 0);
	jint *limited_credit_value_ = env->GetIntArrayElements(limited_credit_value, 0);
	jbyte *limited_credit_enable_ = env->GetByteArrayElements(limited_credit_enable, 0);
	jbyte *free_get_value_ = env->GetByteArrayElements(free_get_value, 0);
	jint *record_size_ = env->GetIntArrayElements(record_size, 0);
	jint *max_number_of_rec_ = env->GetIntArrayElements(max_number_of_rec, 0);
	jint *curr_number_of_rec_ = env->GetIntArrayElements(curr_number_of_rec, 0);
	jbyte *ex_unauth_operation_ = env->GetByteArrayElements(ex_unauth_operation, 0);
	jbyte *tmc_limit_conf_ = env->GetByteArrayElements(tmc_limit_conf, 0);
	jbyte *tm_key_type_ = env->GetByteArrayElements(tm_key_type, 0);
	jbyte *tm_key_version_ = env->GetByteArrayElements(tm_key_version, 0);
	jint *tmc_limit_ = env->GetIntArrayElements(tmc_limit, 0);

	status = dfl_get_file_settings((uint8_t)file_no, (uint8_t *)file_type_, (uint8_t *)communication_mode_, (uint8_t *)read_key_no_, (uint8_t *)write_key_no_, (uint8_t *)read_write_key_no_, (uint8_t *)change_key_no_, (uint32_t *)file_size_, (int32_t *)lower_limit_, (int32_t *)upper_limit_, (uint32_t *)limited_credit_value_, (uint8_t *)limited_credit_enable_, (uint8_t *)free_get_value_, (uint32_t *)record_size_, (uint32_t *)max_number_of_rec_, (uint32_t *)curr_number_of_rec_, (uint8_t *)ex_unauth_operation_, (uint8_t *)tmc_limit_conf_, (uint8_t *)tm_key_type_, (uint8_t *)tm_key_version_, (uint32_t *)tmc_limit_);

	env->ReleaseByteArrayElements(file_type, file_type_, 0);
	env->ReleaseByteArrayElements(communication_mode, communication_mode_, 0);
	env->ReleaseByteArrayElements(read_key_no, read_key_no_, 0);
	env->ReleaseByteArrayElements(write_key_no, write_key_no_, 0);
	env->ReleaseByteArrayElements(read_write_key_no, read_write_key_no_, 0);
	env->ReleaseByteArrayElements(change_key_no, change_key_no_, 0);
	env->ReleaseIntArrayElements(file_size, file_size_, 0);
	env->ReleaseIntArrayElements(lower_limit, lower_limit_, 0);
	env->ReleaseIntArrayElements(upper_limit, upper_limit_, 0);
	env->ReleaseIntArrayElements(limited_credit_value, limited_credit_value_, 0);
	env->ReleaseByteArrayElements(limited_credit_enable, limited_credit_enable_, 0);
	env->ReleaseByteArrayElements(free_get_value, free_get_value_, 0);
	env->ReleaseIntArrayElements(record_size, record_size_, 0);
	env->ReleaseIntArrayElements(max_number_of_rec, max_number_of_rec_, 0);
	env->ReleaseIntArrayElements(curr_number_of_rec, curr_number_of_rec_, 0);
	env->ReleaseByteArrayElements(ex_unauth_operation, ex_unauth_operation_, 0);
	env->ReleaseByteArrayElements(tmc_limit_conf, tmc_limit_conf_, 0);
	env->ReleaseByteArrayElements(tm_key_type, tm_key_type_, 0);
	env->ReleaseByteArrayElements(tm_key_version, tm_key_version_, 0);
	env->ReleaseIntArrayElements(tmc_limit, tmc_limit_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_dfl_1change_1file_1settings_1pk(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jbyte file_no, jbyte key_no, jbyte curr_communication_mode, jbyte new_communication_mode, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no) {

	
	UFR_STATUS status;

	jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);

	status = dfl_change_file_settings_pk((uint8_t *)aes_key_ext_, (uint8_t)file_no, (uint8_t)key_no, (uint8_t)curr_communication_mode, (uint8_t)new_communication_mode, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no);

	env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_dfl_1change_1file_1settings(JNIEnv *env, jobject instance, jbyte aes_key_no, jbyte file_no, jbyte key_no, jbyte curr_communication_mode, jbyte new_communication_mode, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no) {

	
	UFR_STATUS status;


	status = dfl_change_file_settings((uint8_t)aes_key_no, (uint8_t)file_no, (uint8_t)key_no, (uint8_t)curr_communication_mode, (uint8_t)new_communication_mode, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no);


	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_dfl_1delete_1tmc_1file_1pk(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jbyte file_no) {

	
	UFR_STATUS status;

	jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);

	status = dfl_delete_tmc_file_pk((uint8_t *)aes_key_ext_, (uint8_t)file_no);

	env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_dfl_1delete_1tmc_1file(JNIEnv *env, jobject instance, jbyte aes_key_no, jbyte file_no) {

	
	UFR_STATUS status;


	status = dfl_delete_tmc_file((uint8_t)aes_key_no, (uint8_t)file_no);


	return status;
}



extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_WriteEmulationNdefRam(JNIEnv *env, jobject instance, jbyte tnf,  jbyteArray type_record, jbyte type_length,  jbyteArray id, jbyte id_length,  jbyteArray payload, jint payload_length) {

	
	UFR_STATUS status;

	jbyte *type_record_ = env->GetByteArrayElements(type_record, 0);
	jbyte *id_ = env->GetByteArrayElements(id, 0);
	jbyte *payload_ = env->GetByteArrayElements(payload, 0);

	status = WriteEmulationNdefRam((uint8_t)tnf, (uint8_t *)type_record_, (uint8_t)type_length, (uint8_t *)id_, (uint8_t)id_length, (uint8_t *)payload_, (uint32_t)payload_length);

	env->ReleaseByteArrayElements(type_record, type_record_, 0);
	env->ReleaseByteArrayElements(id, id_, 0);
	env->ReleaseByteArrayElements(payload, payload_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_TagEmulationStartRam(JNIEnv *env, jobject instance) {

	
	UFR_STATUS status;

	status = TagEmulationStartRam();

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_TagEmulationStopRam(JNIEnv *env, jobject instance) {

	
	UFR_STATUS status;

	status = TagEmulationStopRam();

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_GetReaderStatus(JNIEnv *env, jobject instance, jintArray state, jintArray emul_mode, jintArray emul_state, jbyteArray sleep_mode) {

	
	UFR_STATUS status;
	jint *state_ = env->GetIntArrayElements(state, 0);
	jint *emul_mode_ = env->GetIntArrayElements(emul_mode, 0);
	jint *emul_state_ = env->GetIntArrayElements(emul_state, 0);
	jbyte *sleep_mode_ = env->GetByteArrayElements(sleep_mode, 0);

	status = GetReaderStatus((pcd_states_t *)state_, (emul_modes_t *)emul_mode_, (emul_states_t *)emul_state_, (uint8_t *)sleep_mode_);
	
	env->ReleaseIntArrayElements(state, state_, 0);
	env->ReleaseIntArrayElements(emul_mode, emul_mode_, 0);
	env->ReleaseIntArrayElements(emul_state, emul_state_, 0);
	env->ReleaseByteArrayElements(sleep_mode, sleep_mode_, 0);

	return status;
}


extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_GetAtqaSak(JNIEnv *env, jobject instance, jshortArray atqa, jbyteArray sak) {

	
	UFR_STATUS status;

	jshort *atqa_ = env->GetShortArrayElements(atqa, 0);
	jbyte *sak_ = env->GetByteArrayElements(sak, 0);

	status = GetAtqaSak((uint16_t *)atqa_, (uint8_t *)sak_);

	env->ReleaseShortArrayElements(atqa, atqa_, 0);
	env->ReleaseByteArrayElements(sak, sak_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication_1app_1master_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireDeleteApplication_app_master_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication_1app_1master_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireDeleteApplication_app_master_des((uint8_t)des_key_nr, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication_1app_1master_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireDeleteApplication_app_master_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication_1app_1master_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireDeleteApplication_app_master_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication_1app_1master_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireDeleteApplication_app_master_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication_1app_1master_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireDeleteApplication_app_master_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication_1app_1master_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireDeleteApplication_app_master_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication_1app_1master_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireDeleteApplication_app_master_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireDeleteApplication_1app_1master_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireDeleteApplication_app_master_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDeleteApplication_1app_1master_1AesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_SAM_DesfireDeleteApplication_app_master_AesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDeleteApplication_1app_1master_13k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_SAM_DesfireDeleteApplication_app_master_3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDeleteApplication_1app_1master_1DesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_SAM_DesfireDeleteApplication_app_master_DesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDeleteApplication_1app_1master_12k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_SAM_DesfireDeleteApplication_app_master_2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireGetKeySettings_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyteArray setting, jbyteArray max_key_no, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *setting_ = env->GetByteArrayElements(setting, 0);
	jbyte *max_key_no_ = env->GetByteArrayElements(max_key_no, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireGetKeySettings_no_auth((uint32_t)aid, (uint8_t *)setting_, (uint8_t *)max_key_no_, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(setting, setting_, 0);
	env->ReleaseByteArrayElements(max_key_no, max_key_no_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}



extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_1TransMac_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireIncreaseValueFile_TransMac_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_1TransMac_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireIncreaseValueFile_TransMac_des((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_1TransMac_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireIncreaseValueFile_TransMac_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_1TransMac_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireIncreaseValueFile_TransMac_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireIncreaseValueFile_1TransMac_1AesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_SAM_DesfireIncreaseValueFile_TransMac_AesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireIncreaseValueFile_1TransMac_1DesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_SAM_DesfireIncreaseValueFile_TransMac_DesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireIncreaseValueFile_1TransMac_12k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_SAM_DesfireIncreaseValueFile_TransMac_2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireIncreaseValueFile_1TransMac_13k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_SAM_DesfireIncreaseValueFile_TransMac_3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_1TransMac_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireIncreaseValueFile_TransMac_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_1TransMac_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireIncreaseValueFile_TransMac_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_1TransMac_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireIncreaseValueFile_TransMac_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_1TransMac_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireIncreaseValueFile_TransMac_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireIncreaseValueFile_1TransMac_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireIncreaseValueFile_TransMac_no_auth((uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_1TransMac_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireDecreaseValueFile_TransMac_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_1TransMac_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireDecreaseValueFile_TransMac_des((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_1TransMac_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireDecreaseValueFile_TransMac_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_1TransMac_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireDecreaseValueFile_TransMac_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDecreaseValueFile_1TransMac_1AesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_SAM_DesfireDecreaseValueFile_TransMac_AesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDecreaseValueFile_1TransMac_1DesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_SAM_DesfireDecreaseValueFile_TransMac_DesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDecreaseValueFile_1TransMac_12k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_SAM_DesfireDecreaseValueFile_TransMac_2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireDecreaseValueFile_1TransMac_13k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_SAM_DesfireDecreaseValueFile_TransMac_3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_1TransMac_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireDecreaseValueFile_TransMac_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_1TransMac_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireDecreaseValueFile_TransMac_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_1TransMac_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireDecreaseValueFile_TransMac_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_1TransMac_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireDecreaseValueFile_TransMac_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireDecreaseValueFile_1TransMac_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte aid_key_nr, jbyte file_id, jbyte communication_settings, jint value, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id, jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireDecreaseValueFile_TransMac_no_auth((uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint8_t)communication_settings, (uint32_t)value, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteRecord_1TransMac_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *data_ = env->GetByteArrayElements(data, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireWriteRecord_TransMac_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(data, data_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteRecord_1TransMac_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *data_ = env->GetByteArrayElements(data, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireWriteRecord_TransMac_des((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(data, data_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteRecord_1TransMac_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *data_ = env->GetByteArrayElements(data, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireWriteRecord_TransMac_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(data, data_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteRecord_1TransMac_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *data_ = env->GetByteArrayElements(data, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireWriteRecord_TransMac_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(data, data_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireWriteRecord_1TransMac_1AesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *data_ = env->GetByteArrayElements(data, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_SAM_DesfireWriteRecord_TransMac_AesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(data, data_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireWriteRecord_1TransMac_1DesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *data_ = env->GetByteArrayElements(data, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_SAM_DesfireWriteRecord_TransMac_DesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(data, data_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireWriteRecord_1TransMac_12k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *data_ = env->GetByteArrayElements(data, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_SAM_DesfireWriteRecord_TransMac_2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(data, data_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireWriteRecord_1TransMac_13k3desAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *data_ = env->GetByteArrayElements(data, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_SAM_DesfireWriteRecord_TransMac_3k3desAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(data, data_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteRecord_1TransMac_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
	jbyte *data_ = env->GetByteArrayElements(data, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireWriteRecord_TransMac_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
	env->ReleaseByteArrayElements(data, data_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteRecord_1TransMac_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
	jbyte *data_ = env->GetByteArrayElements(data, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireWriteRecord_TransMac_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
	env->ReleaseByteArrayElements(data, data_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteRecord_1TransMac_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
	jbyte *data_ = env->GetByteArrayElements(data, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireWriteRecord_TransMac_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
	env->ReleaseByteArrayElements(data, data_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteRecord_1TransMac_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
	jbyte *data_ = env->GetByteArrayElements(data, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireWriteRecord_TransMac_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
	env->ReleaseByteArrayElements(data, data_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireWriteRecord_1TransMac_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte aid_key_nr, jbyte file_id, jshort offset, jshort data_length, jbyte communication_settings,  jbyteArray data, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *data_ = env->GetByteArrayElements(data, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireWriteRecord_TransMac_no_auth((uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t)offset, (uint16_t)data_length, (uint8_t)communication_settings, (uint8_t *)data_, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(data, data_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1TransMac_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireClearRecordFile_TransMac_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1TransMac_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireClearRecordFile_TransMac_des((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1TransMac_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireClearRecordFile_TransMac_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1TransMac_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireClearRecordFile_TransMac_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireClearRecordFile_1TransMac_1AesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_SAM_DesfireClearRecordFile_TransMac_AesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireClearRecordFile_1TransMac_1DesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_SAM_DesfireClearRecordFile_TransMac_DesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireClearRecordFile_1TransMac_12k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_SAM_DesfireClearRecordFile_TransMac_2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireClearRecordFile_1TransMac_13k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_SAM_DesfireClearRecordFile_TransMac_3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1TransMac_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireClearRecordFile_TransMac_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1TransMac_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireClearRecordFile_TransMac_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1TransMac_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireClearRecordFile_TransMac_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1TransMac_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte aid_key_nr, jbyte file_id, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireClearRecordFile_TransMac_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireClearRecordFile_1TransMac_1no_1auth(JNIEnv *env, jobject instance, jint aid, jbyte file_id, jshortArray card_status, jshortArray exec_time, jbyte use_reader_id,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jintArray trans_mac_cnt,  jbyteArray trans_mac_value) {

	
	UFR_STATUS status;

	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jint *trans_mac_cnt_ = env->GetIntArrayElements(trans_mac_cnt, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);

	status = uFR_int_DesfireClearRecordFile_TransMac_no_auth((uint32_t)aid, (uint8_t)file_id, (uint16_t *)card_status_, (uint16_t *)exec_time_, (uint8_t)use_reader_id, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint32_t *)trans_mac_cnt_, (uint8_t *)trans_mac_value_);

	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseIntArrayElements(trans_mac_cnt, trans_mac_cnt_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateTransMacFile_1aes(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte file_id, jbyte read_key_no, jbyte commit_reader_id_key_no, jbyte change_key_no, jbyte communication_settings,  jbyteArray trans_mac_key, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *trans_mac_key_ = env->GetByteArrayElements(trans_mac_key, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireCreateTransMacFile_aes((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)read_key_no, (uint8_t)commit_reader_id_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint8_t *)trans_mac_key_, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(trans_mac_key, trans_mac_key_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateTransMacFile_1des(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte file_id, jbyte read_key_no, jbyte commit_reader_id_key_no, jbyte change_key_no, jbyte communication_settings,  jbyteArray trans_mac_key, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *trans_mac_key_ = env->GetByteArrayElements(trans_mac_key, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireCreateTransMacFile_des((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)read_key_no, (uint8_t)commit_reader_id_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint8_t *)trans_mac_key_, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(trans_mac_key, trans_mac_key_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateTransMacFile_12k3des(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte file_id, jbyte read_key_no, jbyte commit_reader_id_key_no, jbyte change_key_no, jbyte communication_settings,  jbyteArray trans_mac_key, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *trans_mac_key_ = env->GetByteArrayElements(trans_mac_key, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireCreateTransMacFile_2k3des((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)read_key_no, (uint8_t)commit_reader_id_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint8_t *)trans_mac_key_, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(trans_mac_key, trans_mac_key_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateTransMacFile_13k3des(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte file_id, jbyte read_key_no, jbyte commit_reader_id_key_no, jbyte change_key_no, jbyte communication_settings,  jbyteArray trans_mac_key, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *trans_mac_key_ = env->GetByteArrayElements(trans_mac_key, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireCreateTransMacFile_3k3des((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)read_key_no, (uint8_t)commit_reader_id_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint8_t *)trans_mac_key_, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(trans_mac_key, trans_mac_key_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateTransMacFile_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jint aid, jbyte file_id, jbyte read_key_no, jbyte commit_reader_id_key_no, jbyte change_key_no, jbyte communication_settings,  jbyteArray trans_mac_key, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
	jbyte *trans_mac_key_ = env->GetByteArrayElements(trans_mac_key, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireCreateTransMacFile_aes_PK((uint8_t *)aes_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint8_t)read_key_no, (uint8_t)commit_reader_id_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint8_t *)trans_mac_key_, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
	env->ReleaseByteArrayElements(trans_mac_key, trans_mac_key_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateTransMacFile_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray des_key_ext, jint aid, jbyte file_id, jbyte read_key_no, jbyte commit_reader_id_key_no, jbyte change_key_no, jbyte communication_settings,  jbyteArray trans_mac_key, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *des_key_ext_ = env->GetByteArrayElements(des_key_ext, 0);
	jbyte *trans_mac_key_ = env->GetByteArrayElements(trans_mac_key, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireCreateTransMacFile_des_PK((uint8_t *)des_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint8_t)read_key_no, (uint8_t)commit_reader_id_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint8_t *)trans_mac_key_, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(des_key_ext, des_key_ext_, 0);
	env->ReleaseByteArrayElements(trans_mac_key, trans_mac_key_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateTransMacFile_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des2k_key_ext, jint aid, jbyte file_id, jbyte read_key_no, jbyte commit_reader_id_key_no, jbyte change_key_no, jbyte communication_settings,  jbyteArray trans_mac_key, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *des2k_key_ext_ = env->GetByteArrayElements(des2k_key_ext, 0);
	jbyte *trans_mac_key_ = env->GetByteArrayElements(trans_mac_key, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireCreateTransMacFile_2k3des_PK((uint8_t *)des2k_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint8_t)read_key_no, (uint8_t)commit_reader_id_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint8_t *)trans_mac_key_, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(des2k_key_ext, des2k_key_ext_, 0);
	env->ReleaseByteArrayElements(trans_mac_key, trans_mac_key_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireCreateTransMacFile_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray des3k_key_ext, jint aid, jbyte file_id, jbyte read_key_no, jbyte commit_reader_id_key_no, jbyte change_key_no, jbyte communication_settings,  jbyteArray trans_mac_key, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *des3k_key_ext_ = env->GetByteArrayElements(des3k_key_ext, 0);
	jbyte *trans_mac_key_ = env->GetByteArrayElements(trans_mac_key, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_int_DesfireCreateTransMacFile_3k3des_PK((uint8_t *)des3k_key_ext_, (uint32_t)aid, (uint8_t)file_id, (uint8_t)read_key_no, (uint8_t)commit_reader_id_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint8_t *)trans_mac_key_, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(des3k_key_ext, des3k_key_ext_, 0);
	env->ReleaseByteArrayElements(trans_mac_key, trans_mac_key_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateTransMacFileAesAuth(JNIEnv *env, jobject instance, jbyte aes_key_nr, jint aid, jbyte file_id, jbyte read_key_no, jbyte commit_reader_id_key_no, jbyte change_key_no, jbyte communication_settings,  jbyteArray trans_mac_key, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *trans_mac_key_ = env->GetByteArrayElements(trans_mac_key, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_SAM_DesfireCreateTransMacFileAesAuth((uint8_t)aes_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)read_key_no, (uint8_t)commit_reader_id_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint8_t *)trans_mac_key_, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(trans_mac_key, trans_mac_key_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateTransMacFileDesAuth(JNIEnv *env, jobject instance, jbyte des_key_nr, jint aid, jbyte file_id, jbyte read_key_no, jbyte commit_reader_id_key_no, jbyte change_key_no, jbyte communication_settings,  jbyteArray trans_mac_key, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *trans_mac_key_ = env->GetByteArrayElements(trans_mac_key, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_SAM_DesfireCreateTransMacFileDesAuth((uint8_t)des_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)read_key_no, (uint8_t)commit_reader_id_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint8_t *)trans_mac_key_, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(trans_mac_key, trans_mac_key_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateTransMacFile2k3desAuth(JNIEnv *env, jobject instance, jbyte des2k_key_nr, jint aid, jbyte file_id, jbyte read_key_no, jbyte commit_reader_id_key_no, jbyte change_key_no, jbyte communication_settings,  jbyteArray trans_mac_key, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *trans_mac_key_ = env->GetByteArrayElements(trans_mac_key, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_SAM_DesfireCreateTransMacFile2k3desAuth((uint8_t)des2k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)read_key_no, (uint8_t)commit_reader_id_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint8_t *)trans_mac_key_, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(trans_mac_key, trans_mac_key_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1SAM_1DesfireCreateTransMacFile3k3desAuth(JNIEnv *env, jobject instance, jbyte des3k_key_nr, jint aid, jbyte file_id, jbyte read_key_no, jbyte commit_reader_id_key_no, jbyte change_key_no, jbyte communication_settings,  jbyteArray trans_mac_key, jshortArray card_status, jshortArray exec_time) {

	
	UFR_STATUS status;

	jbyte *trans_mac_key_ = env->GetByteArrayElements(trans_mac_key, 0);
	jshort *card_status_ = env->GetShortArrayElements(card_status, 0);
	jshort *exec_time_ = env->GetShortArrayElements(exec_time, 0);

	status = uFR_SAM_DesfireCreateTransMacFile3k3desAuth((uint8_t)des3k_key_nr, (uint32_t)aid, (uint8_t)file_id, (uint8_t)read_key_no, (uint8_t)commit_reader_id_key_no, (uint8_t)change_key_no, (uint8_t)communication_settings, (uint8_t *)trans_mac_key_, (uint16_t *)card_status_, (uint16_t *)exec_time_);

	env->ReleaseByteArrayElements(trans_mac_key, trans_mac_key_, 0);
	env->ReleaseShortArrayElements(card_status, card_status_, 0);
	env->ReleaseShortArrayElements(exec_time, exec_time_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_WriteReaderId(JNIEnv *env, jobject instance,  jbyteArray reader_id) {

	
	UFR_STATUS status;

	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);

	status = WriteReaderId((uint8_t *)reader_id_);

	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_dfl_1change_1tmc_1file_1settings(JNIEnv *env, jobject instance, jbyte aes_key_no, jbyte file_no, jbyte key_no, jbyte curr_communication_mode, jbyte new_communication_mode, jbyte read_key_no, jbyte commit_reader_id_key_no, jbyte change_key_no, jbyte ex_unauth_operation, jbyte tmc_limit_conf, jint tmc_limit) {

	
	UFR_STATUS status;


	status = dfl_change_tmc_file_settings((uint8_t)aes_key_no, (uint8_t)file_no, (uint8_t)key_no, (uint8_t)curr_communication_mode, (uint8_t)new_communication_mode, (uint8_t)read_key_no, (uint8_t)commit_reader_id_key_no, (uint8_t)change_key_no, (uint8_t)ex_unauth_operation, (uint8_t)tmc_limit_conf, (uint32_t)tmc_limit);


	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_dfl_1change_1tmc_1file_1settings_1pk(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jbyte file_no, jbyte key_no, jbyte curr_communication_mode, jbyte new_communication_mode, jbyte read_key_no, jbyte commit_reader_id_key_no, jbyte change_key_no, jbyte ex_unauth_operation, jbyte tmc_limit_conf, jint tmc_limit) {

	
	UFR_STATUS status;

	jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);

	status = dfl_change_tmc_file_settings_pk((uint8_t *)aes_key_ext_, (uint8_t)file_no, (uint8_t)key_no, (uint8_t)curr_communication_mode, (uint8_t)new_communication_mode, (uint8_t)read_key_no, (uint8_t)commit_reader_id_key_no, (uint8_t)change_key_no, (uint8_t)ex_unauth_operation, (uint8_t)tmc_limit_conf, (uint32_t)tmc_limit);

	env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_dfl_1check_1credit_1value_1transaction_1mac(JNIEnv *env, jobject instance, jbyte file_no, jint value, jint trans_mac_counter,  jbyteArray uid,  jbyteArray trans_mac_key,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jbyteArray trans_mac_value,  jbyteArray prev_reader_id) {

	
	UFR_STATUS status;

	jbyte *uid_ = env->GetByteArrayElements(uid, 0);
	jbyte *trans_mac_key_ = env->GetByteArrayElements(trans_mac_key, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);
	jbyte *prev_reader_id_ = env->GetByteArrayElements(prev_reader_id, 0);

	status = dfl_check_credit_value_transaction_mac((uint8_t)file_no, (uint32_t)value, (uint32_t)trans_mac_counter, (uint8_t *)uid_, (uint8_t *)trans_mac_key_, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint8_t *)trans_mac_value_, (uint8_t *)prev_reader_id_);

	env->ReleaseByteArrayElements(uid, uid_, 0);
	env->ReleaseByteArrayElements(trans_mac_key, trans_mac_key_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);
	env->ReleaseByteArrayElements(prev_reader_id, prev_reader_id_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_dfl_1check_1debit_1value_1transaction_1mac(JNIEnv *env, jobject instance, jbyte file_no, jint value, jint trans_mac_counter,  jbyteArray uid,  jbyteArray trans_mac_key,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jbyteArray trans_mac_value,  jbyteArray prev_reader_id) {

	
	UFR_STATUS status;

	jbyte *uid_ = env->GetByteArrayElements(uid, 0);
	jbyte *trans_mac_key_ = env->GetByteArrayElements(trans_mac_key, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);
	jbyte *prev_reader_id_ = env->GetByteArrayElements(prev_reader_id, 0);

	status = dfl_check_debit_value_transaction_mac((uint8_t)file_no, (uint32_t)value, (uint32_t)trans_mac_counter, (uint8_t *)uid_, (uint8_t *)trans_mac_key_, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint8_t *)trans_mac_value_, (uint8_t *)prev_reader_id_);

	env->ReleaseByteArrayElements(uid, uid_, 0);
	env->ReleaseByteArrayElements(trans_mac_key, trans_mac_key_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);
	env->ReleaseByteArrayElements(prev_reader_id, prev_reader_id_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_desfire_1check_1write_1record_1transaction_1mac(JNIEnv *env, jobject instance, jbyte file_no, jint offset, jint data_len,  jbyteArray data, jint trans_mac_counter,  jbyteArray uid,  jbyteArray trans_mac_key,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jbyteArray trans_mac_value,  jbyteArray prev_reader_id) {

	
	UFR_STATUS status;

	jbyte *data_ = env->GetByteArrayElements(data, 0);
	jbyte *uid_ = env->GetByteArrayElements(uid, 0);
	jbyte *trans_mac_key_ = env->GetByteArrayElements(trans_mac_key, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);
	jbyte *prev_reader_id_ = env->GetByteArrayElements(prev_reader_id, 0);

	status = desfire_check_write_record_transaction_mac((uint8_t)file_no, (uint32_t)offset, (uint32_t)data_len, (uint8_t *)data_, (uint32_t)trans_mac_counter, (uint8_t *)uid_, (uint8_t *)trans_mac_key_, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint8_t *)trans_mac_value_, (uint8_t *)prev_reader_id_);

	env->ReleaseByteArrayElements(data, data_, 0);
	env->ReleaseByteArrayElements(uid, uid_, 0);
	env->ReleaseByteArrayElements(trans_mac_key, trans_mac_key_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);
	env->ReleaseByteArrayElements(prev_reader_id, prev_reader_id_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_dfl_1check_1write_1record_1transaction_1mac(JNIEnv *env, jobject instance, jbyte file_no, jint offset, jint data_len,  jbyteArray data, jint trans_mac_counter,  jbyteArray uid,  jbyteArray trans_mac_key,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jbyteArray trans_mac_value,  jbyteArray prev_reader_id) {

	
	UFR_STATUS status;

	jbyte *data_ = env->GetByteArrayElements(data, 0);
	jbyte *uid_ = env->GetByteArrayElements(uid, 0);
	jbyte *trans_mac_key_ = env->GetByteArrayElements(trans_mac_key, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);
	jbyte *prev_reader_id_ = env->GetByteArrayElements(prev_reader_id, 0);

	status = dfl_check_write_record_transaction_mac((uint8_t)file_no, (uint32_t)offset, (uint32_t)data_len, (uint8_t *)data_, (uint32_t)trans_mac_counter, (uint8_t *)uid_, (uint8_t *)trans_mac_key_, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint8_t *)trans_mac_value_, (uint8_t *)prev_reader_id_);

	env->ReleaseByteArrayElements(data, data_, 0);
	env->ReleaseByteArrayElements(uid, uid_, 0);
	env->ReleaseByteArrayElements(trans_mac_key, trans_mac_key_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);
	env->ReleaseByteArrayElements(prev_reader_id, prev_reader_id_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_desfire_1check_1clear_1record_1transaction_1mac(JNIEnv *env, jobject instance, jbyte file_no, jint trans_mac_counter,  jbyteArray uid,  jbyteArray trans_mac_key,  jbyteArray reader_id,  jbyteArray prev_enc_reader_id,  jbyteArray trans_mac_value,  jbyteArray prev_reader_id) {

	
	UFR_STATUS status;

	jbyte *uid_ = env->GetByteArrayElements(uid, 0);
	jbyte *trans_mac_key_ = env->GetByteArrayElements(trans_mac_key, 0);
	jbyte *reader_id_ = env->GetByteArrayElements(reader_id, 0);
	jbyte *prev_enc_reader_id_ = env->GetByteArrayElements(prev_enc_reader_id, 0);
	jbyte *trans_mac_value_ = env->GetByteArrayElements(trans_mac_value, 0);
	jbyte *prev_reader_id_ = env->GetByteArrayElements(prev_reader_id, 0);

	status = desfire_check_clear_record_transaction_mac((uint8_t)file_no, (uint32_t)trans_mac_counter, (uint8_t *)uid_, (uint8_t *)trans_mac_key_, (uint8_t *)reader_id_, (uint8_t *)prev_enc_reader_id_, (uint8_t *)trans_mac_value_, (uint8_t *)prev_reader_id_);

	env->ReleaseByteArrayElements(uid, uid_, 0);
	env->ReleaseByteArrayElements(trans_mac_key, trans_mac_key_, 0);
	env->ReleaseByteArrayElements(reader_id, reader_id_, 0);
	env->ReleaseByteArrayElements(prev_enc_reader_id, prev_enc_reader_id_, 0);
	env->ReleaseByteArrayElements(trans_mac_value, trans_mac_value_, 0);
	env->ReleaseByteArrayElements(prev_reader_id, prev_reader_id_, 0);

	return status;
}



extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_EMV_1GetPAN(JNIEnv *env, jobject instance,  jstring df_name,  jbyteArray pan_str) {

	
	UFR_STATUS status;

	const char* df_name_ = env->GetStringUTFChars(df_name, 0);

	jbyte *pan_str_ =  (signed char *) env->GetByteArrayElements(pan_str, 0);

	status = EMV_GetPAN(df_name_, (char *)pan_str_);

	env->ReleaseByteArrayElements(pan_str, pan_str_, 0);

	env->ReleaseStringUTFChars(df_name, df_name_);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_EMV_1GetLastTransaction(JNIEnv *env, jobject instance,  jstring df_name,  jbyteArray last_transaction_info) {

	
	UFR_STATUS status;

	const char* df_name_ = env->GetStringUTFChars(df_name, 0);
	
	jbyte *last_transaction_info_ =  (signed char *) env->GetByteArrayElements(last_transaction_info, 0);

	status = EMV_GetLastTransaction(df_name_, (char *)last_transaction_info_);

	env->ReleaseByteArrayElements(last_transaction_info, last_transaction_info_, 0);

	env->ReleaseStringUTFChars(df_name, df_name_);

	return status;
}



extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_ReadECCSignatureExt(JNIEnv *env, jobject instance,  jbyteArray lpucECCSignature, jbyteArray lpucECCSignatureLen,  jbyteArray lpucUid, jbyteArray lpucUidLen, jbyteArray lpucDlogicCardType) {

	
	UFR_STATUS status;

	jbyte *lpucECCSignature_ = env->GetByteArrayElements(lpucECCSignature, 0);
	jbyte *lpucECCSignatureLen_ = env->GetByteArrayElements(lpucECCSignatureLen, 0);
	jbyte *lpucUid_ = env->GetByteArrayElements(lpucUid, 0);
	jbyte *lpucUidLen_ = env->GetByteArrayElements(lpucUidLen, 0);
	jbyte *lpucDlogicCardType_ = env->GetByteArrayElements(lpucDlogicCardType, 0);

	status = ReadECCSignatureExt((uint8_t *)lpucECCSignature_, (uint8_t *)lpucECCSignatureLen_, (uint8_t *)lpucUid_, (uint8_t *)lpucUidLen_, (uint8_t *)lpucDlogicCardType_);

	env->ReleaseByteArrayElements(lpucECCSignature, lpucECCSignature_, 0);
	env->ReleaseByteArrayElements(lpucECCSignatureLen, lpucECCSignatureLen_, 0);
	env->ReleaseByteArrayElements(lpucUid, lpucUid_, 0);
	env->ReleaseByteArrayElements(lpucUidLen, lpucUidLen_, 0);
	env->ReleaseByteArrayElements(lpucDlogicCardType, lpucDlogicCardType_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireUidReadECCSignature(JNIEnv *env, jobject instance,  jbyteArray lpucECCSignature,  jbyteArray card_uid, jbyteArray lpucDlogicCardType) {

	
	UFR_STATUS status;

	jbyte *lpucECCSignature_ = env->GetByteArrayElements(lpucECCSignature, 0);
	jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
	jbyte *lpucDlogicCardType_ = env->GetByteArrayElements(lpucDlogicCardType, 0);

	status = uFR_int_DesfireUidReadECCSignature((uint8_t *)lpucECCSignature_, (uint8_t *)card_uid_, (uint8_t *)lpucDlogicCardType_);

	env->ReleaseByteArrayElements(lpucECCSignature, lpucECCSignature_, 0);
	env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
	env->ReleaseByteArrayElements(lpucDlogicCardType, lpucDlogicCardType_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireRidReadECCSignature_1des_1PK(JNIEnv *env, jobject instance,  jbyteArray auth_key_ext, jint aid, jbyte aid_key_nr,  jbyteArray card_uid,  jbyteArray lpucECCSignature, jbyteArray lpucDlogicCardType) {

	
	UFR_STATUS status;

	jbyte *auth_key_ext_ = env->GetByteArrayElements(auth_key_ext, 0);
	jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
	jbyte *lpucECCSignature_ = env->GetByteArrayElements(lpucECCSignature, 0);
	jbyte *lpucDlogicCardType_ = env->GetByteArrayElements(lpucDlogicCardType, 0);

	status = uFR_int_DesfireRidReadECCSignature_des_PK((uint8_t *)auth_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)lpucECCSignature_, (uint8_t *)lpucDlogicCardType_);

	env->ReleaseByteArrayElements(auth_key_ext, auth_key_ext_, 0);
	env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
	env->ReleaseByteArrayElements(lpucECCSignature, lpucECCSignature_, 0);
	env->ReleaseByteArrayElements(lpucDlogicCardType, lpucDlogicCardType_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireRidReadECCSignature_12k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray auth_key_ext, jint aid, jbyte aid_key_nr,  jbyteArray card_uid,  jbyteArray lpucECCSignature, jbyteArray lpucDlogicCardType) {

	
	UFR_STATUS status;

	jbyte *auth_key_ext_ = env->GetByteArrayElements(auth_key_ext, 0);
	jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
	jbyte *lpucECCSignature_ = env->GetByteArrayElements(lpucECCSignature, 0);
	jbyte *lpucDlogicCardType_ = env->GetByteArrayElements(lpucDlogicCardType, 0);

	status = uFR_int_DesfireRidReadECCSignature_2k3des_PK((uint8_t *)auth_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)lpucECCSignature_, (uint8_t *)lpucDlogicCardType_);

	env->ReleaseByteArrayElements(auth_key_ext, auth_key_ext_, 0);
	env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
	env->ReleaseByteArrayElements(lpucECCSignature, lpucECCSignature_, 0);
	env->ReleaseByteArrayElements(lpucDlogicCardType, lpucDlogicCardType_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireRidReadECCSignature_13k3des_1PK(JNIEnv *env, jobject instance,  jbyteArray auth_key_ext, jint aid, jbyte aid_key_nr,  jbyteArray card_uid,  jbyteArray lpucECCSignature, jbyteArray lpucDlogicCardType) {

	
	UFR_STATUS status;

	jbyte *auth_key_ext_ = env->GetByteArrayElements(auth_key_ext, 0);
	jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
	jbyte *lpucECCSignature_ = env->GetByteArrayElements(lpucECCSignature, 0);
	jbyte *lpucDlogicCardType_ = env->GetByteArrayElements(lpucDlogicCardType, 0);

	status = uFR_int_DesfireRidReadECCSignature_3k3des_PK((uint8_t *)auth_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)lpucECCSignature_, (uint8_t *)lpucDlogicCardType_);

	env->ReleaseByteArrayElements(auth_key_ext, auth_key_ext_, 0);
	env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
	env->ReleaseByteArrayElements(lpucECCSignature, lpucECCSignature_, 0);
	env->ReleaseByteArrayElements(lpucDlogicCardType, lpucDlogicCardType_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireRidReadECCSignature_1aes_1PK(JNIEnv *env, jobject instance,  jbyteArray auth_key_ext, jint aid, jbyte aid_key_nr,  jbyteArray card_uid,  jbyteArray lpucECCSignature, jbyteArray lpucDlogicCardType) {

	
	UFR_STATUS status;

	jbyte *auth_key_ext_ = env->GetByteArrayElements(auth_key_ext, 0);
	jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
	jbyte *lpucECCSignature_ = env->GetByteArrayElements(lpucECCSignature, 0);
	jbyte *lpucDlogicCardType_ = env->GetByteArrayElements(lpucDlogicCardType, 0);

	status = uFR_int_DesfireRidReadECCSignature_aes_PK((uint8_t *)auth_key_ext_, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)lpucECCSignature_, (uint8_t *)lpucDlogicCardType_);

	env->ReleaseByteArrayElements(auth_key_ext, auth_key_ext_, 0);
	env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
	env->ReleaseByteArrayElements(lpucECCSignature, lpucECCSignature_, 0);
	env->ReleaseByteArrayElements(lpucDlogicCardType, lpucDlogicCardType_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireRidReadECCSignature_1des(JNIEnv *env, jobject instance, jbyte auth_key_nr, jint aid, jbyte aid_key_nr,  jbyteArray card_uid,  jbyteArray lpucECCSignature, jbyteArray lpucDlogicCardType) {

	
	UFR_STATUS status;

	jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
	jbyte *lpucECCSignature_ = env->GetByteArrayElements(lpucECCSignature, 0);
	jbyte *lpucDlogicCardType_ = env->GetByteArrayElements(lpucDlogicCardType, 0);

	status = uFR_int_DesfireRidReadECCSignature_des((uint8_t)auth_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)lpucECCSignature_, (uint8_t *)lpucDlogicCardType_);

	env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
	env->ReleaseByteArrayElements(lpucECCSignature, lpucECCSignature_, 0);
	env->ReleaseByteArrayElements(lpucDlogicCardType, lpucDlogicCardType_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireRidReadECCSignature_12k3des(JNIEnv *env, jobject instance, jbyte auth_key_nr, jint aid, jbyte aid_key_nr,  jbyteArray card_uid,  jbyteArray lpucECCSignature, jbyteArray lpucDlogicCardType) {

	
	UFR_STATUS status;

	jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
	jbyte *lpucECCSignature_ = env->GetByteArrayElements(lpucECCSignature, 0);
	jbyte *lpucDlogicCardType_ = env->GetByteArrayElements(lpucDlogicCardType, 0);

	status = uFR_int_DesfireRidReadECCSignature_2k3des((uint8_t)auth_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)lpucECCSignature_, (uint8_t *)lpucDlogicCardType_);

	env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
	env->ReleaseByteArrayElements(lpucECCSignature, lpucECCSignature_, 0);
	env->ReleaseByteArrayElements(lpucDlogicCardType, lpucDlogicCardType_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireRidReadECCSignature_13k3des(JNIEnv *env, jobject instance, jbyte auth_key_nr, jint aid, jbyte aid_key_nr,  jbyteArray card_uid,  jbyteArray lpucECCSignature, jbyteArray lpucDlogicCardType) {

	
	UFR_STATUS status;

	jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
	jbyte *lpucECCSignature_ = env->GetByteArrayElements(lpucECCSignature, 0);
	jbyte *lpucDlogicCardType_ = env->GetByteArrayElements(lpucDlogicCardType, 0);

	status = uFR_int_DesfireRidReadECCSignature_3k3des((uint8_t)auth_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)lpucECCSignature_, (uint8_t *)lpucDlogicCardType_);

	env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
	env->ReleaseByteArrayElements(lpucECCSignature, lpucECCSignature_, 0);
	env->ReleaseByteArrayElements(lpucDlogicCardType, lpucDlogicCardType_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_uFR_1int_1DesfireRidReadECCSignature_1aes(JNIEnv *env, jobject instance, jbyte auth_key_nr, jint aid, jbyte aid_key_nr,  jbyteArray card_uid,  jbyteArray lpucECCSignature, jbyteArray lpucDlogicCardType) {

	
	UFR_STATUS status;

	jbyte *card_uid_ = env->GetByteArrayElements(card_uid, 0);
	jbyte *lpucECCSignature_ = env->GetByteArrayElements(lpucECCSignature, 0);
	jbyte *lpucDlogicCardType_ = env->GetByteArrayElements(lpucDlogicCardType, 0);

	status = uFR_int_DesfireRidReadECCSignature_aes((uint8_t)auth_key_nr, (uint32_t)aid, (uint8_t)aid_key_nr, (uint8_t *)card_uid_, (uint8_t *)lpucECCSignature_, (uint8_t *)lpucDlogicCardType_);

	env->ReleaseByteArrayElements(card_uid, card_uid_, 0);
	env->ReleaseByteArrayElements(lpucECCSignature, lpucECCSignature_, 0);
	env->ReleaseByteArrayElements(lpucDlogicCardType, lpucDlogicCardType_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1tt_1change_1sdm_1file_1settings_1pk(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jbyte file_no, jbyte key_no, jbyte curr_communication_mode, jbyte new_communication_mode, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte uid_enable, jbyte read_ctr_enable, jbyte read_ctr_limit_enable, jbyte enc_file_data_enable, jbyte meta_data_key_no, jbyte file_data_read_key_no, jbyte read_ctr_key_no, jint uid_offset, jint read_ctr_offset, jint picc_data_offset, jint mac_input_offset, jint enc_offset, jint enc_length, jint mac_offset, jint read_ctr_limit, jbyte tt_status_enable, jint tt_status_offset) {

	
	UFR_STATUS status;

	jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);

	status = nt4h_tt_change_sdm_file_settings_pk((uint8_t *)aes_key_ext_, (uint8_t)file_no, (uint8_t)key_no, (uint8_t)curr_communication_mode, (uint8_t)new_communication_mode, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)uid_enable, (uint8_t)read_ctr_enable, (uint8_t)read_ctr_limit_enable, (uint8_t)enc_file_data_enable, (uint8_t)meta_data_key_no, (uint8_t)file_data_read_key_no, (uint8_t)read_ctr_key_no, (uint32_t)uid_offset, (uint32_t)read_ctr_offset, (uint32_t)picc_data_offset, (uint32_t)mac_input_offset, (uint32_t)enc_offset, (uint32_t)enc_length, (uint32_t)mac_offset, (uint32_t)read_ctr_limit, (uint8_t)tt_status_enable, (uint32_t)tt_status_offset);

	env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1tt_1change_1sdm_1file_1settings(JNIEnv *env, jobject instance, jbyte aes_key_no, jbyte file_no, jbyte key_no, jbyte curr_communication_mode, jbyte new_communication_mode, jbyte read_key_no, jbyte write_key_no, jbyte read_write_key_no, jbyte change_key_no, jbyte uid_enable, jbyte read_ctr_enable, jbyte read_ctr_limit_enable, jbyte enc_file_data_enable, jbyte meta_data_key_no, jbyte file_data_read_key_no, jbyte read_ctr_key_no, jint uid_offset, jint read_ctr_offset, jint picc_data_offset, jint mac_input_offset, jint enc_offset, jint enc_length, jint mac_offset, jint read_ctr_limit, jbyte tt_status_enable, jint tt_status_offset) {

	
	UFR_STATUS status;


	status = nt4h_tt_change_sdm_file_settings((uint8_t)aes_key_no, (uint8_t)file_no, (uint8_t)key_no, (uint8_t)curr_communication_mode, (uint8_t)new_communication_mode, (uint8_t)read_key_no, (uint8_t)write_key_no, (uint8_t)read_write_key_no, (uint8_t)change_key_no, (uint8_t)uid_enable, (uint8_t)read_ctr_enable, (uint8_t)read_ctr_limit_enable, (uint8_t)enc_file_data_enable, (uint8_t)meta_data_key_no, (uint8_t)file_data_read_key_no, (uint8_t)read_ctr_key_no, (uint32_t)uid_offset, (uint32_t)read_ctr_offset, (uint32_t)picc_data_offset, (uint32_t)mac_input_offset, (uint32_t)enc_offset, (uint32_t)enc_length, (uint32_t)mac_offset, (uint32_t)read_ctr_limit, (uint8_t)tt_status_enable, (uint32_t)tt_status_offset);


	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1tt_1get_1file_1settings(JNIEnv *env, jobject instance, jbyte file_no, jbyteArray file_type, jbyteArray communication_mode, jbyteArray sdm_enable, jintArray file_size, jbyteArray read_key_no, jbyteArray write_key_no, jbyteArray read_write_key_no, jbyteArray change_key_no, jbyteArray uid_enable, jbyteArray read_ctr_enable, jbyteArray read_ctr_limit_enable, jbyteArray enc_file_data_enable, jbyteArray meta_data_key_no, jbyteArray file_data_read_key_no, jbyteArray read_ctr_key_no, jintArray uid_offset, jintArray read_ctr_offset, jintArray picc_data_offset, jintArray mac_input_offset, jintArray enc_offset, jintArray enc_length, jintArray mac_offset, jintArray read_ctr_limit, jbyteArray tt_status_enable, jintArray tt_status_offset) {

	
	UFR_STATUS status;

	jbyte *file_type_ = env->GetByteArrayElements(file_type, 0);
	jbyte *communication_mode_ = env->GetByteArrayElements(communication_mode, 0);
	jbyte *sdm_enable_ = env->GetByteArrayElements(sdm_enable, 0);
	jint *file_size_ = env->GetIntArrayElements(file_size, 0);
	jbyte *read_key_no_ = env->GetByteArrayElements(read_key_no, 0);
	jbyte *write_key_no_ = env->GetByteArrayElements(write_key_no, 0);
	jbyte *read_write_key_no_ = env->GetByteArrayElements(read_write_key_no, 0);
	jbyte *change_key_no_ = env->GetByteArrayElements(change_key_no, 0);
	jbyte *uid_enable_ = env->GetByteArrayElements(uid_enable, 0);
	jbyte *read_ctr_enable_ = env->GetByteArrayElements(read_ctr_enable, 0);
	jbyte *read_ctr_limit_enable_ = env->GetByteArrayElements(read_ctr_limit_enable, 0);
	jbyte *enc_file_data_enable_ = env->GetByteArrayElements(enc_file_data_enable, 0);
	jbyte *meta_data_key_no_ = env->GetByteArrayElements(meta_data_key_no, 0);
	jbyte *file_data_read_key_no_ = env->GetByteArrayElements(file_data_read_key_no, 0);
	jbyte *read_ctr_key_no_ = env->GetByteArrayElements(read_ctr_key_no, 0);
	jint *uid_offset_ = env->GetIntArrayElements(uid_offset, 0);
	jint *read_ctr_offset_ = env->GetIntArrayElements(read_ctr_offset, 0);
	jint *picc_data_offset_ = env->GetIntArrayElements(picc_data_offset, 0);
	jint *mac_input_offset_ = env->GetIntArrayElements(mac_input_offset, 0);
	jint *enc_offset_ = env->GetIntArrayElements(enc_offset, 0);
	jint *enc_length_ = env->GetIntArrayElements(enc_length, 0);
	jint *mac_offset_ = env->GetIntArrayElements(mac_offset, 0);
	jint *read_ctr_limit_ = env->GetIntArrayElements(read_ctr_limit, 0);
	jbyte *tt_status_enable_ = env->GetByteArrayElements(tt_status_enable, 0);
	jint *tt_status_offset_ = env->GetIntArrayElements(tt_status_offset, 0);

	status = nt4h_tt_get_file_settings((uint8_t)file_no, (uint8_t *)file_type_, (uint8_t *)communication_mode_, (uint8_t *)sdm_enable_, (uint32_t *)file_size_, (uint8_t *)read_key_no_, (uint8_t *)write_key_no_, (uint8_t *)read_write_key_no_, (uint8_t *)change_key_no_, (uint8_t *)uid_enable_, (uint8_t *)read_ctr_enable_, (uint8_t *)read_ctr_limit_enable_, (uint8_t *)enc_file_data_enable_, (uint8_t *)meta_data_key_no_, (uint8_t *)file_data_read_key_no_, (uint8_t *)read_ctr_key_no_, (uint32_t *)uid_offset_, (uint32_t *)read_ctr_offset_, (uint32_t *)picc_data_offset_, (uint32_t *)mac_input_offset_, (uint32_t *)enc_offset_, (uint32_t *)enc_length_, (uint32_t *)mac_offset_, (uint32_t *)read_ctr_limit_, (uint8_t *)tt_status_enable_, (uint32_t *)tt_status_offset_);

	env->ReleaseByteArrayElements(file_type, file_type_, 0);
	env->ReleaseByteArrayElements(communication_mode, communication_mode_, 0);
	env->ReleaseByteArrayElements(sdm_enable, sdm_enable_, 0);
	env->ReleaseIntArrayElements(file_size, file_size_, 0);
	env->ReleaseByteArrayElements(read_key_no, read_key_no_, 0);
	env->ReleaseByteArrayElements(write_key_no, write_key_no_, 0);
	env->ReleaseByteArrayElements(read_write_key_no, read_write_key_no_, 0);
	env->ReleaseByteArrayElements(change_key_no, change_key_no_, 0);
	env->ReleaseByteArrayElements(uid_enable, uid_enable_, 0);
	env->ReleaseByteArrayElements(read_ctr_enable, read_ctr_enable_, 0);
	env->ReleaseByteArrayElements(read_ctr_limit_enable, read_ctr_limit_enable_, 0);
	env->ReleaseByteArrayElements(enc_file_data_enable, enc_file_data_enable_, 0);
	env->ReleaseByteArrayElements(meta_data_key_no, meta_data_key_no_, 0);
	env->ReleaseByteArrayElements(file_data_read_key_no, file_data_read_key_no_, 0);
	env->ReleaseByteArrayElements(read_ctr_key_no, read_ctr_key_no_, 0);
	env->ReleaseIntArrayElements(uid_offset, uid_offset_, 0);
	env->ReleaseIntArrayElements(read_ctr_offset, read_ctr_offset_, 0);
	env->ReleaseIntArrayElements(picc_data_offset, picc_data_offset_, 0);
	env->ReleaseIntArrayElements(mac_input_offset, mac_input_offset_, 0);
	env->ReleaseIntArrayElements(enc_offset, enc_offset_, 0);
	env->ReleaseIntArrayElements(enc_length, enc_length_, 0);
	env->ReleaseIntArrayElements(mac_offset, mac_offset_, 0);
	env->ReleaseIntArrayElements(read_ctr_limit, read_ctr_limit_, 0);
	env->ReleaseByteArrayElements(tt_status_enable, tt_status_enable_, 0);
	env->ReleaseIntArrayElements(tt_status_offset, tt_status_offset_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1rid_1read_1ecc_1signature_1pk(JNIEnv *env, jobject instance,  jbyteArray auth_key, jbyte key_no,  jbyteArray uid,  jbyteArray ecc_signature, jbyteArray dlogic_card_type) {

	
	UFR_STATUS status;

	jbyte *auth_key_ = env->GetByteArrayElements(auth_key, 0);
	jbyte *uid_ = env->GetByteArrayElements(uid, 0);
	jbyte *ecc_signature_ = env->GetByteArrayElements(ecc_signature, 0);
	jbyte *dlogic_card_type_ = env->GetByteArrayElements(dlogic_card_type, 0);

	status = nt4h_rid_read_ecc_signature_pk((uint8_t *)auth_key_, (uint8_t)key_no, (uint8_t *)uid_, (uint8_t *)ecc_signature_, (uint8_t *)dlogic_card_type_);

	env->ReleaseByteArrayElements(auth_key, auth_key_, 0);
	env->ReleaseByteArrayElements(uid, uid_, 0);
	env->ReleaseByteArrayElements(ecc_signature, ecc_signature_, 0);
	env->ReleaseByteArrayElements(dlogic_card_type, dlogic_card_type_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1rid_1read_1ecc_1signature(JNIEnv *env, jobject instance, jbyte auth_key_nr, jbyte key_no,  jbyteArray uid,  jbyteArray ecc_signature,  jbyteArray dlogic_card_type) {

	
	UFR_STATUS status;

	jbyte *uid_ = env->GetByteArrayElements(uid, 0);
	jbyte *ecc_signature_ = env->GetByteArrayElements(ecc_signature, 0);
	jbyte *dlogic_card_type_ = env->GetByteArrayElements(dlogic_card_type, 0);

	status = nt4h_rid_read_ecc_signature((uint8_t)auth_key_nr, (uint8_t)key_no, (uint8_t *)uid_, (uint8_t *)ecc_signature_, (uint8_t *)dlogic_card_type_);

	env->ReleaseByteArrayElements(uid, uid_, 0);
	env->ReleaseByteArrayElements(ecc_signature, ecc_signature_, 0);
	env->ReleaseByteArrayElements(dlogic_card_type, dlogic_card_type_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1get_1tt_1status_1pk(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jbyte key_no, jbyteArray tt_perm_status, jbyteArray tt_curr_status) {

	
	UFR_STATUS status;

	jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);
	jbyte *tt_perm_status_ = env->GetByteArrayElements(tt_perm_status, 0);
	jbyte *tt_curr_status_ = env->GetByteArrayElements(tt_curr_status, 0);

	status = nt4h_get_tt_status_pk((uint8_t *)aes_key_ext_, (uint8_t)key_no, (uint8_t *)tt_perm_status_, (uint8_t *)tt_curr_status_);

	env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);
	env->ReleaseByteArrayElements(tt_perm_status, tt_perm_status_, 0);
	env->ReleaseByteArrayElements(tt_curr_status, tt_curr_status_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1get_1tt_1status(JNIEnv *env, jobject instance, jbyte aes_key_nr, jbyte key_no, jbyteArray tt_perm_status, jbyteArray tt_curr_status) {

	
	UFR_STATUS status;

	jbyte *tt_perm_status_ = env->GetByteArrayElements(tt_perm_status, 0);
	jbyte *tt_curr_status_ = env->GetByteArrayElements(tt_curr_status, 0);

	status = nt4h_get_tt_status((uint8_t)aes_key_nr, (uint8_t)key_no, (uint8_t *)tt_perm_status_, (uint8_t *)tt_curr_status_);

	env->ReleaseByteArrayElements(tt_perm_status, tt_perm_status_, 0);
	env->ReleaseByteArrayElements(tt_curr_status, tt_curr_status_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1get_1tt_1status_1no_1auth(JNIEnv *env, jobject instance, jbyteArray tt_perm_status, jbyteArray tt_curr_status) {

	
	UFR_STATUS status;

	jbyte *tt_perm_status_ = env->GetByteArrayElements(tt_perm_status, 0);
	jbyte *tt_curr_status_ = env->GetByteArrayElements(tt_curr_status, 0);

	status = nt4h_get_tt_status_no_auth((uint8_t *)tt_perm_status_, (uint8_t *)tt_curr_status_);

	env->ReleaseByteArrayElements(tt_perm_status, tt_perm_status_, 0);
	env->ReleaseByteArrayElements(tt_curr_status, tt_curr_status_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1enable_1tt_1pk(JNIEnv *env, jobject instance,  jbyteArray aes_key_ext, jbyte tt_status_key_no) {

	
	UFR_STATUS status;

	jbyte *aes_key_ext_ = env->GetByteArrayElements(aes_key_ext, 0);

	status = nt4h_enable_tt_pk((uint8_t *)aes_key_ext_, (uint8_t)tt_status_key_no);

	env->ReleaseByteArrayElements(aes_key_ext, aes_key_ext_, 0);

	return status;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dlogic_uFCoder_nt4h_1enable_1tt(JNIEnv *env, jobject instance, jbyte aes_key_no, jbyte tt_status_key_no) {

	
	UFR_STATUS status;


	status = nt4h_enable_tt((uint8_t)aes_key_no, (uint8_t)tt_status_key_no);


	return status;
}

