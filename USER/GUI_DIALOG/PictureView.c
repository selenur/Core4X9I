/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.22                          *
*        Compiled Jul  4 2013, 15:16:01                              *
*        (c) 2013 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"
#include "header.h"
#include <string.h>

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/


#define ID_BUTTON_PREV (GUI_ID_USER + 0x02)
#define ID_BUTTON_NEXT (GUI_ID_USER + 0x03)
#define ID_BUTTON_EXIT (GUI_ID_USER + 0x04)
// USER START (Optionally insert additional defines)
#define RAD 1
int Time_1;
extern volatile int Time;
GUI_MEMDEV_Handle hMem;

extern ICONVIEW_Handle hALARMA,hALARMB,hIcon_EXIT,hIcon_BRIGHT;
 
extern RTC_DateTypeDef			RTC_Date;
extern GUI_CONST_STORAGE GUI_BITMAP bmhourglass;
void _drawJPG(char *Path,char *fn);
void _drawBMP(char *Path,char *fn);
void _drawGIF(char *Path,char *fn);
//WM_HWIN hWin_Photo;
BUTTON_Handle hButton_NEXT,hButton_PREV,hButton_EXIT;
static unsigned char _acBuffer[4096];//__attribute((at(SDRAM_BASE)));

GUI_GIF_IMAGE_INFO 	gif_i_info;
GUI_GIF_INFO				gif_info;
GUI_JPEG_INFO 			jpg_info;
FIL pFile;
int file_index,file_count;
void Draw_EXIT(int x,int y){
			
			GUI_POINT pPoint[12];
	
			GUI_SetPenSize(3);
			pPoint[0].x=0;
			pPoint[0].y=5;
			pPoint[1].x=5;
			pPoint[1].y=0;
			pPoint[2].x=10;
			pPoint[2].y=5;
			pPoint[3].x=15;
			pPoint[3].y=0;
			pPoint[4].x=20;
			pPoint[4].y=5;
			pPoint[5].x=15;
			pPoint[5].y=10;
			pPoint[6].x=20;
			pPoint[6].y=15;
			pPoint[7].x=15;
			pPoint[7].y=20;
			pPoint[8].x=10;
			pPoint[8].y=15;
			pPoint[9].x=5;
			pPoint[9].y=20;
			pPoint[10].x=0;
			pPoint[10].y=15;
			pPoint[11].x=5;
			pPoint[11].y=10;
			GUI_SetColor(GUI_WHITE);
			GUI_FillPolygon(pPoint,12,x,y);
}
int _cbButtonEXIT(const WIDGET_ITEM_DRAW_INFO *pDrawItemInfo){
	
	GUI_RECT Rect;
	switch(pDrawItemInfo->Cmd){
		case WIDGET_ITEM_DRAW_BACKGROUND:
			GUI_SetPenSize(3);
			Rect.x0=pDrawItemInfo->x0;
			Rect.x1=pDrawItemInfo->x1;
			Rect.y0=pDrawItemInfo->y0;
			Rect.y1=pDrawItemInfo->y1;
			GUI_SetColor(GUI_LIGHTGRAY);
			//GUI_AA_SetFactor(3);
			GUI_AA_FillRoundedRectEx(&Rect,10);
			Draw_EXIT((Rect.x1-Rect.x0+1)/6,(Rect.y1-Rect.y0+1)/6);

		break;
		default:
			return BUTTON_DrawSkinFlex(pDrawItemInfo);
		}
	return 0;
}
void Draw_PREV(int x,int y,int size){
			
			GUI_POINT pPoint[6];
	
			GUI_SetPenSize(3);
			pPoint[0].x=size+5;
			pPoint[0].y=0;
			pPoint[1].x=size;
			pPoint[1].y=0;
			pPoint[2].x=0;
			pPoint[2].y=size*3;
			pPoint[3].x=size;
			pPoint[3].y=size*6;
			pPoint[4].x=size+5;
			pPoint[4].y=size*6;
			pPoint[5].x=5;
			pPoint[5].y=size*3;
			GUI_SetColor(GUI_WHITE);
			GUI_FillPolygon(pPoint,6,x,y);
}

