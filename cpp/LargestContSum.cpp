#include <iostream>
using namespace std;

int maxSubArraySum(int *array,int size){
    int maxSoFar = array[0];
    int curMax = array[0];
    

    
    for (int i = 0; i < size; i++){
        curMax = max (array[i], curMax + array[i]);
        maxSoFar = max (maxSoFar, curMax);
    }
    return maxSoFar;
}

int maxSubArrayTrace(int *array, int size){
    int maxSoFar = ~0;
    int maxEndingHere = 0;
    int startIdx = 0;
    int endIdx = 0;
    int s = 0;
    
    for (int i = 0; i < size; i++){
        maxEndingHere += array[i];
        
        if(maxEndingHere > maxSoFar){
            maxSoFar = maxEndingHere;
            startIdx =  s;
            endIdx = i;                // Current is the last element of series running longest
            
        }
        if(maxEndingHere < 0){
            maxEndingHere = 0;
            s = i+1;                    // Count values from the next one, because this contributes a negative sum
        }
    }
    cout << "startIdx = " << startIdx << endl;
    cout << "endIdx = " << endIdx << endl; 
    return maxSoFar;
     
}

int main (int argc, char ** argv){
    int array[] = {1,2,3,4,5,6};
    int size = sizeof(array)/sizeof(array[0]);
    cout << maxSubArraySum(array,size) << endl;
        cout << maxSubArrayTrace(array,size) << endl;


}
