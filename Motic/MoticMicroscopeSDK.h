#pragma once

/**
\brief ����̨�¼�
*/
#define XY_MOVING (0)
#define XY_MOVED (1)
/**
\brief Z ���¼�
*/
#define Z_MOVING (10)
#define Z_MOVED (11)
/**
\brief �ﾵ�¼�
*/
#define OBJECTIVE_CHANGING (20)
#define OBJECTIVE_PRECHANGED (21)
#define OBJECTIVE_CHANGED (22)
/**
\brief �����¼�
*/
#define ILLUMINATION_CHANGED (30)


/**
\brief ��΢���¼��ص�����
*/
typedef void (*fnEventHandler)(int eventId, int data, void* userdata);

/**
\brief ��ʼ����΢��
*/
int mms_Initialize(const wchar_t* configpath);

/**
\brief ����ʼ����΢��
*/
void mms_Uninitialize();

/**
\brief ������΢���ص�����
*/
void mms_SetEventHandler(fnEventHandler eh, void* userdata);

/**
\brief ����̨�Ƿ����
*/
bool xy_Available();

/**
\brief �Ƿ������ƶ���		
*/
bool xy_IsMoving();

/**
\brief ��ȡx����ķ�Χ��
\param min ��Сλ��(΢��)��
\param max ���λ��(΢��)��
*/
void xy_XRange(double* min,double* max);

/**
\brief ��ȡy����ķ�Χ��
\param min ��Сλ��(΢��)��
\param max ���λ��(΢��)��
*/
void xy_YRange(double* min,double* max);

/**
\brief ��ȡ�ٶȷ�Χ��
\param min ��С��
\param max ���	
*/
void xy_SpeedRange(double* min,double* max);

/**
\brief ��ȡ�ӳ����ĵ�ǰλ�á�
\param positionX [out]xλ��(΢��)��
\param positionY [out]yλ��(΢��)��
*/
void xy_CurrentPosition(double* positionX,double* positionY);

/**
\brief ����ƶ���
\param deltaX x����ƫ����(΢��)��
\param deltaY y����ƫ����(΢��)��
\param speed �ٶ�(΢��/��)��
\note ���û���ƶ�,�Ѿ�����Ŀ��λ�ò���XY_MOVED��
���speed=0���ߴ����޷��ƶ���״̬,�������κ���Ϣ,����false��
*/
bool xy_MoveRelatively(double deltaX,double deltaY,double speed);

/**
\brief �ƶ�������λ�á�
\param positionX xλ��(΢��)��
\param positionY yλ��(΢��)��
\param speed �ٶȡ�
\note ���û���ƶ�,�Ѿ�����Ŀ��λ�ò���XY_MOVED,
speed=0���ߴ����޷��ƶ���״̬,�������κ���Ϣ,����false��
*/
bool xy_MoveAbsolutely(double positionX,double positionY,double speed);

/**
\brief ��һ�����������ƶ���
\param angle �˶��Ƕ�,��ʱ��Ϊ��,0��Ϊx������(��)��(�Ƕ�0~360)��
\param speed �ٶȡ�
\note ���û���ƶ�,�Ѿ�����Ŀ��λ�ò���XY_MOVED,
speed=0���ߴ����޷��ƶ���״̬,�������κ���Ϣ,����false��
*/
bool xy_MoveContinuously(double angle,double speed);

/**
\brief ֹͣ�ƶ���
*/
void xy_Stop();

/**
\brief ���ÿջز�����
\param compensationx X ��ջز���ֵ(΢��);
\param compensationy Y ��ջز���ֵ(΢��);
*/
void xy_SetCompensation(double compensationx, double compensationy);

/**
\brief ��ȡ�ջز������á�
\param compensationx X ��ջز���ֵ(΢��);
\param compensationy Y ��ջز���ֵ(΢��);
*/
void xy_GetCompensation(double* compensationx, double* compensationy);

/**
\brief ��ȡӲ���˶�������
\param scaleX [out]΢��/Ӳ���ƶ���λ����������ȣ���
\param scaleY [out]΢��/Ӳ���ƶ���λ����������ȣ���
*/
void xy_GetHardwareMotionScale(double* scaleX,double* scaleY);

/**
\brief Z ���Ƿ����
*/
bool z_Available();

/**
\brief �Ƿ������ƶ���		
*/
bool z_IsMoving();

/**
\brief ��ȡ�ƶ���Χ��
\param min ��Сλ��(΢��)��
\param max ���λ��(΢��)��
*/
void z_Range(double* min,double* max);

/**
\brief ��ȡ�ٶȷ�Χ��
\param min ��С��
\param max ���
*/
void z_SpeedRange(double* min,double* max);

/**
\brief ��ȡ��ǰλ�á�(΢��)		
*/
double z_CurrentPosition();

/**
\brief ����ƶ���
\param delta ���λ��(΢��)��
\param speed �ٶȡ�
\note ���û���ƶ�,�Ѿ�����Ŀ��λ�ò���Z_MOVED��
speed=0���ߴ����޷��ƶ���״̬,�������κ���Ϣ,����false��
*/
bool z_MoveRelatively(double delta,double speed);

/**
\brief �ƶ�������λ�á�
\param position λ��(΢��)��
\param speed �ٶȡ�
\note ���û���ƶ�,�Ѿ�����Ŀ��λ�ò���Z_MOVED��
speed=0���ߴ����޷��ƶ���״̬,�������κ���Ϣ,����false��
*/
bool z_MoveAbsolutely(double position,double speed);

/**
\brief ��һ��������������ƶ���
\param dir ����,true:������,false:������
\param speed �ٶȡ�
\note ���û���ƶ�,�Ѿ�����Ŀ��λ�ò���Z_MOVED��
speed=0���ߴ����޷��ƶ���״̬,�������κ���Ϣ,����false��
*/
bool z_MoveContinuously(bool dir,double speed);

/**
\brief ֹͣ��
*/
void z_Stop();

/**
\brief ���ÿջز�����
\param compensation �ջز���ֵ(΢��);
*/
void z_SetCompensation(double compensation);

/**
\brief ��ȡ�ջز������á�
\return �ջز�������(΢��)��
*/
double z_GetCompensation();

/**
\brief ��ȡӲ���˶�������(΢��/Ӳ���ƶ���λ(���������))��
*/
double z_GetHardwareMotionScale();


/**
\brief �ﾵ�Ƿ����
*/
bool obj_Available();

/**
\brief ��ȡ�ﾵ������
*/
int obj_GetCount();

/**
\brief ��ȡ�ﾵ�Ŵ�����
\param n [in]����0���ﾵ������
*/
double obj_GetObjectiveMagnification(int n);

/**
\brief �л��ﾵ��
\param n [in]Ŀ���ﾵ������
*/
bool obj_SwitchObjective(int n);

/**
\brief ��ȡ��ǰ�ﾵ��
\return �ﾵ������
*/
int obj_GetCurrentObjective();


/**
\brief �����Ƿ����
*/
bool illumination_Available();

/**
\brief ��ȡ����ֵ��Χ��
\param min [out]��Сֵ��
\param max [out]���ֵ��		
*/
void illumination_GetRange(int* min,int* max);

/**
\brief ��ȡ����ֵ��
\return ��ǰ����ֵ��
\see SetValue
*/
int illumination_GetValue();

/**
\brief ��������ֵ��
\param val [in]����ֵ��
\see GetValue
*/
void illumination_SetValue(int val);