static int _cbButtonPREV(const WIDGET_ITEM_DRAW_INFO *pDrawItemInfo){
	
	GUI_RECT Rect;
	switch(pDrawItemInfo->Cmd){
		case WIDGET_ITEM_DRAW_BACKGROUND:
			GUI_SetPenSize(3);
			Rect.x0=pDrawItemInfo->x0;
			Rect.x1=pDrawItemInfo->x1;
			Rect.y0=pDrawItemInfo->y0;
			Rect.y1=pDrawItemInfo->y1;
			
			GUI_SetColor(GUI_LIGHTGRAY);
			GUI_FillRoundedRect(Rect.x0, Rect.y0, Rect.x1, Rect.y1, RAD);
			Draw_PREV((Rect.x1-Rect.x0+1)/3,(Rect.y1-Rect.y0+1)/8,(Rect.x1-Rect.x0+1)/3);

		break;
		default:
			return BUTTON_DrawSkinFlex(pDrawItemInfo);
		}
	return 0;
}
void Draw_NEXT(int x,int y,int size){
			
			GUI_POINT pPoint[6];
	
			GUI_SetPenSize(3);
			pPoint[0].x=0;
			pPoint[0].y=0;
			pPoint[1].x=5;
			pPoint[1].y=0;
			pPoint[2].x=size+5;
			pPoint[2].y=size*3;
			pPoint[3].x=5;
			pPoint[3].y=size*6;
			pPoint[4].x=0;
			pPoint[4].y=size*6;
			pPoint[5].x=size;
			pPoint[5].y=size*3;
			GUI_SetColor(GUI_WHITE);
			GUI_FillPolygon(pPoint,6,x,y);
}

static int _cbButtonNEXT(const WIDGET_ITEM_DRAW_INFO *pDrawItemInfo){
	

	
	GUI_RECT Rect;
	switch(pDrawItemInfo->Cmd){
		case WIDGET_ITEM_DRAW_BACKGROUND:
			GUI_SetPenSize(3);
			Rect.x0=pDrawItemInfo->x0;
			Rect.x1=pDrawItemInfo->x1;
			Rect.y0=pDrawItemInfo->y0;
			Rect.y1=pDrawItemInfo->y1;
			GUI_SetColor(GUI_LIGHTGRAY);
			GUI_FillRoundedRect(Rect.x0, Rect.y0, Rect.x1, Rect.y1, RAD);
			Draw_NEXT((Rect.x1-Rect.x0+1)/6,(Rect.y1-Rect.y0+1)/8,(Rect.x1-Rect.x0+1)/3);

		break;
		default:
			return BUTTON_DrawSkinFlex(pDrawItemInfo);
		}
	return 0;
}



