#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
#define MAX_CHAR 1000


void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void generatePermutations(int nums[], int N, int start) {
    if (start == N) {
        for (int i = 0; i < N; ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = start; i < N; ++i) {
        swap(nums[start], nums[i]);
        generatePermutations(nums, N, start + 1);
        swap(nums[start], nums[i]); 
    }
}


void generateKPermutations(int nums[], int N, int K, int start) {
    if (start == K) {
        
        for (int i = 0; i < K; ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = start; i < N; ++i) {
        swap(nums[start], nums[i]);
        generateKPermutations(nums, N, K, start + 1);
        swap(nums[start], nums[i]); 
    }
}

void generateKSets(int nums[], int N, int K, int start, int currentSize) {
    if (currentSize == K) {
        
        for (int i = 0; i < K; ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = start; i <= N; ++i) {
        nums[currentSize] = i;
        generateKSets(nums, N, K, i + 1, currentSize + 1);
    }
}
int main() {
  int choice;
  cin>>choice; 
  if (choice == 1) 
	{
	int n; 
    cin>>n; 
    int nums[n];
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }

    cout << "Tat ca cac hoan vi cua  " << n << ":" << endl;
    generatePermutations(nums, n, 0);
   }
 
  if (choice == 2) {
  	int n, K;
    cout << "Enter two positive integers N and K (N >= K): ";
    cin >> n >> K;
    int nums[n];
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }

    cout << "All " << K << "-permutations from 1 to " << n << ":" << endl;
    generateKPermutations(nums, n, K, 0);
  } 
  
  if (choice == 3){
  	int N, K;
    cout << "Nhap hai so nguyen duong N và K (N >= K): ";
    cin >> N >> K;
    int nums[K];
    cout << "Tat ca cac " << K << "sets cua " << N << ":" << endl;
    generateKSets(nums, N, K, 1, 0);

  } 
  return 0; 
}

