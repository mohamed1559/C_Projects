#include <stdio.h>
#include <stdlib.h>

int ord=0;
struct min_node {

    char data;
    int freq;
    int order;
    struct min_node *left, *right;
};


struct MinHeap {

    int size;
    int capacity;
    struct min_node** array;
};



struct min_node* newNode(char data, int freq)
{
    struct min_node* temp = (struct min_node*)malloc(sizeof(struct min_node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    temp->order=ord++;

    return temp;
}


struct MinHeap* createMinHeap(int capacity)
{
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct min_node**)malloc(minHeap->capacity * sizeof(struct min_node));
    return minHeap;
}


void swapnodes(struct min_node** a,struct min_node** b)

{
    struct min_node* t = *a;
    *a = *b;
    *b = t;
}


void Heapify(struct MinHeap* minHeap, int i)

{

    int min = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < minHeap->size&& minHeap->array[left]->freq< minHeap->array[min]->freq)
        min = left;

    if (right < minHeap->size&& minHeap->array[right]->freq< minHeap->array[min]->freq)
        min = right;
// for the same freq compare the order
    if (left < minHeap->size&& minHeap->array[left]->freq== minHeap->array[min]->freq &&
             minHeap->array[left]->order < minHeap->array[min]->order)
        min = left;

    if (right < minHeap->size&& minHeap->array[right]->freq== minHeap->array[min]->freq &&
         minHeap->array[right]->order < minHeap->array[min]->order)
        min = right;

    if (min != i) {
        swapnodes(&minHeap->array[min],&minHeap->array[i]);
        Heapify(minHeap, min);
    }
}

int isSizeOne(struct MinHeap* minHeap)
{
return (minHeap->size == 1);
}


// extract minimum value node from heap
struct min_node* extractMin(struct MinHeap* minHeap)

{

    struct min_node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    Heapify(minHeap, 0);
    return temp;
}


// a new node to Min Heap
void insertheapnode(struct MinHeap* minHeap,struct min_node* min_node)

{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i&& min_node->freq< minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = min_node;
}

//  build min heap
void buildMinHeap(struct MinHeap* minHeap)

{

    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        Heapify(minHeap, i);
}


// Utility function to check if this node is leaf
int isLeaf(struct min_node* root)

{
    return !(root->left) && !(root->right);
}


struct MinHeap* createAndBuildMinHeap(char data[],int freq[], int size)

{

    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

//  builds Huffman tree
struct min_node* buildHuffmanTree(char data[],int freq[], int size)

{
    struct min_node *left, *right, *high;

    struct MinHeap* minHeap= createAndBuildMinHeap(data, freq, size);


    while (!isSizeOne(minHeap)) {


        left = extractMin(minHeap);
        right = extractMin(minHeap);
        high = newNode('$', left->freq + right->freq);

        high->left = left;
        high->right = right;

        insertheapnode(minHeap, high);
    }

    return extractMin(minHeap);
}


void swap_char(char *a, char *b )
{

    char temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int *a, int *b )
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(char*charc,int*freq,int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(freq[j]>freq[j+1])
            {
                swap(&freq[j],&freq[j+1]);
                swap_char(&charc[j],&charc[j+1]);
            }
            else if(charc[j]<charc[j+1] && !(freq[j]< freq[j+1])) // order by alphabetical order
            {
                swap(&freq[j],&freq[j+1]);
                swap_char(&charc[j],&charc[j+1]);
            }
        }
    }
}

void decoding (struct min_node* root,char code[])

 {
     struct min_node* current =root;


     for(int i=0;code[i]!= '\0';i++)
     {
         if(code[i] == '0')
         {
             current=current->left;
         }else if(code[i]=='1')
         {
             current=current->right;
         }
         if(isLeaf(current))
         {
             printf("%c",current->data);
             current=root;
         }
     }


 }

int main() {

    char sentence[10000];
    char code[10000];
    int count;
    gets(sentence);
    gets(code);
    for (count=0; sentence[count] != '\0'; count++); // count the size of sentence
    sentence[count] = '\0';


   /*store in Array*/

   char charchters[10000];
   for(int i=0;sentence[i];i++)
   {  charchters[i]=sentence[i];
   }


   /*Find the duplicate for each one */
     int c = 0, frequency[27] = {0}, x;
while (sentence[c] != '\0') {


      if (sentence[c] >= 'a' && sentence[c] <= 'z') {
         x = sentence[c] - 'a';
         frequency [x]++;
      }
      else if(sentence[c]==' ')
      {
           frequency [26]++;
      }

      c++;
   }

   /*build unique  array*/

     for ( int i = 0; i < count; i ++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if ( charchters[i] == charchters[j])
            {
                for (int k = j; k < count - 1; k++)
                {
                    charchters[k] = charchters [k + 1];
                }

                count--;
                j--;
            }
        }
    }


    int freq[10000];
    for(int i=0;i<count;i++)
    {
       for (c = 0; c < 27; c++){
          if(charchters[i]==c + 'a')
         {
          freq[i]= frequency [c];
          break;

        } else if(charchters[i]==' ')
        {
             freq[i]=frequency [26];
                 break;
        }
            }
    }

  sort(charchters,freq,count);
  struct min_node* root= buildHuffmanTree(charchters, freq, count);
    decoding (root,code);

}
