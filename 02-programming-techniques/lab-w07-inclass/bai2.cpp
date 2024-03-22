#include <iostream>
using namespace std;
int N, X[100], col[100], pDia[100], sDia[100];
int a[100][100];
void inkq() {
	memset (a,0,sizeof(a));
	for (int i=1;i<=N;i++){
        a[i][X[i]]=1;
    }
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            cout<< a[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
void Try(int i) {
	for (int j = 1; j <= N; j++) {
		// gan X[i]=j
		if (col[j] == 0 && pDia[i - j + N] == 0 && sDia[i + j - 1] == 0) {
			X[i] = j;
			col[j] = pDia[i - j + N] = sDia[i + j - 1] = 1;
			if (i == N) 
				inkq();
		 }
		else {
			Try(i + 1);
		}
		//backtrack
		 col[j] = pDia[i - j + N] = sDia[i + j - 1] = 1;

	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= 99; i++) {
		col[i] = pDia[i - j + N] = sDia[i + j - 1] = 0;
	}
	Try(1);
	return 0;
}
