class Heap {
  constructor() {
    this.heap = [];
  }

  swap(a, b) {
    [ this.heap[a], this.heap[b] ] = [ this.heap[b], this.heap[a] ];
  }

  size() {
    return this.heap.length;
  }

  insert(value) {
    this.heap.push(val);
    let cur = this.heap.length - 1;
    let parent = Math.floor((cur - 1) / 2);

    while(parent < val) {
      this.swap(this.heap[parent], this.heap[cur]);
      cur = parent;
      parent = Math.floor((cur - 1) / 2);
    }
  }

  pop() {
    const lastIndex = this.heap.length - 1;
    this.swap(this.heap[0], this.heap[lastIndex]);

    let value = this.heap.pop();
    let cur = 0;

    while(cur < lastIndex) {
      let leftChild = cur * 2 + 1;
      let rightChild = cur * 2 + 2;

      if(leftChild >= lastIndex) break;

      else if(rightChild >= lastIndex) {
        if(this.heap[cur] < this.heap[leftChild]) {
          this.swap(this.heap[cur], this.heap[rightChild]);
          cur = leftChild;
        } else {
          break;
        }
      }

      else {
        if(this.heap[cur] < this.heap[leftChild] && this.heap[cur] < this.heap[rightChild]){
          if(this.heap[leftChild] > this.heap[rightChild]) {
            this.swap(this.heap[cur], this.heap[leftChild]);
            cur = leftChild;
          } else {
            this.swap(this.heap[cur], this.heap[rightChild]);
            cur = rightChild;
          }
        }

        else if(this.heap[cur] < this.heap[leftChild]) {
          this.swap(this.heap[cur], this.heap[leftChild]);
          cur = leftChild;
        } else if(this.heap[cur] < this.heap[rightChild]) {
          this.swap(this.heap[cur], this.heap[rightChild]);
          cur = rightChild;
        } else {
          break;
        }
      }
    }
    return value;
  }
}