int _GetData(void *p,const U8 **ppData,unsigned NumBytesReq,U32 Off){
	uint32_t NumBytesRead;
	FIL *phFile;
	phFile=(FIL*)p;

// Check buffer size	
	if(NumBytesReq>sizeof(_acBuffer))
		NumBytesReq=sizeof(_acBuffer);

// Set file pointer to the offset location
	f_lseek (phFile, Off);

// Read data into buffer
	fresult=f_read(phFile,_acBuffer,NumBytesReq,&NumBytesRead);

	// Set data pointer to the beginning of the buffer
  *ppData = _acBuffer;	
	return 	NumBytesRead;
}
void _drawGIF(char *Path,char *fn){
	uint8_t m=1;
	int xNum,yNum,Num,xSize,ySize,xPos,yPos,i,j;
	uint32_t NumBytesRead;	
	
	fresult=f_open (&pFile, Path, FA_READ);	// open file
	fresult=f_read(&pFile,(uint32_t*)(SDRAM_BASE+0x200000), pFile.fsize,&NumBytesRead);
	
	GUI_DrawBitmap(&bmhourglass, 225, 120);
	
	GUI_GIF_GetInfo((uint32_t*)(SDRAM_BASE+0x200000),pFile.fsize,&gif_info);
	NVIC_DisableIRQ(TIM6_DAC_IRQn);
	NVIC_DisableIRQ(CAN1_RX0_IRQn);
	NVIC_DisableIRQ(CAN1_RX1_IRQn);	
	
	if((gif_info.xSize<=480)&&(gif_info.ySize<=272))
		{
			xPos=(480-gif_info.xSize)/2;
			yPos=(272-gif_info.ySize)/2;
			
			hMem=hMem=GUI_MEMDEV_Create(xPos, yPos, gif_info.xSize+2, gif_info.ySize+2);
			GUI_MEMDEV_Select(hMem);
			
			if((1<gif_info.NumImages)&&(gif_info.NumImages<25))
				m=3;
			for(j=0;j<m;j++)
				{
					Time=0;
					GUI_GIF_DrawSub((uint32_t*)(SDRAM_BASE+0x200000),pFile.fsize,xPos,yPos,0);
					GUI_MEMDEV_MarkDirty(hMem,225,120,275,168);
					GUI_MEMDEV_CopyToLCD(hMem);
					Time_1=Time;
					for(i=1;i<gif_info.NumImages;i++)
						{
						GUI_MEMDEV_Clear(hMem);
						GUI_GIF_DrawSub((uint32_t*)(SDRAM_BASE+0x200000),pFile.fsize,xPos,yPos,i);
						GUI_MEMDEV_CopyToLCD(hMem);
						GUI_GIF_GetImageInfo((uint32_t*)(SDRAM_BASE+0x200000), pFile.fsize, &gif_i_info, i);
						GUI_Delay(gif_i_info.Delay);
						}	
				}	
		}
	else	
		{
			xNum=480000/gif_info.xSize;
			yNum=272000/gif_info.ySize;
			if(xNum<yNum)
				Num=xNum;
			else
				Num=yNum;
			xSize=gif_info.xSize*Num/1000;
			ySize=gif_info.ySize*Num/1000;
			xPos=(480-xSize)/2;
			yPos=(272-ySize)/2;
			hMem=GUI_MEMDEV_Create(xPos, yPos, xSize+2, ySize+2);
			GUI_MEMDEV_Select(hMem);
			if((1<gif_info.NumImages)&&(gif_info.NumImages<25))
				m=3;
			for(j=0;j<m;j++)
			 {
				Time=0;
				GUI_GIF_DrawSubScaled((uint32_t*)(SDRAM_BASE+0x200000),pFile.fsize,xPos,yPos,0,Num,1000);
				GUI_MEMDEV_MarkDirty(hMem,225,120,275,168);
				GUI_MEMDEV_CopyToLCD(hMem);
				Time_1=Time; 
				for(i=1;i<gif_info.NumImages;i++)
					{
					GUI_MEMDEV_Clear(hMem);
					GUI_GIF_DrawSubScaled((uint32_t*)(SDRAM_BASE+0x200000),pFile.fsize,xPos,yPos,i,Num,1000);
					GUI_MEMDEV_CopyToLCD(hMem);
					GUI_GIF_GetImageInfo((uint32_t*)(SDRAM_BASE+0x200000), pFile.fsize, &gif_i_info, i);
					GUI_Delay(gif_i_info.Delay);
					}
			 }				
		}
	GUI_MEMDEV_Delete(hMem);
	NVIC_EnableIRQ(TIM6_DAC_IRQn);
	NVIC_EnableIRQ(CAN1_RX0_IRQn);
	NVIC_EnableIRQ(CAN1_RX1_IRQn);		
	GUI_SetAlpha(0x80);
	GUI_SetColor(GUI_RED);
	GUI_DispStringAt("File : ",0,257);
	GUI_DispString(fn);	
	GUI_DispChars(' ',2);
	GUI_DispDecMin(gif_info.xSize);
	GUI_DispString(" x ");
	GUI_DispDecMin(gif_info.ySize);
	GUI_DispStringAt("Time decomress (ms): ",40,0);
	GUI_DispDecMin(Time_1);
	GUI_DispString("    File size (KB): ");
	GUI_DispDecMin(pFile.fsize/1024);
	f_close (&pFile);		
}

