#pragma once

#include "VDDevelopKitDefs.h"

#ifdef __cplusplus
extern "C" {
#endif

	// Common function
	UINT VDDevelopKit_C_Initialize(LPCWSTR cpModuleDir, LPCWSTR cpLangXmlFilePath = NULL, LPCWSTR cpTempDir = NULL);
	void VDDevelopKit_C_UnInitialize();
	UINT VDDevelopKit_C_RefreshLanguage(LPCWSTR cpLangXmlFilePath);
	UINT VDDevelopKit_C_RefreshAllModels();
	UINT VDDevelopKit_C_GetTrialLimit(int *ipTrialLimit);
	UINT VDDevelopKit_C_SetLoggerType(int iLoggerType);
	UINT VDDevelopKit_C_SetUseSoftKB(BOOL bUseSoftKB);
	UINT VDDevelopKit_C_SetProjectPassword(LPCWSTR cpPassword);
	UINT VDDevelopKit_C_GetLastError();

	// License key
	BOOL VDDevelopKit_C_IsExistKey();
	BOOL VDDevelopKit_C_CheckLicenseValid(UINT nModuleBit);
	UINT VDDevelopKit_C_GetLicenseKeyUniqueID();
	UINT VDDevelopKit_C_GetLicenseKeyCustomerDataLen();
	UINT VDDevelopKit_C_ReadLicenseKeyCustomerData(UCHAR *ucpData, UINT nDataLen);
	UINT VDDevelopKit_C_WriteLicenseKeyCustomerData(const UCHAR *ucpData, UINT nDataLen);

	// Advanced function
	// 1. Setting
	HANDLE VDDevelopKit_C_FlowUnit_Create(UINT nImageUnitNum = 1, BOOL bIncludingVImageUnit = FALSE);
	HANDLE VDDevelopKit_C_FlowUnit_CreateEx(UINT n2DImageUnitNum = 1, UINT nDepthImageUnitNum = 0, UINT n3DImageUnitNum = 0, UINT nVirtualImageUnitNum = 0);
	void VDDevelopKit_C_FlowUnit_Destroy(HANDLE hFlowUnit);
	UINT VDDevelopKit_C_FlowUnit_Copy(HANDLE hFlowUnitSrc, HANDLE hFlowUnitDst);
	BOOL VDDevelopKit_C_FlowUnit_Compare(HANDLE hFlowUnit1, HANDLE hFlowUnit2);
	UINT VDDevelopKit_C_FlowUnit_Load(HANDLE hFlowUnit, LPCWSTR cpFilePath);
	UINT VDDevelopKit_C_FlowUnit_Save(HANDLE hFlowUnit, LPCWSTR cpFilePath);
	UINT VDDevelopKit_C_FlowUnit_SetName(HANDLE hFlowUnit, LPCWSTR cpFlowUnitName);
	UINT VDDevelopKit_C_FlowUnit_PosCalib_PointMap_ClearPointPair(HANDLE hFlowUnit, int iImageUnitIndex);
	UINT VDDevelopKit_C_FlowUnit_PosCalib_PointMap_AddPointPair(HANDLE hFlowUnit, int iImageUnitIndex, double dMarkerX, double dMarkerY, double dModelX, double dModelY);
	UINT VDDevelopKit_C_FlowUnit_PosCalib_PointMap_Calibration(HANDLE hFlowUnit, int iImageUnitIndex);
	UINT VDDevelopKit_C_FlowUnit_PosCalib_ConvertPoint(HANDLE hFlowUnit, int iImageUnitIndex, double dPointSrcX, double dPointSrcY, double *dpPointDstX, double *dpPointDstY);
	double VDDevelopKit_C_FlowUnit_PosCalib_GetRMS(HANDLE hFlowUnit, int iImageUnitIndex);
	UINT VDDevelopKit_C_FlowUnit_PosCalib_Calibration(HANDLE hFlowUnit, int iImageUnitIndex, BOOL bReplaceImageWhenSuccess, HANDLE hImage);
	UINT VDDevelopKit_C_FlowUnit_ScaleCalib_Calibration(HANDLE hFlowUnit, int iImageUnitIndex, BOOL bReplaceImageWhenSuccess, HANDLE hImage);
	UINT VDDevelopKit_C_FlowUnit_DisplayOverlay_SetShowOption(HANDLE hFlowUnit, int iImageUnitIndex, BOOL bShowNormalStatInfo, BOOL bShowStatusRect);
	UINT VDDevelopKit_C_FlowUnit_GetImageUnitCount(HANDLE hFlowUnit);
	UINT VDDevelopKit_C_FlowUnit_SetImageUnitName(HANDLE hFlowUnit, int iImageUnitIndex, LPCWSTR cpImageUnitName);
	int VDDevelopKit_C_FlowUnit_GetCameraIndex(HANDLE hFlowUnit, int iImageUnitIndex);
	UINT VDDevelopKit_C_FlowUnit_SetCameraIndex(HANDLE hFlowUnit, int iImageUnitIndex, int iCameraIndex);
	UINT VDDevelopKit_C_FlowUnit_GetImageUnitRefImage(HANDLE hFlowUnit, int iImageUnitIndex, HANDLE hImage);
	UINT VDDevelopKit_C_FlowUnit_SetImageUnitRefImage(HANDLE hFlowUnit, int iImageUnitIndex, HANDLE hImage);
	UINT VDDevelopKit_C_FlowUnit_GetGrabParam(HANDLE hFlowUnit, int iImageUnitIndex, double *dpExposureTime, double *dpGain);
	UINT VDDevelopKit_C_FlowUnit_SetGrabParam(HANDLE hFlowUnit, int iImageUnitIndex, double dExposureTime, double dGain);
	BOOL VDDevelopKit_C_FlowUnit_IsPreprocValid(HANDLE hFlowUnit, int iImageUnitIndex);
	UINT VDDevelopKit_C_FlowUnit_GetModuleCount(HANDLE hFlowUnit, int iImageUnitIndex);
	BOOL VDDevelopKit_C_FlowUnit_IsDefinedCustomModuleOutput(HANDLE hFlowUnit, int iImageUnitIndex, int iModuleIndex);
	UINT VDDevelopKit_C_FlowUnit_SetModuleValid(HANDLE hFlowUnit, int iImageUnitIndex, int iModuleIndex, int iSubModuleIndex, int iSSubModuleIndex, BOOL bValid);
	UINT VDDevelopKit_C_FlowUnit_SettingWindow_SetDirTestCallback(VDDirTestCallback pDirTestCallback, HANDLE hContext = NULL);
	INT_PTR VDDevelopKit_C_FlowUnit_ShowSettingWindow(HANDLE hFlowUnit, UINT nImageCount, HANDLE *vpImages, BOOL bMaxWindow = FALSE, VDGrabImageCallback pGrabImageCallback = NULL, HANDLE hContext = NULL);
	INT_PTR VDDevelopKit_C_FlowUnit_ShowSettingWindowDepth(HANDLE hFlowUnit, UINT nImageCount, HANDLE *vpImages, HANDLE *vpImageDepths, BOOL bMaxWindow = FALSE, VDGrabImageCallback pGrabImageCallback = NULL, HANDLE hContext = NULL);
	// 2. Run
	UINT VDDevelopKit_C_FlowUnit_SetProductID(HANDLE hFlowUnit, LPCWSTR cpProductID);
	UINT VDDevelopKit_C_FlowUnit_SetCmdIntValue(HANDLE hFlowUnit, int iIndex, int iValue);
	UINT VDDevelopKit_C_FlowUnit_SetCmdDoubleValue(HANDLE hFlowUnit, int iIndex, double dValue);
	UINT VDDevelopKit_C_FlowUnit_SetCmdStringValue(HANDLE hFlowUnit, int iIndex, LPCWSTR cpValue);
	UINT VDDevelopKit_C_FlowUnit_EmptyStatistics(HANDLE hFlowUnit);
	UINT VDDevelopKit_C_FlowUnit_Clear(HANDLE hFlowUnit);
	UINT VDDevelopKit_C_FlowUnit_PreprocImage(HANDLE hFlowUnit, int iImageUnitIndex, HANDLE hImage, HANDLE hImagePreproc);
	UINT VDDevelopKit_C_FlowUnit_Process(HANDLE hFlowUnit, int iImageUnitIndex, HANDLE hImage);
	UINT VDDevelopKit_C_FlowUnit_Process_PreprocImage(HANDLE hFlowUnit, int iImageUnitIndex, HANDLE hImage, HANDLE hImagePreproc);
	UINT VDDevelopKit_C_FlowUnit_ProcessDepth(HANDLE hFlowUnit, int iImageUnitIndex, HANDLE hImage, HANDLE hImageDepth);
	UINT VDDevelopKit_C_FlowUnit_Process_PreprocImageDepth(HANDLE hFlowUnit, int iImageUnitIndex, HANDLE hImage, HANDLE hImageDepth, HANDLE hImagePreproc);
	UINT VDDevelopKit_C_FlowUnit_Process3D(HANDLE hFlowUnit, int iImageUnitIndex, HANDLE hImage3D);
	// 3. Result
	UINT VDDevelopKit_C_FlowUnit_InitDispParam(HANDLE hFlowUnit, int iImageUnitIndex, HANDLE hVDWnd);
	UINT VDDevelopKit_C_FlowUnit_InitDispParam3D(HANDLE hFlowUnit, int iImageUnitIndex, HANDLE hVDWnd3D);
	UINT VDDevelopKit_C_FlowUnit_Display(HANDLE hFlowUnit, int iImageUnitIndex, HANDLE hVDWnd);
	UINT VDDevelopKit_C_FlowUnit_Display3D(HANDLE hFlowUnit, int iImageUnitIndex, HANDLE hVDWnd3D);
	BOOL VDDevelopKit_C_FlowUnit_GetStatus(HANDLE hFlowUnit, int iImageUnitIndex);
	UINT VDDevelopKit_C_FlowUnit_GetResultCount(HANDLE hFlowUnit);
	UINT VDDevelopKit_C_FlowUnit_GetResultItem(HANDLE hFlowUnit, int iResultIndex, LPWSTR cpValue, int *ipValueSize, LPWSTR cpValueName, int *ipValueNameSize);
	UINT VDDevelopKit_C_FlowUnit_GetResultItemInfo(HANDLE hFlowUnit, int iResultIndex, LPWSTR cpItemDesc, int *ipItemDescSize);
	UINT VDDevelopKit_C_FlowUnit_GetStatistics(HANDLE hFlowUnit, int iImageUnitIndex, UINT *npTotal, UINT *npOKCount);
	UINT VDDevelopKit_C_FlowUnit_CustomModule_GetCellCount(HANDLE hFlowUnit, int iImageUnitIndex, int iModuleIndex);
	UINT VDDevelopKit_C_FlowUnit_CustomModule_Cell_GetResultCount(HANDLE hFlowUnit, int iImageUnitIndex, int iModuleIndex, int iCellIndex);
	UINT VDDevelopKit_C_FlowUnit_CustomModule_Cell_GetResultItem(HANDLE hFlowUnit, int iImageUnitIndex, int iModuleIndex, int iCellIndex, int iResultIndex, LPWSTR cpValue, int *ipValueSize, LPWSTR cpValueName, int *ipValueNameSize);
	UINT VDDevelopKit_C_FlowUnit_GetDefectCount(HANDLE hFlowUnit, int iImageUnitIndex);
	UINT VDDevelopKit_C_FlowUnit_GetDefectItem(HANDLE hFlowUnit, int iImageUnitIndex, int iDefectIndex, VDDKITDefect_T *tpDefect);
	UINT VDDevelopKit_C_FlowUnit_GetModuleInfoCount(HANDLE hFlowUnit, int iImageUnitIndex);
	UINT VDDevelopKit_C_FlowUnit_GetModuleInfoItem(HANDLE hFlowUnit, int iImageUnitIndex, int iModuleInfoIndex, LPWSTR cpModuleName, int *ipModuleNameSize, int *ipModuleCode, int *ipMStatus, LPWSTR cpResultDesc, int *ipResultDescSize, VDDKITPoint_T *tpRegionPoints, int *ipRegionPointsSize);
	UINT VDDevelopKit_C_FlowUnit_GetCoord(HANDLE hFlowUnit, int iImageUnitIndex, int iModuleIndex, double *dpOriginX, double *dpOriginY, double *dpAngle);
	UINT VDDevelopKit_C_FlowUnit_GetCommData(HANDLE hFlowUnit, UCHAR *ucpData, int *ipDataLen, LPWSTR cpDataDesc, int *ipDataDescSize);
	UINT VDDevelopKit_C_FlowUnit_LoadStatInfo(HANDLE hFlowUnit, LPCWSTR cpFilePath);
	UINT VDDevelopKit_C_FlowUnit_SaveStatInfo(HANDLE hFlowUnit, LPCWSTR cpFilePath);

	// Image function
	HANDLE VDDevelopKit_C_Image_Create(UINT nWidth = 640, UINT nHeight = 480, int iImageType = VDDKIT_IMAGETYPE_UC8);
	HANDLE VDDevelopKit_C_Image_CreateEx(UINT nWidth, UINT nHeight, int iImageType, UCHAR *ucpData, BOOL bRefPointer = TRUE);
	void VDDevelopKit_C_Image_Destroy(HANDLE hImage);
	UINT VDDevelopKit_C_Image_Copy(HANDLE hImageSrc, HANDLE hImageDst);
	UINT VDDevelopKit_C_Image_Cut(HANDLE hImageSrc, int iPosXs, int iPosYs, int iPosXe, int iPosYe, HANDLE hImageDst);
	UINT VDDevelopKit_C_Image_GetSize(HANDLE hImage, UINT *npWidth, UINT *npHeight, int *ipImageType);
	UINT VDDevelopKit_C_Image_SetSize(HANDLE hImage, UINT nWidth, UINT nHeight, int iImageType);
	UCHAR * VDDevelopKit_C_Image_GetBuffer(HANDLE hImage, UINT nXOffset = 0, UINT nYOffset = 0);
	UINT VDDevelopKit_C_Image_GetDataSize(HANDLE hImage);
	UINT VDDevelopKit_C_Image_CopyData(HANDLE hImage, UCHAR *ucpData);
	UINT VDDevelopKit_C_Image_CopyData3D(HANDLE hImage, UINT nYOffset, const void *vpData3D, UINT nData3DHeight, int iData3DType, float fData3DNan);
	UINT VDDevelopKit_C_Image_ConvertBayerToRGB24(HANDLE hImageSrc, HANDLE hImageDst, int iColorType = VDDKIT_BAYERCOLORTYPE_RGGB, int iThreadNum = -1);
	UINT VDDevelopKit_C_Image_ComposeRGB32(HANDLE hImageR, HANDLE hImageG, HANDLE hImageB, HANDLE hImageA, HANDLE hImageDst);
	UINT VDDevelopKit_C_Image_CalcDefinition(HANDLE hImage, int iXs, int iYs, int iXe, int iYe, int iAnalyzeMode, double *dpDefinition);
	UINT VDDevelopKit_C_Image_Load(HANDLE hImage, LPCWSTR cpFilePath);
	UINT VDDevelopKit_C_Image_Save(HANDLE hImage, LPCWSTR cpFilePath, UINT nOption = 0);

	// Image3D function
	// Image3D - Map
	HANDLE VDDevelopKit_C_Image3D_MapCreate(UINT nWidth = 3200, UINT nHeight = 3000, int iImage3DType = VDDKIT_IMAGE3DTYPE_MAPZ);
	UINT VDDevelopKit_C_Image3D_MapGetSize(HANDLE hImage3D, UINT *npWidth, UINT *npHeight, int *ipImage3DType);
	UINT VDDevelopKit_C_Image3D_MapSetSize(HANDLE hImage3D, UINT nWidth, UINT nHeight, int iImage3DType);
	UINT VDDevelopKit_C_Image3D_MapGetInfo(HANDLE hImage3D, double dTransform[16]);
	UINT VDDevelopKit_C_Image3D_MapSetInfo(HANDLE hImage3D, const double dTransform[16]);
	void * VDDevelopKit_C_Image3D_MapGetBuffer(HANDLE hImage3D, UINT nXOffset = 0, UINT nYOffset = 0);
	UINT VDDevelopKit_C_Image3D_MapCopyData(HANDLE hImage3D, UINT nYOffset, const void *vpData3D, UINT nData3DHeight, int iData3DType, float fData3DNan, float fScaleZ);
	UINT VDDevelopKit_C_Image3D_MapRemoveInvalidPoint(HANDLE hImage3D);
	// Image3D - XYZ
	HANDLE VDDevelopKit_C_Image3D_XYZCreate(UINT nPointNum = 1555200, int iImage3DType = VDDKIT_IMAGE3DTYPE_XYZ);
	UINT VDDevelopKit_C_Image3D_XYZGetSize(HANDLE hImage3D, UINT *npPointNum, int *ipImage3DType);
	UINT VDDevelopKit_C_Image3D_XYZSetSize(HANDLE hImage3D, UINT nPointNum, int iImage3DType);
	void * VDDevelopKit_C_Image3D_XYZGetBuffer(HANDLE hImage3D, UINT nIndex = 0);
	UINT VDDevelopKit_C_Image3D_XYZCopyData(HANDLE hImage3D, const void *vpData3D);
	UINT VDDevelopKit_C_Image3D_XYZRemoveInvalidPoint(HANDLE hImage3D);
	// Image3D - Common
	BOOL VDDevelopKit_C_Image3D_IsMapImage(HANDLE hImage3D);
	void VDDevelopKit_C_Image3D_Destroy(HANDLE hImage3D);
	UINT VDDevelopKit_C_Image3D_Copy(HANDLE hImage3DSrc, HANDLE hImage3DDst);
	UINT VDDevelopKit_C_Image3D_Load(HANDLE hImage3D, LPCWSTR cpFilePath);
	UINT VDDevelopKit_C_Image3D_Save(HANDLE hImage3D, LPCWSTR cpFilePath, UINT nOption = 0);

	// Window function
	HANDLE VDDevelopKit_C_Wnd_Create(HWND hParentWnd);
	void VDDevelopKit_C_Wnd_Destory(HANDLE hVDWnd);
	HWND VDDevelopKit_C_Wnd_GetHwnd(HANDLE hVDWnd);
	UINT VDDevelopKit_C_Wnd_SyncParentWndSize(HANDLE hVDWnd);
	HANDLE VDDevelopKit_C_Wnd_GetImage(HANDLE hVDWnd);
	UINT VDDevelopKit_C_Wnd_SetImage(HANDLE hVDWnd, HANDLE hImage);
	UINT VDDevelopKit_C_Wnd_ClearOverlay(HANDLE hVDWnd);
	UINT VDDevelopKit_C_Wnd_DrawText(HANDLE hVDWnd, LPCWSTR cpText, int iPosX, int iPosY, BOOL bImageCoordinate, COLORREF clrText, UINT nTextAlign, int iFontHeight);
	UINT VDDevelopKit_C_Wnd_DrawRectangle(HANDLE hVDWnd, int iXs, int iYs, int iXe, int iYe, BOOL bImageCoordinate, COLORREF clrRect, UINT nLineWidth, BOOL bFill);
	UINT VDDevelopKit_C_Wnd_ShowCenterCross(HANDLE hVDWnd, BOOL bShowCenterCross);
	UINT VDDevelopKit_C_Wnd_Redraw(HANDLE hVDWnd, BOOL bFitSize = TRUE, double dMagnification = 1.0);
	UINT VDDevelopKit_C_Wnd_GetDisplayImage(HANDLE hVDWnd, HANDLE hImage, BOOL bWholeImage);
	UINT VDDevelopKit_C_Wnd_WndPointToImagePoint(HANDLE hVDWnd, int iWindowX, int iWindowY, double *dpImageX, double *dpImageY);

	// Window3D function
	HANDLE VDDevelopKit_C_Wnd3D_Create(HWND hParentWnd, BOOL bShowToolBar = FALSE);
	void VDDevelopKit_C_Wnd3D_Destory(HANDLE hVDWnd3D);
	HWND VDDevelopKit_C_Wnd3D_GetHwnd(HANDLE hVDWnd3D);
	UINT VDDevelopKit_C_Wnd3D_SyncParentWndSize(HANDLE hVDWnd3D);
	HANDLE VDDevelopKit_C_Wnd3D_GetImage(HANDLE hVDWnd3D);
	UINT VDDevelopKit_C_Wnd3D_SetImage(HANDLE hVDWnd3D, HANDLE hImage3D);
	UINT VDDevelopKit_C_Wnd3D_ClearOverlay(HANDLE hVDWnd3D);
	UINT VDDevelopKit_C_Wnd3D_DrawText(HANDLE hVDWnd3D, LPCWSTR cpText, int iPosX, int iPosY, COLORREF clrText, UINT nTextAlign, int iFontHeight);
	UINT VDDevelopKit_C_Wnd3D_DrawRectangle(HANDLE hVDWnd3D, int iXs, int iYs, int iXe, int iYe, COLORREF clrRect);
	UINT VDDevelopKit_C_Wnd3D_Redraw(HANDLE hVDWnd3D, BOOL bFitSize = TRUE);
	UINT VDDevelopKit_C_Wnd3D_GetDisplayImage(HANDLE hVDWnd3D, HANDLE hImage2D);
	UINT VDDevelopKit_C_Wnd3D_WndPointToImagePoint(HANDLE hVDWnd3D, int iWindowX, int iWindowY, double *dpImageX, double *dpImageY, double *dpImageZ);

	// Lens calibration
	HANDLE VDDevelopKit_C_LensCalib_Create();
	void VDDevelopKit_C_LensCalib_Destroy(HANDLE hLensCalib);
	UINT VDDevelopKit_C_LensCalib_Load(HANDLE hLensCalib, LPCWSTR cpFilePath);
	UINT VDDevelopKit_C_LensCalib_Save(HANDLE hLensCalib, LPCWSTR cpFilePath);
	UINT VDDevelopKit_C_LensCalib_GetRefImage(HANDLE hLensCalib, HANDLE hImage);
	UINT VDDevelopKit_C_LensCalib_SetRefImage(HANDLE hLensCalib, HANDLE hImage);
	UINT VDDevelopKit_C_LensCalib_Calibration(HANDLE hLensCalib, BOOL bReplaceImageWhenSuccess, HANDLE hImage);
	INT_PTR VDDevelopKit_C_LensCalib_ShowSettingWindow(HANDLE hLensCalib, VDGrabImageCallback pGrabImageCallback = NULL, HANDLE hContext = NULL);
	UINT VDDevelopKit_C_LensCalib_Process(HANDLE hLensCalib, HANDLE hImageSrc, HANDLE hImageDst);

	// Public image calibration
	UINT VDDevelopKit_C_ImageCalib_Init(UINT nCameraNum, LPCWSTR cpImageCalibDir);
	UINT VDDevelopKit_C_ImageCalib_Save(int iCameraIndex);
	UINT VDDevelopKit_C_ImageCalib_GetRefImage(int iCameraIndex, HANDLE hImage);
	UINT VDDevelopKit_C_ImageCalib_SetRefImage(int iCameraIndex, HANDLE hImage);
	UINT VDDevelopKit_C_ImageCalib_PosCalib_Calibration(int iCameraIndex, BOOL bReplaceImageWhenSuccess, HANDLE hImage);
	UINT VDDevelopKit_C_ImageCalib_ScaleCalib_Calibration(int iCameraIndex, BOOL bReplaceImageWhenSuccess, HANDLE hImage);
	INT_PTR VDDevelopKit_C_ImageCalib_ShowSettingWindow(int iCameraIndex, VDGrabImageCallback pGrabImageCallback = NULL, HANDLE hContext = NULL);

#ifdef __cplusplus
}
#endif
