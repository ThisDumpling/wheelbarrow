#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

char str[1024];
int Loop,Count;
double Time;

int main(void)
{
    printf("本程序基于c++的剪切板操作与模拟键盘操作实现，已在GitHub开源\n");
    printf("请将需要打出的文本放在与本程序相同的根目录下，使用txt文件并命名为text\n");
    printf("请输入你将要进行的循环次数（使用正整数，建议不要过大）：");
    scanf("%d",&Loop);
    printf("\n请在此处输入每次循环之间的间隔时间（支持小数，建议不要过短，可能会造成机器卡顿）：");
    scanf("%lf",&Time);
    printf("\n5秒后自动开始，现在请点击需要输入的文本框");
    Sleep(5000);
    while(Loop--)
    {
        freopen("text.txt","r",stdin);
        while(scanf("%s\n",str)!=EOF)
        {
            HWND hwnd=NULL;
            OpenClipboard( hwnd );//打开剪切板
            EmptyClipboard();//清空剪切板
            HANDLE hHandle = GlobalAlloc(GMEM_FIXED, 1000);//分配内存
            char* pData = (char*) GlobalLock(hHandle);//锁定内存，返回申请内存的首地址
            strcpy(pData,str);
            SetClipboardData(CF_TEXT, hHandle);//设置剪切板数据
            GlobalUnlock(hHandle);//解除锁定
            CloseClipboard();//关闭剪切板
            keybd_event(17,0,0,0);
            keybd_event(86,0,0,0);
            keybd_event(17,0,KEYEVENTF_KEYUP,0);
            keybd_event(86,0,KEYEVENTF_KEYUP,0);
            keybd_event(13,0,0,0);
            keybd_event(13,0,KEYEVENTF_KEYUP,0);
        }
        printf("当前程序已执行%d次\n",++Count);
        Sleep(Time*1000);
    }
    return 0;
}