void _drawBMP(char *Path,char *fn){
	int xNum,yNum,xSize,ySize,xPos,yPos,Num,x,y;
	uint32_t NumBytesRead;
	fresult=f_open (&pFile, Path, FA_READ);	// open file
	fresult=f_read(&pFile,(uint32_t*)0x90200000, pFile.fsize,&NumBytesRead);
	//xSize=GUI_BMP_GetXSizeEx(_GetData,&pFile);
	//ySize=GUI_BMP_GetYSizeEx(_GetData,&pFile);
	
	GUI_DrawBitmap(&bmhourglass, 225, 120);
	NVIC_DisableIRQ(TIM6_DAC_IRQn);
	NVIC_DisableIRQ(CAN1_RX0_IRQn);
	NVIC_DisableIRQ(CAN1_RX1_IRQn);	
	xSize=GUI_BMP_GetXSize((uint32_t*)0x90200000);
	ySize=GUI_BMP_GetYSize((uint32_t*)0x90200000);
	if((xSize<=480)&&(ySize<=272))
		{
			xPos=(480-xSize)/2;
			yPos=(272-ySize)/2;
			hMem=GUI_MEMDEV_Create(xPos, yPos, xSize, ySize);
			GUI_MEMDEV_Select(hMem);
			//GUI_BMP_DrawEx(_GetData,&pFile,xPos,yPos);
			//GUI_PNG_Draw((uint32_t*)0x90200000,pFile.fsize,xPos,yPos);
			Time=0;
			GUI_BMP_Draw((uint32_t*)0x90200000,xPos,yPos);
			GUI_MEMDEV_MarkDirty(hMem,225,120,275,168);
			GUI_MEMDEV_CopyToLCD(hMem);
			Time_1=Time;
		}
	else
		{	
			xNum=480000/xSize;
			yNum=272000/ySize;
			if(xNum<yNum)
				Num=xNum;
			else
				Num=yNum;
			x=xSize*Num/1000;
			y=ySize*Num/1000;
			xPos=(480-x)/2;
			yPos=(272-y)/2;
			//GUI_BMP_DrawScaledEx(_GetData,&pFile,xPos,yPos,Num,1000);
			hMem=GUI_MEMDEV_Create(xPos, yPos, x, y);
			GUI_MEMDEV_Select(hMem);
			Time=0;
			GUI_BMP_DrawScaled((uint32_t*)0x90200000,xPos,yPos,Num,1000);
			GUI_MEMDEV_MarkDirty(hMem,225,120,275,168);
			GUI_MEMDEV_CopyToLCD(hMem);
			Time_1=Time;
		}
	GUI_MEMDEV_Delete(hMem);
	NVIC_EnableIRQ(TIM6_DAC_IRQn);	
	NVIC_EnableIRQ(CAN1_RX0_IRQn);
	NVIC_EnableIRQ(CAN1_RX1_IRQn);	
		
	GUI_SetAlpha(0x80);
	GUI_SetColor(GUI_RED);
	GUI_DispStringAt("File : ",0,257);
	GUI_DispString(fn);	
	GUI_DispChars(' ',2);
	GUI_DispDecMin(xSize);
	GUI_DispString(" x ");
	GUI_DispDecMin(ySize);
	GUI_DispStringAt("Time decomress (ms): ",40,0);
	GUI_DispDecMin(Time_1);
	GUI_DispString("    File size (KB): ");
	GUI_DispDecMin(pFile.fsize/1024);
	f_close (&pFile);	

}

