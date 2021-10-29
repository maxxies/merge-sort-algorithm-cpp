#include <iostream>
#include <vector>

using namespace std;

//An array to hold numbers
vector<int>arr;

//Function stamps
vector<int> mergesort(vector<int> &arr);
vector<int>mergeArrays(vector<int> &arrayOne,vector<int> &arrayTwo);

int main(){

    int total;
    cout<<"Enter total number of number entries: "<<endl;
    cout<<">> "; //Get array size from user
    while(!(cin>>total)){ //checks whether input is a number
        cout<<"Input must be a number."<<endl;
        cout<<">> ";
        cin.clear();
        cin.ignore(123,'\n');
    }
    //Takes input from the user based on the array size given
    for(int i = 0; i < total; i++){
        int num;
        cout<<"Enter number: "<<endl;
        cout<<">> ";
        while(!(cin>>num)){ // checks if input is a number
        cout<<"Input must be a number."<<endl;
        cout<<">> ";
        cin.clear();
        cin.ignore(123,'\n');
        }
        arr.push_back(num); //adds entered numbers to the array
    }

    //display numbers to be sorted
    cout<<"\n";
    cout<<"Entered numbers."<<endl;
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }


    mergesort(arr); //Calls function for sorting the array

    //displays sorted numbers
    cout<<"\n";
    cout<<"\nSorted numbers."<<endl;
    for(int i = 0; i < mergesort(arr).size(); i++){
        cout<<mergesort(arr)[i]<<" ";
    }

    return 0;
}

/*
    Function takes in an array and divides till the size of array is 1. Has two array variables
    which is passed to another function returning a sorted array of the numbers. This is passed
    to the same function till a single array of the numbers is achieved. This array is then returned.
*/
vector<int> mergesort(vector<int> &arr){
    if(arr.size() == 1){ //checks if size of array is 1
        return arr;
    }
    int arraySize = arr.size(); //holds size of array
    int m;
    //array variables
    vector<int>arr1;
    vector<int>arr2;
    if(arraySize%2==0){ //checks if size of array is an even number or an odd number
        m = arraySize/2;
        //splits array into two
        arr1= vector<int>(arr.begin(),arr.end()-m);
        arr2 = vector<int>(arr.begin()+ m,arr.end());
    }else{
        m = 1+(arraySize-1)/2;
        arr1= vector<int>(arr.begin(),arr.end()-(m-1));
        arr2 = vector<int>(arr.begin()+ m,arr.end());
    }

    // Recursive call on same function until an array is passed
    arr1 = mergesort(arr1);
    arr2 = mergesort(arr2);

    //calls function to merge arrays
    return mergeArrays(arr1,arr2);
}

/*
   Function takes in two arrays, sorts them and returns them as a single array.
*/
vector<int>mergeArrays(vector<int> &arrayOne,vector<int> &arrayTwo){
    vector<int>mainarray; //Array variable
    while(arrayOne.size()!=0 && arrayTwo.size()!=0){ //Checks if any of the array is empty
        if(arrayOne[0]>arrayTwo[0]){ //Compares the first element of the arrays for the greater number
            mainarray.push_back(arrayTwo[0]); //Adds the lesser number to the main array
            arrayTwo.erase(arrayTwo.begin());// Removes lesser number from its array
        }
        else{
            mainarray.push_back(arrayOne[0]);
            arrayOne.erase(arrayOne.begin());
        }
    }
    while(arrayOne.size()!=0){ //Code runs if the array is not empty
        mainarray.push_back(arrayOne[0]); //Adds remaining elements to the main array
        arrayOne.erase(arrayOne.begin()); //removes element after it has been added to the main array from its array
    }
    while(arrayTwo.size()!=0){
        mainarray.push_back(arrayTwo[0]);
        arrayTwo.erase(arrayTwo.begin());
    }
    //Returns sorted array
    return mainarray;
}

