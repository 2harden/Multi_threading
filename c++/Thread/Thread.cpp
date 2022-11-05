// Thread.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>

using namespace std;

// 自己创建的线程也要从一个函数开始运行
void MyPrint() 
{
    cout << "thread start..." << endl;

    cout << "thread end1..." << endl;
    cout << "thread end2..." << endl;
    cout << "thread end3..." << endl;
    cout << "thread end4..." << endl;
    cout << "thread end5..." << endl;
    cout << "thread end6..." << endl;
    cout << "thread end7..." << endl;
    cout << "thread end8..." << endl;
    cout << "thread end9..." << endl;
}

int main()
{
    // 程序运行起来，生成一个进程，该进程所属的主线程开始运行
    // cout << "Hello World!" << endl; // 实际上是主线程在执行，主线程从main()函数返回，则整个进程执行完毕

    // 主线程从main()开始执行，那么我们自己创建的线程也需要从一个函数开始执行（初始函数），一旦这个函数运行完毕，就代表我们这个线程执行完毕

    // 整个进程是否执行完毕的标志是主线程是否执行完毕，如果主线程执行完毕了，就代表着整个进程执行完毕了
    // 此时，如果其他子线程还没执行完毕，那么这些子线程也会被操作系统强终止
    // 所以，一般情况下，大家想保持子线程（自己用代码创建的线程）的运行状态的话，要让主线一直保持运行，不要让主线运行完毕
    // 这条规律有例外，后面会解释这种例外，目前先这样理解和记忆

    // 编写多线程
    /*  1，包含头文件
     *  2，创建初始函数
     *  3，main函数中开始编写代码
     */

    // 多线程编程函数
    /* thread：是标准库的一个类
     * join(): 加入线程，说白了就是阻塞，阻塞主线程，让主线程等待子线程执行完毕，然后子线程和主线程会合，一起执行完毕
     * detach(): 传统多线程程序主线程要等待子线程执行完毕，然后自己再退出。
     *           detach，分离，也就是主线程不和子线程会合了，你主线程执行你自己的，我子线程执行我的，你主线程也不必等我子线程运行结束，你可以先执行结束，这并不影响我子线程的执行
     *           为什么要引入detach()? 我们创建了很多子线程，让主线逐个等待子线程执行完毕，这种编程方法不太好，所以引入了detech()
     *           一旦detach()之后，与这个主线程关联的thread对象就会失去与这个主线程的关联，此时这个子线程就会驻留在后台运行（主线程与子线程失去联系）
     *           这子线程就相当于被c++运行时库接管，当这个子线程执行完毕后，有运行时库负责清理该线程相关的资源（守护线程）
     *           detach()，会导致MyPrint失去我们自己的控制
     * joinable()：判断是否可以成功使用join()或者detach()
     *             返回true（可以join或者detach）或者false（不能join或者detach）
     */

    // 这里要明确一点，有两个线程在跑，相当于整个程序的执行有两条线在同时走，所以可以干两个事。即使一条线被堵住了，另外一个还是可以通行的，这就是多线程
    // 如果主线程执行完了，但是子线程还没执行完毕，这种程序员是不合格的，写出来的程序也是不稳定的
    // 一个书写良好的程序，应该是主线程等待子线程执行完毕，主线程才能退出
    thread myPrint(MyPrint); // thread：是标准库的一个类，MyPrint：是可调用对象。这一句整体就是创建了线程，线程执行起点（入口）MyPrint(),myPrint线程开始执行
    // myPrint.join(); // 加入线程，说白了就是阻塞，阻塞主线程，让主线程等待子线程执行完毕，然后子线程和主线程会合，一起执行完毕。等待MyPrint()执行完毕
    if (myPrint.joinable()) {
        myPrint.join();
        cout << "myPrint.joinable() is true" << endl;
    }
    else {
        cout << "myPrint.joinable() is false" << endl;
    }
    // myPrint.detach(); // 主/子线程各执行各的，一旦调用了detach()，就再不能用join()，会有异常

    cout << "Hello World1!" << endl;
    cout << "Hello World2!" << endl;
    cout << "Hello World3!" << endl;
    cout << "Hello World4!" << endl;
    cout << "Hello World5!" << endl;
    cout << "Hello World6!" << endl;

    return 0;
}