void _drawJPG(char *Path,char *fn){
		int xNum,yNum,xSize,ySize,xPos,yPos,Num;
		uint32_t NumBytesRead;
		
	fresult=f_open (&pFile, Path, FA_READ);	// open file
	fresult=f_read(&pFile,(uint32_t*)0x90200000, pFile.fsize,&NumBytesRead);
	
	GUI_DrawBitmap(&bmhourglass, 225, 120);
	
	NVIC_DisableIRQ(TIM6_DAC_IRQn);
	NVIC_DisableIRQ(CAN1_RX0_IRQn);
	NVIC_DisableIRQ(CAN1_RX1_IRQn);	
	
	GUI_JPEG_GetInfo((uint32_t*)0x90200000, pFile.fsize, &jpg_info);			
	if((jpg_info.XSize<=480)&&(jpg_info.YSize<=272))
		{
			xPos=(480-jpg_info.XSize)/2;
			yPos=(272-jpg_info.YSize)/2;
			hMem=GUI_MEMDEV_Create(xPos, yPos, jpg_info.XSize, jpg_info.YSize);
			GUI_MEMDEV_Select(hMem);
			Time=0;
			GUI_JPEG_Draw((uint32_t*)0x90200000, pFile.fsize,xPos, yPos);
			GUI_MEMDEV_MarkDirty(hMem,225,120,275,168);
			GUI_MEMDEV_CopyToLCD(hMem);
			Time_1=Time;
		}
	else
		{
		//GUI_JPEG_GetInfoEx(_GetData, &pFile, &Info);
		xNum=480000/jpg_info.XSize;
		yNum=272000/jpg_info.YSize;
		if(xNum<yNum)
			Num=xNum;
		else
			Num=yNum;
		xSize=jpg_info.XSize*Num/1000;
		ySize=jpg_info.YSize*Num/1000;
		xPos=(480-xSize)/2;
		yPos=(272-ySize)/2;
	 //GUI_JPEG_DrawScaledEx(_GetData, &pFile,xPos, yPos,Num,1000);
		hMem=GUI_MEMDEV_Create(xPos, yPos, xSize, ySize);
		GUI_MEMDEV_Select(hMem);
		Time=0;
		GUI_JPEG_DrawScaled((uint32_t*)0x90200000, pFile.fsize,xPos, yPos, Num, 1000);
		GUI_MEMDEV_MarkDirty(hMem,225,120,275,168);
		GUI_MEMDEV_CopyToLCD(hMem);
		Time_1=Time;
		}
	GUI_MEMDEV_Delete(hMem);
		
  NVIC_EnableIRQ(TIM6_DAC_IRQn);
	NVIC_EnableIRQ(CAN1_RX0_IRQn);
	NVIC_EnableIRQ(CAN1_RX1_IRQn);			
	
	GUI_SetAlpha(0x80);
	GUI_SetColor(GUI_RED);
	GUI_DispStringAt("File: ",0,257);
	GUI_DispString(fn);	
	GUI_DispChars(' ',2);
	GUI_DispDecMin(jpg_info.XSize);
	GUI_DispString(" x ");
	GUI_DispDecMin(jpg_info.YSize);
	GUI_DispStringAt("Time decomress (ms): ",40,0);
	GUI_DispDecMin(Time_1);
	GUI_DispString("    File size (KB): ");
	GUI_DispDecMin(pFile.fsize/1024);
	f_close (&pFile);	
							
	
}

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
static void _cbPhoto(WM_MESSAGE * pMsg) {
	 char *fn,*pPath;
//	int xNum,yNum,xSize,ySize,xPos,yPos,Num,x,y;
	int     NCode;
  int     Id;
	int i;
	
#if _USE_LFN
    static char lfn[_MAX_LFN + 1];   /* Buffer to store the LFN */
    finfo.lfname = lfn;
    finfo.lfsize = sizeof lfn;
#endif		
	switch (pMsg->MsgId) {
		case WM_TOUCH:
			WM_ShowWindow(hButton_NEXT);
			WM_ShowWindow(hButton_PREV);
			WM_ShowWindow(hButton_EXIT);
		break;
		case WM_NOTIFY_PARENT:
			Id    = WM_GetId(pMsg->hWinSrc);
			NCode = pMsg->Data.v;
			switch(Id) {
				case ID_BUTTON_PREV:
					switch(NCode){
						case WM_NOTIFICATION_RELEASED:
							fresult=f_opendir(&dir, "0:Photo"); 
							for(i=0;i<file_index-1;i++)
								fresult=f_readdir(&dir,&finfo); 
							file_index--;
							if(file_index==2)
								{
									for(i=0;i<file_count-2;i++)
										fresult=f_readdir(&dir,&finfo);
									file_index=file_count;
								}
#if _USE_LFN
			fn = *finfo.lfname ? finfo.lfname : finfo.fname;
#else
		 fn = finfo.fname;
#endif												
							pPath=strchr(Path,'/');
							*(++pPath)='\0';
							strcat(Path,fn);
							pPath=strchr(fn,'\0');
							pPath-=3;
							GUI_SetAlpha(0);	
							GUI_Clear();
							if((*pPath=='j')||(*pPath=='J'))	
								_drawJPG(Path,fn);
							else if((*pPath=='b')||(*pPath=='B'))
								_drawBMP(Path,fn);
							else if((*pPath=='g')||(*pPath=='G'))
								_drawGIF(Path,fn);
							
							WM_HideWindow(hButton_PREV);
							WM_HideWindow(hButton_EXIT);
							WM_HideWindow(hButton_NEXT);
						break;	
					}
				break;
				case ID_BUTTON_NEXT:
					switch(NCode){
						case WM_NOTIFICATION_RELEASED:
							for(;;)
								{
									fresult=f_readdir(&dir,&finfo); file_index++;
									if(finfo.fname[0]==0)		
									{
										fresult=f_opendir(&dir, "0:Photo"); file_index=0;
										continue;
									}
									if((fresult!=FR_OK)||(finfo.fname[0]!='.'))
										break;
									if(finfo.fname[0]=='.')
										continue;
								}
#if _USE_LFN
			fn = *finfo.lfname ? finfo.lfname : finfo.fname;
#else
		 fn = finfo.fname;
#endif												
							pPath=strchr(Path,'/');
							*(++pPath)='\0';
							strcat(Path,fn);
							pPath=strchr(fn,'\0');
							pPath-=3;;
							GUI_SetAlpha(0);	
							GUI_Clear();
							if((*pPath=='j')||(*pPath=='J'))	
								_drawJPG(Path,fn);
							else if((*pPath=='b')||(*pPath=='B'))
								_drawBMP(Path,fn);
							else if((*pPath=='g')||(*pPath=='G'))
								_drawGIF(Path,fn);
							WM_HideWindow(hButton_PREV);
							WM_HideWindow(hButton_EXIT);
							WM_HideWindow(hButton_NEXT);
							break;
					}
				break;
				case ID_BUTTON_EXIT:
					switch(NCode){
						case WM_NOTIFICATION_RELEASED:
							WM_DeleteWindow(hButton_NEXT);
							WM_DeleteWindow(hButton_PREV);
							WM_DeleteWindow(hButton_EXIT);
							GUI_SetAlpha(0);
							GUI_SetBkColor(GUI_LIGHTBLUE);
							GUI_ClearRect(1,17,58,270);
							GUI_SetColor(GUI_YELLOW);
							GUI_DrawRect(0,16,59,271);
							GUI_SetBkColor(GUI_DARKBLUE);
							GUI_ClearRect(0,0,470,15);
							
							RTC_GetDate(RTC_Format_BIN, &RTC_Date);
							GUI_DispDecAt(RTC_Date.RTC_Date,5,0,2);
							GUI_DispString(".");
							GUI_DispDec(RTC_Date.RTC_Month,2);
							GUI_DispString(".20");
							GUI_DispDec(RTC_Date.RTC_Year,2);
							
							WM_ShowWindow(PROGBAR_MEM);
							WM_ShowWindow(hIcon_EXIT);
							WM_ShowWindow(hIcon_BRIGHT);
							WM_ShowWindow(hALARMA);
							WM_ShowWindow(hALARMB);
							
							time_show=1;
							CreateStart();
						
						break;	
					}
				break;		
			}
		break;
		default:
		WM_DefaultProc(pMsg);
		break;		
	}		
}

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

