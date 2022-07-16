#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


/* Very first we have to build an array detecting the frequency of the elements in the document.
Then we create a min heap and use heap sort to arrange elements. Then we use huffman compression and implement algorithm to identify code length. */



class Min_Heap_Node{
    public:

    int frequency;
    char letter;
    Min_Heap_Node *left;
    Min_Heap_Node *right;

    Min_Heap_Node *newnode(char letter, int frequency){
        Min_Heap_Node *temp = new Min_Heap_Node();
        temp->letter = letter;
        temp->frequency = frequency;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }
  
};

class Min_Heap{
    public:
    
    int size;
    int capacity;
    Min_Heap_Node **list;

};


    Min_Heap *createArray(int capacity) {
        Min_Heap *new_heap = new Min_Heap;
        new_heap->size = 0;
        new_heap->capacity = capacity;
        new_heap->list = new Min_Heap_Node*[capacity];
        return new_heap;
    }

     void swap_Nodes(Min_Heap_Node **first, Min_Heap_Node **second) {
        Min_Heap_Node *temporary = *first;
        *first = *second;
        *second = temporary;
    }


    void heapify(Min_Heap *temp ,int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;
        if (left < temp->size && temp->list[left]->frequency < temp->list[smallest]->frequency) {
            smallest = left;
        }
        if (right < temp->size && temp->list[right]->frequency < temp->list[smallest]->frequency) {
            smallest = right;
        }
        if (smallest != index) {
            swap_Nodes(&temp->list[smallest], &temp->list[index]);
            heapify(temp,smallest);
        }
    }

    void build_heap(Min_Heap *temp) {
        int n = temp->size - 1;
        for (int i = (n - 1) / 2; i >= 0; i--) {
            heapify(temp, i);
        }
    }

    Min_Heap *heap_build(char *elements, int *frequencies, int size){
        Min_Heap *new_heap = createArray(size);
        Min_Heap_Node *new_node = new Min_Heap_Node();
        for(int i = 0; i < size; i++){
            new_heap->list[i] = new_node->newnode(elements[i], frequencies[i]);
        }
        new_heap->size = size;
        build_heap(new_heap);
        return new_heap;
    }


void insert(Min_Heap *temp, Min_Heap_Node *new_node) {
        temp->size++;
        int i = temp->size - 1;
        while (i && new_node->frequency < temp->list[(i - 1) / 2]->frequency) {
            temp->list[i] = temp->list[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        temp->list[i] = new_node;
    }

    Min_Heap_Node *minimum_extraction(Min_Heap *temp){
        Min_Heap_Node *temp_node = temp->list[0];
        temp->list[0] = temp->list[temp->size - 1];
        temp->size--;
        heapify(temp,0);
        return temp_node;
    }

     bool isOne(Min_Heap *temp) {
        if (temp->size == 1) {
            return true;
        }
        return false;
    }

Min_Heap_Node *Huff_tree(char *elements, int *frequencies, int size){
        Min_Heap_Node *right, *left, *root;
        Min_Heap *heap = new Min_Heap();
        heap = heap_build(elements, frequencies, size);
        

        while(!isOne(heap)){
            left = minimum_extraction(heap);
            right = minimum_extraction(heap);

            root = root->newnode(' ', left->frequency + right->frequency);
            root->left = left;
            root->right = right;
            insert(heap, root);
        }
        return minimum_extraction(heap);
    }




    bool is_not_leaf(Min_Heap_Node *node) {
        if (!node->left && !node->right) {              //checks whether the node is a leaf or not
            return false;
        }
        return true;
    }

    

    std:: vector <char> huffman_letters;
    std:: vector <int> huffman_length;
    std:: vector <int> huffman_freqs;

    void get_codes(Min_Heap_Node *root, int *codes, int top) {
        if (root->left) {
            codes[top] = 0;
            get_codes(root->left, codes, top + 1);
        }
        if (root->right) {
            codes[top] = 1;
            get_codes(root->right, codes, top + 1);
        }
        if (!is_not_leaf(root)) {

            huffman_letters.push_back(root->letter);
            huffman_length.push_back(top);
            huffman_freqs.push_back(root->frequency);
        }
    }


  void H_T_Processor(char items[], int frequencies[], int size) {
        Min_Heap_Node *root = Huff_tree(items, frequencies, size);
        int *codes = new int[size];
        get_codes(root, codes, 0);
    }





int main(int argc, char *argv[]) {
    
if (argc != 2) {
    cout << "Please enter a file name" << endl;
    return 0;
}

int chaaracters[128] = {0};
string filename = argv[1];
ifstream file(filename);
char letter;
string line;
vector <char> letters;
vector <int> frequencies;


if (!file) {
        cout << "Unable to open " << filename << endl;
        return 1;
    }

while(!file.eof()) {
    getline(file, line, '\r');
    for (int i = 0; i < line.length(); i++) {
        letter = line[i];
        chaaracters[(int)letter]++;
    }
    
}

for (int i = 0; i < 128; i++) {
    if (chaaracters[i] != 0) {
        char unit = (char)i;
        int num = chaaracters[i];
        letters.push_back(unit);
        frequencies.push_back(num);
    }
}

char letter_array [letters.size()];
int frequency_array [frequencies.size()];

for (int i = 0; i < letters.size(); i++) {
    letter_array[i] = letters[i];
    frequency_array[i] = frequencies[i];
}

H_T_Processor(letter_array, frequency_array, letters.size());

int uncompressed = 0;
int compressed = 0;

for (int i = 0; i < letters.size();i++){
    uncompressed += frequencies[i];
    compressed += huffman_freqs[i] * huffman_length[i];
}

cout << "Uncompressed length: " << 8*uncompressed << " bits" << endl;
cout << "Compressed length: " << compressed << " bits" << endl;
cout << "CHAR|FREQ|CODE_LEN" << endl;



for (int i = 0; i < letters.size(); i++) {
    for (int j = 0; j < huffman_letters.size(); j++){
        if (letters[i] == huffman_letters[j]) {
            cout << "'" << huffman_letters[j] << "'" << "|";
            cout << huffman_freqs[j] << "|";
            cout << huffman_length[j];
            cout << endl;
            break;
        }
        
    }
}



/*for (int i = 0; i < frequencies.size(); i++) {
   cout << letters[i] << " " << frequencies[i] << endl;
}*/


   

   return 0;
}
