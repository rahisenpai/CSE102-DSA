#include "../include/common.h"
#include "pa4.h"


// don't remove these globals
struct heap_elem *min_heap_arr = NULL;

// don't modify this function
void initialize_min_heap_arr(struct heap_elem *arr)
{
  min_heap_arr = arr;
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


// The friends field in "struct record" stores the
// head of the linked list of friends of a given user.
// return temp->record->friends.
struct list_records* get_friends_list(struct record *r)
{
  return r->friends;
}

// Make r1 and r2 friends of each other if they aren't already friends.
// The friends field in "struct record" stores the
// head of the linked list of friends of a given user.
// Return 1 if r1 and r2 are already friends before this call.
// Otherwise, make r1 a friend of r2 and return 0.
// To make r1 a friend of r2, 
// insert r1 into the list r2->friends and insert r2 into the list r1->friends.
int cmp_uid(char *uid1, char *uid2){
  for (int i = 0; i < MAX_LEN; i++) {
    if (uid1[i] > uid2[i]) {
      return 1;
    }
    else if (uid1[i] < uid2[i]) {
      return -1;
    }
  }
  return 0;
}
struct list_records* ll_search(struct list_records *head, struct record *r){
  struct list_records *temp = head;
  while (temp != NULL){
    if (cmp_uid(temp->record->uid, r->uid) == 0){
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}
struct list_records* ll_insert(struct list_records *head, struct record *r){
  struct list_records* temp = (struct list_records *)allocate_memory(sizeof(struct list_records));
  temp->record = r;
  temp->next = head;
  return temp;
}
int make_friends(struct record *r1, struct record *r2)
{
  if (ll_search(r1->friends,r2) != NULL){
    return 1;
  }
  r1->friends = ll_insert(r1->friends,r2);
  r2->friends = ll_insert(r2->friends,r1);
  return 0;
}

// remove all nodes from r->friends and release the corresponding memory
void delete_friends_list(struct record *r)
{
  struct list_records *curr = r->friends, *next;
  while (curr != NULL){
    next = curr->next;
    free_memory(curr);
    curr = next;
  }
}

// Each friends f of r is connected via an undirected
// edge whose weight is the distance between r and f.
// compute the shortest distance and a shortest path to 
// all other vertices reachable from r.
// initially, the status fields in all records are set to zero.
// distance and pred fields may contain grabage values.
// you need to use the distance function to compute the distance
// between two records.
// you can use min_heap_arr to implement a min heap or
// a linear scan to find a vertex with the minimum distance.
// In addition to distance and pred, you can also update the
// status field in your implementation.
// Don't modify other fields in struct record.
// At the end of this procedure, distance field in each record
// reachable via r, must contain the minimum distance from r;
// and the pred field must contain the predecessor on a shorest
// path.
void dfs(struct record *r, int *num){
  struct list_records *temp = r->friends;
  struct heap_elem rec;
  rec.r = r;
  min_heap_arr[*num] = rec;
  r->status = 1;
  while (temp){
    if (temp->record->status != 1){
      (*num)++;
      temp->record->distance = __DBL_MAX__;
      temp->record->pred = NULL;
      dfs(temp->record, num);
    }
    temp = temp->next;
  }
}
struct record* get_min(int num){
  struct record *temp = min_heap_arr[0].r;
  temp->distance = __DBL_MAX__;
  for(int i=1; i<=num; i++){
    if((min_heap_arr[i].r->status!=0) && (temp->distance > min_heap_arr[i].r->distance)){
      temp = min_heap_arr[i].r;
    }
  }
  temp->status = 0;
  return temp;
}
void compute_sssp(struct record *r)
{
  int n, num=0;
  double dis;
  struct record *rec;
  struct list_records *temp;
  dfs(r, &num);
  n = num+1;
  // for(int i=0; i<=num; i++){
  //   printf("%s ",min_heap_arr[i].r->name);
  // }
  // printf("\n%d %d\n\n",num,n);
  r->distance = 0;
  r->status = 0;
  while(n!=0){
    if (n!=num+1){
      rec = get_min(num);
    }
    else{
      rec = min_heap_arr[0].r;
    }
    // printf("%s %f\n",rec->name,rec->distance);
    temp = rec->friends;
    while(temp){
      dis = distance(&rec->loc,&temp->record->loc);
      if (temp->record->distance > rec->distance+dis){
        temp->record->distance = rec->distance+dis;
        temp->record->pred = rec;
      }
      temp = temp->next;
    }
    n--;
  }
  r->pred = NULL;
  r->distance = 0;
}
