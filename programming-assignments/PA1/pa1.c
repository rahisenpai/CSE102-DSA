#include "../include/common.h"
#include "pa1.h"


// don't remove these globals
static struct record *record_arr = NULL;
static size_t max_capacity = 0;
static size_t num_records = 0;

// don't modify this function
struct record *get_record_arr()
{
  return record_arr;
}

// don't modify this function
// compare two uids
// return -1 if uid1 < uid2
// return 0 if uid1 == uid2
// return 1 if uid1 > uid2
static int cmp_uid(char *uid1, char *uid2)
{
  int i;

  for (i = 0; i < MAX_LEN; i++) {
    if (uid1[i] > uid2[i]) {
      return 1;
    }
    else if (uid1[i] < uid2[i]) {
      return -1;
    }
  }
  return 0;
}

// don't modify this function
// compare two records when uid is key
// return -1 if record1 < record2
// return 0 if record1 == record2
// return 1 if record1 > record2
static int cmp_record(struct record *r1, struct record *r2)
{
  return cmp_uid(r1->uid, r2->uid);
}

// don't modify this function
static void *allocate_memory(size_t size)
{
  return __mymalloc(size);
}

// don't modify this function
static void free_memory(void *ptr)
{
  __myfree(ptr);
}

// ---------------- Add your code below this line ----------------- //

#define NOT_IMPLEMENTED { printf("%s still needs to be implemented!\n", __func__); abort(); }

// return the total number of records in the
// record_arr
size_t get_num_records()
{
	//NOT_IMPLEMENTED;
  return num_records;
}

// insert record r at the end of the record array
// if the record array is full, allocate
// a new buffer of double size, copy data
// from old buffer to the new buffer
// delete the old buffer
// make record_arr point to the new buffer
void insert_record(struct record r)
{
	//NOT_IMPLEMENTED;
  if (max_capacity == 0 && num_records == 0){
    record_arr = allocate_memory(sizeof(struct record));
    max_capacity++;
  }
  else if (max_capacity == num_records){
    struct record *temp = allocate_memory(2 * num_records * sizeof(struct record));
    for (int i = 0; i < num_records; i++){
      temp[i] = record_arr[i];
    }
    free_memory(record_arr);
    record_arr = temp;
    //free_memory(temp);
    max_capacity *= 2;
  }
  record_arr[num_records] = r;
  num_records++;
}

// return the record corresponding to the uid
// use the linear search algorithm
// you can also use cmp_uid routine defined earlier
// if none of the records contain the input uid
// return a dummy record with status == -1
struct record search_record_linear(char uid[MAX_LEN])
{
	//NOT_IMPLEMENTED;
  for (int i=0; i<num_records; i++){
    if ((cmp_uid(record_arr[i].uid,uid)) == 0){
      return record_arr[i];
    }
  }
  struct record dummy;
  dummy.status = -1;
  return dummy;
}

// return the record corresponding to the uid
// use the binary search algorithm
// you can assume that the record_arr is alaredy sorted
// if none of the records contain the input uid
// return a dummy record with status == -1
struct record search_record_binary(char uid[MAX_LEN])
{
	//NOT_IMPLEMENTED;
  int lo=0, hi=num_records-1;
  while (hi>=lo){
    int mid = lo + (hi-lo)/2;
    if ((cmp_uid(record_arr[mid].uid,uid))==0){
      return record_arr[mid];
    }
    else if((cmp_uid(record_arr[mid].uid,uid))==1){
      hi=mid-1;
    }
    else{
      lo=mid+1;
    }
  }
  struct record dummy;
  dummy.status = -1;
  return dummy;
}

// delete record correspondig to the uid
// if the corresponding record doesn't exist
// return a dummy record with status == -1
// Otherwise, return a copy of the record to the caller 

