#include "../include/common.h"
#include "pa2.h"


// don't remove these globals
static struct record *bst_root = NULL;
static struct record *avl_root = NULL;
static size_t num_bst_nodes = 0;
static size_t num_avl_nodes = 0;

// don't modify this function
struct record *get_bst_root()
{
  return bst_root;
}

// don't modify this function
struct record *get_avl_root()
{
  return avl_root;
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
// compare two records
// we assume that uid is unique and
// there can't be two records with the 
// same uid
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

// Return the total number of records in the
// BST rooted at bst_root.
size_t get_num_bst_records()
{
  return num_bst_nodes;
}

// Return the total number of records in the
// AVL tree rooted at avl_root.
size_t get_num_avl_records()
{
  return num_avl_nodes;
}

// Insert record r in the BST rooted at bst_root.
struct record* allocate_record(struct record* r){
  struct record* temp = (struct record *)allocate_memory(sizeof(struct record));
  *temp = *r;
  return temp;
}
struct record* insert_bst(struct record* root, struct record* r){
  if (root == NULL){
    return allocate_record(r);
  }
  if ((cmp_record(r,root))==-1){
    root->left = insert_bst(root->left, r);
    //root->left->parent = root;
  } else{
    root->right = insert_bst(root->right, r);
    //root->right->parent = root;
  }
  return root;
}
void insert_record_bst(struct record r)
{
  bst_root = insert_bst(bst_root,&r);
  num_bst_nodes++;
}

// Insert record r in the AVL tree rooted at avl_root.
int get_balance(struct record *n){
  int l_height = (n->left) ? n->left->height : -1;
  int r_height = (n->right) ? n->right->height : -1;
  return l_height - r_height;
}
void set_height(struct record *n){
  int l_height = (n->left) ? n->left->height : -1;
  int r_height = (n->right) ? n->right->height : -1;
  n->height = (l_height > r_height) ? l_height + 1: r_height + 1;
}
struct record* LL(struct record *n) {
  struct record *new_root = n->left;
  n->left = new_root->right;
  new_root->right = n;
  set_height(n);
  set_height(new_root);
  return new_root;
}
struct record* RR(struct record *n) {
  struct record *new_root = n->right;
  n->right = new_root->left;
  new_root->left = n;
  set_height(n);
  set_height(new_root);
  return new_root;
}
struct record* RL(struct record *n) {
  struct record *mid = n->right;
  struct record *new_root = mid->left;
  mid->left = new_root->right;
  n->right = new_root->left;
  new_root->left = n;
  new_root->right = mid;
  set_height(n);
  set_height(mid);
  set_height(new_root);
  return new_root;
}
struct record* LR(struct record *n) {
  struct record *mid = n->left;
  struct record *new_root = mid->right;
  mid->right = new_root->left;
  n->left = new_root->right;
  new_root->left = mid;
  new_root->right = n;
  set_height(n);
  set_height(mid);
  set_height(new_root);
  return new_root;
}
struct record* try_rotate(struct record *n) {
  int bal = get_balance(n);
  if (bal < -1) {
    bal = get_balance(n->right);
    if (bal > 0) {
      n = RL(n);
    } else {
      n = RR(n);
    }
  }
  else if (bal > 1) {
    bal = get_balance(n->left);
    if (bal < 0) {
      n = LR(n);
    }
    else {
      n = LL(n);
    }
  }
  return n;
}
struct record* insert_avl(struct record *root, struct record *r){
  struct record *n;
  if (root == NULL) {
    return allocate_record(r);
  }
  if ((cmp_record(r,root))==-1){
    root->left = insert_avl(root->left, r);
    //root->left->parent = root;
  } else {
    root->right = insert_avl(root->right, r);
    //root->right->parent = root;
  }
  set_height(root);
  n = try_rotate(root);
  return n;
}
void insert_record_avl(struct record r)
{
  avl_root = insert_avl(avl_root, &r);
  num_avl_nodes++;
}

// Search the record corresponding to uid in the BST
// rooted at bst_root.
// If the record is not present, return a dummy record
// with -1 in the status field.
struct record* search_record(struct record* root, char uid[]){
  if (root == NULL){
    return NULL;
  }
  if (cmp_uid(root->uid,uid)==0){
    return root;
  } else if (cmp_uid(root->uid,uid)==1){
    return search_record(root->left,uid);
  } else {
    return search_record(root->right,uid);
  }
}
struct record search_record_bst(char uid[MAX_LEN])
{
  struct record* r = search_record(bst_root,uid);
  if (r == NULL){
    struct record dummy;
    dummy.status = -1;
    return dummy;
  }
  return *r;
}

// The friends field in "struct record" stores the
// head of the linked list of friends of a given user.
// Return the head of the linked list of friends
// of the user with uid uid in the BST rooted at bst_root.
// If the corresponding record doesn't exist, return NULL.
struct list_records *get_friends_list_bst(char uid[MAX_LEN])
{
  struct record* r = search_record(bst_root,uid);
  if (r == NULL){
    return NULL;
  }
  return r->friends;
}

// Delete the record (say n) corresponding to uid from the BST.
// Remove n from the lists of friends of other records
// and release the memory for the linked list nodes.
// Release memory for all the nodes in the list of friends of n.
// Return a copy of the value of the deleted node.
// If the node is not present, return a dummy record
// with -1 in the status field.   
struct record* find_min(struct record *root) {
  if (root == NULL) {
    return NULL;
  }
  if (root->left == NULL) {
    return root;
  }
  else {
    return find_min(root->left);
  }
}
struct list_records* remove_friends(struct list_records* head, struct record *n){
  if (head == NULL){
    return NULL;
  }
  while (head != NULL && cmp_record(head->record, n) == 0){
    struct list_records* temp = head;
    head = head->next;
    free_memory(temp);
  }
  struct list_records* curr = head;
  while (curr != NULL && curr->next != NULL){
    if (cmp_record(curr->next->record, n) == 0){
      struct list_records* temp = curr->next;
      curr->next = temp->next;
      free_memory(temp);
    }
    else{
      curr = curr->next;
    }
  }
  return head;
}
struct record* delete_bst(struct record *root, char uid[MAX_LEN]) {
  if (root == NULL) {
    return NULL;
  }
  if (cmp_uid(root->uid,uid) < 0) {
    root->right = delete_bst(root->right, uid);
  }
  else if (cmp_uid(root->uid,uid) > 0){
    root->left = delete_bst(root->left, uid);
  }
  else {
    if (root->left == NULL) {
      struct record *ret = root->right;
      free_memory(root);
      return ret;
    }
    else if (root->right == NULL) {
      struct record *ret = root->left;
      free_memory(root);
      return ret; 
    }
    struct record *min_node = find_min(root->right);
    for (int i = 0; i < MAX_LEN; i++) {
      root->uid[i] = min_node->uid[i];
    }
    strcpy(root->name,min_node->name);
    root->friends = min_node->friends;
    root->right = delete_bst(root->right, min_node->uid);
  }
  return root;
}
struct record delete_record_bst(char uid[MAX_LEN])
{
  struct record* r = search_record(bst_root,uid);
  struct record dummy;
  if (r == NULL){
    dummy.status = -1;
    return dummy;
  }
  for (int i = 0; i < MAX_LEN; i++) {
    dummy.uid[i] = r->uid[i];
  }
  strcpy(dummy.name,r->name);
  dummy.friends = r->friends;
  dummy.status = r->status;
  struct list_records *curr = r->friends, *next;
  while (curr != NULL){
    next = curr->next;
    struct record* rec = search_record(bst_root,curr->record->uid);
    rec->friends = remove_friends(rec->friends,r);
    free_memory(curr);
    curr = next;
  }
  bst_root = delete_bst(bst_root, uid);
  num_bst_nodes--;
  return dummy;
}

// Search the record corresponding to uid in the AVL tree
// rooted at avl_root.
// If the record is not present, return a dummy record 
// with -1 in the status field.
struct record search_record_avl(char uid[MAX_LEN])
{
  struct record* r = search_record(avl_root,uid);
  if (r == NULL){
    struct record dummy;
    dummy.status = -1;
    return dummy;
  }
  return *r;
}

// The friends field in "struct record" stores the
// head of the linked list of friends of a given user.
// Return the head of the linked list of friends
// of the user with uid uid in the AVL tree rooted at avl_root.
// If the corresponding record doesn't exist, return NULL.
struct list_records *get_friends_list_avl(char uid[MAX_LEN])
{
  struct record* r = search_record(avl_root,uid);
  if (r == NULL){
    return NULL;
  }
  return r->friends;
}

// Delete the record (say n) corresponding to uid from the AVL tree.
// Remove n from the lists of friends of other records
// and release the memory for the linked list nodes.
// Release memory for all the nodes in the list of friends of n.
// Return a copy of the value of the deleted node.
// If the node is not present, return a dummy record
// with -1 in the status field.
struct record* delete_avl(struct record *root, char uid[MAX_LEN]) {
  if (root == NULL) {
    return NULL;
  }
  if (cmp_uid(root->uid,uid) < 0) {
    root->right = delete_avl(root->right, uid);
  }
  else if (cmp_uid(root->uid,uid) > 0){
    root->left = delete_avl(root->left, uid);
  }
  else {
    if (root->left == NULL) {
      struct record *ret = root->right;
      free_memory(root);
      return ret;
    }
    else if (root->right == NULL) {
      struct record *ret = root->left;
      free_memory(root);
      return ret; 
    }
    struct record *min_node = find_min(root->right);
    for (int i = 0; i < MAX_LEN; i++) {
      root->uid[i] = min_node->uid[i];
    }
    strcpy(root->name,min_node->name);
    root->friends = min_node->friends;
    root->right = delete_avl(root->right, min_node->uid);
  }
  set_height(root);
  struct record *qt = try_rotate(root);
  return qt;
}
struct record delete_record_avl(char uid[MAX_LEN])
{
  struct record* r = search_record(avl_root,uid);
  struct record dummy;
  if (r == NULL){
    dummy.status = -1;
    return dummy;
  }
  for (int i = 0; i < MAX_LEN; i++) {
    dummy.uid[i] = r->uid[i];
  }
  strcpy(dummy.name,r->name);
  dummy.friends = r->friends;
  dummy.status = r->status;
  struct list_records *curr = r->friends, *next;
  while (curr != NULL){
    next = curr->next;
    struct record* rec = search_record(avl_root,curr->record->uid);
    rec->friends = remove_friends(rec->friends,r);
    free_memory(curr);
    curr = next;
  }
  avl_root = delete_avl(avl_root, uid);
  num_avl_nodes--;
  return dummy;
}

// Release memory for all BST nodes and their lists of friends.
// Make bst_root points to an empty tree.
void tree_destruction(struct record *root){
  if (root == NULL){
    return;
  }
  tree_destruction(root->left);
  tree_destruction(root->right);
  struct list_records *curr = root->friends, *next;
  while (curr != NULL){
    next = curr->next;
    free_memory(curr);
    curr = next;
  }
  free_memory(root);
}
void destroy_bst()
{
  tree_destruction(bst_root);
  bst_root=NULL;
  num_bst_nodes=0;
}

// Release memory for all AVL nodes and their lists of friends.
// Make avl_root points to an empty tree.
void destroy_avl()
{
  tree_destruction(avl_root);
  avl_root=NULL;
  num_avl_nodes=0;
}

// Make users with uids uid1 and uid2 in the BST rooted at bst_root
// friends of each other if they aren't already friends.
// The friends field in "struct record" stores the
// head of the linked list of friends of a given user.
// To make the user with record A a friend of the user with record B, 
// add A to B's list of friends and add B to A's list of friends.
// Return 1 if uid1 and uid2 are already friends before this call.
// Return 0 if they become friends during this call.
struct list_records* ll_search(struct list_records *head, struct record *rec){
  struct list_records *temp = head;
  while (temp != NULL){
    if (cmp_record(temp->record, rec) == 0){
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
int make_friends_bst(char uid1[MAX_LEN], char uid2[MAX_LEN])
{
  struct record *rec1 = search_record(bst_root,uid1);
  struct record *rec2 = search_record(bst_root,uid2);
  if (ll_search(rec1->friends,rec2) != NULL){
    return 1;
  }
  rec1->friends = ll_insert(rec1->friends,rec2);
  rec2->friends = ll_insert(rec2->friends,rec1);
  return 0;
}

// Make users with uids uid1 and uid2 in the AVL tree rooted at avl_root
// friends of each other if they aren't already friends.
// The friends field in "struct record" stores the
// head of the linked list of friends of a given user.
// To make the user with record A a friend of the user with record B, 
// add A to B's list of friends and add B to A's list of friends.
// Return 1 if uid1 and uid2 are already friends before this call.
// Return 0 if they become friends during this call.
int make_friends_avl(char uid1[MAX_LEN], char uid2[MAX_LEN])
{
  struct record *rec1 = search_record(avl_root,uid1);
  struct record *rec2 = search_record(avl_root,uid2);
  if (ll_search(rec1->friends,rec2) != NULL){
    return 1;
  }
  rec1->friends = ll_insert(rec1->friends,rec2);
  rec2->friends = ll_insert(rec2->friends,rec1);
  return 0;
}
