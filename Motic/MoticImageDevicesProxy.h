/**
 * @file MoticImageDeviceProxy.h
 *
 * @brief MoticImageDevice�����豸ģ�����ӿ���һ��C���Զ�̬��(dll)
 *        the proxy of Motic Capture module(MoticImageDevice) is a C dynamic library(dll). 
 *        �û���ͨ���ô���̬�⣬�򿪳���ģ����ֱ�ӻ�ȡͼ�񼯳ɵ����ǵ�Ӧ�ó����У�����Ӳ�Ѱ�����Motic�豸
 *        The developer, who want to integrate the motic device's image into his application, can use this dll query and operate the Motic device indirectly
 *        �ö�̬��Ϊ�����������Motic�ĳ���ģ�飨MoticImageDevice)�������ӣ�ʹ��������������׵ؼ���motic�豸
 *        this dynamic library create a bridge between the 3rd party application and Motic capture module(MoticImageDevice), allow the 3rd party application use Motic's Camera easily.
 *
 * @code
 * void Open()
 * {
 *    if(MIDP_Open(false) == 0)//�򿪣�Open Proxy
 *    {
 *      int count = MIDP_GetCameraCount();//��Ѱ�豸����query camera count
 *      for(int i = 0; i < count; i++)
 *      {
 *        AddCameraName(MIDP_GetCameraName(i));//�����豸����store the name of camera
 *      }    
 *      SetCurCameraIndex(MIDP_GetCurCameraIndex());//ѡ��ǰ�򿪵��豸��select current open camera
 *      count = MIDP_GetResolutionCount(); //��Ѱ�ֱ��ʸ�����query the count of resolution
 *      for (int i = 0; i < count; i++)
 *      {
 *        CString strFmt;
 *        long w, h;
 *        MIDP_GetResolution(i, &w, &h);//��Ѱ�ֱ��ʣ�query the resolution
 *        strFmt.Format(_T("%dX%d"), w, h);
 *        AddCurrentResolution(strFmt);//����ֱ��ʣ�store the resolution
 *      }
 *     SetCurResolutionIndex(MIDP_GetCurResolutionIndex()); //ѡ��ǰ�ֱ��ʣ�select current resolution  
 *    }
 * }
 *
 * void GetFrame()
 * {
 *   long w, h, bits, channels;
 *   MIDP_GetFormat(&w, &h, &bits, &channels);
 *   int sz = w*h*bits*channels/8;
 *   //extend unsigned char* m_pBuffer; int m_iSize;
 *   if(m_pBuffer== NULL || sz > m_iSize)
 *   {
 *     m_iSize = sz;
 *     if(m_pBuffer)
 *     {
 *       delete[] m_pBuffer;
 *       m_pBuffer = 0;
 *     }
 *     m_pBuffer = new unsigned char[m_iSize];
 *   }
 *   if(MIDP_GetFrame(m_pBuffer, w, h) == 0)
 *   {
 *     ShowImage(m_pBuffer, w, h);
 *   }
 * }
 * 
 * void Show(bool bShow)
 * {
 *   if(bShow) 
 *     MIDP_Show(1);
 *   else
 *     MIDP_Show(0);
 * }
 *
 * @endcode
 *
 * @Author: Chendemin@motic.com
 *
 * @Date:2011-9-19
 *
 */
#pragma once
/**
 * @brief ��Motic Image Devices ģ��
 *        Open Motic Image Devices Modules
 *
 * @param bShow ��ʼ�����Ƿ���ʾMoticImageDevices���棬bShow:0����ʾ,������ʾ
 *              display or hide the MoticImageDevices window after open, 0, hide, otherwise display 
 *
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
 *
*/
long MIDP_Open(long bShow);

/**
 * @brief ���ر�MoticImageDevices���˳�����ǰ����ùر� ��
 *          Close MoticImageDevices, need to be invoked before exit process
 *
 *
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
 *
*/
long MIDP_Close();

/**
 * @brief ��ͣ����,ͨ��MIDP_Resume����
 *        pause, invoke MIDP_Resume to continue.
 *
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
 *
 * @see MIDP_Resume
 *
*/
long MIDP_Pause();

/**
 * @brief �������У�������MIDP_Pause��ͣ��ɵ��ø÷�������
 *        resume from pause 

 *
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
 *
 * @see MIDP_Pause
 *
*/
long MIDP_Resume();

/**
 * @brief ��ʾ�����ؽ���
 *        show/hide window
 *
 * @Param bShow:0 ���ؽ���,��1,��ʾ�ϴμ���Ĵ��ڣ�2,����ʾ������壬3����ʾ��Ƶ��������
 *��������������0 hide the window, 1 show window, 2 show control Panel, 3 show live image and Control Panel
 *
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
*/
long MIDP_Show(long bShow);