// resize the record array in the following manner
// let's say, x is the size of the array
// and after deletion only x/4 
// space in the array is occupied, in this
// case, allocate an array of size x/2,
// copy records from old array to the new
// array, and delete the old array,
// make record_arr point to the new array
struct record delete_record(char uid[MAX_LEN])
{
  //NOT_IMPLEMENTED;
  struct record r;
  int i,flag=0;
  for (i=0; i<num_records; i++){
    if ((cmp_uid(record_arr[i].uid,uid)) == 0){
      r = record_arr[i];
      record_arr[i]=record_arr[num_records-1];
      num_records--;
      flag = 1;
      break;
    }
  }
  if (flag==0){
    r.status = -1;
    return r;
  }
  else if (num_records==(max_capacity/4)){
    struct record *temp = allocate_memory(2 * num_records * sizeof(struct record));
    for (int j = 0; j < num_records; j++){
      temp[j] = record_arr[j];
    }
    free_memory(record_arr);
    record_arr = temp;
    max_capacity /= 2;
  }
  return r;
}

// delete all records in the record_arr
// free record_arr
void delete_all_records()
{
  //NOT_IMPLEMENTED;
  free_memory(record_arr);
  max_capacity = 0;
  num_records = 0;
}

// sort the record array using quick sort
// use cmp_record implementaion to compare two records
void exchange(int a, int b){
  struct record dummy = record_arr[a];
  record_arr[a] = record_arr[b];
  record_arr[b] = dummy;
}

int partition(struct record arr[], int lo, int hi){
  struct record pivot = arr[hi];
  int i = lo-1;
  for (int j = lo; j <= hi-1; j++) {
      if ((cmp_record(&arr[j],&pivot)) == -1) {
          i++;
          exchange(i, j);
      }
  }
  exchange(i+1, hi);
  return i+1;
}

void quicksort(struct record arr[], int lo, int hi){
  if (lo < hi) {
    int p = partition(record_arr, lo, hi);
    quicksort(record_arr, lo, p - 1);
    quicksort(record_arr, p + 1, hi);
  }
}

void sort_records_quick()
{
	//NOT_IMPLEMENTED;
  quicksort(record_arr,0,num_records-1);  
}

// sort the record_arr using merge sort
// use cmp_record implementaion to compare two records
void merge(struct record arr[], int lo, int mid, int hi){
  int i = lo, j = mid + 1, k = lo;
  int z=0;
  struct record *temp = allocate_memory(sizeof(struct record) * (hi + 1));
  for(int m=0; m<10; m++){
    z++;
  }
  while (i<=mid && j<=hi) {
    if ((cmp_record(&arr[i], &arr[j])) == -1 || (cmp_record(&arr[i], &arr[j])) == 0) {
      temp[k] = arr[i];
      i++; k++;
    }
    else {
      temp[k] = arr[j];
      j++; k++;
    }
  }
  while (i<=mid) {
    temp[k] = arr[i];
    i++; k++; z++;
  }
  while (j<=hi) {
    temp[k] = arr[j];
    j++; k++;
  }
  for (int p=lo; p<=hi; p++) {
    arr[p] = temp[p];
  }
  free_memory(temp);
}

void mergesort(struct record arr[], int lo, int hi){
  if (lo<hi) {
    int mid = lo + (hi-lo)/2;
    mergesort(arr, lo, mid);
    mergesort(arr, mid+1, hi);
    merge(arr, lo, mid, hi);
  }
}

void sort_records_merge()
{
	//NOT_IMPLEMENTED;
  mergesort(record_arr,0,num_records-1);
}

// sort the record_arr using selection sort
// use cmp_record implementaion to compare two records
void sort_records_selection(){
	//NOT_IMPLEMENTED;
  int idx;
  for (int i=0; i<num_records-1; i++){
    idx=i;
    for (int j=i+1; j<num_records; j++){
      if ((cmp_record(&record_arr[idx], &record_arr[j])) == 1){
        idx=j;
      }
    }
    if(idx!=i){
      exchange(idx,i);
    }
  }
}

// return the number of records corresponding to the input name
// use linear search to obtain the results
size_t get_num_records_with_name_linear(char name[MAX_LEN])
{
	//NOT_IMPLEMENTED;
  int count=0;
  for (int i=0; i<num_records; i++){
    if ((strcmp(record_arr[i].name,name)) == 0){
      count ++;
    }
  }
  return count;
}

// implement quick sort algorithm to sort the 
// record_arr using name as key
void rearrange_data()
{
	NOT_IMPLEMENTED;
}

// return the number of records corresponding to the input name
// use binary search to obtain the results
// you can assume that the caller has sorted
// data using name as key before making these queries
size_t get_num_records_with_name_binary(char name[MAX_LEN])
{
	NOT_IMPLEMENTED;
}
