// C program for Huffman Coding
#include <stdio.h>
#include <stdlib.h>

// This constant is the max height of the tree
#define MAX_TREE_HT 100

// A Huffman tree node
struct MinHeapNode
{
    char data;  // One of the input characters
    unsigned freq;  // Frequency of the character
    struct MinHeapNode *left, *right; // Left and right child of this node
};

// A Min Heap:  Collection of min heap (or Hufmman tree) nodes
struct MinHeap
{
    unsigned size;    // Current size of min heap
    unsigned capacity;   // capacity of min heap
    struct MinHeapNode **array;  // Array of minheap node pointers
};

// A utility function allocate a new min heap node with given character
// and frequency of the character
struct MinHeapNode* newNode(char data, unsigned freq)
{
    struct MinHeapNode* temp =
          (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// A utility function to create a min heap of given capacity
struct MinHeap* createMinHeap(unsigned capacity)
{
    struct MinHeap* minHeap =
         (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->size = 0;  // current size is 0
    minHeap->capacity = capacity;
    minHeap->array =
     (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// A utility function to swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// The standard minHeapify function.
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size &&
        minHeap->array[left]->freq < minHeap->array[smallest]->freq)
      smallest = left;

    if (right < minHeap->size &&
        minHeap->array[right]->freq < minHeap->array[smallest]->freq)
      smallest = right;

    if (smallest != idx)
    {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// A utility function to check if size of heap is 1 or not
int isSizeOne(struct MinHeap* minHeap)
{
    return (minHeap->size == 1);
}

// A standard function to extract minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// A utility function to insert a new node to Min Heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1)/2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1)/2];
        i = (i - 1)/2;
    }
    minHeap->array[i] = minHeapNode;
}

// A standard funvtion to build min heap
void buildMinHeap(struct MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// A utility function to print an array of size n
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

// Utility function to check if this node is leaf
int isLeaf(struct MinHeapNode* root)
{
    return !(root->left) && !(root->right) ;
}

// Creates a min heap of capacity equal to size and inserts all character of
// data[] in min heap. Initially size of min heap is equal to capacity
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)
{
    int i = 0;
    struct MinHeap* minHeap = createMinHeap(size);
    for ( i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// The main function that builds Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;

    //  Create a min heap of capacity equal to size.
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    // Iterate while size of heap doesn't become 1
    while (!isSizeOne(minHeap))
    {
        //  Extract the two minimum freq items from min heap
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        // '$' is a special value for internal nodes, not used
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }

    // The remaining node is the root node and the tree is complete.
    return extractMin(minHeap);
}

// Prints huffman codes from the root of Huffman Tree.  It uses arr[] to
// store codes
void printCodes(struct MinHeapNode* root, int arr[], int top)
{
    // Assign 0 to left edge and recur
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    // Assign 1 to right edge and recur
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    // If this is a leaf node, then it contains one of the input
    // characters, print the character and its code from arr[]
    if (isLeaf(root))
    {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}

// The main function that builds a Huffman Tree and print codes by traversing
// the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
   //  Construct Huffman Tree
   struct MinHeapNode* root = buildHuffmanTree(data, freq, size);

   // Print Huffman codes using the Huffman tree built above
   int arr[MAX_TREE_HT], top = 0;
   printCodes(root, arr, top);
}

// Driver program to test above functions
int main()
{

      /* a buffer to hold the count of characters 0,...,256; it is
   * initialized to zero on every element */
    int count[256] = { 0 };
    float rate[256];
    int chi=0;
    int ch=0;
    int i=0,j=-1,l=-1;

    int k;
    FILE *fp;
  // file handle
  fp = fopen("new.txt", "r");

  // a holder for each character (stored as int)
  int c;

  // for as long as we can get characters
  while((c=fgetc(fp))) {
    // break if end of file
    if(c == EOF) break;
    // otherwise add one to the count of that particular character
    count[c]+=1;
    ch++;
  }
  char cha[ch];
    int co[ch];
  // now print the results; only if the count is different from zero
   printf("number of characters in file is %d\n",ch);
    for(k=0; k<256; k++) {
     if(count[k] > 0){
             cha[j++]=k;
             co[l++]=count[k];
             chi++;
        rate[k]=((float)count[k]/(float)ch);
      printf("char %c: %d times, rate:%f \n", k, count[k],rate[k]);
     }
    }
  // close the file
  fclose(fp);
  char chaa[chi-1];
  int coo[chi-1];
  for(i=0; i<chi-1; i++){
     chaa[i]=cha[i];
     coo[i]=co[i];
  }
    // encode the characters in the file
    HuffmanCodes(chaa, coo, chi-1);
    return 0;
}
