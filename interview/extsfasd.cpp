
void readBlockToHeap(const FilePointer * const fp_s, const FilePointer * const fp_e, const size_t toread, const size_t index, heap &){
  if(fp_s == fp_e && 0 == to_read) return;
  for(size_t i =0; i< toread; ++i){
    heap.insert(makepair(readfile(fp_s), index));
  }
}

/* This function check whether we already sorted all the numbers */
bool endSorted(const FilePointer * const fp_s, const FilePointer * const fp_e,  const size_t block_number){
  for (size_t i = 0; i < block_number; ++i) {
    if(fp_s[i] != fp_e[i]) return false;
  }
  return true;
}

/* This function check whether we need to read stuff to the heap */
bool needReadNumber(const size_t * const countArray, const size_t  block_number) {
  for (size_t i = 0; i < block_number; ++i) {
    if(0 == countArray[i]) return true;
  }
  return false;
}

FileHandle externalsorted(FileHandle input, const size_t block_size,  const size_t block_number){
  FilePointer * fp_s = new FilePointer [block_number];
  FilePointer * fp_e = new FilePointer [block_number];
  FileHandle  output = new fileBlock;
  fp_s[0] = new FilePointer();
  fp_s[0] = fseek(input, 0);
  for(size_t i = 1; i < block_number; ++i) {
    fp_s[i] = fseek(input, i*block_size); 
    fp_e[i - 1] = fp_s[i];  
  }
  fp_e[block_number - 1] = end_of_file;

  // sort each block
  for(size_t i = 0; i < block_number; ++i) {
    quicksort(fp_s[i], fp_e[i], block_size); 
    /*this function take 2 filepointer(the start of file and the end of the file) 
      and a total number of numbers to be sorted will sorted the fileblock
     */
  }

  MyHeap<MyPair> heap; // the MyPair need to overload < 



  size_t  * count_array = new size_t[block_number];
  // set all count to 0
  for(size_t i = 0; i < block_number; ++i) {
    count_array[i] = 0;
  }  
  size_t  containsNumber = block_size / block_number /2 ; // this will limit the heap just use half of the allowed space
  int *buffer = new int[block_size / 2];
  size_t buffer_index = 0;
  MyPair temppair;
  while(!endSorted(fp_s, fp_e, block_number)){
    if(needReadNumber(count_array, block_number)) {
      epoll(buffer, buffer_index,filehandle); // call epoll to write things to disk
      buffer_index =0;
      for(size_t i = 0; i< block_number; ++i){
        readBlockToHeap(fp_s, fp_e, containsNumber - count_array[i], heap);
      }
    }
    temppair= heap.pop();
    buffer[buffer_index++] = temppair.first;
    count_array[temppair.second]--;
  } 
  // clean up
  delete []fp_s;
  delete []fp_e;  
  delete []counter_array;
  delete [] buffer;
}