/**
 * @brief ��ȡ��ǰͼ��ĸ�ʽ
 *        Query image format
 *
 * @param w         ͼ����
 *                  image width
 *        h         ͼ��߶�
 *                  image height
 *        bits      ɫ��λ�һ����8����λ��Ϊ16��
 *                  color depth(8 bits normal image, 16bits for high depth image)
 *        channels  ��ɫͨ����һ����RGB����ͨ������ɫΪ1��ͨ����
 *                  color channels(normally, we use RGB format, which has 3 channels, homochrome image only has 1 channel)
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
 */
long MIDP_GetFormat(long*w, long*h, long* bits, long*channels);

/**
 * @brief ��ȡһ֡ͼ������
 *        get one frame of image
 *
 * @param buffer ������ָ�룬�����㹻���ɽ�ȡ�õ�ͼ�����ݡ�
 *               The frame buffer, must be big enough for containing the image data.
 *        w      ͼ���� 
 * ��������������width
 *        h      ͼ��߶�
 *               height 
 *
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
 *
 * @see   MIDP_GetFormat
 */
long MIDP_GetFrame(unsigned char* buffer, long w, long h);

/**
 * @brief ��ȡ�豸��
 *        Query the number of cameras 
 *
 * @return �豸��
 *          the number of cameras
 *
 */
long  MIDP_GetCameraCount();

/**
 * @brief ��ȡ��ǰ���豸����������ͨ��MIDP_GetCameraName�������
 *        query the index of opened camera. can obtain device's name by invoke MIDP_GetCameraName 
 *
 * @return ��ǰ�򿪵��豸����
 *         the index of opened camera.
 *
 * @see MIDP_GetCameraName
 */
long  MIDP_GetCurCameraIndex();

/**
 * @brief ����������ȡ�豸����
 *        query the device's name 
 * 
 * @Return �豸����,UINCODE�ַ�
 *         device's UINCODE name
*/
long MIDP_GetCameraName( long idx, wchar_t*name, int len );

/**
 * @brief ѡ���л��豸���л��豸��Ҫ���»�ȡ�ֱ�����ͼ���ʽ����
 *        select to open camera by index, after invoke this function, all the resolutions and formats of image need to be Query again
 * @param idx �豸����
 *            index of camera
 *
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
 *
 * @see MIDP_GetCameraCount 
 */
long  MIDP_SelectCamera(long idx);

/**
 * @brief ��ȡ��ǰ���豸�ķֱ��ʸ���
 *        get the number of resolutions
 * 
 * @return     �ֱ��ʸ���
 *             the count of resolutions
 */
long  MIDP_GetResolutionCount();

/**
 * @brief ��ȡ��ǰ��ʾ�ķֱ�����������ͨ��MIDP_GetResolution��ȡʵ�ʷֱ���
 *        get the index of current resolution, please invoke MIDP_GetResolution to query the resolution.
 *
 * @Return ��ǰ�ֱ�������
 *          the index of current resolution
 * @see MIDP_GetResolution
*/
long  MIDP_GetCurResolutionIndex();

/**
 * @brief ����������ȡ�ֱ���
 *        query the resolution by index
 * @param idx �ֱ�������
 *            the index of resolution
 *        w   ���ڻ�ȡ�ֱ��ʿ�ȵ�����ָ��
 *            the point to the long to receive the with of resolution
 *        h   ���ڻ�ȡ�ֱ��ʸ߶ȵ�����ָ��
 *            the point to the long to receive the height of resolution
 *
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
 */
long MIDP_GetResolution(long idx, long*w, long*h);

/**
 * @brief ���ݷֱ��ʴ�С��ѡ��ֱ��ʣ�����ΪMIDP_GetResolution���طֱ���֮һ
 *        select the resolution by size, the w,h must be one of values query from MIDP_GetResolution
 * 
 * @param w   �ֱ��ʿ��
 *            the with of resolution
 *        h   �ֱ��ʸ߶�
 *            the height of resolution
 *
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
 *
 * @see  MIDP_GetResolution
 */
long  MIDP_SelectResolution(long w, long h);

/**
 * @brief ���ݷֱ���������ѡ��ֱ���
 *        select the resolution by index
 *
 * @param idx  �ֱ�����������Ϊ0��������MIDP_GetResolutionCount����ֵ������)֮���ֵ.
 *              the index of resolution must be one of integrate vaule between 0 and the value return by MIDP_GetResolutionCount
 *
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
 *
 * @see MIDP_GetResolutionCount
 */