void PictureView(void) {
char *fn,*pPath;
	file_index=0;file_count=0;
	GUI_SetBkColor(GUI_BLACK);
	GUI_Clear();
	for(;;)
			{
				fresult=f_readdir(&dir,&finfo);   /* Count of file in directory Photo */
				if(finfo.fname[0]==0)
					break;
				file_count++;
			}
/* Next entry directory Photo */
		fresult=f_opendir(&dir, Path);
		for(;;)
			{
			fresult=f_readdir(&dir,&finfo); file_index++;   
			if((fresult!=FR_OK)||(finfo.fname[0]!='.'))
					break;
			if(finfo.fname[0]=='.')
				continue;
				
			}
#if _USE_LFN
      fn = *finfo.lfname ? finfo.lfname : finfo.fname;
#else
     fn = finfo.fname;
#endif												
			strcat(Path,"/");
			strcat(Path,fn);
			pPath=strchr(fn,'\0');
			pPath-=3;	
			if((*pPath=='j')||(*pPath=='J'))	
				_drawJPG(Path,fn);
			else if((*pPath=='b')||(*pPath=='B'))
				_drawBMP(Path,fn);
			else if((*pPath=='p')||(*pPath=='P'))
				_drawGIF(Path,fn);
			
			hButton_NEXT=BUTTON_CreateEx(445,90,30,80,WM_HBKWIN,/*WM_CF_SHOW|*/WM_CF_HASTRANS,0,ID_BUTTON_NEXT);
			BUTTON_SetSkin(hButton_NEXT, _cbButtonNEXT);
					
			hButton_PREV=BUTTON_CreateEx(5,90,30,80,WM_HBKWIN,/*WM_CF_SHOW|*/WM_CF_HASTRANS,0,ID_BUTTON_PREV);
			BUTTON_SetSkin(hButton_PREV, _cbButtonPREV);
				
			hButton_EXIT=BUTTON_CreateEx(5,5,30,30,WM_HBKWIN,/*WM_CF_SHOW|*/WM_CF_HASTRANS,0,ID_BUTTON_EXIT);
			BUTTON_SetSkin(hButton_EXIT, _cbButtonEXIT);
			WM_SetCallback(WM_HBKWIN, _cbPhoto);
			
}

// USER END

/*************************** End of file ****************************/
