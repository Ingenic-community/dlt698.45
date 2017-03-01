

#ifndef DLT698_H_
#define DLT698_H_
#include "Objectdef.h"

extern int doObjectAction(OAD oad,INT8U *data);
extern int StateProcess(CommBlock* nst, int delay_num);
extern int ProcessData(CommBlock *com);
extern int Link_Request(LINK_Request request,INT8U *addr,INT8U *buf);
extern void testframe(INT8U *apdu,int len);
extern int  create_OAD(INT8U *data,OAD oad);
extern INT8U Report_Event(CommBlock *com,Reportevent report_event);
extern INT16U composeAutoReport(INT8U* SendApdu,INT16U length);
/*----------------------统计相关数据----------------------*/
extern INT8U Get_2200(OI_698 oi,INT8U *sourcebuf,INT8U *buf,int *len);
extern INT8U Get_2203(OI_698 oi,INT8U *sourcebuf,INT8U *buf,int *len);
extern INT8U Get_2204(OI_698 oi,INT8U *sourcebuf,INT8U *buf,int *len);

/*----------------------抄表相关*************************/
INT16S composeProtocol698_GetRequest(INT8U*,CLASS_6015,TSA);
//OAD转换为报文
extern INT8U OADtoBuff(OAD fromOAD,INT8U* buff);

extern void ProxyListResponse(PROXY_GETLIST *list,CommBlock *com);
int createFile(const char * path, int length, unsigned char crc, unsigned short bs);
int appendFile(int shift, int length, unsigned char *buf);
/*----------------------接口类及对象实例的基本数据类型组帧----------------------*/
extern int create_OAD(INT8U *data,OAD oad);
extern int create_array(INT8U *data,INT8U numm);
extern int create_struct(INT8U *data,INT8U numm);
extern int file_bool(INT8U *data,INT8U value);
extern int fill_bit_string8(INT8U *data,INT8U bits);
extern int fill_double_long_unsigned(INT8U *data,INT32U value);
extern int fill_octet_string(INT8U *data,char *value,INT8U len);
extern int fill_visible_string(INT8U *data,char *value,INT8U len);
extern int fill_integer(INT8U *data,INT8U value);
extern int fill_unsigned(INT8U *data,INT8U value);
extern int fill_long_unsigned(INT8U *data,INT16U value);
extern int fill_enum(INT8U *data,INT8U value);
extern int fill_time(INT8U *data,INT8U *value);
extern int fill_date_time_s(INT8U *data,DateTimeBCD *time);
extern int fill_TI(INT8U *data,TI ti);
extern int fill_TSA(INT8U *data,INT8U *value,INT8U len);
/*----------------------接口类及对象实例的数据类型解析----------------------*/
extern int getArray(INT8U *source,INT8U *dest);	//1
extern int getStructure(INT8U *source,INT8U *dest);	//2
extern int getBool(INT8U *source,INT8U *dest);		//3
extern int getUnsigned(INT8U *source,INT8U *dest);	//0x11
extern int getLongUnsigned(INT8U *source,INT8U *dest);//0x12
extern int getDateTimeS(INT8U type,INT8U *source,INT8U *dest);//0x1C
extern int getOAD(INT8U type,INT8U *source,OAD *oad);		//0x51
extern int getROAD(INT8U *source,ROAD *dest);		//0x52
extern int getTI(INT8U type,INT8U *source,TI *ti);		//0x54
extern int get_BasicRSD(INT8U *source,INT8U *dest,INT8U *type);	//0x5A
extern int getMS(INT8U *source,INT8U *dest);		//0x5C
extern int get_BasicRCSD(INT8U *source,CSD_ARRAYTYPE *csds);	//0x60

#endif
