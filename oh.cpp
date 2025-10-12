#include <cstdio>
#include<windows.h>
const int MAXLEN = 5000 + 10;
int prime[MAXLEN];
bool flag[MAXLEN] = {0};
int phi[MAXLEN],m = 0;

void oula(){
    phi[1] = 1;
    for(int i = 2;i < MAXLEN;i ++){
        if(!flag[i]){
            prime[m] = i;
            m ++;
            phi[i] = i - 1;
        }
        for(int j = 0;j <= m && i * prime[j] <= MAXLEN;j ++){
            flag[i * prime[j]] = true;
            if(i % prime[j] == 0){
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else{
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            }
        }
    }
    return;
}

void stepwise(int a[],int d,int n){
    int temp;
    for(int i = 0;i < d;i ++){
        for(int j = i + d;j < n;j += d){
            temp = a[j];int k = j;
            while((k - d) >= 0 &&  temp < a[k - d]){
                a[k] = a[k - d];k = k - d;
            }
            a[k] = temp;
        }
    }
}

void ShellSort(int a[],int n){
    for(int i = m - 1;i >= 0;i ++){
        int d = prime[i];
        stepwise(a,d,n);
    }
    stepwise(a,1,n);
    return;
}

int main() {
    int n;
    /*
    scanf("%d", &n);
    int a[MAXLEN];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    ShellSort(a, n);*/
    oula();
    for (int i = 0; i < m; i++) {
        printf("%d ", prime[i]);
    }
    system("pause");
    return 0;
}