long  MIDP_SelectResByIndex(long idx);

/**
 * @brief ���գ�����ǰ֡����ΪͼƬ��֧��BMP,JPG,PNG���ָ�ʽ
 *        Capture, save current image to file, support 3 format:.bmp, .jpg, .png.
 *
 * @param name, ����ͼƬ���ļ�����ע����չ��ֻ��Ϊ".bmp", ".jpg", ".png"����֮һ����Ӧ����ͼ���ʽ��
 *��������������file name. The extension must be one of 3 format types: ".bmp", ".jpg" or ".png" 
 *
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
 */
long MIDP_Capture(wchar_t*name);

/**
 * @brief �趨�Զ��ع⣬
 *        Auto Exposure setting
 * @param bAuto �Ƿ���Զ��ع⣬true�򿪣�false�ر�
 *              Activate/deactivate Auto Exposure, true activate auto exposure, false deactivate auto exposure
 *
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
 */
long MIDP_AutoExposure(bool bAuto);

/**
 * @brief ��Ѱ�ع�ֵ��Χ
 *        query the range of exposure value
 *
 * @param  min ��С�ع�ֵ
 *             the minimum exposure value
 *         max ����ع�ֵ
 *             the maximum exposure value
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
 */
long MIDP_GetExposureValueRange(long* min, long* max);

/**
 * @brief �趨�ع�ֵ
 *        set exposure value
 *
 * @param  v  �ع�ֵ��������MIDP_GetExposureValueRange����ֵ��Χ��
 *            exposure value, must be one of value within the range return by MIDP_GetExposureValueRange
 *
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
 *
 * @see    MIDP_GetExposureValueRange   
 */
long MIDP_SetExposureValue(long v);

/**
 * @brief ��ȡ�ع�ֵ
 *        get exposure value
 *
 * @param  v  ���صĵ�ǰ�ع�ֵ
 *            current exposure value return.
 *
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
 *
 * @see    MIDP_GetExposureValueRange   
 */
long MIDP_GetExposureValue(long* v);

/**
 * @brief ��ȡ���淶Χ�����Ӳ��֧�֣������Χ����Ӳ�������棬����Ϊ�������
 *        Query the range of gain, this gain come from hardware if device support gain adjustment, otherwise, it is software gain
 *
 * @param  min ��С���棬
 *             minimum gain
 *         max �������
 *             maximum gain
 *
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
 *
 */
long MIDP_GetGainRange(float* min, float*max);

/**
 * @brief �������棬Ĭ��ֵΪ1.0
 *        set Gain, default value is 1.0
 *
 * @param  g ����ֵ������ΪMIDP_GetGainRange���صķ�Χ֮���ֵ��
 *           gain, gain value must be in the range query from MIDP_GetGainRange 
 *
 * @return 0 �ɹ�; ����ʧ��
 *         0 succeed, otherwise failed.
 *
 * @see    MIDP_GetGainRange
 */
long MIDP_SetGain(float g);

/**
 * @brief ��ȡRGB���淶Χ��RGBΪ�������
 *        Query the range of software gain
 *
 * @param  min ��С���棬
 *             minimum gain
 *         max �������
 *             maximum gain
 *
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
 *
 */
long MIDP_GetRGBGainRange(float*min, float*max);

/**
 * @brief ����RGB�������, Ĭ��ֵΪ1.0
 *        set RGB software Gain,default value is 1.0
 *
 * @param  r ��ɫ����ֵ������ΪMIDP_GetRGBGainRang���صķ�Χ֮���ֵ��
 *           gain of red channel, the value must be within the range query from MIDP_GetRGBGainRange
 *         g ��ɫ����ֵ������ΪMIDP_GetRGBGainRang���صķ�Χ֮���ֵ��    
 *           gain of green channel, the value must be within the range query from MIDP_GetRGBGainRange
 *         b ��ɫ����ֵ������ΪMIDP_GetRGBGainRang���صķ�Χ֮���ֵ��
 *           gain of blue channel, the value must be within the range query from MIDP_GetRGBGainRange
 *
 * @return 0 �ɹ�; ����ʧ��
 *         0 succeed, otherwise failed.
 *
 * @see    MIDP_GetRGBGainRange
 */
long MIDP_SetRGBGain(float r, float g, float b);

/**
 * @brief �趨����ƫ��, Ĭ��ֵΪ0
 *        set offset of brightness, default value is 0
 *
 * @param  b ����ƫ��ֵ����ΧΪ-255~255,Ĭ��Ϊ0��
 *           offset value of brightness, range:-255~255, default value: 0
 *
 * @return 0 �ɹ�; ����ʧ��
 *         0 succeed, otherwise failed.
 *
 */
