#include <Windows.h> 
#include <iostream> 
  
using namespace std; 
  //声明线程函数1，2
DWORD WINAPI Fun1Proc(LPVOID lpParameter);//WINAPI视窗操作系统应用程序接口,表示进行函数调用，函数参数的入栈方式是最右边先入栈 
DWORD WINAPI Fun2Proc(LPVOID lpParameter); //LPVOID是一个没有类型的指针,可以将LPVOID类型的变量赋值给任意类型的指针
  
int index=0; 
int tickets=20; 
HANDLE hMutex;  ////定义线程互斥对象,HANDLE是表示指向void类型的一个指针 
void main() 
{ 
    HANDLE hThread1; //定义线程hThread1
    HANDLE hThread2; //定义线程hThread2

//创建互斥对象.CreateMutex找出当前系统是否已经存在指定进程的实例。如果没有则创建一个互斥体
    hMutex=CreateMutex(NULL,TRUE,"tickets");//如执行成功，就返回互斥体对象的句柄,第二个参数为TRUE时，创建线程立即拥有mutex 
    //创建线程 
  //CreateThread是一种微软在Windows API中提供了建立新的线程的函数，该函数在主线程的基础上创建一个新线程。
  //线程中止运行后，线程对象仍然在系统中，必须通过CloseHandle函数来关闭该线程对象
    hThread1=CreateThread(NULL,0,Fun1Proc,NULL,0,NULL);//创建线程 
    hThread2=CreateThread(NULL,0,Fun2Proc,NULL,0,NULL); 
    //关闭线程句柄只是释放句柄资源，新开启线程后，如果不再利用其句柄，应该关闭句柄，释放系统资源。关闭线程句柄和线程的结束与否没有关系。
    CloseHandle(hThread1);
    CloseHandle(hThread2);  //关闭线程句柄
   
    
     
    if (hMutex) 
    { 
        if (ERROR_ALREADY_EXISTS==GetLastError()) //判断实例是否正在运行
        { 
            cout<<"only one instance can run!"<<endl; 
            return; 
        } 
    } 
  
    WaitForSingleObject(hMutex,INFINITE); //等待线程互斥对象,第二个参数为INFINITE表示一直等待，直到拥有互斥对象
    ReleaseMutex(hMutex); 
    ReleaseMutex(hMutex); 
  
    getchar(); 
} 
//线程1的入口函数 
DWORD WINAPI Fun1Proc(LPVOID lpParameter)//thread data 
{ 
    while (true) 
    { 
        ReleaseMutex(hMutex); 
        WaitForSingleObject(hMutex,INFINITE); //等待线程互斥对象,第二个参数为INFINITE表示一直等待，直到拥有互斥对象
        if (tickets>0) //如果车票数量大于0则卖票，车票数量减一
        { 
            Sleep(1); 
            cout<<"thread1 sell ticket :"<<tickets--<<endl; 
        } 
        else
            break; //若车票卖光了，则跳出while循环
        ReleaseMutex(hMutex); //卖出一张票后，释放线程互斥对象
    } 
  
    return 0; 
} 
//线程2的入口函数 
DWORD WINAPI Fun2Proc(LPVOID lpParameter)//thread data 
{ 
    while (true) 
    { 
        ReleaseMutex(hMutex); 
        WaitForSingleObject(hMutex,INFINITE); //等待线程互斥对象,第二个参数为INFINITE表示一直等待，直到拥有互斥对象
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
