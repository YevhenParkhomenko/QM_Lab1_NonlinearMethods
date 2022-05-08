#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int methodRelaxation(double e){
    cout << "The chosen one is relaxation.\ne = " << e << endl;
    int cnt = 0;
    double x0 = 3.275, x1, t = 0.06529759378, fx;
    int iterCnt = log((0.5)/e)/log(1.0/0.2473146365)+1;
    cout << "The estimated number of iterations is " << iterCnt << endl;
    cout << "n\txn\t\tf(x)\n";
    while (true){
        fx = t*(x0*x0*x0-3*x0*x0-x0-3);
        x1 = x0 - fx;
        cout << cnt << "\t" << x0 << "\t" << fx << endl;
        if(fabs(x1-x0)<e) break;
        cnt++;
        x0 = x1;
    }
    cout << endl;
    return 0;
}

int methodNewton(double e){
    cout << "The chosen one is Newton.\ne = " << e << endl;
    int cnt = 0;
    double x0 = -2.1, x1, fx;
    int iterCnt = (log2(log((0.5)/e)/log(1.0/0.88122037914))+1);
    cout << "The estimated number of iterations is " << ++iterCnt << endl;
    cout << "n\txn\t\tf(x)\n";
    while (true){
        fx = x0*x0*x0 + x0*x0 -4*x0 -4;
        x1 = x0 - fx/(3*x0*x0+2*x0-4);
        cout << cnt << "\t" << x0 << "\t" << fx << endl;
        if(fabs(x1-x0)<e) break;
        cnt++;
        x0 = x1;
    }
    cout << endl;
    return 0;
}

int methodSimpleIteration(double e){
    cout << "The chosen one is simple iteration.\ne = " << e << endl;
    int cnt = 0;
    double x0 = 3.75, x1, temp;
    int iterCnt = log(0.5/((1.0-0.781)*e))/log(1.0/0.781)+1;
    cout << "The estimated number of iterations is " << iterCnt << endl;
    cout << "n\txn\t\tf(x)\n";
    while(true){
        x1 = pow(4*x0*x0+4*x0-16, 1.0/3);
        cout << cnt << "\t" << x0 << "\t" << x0-x1 << endl;
        if(fabs(x1-x0)<e) break;
        cnt++;
        x0 = x1;
    }
    return 0;
}

int main()
{
    double e = 0.001;
    char methodInd;
    char yesnt = 'Y';
    cout << fixed;
    cout << setprecision(10);
    while(yesnt == 'Y'){
    cout << "Hello there!\nChoose one of the following methods(enter the corresponding number):\n";
    cout << "1. Relaxation\n2. Newton\n3. Simple iteration\n";
    cin >> methodInd;
    cout << "e = " << e << "\nWould you like to change it?(Y/N)\n";
    cin >> yesnt;
    if (yesnt == 'Y'){
        cout << "Please set the value of e\n";
        cin >> e;
    }
    switch (methodInd)
    {
        case '1':
            methodRelaxation(e);
            break;
        case '2':
            methodNewton(e);
            break;
        case '3':
            methodSimpleIteration(e);
            break;
    }
    cout << "Would you like to solve the equation via different method/with different e-value?(Y/N)\n";
    cin >> yesnt;
    }
    cout << "Thank you.";
    return 0;
}
