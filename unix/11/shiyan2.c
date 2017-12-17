#include <Windows.h> 
#include <iostream> 
  
using namespace std; 
  //�����̺߳���1��2
DWORD WINAPI Fun1Proc(LPVOID lpParameter);//WINAPI�Ӵ�����ϵͳӦ�ó���ӿ�,��ʾ���к������ã�������������ջ��ʽ�����ұ�����ջ 
DWORD WINAPI Fun2Proc(LPVOID lpParameter); //LPVOID��һ��û�����͵�ָ��,���Խ�LPVOID���͵ı�����ֵ���������͵�ָ��
  
int index=0; 
int tickets=20; 
HANDLE hMutex;  ////�����̻߳������,HANDLE�Ǳ�ʾָ��void���͵�һ��ָ�� 
void main() 
{ 
    HANDLE hThread1; //�����߳�hThread1
    HANDLE hThread2; //�����߳�hThread2

//�����������.CreateMutex�ҳ���ǰϵͳ�Ƿ��Ѿ�����ָ�����̵�ʵ�������û���򴴽�һ��������
    hMutex=CreateMutex(NULL,TRUE,"tickets");//��ִ�гɹ����ͷ��ػ��������ľ��,�ڶ�������ΪTRUEʱ�������߳�����ӵ��mutex 
    //�����߳� 
  //CreateThread��һ��΢����Windows API���ṩ�˽����µ��̵߳ĺ������ú��������̵߳Ļ����ϴ���һ�����̡߳�
  //�߳���ֹ���к��̶߳�����Ȼ��ϵͳ�У�����ͨ��CloseHandle�������رո��̶߳���
    hThread1=CreateThread(NULL,0,Fun1Proc,NULL,0,NULL);//�����߳� 
    hThread2=CreateThread(NULL,0,Fun2Proc,NULL,0,NULL); 
    //�ر��߳̾��ֻ���ͷž����Դ���¿����̺߳������������������Ӧ�ùرվ�����ͷ�ϵͳ��Դ���ر��߳̾�����̵߳Ľ������û�й�ϵ��
    CloseHandle(hThread1);
    CloseHandle(hThread2);  //�ر��߳̾��
   
    
     
    if (hMutex) 
    { 
        if (ERROR_ALREADY_EXISTS==GetLastError()) //�ж�ʵ���Ƿ���������
        { 
            cout<<"only one instance can run!"<<endl; 
            return; 
        } 
    } 
  
    WaitForSingleObject(hMutex,INFINITE); //�ȴ��̻߳������,�ڶ�������ΪINFINITE��ʾһֱ�ȴ���ֱ��ӵ�л������
    ReleaseMutex(hMutex); 
    ReleaseMutex(hMutex); 
  
    getchar(); 
} 
//�߳�1����ں��� 
DWORD WINAPI Fun1Proc(LPVOID lpParameter)//thread data 
{ 
    while (true) 
    { 
        ReleaseMutex(hMutex); 
        WaitForSingleObject(hMutex,INFINITE); //�ȴ��̻߳������,�ڶ�������ΪINFINITE��ʾһֱ�ȴ���ֱ��ӵ�л������
        if (tickets>0) //�����Ʊ��������0����Ʊ����Ʊ������һ
        { 
            Sleep(1); 
            cout<<"thread1 sell ticket :"<<tickets--<<endl; 
        } 
        else
            break; //����Ʊ�����ˣ�������whileѭ��
        ReleaseMutex(hMutex); //����һ��Ʊ���ͷ��̻߳������
    } 
  
    return 0; 
} 
//�߳�2����ں��� 
DWORD WINAPI Fun2Proc(LPVOID lpParameter)//thread data 
{ 
    while (true) 
    { 
        ReleaseMutex(hMutex); 
        WaitForSingleObject(hMutex,INFINITE); //�ȴ��̻߳������,�ڶ�������ΪINFINITE��ʾһֱ�ȴ���ֱ��ӵ�л������
        if (tickets>0) 
        { 
            Sleep(1); 
            cout<<"thread2 sell ticket :"<<tickets--<<endl; 
        } 
        else
            break; 
        ReleaseMutex(hMutex); 
    } 
  
    return 0; 
}
