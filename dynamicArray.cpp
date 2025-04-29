#include "dynamicArray.h"

template<class T>
void DynamicArray<T>::resize(const int newsize){
    T* temp = new T[newsize];
    for (int i=0; i < currentMaxNumElements; i++){ 
        temp[i] = array[i];
    }

    delete[] array;
    currentMaxNumElements = newsize;
    array = temp;
}

template<class T>
DynamicArray<T>::DynamicArray(){
    currentMaxNumElements = 3;
    currentNumElementsStored = 0;
    array = new T[currentMaxNumElements];
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray& rhs){
    currentMaxNumElements = rhs.getCurrentMaxNumElements();
    currentNumElementsStored = rhs.getCurrentNumElementsStored();
    array = new T[rhs.getCurrentMaxNumElements()];

    for (int i = 0; i < currentMaxNumElements; i++){
        array[i] = rhs.array[i];
    }
}

template<class T>
DynamicArray<T>::DynamicArray(T* arr, int num, int max){
    currentMaxNumElements = max;
    currentNumElementsStored = num;
    array = new T[max];
    for(int i = 0; i < num; i++){
        array[i] = arr[i];
    }
}

template<class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& rhs){
    currentNumElementsStored = rhs.getCurrentNumElementsStored();
    currentMaxNumElements = rhs.getCurrentMaxNumElements();
    T* temp = new T[currentMaxNumElements];
    for(int i = 0; i < currentNumElementsStored; i++){
        temp[i] = rhs.array[i];
    }
    if(array != nullptr){
        delete [] array;
    }
    array = temp;
    return *this;
}

template<class T>
DynamicArray<T>::~DynamicArray() {
    delete[] array;
}

template<class T>
int DynamicArray<T>::getCurrentNumElementsStored() const {
    return currentNumElementsStored;
}

template<class T>
int DynamicArray<T>::getCurrentMaxNumElements() const {
    return currentMaxNumElements;
}

template<class T>
void DynamicArray<T>::addElementToEndOfArr(const T& newitem){
    if (currentNumElementsStored == currentMaxNumElements){
        resize(currentMaxNumElements+2);
    }

    array[currentNumElementsStored] = newitem;
    currentNumElementsStored++;
}

template<typename T>
T DynamicArray<T>::getElementAtIndex(const int i)const{
    return array[i];
}

template<typename T>
void DynamicArray<T>::replaceElementAtIndex(int i, T newItem){
    array[i] = newItem;
}

template<class T>
void DynamicArray<T>::clearArray(){
    //~DynamicArray(); //clear it
    delete [] array;
    array = new T[1]; //give memory
    currentMaxNumElements = 1;
    currentNumElementsStored = 0;

}

template<class T>
void DynamicArray<T>::removeElementAtIndex(int ind){
    T* temp = new string[currentMaxNumElements];
    int count = 0;
    for(int i = 0; i < currentNumElementsStored; i++){
        if(i != ind){
            temp[count] = array[i];
            count++;
        }
    }
    delete [] array;
    array = temp;
    currentNumElementsStored--;
}

template<class T>
ostream& operator <<(ostream& out, const DynamicArray<T>& arr){
    for(int i = 0; i < arr.getCurrentNumElementsStored(); i++){
        out << i+1 << ". " << arr.getElementAtIndex(i) << endl;
    }
    return out;
}