long MIDP_SetBrightness(long b);

/**
 * @brief �趨RGB����ɫ������ƫ��, Ĭ��ֵΪ0
 *        set offset of RGB brightness, default value is 0
 *
 * @param  r ��ɫ����ƫ��ֵ����ΧΪ-255~255,Ĭ��Ϊ0��
 *           offset value of Red brightness, range:-255~255, default value: 0
 *         g ��ɫ����ƫ��ֵ����ΧΪ-255~255,Ĭ��Ϊ0��
 *           offset value of Green brightness, range:-255~255, default value: 0
 *         b ��ɫ����ƫ��ֵ����ΧΪ-255~255,Ĭ��Ϊ0��
 *           offset value of Blue brightness, range:-255~255, default value: 0
 *
 * @return 0 �ɹ�; ����ʧ��
 *         0 succeed, otherwise failed.
 *
 */
long MIDP_SetRGBBrightness(long r, long g, long b);

/**
 * @brief �趨٤��ֵ
 *        set gamma
 *
 * @param  g ٤��ֵ����ΧΪ0.1~10,Ĭ��Ϊ1.0��
 *           gamma value, range: 0.1-10,default value is 1.0
 *         o ����ƫ�ƣ���Ϊֱ��ͼ��ǿ����ֵ����ΧΪ0~255,Ĭ��Ϊ0
 *           offset of pixel, it is the lower limit value of histogram enhance, range: 0~255, default: 0
 *
 * @return 0 �ɹ�; ����ʧ��
 *         0 succeed, otherwise failed.
 *
 */
long MIDP_SetGamma(float g, long o);

/**
 * @brief ���ڵ�ǰ��ͼ����㲢Ӧ�ð�ƽ�⣬һ������µ�ǰͼ��Ϊ����ʱ���øú�����
          ����ϵͳ�����������ֻҪ����һ�θú�������ƽ��ͻ������ϵͳ�У��´�ֻҪ����MIDP_ActivateWhiteBalance
 *        calculate the factors of whitebalance base on current image. normally, invoke this function once only 
 *        when current image is background image, and these factors will be record in system, you can open white balance simply invoke MIDP_ActivateWhiteBalance next time
 *
 * @return 0 �ɹ�; ����ʧ��
 *         0 succeed, otherwise failed.
 *
 * @see MIDP_ActivateWhiteBalance
 */
long MIDP_DoWhiteBalance();

/**
 * @brief Ӧ�ð�ƽ�⣬���øú�����MIDP_DoWhiteBalance֮��һ����ͬ���Ļ����°�ƽ��Ĳ�������ı�,���ᱣ����ϵͳ��
 *���������´��ٴ򿪳���ֻҪ�򵥵ص��øú����Ϳ���Ӧ��֮ǰ����İ�ƽ��
 *        Activate white balance, the whitebalance factors, which are generated after call MIDP_DoWhiteBalance last time,will remain in you system.
 *        You can simply invoke this function to activate white balance when you open the software next time. 
 *
 * @return 0 �ɹ�; ����ʧ��
 *         0 succeed, otherwise failed.
 *
 * @see MIDP_DoWhiteBalance
 */
long MIDP_ActivateWhiteBalance();

/**
 * @brief �趨ɫ��У������
 *        set Color Correction
 *
 * @param  val ɫ��У������ֵ����Χ-10~10,Ĭ��ֵΪ0,�����������ǿɫ�ʣ���ֵ����ɫ��
 *             value of color correction, range: -10-10, default: 0, 
 *
 * @return 0 �ɹ�; ����ʧ��
 *         0 succeed, otherwise failed.
 *
 */
long MIDP_SetColorCorrection(long val);


/**
 * @brief ��ȡһ֡ͼ�����ݵ�ָ������
 *
 * @param buffer ������ָ�룬�����㹻���ɽ�ȡ�õ�ͼ�����ݡ�
 *        x      ͼ���ˮƽ��ʼλ�� 
 *        y      ͼ��Ĵ�ֱ��ʼλ��
 *        w      ͼ��Ŀ��
 *        h      ͼ��ĸ߶�
 *        stride �����������ֽ���
 *        flip   �Ƿ��뷭תͼ��
 *
 * @return     0 �ɹ�; ����ʧ��
 *             0 succeed, otherwise failed.
 *
 * @see   MIDP_GetFormatEx
 */
long MIDP_GetFrameEx(unsigned char* buffer, long x, long y, long w, long h, long stride, bool flip);
/**
 * @undocumented
 */
double MIDP_EvaluateFocusDegree24bits(unsigned char* buffer, long width, long height);